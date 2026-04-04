#ifndef SEND1_H
#define SEND1_H

//Note:  Aircraft Status variables are only polled when a good quality connection exists.
//      They are not polled during periods of network congestion



#include "Globals/globalDefines.h"
#include "allFunctions.h"



QByteArray  getValAsQByteArray  (varIDtype varID);
void        releaseOutPacket     (QHostAddress   qhaAddress, int isCrucial);
void        pushSuperVarRead        (varIDtype varID);
void        pushHeartBeat();

void pollVariables(int i);





//*******************************************
void MainWindow::timer2_setInterval()   //Driven by timer2  & timer4
    {

    }

//*******************************************
void MainWindow::decideIfToSendPackets()  //Driven by timer2
{
//Plese See Globals-->SuperVar2 and search for pauseAllTransmission
if ((pauseAllTransmission_PleaseCancel == 1) && (QDateTime::currentDateTime().toMSecsSinceEpoch() > (unsigned int) pauseAllTransmission_timeToCancel)){
    pauseAllTransmission_PleaseCancel   = 0;
    pauseAllTransmission                = 0;
    }

    //For Video DATA 1414 byte packets X 4 per PDU  is what Netflix does
    //these PDU's are sent often enough to meet the req'd data rate
    //For HD movies, the average encoding bitrate is around 3,200DataRate,
    //which means 1 PDU every 2msec

     //***************************************************
    if (PeriodicityFunction(PeriodicityintervalA, 1000)){
            static int   enumIPAddressingMode_OLD;
            static int   systemIsWarm;   //but not on the first execution of this functionm
            if (systemIsWarm){
                if (enumIPAddressingMode != enumIPAddressingMode_OLD) {
                    MainWindow::rebindUDPSocket();
                    connectionStatus     = 0;  //gets blown away anyways but is here for fun
                    HandshakeStep        = 0;
                    }
                }
            systemIsWarm = 1;
            enumIPAddressingMode_OLD = enumIPAddressingMode;
            static QString sTargetIPAddress_OLD;
            if (sTargetIPAddress != sTargetIPAddress_OLD) {
                connectionStatus     = 0;  //gets blown away anyways but is here for fun
                HandshakeStep        = 0;
                }
            sTargetIPAddress_OLD = sTargetIPAddress;
          //***Calculate Packet Window
            //packetWindow = expectedPingForThisNetwork / 10;
            //if (packetWindow <=3)  packetWindow = 4;
            //if (packetWindow >200) packetWindow = 200; //keeps us from blowing away part of the sent packet log which is only 256 in length
            packetWindow = 3;  //undesired buffering on the RPI forces me to keep the packet window short.
          //***Calculate data rate
            static ullint uliBytesReceived_OLD;
            static ullint uliBytesSent_OLD;
            unsigned int sentRate     =uliBytesSent - uliBytesSent_OLD;
            unsigned int recievedRate = uliBytesReceived - uliBytesReceived_OLD;
            DataRate_Sent       =  (float) (int) (DataRate_Sent     * 0.8  + ((float) sentRate)     * 0.2);
            DataRate_Recieved   =  (float) (int) (DataRate_Recieved * 0.8  + ((float) recievedRate) * 0.2);
            uliBytesReceived_OLD    = uliBytesReceived;
            uliBytesSent_OLD        = uliBytesSent;
            }

    //***************************************************
    //FIXME can some of this burden be removed from the Pi?  Does it need to execute this code?
    int intervalB = 250;
    if (!HelicopterMode){
        intervalB = 15;}
    if (PeriodicityFunction(PeriodicityintervalB, intervalB)){
        ullint          AgeOfLogEntry;
        ullint          currentTime                     = QDateTime::currentDateTime().toMSecsSinceEpoch();
        long int        unackedPacketCounter            = 0;  //its counted with this var then copied to a global var
                        numberOfUnackedCrucialPackets   = 0;
        static int      retransmitCount;
            msecsToRememberSentPackets = HeartbeatInterval;
            msecsRetyInterval          = QDateTime::currentDateTime().toMSecsSinceEpoch() - timeLastPacketReceived;
            if (lastAckRTT * 3 > msecsRetyInterval)    msecsRetyInterval = lastAckRTT * 3;
            if (msecsRetyInterval > (unsigned int) HeartbeatInterval) msecsRetyInterval = HeartbeatInterval;
            for (int x = 0; x < sentPacketLogLength; x++){  //loop through every element of sent packet log
                AgeOfLogEntry       = ((ullint) currentTime) - ((ullint) sentPacketsLog[x].timeSent);   if (AgeOfLogEntry > 6000000) AgeOfLogEntry = 0;
                //forget old nonCritical packets
                if (!sentPacketsLog[x].crucialPacket)
                    if ((AgeOfLogEntry > msecsToRememberSentPackets) && (sentPacketsLog[x].timeSent != 0)){
                    sentPacketsLog[x]           = blankSentPacketLogEntry;
                    }
                //retransmit Critical packets
                if (sentPacketsLog[x].crucialPacket){
                    if ((AgeOfLogEntry > msecsRetyInterval         ) && (sentPacketsLog[x].timeSent != 0)){
                        if (sentPacketsLog[x].ackCount == 0){
                            numberOfUnackedCrucialPackets++;
                            retransmitCount++;
                            OutPacket.clear();                                           //limitation - it blows away whatever packlets were waiting in the queue
                            OutPacket.append(sentPacketsLog[x].crucialPacketBody);
                            QByteArray logRow;
                            qDebug() << "Retransmission.  Packet sequence num=" << QString::number(sentPacketsLog[x].PacketSeqNum) << QByteArray2Hex(sentPacketsLog[x].crucialPacketBody);
                            logRow.append("PUSH archived packet for Retransmission.  Packet sequence num=" + QString::number(sentPacketsLog[x].PacketSeqNum));// logRow.append(QByteArray2Hex(packletBody));
                            pleaseLogEvent(Qt::darkCyan, logRow, defCommsLog);
                            releaseOutPacket(criticalPacket);         //limitation - we always retransmit to the latest address, not the original address.
                            sentPacketsLog[x]           = blankSentPacketLogEntry;
                            }
                        }
                    }
                if (retransmitCount >= 7){   //sometimes we get unacked critical's with bad CRC.  They never get acked.  We must reinitialize.
                    connectionStatus     = 0;  //gets blown away anyways but is here for fun
                    HandshakeStep        = 0;
                    }
                if (numberOfUnackedCrucialPackets == 0) retransmitCount = 0;

                if (sentPacketsLog[x].timeSent != 0)  unackedPacketCounter++;
            //qDebug() << x << AgeOfLogEntry << sentPacketsLog[x].PacketSeqNum << sentPacketsLog[x].ackCount << sentPacketsLog[x].crucialPacket << sentPacketsLog[x].timeSent;
            }
        unackedPacketCount = unackedPacketCounter;
        //Determine Connection Status
        if ( unackedPacketCount >= 0.7 * packetWindow)                                                         connectionStatus      = 1;
        if ((unackedPacketCount <  0.7 * packetWindow) && (unackedPacketCount >= 0.3 * packetWindow))          connectionStatus      = 2;
        if ( unackedPacketCount <  0.3 * packetWindow)                                                         connectionStatus      = 3;
        if (QDateTime::currentDateTime().toMSecsSinceEpoch() - timeLastPacketReceived > (unsigned int) HeartbeatInterval * 3) connectionStatus      = 0;
        //Take certain actions based on connection status
        if (!HelicopterMode) connectionHandShake(); //This is the Watchdog for connection handshake
         }

    //***************************************************
    //EVENT 1 - DATA TRANSMISSION
    if (HelicopterMode || (sTargetIPAddress == "127.0.0.1")){  //we need heartbeats to get the flow going if operating simulator in loopback mode
         if (QDateTime::currentDateTime().toMSecsSinceEpoch() - timeOfLastTransmission > (unsigned int) HeartbeatInterval   ){
             pushHeartBeat();
             }
         }
    if (!HelicopterMode){
        int xmitInterval;
        if (unackedPacketCount < packetWindow){
            xmitInterval= 37.0 * ((float) packetWindow   /   ((float) packetWindow - ((float) unackedPacketCount *1.07)));
        }else{
            xmitInterval= HeartbeatInterval;
        }
        if ((HandshakeStep == 10) && PeriodicityFunction(PeriodicityintervalE, xmitInterval)){
            //qDebug() << xmitInterval << "packetWindow=" << packetWindow << "unackedPacketCount=" << unackedPacketCount;
                //NOTE HANDSHAKE can also transmit independently of this via TCP_VarHandshake.h
                //SEND CONTROLLER
                if (PeriodicityFunction(PeriodicityintervalF, iControllerPacketInterval)){
                    static unsigned long long int Ctrl_controllerInputCounter_OLD;
                    if (Ctrl.controllerInputCounter   > Ctrl_controllerInputCounter_OLD){
                        push_ZPack_XBoxController();
                        }
                    Ctrl_controllerInputCounter_OLD = Ctrl.controllerInputCounter;
                    }
                //POLL SUPER VARIABLES   // the interval checked inside the function
                if((superVarsHaveBeenAddedtoSystem  == 1 )                                    &&
                    (numberOfUnackedCrucialPackets  == 0 )){
                    pollVariables(1);
                    pollVariables(2);
                    }
            }
        }
    //RELEASE PACKET
    if (OutPacket.size()>0)    {
        releaseOutPacket(nonCriticalPacket);    //send these packets immediately
        }
    }







void pollVariables(int i){
    int intervalNumber;
    if (i == 1) intervalNumber = PeriodicityintervalC;
    if (i == 2) intervalNumber = PeriodicityintervalD;
    if (PeriodicityFunction(intervalNumber,pollingInterval[i])){
        numberOfReadRequestsNeededIsKnown = 1;
        lastTime_PolledInterval[i] = QDateTime::currentDateTime().toMSecsSinceEpoch();
        for (int x =1; x <=largestVarID; x++) {
            if (getVarClass(x)==i){
                pushSuperVarRead(x);
                }
            }

        //Logging
        if (savePolledVarsToDisk){
            QByteArray logRow;
            int logNumToUse = defLogAllVars;
            glbLogWriteToFile[logNumToUse] = savePolledVarsToDisk;
            glbLogCanScroll[logNumToUse]   = savePolledVarsToDisk;
            for (int x =1; x <=largestVarID; x++) {
                    logRow.append("," + getName(x) + "," + getValAsString(x));  //limitation - it probably records the old value
                }
            pleaseLogEvent(Qt::darkCyan, logRow, logNumToUse);
            }
        }
    }


//***************************************************************************************************************
//***************************************************************************************************************
/*
void pollVariables(int i){
    static ullint               lastTime_PolledInterval     [numberOfPollingIntervals];
    ullint                      mcecsSincePolledInterval    [numberOfPollingIntervals];
    static int                  NumberOfReadsNeeded_IsKnown [numberOfPollingIntervals];
    static int                  numberOfReadsNeeded         [numberOfPollingIntervals];
    static unsigned short int   HighestVarChecked           [numberOfPollingIntervals];
    static unsigned short int   HighestVarChecked_OLD       [numberOfPollingIntervals];
    ullint                      effectiveInterval;
    if (NumberOfReadsNeeded_IsKnown[i]){effectiveInterval = pollingInterval[i] / numberOfReadsNeeded[i]; }else{
                                        effectiveInterval = pollingInterval[i];                          }
    //Test INTERVAL
    mcecsSincePolledInterval[i]   = QDateTime::currentDateTime().toMSecsSinceEpoch() - lastTime_PolledInterval[i];
    if (mcecsSincePolledInterval[i] > effectiveInterval){
        mSecUntilNextPoll   =0;  //this is good to know cause if wait is short, perhaps don't send xbox packet until wait expires.
        lastTime_PolledInterval[i] = QDateTime::currentDateTime().toMSecsSinceEpoch();
        QByteArray logRow;
        //XXXXXXXXXXX logging stuff XXXXXXXXXX
        int logNumToUse;
        if (i == 1) logNumToUse = defInterval1VarsLogNum;
        if (i == 2) logNumToUse = defInterval2VarsLogNum;
        glbLogWriteToFile[logNumToUse] = savePolledVarsToDisk;
        glbLogCanScroll[logNumToUse]   = savePolledVarsToDisk;
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        if  (HighestVarChecked[i] == 0)            HighestVarChecked[i] = 1;     //we start at 1
        if  (HighestVarChecked[i] == largestVarID) HighestVarChecked[i] = 1;
        int x;
        for (x = HighestVarChecked[i] ; x <=largestVarID; x++) {
            if (getVarClass(x)==i){
                pushSuperVarRead(x);  logRow.append("," + getName(x) + "," + getValAsString(x));  //limitation - it probably records the old value
                }
            if (x == largestVarID)  HighestVarChecked[i] = x;
            if ((OutPacket.size() > AlmostMaxOutpacketSize)|| (x==largestVarID)){
                HighestVarChecked[i] = x;
                break;
                }
            }
        //Determine the number of reads needed
        if (!NumberOfReadsNeeded_IsKnown[i]){
            if (HighestVarChecked[i] ==largestVarID){
                NumberOfReadsNeeded_IsKnown[i]=1;
                if (numberOfReadsNeeded==0) numberOfReadsNeeded[i]++;  //neededto prevent a crash
            }else{
                if (HighestVarChecked[i] >HighestVarChecked_OLD[i])    numberOfReadsNeeded[i]++;
            }
        }
        HighestVarChecked_OLD[i] = HighestVarChecked[i];
        //Determine if all numbersOfReadsNeededAReKnown
        numberOfReadRequestsNeededIsKnown = 1;
        for(int x = 1; x < numberOfPollingIntervals; x++){
             if (!NumberOfReadsNeeded_IsKnown[i]) numberOfReadRequestsNeededIsKnown = 0;
                //qDebug() << "Class " << x << "NumberOfReadsNeeded_IsKnown[x]" << NumberOfReadsNeeded_IsKnown[x] << "numberOfReadsNeeded[x]=" << numberOfReadsNeeded[x] << "known=" << numberOfReadRequestsNeededIsKnown;
               }
        } //if (mcecsSincePolledInterval[i] > effectiveInterval)
    }
    */



#endif // SEND1_H
