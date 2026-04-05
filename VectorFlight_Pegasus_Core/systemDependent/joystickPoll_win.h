//#define JOYSTICKPOLL_WIN_H

#ifndef JOYSTICKPOLL_WIN_H
#define JOYSTICKPOLL_WIN_H



#include <qtimer.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include "joystickPoll_win_Functions.h"



void calibrationRoutine();





//*******************************************
//Slot:     Re_Acquire_Controller, triggerd from menu or shortcut keys
//
//*******************************************
void MainWindow::on_actionRe_Acquire_Controller_triggered()
{
    Ctrl.requestReconnection = 1;
}






//*******************************************
//Slot:     pollJoystick()
//Purpose:
//
//Zackery Sobin
//*******************************************
void MainWindow::pollJoystick()
{
Player1 = new CXBOXController(Ctrl.controllerNum + 1);


controllerConnected = Player1->IsConnected();

if (!controllerConnected){
    Ctrl.controllerNum = Ctrl.controllerNum + 1;
    if (Ctrl.controllerNum > 3) Ctrl.controllerNum = 0;
    }



//Update new values of button positions
    Ctrl.A         = (((unsigned long int )      Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A));
    Ctrl.B         = (((unsigned long int )      Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B));
    Ctrl.X         = (((unsigned long int )      Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X));
    Ctrl.Y         = (((unsigned long int )      Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y));
    Ctrl.LB        = (((unsigned long int )      Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER));
    Ctrl.RB        = (((unsigned long int )      Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER));
    Ctrl.Back      = (((unsigned long int )      Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_BACK));
    Ctrl.Start     = (((unsigned long int )      Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_START));
    Ctrl.Guide     = 0; //(((unsigned long int )      Player1->GetState().Gamepad.wButtons & ));
    Ctrl.LJ        = (((unsigned long int )      Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB));
    Ctrl.RJ        = (((unsigned long int )      Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB));
//Store the Raw value of each Analog input for the Zeroing function
    Ctrl.LJ_X_Raw  =   Player1->GetState().Gamepad.sThumbLX;
    Ctrl.LJ_Y_Raw  = - Player1->GetState().Gamepad.sThumbLY;
    Ctrl.LT_Raw    =   Player1->GetState().Gamepad.bLeftTrigger * 255;
    Ctrl.RJ_X_Raw  =   Player1->GetState().Gamepad.sThumbRX;
    Ctrl.RJ_Y_Raw  = - Player1->GetState().Gamepad.sThumbRY;
    Ctrl.RT_Raw    =   Player1->GetState().Gamepad.bRightTrigger * 255;
    if (((unsigned long int )      Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT))     Ctrl.KPD_X_Raw = -1;
    else if (((unsigned long int ) Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT))    Ctrl.KPD_X_Raw = 1;
    else                                                                                                 Ctrl.KPD_X_Raw = 0;
    if (((unsigned long int )      Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN))     Ctrl.KPD_Y_Raw = -1;
    else if (((unsigned long int ) Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP))       Ctrl.KPD_Y_Raw = 1;
    else                                                                                                 Ctrl.KPD_Y_Raw = 0;


//Store the latest actual value with inputs.  Axis Val's	Neg(-)=Left/Up/Out, Pos(+)=Right/Down/In
    Ctrl.LJ_X     = Ctrl.LJ_X_Raw   + Ctrl.LJ_X_Offset;
    Ctrl.LJ_Y     = Ctrl.LJ_Y_Raw   + Ctrl.LJ_Y_Offset;
    Ctrl.LT       = Ctrl.LT_Raw     + Ctrl.LT_Offset;
    Ctrl.RJ_X     = Ctrl.RJ_X_Raw   + Ctrl.RJ_X_Offset;
    Ctrl.RJ_Y     = Ctrl.RJ_Y_Raw   + Ctrl.RJ_Y_Offset;
    Ctrl.RT       = Ctrl.RT_Raw     + Ctrl.RT_Offset;
    Ctrl.KPD_X    = Ctrl.KPD_X_Raw;
    Ctrl.KPD_Y    = Ctrl.KPD_Y_Raw;


//calculate the Azimuth of the joystick
    int temp = 3600 * (atan2(((double) Ctrl.LJ_X),((double) - Ctrl.LJ_Y))) / (2 * 3.1415926) ;
    if (temp >= 0 ) Ctrl.LJ_Ang = temp;
    if (temp <  0 ) Ctrl.LJ_Ang = temp + 3600;

        temp = 3600 * (atan2(((double) Ctrl.RJ_X),((double) - Ctrl.RJ_Y))) / (2 * 3.1415926) ;
    if (temp >= 0 ) Ctrl.RJ_Ang = temp;
    if (temp <  0 ) Ctrl.RJ_Ang = temp + 3600;


//Calculate the magnitude of Joystick movement difference from zero
    Ctrl.LJ_Mag = sqrt((pow((float) Ctrl.LJ_X,2) + pow((float) Ctrl.LJ_Y,2)));
    Ctrl.RJ_Mag = sqrt((pow((float) Ctrl.RJ_X,2) + pow((float) Ctrl.RJ_Y,2)));

    //WORK THAT COULD BE DONE - this could be replaced with a scaling factor from calibration
    //Constrain the output to between -32768 to 32767
    if (Ctrl.LJ_Mag > 32767) Ctrl.LJ_Mag = 32767;
    if (Ctrl.RJ_Mag > 32767) Ctrl.RJ_Mag = 32767;

    if (Ctrl.calibMode == 1)
        {
        calibrationRoutine(&Ctrl);
        }
joystickProcess();
}




#endif // JOYSTICKPOLL_WIN_H
