#ifndef GLOBALVARS_H
#define GLOBALVARS_H

#include "allFunctions.h"
#include <QString>
#include <QUdpSocket>
#include <QTimer>
#include "globalDefines.h"
#include "globalStructs.h"
//DEFAULT VALUES -->Startup.h
//RETAINED VALUES -->Globals/retainVariables.h   (Saved to Hard Disk)





SimuHeli simuHeli;


float Position_X;
float Position_Y;
float Position_Z;
float Position_A;
float Position_B;
float Position_C;


    static float deg = 3.1415926535898 / 180.0;

//****************************************************************
//Controller
//****************************************************************
struct Struct_XBox360Controller     Ctrl;
struct Struct_XBox360Controller     CtrlRx1;
struct Struct_JoystickZeroPositions CtrlCalibShare;
struct Struct_JoystickZeroPositions EmptyStruct_CtrlCalibShare;
//output Flags
int         controllerConnected;

//****************************************************************
//Communications
//****************************************************************
//Settings
int             pauseAllTransmission_PleaseCancel;
ullint          pauseAllTransmission_timeToCancel;
QByteArray      OutPacket;       //this is the outbound dataGram to which Packlets get added.
QString         sConnectionState = "Not Connected";
QUdpSocket      udpSocket;
float           RTT_K = 0.9;
unsigned int    unackedPacketCount;
unsigned int    lastAckRTT                   = -1;
float           averageRTT;
unsigned int    packetWindow                 = 3;               //max number of unacked packets at a time
unsigned int    msecsToRememberSentPackets   = 20000;           //msec    - Entries older than this get flushed 1 minute
unsigned int    msecsRetyInterval            = 3000;            //this only applies to critical packets
int             examinePing_NumberOfPackets  = 10;
int             examinePingStep;
ullint          uliPacketsSentWhenExaminePingStarted;
static ullint               lastTime_PolledInterval     [numberOfPollingIntervals];      //move to global to facilitate debugging to see time for response
int             numberOfReadRequestsNeededIsKnown;
int             pauseAllTransmission;

//Statistics but some of these may be deleted
unsigned long int       uliPacketsSent;
unsigned long int       uliPacketsReceived;
float                   DataRate_Recieved;
float                   DataRate_Sent;


unsigned long int       uliBadChecksumPacketsRejected;
unsigned long int       uliBytesSent;
unsigned long int       uliBytesReceived;
ullint                  timeOfLastTransmission;
ullint                  timeLastPacketReceived;
unsigned long int       RxPacketErrorCounter_CRC;
unsigned long int       RxPacketErrorCounter_BadLength;
unsigned long int       RxPacketErrorCounter_Stub;
int                     numberOfUnackedCrucialPackets;
int                     connectionStatus;
int                     HandshakeStep;
int                     InformUserOfHandshakeSuccess;
int                     VarHandshakeStatus[maxAllowedVarID];
QString                 comparisonMismatchDetails;
ullint                  commsStatisticsRefreshCounter;

//Sent Packet log for determining connection quality and expected acknowledgements
struct Struct_sentPacketInfo blankSentPacketLogEntry;
struct Struct_sentPacketInfo sentPacketsLog[sentPacketLogLength];
int nextSentPacketLogIndexToWrite;

//Things that are in every packet Header
ullint          glbZackPacketSequence;



//*********************************************************************
//SUPER VARIABLES
struct Struct_superGlobalVars Vars;   //One Instance
int         varList[numberOfLists][maxListIndex];
int         VarList_MaxIndex[numberOfLists];
int         listToView;
int         RowID[18];              //variable ID of Row being displayed
varIDtype   largestVarID=0;  //XML variable ID  - this is actually the highest USED variable ID.
int         superVarsHaveBeenAddedtoSystem;
short int   nextBoardAddress;
QString defaultSettingsFileName = "./ProgramData/retainData.stz";
//unsigned char FlightBoardRegisters[FlightBoardBufferSize ];

//I2C
int I2Cfile;
unsigned char FlightBoardRegisters[FlightBoardBufferSize];
unsigned char FlightBoardRegisters_Bak[FlightBoardBufferSize];
unsigned int maxAddress_I2C_polled;
unsigned int maxAddress_I2C;
unsigned short int HIGHEST_I2C_POLLED;

//****************************************************************
//Display
//****************************************************************
float zoomLevel = 1;
extern QImage backgroundImage;
//mainWindow dimensiosn
int gWindowWidth;
int gWindowHeight;

//Windows That Are Open
int commSettingsIsOpen;
int commStatisticsIsOpen;
int varListIsOpen;
int aircraftGeometryIsOpen;
int AutopilotSettingsIsOpen;
int gProgMode;      //This determines what is on the main screen see #defines
int menuNum;

//****************************************************************
//Logging Flags
//****************************************************************
//See   Display/Mode_04_viewLogs.h
int glbLogCanScroll[numberOfLogs];
int glbLogWriteToFile[numberOfLogs];
struct Struct_LogDisplayBuffer LogDisplayBuffer[numberOfLogs];
int         loggingIsWarm[numberOfLogs];


#endif // GLOBALVARS_H
