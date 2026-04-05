#ifndef I2C_COMMS_H
#define I2C_COMMS_H
#include <QByteArray>

#ifdef TARGET_HARDWARE_PI
//#include <sys/ioctl.h>
//#include "/usr/include/linux/i2c.h"
//#include "/usr/include/linux/i2c-dev.h"
//#include <unistd.h>
//#include <errno.h>
//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <fcntl.h>
#endif

/*

 //I did this to test the I2c Bus
    sudo apt-get install i2c-tools
    sudo modprobe i2c-dev
    sudo modprobe i2c-bcm2708
    sudo i2cdetect -y 1

sudo nano /lib/udev/rules.d/60-i2c-tools.rules  (changed 0660 to 0666)
    KERNEL=="i2c-[1-9]*", GROUP="i2c", MODE="0666"

added the following lines to  ?/etc/modules?
i2c-dev
i2c-bcm2708
*/



#ifdef TARGET_HARDWARE_PI
//
//void OpenI2C(){
//    qDebug() << "Opening I2C device.";
//       char *filename = "/dev/i2c-1";
//       if ((I2Cfile = open(filename, O_RDWR)) < 0) {
//           /* ERROR HANDLING: you can check errno to see what went wrong */
//           //perror("Failed to open the i2c bus");
//           qDebug() << "Unable to open I2C channel to contact flightboard." << I2Cfile;
//           I2C_Error = 1;
//           }
//       int addr = 0x08;          // The I2C chip address
//       int x;
//       if ((x = ioctl(I2Cfile, I2C_SLAVE, addr)) < 0) {
//          qDebug() << "Failed to acquire I2C bus access and/or talk to slave.\n" << x;
//          I2C_Error = 2;
//       }
//}
//
//void WriteAllSuperVariables(){
//    //write each supervar to device during boot
//    qDebug() << "Writing All Super Variables to Device";
//    for (int x = 1; x <= largestVarID; x++){
//        if (getFlags(x) & defIsRetain)    I2CSuperVarWrite(x);
//    if (I2C_Error){
//        qDebug() << "WriteAllSuperVariables() I2C Error detected.  bailing";
//        return;
//    }
//    }
//
//}
//
//
//#define registerAddressingMode  16
//
//    //NOT USING 8 BIT ADDRESSING
//int I2CRead8(unsigned char baseReg, unsigned char byteCnt, unsigned char buf[]){ //            unsigned char &buf[]){
//qDebug() << "Byte Count=" << byteCnt;
//    buf[0] = baseReg;
//    if(write(I2Cfile, buf, 1)       != 1)        {I2C_Error = 3; qDebug() << "Unable to set read pointer baseReg=" << baseReg << " byteCnt=" << byteCnt;   return 0;}
//    if(read (I2Cfile, buf, byteCnt) != byteCnt)  {I2C_Error = 4; qDebug() << "Unable to read from register "; return 0;}
//    else{return 1;}
//    return 0;
//}
//
//int I2CWrite8(unsigned char baseReg, unsigned char byteData){ //            unsigned char &buf[]){
//    unsigned char buf[2];
//    buf[0] = baseReg;  //eeprom address in Page 0
//    buf[1] = byteData;     //data2
//    if (write(I2Cfile, buf, 2) != 2){  I2C_Error = 5;   qDebug() << "Unable to write I2C byte baseReg=" << " byteData="<< byteData;}
//    //I2C_Error = 0;
//    return 1;
//}
//
//
//
//    //preceed argument in caller with & if not a string or array
//int I2CRead(unsigned short int baseReg, unsigned char byteCnt, unsigned char c[]){ //            unsigned char &buf[]){
//    if (byteCnt < 2) qDebug() << "Read must of of at least 2 bytes!!!";
//    unsigned char buff[2];
//    c[0] = 0;
//    buff[0] = (unsigned char)((baseReg & 0xFF00)>>8);
//    buff[1] = (unsigned char)((baseReg & 0x00FF));
//    //NUMBER OF BYTES READ MUST BE EVEN NUMBER
//    //I2C_Error = 0;
//    if(write(I2Cfile, buff, 2      )   != 2      )  {I2C_Error = 1; qDebug() << "I2C error - Unable to set read pointer baseReg=" << baseReg << " byteCnt=" << byteCnt;   return 0;}
//    if(read (I2Cfile, c,    byteCnt)   != byteCnt)  {I2C_Error = 1; qDebug() << "I2C error - Unable to read from register "; return 0;}
//    else{
//        return 1;}
//    return 0;
//}
//int I2CWrite(unsigned short int baseReg, unsigned char byteCnt, unsigned char c[]){ //            unsigned char &buf[]){
//    unsigned char buf[1024];
//    buf[0] = (unsigned char)((baseReg & 0xFF00)>>8);
//    buf[1] = (unsigned char)(baseReg & 0x00FF);
//    for (int x = 0; x < byteCnt; x++){
//       buf[2 + x] = c[x];
//    }
//    //I2C_Error = 0;
//    if (write(I2Cfile, buf, 2 + byteCnt) != 2 + byteCnt){I2C_Error = 8;  qDebug() << "I2C Error - Unable to write" << byteCnt << "bytes at address:" << baseReg;}
//    return 1;
//}
//    //*****************************************************
//void I2CSuperVarWrite(varIDtype varID){
//    if (varID > largestVarID){
//      qDebug() << "I2CSuperVarWrite(varIDtype varID) invalid varID of:" << varID;
//      return;
//    }
//    QByteArray varData;
//    varData.append(getValAsQByteArray(varID));
//    unsigned char buf[256];
//    for (int x = 0; x < varData.length(); x++){
//        buf[x] = varData.at(x);
//        }
//    I2CWrite(getBoardAddress(varID), varData.length(),  buf);
//    }
//
//void GetDaugtherSuperVar(varIDtype varID){
//    //qDebug() << " GetDaugtherSuperVar(varIDtype varID){" << varID;
//    if (varID > largestVarID){
//      return;
//    }
//QByteArray varValue;
//varValue.clear();
//    usint boardAddress = getBoardAddress(varID);
//    usint varType; usint i;  getTypeAndArrIndex(varID,i,varType);
//    usint varSize = getLength(varID);
//    for (int x = 0; x < varSize; x++){
//        varValue.append(FlightBoardRegisters[boardAddress + x]);
//        }
//    setValue(varID, varValue);
//    }
//
//
//
//
//
//
//
#endif

#endif // I2C_COMMS_H
