#define JOYSTICKPOLL_DUMMY_H


#ifndef JOYSTICKPOLL_DUMMY_H
#define JOYSTICKPOLL_DUMMY_H

#include <qtimer.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>



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
            controllerConnected = 1;
            int             joystickChange;


//calculate the Azimuth of the joystick
    static int temp1;
    temp1 = temp1 + 10; if (temp1 > 3600) temp1 = 0;
    Ctrl.LJ_Ang = temp1;
    static int temp2;
    temp2 = temp2 - 10; if (temp2 < 0) temp2 = 3600;
    Ctrl.RJ_Ang = temp2;

    Ctrl.LJ_Mag = 32767*sin(3.1415*Ctrl.LJ_Ang/3600);
    Ctrl.RJ_Mag = 32767*sin(3.1415*Ctrl.RJ_Ang/3600);
    if (Ctrl.LJ_Mag > 32767) Ctrl.LJ_Mag = 32767;
    if (Ctrl.RJ_Mag > 32767) Ctrl.RJ_Mag = 32767;
    if (Ctrl.LJ_Mag < 0) Ctrl.LJ_Mag = 0;
    if (Ctrl.RJ_Mag < 0) Ctrl.RJ_Mag = 0;

    Ctrl.A = 0;
    Ctrl.B = 0;
    Ctrl.X = 0;
    Ctrl.Y = 0;
    if ((Ctrl.LJ_Ang > 1800) && (Ctrl.LJ_Ang < 2800)) Ctrl.A = 1;
    if ((Ctrl.LJ_Ang > 800) && (Ctrl.LJ_Ang < 1000)) Ctrl.B = 1;
    if ((Ctrl.LJ_Ang > 500) && (Ctrl.LJ_Ang < 700)) Ctrl.X = 1;
    if ((Ctrl.LJ_Ang > 100) && (Ctrl.LJ_Ang < 300)) Ctrl.Y = 1;




//Other stuff
if (joystickChange) emit joystickEvent();
if (Ctrl.calibMode == 1)
    {
    calibrationRoutine(&Ctrl);
    }
joystickProcess();
}










#endif // JOYSTICKPOLL_DUMMY_H
