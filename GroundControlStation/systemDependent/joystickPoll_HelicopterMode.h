#ifndef JOYSTICKPOLL_HELICOPTERMODE_H
#define JOYSTICKPOLL_HELICOPTERMODE_H

#include <qtimer.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>



void calibrationRoutine();

extern int HelicopterMode;



//*******************************************
//Slot:     Re_Acquire_Controller, triggerd from menu or shortcut keys
//
//*******************************************
void MainWindow::on_actionRe_Acquire_Controller_triggered()
{
    //Ctrl.requestReconnection = 1;
}



//*******************************************
//Slot:     pollJoystick()
//Purpose:
//
//Zackery Sobin
//*******************************************
void MainWindow::pollJoystick()
{
     HelicopterMode = 1;
}









#endif // JOYSTICKPOLL_HELICOPTERMODE_H
