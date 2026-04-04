#ifndef FLIGHTBOARD_H
#define FLIGHTBOARD_H

#include "Globals/globalDefines.h"
#include "allFunctions.h"
//#include <sys/ioctl.h>
//#include "/usr/include/linux/i2c-dev.h"
//#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void    WriteAllSuperVariables();
int I2CRead(unsigned short int baseReg, unsigned char byteCnt, unsigned char c[]);
void GetDaugtherSuperVar(varIDtype varID);




//****************************************************
void MainWindow::getDataFromFlightboard(){
AutoPilot_ConnectionStatusOfHeli = ((connectionStatus) && 1);   //needed for Simulator AND flightboard

#ifdef TARGET_HARDWARE_PI
//    static int iStep;
//    static unsigned short int startAddress;
//    static unsigned char      readLength;
//    static unsigned long long int timeStart;
//    unsigned short int AutoPilot_ConnectionStatusOfHeli_BAK;
//
//    //changes in this need to connectivity must be written into flightboard
//    if (AutoPilot_ConnectionStatusOfHeli_BAK != AutoPilot_ConnectionStatusOfHeli){
//        I2CSuperVarWrite(getVarID("AutoPilot_ConnectionStatusOfHeli"));
//        }
//    AutoPilot_ConnectionStatusOfHeli_BAK = AutoPilot_ConnectionStatusOfHeli;
//
//    //if errors abort
//    unsigned char trash[2];
//    I2CRead(0, 2, trash);
//    if (I2C_Error)                                      iStep = 5;
//    if (HIGHEST_I2C_POLLED  == 0)    iStep = 5;
//
//    //setup for poll
//    if (iStep ==0){
//        startAddress    = 0;
//        readLength      = 128;
//        //poll
//        //400 vars 134msec with 255 byte read      -6   reads   -22
//        //400 vars 141msec with 128 byte read     - 10  reads   -14msec per read
//        //400 vars 154msec with 64  byte read     - 20  reads   -7.7
//        //400 vars 181msec with 32 byte read       -42  reads   -6
//        //400 vars 215msec with 16 byte read       -86  reads   -2.5
//        //400 vars 476msec with 4 byte read        -343 reads   -1.3msec
//
//        //make a backup to restore register corrupted by dropout
//        for (int x = 0; x <= FlightBoardBufferSize; x++){   //FIXME we don't need to do the whole buffer we only need to go until  maxAddress_I2C (do search of this)
//            FlightBoardRegisters_Bak[x] = FlightBoardRegisters[x];
//            }
//        iStep = 1;
//        }
//
//    if(iStep == 1){//qDebug() << "iStep=1";
//        I2CRead(startAddress, readLength,  &FlightBoardRegisters[0] + startAddress);
//        startAddress = startAddress + readLength;
//        if (startAddress + readLength > maxAddress_I2C_polled + getSize(HIGHEST_I2C_POLLED))         iStep        = 2;
//        //Also Get the Slow Vars in this step
//        static int nextSlowVar = 1;
//        for (int x = nextSlowVar; x <= largestVarID; x++){
//            if (x == 1)  counter_FB_push_3++;
//            if ((getFlags(x) & I2CSlow)){
//                //qDebug() << "     Get VarID" << x;
//                unsigned short int varAddr = getBoardAddress(x);
//                unsigned short int varSize = getSize(x);
//                if (varSize < 2) varSize = 2;
//                I2CRead(varAddr, varSize,  &FlightBoardRegisters[0] + varAddr);
//                GetDaugtherSuperVar(x);  //buffer-->Variables
//                nextSlowVar = x + 1;
//                if (nextSlowVar > largestVarID) nextSlowVar = 1;
//                break;
//            }else{
//            if (x == largestVarID) nextSlowVar = 1;
//                }
//            }
//        }
//
//
//    if (iStep==2){
//        for (int x = 1; x <= HIGHEST_I2C_POLLED; x++){
//                if ((getFlags(x) & I2CFast)) GetDaugtherSuperVar(x);  //buffer-->Variables
//            }
//        iStep = 0;
//        I2C_PollingPeriodMsecs  = QDateTime::currentDateTime().toMSecsSinceEpoch() - timeStart;
//        timeStart               = QDateTime::currentDateTime().toMSecsSinceEpoch();
//    }
//
//
//    //Bad Comms Step 1 - Restore buffer backup.  It might have been corrupted
//    if (iStep ==5){
//        for (int x = 0; x < FlightBoardBufferSize; x++){
//            FlightBoardRegisters[x] = FlightBoardRegisters_Bak[x];
//            }
//        for (int x = 1; x <= HIGHEST_I2C_POLLED; x++){
//                if ((getFlags(x) & I2CFast)) GetDaugtherSuperVar(x);
//            }
//        iStep = 6;
//    }
//
//    //Bad Comms Step 2
//    if (iStep==6){
//        qDebug() << "I2C error.  Was flightboard restarted?  I2C begin reinitialize begin.";
//        I2C_Error   = 0;
//        I2C_PollingPeriodMsecs = 9999;
//        WriteAllSuperVariables();
//        if (I2C_Error   == 0)      {iStep       = 0;
//        }
//    }
//
#endif
}


#endif // FLIGHTBOARD_H
