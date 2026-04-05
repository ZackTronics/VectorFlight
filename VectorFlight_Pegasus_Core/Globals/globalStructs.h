#ifndef GLOBALSTRUCTS_H
#define GLOBALSTRUCTS_H
#include <QHostAddress>
#include "Globals/globalDefines.h"


struct SimuHeli{
    float RotationRate_Yaw;
    unsigned char   isAnimate;
    unsigned char   hasAnimated;

    //propulsion characteristics
    float MotorMaxThrust;
    float torqueK;

    float Throttle_Motor[7];
    float ActualThrust_Motor[7];

    float ActualTorque_Motor[7];



    //Mass characteristics
       float mass;
       float propAndMotorMass;
       float armLength;
       float CenterOfCraftRadius;
       float CenterOfCraftMass;
       float yawMoment;
       float rollMoment;

    //Drag characteristics
       float dragK_Linear;
       float dragK_Roll;
       float dragK_Yaw;

   //Wind
       float WindSpeed_X;
       float WindSpeed_Y;
       float WindSpeed_Z;
       float maxWindSpeed;
       float turbulenceLevel;

    //Forces
    float YawTorque;
    float RollTorque;
    float RollTorqueAzimuth;
    float Force_X;
    float Force_Y;
    float Force_Z;

    //Orientation
    float NoseAzimuth;
    float TiltAmount;
    float TiltAzimuth;
    float pos_X;
    float pos_Y;
    float pos_Z;

    //Velocity
    float YawRate;

    float RollAzimuth;
    float RollVelocity;
    float Velocity_X;
    float Velocity_Y;
    float Velocity_Z;
    float AirVelocity_X;
    float AirVelocity_Y;
    float AirVelocity_Z;

    //Acceleration
    float verticalAccleration;



    //Initial conditions
    float Heli_d;
    float Heli_e;
    float Heli_f;
    float Heli_a;
    float Heli_b;
    float Heli_c;
};

struct Struct_superGlobalVars{      //retain or transferrable between computers
//*****
//* 3 *
//*****
    //
    unsigned char           *Ptr_uint8[num_uint8];
    unsigned char        Cached1_uint8[num_uint8];  //for storing to disk
    unsigned char        Cached2_uint8[num_uint8];  //for transmitting
    unsigned char        Cached3_uint8[num_uint8];  //These store the last know remote values.  If values update they can be automatically transmitted if necessary
    QByteArray        QbarrCache_uint8[num_uint8];
    QString                 Name_uint8[num_uint8];
    short int               Type_uint8[num_uint8];
    short int       BoardAddress_uint8[num_uint8];
    QString          Description_uint8[num_uint8];
    varIDtype                 ID_uint8[num_uint8];
    int              retainFlags_uint8[num_uint8];
    int                 pollRate_uint8[num_uint8];

    //
    unsigned short int     *Ptr_uint16[num_uint16];
    unsigned short int  Cached1_uint16[num_uint16];
    unsigned short int  Cached2_uint16[num_uint16];
    unsigned short int  Cached3_uint16[num_uint16];
    QByteArray       QbarrCache_uint16[num_uint16];
    QString                Name_uint16[num_uint16];
    short int              Type_uint16[num_uint16];
    short int      BoardAddress_uint16[num_uint16];
    QString         Description_uint16[num_uint16];
    varIDtype                ID_uint16[num_uint16];
    int             retainFlags_uint16[num_uint16];
    int                pollRate_uint16[num_uint16];
    //
    unsigned int           *Ptr_uint32[num_uint32];
    unsigned int        Cached1_uint32[num_uint32];
    unsigned int        Cached2_uint32[num_uint32];
    unsigned int        Cached3_uint32[num_uint32];
    QByteArray       QbarrCache_uint32[num_uint32];
    QString                Name_uint32[num_uint32];
    short int              Type_uint32[num_uint32];
    short int      BoardAddress_uint32[num_uint32];
    QString         Description_uint32[num_uint32];
    varIDtype                ID_uint32[num_uint32];
    int             retainFlags_uint32[num_uint32];
    int                pollRate_uint32[num_uint32];
    //
    ullint                 *Ptr_uint64[num_uint64];
    ullint              Cached1_uint64[num_uint64];
    ullint              Cached2_uint64[num_uint64];
    ullint              Cached3_uint64[num_uint64];
    QByteArray       QbarrCache_uint64[num_uint64];
    QString                Name_uint64[num_uint64];
    short int              Type_uint64[num_uint64];
    short int      BoardAddress_uint64[num_uint64];
    QString         Description_uint64[num_uint64];
    varIDtype                ID_uint64[num_uint64];
    int             retainFlags_uint64[num_uint64];
    int                pollRate_uint64[num_uint64];
    //
    short int               *Ptr_int16[num_int16];
    short int            Cached1_int16[num_int16];
    short int            Cached2_int16[num_int16];
    short int            Cached3_int16[num_int16];
    QByteArray        QbarrCache_int16[num_int16];
    QString                 Name_int16[num_int16];
    short int               Type_int16[num_int16];
    short int       BoardAddress_int16[num_int16];
    QString          Description_int16[num_int16];
    varIDtype                 ID_int16[num_int16];
    int              retainFlags_int16[num_int16];
    int                 pollRate_int16[num_int16];
    //int32
    int                     *Ptr_int32[num_int32];
    int                  Cached1_int32[num_int32];
    int                  Cached2_int32[num_int32];
    int                  Cached3_int32[num_int32];
    QByteArray        QbarrCache_int32[num_int32];
    QString                 Name_int32[num_int32];
    short int               Type_int32[num_int32];
    short int       BoardAddress_int32[num_int32];
    QString          Description_int32[num_int32];
    varIDtype                 ID_int32[num_int32];
    int              retainFlags_int32[num_int32];
    int                 pollRate_int32[num_int32];
    //
    float                 *Ptr_float32[num_float32];
    float              Cached1_float32[num_float32];
    float              Cached2_float32[num_float32];
    float              Cached3_float32[num_float32];
    QByteArray      QbarrCache_float32[num_float32];
    QString               Name_float32[num_float32];
    short int             Type_float32[num_float32];
    short int     BoardAddress_float32[num_float32];
    QString        Description_float32[num_float32];
    varIDtype               ID_float32[num_float32];
    int            retainFlags_float32[num_float32];
    int               pollRate_float32[num_float32];
    //
    double                *Ptr_float64[num_float64];
    double             Cached1_float64[num_float64];
    double             Cached2_float64[num_float64];
    double             Cached3_float64[num_float64];
    QByteArray      QbarrCache_float64[num_float64];
    QString               Name_float64[num_float64];
    short int             Type_float64[num_float64];
    short int     BoardAddress_float64[num_float64];
    QString        Description_float64[num_float64];
    varIDtype               ID_float64[num_float64];
    int            retainFlags_float64[num_float64];
    int               pollRate_float64[num_float64];
    //
    QString               *Ptr_QString[num_QString];
    QString            Cached1_QString[num_QString];
    QString            Cached2_QString[num_QString];
    QString            Cached3_QString[num_QString];
    QByteArray      QbarrCache_QString[num_QString];
    QString               Name_QString[num_QString];
    short int             Type_QString[num_QString];
    short int     BoardAddress_QString[num_QString];
    QString        Description_QString[num_QString];
    varIDtype               ID_QString[num_QString];
    int            retainFlags_QString[num_QString];
    int               pollRate_QString[num_QString];
    };


struct Struct_XBox360Controller
{
    //CONTROL OUTPUT
    unsigned short int  A, B, X, Y, Back, Start, Guide, LJ, RJ, LB, RB;
    short int           KPD_X, KPD_Y;
    unsigned short int  LT, RT;
    unsigned short int  LJ_Mag, LJ_Ang, RJ_Mag, RJ_Ang; //These can rollover if an unsiged value is not used
    //OLD VALUES
    unsigned short int  A_OLD, B_OLD, X_OLD, Y_OLD, Back_OLD, Start_OLD, Guide_OLD, LJ_OLD, RJ_OLD, LB_OLD, RB_OLD;
    short int           KPD_X_OLD, KPD_Y_OLD    ;
    unsigned short int  LT_OLD, RT_OLD;
    unsigned short int  LJ_Mag_OLD, LJ_Ang_OLD, RJ_Mag_OLD, RJ_Ang_OLD;
    //I'm not sure where these are really used
    int LJ_X, LJ_Y, RJ_X, RJ_Y;
    //input Flags
    int calibMode;
    int requestReconnection;
    //Extra variables that may or may not be used
    short int A_Pressed, B_Pressed, X_Pressed, Y_Pressed, Back_Pressed, Start_Pressed, Guide_Pressed, LJ_Pressed, RJ_Pressed, LB_Pressed, RB_Pressed;
    short int A_Released, B_Released, X_Released, Y_Released, Back_Released, Start_Released, Guide_Released, LJ_Released, RJ_Released, LB_Released, RB_Released;
    //The Raw value of each analog input gets stored here.  These values are used to zero the analog inputs.
    int LJ_X_Raw, LJ_Y_Raw, RJ_X_Raw, RJ_Y_Raw, KPD_X_Raw, KPD_Y_Raw, LT_Raw, RT_Raw;
     //Offset values for zeroing the analog inputs
    int LJ_X_Offset, LJ_Y_Offset, RJ_X_Offset, RJ_Y_Offset, LT_Offset, RT_Offset;
    //STATUS INFO
    unsigned short int controllerNum;
    unsigned long long int controllerInputCounter
    ;
};


struct Struct_JoystickZeroPositions
    {
    int LJ_Mag[arrSize];
    int LJ_Ang[arrSize];
    int RJ_Mag[arrSize];
    int RJ_Ang[arrSize];
    int LJ_ZeroPosArrPtr, RJ_ZeroPosArrPtr; //index of the next spot in the array to be stored.
    int LJ_ZeroArrLast, RJ_ZeroArrLast;     //index of the last spot in the array to be stored.
    int LJ_NumPointsinZeroArr, RJ_NumPointsinZeroArr;

    int LJ_Offset_Mag;int LJ_Offset_Ang;
    int RJ_Offset_Mag;int RJ_Offset_Ang;
    int newData;
};



struct Struct_sentPacketInfo
    {
    QHostAddress            origIPAddress;
    unsigned long long int  timeSent;           //most recent retransmit
    unsigned long long int  ackCount;
    int                     crucialPacket;
    QByteArray              crucialPacketBody;
    QHostAddress            crucialPacketDestination;
    packetSeqType           PacketSeqNum;
    };

struct Struct_LogDisplayBuffer
    {
    QColor               rowColor[rowBufferSize];
    QByteArray           rowText[rowBufferSize];
    int           glbNextLineToWrite;
    long long int glbNumberOfEntriesInCommsLog;
    int x;
    };


#endif // GLOBALSTRUCTS_H
