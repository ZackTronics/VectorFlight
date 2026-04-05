#ifndef SEND3_H
#define SEND3_H

#include <QMessageBox>
#include "Globals/globalDefines.h"


//*******************************************************
void pushSuperVarWrite(varIDtype varID){
    QHostAddress    qhaTargetIPAddress = QHostAddress(sTargetIPAddress);
    QByteArray packetBody;
    packetBody.append(num2QByteArray(varID));
    packetBody.append(getValAsQByteArray(varID));
    addMsgToOutPacket(ZPack_WriteSuperVar,packetBody);
    }
//*******************************************************
void pushSuperVarWrite(QString varName){
    unsigned int vID = getVarID(varName);
    QMessageBox msgBox;
    if (vID == 0){
        msgBox.setText("The following variable does not exist and cannot be tranmitted\n\n"
                       "Please contact the developer - " + varName);
        msgBox.setStandardButtons(QMessageBox::Ok);
        int msgboxResult = msgBox.exec();
        UNUSED(msgboxResult);
        }
    pushSuperVarWrite(vID);
}
//*******************************************************
void pushSuperVarRead(varIDtype varID){
    QHostAddress    qhaTargetIPAddress = QHostAddress(sTargetIPAddress);
    QByteArray packetBody;
    packetBody.append(num2QByteArray(varID));
    addMsgToOutPacket(ZPack_ReadRequest,packetBody);
    }
//*******************************************************
void pushVarReadResponse(varIDtype varID){
    QHostAddress    qhaTargetIPAddress = QHostAddress(sTargetIPAddress);
    QByteArray packetBody;
    packetBody.append(num2QByteArray(varID));
    packetBody.append(getValAsQByteArray(varID));
    addMsgToOutPacket(ZPack_ReadResponse,packetBody);
    }
//*******************************************************
void MainWindow::push_ZPack_Acknowledgment(   sourceCompType    sourceComp,
                                              packetSeqType     incomingPacketSeqNum){
    UNUSED(sourceComp);
    QByteArray packetBody;
    packetBody.append(num2QByteArray((packetSeqType) incomingPacketSeqNum));
    addMsgToOutPacket(ZPack_Acknowledge, packetBody);
    }
//*******************************************************
void pushHeartBeat(){
    QHostAddress    qhaTargetIPAddress = QHostAddress(sTargetIPAddress);
    QByteArray packetBody;
    packetBody.clear();
    addMsgToOutPacket(ZPack_HeartBeat,packetBody);
    }
void ZTransmitCritical(QString variableName){
    pushSuperVarWrite(getVarID(variableName));
    releaseOutPacket(criticalPacket);
    }
//*******************************************************
void MainWindow::push_ZPack_XBoxController()
    {
    QByteArray ctrlWord;
    char b[3];
    b[0] = 0; b[1] = 0; b[2] = 0;                       //-BYTE 0--  --BYTE 1-  --BYTE 2-
    b[0] =         0x80 & (0xFF * (Ctrl.A     && 1));   //1--- ----  ---- ----  ---- ----
    b[0] = b[0] | (0x40 & (0xFF * (Ctrl.B     && 1)));  //-1-- ----  ---- ----  ---- ----
    b[0] = b[0] | (0x20 & (0xFF * (Ctrl.X     && 1)));  //--1- ----  ---- ----  ---- ----
    b[0] = b[0] | (0x10 & (0xFF * (Ctrl.Y     && 1)));  //---1 ----  ---- ----  ---- ----
    b[0] = b[0] | (0x08 & (0xFF * (Ctrl.Back  && 1)));  //---- 1---  ---- ----  ---- ----
    b[0] = b[0] | (0x04 & (0xFF * (Ctrl.Start && 1)));  //---- -1--  ---- ----  ---- ----
    b[0] = b[0] | (0x02 & (0xFF * (Ctrl.Guide && 1)));  //---- --1-  ---- ----  ---- ----
    b[0] = b[0] | (0x01 & (0xFF * (Ctrl.LJ    && 1)));  //---- ---1  ---- ----  ---- ----
    b[1] =         0x80 & (0xFF * (Ctrl.RJ    && 1));   //---- ----  1--- ----  ---- ----
    b[1] = b[1] | (0x40 & (0xFF * (Ctrl.LB    && 1)));  //---- ----  -1-- ----  ---- ----
    b[1] = b[1] | (0x20 & (0xFF * (Ctrl.RB    && 1)));  //---- ----  --1- ----  ---- ----
    b[2] =          Ctrl.KPD_X & 0x0F;                  //---- ----  ---- ----   ---- XXXX (1111=L, 0001=R)
    b[2] = b[2] | ((Ctrl.KPD_Y & 0x0F) <<4);            //---- ----  ---- ----   YYYY ---- (1111=U, 0001=D)
    ctrlWord.append(b[0]);                            //Msg Body Byte  0
    ctrlWord.append(b[1]);                            //Msg Body Byte  1
    ctrlWord.append(b[2]);                            //Msg Body Byte  2
    ctrlWord.append(num2QByteArray( Ctrl.LT));        //Msg Body Bytes 3,4
    ctrlWord.append(num2QByteArray( Ctrl.RT));        //Msg Body Bytes 5,6
    ctrlWord.append(num2QByteArray( Ctrl.LJ_Mag));    //Msg Body Bytes 7,8
    ctrlWord.append(num2QByteArray( Ctrl.LJ_Ang));    //Msg Body Bytes 9,10
    ctrlWord.append(num2QByteArray( Ctrl.RJ_Mag));    //Msg Body Bytes 11,12
    ctrlWord.append(num2QByteArray( Ctrl.RJ_Ang));    //Msg Body Bytes 13,14
    QHostAddress    qhaTargetIPAddress = QHostAddress(sTargetIPAddress);
    addMsgToOutPacket(ZPack_XBoxControllerWord, ctrlWord);
    }

#endif // SEND3_H
