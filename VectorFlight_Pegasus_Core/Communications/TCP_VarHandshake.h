#ifndef TCP_VARHANDSHAKE_H
#define TCP_VARHANDSHAKE_H

#include <QMessageBox>
#include "Globals/globalDefines.h"
void        releaseOutPacket     (QHostAddress   qhaAddress, int isCrucial);
void        pushSuperVarRead        (varIDtype varID);

void connectionHandShake(){
    //******************************************************************
    //Handshake watchdog
    if (!HelicopterMode){
        static int OLD_HandshakeStep ;  static ullint timeHandShakeValChanged;    ullint msecsSinceHandShakeValChanged;
        if (HandshakeStep !=  OLD_HandshakeStep) timeHandShakeValChanged = QDateTime::currentDateTime().toMSecsSinceEpoch();
        if ((HandshakeStep >=1) && (HandshakeStep <10)){
            msecsSinceHandShakeValChanged = QDateTime::currentDateTime().toMSecsSinceEpoch() - timeHandShakeValChanged;
            if (msecsSinceHandShakeValChanged > (unsigned int) HeartbeatInterval){
                QByteArray logRow;     logRow.append("*************Initiated Handshake with Chopper************");
                pleaseLogEvent(Qt::darkCyan, logRow, defCommsLog);
                //QMessageBox msgBox;
                //msgBox.setText("The Handshake with the chopper timed out.  Reattempting... \n\nHandshakeStep =" +QString::number(HandshakeStep));
                //msgBox.exec();
                msecsSinceHandShakeValChanged = QDateTime::currentDateTime().toMSecsSinceEpoch() - timeHandShakeValChanged;
                HandshakeStep = 0;
                }
            }
        OLD_HandshakeStep  = HandshakeStep;
        }



    //THESE ACTIONS ARE CURRENTLY ONLY DONE FROM THE BIG COMPUTER
    //******************************************************************
    //DETERMINE WHEN TO DO PING TIME CALIBRATION
    if (!HelicopterMode){
//        qDebug() << "conExexaminePingStep  <<numberOfReadRequestsNeededIsKnown;
        //STEP 0 - We only get here after a cold bood
        if (examinePingStep == 0){
            if (numberOfReadRequestsNeededIsKnown)  {
                examinePingStep = 1;
                }
            }
        //STEP 1 - ensure handshake is done
        if (examinePingStep==1){
            if (HandshakeStep==10){
                uliPacketsSentWhenExaminePingStarted = uliPacketsSent;
                examinePingStep = 2;
                }
            }
        //STEP 2 - WAIT 50 more packets
        if (examinePingStep==2)   {
            if (abs((long int)(uliPacketsSent - uliPacketsSentWhenExaminePingStarted))>examinePing_NumberOfPackets + 5) examinePingStep=1;     //if rollover occured start over.  Prob could 1 instead of 5 here
            if (abs((long int)(uliPacketsSent - uliPacketsSentWhenExaminePingStarted))>examinePing_NumberOfPackets)  {
                examinePingStep = 3;
                }
            }
        //Step 4 - Tell the helicopter what the expected ping time is
        if (examinePingStep == 4){
            pushSuperVarWrite(getVarID("expectedPingForThisNetwork"));
            releaseOutPacket(nonCriticalPacket);  //this would clog the tubes if it was a critical packet
            examinePingStep = 5;
            }
        //Step 3 - Store the average ping time  (it must be stored for long enough before proceeding to step 3)
        if (examinePingStep==3){
            expectedPingForThisNetwork = averageRTT;
            examinePingStep = 4;
            }
        //STEP 5 - STEADY STATE but we may need to leave it
        if (examinePingStep==5){
            if (connectionStatus <= 0 )                     examinePingStep = 1;
            if (averageRTT < expectedPingForThisNetwork)    examinePingStep = 1;
            }

        //******************************************************************
        //This is the connection handshake stuff
        //State 0 -- Idle or Complete
        //State 1  -Begin Handshake - Request Remote Variables

        //static int HandshakeStep_OLD;
        //if (HandshakeStep != HandshakeStep_OLD) qDebug() << "newHandshakeStep=" << HandshakeStep;
        //HandshakeStep_OLD = HandshakeStep;
        //
        //
        //Note if changing the significance of these steps, please change "Communications/Recieve.h" --> process_ZPack_IncomingSuperVar
        //
        //

        //State 0 - Wait for connection then begin handshake
        if (HandshakeStep == 0){
             for (int x = 1; x <=largestVarID; x++){
                VarHandshakeStatus[x] = 0;
                }
           // if (connectionStatus >= 2){
                //comparisonMismatchDetails.clear();
                if (!HelicopterMode) HandshakeStep = 1;
           //     }
            }
        //State 1 - Send Read Requests
        if (HandshakeStep ==1){
            for (int x = 1; x <=largestVarID; x++){
                if ((getFlags(x) & plsHandshk)){
                    pushSuperVarRead(x);
                    }
                }
                HandshakeStep =2;
                releaseOutPacket(nonCriticalPacket);
                for (int x = 1; x < sentPacketLogLength; x++){  //loop through every element of sent packet log
                    sentPacketsLog[x]           = blankSentPacketLogEntry;
                    //FIXME
                    //it is dangerous to clear the sentPacketLog entry because its possible there are buffered packets en route
                    //if we recieve an unexpected packet
                    //we should restore the sent packet log entry
                    }
            }
        //State 2 -Wait for all the responses
        if (HandshakeStep ==2){
            int StillAwaitingResponses = 0;
            for (int x = 1; x <=largestVarID; x++){
                if (getFlags(x) & plsHandshk){
                    if (VarHandshakeStatus[x] ==0)      StillAwaitingResponses = 1;
                    }
                }
                if (!StillAwaitingResponses) HandshakeStep =3;
            }
        //State 3 -Compare responses and decide action if necessarry
        int UserAction;
        if (HandshakeStep ==3){
            int VarMisMatch = 0;
            for (int x = 1; x <=largestVarID; x++){
                if (getFlags(x) & plsHandshk){
                    if (VarHandshakeStatus[x] ==-1)    {
                        VarMisMatch = 1;
                        //qDebug() << x << getName(x) << "LocalValue=" << getValAsString(x);
                        }
                    }
                }
            if (VarMisMatch){
                QMessageBox msgBox;
                //msgBox.setText("Choose Action");

                QString details = comparisonMismatchDetails;
                comparisonMismatchDetails.clear();

                msgBox.setInformativeText("These are some differences between the local parameters and those stored on the aircraft:   " +sTargetIPAddress + "\n\n\n**************************************************************\n" +

                                          details + "\n**************************************************************\n\n\n             ---Please choose action---");
                msgBox.addButton("Write to chopper", QMessageBox::ActionRole);
                msgBox.addButton("Read from chopper", QMessageBox::ActionRole);

                UserAction = msgBox.exec();        //Read From Chopper is 1, Write to Chopper is 0
                HandshakeStep =4;
                }
            else{//no MisMatch
                HandshakeStep = 10;
                for (int x = 1; x <=largestVarID; x++){
                    if (getFlags(x) & plsHandshk){
                        VarHandshakeStatus[x] =1;
                        }
                    }
                    if (InformUserOfHandshakeSuccess){
                        QMessageBox msgBox;
                        msgBox.setText("No differences were found between the helicopter and the local variables.");
                        msgBox.exec();
                        InformUserOfHandshakeSuccess = 0;
                    }
                }
            }
        //State 4 -Perform action if it was needed from step 3
        static ullint timeStep5started ;

        if (HandshakeStep ==4){
            qDebug() <<  "UserAction=" << UserAction;
            if (UserAction ==1){   //read from chopper
                for (int x = 1; x <=largestVarID; x++){
                    if (getFlags(x) & plsHandshk){
                        if (VarHandshakeStatus[x] ==-1) {pushSuperVarRead(x);  VarHandshakeStatus[x] =1; }
                        }
                    }
                    releaseOutPacket(criticalPacket);
                }
            else{           //write to chopper
                for (int x = 1; x <=largestVarID; x++){
                    if (getFlags(x) & plsHandshk){
                        if (VarHandshakeStatus[x] ==-1) {pushSuperVarWrite(x);   VarHandshakeStatus[x] =1; }
                        }
                    }
                releaseOutPacket(criticalPacket);
                }
            //comparisonMismatchDetails.append("Step4");
            HandshakeStep = 5;
            timeStep5started = QDateTime::currentDateTime().toMSecsSinceEpoch() ;
            }
        //State 5 - Wait for all acknowledgments on action
        if (HandshakeStep ==5)  {
            if ((unackedPacketCount == 0) && (QDateTime::currentDateTime().toMSecsSinceEpoch() - timeStep5started) >300) HandshakeStep = 0;
            }
        //State 10 -Steady State
        if (HandshakeStep == 10){
            if (connectionStatus < 1) {
                HandshakeStep = 0;
                comparisonMismatchDetails.clear();
                }
            }
        }
    }

#endif // TCP_VARHANDSHAKE_H
