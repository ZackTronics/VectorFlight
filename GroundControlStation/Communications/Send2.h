#ifndef SEND2_H
#define SEND2_H

#include <QString>
#include "Globals/globalDefines.h"
#include <QTimer>
#include <QDateTime>
#include <QUdpSocket>
#include <QMessageBox>



extern unsigned long int uliBytesSent;
//extern unsigned long int uliBytesRecd;




void pleaseLogEvent(QColor lineColor, QByteArray newLine, int whichLog);






void addMsgToOutPacket(MsgIDType      MsgID,
                       QByteArray     &packletBody)
    {
    if (!pauseAllTransmission && paramSetVersion > 0){
        //************************************************************************
        //ADD PACKLET TO OutPacket
        //************************************************************************
        QByteArray packlet;
        packlet = packletBody;
        packlet.insert(0,num2QByteArray((MsgIDType)      MsgID));
        //packlet.insert(0,num2QByteArray((sourceCompType) sourceComp));
        //packlet.insert(0,num2QByteArray((destCompType)   destComp));
        packlet.insert(0,num2QByteArray((usint)          (packlet.size() + sizeof(usint))));  //packletSize
        //************************************************************************
        //Update Comms Log
        if ((glbLogWriteToFile[defCommsLog]) || (glbLogCanScroll[defCommsLog])){
            QByteArray logRow;                      logRow.append(" PUSH");
            if (MsgID== ZPack_Acknowledge)          logRow.append(" (ACK)");
            if (MsgID== ZPack_XBoxControllerWord)   logRow.append(" (XBOX)");
            if (MsgID== ZPack_WriteSuperVar)       {logRow.append(" (WRITE VarID=");          QByteArray b = packlet.mid(sizeof(MsgID)+sizeof(usint),sizeof(varIDtype )); logRow.append( QString::number(QByteArray2lluint(b)) + " Name="+getName(QByteArray2lluint(b))+ ")");}
            if (MsgID== ZPack_ReadRequest)         {logRow.append(" (READ REQUEST VarID=");   QByteArray b = packlet.mid(sizeof(MsgID)+sizeof(usint),sizeof(varIDtype )); logRow.append( QString::number(QByteArray2lluint(b)) + " Name="+getName(QByteArray2lluint(b))+  ")");}
            if (MsgID== ZPack_ReadResponse)        {logRow.append(" (READ RESPONSE VarID=");  QByteArray b = packlet.mid(sizeof(MsgID)+sizeof(usint),sizeof(varIDtype )); logRow.append( QString::number(QByteArray2lluint(b)) + " Name="+getName(QByteArray2lluint(b))+ ")");}
            if (MsgID== ZPack_HeartBeat)            logRow.append(" (HEARTBEAT)");
                                                    logRow.append(" MsgID=");           logRow.append(QString::number(MsgID));
                                                    logRow.append(" Size=");            logRow.append(QString::number(packlet.size()));
            /*                                         logRow.append(" dest=");            logRow.append(QString::number(destComp));
            if (destComp== ControlLaptop)           logRow.append(" (Laptop)");
            if (destComp== Beagleboard)             logRow.append(" (BeagleBD)");
            if (destComp== Flightboard)             logRow.append(" (FlightBD)");
                                                    logRow.append(" source=");          logRow.append(QString::number(sourceComp));
            if (sourceComp== ControlLaptop)         logRow.append(" (Laptop)");
            if (sourceComp== Beagleboard)           logRow.append(" (BeagleBD)");
            if (sourceComp== Flightboard)           logRow.append(" (FlightBD)");
            */
            pleaseLogEvent(Qt::darkCyan, logRow, defCommsLog);
            logRow.clear();                         logRow.append("    Body="); logRow.append(QByteArray2Hex(packletBody));
            pleaseLogEvent(Qt::darkCyan, logRow, defCommsLog);
            }
        //************************************************************************
        OutPacket.append(packlet);
        packlet.clear();
        }
    }




//*******************************************
void releaseOutPacket(int isCrucial)  {
    if (!pauseAllTransmission && paramSetVersion > 0){
    //Loop through each Packlet
        int weWantAckForThisPacket = 0;
        //int weWantAckForThisPacket = 1;
        int packletsRemaining = 1;
            int PackletNum = 0;
            int packletStart = 0;
        while(packletsRemaining && PackletNum < 5)
            {
            PackletNum++;
            QByteArray mydata;  mydata.append(OutPacket);
            //THIS CODE ALSO APPEARS in dataReceive
            int paramOffset = packletStart;
            //Get packletSize---------------------------------------------------------------------
                    packletSizeType
                    packletSize =
                   (packletSizeType)    QByteArray2lluint(mydata.mid(paramOffset,
             sizeof(packletSizeType))); paramOffset = paramOffset +
             sizeof(packletSizeType);
            /*
            //get destComp---------------------------------------------------------------------
                    destCompType
                    destComp =
                   (destCompType)       QByteArray2lluint(mydata.mid(paramOffset,
             sizeof(destCompType)));    paramOffset = paramOffset +
             sizeof(destCompType);
            //get sourceComp---------------------------------------------------------------------
                    sourceCompType
                    sourceComp =
                   (sourceCompType)     QByteArray2lluint(mydata.mid(paramOffset,
             sizeof(sourceCompType)));  paramOffset = paramOffset +
             sizeof(sourceCompType);
             */
            //get MsgID---------------------------------------------------------------------
                    MsgIDType
                    MsgID =
                   (MsgIDType)          QByteArray2lluint(mydata.mid(paramOffset,
             sizeof(MsgIDType)));       paramOffset = paramOffset +
             sizeof(MsgIDType);
            //---------------------------------------------------------------------
            int bytesRemainingThisPacket = mydata.size() - (packletStart + packletSize);
            if (MsgID != ZPack_Acknowledge) weWantAckForThisPacket=1;
            //if (MsgID == ZPack_Acknowledge) weWantAckForThisPacket=0;
            if  (bytesRemainingThisPacket <= 2) {packletsRemaining = 0;}
            else                                {packletStart = packletStart + packletSize;}
            }
        //************************************************************************
        //SEND PACKET
        //************************************************************************
        //store original data incase retransmission is needed
        //qDebug() << "OutPacket=" << QByteArray2Hex(OutPacket);
        QByteArray originalData; if (isCrucial){
            originalData =OutPacket;
            }
        //prepend header,
        OutPacket.insert(0,num2QByteArray((packetSeqType     ) glbZackPacketSequence));
        OutPacket.insert(0,num2QByteArray((packetTypeDescType) zackPacket           ));
        //append signature,
        uint16_t CRCstamp = crcx25((unsigned char*) OutPacket.data(), sizeof(OutPacket.data()));
        OutPacket.append(num2QByteArray((usint) CRCstamp));

        //then send OutPacket
        QHostAddress qhaAddress = QHostAddress(sTargetIPAddress);
        udpSocket.writeDatagram(OutPacket.data(),OutPacket.size(),qhaAddress,12346);
        //Keep record of set packets
        if (weWantAckForThisPacket){
            sentPacketsLog[nextSentPacketLogIndexToWrite].origIPAddress         = qhaAddress;
            sentPacketsLog[nextSentPacketLogIndexToWrite].timeSent              = QDateTime::currentDateTime().toMSecsSinceEpoch();
            sentPacketsLog[nextSentPacketLogIndexToWrite].ackCount              = 0;
            sentPacketsLog[nextSentPacketLogIndexToWrite].crucialPacket         = isCrucial;
            sentPacketsLog[nextSentPacketLogIndexToWrite].PacketSeqNum          = glbZackPacketSequence;
            if (isCrucial){
                //qDebug() << "Packet is Crucial! to" << qhaAddress << "originalData=" << QByteArray2Hex(originalData);
                sentPacketsLog[nextSentPacketLogIndexToWrite].crucialPacketDestination  = qhaAddress;
                sentPacketsLog[nextSentPacketLogIndexToWrite].crucialPacketBody         = originalData;
                }
            nextSentPacketLogIndexToWrite++;
            if (nextSentPacketLogIndexToWrite >= sentPacketLogLength) nextSentPacketLogIndexToWrite = 0;
                }
        //************************************************************************
        //Update Comms Log
        if ((glbLogWriteToFile[defCommsLog]) || (glbLogCanScroll[defCommsLog])){
            QByteArray logRow;
            logRow.append("        SENT ZPacket TO:");  logRow.append(qhaAddress.toString());
            logRow.append("   TotalSize=");             logRow.append(QString::number(OutPacket.size()));
            logRow.append("   isCrucial=");             logRow.append(QString::number(isCrucial));
            logRow.append("   ackExpected=");           logRow.append(QString::number(weWantAckForThisPacket));
            pleaseLogEvent(Qt::darkCyan, logRow, defCommsLog);
            }
        //************************************************************************
        uliBytesSent = uliBytesSent + OutPacket.size();
        uliPacketsSent++;
        glbZackPacketSequence++;
        timeOfLastTransmission = QDateTime::currentDateTime().toMSecsSinceEpoch();
        }
    OutPacket.clear();
}




#endif // SEND2_H
