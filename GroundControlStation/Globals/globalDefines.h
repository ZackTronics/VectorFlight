#ifndef GLOBALDEFINES_H
#define GLOBALDEFINES_H
//DO NOT COPY the IFDEF at the beginning and end of this
//if you are copying into the pI


#define num_SocketPort 12346





#define UNUSED(x) (void)(x)


//*********************************************************************

//Joystick update sensitivity  - will not transmit until significant change
#define compK 0.1
//this is how often crucial packets get retransmitted.
#define crucialRetransIntervalTimesRTT 7
#define defTransmitEvalInt  20



//SUPER VARIABLES

#define FlightBoardBufferSize 2048
#define noFlags 0



#define maxMotionVars 10
#define defMaxMotors   6

#define listOf_MotionVars   0
#define listOf_CraftStatus   1

#define numberOfLists   2
#define maxListIndex    1000

#define criticalPacket      1
#define nonCriticalPacket   0
#define maxAllowedVarID     400
#define numberOfPollingIntervals 3
//      numberOfPollingIntervals should be the max polling interval number  (possibly 1 more than the number)

#define AlmostMaxOutpacketSize  1000
//          CONSIDER MODIFYING THE SIZE OF ---AlmostMaxOutpacketSize---

#define mac_uint8           1
#define mac_uint16          2
#define mac_uint32          3
#define mac_uint64          4
#define mac_int16           5
#define mac_int32           6
#define mac_float32         7
#define mac_float64         8
#define mac_QString         9







//KEEP THESE LESS THAN 10 unless you increase array size in PeriodicityFunction
#define PeriodicityintervalA     0
#define PeriodicityintervalB     1
#define PeriodicityintervalC     2
#define PeriodicityintervalD     3
#define PeriodicityintervalE     4
#define PeriodicityintervalF     5
#define PeriodicityintervalG     5





//**************************************************************
//LOGGING
#define numberOfLogs        5

#define defCommsLog         0
#define defEventLog         1
#define defInterval1VarsLogNum    2
#define defInterval2VarsLogNum    3
#define defLogAllVars    4

#define rowBufferSize       100



//*****************************************
//*****************************************
//***   Modifiable Parames
//*****************************************
#define usint                unsigned short int
#define ullint               unsigned long long int
#define isBigEndian       0
#define         sentPacketLogLength            16   //Entries -This is the size of the log used to store sent packet record agains which acks are compared


//****************************************************************
//Debug
//****************************************************************
#define DbgNum2QbyteArray   FALSE






//Constants
#define TRUE    1
#define FALSE   0

#define standardTextSize 11.5
#define         num_uint64     5
#define         num_uint32     10
#define         num_int32      22
#define         num_uint8       200
#define         num_QString     2
#define         num_float32     400
#define         num_float64     10
#define         num_uint16      15
#define         num_int16       2


//these are flags
#define         defIsRetain                        1
#define         UserEditable                            4
#define         plsHandshk                             8
#define         I2CFast                        16
#define         I2CSlow                        32


//********************************
// Shared Variables for -- zeroJoystick
//*********************************
#define arrSize         15
#define macroRJ          2
#define macroLJ          1


//Packet Types
#define mavPacket    0xFE
#define zackPacket   0x25

//ZackPacket -- MsgID
#define ZPack_XBoxControllerWord  0x36
#define ZPack_Acknowledge         0xAC
#define ZPack_WriteSuperVar       0xB3
#define ZPack_ReadRequest         0xB4
#define ZPack_ReadResponse        0xB5
#define ZPack_HeartBeat           0xB6




#define PacketSequence_ZPack_XBoxControllerWord     glbZackPacketSequence
#define PacketSequence_ZPack_Acknowledge            glbZackPacketSequence

//Addresses of Components
#define ControlLaptop 0x01
#define Beagleboard   0x02
#define Flightboard   0x03
#define anyComponent  0x04


//Packet Component types
#define packetSeqType        unsigned short int
#define packletSizeType      unsigned short int
#define MsgIDType            unsigned short int
#define varIDtype            unsigned short int
#define packetTypeDescType   unsigned char
#define destCompType         unsigned char
#define sourceCompType       unsigned char
//I use either "usint" or "unsigned short int" to indicate packet size.  TCP limits to 65535 anyways.


//Display
//These are display Modes for the main screen
#define num_normalMode              0
#define num_calibrateMode           1
#define num_viewControllerMode      2
#define num_viewRmtCtrlMode         3
#define num_viewCommsLog            1000
#define num_viewEventLog            1001
#define num_viewHeliSimulationMode  5



#endif // GLOBALDEFINES_H
