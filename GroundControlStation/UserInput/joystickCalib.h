#ifndef JOYSTICKCALIB_H
#define JOYSTICKCALIB_H

#include "Globals/globalDefines.h"





//******************************************************************
//
//
//******************************************************************
struct Struct_calibrationRoutine
    {
    QString  displayText1;
    QString  displayText2;
    int calibStep;
    };
struct  Struct_calibrationRoutine calibrationRoutineShare;





//sub function for calibration routine
void MainWindow::calibrationGoBack()
{
    if (calibrationRoutineShare.calibStep == 0){
        Ctrl.calibMode      = 0;
        on_enteringInitialMode();
        }
    if ((calibrationRoutineShare.calibStep == 1) || (calibrationRoutineShare.calibStep == 2))
        {
        for (int x = 0; x < 15; x++){
            CtrlCalibShare.LJ_Mag[x] = 0;   CtrlCalibShare.LJ_Ang[x] = 0;
            CtrlCalibShare.RJ_Mag[x] = 0;   CtrlCalibShare.RJ_Ang[x] = 0;
            }
        CtrlCalibShare.LJ_ZeroPosArrPtr           = 0;        CtrlCalibShare.RJ_ZeroPosArrPtr           = 0;
        CtrlCalibShare.LJ_ZeroArrLast             = 0;        CtrlCalibShare.RJ_ZeroArrLast             = 0;
        CtrlCalibShare.LJ_NumPointsinZeroArr      = 0;        CtrlCalibShare.RJ_NumPointsinZeroArr      = 0;
        CtrlCalibShare.LJ_Offset_Mag              = 0;        CtrlCalibShare.LJ_Offset_Ang              = 0;
        CtrlCalibShare.RJ_Offset_Mag              = 0;        CtrlCalibShare.RJ_Offset_Ang              = 0;
        //decrement calibration mode
        calibrationRoutineShare.calibStep         =0; //snap detection mode
        }
    }

void MainWindow::calibrationRoutine(struct Struct_XBox360Controller* Controller)
{
//static int calibStep;

static int iPtr;
static int Ctrl_LJ_Mag[20];
static int Ctrl_RJ_Mag[20];
iPtr++;
if (iPtr == 20) iPtr = 0;
Ctrl_LJ_Mag[iPtr] = Controller->LJ_Mag;
Ctrl_RJ_Mag[iPtr] = Controller->RJ_Mag;
int N[20];          //stores the significance of each of the array elements
for (int i = 0; i < 20; i++)
    {
    if ((iPtr - i) >= 0)   N[i] = iPtr - i;
    if ((iPtr - i) < 0)    N[i] = iPtr - i + 20;
    }



//calibstep
//0     no joysticks have yet snapped to zero
//1     at least one joystick has snapped to zero once
//2     both joystick have snapped to zero 3 or more times
//3     this is the step when the user verifies functionality.

//Calibration Step 0 and 1  (they havne't let both Joysticks snap enough times (0) and they have(1))
if (calibrationRoutineShare.calibStep <= 2)
    {
    static int LJ_SpringLoaded;
    static int RJ_SpringLoaded;
    static int LJsnapCount;
    static int RJsnapCount;

    //if the joystick snaps back into position detect this and call zeroJoystick function to add it to the calibration array
    if (Ctrl_LJ_Mag[N[0]] > 20000) LJ_SpringLoaded = 1;
    int LJ_IsStationary = 1;
    for (int i = 0; i < 10; i++)    if (Ctrl_LJ_Mag[N[0]] != Ctrl_LJ_Mag[N[i]]) LJ_IsStationary = 0;
    if (LJ_SpringLoaded)
        {
        if (LJ_IsStationary && (Ctrl_LJ_Mag[N[0]] < 5000))
            {
            LJ_SpringLoaded = 0;
            LJsnapCount++;
            zeroJoysick(macroLJ);
            }
        }
    if (Ctrl_RJ_Mag[N[0]] > 20000) RJ_SpringLoaded = 1;
    int RJ_IsStationary = 1;
    for (int i = 0; i < 10; i++)    if (Ctrl_RJ_Mag[N[0]] != Ctrl_RJ_Mag[N[i]]) RJ_IsStationary = 0;
    if (RJ_SpringLoaded)
        {
        if (RJ_IsStationary && (Ctrl_RJ_Mag[N[0]] < 5000))
            {
            RJ_SpringLoaded = 0;
            RJsnapCount++;
            zeroJoysick(macroRJ);
            }
        }
 }
//The above items are done in step 0 and 1


//calibstep
//0     no joysticks have yet snapped to zero
//1     at least one joystick has snapped to zero once
//2     both joystick have snapped to zero 3 or more times
//3     this is the step when the user verifies functionality.
//calibstep is also referenced in Display



//Its a little disorganized
//During all steps of calibration, the B button is responded to here
//regardless of what mode we are in.
//A button being pressed conditionals are different.  They are nested inside conditionals that
//only execute depending on step.

// B - Back
//This code is duplicated in keyboardProcess to do all the same things if the back button is pressed.
if (Controller->B_Pressed)  calibrationGoBack();


//This code steps forward in the calibration process and displays text
//for some of the steps which will be displayed by update display if gProgMode = num_calibrateMode
if (calibrationRoutineShare.calibStep <= 2)
    {
    if ((CtrlCalibShare.LJ_NumPointsinZeroArr < 3) && (CtrlCalibShare.RJ_NumPointsinZeroArr < 3))
        {
        calibrationRoutineShare.displayText1 = "Let both Joysticks snap to zero 3 times each.  Press B to go Back.";
        }
    if ((CtrlCalibShare.LJ_NumPointsinZeroArr >= 3) || (CtrlCalibShare.RJ_NumPointsinZeroArr >= 3))
        {
        calibrationRoutineShare.displayText1 = "Let *BOTH* Joysticks snap to zero 3 times each.  Press B to go Back.";
        }
    if ((CtrlCalibShare.LJ_NumPointsinZeroArr >=1) || (CtrlCalibShare.RJ_NumPointsinZeroArr >=1))
        {
        calibrationRoutineShare.calibStep = 1;
        }

    if ((CtrlCalibShare.LJ_NumPointsinZeroArr >=3) && (CtrlCalibShare.RJ_NumPointsinZeroArr >=3))
        {
        calibrationRoutineShare.calibStep = 2;
        }
    }

if (calibrationRoutineShare.calibStep == 2)
    {
    calibrationRoutineShare.displayText1 = "Press 'A' or ENTER to continue, or press B for Back.";
    calibrationRoutineShare.displayText2 = "";
    if (Controller->A_Pressed)  {
        Controller->A_Pressed = 0;
        calibrationRoutineShare.calibStep ++;  //verify mode
        }
    }

if (calibrationRoutineShare.calibStep == 3)
    {
    calibrationRoutineShare.displayText1 = "Verify the controller works to your satisfaction then press ENTER";
    calibrationRoutineShare.displayText2 = " ";
    //The code to process the ENTER key event is in keyboardProcess.h
    }

}





//******************************************************************
//      This function stores and averages the zero positions of each joystick as a reference
//       so that a more accurate joystick position can be calculated
//******************************************************************
void MainWindow::zeroJoysick(int JoyNum)
{
static int  Ctrl_LJ_X_aOffset[arrSize];
static int  Ctrl_LJ_Y_aOffset[arrSize];
static int  Ctrl_RJ_X_aOffset[arrSize];
static int  Ctrl_RJ_Y_aOffset[arrSize];
int         X_aOffset_Sum   = 0;
int         Y_aOffset_Sum   = 0;

if (JoyNum ==macroLJ) { //LJ
    //the required offset is the negative of the raw value
    Ctrl_LJ_X_aOffset[CtrlCalibShare.LJ_ZeroPosArrPtr]   = - Ctrl.LJ_X_Raw;
    Ctrl_LJ_Y_aOffset[CtrlCalibShare.LJ_ZeroPosArrPtr]   = - Ctrl.LJ_Y_Raw;

    //Sum the arrays
    for (int i = 0; (i <= CtrlCalibShare.LJ_NumPointsinZeroArr);  i++)
        {
        X_aOffset_Sum += Ctrl_LJ_X_aOffset[i];
        Y_aOffset_Sum += Ctrl_LJ_Y_aOffset[i];
        }
    //Offset is average (Sum / total array elements)
    Ctrl.LJ_X_Offset = (float) X_aOffset_Sum / (float) (CtrlCalibShare.LJ_NumPointsinZeroArr+1);
    Ctrl.LJ_Y_Offset = (float) Y_aOffset_Sum / (float) (CtrlCalibShare.LJ_NumPointsinZeroArr+1);
        {
        //Share the average in Polar Format
        int temp = 3600 * (atan2(((double) -Ctrl.LJ_X_Offset),((double) + Ctrl.LJ_Y_Offset))) / (2 * 3.1415926) ;
        if (temp >= 0 ) CtrlCalibShare.LJ_Offset_Ang = temp;
        if (temp <  0 ) CtrlCalibShare.LJ_Offset_Ang = temp + 3600;
        CtrlCalibShare.LJ_Offset_Mag = sqrt((pow((float) Ctrl.LJ_X_Offset,2) + pow((float) Ctrl.LJ_Y_Offset,2)));
        CtrlCalibShare.newData = 1;
        //Share the array in Polar Format
            temp = 3600 * (atan2(((double) Ctrl.LJ_X_Raw),((double) - Ctrl.LJ_Y_Raw))) / (2 * 3.1415926) ;
        if (temp >= 0 ) CtrlCalibShare.LJ_Ang[CtrlCalibShare.LJ_ZeroPosArrPtr] = temp;
        if (temp <  0 ) CtrlCalibShare.LJ_Ang[CtrlCalibShare.LJ_ZeroPosArrPtr] = temp + 3600;
        CtrlCalibShare.LJ_Mag[CtrlCalibShare.LJ_ZeroPosArrPtr] = sqrt((pow((float) Ctrl.LJ_X_Raw,2) + pow((float) Ctrl.LJ_Y_Raw,2)));
        CtrlCalibShare.newData = 1;
        }
    CtrlCalibShare.LJ_ZeroArrLast = CtrlCalibShare.LJ_ZeroPosArrPtr;
    CtrlCalibShare.LJ_ZeroPosArrPtr++;
    if (CtrlCalibShare.LJ_ZeroPosArrPtr >= arrSize) {
        CtrlCalibShare.LJ_ZeroPosArrPtr = 0;
        }
    if (CtrlCalibShare.LJ_NumPointsinZeroArr < (arrSize-1)) CtrlCalibShare.LJ_NumPointsinZeroArr++;
    }

if (JoyNum ==macroRJ) {  //RJ
    //the required offset is the negative of the raw value
    Ctrl_RJ_X_aOffset[CtrlCalibShare.RJ_ZeroPosArrPtr]   = - Ctrl.RJ_X_Raw;
    Ctrl_RJ_Y_aOffset[CtrlCalibShare.RJ_ZeroPosArrPtr]   = - Ctrl.RJ_Y_Raw;
    //Sum the arrays
    for (int i = 0; (i <= CtrlCalibShare.RJ_NumPointsinZeroArr);  i++)
        {
        X_aOffset_Sum += Ctrl_RJ_X_aOffset[i];
        Y_aOffset_Sum += Ctrl_RJ_Y_aOffset[i];
        }
    //Offset is average (Sum / total array elements)
    Ctrl.RJ_X_Offset = (float) X_aOffset_Sum / (float) (CtrlCalibShare.RJ_NumPointsinZeroArr+1);
    Ctrl.RJ_Y_Offset = (float) Y_aOffset_Sum / (float) (CtrlCalibShare.RJ_NumPointsinZeroArr+1);
        {
        //Share This Data, firs the average result
        int temp = 3600 * (atan2(((double) -Ctrl.RJ_X_Offset),((double) + Ctrl.RJ_Y_Offset))) / (2 * 3.1415926) ;
        if (temp >= 0 ) CtrlCalibShare.RJ_Offset_Ang = temp;
        if (temp <  0 ) CtrlCalibShare.RJ_Offset_Ang = temp + 3600;
        CtrlCalibShare.RJ_Offset_Mag = sqrt((pow((float) Ctrl.RJ_X_Offset,2) + pow((float) Ctrl.RJ_Y_Offset,2)));
        CtrlCalibShare.newData = 1;
        //Share the array in Polar Format
            temp = 3600 * (atan2(((double) Ctrl.RJ_X_Raw),((double) - Ctrl.RJ_Y_Raw))) / (2 * 3.1415926) ;
        if (temp >= 0 ) CtrlCalibShare.RJ_Ang[CtrlCalibShare.RJ_ZeroPosArrPtr] = temp;
        if (temp <  0 ) CtrlCalibShare.RJ_Ang[CtrlCalibShare.RJ_ZeroPosArrPtr] = temp + 3600;
        CtrlCalibShare.RJ_Mag[CtrlCalibShare.RJ_ZeroPosArrPtr] = sqrt((pow((float) Ctrl.RJ_X_Raw,2) + pow((float) Ctrl.RJ_Y_Raw,2)));
        CtrlCalibShare.newData = 1;
        }
    CtrlCalibShare.RJ_ZeroArrLast = CtrlCalibShare.RJ_ZeroPosArrPtr;
    CtrlCalibShare.RJ_ZeroPosArrPtr++;
    if (CtrlCalibShare.RJ_ZeroPosArrPtr >= arrSize) {
        CtrlCalibShare.RJ_ZeroPosArrPtr = 0;
        }
    if (CtrlCalibShare.RJ_NumPointsinZeroArr < (arrSize-1)) CtrlCalibShare.RJ_NumPointsinZeroArr++;
    }
CtrlCalibShare.newData = 1;  //this is possibly not utilized
}







#endif // JOYSTICKCALIB_H
