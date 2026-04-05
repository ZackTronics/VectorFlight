#ifndef JOYSTICKPROCESS_H
#define JOYSTICKPROCESS_H
#include "allFunctions.h"
#include "Globals/globalDefines.h"

void MainWindow::joystickProcess()
{
//look for significant changes in the controller input.  IF they exist increment counter
//so that they are transmitted
    if
    ((Ctrl.A_OLD          != Ctrl.A)         ||
    (Ctrl.B_OLD          != Ctrl.B)         ||
    (Ctrl.X_OLD          != Ctrl.X)         ||
    (Ctrl.Y_OLD          != Ctrl.Y)         ||
    (Ctrl.Back_OLD       != Ctrl.Back)      ||
    (Ctrl.Start_OLD      != Ctrl.Start)     ||
    (Ctrl.Guide_OLD      != Ctrl.Guide)     ||
    (Ctrl.LJ_OLD         != Ctrl.LJ)        ||
    (Ctrl.RJ_OLD         != Ctrl.RJ)        ||
    (Ctrl.LB_OLD         != Ctrl.LB)        ||
    (Ctrl.RB_OLD         != Ctrl.RB)        ||
    (Ctrl.KPD_X_OLD      != Ctrl.KPD_X)     ||
    (Ctrl.KPD_Y_OLD      != Ctrl.KPD_Y)     ||
    (abs((float) (Ctrl.LT_OLD         - (float) Ctrl.LT))     / (float) Ctrl.LT)     > compK          ||
    (abs((float) (Ctrl.RT_OLD         - (float) Ctrl.RT))     / (float) Ctrl.RT)     > compK          ||
    (abs((float) (Ctrl.LJ_Mag_OLD     - (float) Ctrl.LJ_Mag)) / (float) Ctrl.LJ_Mag) > compK          ||
    (abs((float) (Ctrl.LJ_Ang_OLD     - (float) Ctrl.LJ_Ang)) / (float) Ctrl.LJ_Ang) > compK *0.25    ||
    (abs((float) (Ctrl.RJ_Mag_OLD     - (float) Ctrl.RJ_Mag)) / (float) Ctrl.RJ_Mag) > compK          ||
    (abs((float) (Ctrl.RJ_Ang_OLD     - (float) Ctrl.RJ_Ang)) / (float) Ctrl.RJ_Ang) > compK * 0.25){
    Ctrl.controllerInputCounter++;


    /*
    //Looke for ThrottleMode Selection
    static ullint lastTime_Ctrl_LJDown;
    int clicked_LJ = 0;
    if (Ctrl.LJ && !Ctrl.LJ_OLD){
        if ((QDateTime::currentDateTime().toMSecsSinceEpoch() - lastTime_Ctrl_LJDown) < 500) {
            clicked_LJ = 1;
         if (UserInput_AutoClimb) UserInput_AutoClimb = 0;         else UserInput_AutoClimb = 1;
            if (connectionStatus > 0)   {
                pushSuperVarWrite("UserInput_AutoClimb");
                releaseOutPacket(QHostAddress(sTargetIPAddress), nonCriticalPacket);
                }
        }
        lastTime_Ctrl_LJDown  = QDateTime::currentDateTime().toMSecsSinceEpoch();
        if (clicked_LJ) lastTime_Ctrl_LJDown = 0;
        }
    //Toggle Manual Roll Control
    static ullint lastTime_Ctrl_RJDown;
    int clicked_RJ = 0;
    if (Ctrl.RJ && !Ctrl.RJ_OLD){
        if ((QDateTime::currentDateTime().toMSecsSinceEpoch() - lastTime_Ctrl_RJDown) < 500) {
            clicked_RJ = 1;
         if (UserInput_AutoLateral) UserInput_AutoLateral = 0;         else UserInput_AutoLateral = 1;
            if (connectionStatus > 0)   {
                pushSuperVarWrite("UserInput_AutoLateral");
                releaseOutPacket(QHostAddress(sTargetIPAddress), nonCriticalPacket);
                }
        }
        lastTime_Ctrl_RJDown  = QDateTime::currentDateTime().toMSecsSinceEpoch();
        if (clicked_RJ) lastTime_Ctrl_RJDown = 0;
        }
    //Toggle Manual Yaw ControlCtrl.LB
    static ullint lastTime_LB;
    int clicked_LB = 0;
    if (Ctrl.LB && !Ctrl.LB_OLD){
        if ((QDateTime::currentDateTime().toMSecsSinceEpoch() - lastTime_LB) < 500) {
            clicked_LB = 1;
         if (UserInput_AutoYaw) UserInput_AutoYaw = 0;
         else UserInput_AutoYaw = 1;
            if (connectionStatus > 0)   {
                pushSuperVarWrite("UserInput_AutoYaw");
                releaseOutPacket(QHostAddress(sTargetIPAddress), nonCriticalPacket);
                }
        }
        lastTime_LB  = QDateTime::currentDateTime().toMSecsSinceEpoch();
        if (clicked_LB) lastTime_LB = 0;
        }
    //Toggle User vs Craft Relative Mode
    static ullint lastTime_RB;
    int clicked_RB = 0;
    if (Ctrl.RB && !Ctrl.RB_OLD){
        if ((QDateTime::currentDateTime().toMSecsSinceEpoch() - lastTime_RB) < 500) {
            clicked_RB = 1;
         if (UserInput_ControlAzimuthIsHeliRelative) UserInput_ControlAzimuthIsHeliRelative = 0;
         else UserInput_ControlAzimuthIsHeliRelative = 1;
            if (connectionStatus > 0)   {
                pushSuperVarWrite("UserInput_ControlAzimuthIsHeliRelative");
                releaseOutPacket(QHostAddress(sTargetIPAddress), nonCriticalPacket);
                }
        }
        lastTime_RB  = QDateTime::currentDateTime().toMSecsSinceEpoch();
        if (clicked_RB) lastTime_RB = 0;
        }
*/


    if (Ctrl.Start && !Ctrl.Start_OLD)  {
        if (!simuHeli.isAnimate){
            simuHeli.isAnimate      = 1;
            simuHeli.hasAnimated    = 1;
            }
        else{
            simuHeli.isAnimate      = 0;
            }
        pushSuperVarWrite("simuHeli.hasAnimated");
        pushSuperVarWrite("simuHeli.isAnimate");
        releaseOutPacket(nonCriticalPacket);
        }

    if (Ctrl.Back && !Ctrl.Back_OLD)  {
        simuHeli.hasAnimated = 0;
        simuHeli.isAnimate   = 0;
        pushSuperVarWrite("simuHeli.hasAnimated");
        pushSuperVarWrite("simuHeli.isAnimate");
        releaseOutPacket(nonCriticalPacket);
        }

    if (Ctrl.A && !Ctrl.A_OLD)  {
        AutoPilot_Enabled = 0;
        pushSuperVarWrite("AutoPilot_Enabled");
        releaseOutPacket(nonCriticalPacket);}



    //RECORD OLD VALUES but only when a significant change has occured
    //(otherwise if we have a bunch of very small changes they may not get transmitted)
    Ctrl.A_OLD          = Ctrl.A;
    Ctrl.B_OLD          = Ctrl.B;
    Ctrl.X_OLD          = Ctrl.X;
    Ctrl.Y_OLD          = Ctrl.Y;
    Ctrl.Back_OLD       = Ctrl.Back;
    Ctrl.Start_OLD      = Ctrl.Start;
    Ctrl.Guide_OLD      = Ctrl.Guide;
    Ctrl.LJ_OLD         = Ctrl.LJ;
    Ctrl.RJ_OLD         = Ctrl.RJ;
    Ctrl.LB_OLD         = Ctrl.LB;
    Ctrl.RB_OLD         = Ctrl.RB;
    Ctrl.KPD_X_OLD      = Ctrl.KPD_X;
    Ctrl.KPD_Y_OLD      = Ctrl.KPD_Y;
    Ctrl.LT_OLD         = Ctrl.LT;
    Ctrl.RT_OLD         = Ctrl.RT;
    Ctrl.LJ_Mag_OLD     = Ctrl.LJ_Mag;
    Ctrl.LJ_Ang_OLD     = Ctrl.LJ_Ang;
    Ctrl.RJ_Mag_OLD     = Ctrl.RJ_Mag;
    Ctrl.RJ_Ang_OLD     = Ctrl.RJ_Ang;
    }

//qDebug() << "Counter=" << Ctrl.controllerInputCounter;
}


#endif // JOYSTICKPROCESS_H
