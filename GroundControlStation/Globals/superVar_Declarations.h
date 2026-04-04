#ifndef SUPERVAR_DECLARE2_H
#define SUPERVAR_DECLARE2_H
//Flightboard Variables
     unsigned char guardA;
     float Sensor_Accelerometer_X;
     float Sensor_Accelerometer_Y;
     float Sensor_Accelerometer_Z;
     unsigned short int FlighboardErrorCode;
     unsigned short int FlighboardErrorCode2;
     QString FlighboardErrorString;
     float Sensor_Accelerometer_Magnitude;
     float Sensor_Accelerometer_RelAzimuth;
     float Sensor_Accelerometer_RelIncline;
     float Sensor_Compass_X;
     float Sensor_Compass_Y;
     float Sensor_Compass_Z;
     float Sensor_Compass_FieldStrength;
     float Sensor_Compass_NorthRelAzimuth;
     float Sensor_Compass_NorthRel_Incline;
     float Sensor_Baro_psia;
     float Sensor_Baro_altimeter;
     float Sensor_Baro_temp;
     float Sensor_Gyro_yawRate;
     float Sensor_Gyro_pitchRate;
     float Sensor_Gyro_rollRate;
     float Sensor_Gyro_RelAzimuth;
     float Sensor_Gyro_Rel_Incline;
     float Sensor_Gyro_Rate;
     unsigned char Sensor_GPS_IsAvailable;
     ullint Sensor_GPS_Time;
     unsigned short int Sensor_GPS_Altitude;
     double Sensor_GPS_Lattitude;
     double Sensor_GPS_Longitude;
     float Sensor_GPS_Heading;
     float Sensor_GPS_Speed;
     float Sensor_GPS_Climbrate;
     float Battery_ActualVoltage;
     float Battery_EffectiveVoltage;
     float Battery_PercentRemainingInstantaneous;
     float Battery_PercentRemainingFiltered;
     float Battery_batteryPercentPerMinute;
     float Battery_flightTimeRemaining;
     float throttleValues[7];
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
     float secondsElapsed;
     unsigned char AutoPilot_Enabled;
     unsigned char UserInput_AutoClimb;
     unsigned char UserInput_AutoLateral;
     unsigned char UserInput_AutoYaw;
     unsigned char UserInput_ControlAzimuthIsHeliRelative;
     unsigned int paramSetChecksum_Flightboard;
     unsigned int counter_FB_mainLoop;
     unsigned int counter_FB_push_1;
     unsigned int counter_FB_push_2;
     unsigned int counter_FB_push_3;
     unsigned int counter_FB_get_1;
     unsigned int counter_FB_get_2;
     unsigned int bufferVar_DoNotUse;
     unsigned short int xx_VAR_ID_OF_HIGHEST_I2C_POLLED_VAR_xx;
     unsigned char I2C_Error;
     unsigned short int I2C_PollingPeriodMsecs;
     unsigned char ControllerInput[3];
//intentionally blank
//intentionally blank
//intentionally blank
     unsigned short int ControllerInput_LT;
     unsigned short int ControllerInput_RT;
     unsigned short int ControllerInput_LJ_Mag;
     unsigned short int ControllerInput_LJ_Ang;
     unsigned short int ControllerInput_RJ_Mag;
     unsigned short int ControllerInput_RJ_Ang;
//Used by flight algorithm and flight sim
     float UserInput_DirectionStick_Mag;
     float UserInput_DirectionStick_Azi;
     float UserInput_Travel_Mag;
     float UserInput_Travel_Azi;
     float UserInput_ThrottleStick;
     float UserInput_ThrottleStickEnhanced;
     float UserInput_Trigger_Right;
     float UserInput_Trigger_Left;
     unsigned short int AutoPilot_ConnectionStatusOfHeli;
//Modes
     float AutoPilot_CommLoss_Delay_PositionHold;
     int AutoPilot_CommLoss_Delay_PositionHold_Enabled;
     float AutoPilot_CommLoss_Delay_ReturnHome;
     int AutoPilot_CommLoss_Delay_ReturnHome_Enabled;
     float AutoPilot_CommLoss_Delay_Land;
     int AutoPilot_CommLoss_Delay_Land_Enabled;
     int AutoPilot_LowBatt_Percent_ReturnHome_AutoSetEnabled;
     float AutoPilot_LowBatt_Percent_ReturnHome;
     int AutoPilot_LowBatt_Percent_ReturnHome_Enabled;
     float AutoPilot_LowBatt_Percent_LandNow;
     int AutoPilot_LowBatt_Percent_LandNow_Enabled;
     float AutoPilot_LowBatt_Percent_KillSystem;
     int AutoPilot_LowBatt_Percent_KillSystem_Enabled;
     float AutoPilot_LowBatt_Percent_TimeDelay;
     float AutoPilot_ReturnHomeAltitudeAboveTakeoff;
     float AutoPilot_ReturnHomeAltitudeObjectiveToleranceReqd;
     float AutoPilot_distanceToNextWaypoint;
     float AutoPilot_distanceNeededToStopAircraft;
     float AutoPilot_wayPointDistanceTolerance;
     float AutoPilot_MaxTransitSpeed;
     float AutoPilot_descentRate;
     int AutoPilot_Step;
     double AutoPilot_NextWayPoint_Latitude;
     double AutoPilot_NextWayPoint_Longitude;
     int GoBack_UserInput_AutoClimb;
     int GoBack_UserInput_AutoLateral;
     int GoBack_UserInput_AutoYaw;
//Position
     double Position_Latitude;
     double Position_Longitude;
     float Position_Altitude;
     double Position_Origin_Latitude;
     double Position_Origin_Longitude;
     float Position_Origin_Altitude;
     float Position_DistanceFromOrigin_X;
     float Position_DistanceFromOrigin_Y;
     float Position_FromOrigin_Distance;
     float Position_FromOrigin_Azimuth;
     float Position_FromOrigin_Altitude;
     int Position_CraftIsAirborne;
     float tooHigh;
//Lateral
     float Motion_Lateral_EffectOf_P_Mag;
     float Motion_Lateral_EffectOf_P_Azi;
     float Motion_Lateral_EffectOf_I_Mag;
     float Motion_Lateral_EffectOf_I_Azi;
     float Motion_Lateral_EffectOf_D_Mag;
     float Motion_Lateral_EffectOf_D_Azi;
     float Motion_Lateral_VelocErr_Integrated_Mag;
     float Motion_Lateral_VelocErr_Integrated_Azi;
     float Motion_Lateral_VelocityError_Mag;
     float Motion_Lateral_VelocityError_Azi;
     float Motion_Lateral_VelocDesire_Mag;
     float Motion_Lateral_VelocDesire_Azi;
     float Motion_Lateral_Accelration_Mag;
     float Motion_Lateral_Accelration_Azi;
     float Motion_Lateral_Velocity_Mag;
     float Motion_Lateral_Velocity_Azi;
     float Motion_Tilt_Desired_Mag;
     float Motion_Tilt_Desired_Azi;
     float Motion_Tilt_EffectOf_P_Mag;
     float Motion_Tilt_EffectOf_P_Azi;
     float Motion_Tilt_EffectOf_D_Mag;
     float Motion_Tilt_EffectOf_D_Azi;
     float Motion_Tilt_Error_Mag;
     float Motion_Tilt_Error_Azi;
     float Motion_Tilt_Velocity_Composite_Mag;
     float Motion_Tilt_Velocity_Composite_Azi;
     float Motion_Tilt_Velocity_Mems_Mag ;
     float Motion_Tilt_Velocity_Mems_Azi;
     float Motion_Tilt_TorqueNeeded_Mag;
     float Motion_Tilt_TorqueNeeded_Azi;
     float Motion_Tilt_Actual_Mag;
     float Motion_Tilt_Actual_Azi;
//Yaw
     float Motion_YawDesiredNoseAzimuth;
     float Motion_NoseAzimuthError;
     float Motion_YawNoseErrorP;
     float Motion_YawNoseErrorD;
     float Motion_Yaw_UserCommand;
     float Motion_Yaw_MaxRateNoClimbEffect;
     float Motion_Yaw_AircraftNose_Azi;
     float Motion_Yaw_Error_P;
     float Motion_Yaw_Error_I;
     float Motion_Yaw_Error_D;
     float Motion_Yaw_EffectOf_P;
     float Motion_Yaw_EffectOf_I;
     float Motion_Yaw_EffectOf_D;
     float Motion_Yaw_Velocity;
     float Motion_Yaw_TorqueRequested;
     float Motion_Yaw_VelocityRequested;
     float Motion_Yaw_VelocityError;
     float Motion_Yaw_Acceleration;
     float Motion_Yaw_VelocityError_Integrated;
     float Motion_Yaw_VelocityDesired;
     float Motion_Yaw_MaxYawRateDesired;
     float Sensor_Composite_NoseAzimuth;
//Vertical
     float Motion_DesiredAltitudeAboveSeaLevel;
     float Motion_DesiredAltitudeAboveTakeoff;
     float Motion_AltitudeError;
     float Motion_AltitudeErrorP;
     float Motion_ClimbRate_Actual;
     float Motion_ClimbRate_Desired;
     float Motion_Climb_EffectOf_P;
     float Motion_Climb_EffectOf_I;
     float Motion_Climb_EffectOf_D;
     float Motion_climbRateErrorD;
     float Motion_climbAcceleration;
     float Motion_climbRateError;
     float Motion_ClimbRateError_Integrated;
     float Thrust_ThrottleSignal;
     float Thrust_MotorThrottleSummation;
     float Thrust_PredictedActual;
     float Thrust_Downward;
     float Thrust_Lateral;
     float Characteristic_craftWeight;
     float Characteristic_maxTiltForDesiredClimb;
     float Characteristic_maxTiltForZeroClimb;
     float Characteristic_topSpeed;
     float Characteristic_topSpeedZeroClimb;
//Motors
     float predictedActualThrust[7];
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
     unsigned char motorFailureDetected[7];
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//Sensors
     float Sensor_AccelerometerOrientationAccuracyMagnitude;
     float Sensor_AccelerometerOrientationRelAzimuth;
     float Sensor_AccelerometerOrientationRel_Incline;
     float Sensor_AccelerometerAccelerationAccuracyMagnitude;
     float Sensor_AccelerometerAccelerationRelAzimuth;
     float Sensor_AccelerometerAccelerationRelPitch;
     float Sensor_MagneticOrientationAccuracyMagnitude;
     float Sensor_MagneticOrientationTrueHeading;
     float Sensor_MagneticOrientationRollRelAzimuth;
     float Sensor_MagneticOrientationRoll_Incline;
     float Sensor_Composite_Pitch;
     float Sensor_Composite_Roll;
     float Sensor_Composite_Yaw;
//Motion Characteristics
//Motion Characteristics
//Motion Characteristics
//Motion Characteristics
//Settings and Commands
     float UserInput_Sensitivity_Throttle;
     float UserInput_Sensitivity_DirectionStick;
     float UserInput_Sensitivity_Yaw;
     unsigned char Command_PleaseReturnHome;
     unsigned char Command_PleaseUnlockMotors;
     unsigned char Command_PleaseMarkThisAsOrigin;
     float Setpoint_TransitHomeAltitudeAboveGround;
     float Setpoint_Ceiling_SeaLevel;
     float Setpoint_Ceiling_DistanceAboveTakeoff;
//PID Values
     float Control_Lateral_P;
     float Control_Lateral_D;
     float Control_Lateral_I;
     float Control_Lateral_I_MaxWindup;
     float Control_Lateral_TopSpeedCorrectionK;
     float Control_Climb_P;
     float Control_Climb_D;
     float Control_Climb_I;
     float Control_Climb_I_MaxWindup;
     float Control_Tilt_P;
     float Control_Tilt_D;
     unsigned char Control_Tilt_PleaseUseGyroAndAccel;
     float Control_Yaw_P;
     float Control_Yaw_D;
     float Control_Yaw_I;
     float Control_Yaw_I_MaxWindup;
     float Control_Yaw_MaxYawRateDesired;
//Aircraft Geometry
     float motor_ResponseTC;
     unsigned char numberOfMotors;
     float angle_motor_[7];
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
     unsigned char doesRotateClockwise_motor[7];
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
     unsigned char simuMotorFailure[7];
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//Simulated Heli
//intentionally blank
//intentionally blank
     unsigned char freezeSimulatedHeli;
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//intentionally blank
//Instrumentation
     float Sensor_FilterTimeConstantBarometer;
     float Sensor_FilterTimeConstantAccelerometer;
     float Sensor_FilterTimeConstantGyro;
     float Sensor_FilterTimeConstantCompass;
     float Sensor_FilterTimeConstantGPSHorizontal;
     float Sensor_FilterTimeConstantGPSVertical;
     float Sensor_FilterTimeConstantThrustMagnitudeChange;
     float Sensor_FilterTimeConstantBatteryPercent;
     float Sensor_memsZeroYawRate;
     float Sensor_memsZeroRollRelAzimuth;
     float Sensor_memsZeroRollRate;
     float Sensor_declinationAbsAzimuth;
     float Sensor_declinationAbsPitch;
     float Battery_MinCellvoltage;
     float Battery_MaxCellvoltage;
     float Battery_VoltageDropFullThrottle;
     float Battery_PercentRemainingFilteringTC;
     float Battery_flightTimeNeededToReachHome;
     float testVariable1;
     double testVariable2;
     float debugVar1;
     float debugVar2;
     float debugVar3;
     float debugVar4;
     float debugVar5;
//Netowork and Debugging
     unsigned int paramSetVersion;
     unsigned int paramSetChecksum;
     int HeartbeatInterval;
     int iControllerPacketInterval;
     ullint pollingInterval[3];
//intentionally blank
//intentionally blank
     int expectedPingForThisNetwork;
     int enumIPAddressingMode;
     int HelicopterMode;
     QString sTargetIPAddress;
     int savePolledVarsToDisk;
     unsigned char glbSystemID;



void setVariableData(){
;
//Flightboard Variables
addSuperVar(guardA,     "guardA", I2CFast ,1,"units - comment");
addSuperVar(Sensor_Accelerometer_X,     "Sensor_Accelerometer_X", I2CFast ,1,"units - comment");
addSuperVar(Sensor_Accelerometer_Y,     "Sensor_Accelerometer_Y", I2CFast ,1,"minutes - comment");
addSuperVar(Sensor_Accelerometer_Z,     "Sensor_Accelerometer_Z", I2CFast ,1,"minutes - comment");
addSuperVar(FlighboardErrorCode,     "FlighboardErrorCode", I2CSlow ,1,"minutes - comment");
addSuperVar(FlighboardErrorCode2,     "FlighboardErrorCode2", I2CSlow ,1,"minutes - comment");
addSuperVar(FlighboardErrorString,     "FlighboardErrorString", I2CSlow ,1,"minutes - comment");
addSuperVar(Sensor_Accelerometer_Magnitude,     "Sensor_Accelerometer_Magnitude", I2CSlow ,1,"minutes - comment");
addSuperVar(Sensor_Accelerometer_RelAzimuth,     "Sensor_Accelerometer_RelAzimuth", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Accelerometer_RelIncline,     "Sensor_Accelerometer_RelIncline", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Compass_X,     "Sensor_Compass_X", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Compass_Y,     "Sensor_Compass_Y", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Compass_Z,     "Sensor_Compass_Z", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Compass_FieldStrength,     "Sensor_Compass_FieldStrength", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Compass_NorthRelAzimuth,     "Sensor_Compass_NorthRelAzimuth", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Compass_NorthRel_Incline,     "Sensor_Compass_NorthRel_Incline", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Baro_psia,     "Sensor_Baro_psia", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Baro_altimeter,     "Sensor_Baro_altimeter", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Baro_temp,     "Sensor_Baro_temp", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Gyro_yawRate,     "Sensor_Gyro_yawRate", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Gyro_pitchRate,     "Sensor_Gyro_pitchRate", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Gyro_rollRate,     "Sensor_Gyro_rollRate", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Gyro_RelAzimuth,     "Sensor_Gyro_RelAzimuth", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Gyro_Rel_Incline,     "Sensor_Gyro_Rel_Incline", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Gyro_Rate,     "Sensor_Gyro_Rate", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_GPS_IsAvailable,     "Sensor_GPS_IsAvailable", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_GPS_Time,     "Sensor_GPS_Time", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_GPS_Altitude,     "Sensor_GPS_Altitude", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_GPS_Lattitude,     "Sensor_GPS_Lattitude", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_GPS_Longitude,     "Sensor_GPS_Longitude", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_GPS_Heading,     "Sensor_GPS_Heading", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_GPS_Speed,     "Sensor_GPS_Speed", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_GPS_Climbrate,     "Sensor_GPS_Climbrate", I2CSlow ,1,"units - comment");
addSuperVar(Battery_ActualVoltage,     "Battery_ActualVoltage", I2CSlow ,1,"units - comment");
addSuperVar(Battery_EffectiveVoltage,     "Battery_EffectiveVoltage", I2CSlow ,1,"units - comment");
addSuperVar(Battery_PercentRemainingInstantaneous,     "Battery_PercentRemainingInstantaneous", I2CSlow ,1,"units - comment");
addSuperVar(Battery_PercentRemainingFiltered,     "Battery_PercentRemainingFiltered", I2CSlow ,1,"units - comment");
addSuperVar(Battery_batteryPercentPerMinute,     "Battery_batteryPercentPerMinute", I2CSlow ,1,"units - comment");
addSuperVar(Battery_flightTimeRemaining,     "Battery_flightTimeRemaining", I2CSlow ,1,"units - comment");
//intentionally blank
addSuperVar(throttleValues[0],     "throttleValues[0]", I2CSlow ,1,"units - comment");
addSuperVar(throttleValues[1],     "throttleValues[1]", I2CSlow ,1,"units - comment");
addSuperVar(throttleValues[2],     "throttleValues[2]", I2CSlow ,1,"units - comment");
addSuperVar(throttleValues[3],     "throttleValues[3]", I2CSlow ,1,"units - comment");
addSuperVar(throttleValues[4],     "throttleValues[4]", I2CSlow ,1,"units - comment");
addSuperVar(throttleValues[5],     "throttleValues[5]", I2CSlow ,1,"units - comment");
addSuperVar(throttleValues[6],     "throttleValues[6]", I2CSlow ,1,"units - comment");
addSuperVar(secondsElapsed,     "secondsElapsed", I2CSlow ,1,"units - comment");
addSuperVar(AutoPilot_Enabled,     "AutoPilot_Enabled", I2CSlow   |                      UserEditable ,1,"units - comment");
addSuperVar(UserInput_AutoClimb,     "UserInput_AutoClimb", I2CSlow ,1,"Bool - 0=Manual, 1=Assisted, 2=Fully Automatic(See desired Altitude)");
addSuperVar(UserInput_AutoLateral,     "UserInput_AutoLateral", I2CSlow ,1,"Bool - ");
addSuperVar(UserInput_AutoYaw,     "UserInput_AutoYaw", I2CSlow ,1,"Bool - ");
addSuperVar(UserInput_ControlAzimuthIsHeliRelative,     "UserInput_ControlAzimuthIsHeliRelative", I2CSlow ,1,"Bool - This comes from the left joystick being pressed.");
addSuperVar(paramSetChecksum_Flightboard,     "paramSetChecksum_Flightboard", I2CSlow ,1," - ");
addSuperVar(counter_FB_mainLoop,     "counter_FB_mainLoop", I2CSlow ,1," - ");
addSuperVar(counter_FB_push_1,     "counter_FB_push_1", I2CSlow ,1," - PushPolledVariables();");
addSuperVar(counter_FB_push_2,     "counter_FB_push_2", I2CSlow ,1," - ");
addSuperVar(counter_FB_push_3,     "counter_FB_push_3", I2CSlow ,1," - ");
addSuperVar(counter_FB_get_1,     "counter_FB_get_1", I2CSlow ,1," - getFastVars(); ");
addSuperVar(counter_FB_get_2,     "counter_FB_get_2", I2CSlow ,1," - getRetainVars();");
addSuperVar(bufferVar_DoNotUse,     "bufferVar_DoNotUse", I2CSlow ,1," - ");
addSuperVar(xx_VAR_ID_OF_HIGHEST_I2C_POLLED_VAR_xx,     "xx_VAR_ID_OF_HIGHEST_I2C_POLLED_VAR_xx", noFlags ,1,"units - comment");
addSuperVar(I2C_Error,     "I2C_Error", noFlags ,1,"seconds - -1 for disabled");
addSuperVar(I2C_PollingPeriodMsecs,     "I2C_PollingPeriodMsecs", noFlags ,1,"seconds - -1 for disabled");
//intentionally blank
addSuperVar(ControllerInput[0],     "ControllerInput[0]", noFlags ,1,"units - This is the controller user input for I2C write to flightboard");
addSuperVar(ControllerInput[1],     "ControllerInput[1]", noFlags ,1,"units - This is the controller user input for I2C write to flightboard");
addSuperVar(ControllerInput[2],     "ControllerInput[2]", noFlags ,1,"units - This is the controller user input for I2C write to flightboard");
addSuperVar(ControllerInput_LT,     "ControllerInput_LT", noFlags ,1,"units - This is the controller user input for I2C write to flightboard");
addSuperVar(ControllerInput_RT,     "ControllerInput_RT", noFlags ,1,"units - This is the controller user input for I2C write to flightboard");
addSuperVar(ControllerInput_LJ_Mag,     "ControllerInput_LJ_Mag", noFlags ,1,"units - This is the controller user input for I2C write to flightboard");
addSuperVar(ControllerInput_LJ_Ang,     "ControllerInput_LJ_Ang", noFlags ,1,"units - This is the controller user input for I2C write to flightboard");
addSuperVar(ControllerInput_RJ_Mag,     "ControllerInput_RJ_Mag", noFlags ,1,"units - This is the controller user input for I2C write to flightboard");
addSuperVar(ControllerInput_RJ_Ang,     "ControllerInput_RJ_Ang", noFlags ,1,"units - This is the controller user input for I2C write to flightboard");
//Used by flight algorithm and flight sim
addSuperVar(UserInput_DirectionStick_Mag,     "UserInput_DirectionStick_Mag", noFlags ,1,"units - comment");
addSuperVar(UserInput_DirectionStick_Azi,     "UserInput_DirectionStick_Azi", noFlags ,1,"units - comment");
addSuperVar(UserInput_Travel_Mag,     "UserInput_Travel_Mag", noFlags ,1,"units - comment");
addSuperVar(UserInput_Travel_Azi,     "UserInput_Travel_Azi", noFlags ,1,"units - comment");
addSuperVar(UserInput_ThrottleStick,     "UserInput_ThrottleStick", noFlags ,1,"units - comment");
addSuperVar(UserInput_ThrottleStickEnhanced,     "UserInput_ThrottleStickEnhanced", noFlags ,1,"units - comment");
addSuperVar(UserInput_Trigger_Right,     "UserInput_Trigger_Right", noFlags ,1,"units - comment");
addSuperVar(UserInput_Trigger_Left,     "UserInput_Trigger_Left", noFlags ,1,"units - comment");
addSuperVar(AutoPilot_ConnectionStatusOfHeli,     "AutoPilot_ConnectionStatusOfHeli", noFlags ,0,"seconds - -1 for disabled");
//Modes
addSuperVar(AutoPilot_CommLoss_Delay_PositionHold,     "AutoPilot_CommLoss_Delay_PositionHold",                plsHandshk |UserEditable | defIsRetain ,0,"seconds - -1 for disabled");
addSuperVar(AutoPilot_CommLoss_Delay_PositionHold_Enabled,     "AutoPilot_CommLoss_Delay_PositionHold_Enabled",                plsHandshk |UserEditable | defIsRetain ,0,"seconds - -1 for disabled");
addSuperVar(AutoPilot_CommLoss_Delay_ReturnHome,     "AutoPilot_CommLoss_Delay_ReturnHome",                plsHandshk |UserEditable | defIsRetain ,0,"seconds - -1 for disabled");
addSuperVar(AutoPilot_CommLoss_Delay_ReturnHome_Enabled,     "AutoPilot_CommLoss_Delay_ReturnHome_Enabled",                plsHandshk |UserEditable | defIsRetain ,0,"seconds - -1 for disabled");
addSuperVar(AutoPilot_CommLoss_Delay_Land,     "AutoPilot_CommLoss_Delay_Land",                plsHandshk |UserEditable | defIsRetain ,0,"seconds - -1 for disabled");
addSuperVar(AutoPilot_CommLoss_Delay_Land_Enabled,     "AutoPilot_CommLoss_Delay_Land_Enabled",                plsHandshk |UserEditable | defIsRetain ,0,"seconds - -1 for disabled");
addSuperVar(AutoPilot_LowBatt_Percent_ReturnHome_AutoSetEnabled,     "AutoPilot_LowBatt_Percent_ReturnHome_AutoSetEnabled",                plsHandshk |UserEditable | defIsRetain ,0,"seconds - -1 for disabled");
addSuperVar(AutoPilot_LowBatt_Percent_ReturnHome,     "AutoPilot_LowBatt_Percent_ReturnHome",                plsHandshk |UserEditable | defIsRetain ,0,"seconds - Battery percent below which the autopilot will take the craft home.  (-1 for disabled)");
addSuperVar(AutoPilot_LowBatt_Percent_ReturnHome_Enabled,     "AutoPilot_LowBatt_Percent_ReturnHome_Enabled",                plsHandshk |UserEditable | defIsRetain ,0,"seconds - Battery percent below which the autopilot will take the craft home.  (-1 for disabled)");
addSuperVar(AutoPilot_LowBatt_Percent_LandNow,     "AutoPilot_LowBatt_Percent_LandNow",                plsHandshk |UserEditable | defIsRetain ,0,"seconds - Battery percentage below which the craft will land immediately.  (-1 for disabled)");
addSuperVar(AutoPilot_LowBatt_Percent_LandNow_Enabled,     "AutoPilot_LowBatt_Percent_LandNow_Enabled",                plsHandshk |UserEditable | defIsRetain ,0,"seconds - Battery percentage below which the craft will land immediately.  (-1 for disabled)");
addSuperVar(AutoPilot_LowBatt_Percent_KillSystem,     "AutoPilot_LowBatt_Percent_KillSystem",                plsHandshk |UserEditable | defIsRetain ,0,"seconds - Battery percentage below which the craft will land immediately.  (-1 for disabled)");
addSuperVar(AutoPilot_LowBatt_Percent_KillSystem_Enabled,     "AutoPilot_LowBatt_Percent_KillSystem_Enabled",                plsHandshk |UserEditable | defIsRetain ,0,"seconds - Battery percentage below which the craft will land immediately.  (-1 for disabled)");
addSuperVar(AutoPilot_LowBatt_Percent_TimeDelay,     "AutoPilot_LowBatt_Percent_TimeDelay",                plsHandshk |UserEditable | defIsRetain ,0,"seconds - This is the time that batteryPercent must be below a threshold before that action occurs (return home, land here, etc.)");
addSuperVar(AutoPilot_ReturnHomeAltitudeAboveTakeoff,     "AutoPilot_ReturnHomeAltitudeAboveTakeoff",                plsHandshk |UserEditable | defIsRetain ,0,"units - comment");
addSuperVar(AutoPilot_ReturnHomeAltitudeObjectiveToleranceReqd,     "AutoPilot_ReturnHomeAltitudeObjectiveToleranceReqd",                plsHandshk |UserEditable | defIsRetain ,0,"units - comment");
addSuperVar(AutoPilot_distanceToNextWaypoint,     "AutoPilot_distanceToNextWaypoint", I2CSlow ,1,"units - comment");
addSuperVar(AutoPilot_distanceNeededToStopAircraft,     "AutoPilot_distanceNeededToStopAircraft",                plsHandshk |UserEditable | defIsRetain ,0,"units - comment");
addSuperVar(AutoPilot_wayPointDistanceTolerance,     "AutoPilot_wayPointDistanceTolerance",                plsHandshk |UserEditable | defIsRetain ,0,"units - comment");
addSuperVar(AutoPilot_MaxTransitSpeed,     "AutoPilot_MaxTransitSpeed",                plsHandshk |UserEditable | defIsRetain ,0,"units - comment");
addSuperVar(AutoPilot_descentRate,     "AutoPilot_descentRate",                plsHandshk |UserEditable | defIsRetain ,0,"units - comment");
addSuperVar(AutoPilot_Step,     "AutoPilot_Step", I2CSlow ,1,"units - comment");
addSuperVar(AutoPilot_NextWayPoint_Latitude,     "AutoPilot_NextWayPoint_Latitude", I2CSlow ,1,"units - comment");
addSuperVar(AutoPilot_NextWayPoint_Longitude,     "AutoPilot_NextWayPoint_Longitude", I2CSlow ,1,"units - comment");
addSuperVar(GoBack_UserInput_AutoClimb,     "GoBack_UserInput_AutoClimb", I2CSlow ,1,"units - comment");
addSuperVar(GoBack_UserInput_AutoLateral,     "GoBack_UserInput_AutoLateral", I2CSlow ,1,"units - comment");
addSuperVar(GoBack_UserInput_AutoYaw,     "GoBack_UserInput_AutoYaw", I2CSlow ,1,"units - comment");
//Position
addSuperVar(Position_Latitude,     "Position_Latitude", I2CSlow ,1,"units - comment");
addSuperVar(Position_Longitude,     "Position_Longitude", I2CSlow ,1,"units - comment");
addSuperVar(Position_Altitude,     "Position_Altitude", I2CSlow ,1,"units - comment");
addSuperVar(Position_Origin_Latitude,     "Position_Origin_Latitude",                plsHandshk |UserEditable | defIsRetain ,1,"units - comment");
addSuperVar(Position_Origin_Longitude,     "Position_Origin_Longitude",                plsHandshk |UserEditable | defIsRetain ,1,"units - comment");
addSuperVar(Position_Origin_Altitude,     "Position_Origin_Altitude",                plsHandshk |UserEditable | defIsRetain ,1,"units - comment");
addSuperVar(Position_DistanceFromOrigin_X,     "Position_DistanceFromOrigin_X", I2CSlow ,1,"units - comment");
addSuperVar(Position_DistanceFromOrigin_Y,     "Position_DistanceFromOrigin_Y", I2CSlow ,1,"units - comment");
addSuperVar(Position_FromOrigin_Distance,     "Position_FromOrigin_Distance", I2CSlow ,1,"units - comment");
addSuperVar(Position_FromOrigin_Azimuth,     "Position_FromOrigin_Azimuth", I2CSlow ,1,"units - comment");
addSuperVar(Position_FromOrigin_Altitude,     "Position_FromOrigin_Altitude", I2CSlow ,1,"units - comment");
addSuperVar(Position_CraftIsAirborne,     "Position_CraftIsAirborne", I2CSlow ,1,"units - comment");
addSuperVar(tooHigh,     "tooHigh", I2CSlow ,1,"units - comment");
//Lateral
addSuperVar(Motion_Lateral_EffectOf_P_Mag,     "Motion_Lateral_EffectOf_P_Mag", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Lateral_EffectOf_P_Azi,     "Motion_Lateral_EffectOf_P_Azi", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Lateral_EffectOf_I_Mag,     "Motion_Lateral_EffectOf_I_Mag", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Lateral_EffectOf_I_Azi,     "Motion_Lateral_EffectOf_I_Azi", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Lateral_EffectOf_D_Mag,     "Motion_Lateral_EffectOf_D_Mag", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Lateral_EffectOf_D_Azi,     "Motion_Lateral_EffectOf_D_Azi", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Lateral_VelocErr_Integrated_Mag,     "Motion_Lateral_VelocErr_Integrated_Mag", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Lateral_VelocErr_Integrated_Azi,     "Motion_Lateral_VelocErr_Integrated_Azi", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Lateral_VelocityError_Mag,     "Motion_Lateral_VelocityError_Mag", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Lateral_VelocityError_Azi,     "Motion_Lateral_VelocityError_Azi", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Lateral_VelocDesire_Mag,     "Motion_Lateral_VelocDesire_Mag", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Lateral_VelocDesire_Azi,     "Motion_Lateral_VelocDesire_Azi", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Lateral_Accelration_Mag,     "Motion_Lateral_Accelration_Mag", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Lateral_Accelration_Azi,     "Motion_Lateral_Accelration_Azi", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Lateral_Velocity_Mag,     "Motion_Lateral_Velocity_Mag", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Lateral_Velocity_Azi,     "Motion_Lateral_Velocity_Azi", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Tilt_Desired_Mag,     "Motion_Tilt_Desired_Mag", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Tilt_Desired_Azi,     "Motion_Tilt_Desired_Azi", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Tilt_EffectOf_P_Mag,     "Motion_Tilt_EffectOf_P_Mag", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Tilt_EffectOf_P_Azi,     "Motion_Tilt_EffectOf_P_Azi", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Tilt_EffectOf_D_Mag,     "Motion_Tilt_EffectOf_D_Mag", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Tilt_EffectOf_D_Azi,     "Motion_Tilt_EffectOf_D_Azi", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Tilt_Error_Mag,     "Motion_Tilt_Error_Mag", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Tilt_Error_Azi,     "Motion_Tilt_Error_Azi", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Tilt_Velocity_Composite_Mag,     "Motion_Tilt_Velocity_Composite_Mag", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Tilt_Velocity_Composite_Azi,     "Motion_Tilt_Velocity_Composite_Azi", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Tilt_Velocity_Mems_Mag ,     "Motion_Tilt_Velocity_Mems_Mag ", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Tilt_Velocity_Mems_Azi,     "Motion_Tilt_Velocity_Mems_Azi", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Tilt_TorqueNeeded_Mag,     "Motion_Tilt_TorqueNeeded_Mag", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Tilt_TorqueNeeded_Azi,     "Motion_Tilt_TorqueNeeded_Azi", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Tilt_Actual_Mag,     "Motion_Tilt_Actual_Mag", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Tilt_Actual_Azi,     "Motion_Tilt_Actual_Azi", I2CSlow ,1,"units - comment");
//Yaw
addSuperVar(Motion_YawDesiredNoseAzimuth,     "Motion_YawDesiredNoseAzimuth",                            UserEditable ,1,"units - comment");
addSuperVar(Motion_NoseAzimuthError,     "Motion_NoseAzimuthError", I2CSlow ,1,"units - comment");
addSuperVar(Motion_YawNoseErrorP,     "Motion_YawNoseErrorP",                            UserEditable ,1,"units - comment");
addSuperVar(Motion_YawNoseErrorD,     "Motion_YawNoseErrorD",                            UserEditable ,1,"units - comment");
addSuperVar(Motion_Yaw_UserCommand,     "Motion_Yaw_UserCommand", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Yaw_MaxRateNoClimbEffect,     "Motion_Yaw_MaxRateNoClimbEffect", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Yaw_AircraftNose_Azi,     "Motion_Yaw_AircraftNose_Azi", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Yaw_Error_P,     "Motion_Yaw_Error_P", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Yaw_Error_I,     "Motion_Yaw_Error_I", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Yaw_Error_D,     "Motion_Yaw_Error_D", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Yaw_EffectOf_P,     "Motion_Yaw_EffectOf_P", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Yaw_EffectOf_I,     "Motion_Yaw_EffectOf_I", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Yaw_EffectOf_D,     "Motion_Yaw_EffectOf_D", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Yaw_Velocity,     "Motion_Yaw_Velocity", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Yaw_TorqueRequested,     "Motion_Yaw_TorqueRequested", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Yaw_VelocityRequested,     "Motion_Yaw_VelocityRequested", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Yaw_VelocityError,     "Motion_Yaw_VelocityError", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Yaw_Acceleration,     "Motion_Yaw_Acceleration", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Yaw_VelocityError_Integrated,     "Motion_Yaw_VelocityError_Integrated", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Yaw_VelocityDesired,     "Motion_Yaw_VelocityDesired", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Yaw_MaxYawRateDesired,     "Motion_Yaw_MaxYawRateDesired", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Composite_NoseAzimuth,     "Sensor_Composite_NoseAzimuth", I2CSlow ,1,"units - comment");
//Vertical
addSuperVar(Motion_DesiredAltitudeAboveSeaLevel,     "Motion_DesiredAltitudeAboveSeaLevel", I2CSlow ,1,"units - comment");
addSuperVar(Motion_DesiredAltitudeAboveTakeoff,     "Motion_DesiredAltitudeAboveTakeoff", I2CSlow ,1,"units - comment");
addSuperVar(Motion_AltitudeError,     "Motion_AltitudeError", I2CSlow ,1,"units - comment");
addSuperVar(Motion_AltitudeErrorP,     "Motion_AltitudeErrorP",                plsHandshk |UserEditable | defIsRetain ,1,"PID ? P Setting - comment");
addSuperVar(Motion_ClimbRate_Actual,     "Motion_ClimbRate_Actual", I2CSlow ,1,"units - comment");
addSuperVar(Motion_ClimbRate_Desired,     "Motion_ClimbRate_Desired", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Climb_EffectOf_P,     "Motion_Climb_EffectOf_P", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Climb_EffectOf_I,     "Motion_Climb_EffectOf_I", I2CSlow ,1,"units - comment");
addSuperVar(Motion_Climb_EffectOf_D,     "Motion_Climb_EffectOf_D", I2CSlow ,1,"units - comment");
addSuperVar(Motion_climbRateErrorD,     "Motion_climbRateErrorD", I2CSlow ,1,"units - comment");
addSuperVar(Motion_climbAcceleration,     "Motion_climbAcceleration", I2CSlow ,1,"units - comment");
addSuperVar(Motion_climbRateError,     "Motion_climbRateError", I2CSlow ,1,"units - comment");
addSuperVar(Motion_ClimbRateError_Integrated,     "Motion_ClimbRateError_Integrated", I2CSlow ,1,"units - comment");
addSuperVar(Thrust_ThrottleSignal,     "Thrust_ThrottleSignal", I2CSlow ,1,"units - comment");
addSuperVar(Thrust_MotorThrottleSummation,     "Thrust_MotorThrottleSummation", I2CSlow ,1,"units - comment");
addSuperVar(Thrust_PredictedActual,     "Thrust_PredictedActual", I2CSlow ,1,"units - comment");
addSuperVar(Thrust_Downward,     "Thrust_Downward", I2CSlow ,1,"units - comment");
addSuperVar(Thrust_Lateral,     "Thrust_Lateral", I2CSlow ,1,"units - comment");
addSuperVar(Characteristic_craftWeight,     "Characteristic_craftWeight",                          UserEditable | defIsRetain ,1,"units - comment");
addSuperVar(Characteristic_maxTiltForDesiredClimb,     "Characteristic_maxTiltForDesiredClimb", I2CSlow ,1,"units - comment");
addSuperVar(Characteristic_maxTiltForZeroClimb,     "Characteristic_maxTiltForZeroClimb",                          UserEditable | defIsRetain ,1,"units - comment");
addSuperVar(Characteristic_topSpeed,     "Characteristic_topSpeed", I2CSlow ,1,"units - comment");
addSuperVar(Characteristic_topSpeedZeroClimb,     "Characteristic_topSpeedZeroClimb",                          UserEditable | defIsRetain ,1,"units - comment");
//Motors
//intentionally blank
addSuperVar(predictedActualThrust[0],     "predictedActualThrust[0]", I2CSlow ,1,"units - comment");
addSuperVar(predictedActualThrust[1],     "predictedActualThrust[1]", I2CSlow ,1,"units - comment");
addSuperVar(predictedActualThrust[2],     "predictedActualThrust[2]", I2CSlow ,1,"units - comment");
addSuperVar(predictedActualThrust[3],     "predictedActualThrust[3]", I2CSlow ,1,"units - comment");
addSuperVar(predictedActualThrust[4],     "predictedActualThrust[4]", I2CSlow ,1,"units - comment");
addSuperVar(predictedActualThrust[5],     "predictedActualThrust[5]", I2CSlow ,1,"units - comment");
addSuperVar(predictedActualThrust[6],     "predictedActualThrust[6]", I2CSlow ,1,"units - comment");
//intentionally blank
addSuperVar(motorFailureDetected[0],     "motorFailureDetected[0]", I2CSlow ,1,"units - comment");
addSuperVar(motorFailureDetected[1],     "motorFailureDetected[1]", I2CSlow ,1,"units - comment");
addSuperVar(motorFailureDetected[2],     "motorFailureDetected[2]", I2CSlow ,1,"units - comment");
addSuperVar(motorFailureDetected[3],     "motorFailureDetected[3]", I2CSlow ,1,"units - comment");
addSuperVar(motorFailureDetected[4],     "motorFailureDetected[4]", I2CSlow ,1,"units - comment");
addSuperVar(motorFailureDetected[5],     "motorFailureDetected[5]", I2CSlow ,1,"units - comment");
addSuperVar(motorFailureDetected[6],     "motorFailureDetected[6]", I2CSlow ,1,"units - comment");
//Sensors
addSuperVar(Sensor_AccelerometerOrientationAccuracyMagnitude,     "Sensor_AccelerometerOrientationAccuracyMagnitude", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_AccelerometerOrientationRelAzimuth,     "Sensor_AccelerometerOrientationRelAzimuth", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_AccelerometerOrientationRel_Incline,     "Sensor_AccelerometerOrientationRel_Incline", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_AccelerometerAccelerationAccuracyMagnitude,     "Sensor_AccelerometerAccelerationAccuracyMagnitude", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_AccelerometerAccelerationRelAzimuth,     "Sensor_AccelerometerAccelerationRelAzimuth", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_AccelerometerAccelerationRelPitch,     "Sensor_AccelerometerAccelerationRelPitch", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_MagneticOrientationAccuracyMagnitude,     "Sensor_MagneticOrientationAccuracyMagnitude", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_MagneticOrientationTrueHeading,     "Sensor_MagneticOrientationTrueHeading", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_MagneticOrientationRollRelAzimuth,     "Sensor_MagneticOrientationRollRelAzimuth", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_MagneticOrientationRoll_Incline,     "Sensor_MagneticOrientationRoll_Incline", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Composite_Pitch,     "Sensor_Composite_Pitch", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Composite_Roll,     "Sensor_Composite_Roll", I2CSlow ,1,"units - comment");
addSuperVar(Sensor_Composite_Yaw,     "Sensor_Composite_Yaw", I2CSlow ,1,"units - comment");
//Motion Characteristics
//Motion Characteristics
//Motion Characteristics
//Motion Characteristics
//Settings and Commands
addSuperVar(UserInput_Sensitivity_Throttle,     "UserInput_Sensitivity_Throttle",                plsHandshk |UserEditable | defIsRetain ,0," - I recommend setting this between 1 and 10.  Lower numbers are more sensitive.");
addSuperVar(UserInput_Sensitivity_DirectionStick,     "UserInput_Sensitivity_DirectionStick",                plsHandshk |UserEditable | defIsRetain ,0," - I recommend setting this between 1 and 10.  Lower numbers are more sensitive.");
addSuperVar(UserInput_Sensitivity_Yaw,     "UserInput_Sensitivity_Yaw",                plsHandshk |UserEditable | defIsRetain ,0," - I recommend setting this between 1 and 10.  Lower numbers are more sensitive.");
addSuperVar(Command_PleaseReturnHome,     "Command_PleaseReturnHome",                plsHandshk |UserEditable | defIsRetain ,0,"Bool - ");
addSuperVar(Command_PleaseUnlockMotors,     "Command_PleaseUnlockMotors",                plsHandshk |UserEditable | defIsRetain ,0,"Bool - ");
addSuperVar(Command_PleaseMarkThisAsOrigin,     "Command_PleaseMarkThisAsOrigin",                plsHandshk |UserEditable | defIsRetain ,0,"Bool - Increment this variable to make it happen");
addSuperVar(Setpoint_TransitHomeAltitudeAboveGround,     "Setpoint_TransitHomeAltitudeAboveGround",                plsHandshk |UserEditable | defIsRetain ,0," - I recommend setting this between 1 and 10.  Lower numbers are more sensitive.");
addSuperVar(Setpoint_Ceiling_SeaLevel,     "Setpoint_Ceiling_SeaLevel",                plsHandshk |UserEditable | defIsRetain ,0,"Feet - I recommend setting this between 1 and 10.  Lower numbers are more sensitive.");
addSuperVar(Setpoint_Ceiling_DistanceAboveTakeoff,     "Setpoint_Ceiling_DistanceAboveTakeoff",                plsHandshk |UserEditable | defIsRetain ,0,"Feet - I recommend setting this between 1 and 10.  Lower numbers are more sensitive.");
//PID Values
addSuperVar(Control_Lateral_P,     "Control_Lateral_P",                plsHandshk |UserEditable | defIsRetain ,0," - Changes how Roll control performs.");
addSuperVar(Control_Lateral_D,     "Control_Lateral_D",                plsHandshk |UserEditable | defIsRetain ,0," - Changes how Roll control performs.");
addSuperVar(Control_Lateral_I,     "Control_Lateral_I",                plsHandshk |UserEditable | defIsRetain ,0," - Changes how Roll control performs.");
addSuperVar(Control_Lateral_I_MaxWindup,     "Control_Lateral_I_MaxWindup",                plsHandshk |UserEditable | defIsRetain ,0," - Changes how Roll control performs.");
addSuperVar(Control_Lateral_TopSpeedCorrectionK,     "Control_Lateral_TopSpeedCorrectionK",                plsHandshk |UserEditable | defIsRetain ,0,"Setting this to greater than one is often necessary to allow it to fly at top speed - Changes how Roll control performs.");
addSuperVar(Control_Climb_P,     "Control_Climb_P",                plsHandshk |UserEditable | defIsRetain ,0," - This effects the way the helicopter controls altitude.");
addSuperVar(Control_Climb_D,     "Control_Climb_D",                plsHandshk |UserEditable | defIsRetain ,0," - This effects the way the helicopter controls altitude.");
addSuperVar(Control_Climb_I,     "Control_Climb_I",                plsHandshk |UserEditable | defIsRetain ,0," - This effects the way the helicopter controls altitude.");
addSuperVar(Control_Climb_I_MaxWindup,     "Control_Climb_I_MaxWindup",                plsHandshk |UserEditable | defIsRetain ,0," - This effects the way the helicopter controls altitude.");
addSuperVar(Control_Tilt_P,     "Control_Tilt_P",                plsHandshk |UserEditable | defIsRetain ,0," - Changes how Roll control performs.");
addSuperVar(Control_Tilt_D,     "Control_Tilt_D",                plsHandshk |UserEditable | defIsRetain ,0," - Changes how Roll control performs.");
addSuperVar(Control_Tilt_PleaseUseGyroAndAccel,     "Control_Tilt_PleaseUseGyroAndAccel",                plsHandshk |UserEditable | defIsRetain ,0,"Bool - If true, orientation data from both the gyroscope and accelerometer will be used rather than just the accelerometer");
addSuperVar(Control_Yaw_P,     "Control_Yaw_P",                plsHandshk |UserEditable | defIsRetain ,0," - Changes how Yaw control performs");
addSuperVar(Control_Yaw_D,     "Control_Yaw_D",                plsHandshk |UserEditable | defIsRetain ,0," - Changes how Yaw control performs");
addSuperVar(Control_Yaw_I,     "Control_Yaw_I",                plsHandshk |UserEditable | defIsRetain ,0," - Changes how Yaw control performs");
addSuperVar(Control_Yaw_I_MaxWindup,     "Control_Yaw_I_MaxWindup",                plsHandshk |UserEditable | defIsRetain ,0," - Changes how Yaw control performs");
addSuperVar(Control_Yaw_MaxYawRateDesired,     "Control_Yaw_MaxYawRateDesired",                plsHandshk |UserEditable | defIsRetain ,0,"Rotations/Second - This is how responsive the heli's motors are assumed to be, (The time that the computer assumes it takes for thrust to reach 0.63 of the throttle value.)");
//Aircraft Geometry
addSuperVar(motor_ResponseTC,     "motor_ResponseTC",                plsHandshk |UserEditable | defIsRetain ,0,"units - comment");
addSuperVar(numberOfMotors,     "numberOfMotors",                plsHandshk |UserEditable | defIsRetain ,0," - Number of motors on craft.  Set to 4 or 6");
//intentionally blank
addSuperVar(angle_motor_[0],     "angle_motor_[0]",                plsHandshk |UserEditable | defIsRetain ,0,"Degrees - Clockwise from the top.  0 degrees is forward");
addSuperVar(angle_motor_[1],     "angle_motor_[1]",                plsHandshk |UserEditable | defIsRetain ,0,"Degrees - Clockwise from the top.  0 degrees is forward");
addSuperVar(angle_motor_[2],     "angle_motor_[2]",                plsHandshk |UserEditable | defIsRetain ,0,"Degrees - Clockwise from the top.  0 degrees is forward");
addSuperVar(angle_motor_[3],     "angle_motor_[3]",                plsHandshk |UserEditable | defIsRetain ,0,"Degrees - Clockwise from the top.  0 degrees is forward");
addSuperVar(angle_motor_[4],     "angle_motor_[4]",                plsHandshk |UserEditable | defIsRetain ,0,"Degrees - Clockwise from the top.  0 degrees is forward");
addSuperVar(angle_motor_[5],     "angle_motor_[5]",                plsHandshk |UserEditable | defIsRetain ,0,"Degrees - Clockwise from the top.  0 degrees is forward");
addSuperVar(angle_motor_[6],     "angle_motor_[6]",                plsHandshk |UserEditable | defIsRetain ,0,"Degrees - Clockwise from the top.  0 degrees is forward");
//intentionally blank
addSuperVar(doesRotateClockwise_motor[0],     "doesRotateClockwise_motor[0]",                plsHandshk |UserEditable | defIsRetain ,0,"Bool - If, from the top the motor rotates clickwise, this is true, otherwise it is false.");
addSuperVar(doesRotateClockwise_motor[1],     "doesRotateClockwise_motor[1]",                plsHandshk |UserEditable | defIsRetain ,0,"Bool - If, from the top the motor rotates clickwise, this is true, otherwise it is false.");
addSuperVar(doesRotateClockwise_motor[2],     "doesRotateClockwise_motor[2]",                plsHandshk |UserEditable | defIsRetain ,0,"Bool - If, from the top the motor rotates clickwise, this is true, otherwise it is false.");
addSuperVar(doesRotateClockwise_motor[3],     "doesRotateClockwise_motor[3]",                plsHandshk |UserEditable | defIsRetain ,0,"Bool - If, from the top the motor rotates clickwise, this is true, otherwise it is false.");
addSuperVar(doesRotateClockwise_motor[4],     "doesRotateClockwise_motor[4]",                plsHandshk |UserEditable | defIsRetain ,0,"Bool - If, from the top the motor rotates clickwise, this is true, otherwise it is false.");
addSuperVar(doesRotateClockwise_motor[5],     "doesRotateClockwise_motor[5]",                plsHandshk |UserEditable | defIsRetain ,0,"Bool - If, from the top the motor rotates clickwise, this is true, otherwise it is false.");
addSuperVar(doesRotateClockwise_motor[6],     "doesRotateClockwise_motor[6]",                plsHandshk |UserEditable | defIsRetain ,0,"Bool - If, from the top the motor rotates clickwise, this is true, otherwise it is false.");
//intentionally blank
addSuperVar(simuMotorFailure[0],     "simuMotorFailure[0]",                plsHandshk |UserEditable | defIsRetain ,0,"Bool - If, from the top the motor rotates clickwise, this is true, otherwise it is false.");
addSuperVar(simuMotorFailure[1],     "simuMotorFailure[1]",                plsHandshk |UserEditable | defIsRetain ,0,"Bool - If, from the top the motor rotates clickwise, this is true, otherwise it is false.");
addSuperVar(simuMotorFailure[2],     "simuMotorFailure[2]",                plsHandshk |UserEditable | defIsRetain ,0,"Bool - If, from the top the motor rotates clickwise, this is true, otherwise it is false.");
addSuperVar(simuMotorFailure[3],     "simuMotorFailure[3]",                plsHandshk |UserEditable | defIsRetain ,0,"Bool - If, from the top the motor rotates clickwise, this is true, otherwise it is false.");
addSuperVar(simuMotorFailure[4],     "simuMotorFailure[4]",                plsHandshk |UserEditable | defIsRetain ,0,"Bool - If, from the top the motor rotates clickwise, this is true, otherwise it is false.");
addSuperVar(simuMotorFailure[5],     "simuMotorFailure[5]",                plsHandshk |UserEditable | defIsRetain ,0,"Bool - If, from the top the motor rotates clickwise, this is true, otherwise it is false.");
addSuperVar(simuMotorFailure[6],     "simuMotorFailure[6]",                plsHandshk |UserEditable | defIsRetain ,0,"Bool - If, from the top the motor rotates clickwise, this is true, otherwise it is false.");
//Simulated Heli
addSuperVar(simuHeli.hasAnimated,     "simuHeli.hasAnimated", I2CSlow ,1,"Bool - start stop and reset");
addSuperVar(simuHeli.isAnimate,     "simuHeli.isAnimate", I2CSlow ,1,"Bool - start stop and reset");
addSuperVar(freezeSimulatedHeli,     "freezeSimulatedHeli", I2CSlow ,1,"Bool - If set to 1 the simulated heli will only be able to roll and will have a fixed total throttle equaling 0.4. ");
addSuperVar(simuHeli.propAndMotorMass,     "simuHeli.propAndMotorMass",                plsHandshk |UserEditable | defIsRetain ,0,"lbs - ");
addSuperVar(simuHeli.CenterOfCraftMass,     "simuHeli.CenterOfCraftMass",                plsHandshk |UserEditable | defIsRetain ,0,"lbs - ");
addSuperVar(simuHeli.armLength,     "simuHeli.armLength",                plsHandshk |UserEditable | defIsRetain ,0,"inches - ");
addSuperVar(simuHeli.CenterOfCraftRadius,     "simuHeli.CenterOfCraftRadius",                plsHandshk |UserEditable | defIsRetain ,0,"inches - ");
addSuperVar(simuHeli.dragK_Linear,     "simuHeli.dragK_Linear",                plsHandshk |UserEditable | defIsRetain ,0," - ");
addSuperVar(simuHeli.dragK_Yaw,     "simuHeli.dragK_Yaw",                plsHandshk |UserEditable | defIsRetain ,0," - ");
addSuperVar(simuHeli.dragK_Roll,     "simuHeli.dragK_Roll",                plsHandshk |UserEditable | defIsRetain ,0," - ");
addSuperVar(simuHeli.MotorMaxThrust,     "simuHeli.MotorMaxThrust",                plsHandshk |UserEditable | defIsRetain ,0,"lbs - ");
addSuperVar(simuHeli.torqueK,     "simuHeli.torqueK",                plsHandshk |UserEditable | defIsRetain ,0,"ft*motorMaxThrust - ");
addSuperVar(simuHeli.maxWindSpeed,     "simuHeli.maxWindSpeed",                plsHandshk |UserEditable | defIsRetain ,0,"mph - ");
addSuperVar(simuHeli.turbulenceLevel,     "simuHeli.turbulenceLevel",                plsHandshk |UserEditable | defIsRetain ,0,"1 to 4 - ");
//Instrumentation
addSuperVar(Sensor_FilterTimeConstantBarometer,     "Sensor_FilterTimeConstantBarometer",                plsHandshk |UserEditable | defIsRetain ,0,"Seconds - ");
addSuperVar(Sensor_FilterTimeConstantAccelerometer,     "Sensor_FilterTimeConstantAccelerometer",                plsHandshk |UserEditable | defIsRetain ,0,"Seconds - ");
addSuperVar(Sensor_FilterTimeConstantGyro,     "Sensor_FilterTimeConstantGyro",                plsHandshk |UserEditable | defIsRetain ,0,"Seconds - ");
addSuperVar(Sensor_FilterTimeConstantCompass,     "Sensor_FilterTimeConstantCompass",                plsHandshk |UserEditable | defIsRetain ,0,"Seconds - ");
addSuperVar(Sensor_FilterTimeConstantGPSHorizontal,     "Sensor_FilterTimeConstantGPSHorizontal",                plsHandshk |UserEditable | defIsRetain ,0,"Seconds - ");
addSuperVar(Sensor_FilterTimeConstantGPSVertical,     "Sensor_FilterTimeConstantGPSVertical",                plsHandshk |UserEditable | defIsRetain ,0,"Seconds - ");
addSuperVar(Sensor_FilterTimeConstantThrustMagnitudeChange,     "Sensor_FilterTimeConstantThrustMagnitudeChange",                plsHandshk |UserEditable | defIsRetain ,0,"Seconds - ");
addSuperVar(Sensor_FilterTimeConstantBatteryPercent,     "Sensor_FilterTimeConstantBatteryPercent",                plsHandshk |UserEditable | defIsRetain ,0,"Seconds - ");
addSuperVar(Sensor_memsZeroYawRate,     "Sensor_memsZeroYawRate",                plsHandshk |UserEditable | defIsRetain ,0,"Radians/Sec - ");
addSuperVar(Sensor_memsZeroRollRelAzimuth,     "Sensor_memsZeroRollRelAzimuth",                plsHandshk |UserEditable | defIsRetain ,0,"Radians - calculated before takeoff");
addSuperVar(Sensor_memsZeroRollRate,     "Sensor_memsZeroRollRate",                plsHandshk |UserEditable | defIsRetain ,0,"Radians/Sec - ");
addSuperVar(Sensor_declinationAbsAzimuth,     "Sensor_declinationAbsAzimuth",                plsHandshk |UserEditable | defIsRetain ,0,"Seconds - ");
addSuperVar(Sensor_declinationAbsPitch,     "Sensor_declinationAbsPitch",                plsHandshk |UserEditable | defIsRetain ,0,"Seconds - ");
addSuperVar(Battery_MinCellvoltage,     "Battery_MinCellvoltage",                plsHandshk |UserEditable | defIsRetain ,0,"units - comment");
addSuperVar(Battery_MaxCellvoltage,     "Battery_MaxCellvoltage",                plsHandshk |UserEditable | defIsRetain ,0,"units - comment");
addSuperVar(Battery_VoltageDropFullThrottle,     "Battery_VoltageDropFullThrottle",                plsHandshk |UserEditable | defIsRetain ,0,"units - comment");
addSuperVar(Battery_PercentRemainingFilteringTC,     "Battery_PercentRemainingFilteringTC",                plsHandshk |UserEditable | defIsRetain ,0,"units - Seconds");
addSuperVar(Battery_flightTimeNeededToReachHome,     "Battery_flightTimeNeededToReachHome", I2CSlow ,1,"units - comment");
addSuperVar(testVariable1,     "testVariable1",                plsHandshk |UserEditable | defIsRetain ,0,"units - comment");
addSuperVar(testVariable2,     "testVariable2",                plsHandshk |UserEditable | defIsRetain ,0,"units - comment");
addSuperVar(debugVar1,     "debugVar1", I2CSlow ,1,"units - comment");
addSuperVar(debugVar2,     "debugVar2", I2CSlow ,1,"units - comment");
addSuperVar(debugVar3,     "debugVar3", I2CSlow ,1,"units - comment");
addSuperVar(debugVar4,     "debugVar4", I2CSlow ,1,"units - comment");
addSuperVar(debugVar5,     "debugVar5", I2CSlow ,1,"units - comment");
//Netowork and Debugging
addSuperVar(paramSetVersion,     "paramSetVersion",                plsHandshk |UserEditable | defIsRetain ,0,"1=param's loaded - ");
addSuperVar(paramSetChecksum,     "paramSetChecksum",                plsHandshk ,0," - ");
addSuperVar(HeartbeatInterval,     "HeartbeatInterval",                plsHandshk |UserEditable | defIsRetain ,0,"mSec - ");
addSuperVar(iControllerPacketInterval,     "iControllerPacketInterval",                plsHandshk |UserEditable | defIsRetain ,0,"mSec - ");
//intentionally blank
addSuperVar(pollingInterval[1],     "pollingInterval[1]",                plsHandshk |UserEditable | defIsRetain ,0,"mSec - comment");
addSuperVar(pollingInterval[2],     "pollingInterval[2]",                plsHandshk |UserEditable | defIsRetain ,0,"mSec - comment");
addSuperVar(expectedPingForThisNetwork,     "expectedPingForThisNetwork", noFlags ,0,"mSec - ");
addSuperVar(enumIPAddressingMode,     "enumIPAddressingMode", noFlags ,0," - ");
addSuperVar(HelicopterMode,     "HelicopterMode",                             UserEditable | defIsRetain ,0,"1=yes - ");
addSuperVar(sTargetIPAddress,     "sTargetIPAddress",                             UserEditable | defIsRetain ,0," - ");
addSuperVar(savePolledVarsToDisk,     "savePolledVarsToDisk",                             UserEditable | defIsRetain ,0,"1=yes - ");
addSuperVar(glbSystemID,     "glbSystemID",                             UserEditable | defIsRetain ,0," - ");
    if  (largestVarID >= maxAllowedVarID){
        QMessageBox msgBox;
        msgBox.setText("The largest Variable ID is too big.  Please close the program and contact the developer.");
        msgBox.exec();
        }
    }
#endif // SUPERVAR_DECLARE2_H



void makeListofCraftStatus(){
int l=listOf_CraftStatus;int i=-1;QString errText="listOf_Craft overflow";
//Flightboard Variables
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("guardA");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Accelerometer_X");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Accelerometer_Y");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Accelerometer_Z");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("FlighboardErrorCode");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("FlighboardErrorCode2");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("FlighboardErrorString");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Accelerometer_Magnitude");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Accelerometer_RelAzimuth");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Accelerometer_RelIncline");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Compass_X");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Compass_Y");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Compass_Z");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Compass_FieldStrength");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Compass_NorthRelAzimuth");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Compass_NorthRel_Incline");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Baro_psia");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Baro_altimeter");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Baro_temp");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Gyro_yawRate");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Gyro_pitchRate");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Gyro_rollRate");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Gyro_RelAzimuth");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Gyro_Rel_Incline");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Gyro_Rate");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_GPS_IsAvailable");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_GPS_Time");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_GPS_Altitude");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_GPS_Lattitude");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_GPS_Longitude");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_GPS_Heading");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_GPS_Speed");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_GPS_Climbrate");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Battery_ActualVoltage");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Battery_EffectiveVoltage");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Battery_PercentRemainingInstantaneous");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Battery_PercentRemainingFiltered");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Battery_batteryPercentPerMinute");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Battery_flightTimeRemaining");
//intentionally blank
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("throttleValues[0]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("throttleValues[1]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("throttleValues[2]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("throttleValues[3]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("throttleValues[4]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("throttleValues[5]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("throttleValues[6]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("secondsElapsed");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_Enabled");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("UserInput_AutoClimb");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("UserInput_AutoLateral");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("UserInput_AutoYaw");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("UserInput_ControlAzimuthIsHeliRelative");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("paramSetChecksum_Flightboard");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("counter_FB_mainLoop");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("counter_FB_push_1");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("counter_FB_push_2");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("counter_FB_push_3");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("counter_FB_get_1");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("counter_FB_get_2");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("bufferVar_DoNotUse");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("xx_VAR_ID_OF_HIGHEST_I2C_POLLED_VAR_xx");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("I2C_Error");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("I2C_PollingPeriodMsecs");
//intentionally blank
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("ControllerInput[0]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("ControllerInput[1]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("ControllerInput[2]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("ControllerInput_LT");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("ControllerInput_RT");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("ControllerInput_LJ_Mag");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("ControllerInput_LJ_Ang");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("ControllerInput_RJ_Mag");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("ControllerInput_RJ_Ang");
//Used by flight algorithm and flight sim
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("UserInput_DirectionStick_Mag");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("UserInput_DirectionStick_Azi");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("UserInput_Travel_Mag");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("UserInput_Travel_Azi");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("UserInput_ThrottleStick");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("UserInput_ThrottleStickEnhanced");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("UserInput_Trigger_Right");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("UserInput_Trigger_Left");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_ConnectionStatusOfHeli");
//Modes
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_CommLoss_Delay_PositionHold");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_CommLoss_Delay_PositionHold_Enabled");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_CommLoss_Delay_ReturnHome");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_CommLoss_Delay_ReturnHome_Enabled");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_CommLoss_Delay_Land");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_CommLoss_Delay_Land_Enabled");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_LowBatt_Percent_ReturnHome_AutoSetEnabled");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_LowBatt_Percent_ReturnHome");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_LowBatt_Percent_ReturnHome_Enabled");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_LowBatt_Percent_LandNow");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_LowBatt_Percent_LandNow_Enabled");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_LowBatt_Percent_KillSystem");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_LowBatt_Percent_KillSystem_Enabled");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_LowBatt_Percent_TimeDelay");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_ReturnHomeAltitudeAboveTakeoff");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_ReturnHomeAltitudeObjectiveToleranceReqd");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_distanceToNextWaypoint");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_distanceNeededToStopAircraft");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_wayPointDistanceTolerance");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_MaxTransitSpeed");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_descentRate");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_Step");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_NextWayPoint_Latitude");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("AutoPilot_NextWayPoint_Longitude");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("GoBack_UserInput_AutoClimb");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("GoBack_UserInput_AutoLateral");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("GoBack_UserInput_AutoYaw");
//Position
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Position_Latitude");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Position_Longitude");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Position_Altitude");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Position_Origin_Latitude");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Position_Origin_Longitude");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Position_Origin_Altitude");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Position_DistanceFromOrigin_X");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Position_DistanceFromOrigin_Y");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Position_FromOrigin_Distance");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Position_FromOrigin_Azimuth");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Position_FromOrigin_Altitude");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Position_CraftIsAirborne");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("tooHigh");
//Lateral
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Lateral_EffectOf_P_Mag");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Lateral_EffectOf_P_Azi");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Lateral_EffectOf_I_Mag");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Lateral_EffectOf_I_Azi");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Lateral_EffectOf_D_Mag");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Lateral_EffectOf_D_Azi");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Lateral_VelocErr_Integrated_Mag");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Lateral_VelocErr_Integrated_Azi");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Lateral_VelocityError_Mag");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Lateral_VelocityError_Azi");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Lateral_VelocDesire_Mag");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Lateral_VelocDesire_Azi");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Lateral_Accelration_Mag");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Lateral_Accelration_Azi");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Lateral_Velocity_Mag");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Lateral_Velocity_Azi");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Tilt_Desired_Mag");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Tilt_Desired_Azi");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Tilt_EffectOf_P_Mag");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Tilt_EffectOf_P_Azi");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Tilt_EffectOf_D_Mag");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Tilt_EffectOf_D_Azi");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Tilt_Error_Mag");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Tilt_Error_Azi");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Tilt_Velocity_Composite_Mag");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Tilt_Velocity_Composite_Azi");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Tilt_Velocity_Mems_Mag ");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Tilt_Velocity_Mems_Azi");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Tilt_TorqueNeeded_Mag");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Tilt_TorqueNeeded_Azi");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Tilt_Actual_Mag");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Tilt_Actual_Azi");
//Yaw
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_YawDesiredNoseAzimuth");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_NoseAzimuthError");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_YawNoseErrorP");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_YawNoseErrorD");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Yaw_UserCommand");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Yaw_MaxRateNoClimbEffect");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Yaw_AircraftNose_Azi");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Yaw_Error_P");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Yaw_Error_I");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Yaw_Error_D");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Yaw_EffectOf_P");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Yaw_EffectOf_I");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Yaw_EffectOf_D");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Yaw_Velocity");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Yaw_TorqueRequested");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Yaw_VelocityRequested");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Yaw_VelocityError");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Yaw_Acceleration");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Yaw_VelocityError_Integrated");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Yaw_VelocityDesired");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Yaw_MaxYawRateDesired");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Composite_NoseAzimuth");
//Vertical
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_DesiredAltitudeAboveSeaLevel");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_DesiredAltitudeAboveTakeoff");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_AltitudeError");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_AltitudeErrorP");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_ClimbRate_Actual");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_ClimbRate_Desired");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Climb_EffectOf_P");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Climb_EffectOf_I");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_Climb_EffectOf_D");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_climbRateErrorD");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_climbAcceleration");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_climbRateError");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Motion_ClimbRateError_Integrated");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Thrust_ThrottleSignal");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Thrust_MotorThrottleSummation");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Thrust_PredictedActual");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Thrust_Downward");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Thrust_Lateral");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Characteristic_craftWeight");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Characteristic_maxTiltForDesiredClimb");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Characteristic_maxTiltForZeroClimb");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Characteristic_topSpeed");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Characteristic_topSpeedZeroClimb");
//Motors
//intentionally blank
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("predictedActualThrust[0]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("predictedActualThrust[1]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("predictedActualThrust[2]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("predictedActualThrust[3]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("predictedActualThrust[4]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("predictedActualThrust[5]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("predictedActualThrust[6]");
//intentionally blank
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("motorFailureDetected[0]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("motorFailureDetected[1]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("motorFailureDetected[2]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("motorFailureDetected[3]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("motorFailureDetected[4]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("motorFailureDetected[5]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("motorFailureDetected[6]");
//Sensors
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_AccelerometerOrientationAccuracyMagnitude");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_AccelerometerOrientationRelAzimuth");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_AccelerometerOrientationRel_Incline");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_AccelerometerAccelerationAccuracyMagnitude");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_AccelerometerAccelerationRelAzimuth");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_AccelerometerAccelerationRelPitch");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_MagneticOrientationAccuracyMagnitude");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_MagneticOrientationTrueHeading");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_MagneticOrientationRollRelAzimuth");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_MagneticOrientationRoll_Incline");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Composite_Pitch");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Composite_Roll");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_Composite_Yaw");
//Motion Characteristics
VarList_MaxIndex[l] = i;}
void makeListofMotionVars(){
int l=listOf_MotionVars;int i=-1;QString errText="listOf_MotionVars overflow";
//Settings and Commands
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("UserInput_Sensitivity_Throttle");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("UserInput_Sensitivity_DirectionStick");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("UserInput_Sensitivity_Yaw");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Command_PleaseReturnHome");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Command_PleaseUnlockMotors");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Command_PleaseMarkThisAsOrigin");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Setpoint_TransitHomeAltitudeAboveGround");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Setpoint_Ceiling_SeaLevel");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Setpoint_Ceiling_DistanceAboveTakeoff");
//PID Values
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Control_Lateral_P");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Control_Lateral_D");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Control_Lateral_I");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Control_Lateral_I_MaxWindup");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Control_Lateral_TopSpeedCorrectionK");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Control_Climb_P");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Control_Climb_D");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Control_Climb_I");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Control_Climb_I_MaxWindup");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Control_Tilt_P");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Control_Tilt_D");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Control_Tilt_PleaseUseGyroAndAccel");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Control_Yaw_P");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Control_Yaw_D");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Control_Yaw_I");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Control_Yaw_I_MaxWindup");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Control_Yaw_MaxYawRateDesired");
//Aircraft Geometry
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("motor_ResponseTC");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("numberOfMotors");
//intentionally blank
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("angle_motor_[0]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("angle_motor_[1]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("angle_motor_[2]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("angle_motor_[3]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("angle_motor_[4]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("angle_motor_[5]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("angle_motor_[6]");
//intentionally blank
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("doesRotateClockwise_motor[0]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("doesRotateClockwise_motor[1]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("doesRotateClockwise_motor[2]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("doesRotateClockwise_motor[3]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("doesRotateClockwise_motor[4]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("doesRotateClockwise_motor[5]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("doesRotateClockwise_motor[6]");
//intentionally blank
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuMotorFailure[0]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuMotorFailure[1]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuMotorFailure[2]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuMotorFailure[3]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuMotorFailure[4]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuMotorFailure[5]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuMotorFailure[6]");
//Simulated Heli
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuHeli.hasAnimated");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuHeli.isAnimate");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("freezeSimulatedHeli");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuHeli.propAndMotorMass");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuHeli.CenterOfCraftMass");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuHeli.armLength");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuHeli.CenterOfCraftRadius");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuHeli.dragK_Linear");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuHeli.dragK_Yaw");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuHeli.dragK_Roll");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuHeli.MotorMaxThrust");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuHeli.torqueK");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuHeli.maxWindSpeed");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("simuHeli.turbulenceLevel");
//Instrumentation
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_FilterTimeConstantBarometer");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_FilterTimeConstantAccelerometer");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_FilterTimeConstantGyro");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_FilterTimeConstantCompass");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_FilterTimeConstantGPSHorizontal");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_FilterTimeConstantGPSVertical");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_FilterTimeConstantThrustMagnitudeChange");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_FilterTimeConstantBatteryPercent");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_memsZeroYawRate");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_memsZeroRollRelAzimuth");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_memsZeroRollRate");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_declinationAbsAzimuth");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Sensor_declinationAbsPitch");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Battery_MinCellvoltage");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Battery_MaxCellvoltage");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Battery_VoltageDropFullThrottle");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Battery_PercentRemainingFilteringTC");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("Battery_flightTimeNeededToReachHome");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("testVariable1");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("testVariable2");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("debugVar1");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("debugVar2");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("debugVar3");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("debugVar4");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("debugVar5");
//Netowork and Debugging
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("paramSetVersion");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("paramSetChecksum");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("HeartbeatInterval");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("iControllerPacketInterval");
//intentionally blank
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("pollingInterval[1]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("pollingInterval[2]");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("expectedPingForThisNetwork");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("enumIPAddressingMode");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("HelicopterMode");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("sTargetIPAddress");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("savePolledVarsToDisk");
i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = getVarID("glbSystemID");
VarList_MaxIndex[l] = i;}
