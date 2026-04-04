#ifndef Z01_SIMFLIGHTCONTROL_H
#define Z01_SIMFLIGHTCONTROL_H

#include "Globals/globalStructs.h"

#include "time.h"

void setMotor(int Motornum, float ThrottleValue){
    if (ThrottleValue < 0) ThrottleValue = 0;
    if (ThrottleValue > 1) ThrottleValue = 1;
    if (Motornum == 1) simuHeli.Throttle_Motor[1] = ThrottleValue;
    if (Motornum == 2) simuHeli.Throttle_Motor[2] = ThrottleValue;
    if (Motornum == 3) simuHeli.Throttle_Motor[3] = ThrottleValue;
    if (Motornum == 4) simuHeli.Throttle_Motor[4] = ThrottleValue;
    if (Motornum == 5) simuHeli.Throttle_Motor[5] = ThrottleValue;
    if (Motornum == 6) simuHeli.Throttle_Motor[6] = ThrottleValue;
    }
float getThrottleVal(int Motornum){
    if (Motornum == 1) return simuHeli.Throttle_Motor[1];
    if (Motornum == 2) return simuHeli.Throttle_Motor[2];
    if (Motornum == 3) return simuHeli.Throttle_Motor[3];
    if (Motornum == 4) return simuHeli.Throttle_Motor[4];
    if (Motornum == 5) return simuHeli.Throttle_Motor[5];
    if (Motornum == 6) return simuHeli.Throttle_Motor[6];
    return 0;
    }
float get_LeftStick_Y(){
    float LJ_Angle      =  (float) CtrlRx1.LJ_Ang / 10.0;
    float LJ_Magnitude  =  (float) CtrlRx1.LJ_Mag / 32767.0;
    return  (LJ_Magnitude * cos(LJ_Angle * deg) + 1.0) / 2.0;
    }

void getCraftLateralVelocity(float &velocity, float &azimuth){
    float velocity_X =     simuHeli.Velocity_X;
    float velocity_Z =     simuHeli.Velocity_Z;

    velocity = pow((float) (pow((float) velocity_X, (float) 2.0) +pow((float) velocity_Z, (float) 2.0)), (float) 0.5);
    azimuth  = atan2(velocity_X, velocity_Z);
    azimuth = azimuth / deg;
    }
float get_RightStickAngle    () {return (float)     CtrlRx1.RJ_Ang / (float) 10.0;   }
float get_RightStickMagnitude() {return (float)     CtrlRx1.RJ_Mag / (float) 32767.0;}
float get_RT                 () {return (float)     CtrlRx1.RT     / (float) 65535.0;}
float get_LT                 () {return (float)     CtrlRx1.LT     / (float) 65535.0;}


/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
// this code should be as unchanged as possible on the real heli
float normalizeAngleMagnitude(float inputAngle){
    while (inputAngle > 180)  inputAngle = inputAngle - 360;
    while (inputAngle < -180) inputAngle = inputAngle + 360;
    return inputAngle;
    }
void normalizeAng(float &numbers){
    while (numbers > 360)   numbers  = numbers  - 360;
    while (numbers < 0)     numbers  = numbers  + 360;
    }
float normalizeAngl(float numbers){
    while (numbers > 360)   numbers  = numbers  - 360;
    while (numbers < 0)     numbers  = numbers  + 360;
    return numbers;
    }
void calculateThrottleValues(float (&throttleValues)[7], float ThrottleCmd, float desiredRollTorque, float desiredRollAzimuth){
    //Add RollTorque and Total Thrust together
    float distanceFromRollTorque_Motor[7];
    // give each motor a value between 0 to 1 being the farthest from desired roll azimuth
    for (int x = 1; x <= numberOfMotors; x++){
        float degrees = fabs(normalizeAngleMagnitude(desiredRollAzimuth - angle_motor_[x]));
        distanceFromRollTorque_Motor[x] = (degrees  / 180);
        }
    float f1[7];
    for (int x = 1; x <= numberOfMotors; x++){
        f1[x] = distanceFromRollTorque_Motor[x] * desiredRollTorque *2;  //the 2 allows full rotate
        }
    float averageVal = 0;
    for (int x = 1; x <= numberOfMotors; x++){
        averageVal = averageVal + f1[x];
        }
    averageVal = averageVal / numberOfMotors;
    float f2[7];
    for (int x = 1; x <= numberOfMotors; x++){
        f2[x] = f1[x] - averageVal;
        }
    //contrain the throttle cmd
     if (ThrottleCmd >1) ThrottleCmd = 1;
     if (ThrottleCmd <0) ThrottleCmd = 0;
     //Add these forces to the needed thrust
      for (int x = 1; x <= numberOfMotors; x++){
         throttleValues[x] = f2[x] + ThrottleCmd;
         }
    }




void addVect(float &Tilt3, float &Azimuth3, float Tilt1, float Azimuth1,float Tilt2, float Azimuth2){
    static float deg = 3.1415926535898 / 180.0;
    float x[3];                    float y[3];
    x[0] = cos(Azimuth1*deg) * Tilt1;    y[0] = sin(Azimuth1*deg) * Tilt1;
    x[1] = cos(Azimuth2*deg) * Tilt2;    y[1] = sin(Azimuth2*deg) * Tilt2;
    x[2] = x[0] + x[1];                  y[2] = y[0] + y[1];
    Tilt3    = pow((float) (pow((float) x[2], (float) 2.0) +pow((float) y[2], (float) 2.0)), (float) 0.5);
    Azimuth3 = atan2((float) y[2], (float) x[2])/deg;
    }
void subtractVect(float &Tilt3, float &Azimuth3, float Tilt1, float Azimuth1,  float Tilt2, float Azimuth2){
    static float deg = 3.1415926535898 / 180.0;
    float x[3];                    float y[3];
    x[0] = cos(Azimuth1*deg) * Tilt1;    y[0] = sin(Azimuth1*deg) * Tilt1;
    x[1] = cos(Azimuth2*deg) * Tilt2;    y[1] = sin(Azimuth2*deg) * Tilt2;
    x[2] = x[0] - x[1];                  y[2] = y[0] - y[1];
    Tilt3    = pow((float) (pow((float) x[2], (float) 2.0) +pow((float) y[2], (float) 2.0)), (float) 0.5);
    Azimuth3 = atan2((float) y[2], (float) x[2])/deg;
    }

float findAngle(double X1, double Y1,double X2, double Y2){
    static float deg = 3.1415926535898 / 180.0;
    float X3 = X1 - X2;
    float Y3 = Y1 - Y2;
    float z = atan2(X3, (float) Y3)/deg;
    return z;
    }
float findDistance(double X1, double Y1,double X2, double Y2){
    float X3 = X1 - X2;
    float Y3 = Y1 - Y2;
    return pow((float) (pow((float) X3, (float) 2.0) +pow((float) Y3, (float) 2.0)), (float) 0.5);
    }


void NormalizeAndFindDifference(float &C_Mag, float &C_Azi,
                  float  B_Mag, float  B_Azi,
                  float  A_Mag, float  A_Azi){
    normalizeAng(A_Mag);              //we must normalize correctly.  For these purposes
    normalizeAng(A_Azi);       //the craft can never be tilted more than 180 degrees
    normalizeAng(B_Mag);
    normalizeAng(B_Azi);
    if (A_Mag > 180){
        A_Mag  = 360 -  A_Mag;
        A_Azi  = A_Azi - 180;
        }
    normalizeAng(A_Azi);
    if (B_Mag > 180){
        B_Mag  = 360 - B_Mag;
        B_Azi  = B_Azi - 180;
        }
    normalizeAng(B_Azi);
    subtractVect(C_Mag , C_Azi,
                 B_Mag , B_Azi,
                 A_Mag , A_Azi);
    normalizeAng(C_Mag);
    normalizeAng(C_Azi);
    if (C_Mag > 180){
        C_Mag  = 360   - C_Mag;
        C_Azi  = C_Azi - 180;
        }
    //qDebug() << "C=" << C_Mag << C_Azi << "B=" << B_Mag << B_Azi << "A=" << A_Mag << A_Azi;
    }
void getCraftLateralAcceleration(float &Acceleration, float &azimuth){
    float lateralVelocity;
    float lateralVelocityAzimuth;
    static float lateralVelocity_OLD;
    static float lateralVelocityAzimuth_OLD;
    getCraftLateralVelocity    (lateralVelocity,     lateralVelocityAzimuth);
    subtractVect(Acceleration,        azimuth,
                 lateralVelocity,     lateralVelocityAzimuth,
                 lateralVelocity_OLD, lateralVelocityAzimuth_OLD);
    lateralVelocity_OLD         = lateralVelocity;
    lateralVelocityAzimuth_OLD  = lateralVelocityAzimuth;
    }

void simFlightMain(){
    static unsigned char   Command_PleaseMarkThisAsOrigin_OLD;
    static unsigned char   systemIsWarm;
    static unsigned int    clock_old;
    static unsigned int    ticks;
    static float    climbRateError_OLD;
    static float    TiltAmount_OLD;
    static float    yaw_P_Error_OLD;
    static float    TiltAmountAzimuth_OLD;
    static int      Position_CraftIsAirborne_OLD;
    static int      AutoPilot_Enabled_OLD;
    static int      SystemIsWarm;
    static int      AutoPilot_ConnectionStatusOfHeli_OLD;
    float           motorDirection;
    float           motorSpoolK;
    float           magToIntegrate;
    float           unityDesiredClimbRate;
    float           transitSpeed;
    static unsigned long int CommsLoss_timeIndexOfOccurance;
    float                    CommsLoss_ElapsedTime;
    float              BatteryPercent = 0;  //fixme - I set it to 0 here though it gets a value from somewhere else not sure where.
    static float       BatteryPercent_OLD;
    static int RtriggerCommsLossA;
    static int RtriggerCommsLossB;
    static int RtriggerCommsLossC;
    static unsigned long int LowBatt_timeIndexOf_A;
    static unsigned long int LowBatt_timeIndexOf_B;
    static unsigned long int LowBatt_timeIndexOf_C;
    float LowBatt_DurationA;
    float LowBatt_DurationB;
    float LowBatt_DurationC;
    static float LowBatt_DurationA_OLD;
    static float LowBatt_DurationB_OLD;
    static float LowBatt_DurationC_OLD;
    float  tooHighA;
    float  tooHighB;
    float batteryFilterK;

//ACCESS TO INSTRUMENTATION
    Motion_ClimbRate_Actual          = simuHeli.Velocity_Y;          //this will be a function on the Heli
    Motion_Tilt_Actual_Azi           = simuHeli.TiltAzimuth;         //this will be a function
    Motion_Tilt_Actual_Mag           = simuHeli.TiltAmount;          //this will be a function
    Motion_Yaw_Velocity              = simuHeli.YawRate  / 60.0;    //Revolutions per second
    Position_Longitude               = simuHeli.pos_X;
    Position_Latitude                = simuHeli.pos_Z;
    Position_Altitude                = simuHeli.pos_Y;
    Motion_Yaw_AircraftNose_Azi      = simuHeli.NoseAzimuth;
    Motion_Tilt_Velocity_Mems_Mag    = simuHeli.RollVelocity;
    Motion_Tilt_Velocity_Mems_Azi    = simuHeli.RollAzimuth;
    UserInput_DirectionStick_Azi     = get_RightStickAngle();
    UserInput_DirectionStick_Mag     = pow((float) get_RightStickMagnitude(),(float) UserInput_Sensitivity_DirectionStick);
    UserInput_ThrottleStick          = (get_LeftStick_Y()-0.5) * 2.0;
    UserInput_Trigger_Right          = get_RT();
    UserInput_Trigger_Left           = get_LT();
    getCraftLateralVelocity    (Motion_Lateral_Velocity_Mag,     Motion_Lateral_Velocity_Azi);
    getCraftLateralAcceleration(Motion_Lateral_Accelration_Mag, Motion_Lateral_Accelration_Azi);

    //Determine secondsElapsed since last loop
    if ((clock() - clock_old) > 0) ticks = clock() - clock_old;
    secondsElapsed = (float) ticks / (float) CLOCKS_PER_SEC;
    clock_old = clock();

   //Battery voltage
    if (AutoPilot_Enabled != 5) {
        Battery_EffectiveVoltage            = (Thrust_MotorThrottleSummation * Battery_VoltageDropFullThrottle) + Battery_ActualVoltage;
    }else{
        Battery_EffectiveVoltage            = Battery_ActualVoltage;
        }
    Battery_PercentRemainingInstantaneous = 100.0 * (Battery_EffectiveVoltage - Battery_MinCellvoltage) / (Battery_MaxCellvoltage - Battery_MinCellvoltage);
    batteryFilterK = exp(- secondsElapsed / Battery_PercentRemainingFilteringTC);
    Battery_PercentRemainingFiltered = Battery_PercentRemainingInstantaneous * (1- batteryFilterK) + Battery_PercentRemainingFiltered * batteryFilterK;
    if (!systemIsWarm) Battery_PercentRemainingFiltered = Battery_PercentRemainingInstantaneous;

    //COMMSLOSS
    //determine if connected to home-base and calculate duration of connection lost.
    if (!AutoPilot_ConnectionStatusOfHeli && AutoPilot_ConnectionStatusOfHeli_OLD){ //comms lost
        CommsLoss_timeIndexOfOccurance = clock();
        }
    if (AutoPilot_ConnectionStatusOfHeli){
        CommsLoss_ElapsedTime = 0;
    }else{
        CommsLoss_ElapsedTime = ((float) (clock() - CommsLoss_timeIndexOfOccurance)/ (float) CLOCKS_PER_SEC);
        }
    AutoPilot_ConnectionStatusOfHeli_OLD = AutoPilot_ConnectionStatusOfHeli;
    if ((AutoPilot_CommLoss_Delay_PositionHold_Enabled) && (CommsLoss_ElapsedTime > AutoPilot_CommLoss_Delay_PositionHold) && !RtriggerCommsLossA) AutoPilot_Enabled = 3;
    if ((AutoPilot_CommLoss_Delay_ReturnHome_Enabled)   && (CommsLoss_ElapsedTime > AutoPilot_CommLoss_Delay_ReturnHome)   && !RtriggerCommsLossB) AutoPilot_Enabled = 1;
    if ((AutoPilot_CommLoss_Delay_Land_Enabled)         && (CommsLoss_ElapsedTime > AutoPilot_CommLoss_Delay_Land)         && !RtriggerCommsLossC) AutoPilot_Enabled = 2;
    RtriggerCommsLossA = CommsLoss_ElapsedTime > AutoPilot_CommLoss_Delay_PositionHold;
    RtriggerCommsLossB = CommsLoss_ElapsedTime > AutoPilot_CommLoss_Delay_ReturnHome;
    RtriggerCommsLossC = CommsLoss_ElapsedTime > AutoPilot_CommLoss_Delay_Land;

    //BATTERY PERCENT

    /*
    AutoPilot_LowBatt_Percent_ReturnHome_Enabled
    AutoPilot_LowBatt_Percent_LandNow_Enabled
    AutoPilot_LowBatt_Percent_KillSystem_Enabled
    */



    if ((BatteryPercent     < AutoPilot_LowBatt_Percent_ReturnHome)&&
       !(BatteryPercent_OLD < AutoPilot_LowBatt_Percent_ReturnHome))    LowBatt_timeIndexOf_A = clock();
    if ((BatteryPercent     < AutoPilot_LowBatt_Percent_LandNow)   &&
       !(BatteryPercent_OLD < AutoPilot_LowBatt_Percent_LandNow))       LowBatt_timeIndexOf_B = clock();
    if ((BatteryPercent     < AutoPilot_LowBatt_Percent_KillSystem)&&
       !(BatteryPercent_OLD < AutoPilot_LowBatt_Percent_KillSystem))    LowBatt_timeIndexOf_C = clock();



    if (BatteryPercent      < AutoPilot_LowBatt_Percent_ReturnHome){
              LowBatt_DurationA= ((float) (clock() - LowBatt_timeIndexOf_A)/ (float) CLOCKS_PER_SEC);
        }else{LowBatt_DurationA = 0;}
    if (BatteryPercent      < AutoPilot_LowBatt_Percent_LandNow){
              LowBatt_DurationB= ((float) (clock() - LowBatt_timeIndexOf_B)/ (float) CLOCKS_PER_SEC);
        }else{LowBatt_DurationB = 0;}
    if (BatteryPercent      < AutoPilot_LowBatt_Percent_KillSystem){
              LowBatt_DurationC= ((float) (clock() - LowBatt_timeIndexOf_C)/ (float) CLOCKS_PER_SEC);
        }else{LowBatt_DurationC = 0;}



    if ((LowBatt_DurationA > AutoPilot_LowBatt_Percent_TimeDelay) && !(LowBatt_DurationA_OLD > AutoPilot_LowBatt_Percent_TimeDelay)&&(AutoPilot_LowBatt_Percent_ReturnHome_Enabled)) AutoPilot_Enabled = 1;
    if ((LowBatt_DurationB > AutoPilot_LowBatt_Percent_TimeDelay) && !(LowBatt_DurationB_OLD > AutoPilot_LowBatt_Percent_TimeDelay)&&(AutoPilot_LowBatt_Percent_LandNow_Enabled))    AutoPilot_Enabled = 2;
    if ((LowBatt_DurationC > AutoPilot_LowBatt_Percent_TimeDelay) && !(LowBatt_DurationC_OLD > AutoPilot_LowBatt_Percent_TimeDelay)&&(AutoPilot_LowBatt_Percent_KillSystem_Enabled)) AutoPilot_Enabled = 5; //kill motors
    BatteryPercent_OLD                          = BatteryPercent;
    LowBatt_DurationA_OLD                       = LowBatt_DurationA;
    LowBatt_DurationB_OLD                       = LowBatt_DurationB;
    LowBatt_DurationC_OLD                       = LowBatt_DurationC;


 //Determine if aircraft is airborne
    if (Motion_ClimbRate_Actual > 0.5)                    Position_CraftIsAirborne = 1;
    if ((fabs(Motion_ClimbRate_Actual) > 0.25) && Thrust_PredictedActual > 0.1) Position_CraftIsAirborne = 1;
    if ((fabs(Motion_ClimbRate_Actual) < 0.1)  && Thrust_PredictedActual < 0.1) Position_CraftIsAirborne = 0;


//Mark Origin Position if desired.
    if (systemIsWarm && (Command_PleaseMarkThisAsOrigin > Command_PleaseMarkThisAsOrigin_OLD)){
        Position_Origin_Longitude     = Position_Longitude;
        Position_Origin_Latitude      = Position_Latitude;
        Position_Origin_Altitude      = Position_Altitude;
        }
    Command_PleaseMarkThisAsOrigin_OLD = Command_PleaseMarkThisAsOrigin;

//Continuously determine position from origin.
    Position_DistanceFromOrigin_X = Position_Longitude - Position_Origin_Longitude;
    Position_DistanceFromOrigin_Y = Position_Latitude - Position_Origin_Latitude;
    Position_FromOrigin_Distance    = pow((float) (pow((float) Position_DistanceFromOrigin_Y, (float) 2.0) +pow((float) Position_DistanceFromOrigin_X, (float) 2.0)), (float) 0.5);
    Position_FromOrigin_Azimuth     = atan2((float) Position_DistanceFromOrigin_X, (float) Position_DistanceFromOrigin_Y)/deg;
    Position_FromOrigin_Altitude  = Position_Altitude - Position_Origin_Altitude;

//Determine if craft is approaching a ceiling
    tooHigh = 0;
    tooHighA = 0;
    tooHighB = 0;
    if ((Position_FromOrigin_Altitude + AutoPilot_distanceNeededToStopAircraft)  > Setpoint_Ceiling_DistanceAboveTakeoff){
        tooHighA = ((Position_FromOrigin_Altitude + AutoPilot_distanceNeededToStopAircraft) - Setpoint_Ceiling_DistanceAboveTakeoff) / AutoPilot_distanceNeededToStopAircraft;
        }
    if ((Position_Altitude + AutoPilot_distanceNeededToStopAircraft)  > Setpoint_Ceiling_SeaLevel){
        tooHighB = ((Position_Altitude + AutoPilot_distanceNeededToStopAircraft) - Setpoint_Ceiling_SeaLevel) / AutoPilot_distanceNeededToStopAircraft;
        }
    if (tooHighA > tooHigh) tooHigh = tooHighA;
    if (tooHighB > tooHigh) tooHigh = tooHighB;
    //qDebug() << "TooHigh= " << tooHigh << "Altitude above origin=" << Position_FromOrigin_Altitude << "Altitude=" << Position_Altitude;


//Disable autopilot when touchdown -->lock motors
    if (!Position_CraftIsAirborne && Position_CraftIsAirborne_OLD){  //Ftrigger CraftIsAirborne
        if (AutoPilot_Enabled)       AutoPilot_Enabled         = 5;
        }
    Position_CraftIsAirborne_OLD = Position_CraftIsAirborne;

//Lock motors on boot
    if (!systemIsWarm)  {
        UserInput_AutoClimb                     = 1;
        UserInput_AutoLateral                   = 1;
        UserInput_AutoYaw                       = 1;
        AutoPilot_Enabled = 5;
        }

//Autopilot - Enter and Exit, mode changes
    if (AutoPilot_Enabled && !AutoPilot_Enabled_OLD){               //Rtrigger AutoPilot
        GoBack_UserInput_AutoClimb              = UserInput_AutoClimb;
        GoBack_UserInput_AutoLateral            = UserInput_AutoLateral;
        GoBack_UserInput_AutoYaw                = UserInput_AutoYaw;
        }
    if (!AutoPilot_Enabled && AutoPilot_Enabled_OLD){               //Ftrigger Autopilot
        //UserInput_AutoClimb                     = GoBack_UserInput_AutoClimb;
        //UserInput_AutoLateral                   = GoBack_UserInput_AutoLateral;
        //UserInput_AutoYaw                       = GoBack_UserInput_AutoYaw;
        UserInput_AutoClimb                     = 1;
        UserInput_AutoLateral                   = 1;
        UserInput_AutoYaw                       = 1;
        AutoPilot_Enabled                       = 0;
        AutoPilot_Step               = 0;
        }
    if (AutoPilot_Enabled != AutoPilot_Enabled_OLD){               //Rtrigger AutoPilot
        if (AutoPilot_Enabled == 0) AutoPilot_Step = 0;
        if (AutoPilot_Enabled == 1) AutoPilot_Step = 2; //go home then land
        if (AutoPilot_Enabled == 2) AutoPilot_Step = 5; //land here
        if (AutoPilot_Enabled == 3) AutoPilot_Step = 6; //hold position
        if (AutoPilot_Enabled == 4) AutoPilot_Step = 8; //Up
      //if (AutoPilot_Enabled == 5)                 LOCK ALL MOTORS -- see throtleset cmd at the end of this POU
        }
    AutoPilot_Enabled_OLD = AutoPilot_Enabled;

//Autopilot - Fly Aircraft.
    if  (AutoPilot_Enabled != 0){
        AutoPilot_distanceToNextWaypoint = findDistance(AutoPilot_NextWayPoint_Latitude,
                                              AutoPilot_NextWayPoint_Longitude,
                                              Position_Latitude,
                                              Position_Longitude);
        if  (AutoPilot_Step == 2){          //store old settings, set desired altitude, set next waypoint
            UserInput_AutoClimb                     = 2;
            UserInput_AutoLateral                   = 2;
            UserInput_AutoYaw                       = 2;
            Motion_DesiredAltitudeAboveSeaLevel     = Position_Origin_Altitude + AutoPilot_ReturnHomeAltitudeAboveTakeoff;
            AutoPilot_NextWayPoint_Latitude         = Position_Origin_Latitude;
            AutoPilot_NextWayPoint_Longitude        = Position_Origin_Longitude;
            AutoPilot_Step++;
            }
        if (AutoPilot_Step == 3){    //obtain desired altitude, yaw towards waypoint
            UserInput_AutoClimb                     = 2;
            UserInput_AutoLateral                   = 2;
            UserInput_AutoYaw                       = 2;
            Motion_YawDesiredNoseAzimuth = findAngle(AutoPilot_NextWayPoint_Longitude,
                                                      AutoPilot_NextWayPoint_Latitude,
                                                      Position_Longitude,
                                                      Position_Latitude);
            if (fabs(Motion_DesiredAltitudeAboveSeaLevel - (Position_Origin_Altitude + AutoPilot_ReturnHomeAltitudeAboveTakeoff)) < AutoPilot_ReturnHomeAltitudeObjectiveToleranceReqd)
                AutoPilot_Step++;
            }
        if (AutoPilot_Step == 4){    //travel towards waypoint, then slowdown as it nears
            UserInput_AutoClimb                     = 2;
            UserInput_AutoLateral                   = 2;
            UserInput_AutoYaw                       = 2;
            Motion_YawDesiredNoseAzimuth = findAngle(AutoPilot_NextWayPoint_Longitude,
                                                      AutoPilot_NextWayPoint_Latitude,
                                                      Position_Longitude,
                                                      Position_Latitude);
            Motion_Lateral_VelocDesire_Azi   = Motion_YawDesiredNoseAzimuth;
            transitSpeed = 0;
            if (AutoPilot_distanceToNextWaypoint > AutoPilot_distanceNeededToStopAircraft) {transitSpeed = AutoPilot_MaxTransitSpeed;}
            else {transitSpeed = AutoPilot_distanceToNextWaypoint / AutoPilot_distanceNeededToStopAircraft;}
            Motion_Lateral_VelocDesire_Mag   = transitSpeed * Characteristic_topSpeed * Control_Lateral_TopSpeedCorrectionK  ;  //we really want to reach top speed
            if (AutoPilot_distanceToNextWaypoint < AutoPilot_wayPointDistanceTolerance) AutoPilot_Step++;
            }
        if (AutoPilot_Step == 5){        //stop lateral transit, then descend.
            UserInput_AutoLateral                   = 3;                        //lateral
            Motion_Lateral_VelocDesire_Mag          = 0;                        //lateral
            Motion_Lateral_VelocDesire_Azi          = 0;                        //lateral
            UserInput_AutoYaw                       = 3;                        //yaw
            Motion_Yaw_VelocityDesired              = 0;                        //yaw
            UserInput_AutoClimb                     = 4;                        //climb
            Motion_ClimbRate_Desired                = AutoPilot_descentRate;    //climb
            }
        //HOLD
        if (AutoPilot_Step == 6){        //Hold current position
            Motion_DesiredAltitudeAboveSeaLevel     = Position_Altitude;
            AutoPilot_Step++;
            }
        if (AutoPilot_Step == 7){        //continue holding position
            UserInput_AutoLateral                   = 3;                        //lateral
            Motion_Lateral_VelocDesire_Mag          = 0;                        //lateral
            Motion_Lateral_VelocDesire_Azi          = 0;                        //lateral
            UserInput_AutoYaw                       = 3;                        //yaw
            Motion_Yaw_VelocityDesired              = 0;                        //yaw
            UserInput_AutoClimb                     = 2;                        //climb
            }
        //UP
        if (AutoPilot_Step == 8){        //Straight up
            UserInput_AutoLateral                   = 3;                        //lateral
            Motion_Lateral_VelocDesire_Mag          = 0;                        //lateral
            Motion_Lateral_VelocDesire_Azi          = 0;                        //lateral
            UserInput_AutoYaw                       = 3;                        //yaw
            Motion_Yaw_VelocityDesired              = 0;                        //yaw
            UserInput_AutoClimb                     = 3;                        //climb
            Motion_ClimbRate_Desired                = 1000;
            }
    }


//DETERMINE DESIRED DIRECTION OF TRAVEL OR TILT
    if (UserInput_ControlAzimuthIsHeliRelative){
        UserInput_Travel_Azi = UserInput_DirectionStick_Azi;
        UserInput_Travel_Azi = UserInput_DirectionStick_Azi + Position_FromOrigin_Azimuth;
    }else{
        UserInput_Travel_Azi = UserInput_DirectionStick_Azi + Motion_Yaw_AircraftNose_Azi;
        }


//TAKE ACTION BASED ON LATERAL CONTROL MODE
    if (UserInput_AutoLateral == 0){
        Motion_Tilt_Desired_Mag    = UserInput_DirectionStick_Mag * Characteristic_maxTiltForDesiredClimb;
        Motion_Tilt_Desired_Azi    = UserInput_Travel_Azi;
    }else{
        if (UserInput_AutoLateral ==1){
        Motion_Lateral_VelocDesire_Mag   = UserInput_DirectionStick_Mag * Characteristic_topSpeed * Control_Lateral_TopSpeedCorrectionK  ;  //we really want to reach top speed
        Motion_Lateral_VelocDesire_Azi   = UserInput_Travel_Azi;
        }


    subtractVect(Motion_Lateral_VelocityError_Mag  , Motion_Lateral_VelocityError_Azi,
                 Motion_Lateral_Velocity_Mag       , Motion_Lateral_Velocity_Azi,
                 Motion_Lateral_VelocDesire_Mag, Motion_Lateral_VelocDesire_Azi);     //desired lateral velocity
    magToIntegrate = Motion_Lateral_VelocityError_Mag * secondsElapsed;
    addVect(Motion_Lateral_VelocErr_Integrated_Mag,   Motion_Lateral_VelocErr_Integrated_Azi,
            Motion_Lateral_VelocErr_Integrated_Mag,   Motion_Lateral_VelocErr_Integrated_Azi,
            magToIntegrate                   ,   Motion_Lateral_VelocityError_Azi);
    if (Motion_Lateral_VelocErr_Integrated_Mag >  Control_Lateral_I_MaxWindup) Motion_Lateral_VelocErr_Integrated_Mag =  Control_Lateral_I_MaxWindup;
    if (Motion_Lateral_VelocErr_Integrated_Mag < -Control_Lateral_I_MaxWindup) Motion_Lateral_VelocErr_Integrated_Mag = -Control_Lateral_I_MaxWindup;
    //if (Motion_Lateral_VelocityError_Mag < 1.0) Motion_Lateral_VelocErr_Integrated_Mag = 0;//prevent windup

    static float Motion_Lateral_VelocErr_Integrated_Mag_OLD;
    float Motion_Lateral_VelocErr_Integrated_MagD;
    Motion_Lateral_VelocErr_Integrated_MagD = (Motion_Lateral_VelocErr_Integrated_Mag - Motion_Lateral_VelocErr_Integrated_Mag_OLD) /secondsElapsed;
    Motion_Lateral_VelocErr_Integrated_Mag_OLD = Motion_Lateral_VelocErr_Integrated_Mag;
    if (Motion_Lateral_VelocErr_Integrated_MagD > Control_Lateral_I_MaxWindup)
        Motion_Lateral_VelocErr_Integrated_Mag = 0;
        //greater than topSpeed change in err per second demonstrates
        //conditions have changed and the old integral no longer applies

    if (fabs(normalizeAngleMagnitude(
                normalizeAngl(Motion_Lateral_VelocityError_Azi) -
                normalizeAngl(Motion_Lateral_VelocErr_Integrated_Azi))) > 90)
                    Motion_Lateral_VelocErr_Integrated_Mag = 0;//prevent windup

    //    qDebug() << Motion_Lateral_VelocityError_Azi << Motion_Lateral_VelocErr_Integrated_Azi;
    Motion_Lateral_EffectOf_P_Mag = Motion_Lateral_VelocityError_Mag       * Control_Lateral_P;
    Motion_Lateral_EffectOf_P_Azi = Motion_Lateral_VelocityError_Azi;
  //Motion_Lateral_EffectOf_D_Mag = lateralVelocityErrorDMag               * Control_Lateral_D;
  //Motion_Lateral_EffectOf_D_Azi = lateralVelocityErrorDAng;
    Motion_Lateral_EffectOf_D_Mag = Motion_Lateral_Accelration_Mag         * Control_Lateral_D;
    Motion_Lateral_EffectOf_D_Azi = Motion_Lateral_Accelration_Azi;
    Motion_Lateral_EffectOf_I_Mag = Motion_Lateral_VelocErr_Integrated_Mag * Control_Lateral_I;
    Motion_Lateral_EffectOf_I_Azi = Motion_Lateral_VelocErr_Integrated_Azi;
    addVect(Motion_Tilt_Desired_Mag,Motion_Tilt_Desired_Azi,
            Motion_Lateral_EffectOf_P_Mag,       Motion_Lateral_EffectOf_P_Azi,
            Motion_Lateral_EffectOf_D_Mag,       Motion_Lateral_EffectOf_D_Azi);
    addVect(Motion_Tilt_Desired_Mag,Motion_Tilt_Desired_Azi,
            Motion_Tilt_Desired_Mag,       Motion_Tilt_Desired_Azi,
            Motion_Lateral_EffectOf_I_Mag,       Motion_Lateral_EffectOf_I_Azi);
    Motion_Tilt_Desired_Mag        = Motion_Tilt_Desired_Mag * Characteristic_maxTiltForDesiredClimb;
    if (Motion_Tilt_Desired_Mag > Characteristic_maxTiltForDesiredClimb)  Motion_Tilt_Desired_Mag = Characteristic_maxTiltForDesiredClimb;
    Motion_Tilt_Desired_Azi = Motion_Tilt_Desired_Azi;
    }
    static float topSpeedCalc;
    static int pauseSpeedCalc;
    static int weHaveGuessedTopSpeed;
    if (Characteristic_topSpeedZeroClimb < 2) Characteristic_topSpeedZeroClimb = 10;
    if ((Motion_Lateral_Accelration_Mag < 0.04) && pauseSpeedCalc == 0 && Motion_Lateral_Velocity_Mag > 2.0){
        topSpeedCalc = (Motion_Lateral_Velocity_Mag / powf(Thrust_Lateral, 0.5));
        pauseSpeedCalc = 1;
        if (weHaveGuessedTopSpeed == 0){
            if (Characteristic_topSpeedZeroClimb < topSpeedCalc) Characteristic_topSpeedZeroClimb = topSpeedCalc;
            }
        if (weHaveGuessedTopSpeed == 1){
            Characteristic_topSpeedZeroClimb = 0.9 * Characteristic_topSpeedZeroClimb + 0.1 * topSpeedCalc;
            }
        weHaveGuessedTopSpeed = 1;
        }
    if (Motion_Lateral_Accelration_Mag > 0.04) pauseSpeedCalc = 0;
    if (Motion_Lateral_Velocity_Mag >Characteristic_topSpeedZeroClimb) Characteristic_topSpeedZeroClimb = Motion_Lateral_Velocity_Mag * 1.1;

    Characteristic_topSpeed = Characteristic_topSpeedZeroClimb;
    //if (maxTiltForDesiredClimb > maxTiltForZeroClimb ) Characteristic_topSpeed = Characteristic_topSpeed *2;


//DETERMINE DESIRED THROTTLE
   if (UserInput_AutoClimb ==0 && tooHigh <= 0) {
        Thrust_ThrottleSignal = UserInput_ThrottleStick;
        }
   if (UserInput_AutoClimb>=1)  {
       if (UserInput_AutoClimb == 1 || tooHigh > 0){  //assisted throttle mode
           UserInput_ThrottleStickEnhanced  = pow(fabs(UserInput_ThrottleStick),(float) UserInput_Sensitivity_Throttle);        //FIXME THIS Should be a settable ctrl stick sensitivity
            if (UserInput_ThrottleStick <0) UserInput_ThrottleStickEnhanced = UserInput_ThrottleStickEnhanced * -1.0;
            Motion_ClimbRate_Desired         = UserInput_ThrottleStickEnhanced * Characteristic_topSpeed ;
            Motion_AltitudeError = 0;
            if (tooHigh > 0.0) {
                if (Motion_ClimbRate_Desired > 0)  Motion_ClimbRate_Desired = 0;
                }
            /*
            if ((tooHigh > 0.0)&& (tooHigh < 0.9)) {    //approaching limit --> slow ascent
                if (Motion_ClimbRate_Desired > 0)  Motion_ClimbRate_Desired = 0;
                }
                //if (Motion_ClimbRate_Desired > -AutoPilot_descentRate * tooHigh)  Motion_ClimbRate_Desired = AutoPilot_descentRate * tooHigh;
                */

            }
       if (UserInput_AutoClimb == 2 && tooHigh <= 0){ //altitude command mode
            Motion_AltitudeError        = Position_Altitude - Motion_DesiredAltitudeAboveSeaLevel;
            Motion_ClimbRate_Desired    = -Motion_AltitudeError * Motion_AltitudeErrorP;
            }


       static float climbRate_OLD;
       Motion_climbAcceleration         = (Motion_ClimbRate_Actual - climbRate_OLD) / secondsElapsed;
       climbRate_OLD                    = Motion_ClimbRate_Actual;
       Motion_climbRateError            = Motion_ClimbRate_Actual - Motion_ClimbRate_Desired;
       Motion_climbRateErrorD           = (Motion_climbRateError - climbRateError_OLD) / secondsElapsed;
       climbRateError_OLD               = Motion_climbRateError;
       Motion_ClimbRateError_Integrated = Motion_ClimbRateError_Integrated + Motion_climbRateError * secondsElapsed;
       if (Motion_ClimbRateError_Integrated >  Control_Climb_I_MaxWindup ) Motion_ClimbRateError_Integrated =   Control_Climb_I_MaxWindup;
       if (Motion_ClimbRateError_Integrated < -Control_Climb_I_MaxWindup ) Motion_ClimbRateError_Integrated =  -Control_Climb_I_MaxWindup;
       Motion_Climb_EffectOf_P          = Motion_climbRateError            * Control_Climb_P;
       Motion_Climb_EffectOf_I          = Motion_ClimbRateError_Integrated * Control_Climb_I;
     //Motion_Climb_EffectOf_D          = Motion_climbRateErrorD           * climb_d;
       Motion_Climb_EffectOf_D          = Motion_climbAcceleration         * Control_Climb_D;
       Thrust_ThrottleSignal                      = Motion_Climb_EffectOf_P + Motion_Climb_EffectOf_I + Motion_Climb_EffectOf_D;
       Thrust_ThrottleSignal                      = Thrust_ThrottleSignal; // cos(TiltAmount * deg);  //more total thrust is needed when tilted
        }
       if (freezeSimulatedHeli >= 1){
            Thrust_ThrottleSignal = 0.4;
            }
       Thrust_ThrottleSignal= Thrust_ThrottleSignal / cos(Motion_Tilt_Actual_Mag * deg);

       // FIXME THE STATEMENT HERE does not assign anything to Thrust_ThrottleSignal!
       if (Motion_Tilt_Desired_Mag > Characteristic_maxTiltForZeroClimb)
         Thrust_ThrottleSignal = Thrust_ThrottleSignal + (Motion_Tilt_Desired_Mag - Characteristic_maxTiltForZeroClimb) / (90.0 - Characteristic_maxTiltForZeroClimb);





       //qDebug() << Thrust_ThrottleSignal << TiltDesired;







       if (Thrust_ThrottleSignal < 0 ) Thrust_ThrottleSignal = 0;
       if (Thrust_ThrottleSignal > 1 ) Thrust_ThrottleSignal = 1;
       //qDebug() << Thrust_ThrottleSignal;

//Determine Predicted Thrust and Downward thrust
       motorSpoolK = exp(- secondsElapsed / motor_ResponseTC);
       Thrust_PredictedActual = 0;
       if (SystemIsWarm == 0){
           SystemIsWarm = 1;
           for (int x = 1; x <= numberOfMotors; x++) predictedActualThrust[x] = 0;
       }else{
           for (int x = 1; x <= numberOfMotors; x++) {
               predictedActualThrust[x] = getThrottleVal(x) * (1- motorSpoolK) + predictedActualThrust[x] * motorSpoolK;
               Thrust_PredictedActual = Thrust_PredictedActual + predictedActualThrust[x];
               }
           }
       Thrust_PredictedActual = Thrust_PredictedActual / numberOfMotors;
       Thrust_Downward        = Thrust_PredictedActual * cos(Motion_Tilt_Actual_Mag * deg);
       Thrust_Lateral         = Thrust_PredictedActual * sin(Motion_Tilt_Actual_Mag * deg);


//Determine Craft Weight
        static  int numberOfSamples;
        if ((fabs((float) Motion_ClimbRate_Actual) < (float) 0.1) && Position_CraftIsAirborne) {
            if (numberOfSamples < 1000) numberOfSamples++;
            if (numberOfSamples <= 1)  Characteristic_craftWeight = Thrust_Downward;
            if (numberOfSamples <= 3)  Characteristic_craftWeight = Characteristic_craftWeight * 0.5  + Thrust_Downward * 0.5;
            if (numberOfSamples <= 10) Characteristic_craftWeight = Characteristic_craftWeight* 0.9  + Thrust_Downward * 0.1;
                                       Characteristic_craftWeight = Characteristic_craftWeight * 0.99 + Thrust_Downward * 0.01;
            }
        float safeWeight = (Characteristic_craftWeight) * 1.10;
        if (safeWeight < 0) safeWeight = 0;
        if (safeWeight > 1) safeWeight = 1;
        Characteristic_maxTiltForDesiredClimb  = (acos(safeWeight) / deg);
        Characteristic_maxTiltForZeroClimb     = (acos(safeWeight) / deg);

        unityDesiredClimbRate =  -1.0 * Motion_climbRateError / Characteristic_topSpeed;
        if (unityDesiredClimbRate  > 1) unityDesiredClimbRate  =  1;
        if (unityDesiredClimbRate < -1) unityDesiredClimbRate  = -1;

        if (unityDesiredClimbRate < 0){
            Characteristic_maxTiltForDesiredClimb = Characteristic_maxTiltForZeroClimb + (90.0 - Characteristic_maxTiltForZeroClimb)  * fabs((float) unityDesiredClimbRate);
            }
        if (unityDesiredClimbRate > 0){
            Characteristic_maxTiltForDesiredClimb = Characteristic_maxTiltForZeroClimb -        (Characteristic_maxTiltForZeroClimb)  * fabs((float) unityDesiredClimbRate);
            }

        //qDebug() << ThrottleStick;
        //qDebug() << maxTiltForDesiredClimb;
      //  qDebug() << craftWeight;

//CONTROL HELICOPTER ROLL TO MATCH DESIRED ROLL
        //Calculate Tilt Error
        NormalizeAndFindDifference(
                      Motion_Tilt_Error_Mag,
                      Motion_Tilt_Error_Azi,
                                            Motion_Tilt_Actual_Mag,
                                            Motion_Tilt_Actual_Azi,
                                                                    Motion_Tilt_Desired_Mag,
                                                                    Motion_Tilt_Desired_Azi);
        Motion_Tilt_Error_Mag  = Motion_Tilt_Error_Mag / 180.0;  //1 means we are tilted 180 out
        //Calculate needed tilt force and corresponding throttle values
        if (Control_Tilt_PleaseUseGyroAndAccel == 1){
            NormalizeAndFindDifference(
                          Motion_Tilt_Velocity_Composite_Mag,
                          Motion_Tilt_Velocity_Composite_Azi,
                                        Motion_Tilt_Actual_Mag,
                                        Motion_Tilt_Actual_Azi,
                                                            TiltAmount_OLD,
                                                            TiltAmountAzimuth_OLD);
            Motion_Tilt_Velocity_Composite_Mag = Motion_Tilt_Velocity_Composite_Mag / 360;
            Motion_Tilt_Velocity_Composite_Azi = Motion_Tilt_Velocity_Composite_Azi / (secondsElapsed);
            TiltAmount_OLD                   = Motion_Tilt_Actual_Mag;
            TiltAmountAzimuth_OLD            = Motion_Tilt_Actual_Azi;
        }else{
            Motion_Tilt_Velocity_Composite_Mag        = (Motion_Tilt_Velocity_Mems_Mag  * 2 / 60.0);  //convert RPM -->  halfRevolution / Second
            Motion_Tilt_Velocity_Composite_Azi        =  Motion_Tilt_Velocity_Mems_Azi;
            }
        Motion_Tilt_EffectOf_P_Mag = Motion_Tilt_Error_Mag  * Control_Tilt_P;
        Motion_Tilt_EffectOf_P_Azi = Motion_Tilt_Error_Azi;
        Motion_Tilt_EffectOf_D_Mag = Motion_Tilt_Velocity_Composite_Mag * Control_Tilt_D;
        Motion_Tilt_EffectOf_D_Azi = Motion_Tilt_Velocity_Composite_Azi;
        addVect(Motion_Tilt_TorqueNeeded_Mag,
                Motion_Tilt_TorqueNeeded_Azi,
                                            Motion_Tilt_EffectOf_P_Mag,
                                            Motion_Tilt_EffectOf_P_Azi,
                                                                        Motion_Tilt_EffectOf_D_Mag,
                                                                        Motion_Tilt_EffectOf_D_Azi);
        Motion_Tilt_TorqueNeeded_Azi = Motion_Tilt_TorqueNeeded_Azi - Motion_Yaw_AircraftNose_Azi;
        calculateThrottleValues(throttleValues, Thrust_ThrottleSignal, Motion_Tilt_TorqueNeeded_Mag,
                                                                       Motion_Tilt_TorqueNeeded_Azi);

//DETERMINE DESIRED YAW FORCE AND ADJUST MOTOR VALUES AS NECESSARRY
        Motion_Yaw_UserCommand         = UserInput_Trigger_Right - UserInput_Trigger_Left;
        Motion_Yaw_TorqueRequested     = 0;
        if (UserInput_AutoYaw == 0){
            Motion_Yaw_TorqueRequested = Motion_Yaw_UserCommand;
            }
        if (UserInput_AutoYaw >=1){
            if (UserInput_AutoYaw ==1){
                Motion_Yaw_VelocityDesired = Motion_Yaw_UserCommand * Control_Yaw_MaxYawRateDesired;
                }
            if (UserInput_AutoYaw ==2){
                Motion_NoseAzimuthError     =  Motion_Yaw_AircraftNose_Azi - Motion_YawDesiredNoseAzimuth;
                Motion_NoseAzimuthError = normalizeAngleMagnitude(Motion_NoseAzimuthError);
                Motion_Yaw_VelocityDesired  = -Motion_NoseAzimuthError * Motion_YawNoseErrorP +
                                               Motion_Yaw_Velocity * Motion_YawNoseErrorD;
                }
            Motion_Yaw_Error_P         = Motion_Yaw_Velocity - Motion_Yaw_VelocityDesired;
            //int negative = 0; if (Motion_Yaw_Error_P <0) negative = 1;
            //Motion_Yaw_Error_P         = powf(fabs((float)Motion_Yaw_Error_P), Motion_YawNoseErrorPexponent);
            //if (negative) Motion_Yaw_Error_P = -1 * Motion_Yaw_Error_P;

            Motion_Yaw_Error_D         = (Motion_Yaw_Error_P - yaw_P_Error_OLD) / secondsElapsed;
            yaw_P_Error_OLD            = yaw_P_Error_OLD;
            Motion_Yaw_Error_I         = (Motion_Yaw_Error_I + Motion_Yaw_Error_P) * secondsElapsed;
            if (Motion_Yaw_Error_I >  Control_Yaw_I_MaxWindup) Motion_Yaw_Error_I =  Control_Yaw_I_MaxWindup;
            if (Motion_Yaw_Error_I < -Control_Yaw_I_MaxWindup) Motion_Yaw_Error_I = -Control_Yaw_I_MaxWindup;
            Motion_Yaw_EffectOf_P      = Motion_Yaw_Error_P * Control_Yaw_P;
            Motion_Yaw_EffectOf_I      = Motion_Yaw_Error_I * Control_Yaw_I;
            //Motion_Yaw_EffectOf_D      = Motion_Yaw_Error_D * Control_Yaw_D;
            Motion_Yaw_EffectOf_D      = Motion_Yaw_Velocity * Control_Yaw_D;
            Motion_Yaw_TorqueRequested = Motion_Yaw_EffectOf_P + Motion_Yaw_EffectOf_I + Motion_Yaw_EffectOf_D;
            }
        //Add Yaw Input to Motors
        Thrust_MotorThrottleSummation = 0;
        for (int x = 1; x <= numberOfMotors; x++){
            Thrust_MotorThrottleSummation = Thrust_MotorThrottleSummation + throttleValues[x];
            }
        Thrust_MotorThrottleSummation = Thrust_MotorThrottleSummation / numberOfMotors;
        Motion_Yaw_MaxRateNoClimbEffect = (0.5 - fabs(0.5 - Thrust_MotorThrottleSummation));
        for (int x = 1; x <= numberOfMotors; x++){
            if (doesRotateClockwise_motor[x]) motorDirection = -1;
            else motorDirection = 1;
            throttleValues[x] = throttleValues[x] + motorDirection * Motion_Yaw_TorqueRequested * Motion_Yaw_MaxRateNoClimbEffect;
            }
    systemIsWarm = 1;
//SET MOTOR VALUES
    if (AutoPilot_Enabled != 5) {
        for (int x = 1; x <=numberOfMotors; x++) setMotor(x, throttleValues[x]);
        }
    else{
        for (int x = 1; x <=numberOfMotors; x++) setMotor(x, 0);
        }
    }







#endif // Z01_SIMFLIGHTCONTROL_H
