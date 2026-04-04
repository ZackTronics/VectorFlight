#ifndef GL_4_ANIMATE_H
#define GL_4_ANIMATE_H
#include "Globals/globalStructs.h"

void simFlightMain();

void normalizeAngle(float &numbers){
    while (numbers > 360)   numbers  = numbers  - 360;
    while (numbers <= 0)    numbers  = numbers  + 360;
    }
void addVectors(float &Azimuth1, float &Tilt1,  float Azimuth2,float Tilt2){
    static float deg = 3.1415926535898 / 180.0;
    float x[3];                    float y[3];
    x[0] = cos(Azimuth1*deg) * Tilt1;    y[0] = sin(Azimuth1*deg) * Tilt1;
    x[1] = cos(Azimuth2*deg) * Tilt2;    y[1] = sin(Azimuth2*deg) * Tilt2;
    x[2] = x[0] + x[1];                  y[2] = y[0] + y[1];
    Tilt1  = pow((float) (pow((float) x[2], (float) 2.0) +pow((float) y[2], (float) 2.0)), (float) 0.5);
    Azimuth1 = atan2((float) y[2], (float) x[2])/deg;
    }
void MainWindow::resetAnimatedHeli(){
    for (int x = 0; x <= numberOfMotors; x++){
        simuHeli.ActualTorque_Motor[x] = 0;
        }
    simuHeli.YawRate = 0;
    simuHeli.RollAzimuth = 0;
    simuHeli.RollVelocity = 0;
    simuHeli.Velocity_X = 0;
    simuHeli.Velocity_Y = 0;
    simuHeli.Velocity_Z = 0;
    simuHeli.AirVelocity_X = 0;
    simuHeli.AirVelocity_Y = 0;
    simuHeli.AirVelocity_Z = 0;
    //Acceleration
    simuHeli.verticalAccleration = 0;
    simuHeli.NoseAzimuth  = 0;
    simuHeli.TiltAmount   = 0;
    simuHeli.TiltAzimuth  = 0;
    simuHeli.pos_X        = 0;
    simuHeli.pos_Y        = 0;
    simuHeli.pos_Z        = 50;




    simuHeli.mass        = simuHeli.CenterOfCraftMass + simuHeli.propAndMotorMass *numberOfMotors;
    simuHeli.yawMoment   = simuHeli.CenterOfCraftMass * powf(simuHeli.CenterOfCraftRadius,2) /2
                          + simuHeli.propAndMotorMass * simuHeli.armLength * numberOfMotors;
    simuHeli.rollMoment  = simuHeli.CenterOfCraftMass * powf(simuHeli.CenterOfCraftRadius,2) /4
                          + simuHeli.propAndMotorMass * simuHeli.armLength * 0.866 * 2;


    for (int x = 1; x <=6; x++) simuHeli.ActualThrust_Motor[x] = 0;
}

void MainWindow::drawSimulate(){
    static ullint lastExecution;
    ullint timeElapsed  = QDateTime::currentDateTime().toMSecsSinceEpoch() - lastExecution;
    if (timeElapsed >2000000000000) timeElapsed = 0;
    lastExecution = QDateTime::currentDateTime().toMSecsSinceEpoch();
    float secondsElapsed = (float) timeElapsed / 1000.0;
    static float simuHeli_Velocity_Y_OLD;

    static int AutoPilot_Enabled_OLD;
    //qDebug() << AutoPilot_Enabled << simuHeli.hasAnimated << simuHeli.isAnimate;

    if (((AutoPilot_Enabled != 5) && (AutoPilot_Enabled_OLD ==5) && simuHeli.isAnimate == 1)) simuHeli.hasAnimated = 1;

    AutoPilot_Enabled_OLD = AutoPilot_Enabled;

    if (!simuHeli.hasAnimated){

        resetAnimatedHeli() ;

        }

    float deg = 3.1415926535898 / 180.0;
//***************************************************************************
if (simuHeli.isAnimate){

//Setup Constants

    float w1 = simuHeli.propAndMotorMass;
    float w2 = simuHeli.CenterOfCraftMass;
    float r1 = simuHeli.armLength           / 12.0;
    float r2 = simuHeli.CenterOfCraftRadius / 12.0;
    float heliMomentFromProp =    1.0 * w2 * powf((          r1),2.0)
                                + 1.0 * w1 * powf((2.0     * r1),2.0)
                                + 2.0 * w1 * powf((1.73205 * r1),2.0)
                                + 2.0 * w1 * powf((0.866   * r1),2.0);

    float heliMomentFromCenter =  0.5 * w2 * powf((          r2),2.0)
                                + 6.0 * w1 * powf((          r1),2.0);

//Create arrays for each force
    float RollTorque        [3];
    float RollTorqueAzimuth [3];
    float YawTorque         [3];
    float Force_X           [3];
    float Force_Y           [3];
    float Force_Z           [3];

//Calculate Windspeed
    static float WindAzimuth;
    static float WindAzimuthVelocity;

    float fturb = 0;
    if (simuHeli.turbulenceLevel == 1) fturb = 0.00000001;
    if (simuHeli.turbulenceLevel == 2) fturb = 0.000001;
    if (simuHeli.turbulenceLevel == 3) fturb = 0.0001;
    if (simuHeli.turbulenceLevel == 4) fturb = 0.001;
    WindAzimuthVelocity = WindAzimuthVelocity + (rand() -16384) * fturb;
    WindAzimuth = WindAzimuth +  WindAzimuthVelocity/100;
    normalizeAngle(WindAzimuth);
    static float WindSpeedChangeRate;
    static float WindSpeedPrecursor;
    WindSpeedChangeRate = WindSpeedChangeRate + (rand() -16384) * fturb*10;
    WindSpeedPrecursor = WindSpeedPrecursor + WindSpeedChangeRate;
    normalizeAngle(WindSpeedPrecursor);
    float windSpeed = 0.5*(sin(WindSpeedPrecursor * deg) + 1) * simuHeli.maxWindSpeed;
    simuHeli.WindSpeed_Z = windSpeed * sin(WindAzimuth*deg);
    simuHeli.WindSpeed_X = windSpeed * cos(WindAzimuth*deg);
    simuHeli.WindSpeed_Y = 0;

//Drag Force;
    RollTorque[0]         =  (-1.0) * simuHeli.RollVelocity * fabs(simuHeli.RollVelocity) * simuHeli.dragK_Roll;
    RollTorqueAzimuth[0]  =  simuHeli.RollAzimuth;
    YawTorque[0]          =  (-1.0) * simuHeli.YawRate      * fabs(simuHeli.YawRate)      * simuHeli.dragK_Yaw;
    simuHeli.AirVelocity_X = simuHeli.Velocity_X - simuHeli.WindSpeed_X;
    simuHeli.AirVelocity_Y = simuHeli.Velocity_Y - simuHeli.WindSpeed_Y;
    simuHeli.AirVelocity_Z = simuHeli.Velocity_Z - simuHeli.WindSpeed_Z;
    Force_X[0]            =  (-1.0) * simuHeli.AirVelocity_X   * fabs(simuHeli.AirVelocity_X)   * simuHeli.dragK_Linear;
    Force_Y[0]            =  (-1.0) * simuHeli.AirVelocity_Y   * fabs(simuHeli.AirVelocity_Y)   * simuHeli.dragK_Linear;
    Force_Z[0]            =  (-1.0) * simuHeli.AirVelocity_Z   * fabs(simuHeli.AirVelocity_Z)   * simuHeli.dragK_Linear;

//Gravity Force
    Force_Y[1]            =  - simuHeli.mass * 21.82; //g=21.8mph/sec

//Calculate Actual thrust based on Motor response Time Constants
    float motorSpoolK = exp(- secondsElapsed / motor_ResponseTC);
    for (int x = 1; x <= numberOfMotors; x++){
        if (simuMotorFailure[x]) simuHeli.Throttle_Motor[x]  = 0;
        simuHeli.ActualThrust_Motor[x] = simuHeli.Throttle_Motor[x] * (1.0-motorSpoolK) + simuHeli.ActualThrust_Motor[x] * (motorSpoolK);
        }

//Motor Linear Thrust
    float totalMotorThrust = 0;
    for (int x = 1; x <= numberOfMotors; x++ ) totalMotorThrust = totalMotorThrust + simuHeli.ActualThrust_Motor[x];
    Force_X[2] = sin(simuHeli.TiltAmount*deg) * sin(simuHeli.TiltAzimuth * deg);
    Force_Z[2] = sin(simuHeli.TiltAmount*deg) * cos(simuHeli.TiltAzimuth * deg);
    Force_Y[2] = cos(simuHeli.TiltAmount*deg);
    Force_X[2] = Force_X[2] *  totalMotorThrust * 21.82; //g=21.8mph/sec
    Force_Y[2] = Force_Y[2] *  totalMotorThrust * 21.82; //g=21.8mph/sec
    Force_Z[2] = Force_Z[2] *  totalMotorThrust * 21.82; //g=21.8mph/sec

//calculate yaw Forces from motor torque
    YawTorque[2] = 0;
    for (int x = 1; x <= defMaxMotors; x++){
        if (doesRotateClockwise_motor[x] == 0) {
            YawTorque[2] = YawTorque[2] +         simuHeli.ActualThrust_Motor[x];
        }else{
            YawTorque[2] = YawTorque[2] - 1.0  *  simuHeli.ActualThrust_Motor[x];
            }
        }

    YawTorque[2] = (YawTorque[2] *  simuHeli.torqueK) *  (heliMomentFromCenter / heliMomentFromProp) * 21.82; //21.82==correction Factor
    float rolltorque_X[7];
    float rolltorque_Y[7];
    rolltorque_X[0] = 0;
    rolltorque_Y[0] = 0;

//calculate roll force from motor thrusts
    for (int x = 1; x <= defMaxMotors; x++){  //calculate thrust of each motor, convert to effective rolltorque from that motor
        rolltorque_X[x] = simuHeli.ActualThrust_Motor[x] * cos (angle_motor_[x]*deg) * simuHeli.armLength / -12.0;
        rolltorque_Y[x] = simuHeli.ActualThrust_Motor[x] * sin (angle_motor_[x]*deg) * simuHeli.armLength / -12.0;
        }
    for (int x = 1; x <= defMaxMotors; x++ ){   //calculate total rolltorque
      rolltorque_X[0]   = rolltorque_X[0] + rolltorque_X[x];
      rolltorque_Y[0]   = rolltorque_Y[0] + rolltorque_Y[x];
        }
    RollTorque               [2] = powf(powf(rolltorque_X[0],2.0) + powf(rolltorque_Y[0],2.0), 0.5);
    RollTorqueAzimuth        [2] = atan2(rolltorque_Y[0],rolltorque_X[0]) / deg;
    RollTorqueAzimuth        [2] = RollTorqueAzimuth        [2]  + simuHeli.NoseAzimuth;
    normalizeAngle(RollTorqueAzimuth[2]);

//Add all the forces together
    simuHeli.RollTorque         = RollTorque[0];
    simuHeli.RollTorqueAzimuth  = RollTorqueAzimuth[0];
    addVectors(simuHeli.RollTorqueAzimuth,simuHeli.RollTorque,RollTorqueAzimuth[2],RollTorque[2] );
    simuHeli.YawTorque          =  YawTorque[0]                             + YawTorque         [2];
    simuHeli.Force_X            =  Force_X[0]                               + Force_X           [2];
    simuHeli.Force_Y            =  Force_Y[0]               + Force_Y[1]    + Force_Y           [2];
    simuHeli.Force_Z            =  Force_Z[0]                               + Force_Z           [2];

//Forces-->Velocity
    addVectors(simuHeli.RollAzimuth,          simuHeli.RollVelocity,
                 simuHeli.RollTorqueAzimuth, ((simuHeli.RollTorque / simuHeli.rollMoment)/deg)*60.0 * secondsElapsed);
    simuHeli.YawRate     = simuHeli.YawRate     + ((simuHeli.YawTorque / simuHeli.yawMoment)/deg)*60.0 * secondsElapsed;
    simuHeli.Velocity_X  = simuHeli.Velocity_X  + (simuHeli.Force_X    / simuHeli.mass     ) * secondsElapsed;
    simuHeli.Velocity_Y  = simuHeli.Velocity_Y  + (simuHeli.Force_Y    / simuHeli.mass     ) * secondsElapsed;
    simuHeli.Velocity_Z  = simuHeli.Velocity_Z  + (simuHeli.Force_Z    / simuHeli.mass     ) * secondsElapsed;

//Calculate Acceleration (it is needed by flight control)
    simuHeli.verticalAccleration = (simuHeli.Velocity_Y - simuHeli_Velocity_Y_OLD) / secondsElapsed;
    simuHeli_Velocity_Y_OLD = simuHeli.Velocity_Y;

if (freezeSimulatedHeli< 3){
    //Velocity-->Position
    simuHeli.NoseAzimuth  = simuHeli.NoseAzimuth + ((simuHeli.YawRate / 60.0) * 360.0) * secondsElapsed;
    normalizeAngle(simuHeli.NoseAzimuth);
    addVectors(simuHeli.TiltAzimuth, simuHeli.TiltAmount,
                 simuHeli.RollAzimuth, ((simuHeli.RollVelocity / 60.0) * 360.0) * secondsElapsed);
    if (simuHeli.TiltAmount > 180){
        simuHeli.TiltAmount  = 360 -  simuHeli.TiltAmount;
        simuHeli.TiltAzimuth  = simuHeli.TiltAzimuth - 180;
        }
    normalizeAngle(simuHeli.TiltAzimuth);
    normalizeAngle(simuHeli.TiltAmount);


    simuHeli.pos_X        = simuHeli.pos_X + simuHeli.Velocity_X*1.46667 * secondsElapsed ;
    simuHeli.pos_Y        = simuHeli.pos_Y + simuHeli.Velocity_Y*1.46667 * secondsElapsed ;
    simuHeli.pos_Z        = simuHeli.pos_Z + simuHeli.Velocity_Z*1.46667 * secondsElapsed ;
    }

    if (freezeSimulatedHeli >= 1){
        simuHeli.pos_X = 0;
        simuHeli.pos_Y = 5;
        simuHeli.pos_Z = 40;
        simuHeli.Velocity_X     = 0;
        simuHeli.Velocity_Y     = 0;
        simuHeli.Velocity_Z     = 0;
        }
    if (freezeSimulatedHeli >=2){
         simuHeli.TiltAzimuth    = 0.001;
         simuHeli.TiltAmount     = 0;
        }

    if (simuHeli.pos_Y <= 0){
        simuHeli.pos_Y          = 0;
        simuHeli.YawRate        = 0;
        simuHeli.RollAzimuth    = 0;
        simuHeli.RollVelocity   = 0;
        simuHeli.Velocity_X     = 0;
        simuHeli.Velocity_Y     = 0;
        simuHeli.Velocity_Z     = 0;
        }
    }

// DRAW Helicopter
choppaGlWidget->xRot = simuHeli.NoseAzimuth;
choppaGlWidget->yRot = simuHeli.TiltAmount;
choppaGlWidget->zRot = simuHeli.TiltAzimuth;
choppaGlWidget->aRot = simuHeli.pos_X;
choppaGlWidget->bRot = simuHeli.pos_Y;
choppaGlWidget->cRot = simuHeli.pos_Z;
choppaGlWidget->updateGL();

//Run SimFlight
simFlightMain();
}


#endif // GL_4_ANIMATE_H
