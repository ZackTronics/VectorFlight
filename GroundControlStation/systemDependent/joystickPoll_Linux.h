#define JOYSTICKPOLL_H

#ifndef JOYSTICKPOLL_H
#define JOYSTICKPOLL_H

#include <qtimer.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <unistd.h>



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
#define AXES    8
#define BUTTONS 11
static long long unsigned int pollCount;
static int      joy_fd;
static int      AI[12];
static int      DI[12];
static int      OLD_AI[12];
static int      OLD_DI[12];
int             joystickChange;
struct struct_js_event {
unsigned int	time;     /* event timestamp in milliseconds */
short int	value;    /* value */
char		type;     /* event type */
char		number;   /* axis/button number */
};
struct          struct_js_event js_event;




//if the user requests a reconnection do these things
if (!controllerConnected) {
    Ctrl.requestReconnection = 1;
    }
if (Ctrl.requestReconnection ==1)   {
    Ctrl.requestReconnection = 0;
    pollCount = 0;
    }

pollCount++;
if (pollCount == 1){
    joy_fd = open("/dev/input/js" + QString::number(Ctrl.controllerNum).toLocal8Bit(), O_RDWR | O_NONBLOCK );
    if (joy_fd < 0) {
        //If not connected keep trying other joystick numbers.
        Ctrl.controllerNum = Ctrl.controllerNum + 1;
        if (Ctrl.controllerNum > 3) Ctrl.controllerNum = 0;
        }
    else    {
        controllerConnected = 1;
        }
    }
//Detect if the Joystick has been recently plugged int
QFile joyStickDevice("/dev/input/js" + QString::number(Ctrl.controllerNum).toLocal8Bit());
if (!joyStickDevice.exists()) controllerConnected = 0;
//Zero buttons and Keypad upon connection
if (pollCount < 10){
    for (int i = 0; i < AXES; i++)      AI[i] = 0;
    for (int i = 0; i < BUTTONS; i++)   DI[i] = 0;
    }



//Keep reading complete joystick events and store the data into the appropriate array elements.
while (read (joy_fd, &js_event, sizeof(js_event)) > 0) {
    if (js_event.type==2){  //AXES
        if ((js_event.number >=0) && (js_event.number < AXES)){
            AI[(int) js_event.number] = js_event.value; //type-cast to eliminate compiler warning
            if ((js_event.number == 2) || (js_event.number == 5))   //Add 32767 to Right and Left Trigger so that neutral position is zero
                {
                AI[(int) js_event.number] =  AI[(int) js_event.number] + 32767;
                }
        }
    }
    if (js_event.type==1){  //BUTTONS
        if ((js_event.number >=0) && (js_event.number < BUTTONS)){
        DI[(int) js_event.number] = js_event.value;
        }
    }
}




//look for changes in joystick input
joystickChange = 0;
for (int i = 0; i < AXES; i++){
    if (AI[i] != OLD_AI[i]) joystickChange = 1;
    OLD_AI[i] = AI[i];
    }
for (int i = 0; i < BUTTONS; i++){
    if (DI[i] != OLD_DI[i]) joystickChange = 1;
    OLD_DI[i] = DI[i];
    }

//archive OLD values of button positions
    Ctrl.A_OLD     = Ctrl.A;       Ctrl.B_OLD     = Ctrl.B;         Ctrl.X_OLD     = Ctrl.X;
    Ctrl.Y_OLD     = Ctrl.Y;       Ctrl.LB_OLD    = Ctrl.LB;        Ctrl.RB_OLD    = Ctrl.RB;
    Ctrl.Back_OLD  = Ctrl.Back;    Ctrl.Start_OLD = Ctrl.Start;     Ctrl.Guide_OLD = Ctrl.Guide;
    Ctrl.LJ_OLD    = Ctrl.LJ;      Ctrl.RJ_OLD    = Ctrl.RJ;
//Update new values of button positions
    Ctrl.A         = DI[0];    Ctrl.B         = DI[1];    Ctrl.X         = DI[2];
    Ctrl.Y         = DI[3];    Ctrl.LB        = DI[4];    Ctrl.RB        = DI[5];
    Ctrl.Back      = DI[6];    Ctrl.Start     = DI[7];    Ctrl.Guide     = DI[8];
    Ctrl.LJ        = DI[9];    Ctrl.RJ        = DI[10];

//Zero the Edge Detection of Button Presses & Releases
    Ctrl.A_Pressed     = 0;    Ctrl.B_Pressed     = 0;    Ctrl.X_Pressed     = 0;
    Ctrl.Y_Pressed     = 0;    Ctrl.LB_Pressed    = 0;    Ctrl.RB_Pressed    = 0;
    Ctrl.Back_Pressed  = 0;    Ctrl.Start_Pressed = 0;    Ctrl.LJ_Pressed    = 0;
    Ctrl.RJ_Pressed    = 0;    Ctrl.Guide_Pressed = 0;
    Ctrl.A_Released      = 0;    Ctrl.B_Released      = 0;    Ctrl.X_Released      = 0;
    Ctrl.Y_Released      = 0;    Ctrl.LB_Released     = 0;    Ctrl.RB_Released     = 0;
    Ctrl.Back_Released   = 0;    Ctrl.Start_Released  = 0;    Ctrl.LJ_Released     = 0;
    Ctrl.RJ_Released     = 0;    Ctrl.Guide_Released  = 0;
//Detect Buttons Pressed
    if  ((Ctrl.A     == 1) && (Ctrl.A_OLD     == 0)) Ctrl.A_Pressed     = 1;
    if  ((Ctrl.B     == 1) && (Ctrl.B_OLD     == 0)) Ctrl.B_Pressed     = 1;
    if  ((Ctrl.X     == 1) && (Ctrl.X_OLD     == 0)) Ctrl.X_Pressed     = 1;
    if  ((Ctrl.Y     == 1) && (Ctrl.Y_OLD     == 0)) Ctrl.Y_Pressed     = 1;
    if  ((Ctrl.LB    == 1) && (Ctrl.LB_OLD    == 0)) Ctrl.LB_Pressed    = 1;
    if  ((Ctrl.RB    == 1) && (Ctrl.RB_OLD    == 0)) Ctrl.RB_Pressed    = 1;
    if  ((Ctrl.Back  == 1) && (Ctrl.Back_OLD  == 0)) Ctrl.Back_Pressed  = 1;
    if  ((Ctrl.Start == 1) && (Ctrl.Start_OLD == 0)) Ctrl.Start_Pressed = 1;
    if  ((Ctrl.Guide == 1) && (Ctrl.Guide_OLD == 0)) Ctrl.Guide_Pressed = 1;
    if  ((Ctrl.LJ    == 1) && (Ctrl.LJ_OLD    == 0)) Ctrl.LJ_Pressed    = 1;
    if  ((Ctrl.RJ    == 1) && (Ctrl.RJ_OLD    == 0)) Ctrl.RJ_Pressed    = 1;
//Detect Buttons released
    if  ((Ctrl.A     == 0) && (Ctrl.A_OLD     == 1)) Ctrl.A_Released     = 1;
    if  ((Ctrl.B     == 0) && (Ctrl.B_OLD     == 1)) Ctrl.B_Released     = 1;
    if  ((Ctrl.X     == 0) && (Ctrl.X_OLD     == 1)) Ctrl.X_Released     = 1;
    if  ((Ctrl.Y     == 0) && (Ctrl.Y_OLD     == 1)) Ctrl.Y_Released     = 1;
    if  ((Ctrl.LB    == 0) && (Ctrl.LB_OLD    == 1)) Ctrl.LB_Released    = 1;
    if  ((Ctrl.RB    == 0) && (Ctrl.RB_OLD    == 1)) Ctrl.RB_Released    = 1;
    if  ((Ctrl.Back  == 0) && (Ctrl.Back_OLD  == 1)) Ctrl.Back_Released  = 1;
    if  ((Ctrl.Start == 0) && (Ctrl.Start_OLD == 1)) Ctrl.Start_Released = 1;
    if  ((Ctrl.Guide == 0) && (Ctrl.Guide_OLD == 1)) Ctrl.Guide_Released = 1;
    if  ((Ctrl.LJ    == 0) && (Ctrl.LJ_OLD    == 1)) Ctrl.LJ_Released    = 1;
    if  ((Ctrl.RJ    == 0) && (Ctrl.RJ_OLD    == 1)) Ctrl.RJ_Released    = 1;


//Store the Raw value of each Analog input for the Zeroing function
    Ctrl.LJ_X_Raw  = AI[0];    Ctrl.LJ_Y_Raw  = AI[1];    Ctrl.LT_Raw    = AI[2];
    Ctrl.RJ_X_Raw  = AI[3];    Ctrl.RJ_Y_Raw  = AI[4];    Ctrl.RT_Raw    = AI[5];
    Ctrl.KPD_X_Raw  = AI[6];    Ctrl.KPD_Y_Raw  = AI[7];

    //Store the latest actual value with inputs.  Axis Val's	Neg(-)=Left/Up/Out, Pos(+)=Right/Down/In
    Ctrl.LJ_X     = AI[0] + Ctrl.LJ_X_Offset;
    Ctrl.LJ_Y     = AI[1] + Ctrl.LJ_Y_Offset;
    Ctrl.LT       = AI[2];
    Ctrl.RJ_X     = AI[3] + Ctrl.RJ_X_Offset;
    Ctrl.RJ_Y     = AI[4] + Ctrl.RJ_Y_Offset;
    Ctrl.RT       = AI[5];
    Ctrl.KPD_X     = AI[6];
    Ctrl.KPD_Y     = AI[7];

    //int LJ_Mag, LJ_Dir, RJ_Mag, RJ_Dir;

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

    Ctrl.KPD_X = Ctrl.KPD_X / 32767;
    Ctrl.KPD_Y = -1* Ctrl.KPD_Y / 32767;  //makes 1=up, -1=down

//WORK THAT COULD BE DONE - this could be replaced with a scaling factor from calibration
//Constrain the output to between -32768 to 32767

if (Ctrl.LJ_Mag > 32767) Ctrl.LJ_Mag = 32767;
if (Ctrl.RJ_Mag > 32767) Ctrl.RJ_Mag = 32767;


//Other stuff
if (joystickChange) emit joystickEvent();
if (Ctrl.calibMode == 1)
    {
    calibrationRoutine(&Ctrl);
    }
joystickProcess();
}










#endif // JOYSTICKPOLL_H
