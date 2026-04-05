#ifndef MODE_01_CALIBRATECONTROLLER_H
#define MODE_01_CALIBRATECONTROLLER_H

#include "Functions/drawText.h"

//Global Variables
extern QImage backgroundImage;

//***************************************
//  Calibrate Mode
//  num_calibrateMode       1
//***************************************
void MainWindow::calibrateMode()   //The declarations can be found in "z01_mainwindow.h"
{//0=enter 1=refresh 2=resize 3=exit
if (calibrationRoutineShare.calibStep < 3)  drawController(&Ctrl, backgroundImage, 0.4, 0.15, 0.5);
if (calibrationRoutineShare.calibStep == 3)  {
    //drawController(&Ctrl, backgroundImage, 0.1, 0.15, 0.7);

    //This code scales and positions the drawController request to maximize size on the screen
    float controllerRatio        = 1.55;
    float WindowViewableHeight   = gWindowHeight-125;
    if (WindowViewableHeight < 0)  WindowViewableHeight = 0;
    float WindowViewableWidth    = gWindowWidth;
    float windowRatio            = (float) WindowViewableWidth / (float) WindowViewableHeight;
    int heightIsLimiting                                = 0;
    if (windowRatio > controllerRatio) heightIsLimiting = 1;
    float sizeRequested;
    if (!heightIsLimiting)  sizeRequested = 0.9;                                  //it only spans 90% the window
    if (heightIsLimiting)   sizeRequested = 0.9 / (windowRatio/controllerRatio);  //when the window is narrower than it is tall.
    float xPosition         = ((WindowViewableWidth  -  (WindowViewableWidth * sizeRequested))/2) / WindowViewableWidth; //centers horizontally
    float controllerHeight  = (WindowViewableWidth * sizeRequested)/controllerRatio;
    float yPosition         = (((WindowViewableHeight - controllerHeight)/2) / WindowViewableHeight) / windowRatio;
    //qDebug() << "windowRatio" << windowRatio << "xPosition" << xPosition << "\tyPosition" << yPosition << "\tsizeRequested" << sizeRequested;
    drawController(&Ctrl, backgroundImage, xPosition, yPosition+ 0.09,  sizeRequested );
    }

//Display text
drawText(backgroundImage, 14, "Bold", "Verdana", Qt::AlignCenter, QPen(Qt::black),
         50*(gWindowWidth*0.01), 5*(gWindowWidth*0.01), "Calibration Mode");
drawText(backgroundImage, 11.5, "Normal", "Verdana", Qt::AlignCenter, QPen(Qt::black),
         50*(gWindowWidth*0.01), 5*(gWindowWidth*0.01)+20, calibrationRoutineShare.displayText1);
drawText(backgroundImage, 11.5, "Normal", "Verdana", Qt::AlignCenter, QPen(Qt::black),
         50*(gWindowWidth*0.01), 5*(gWindowWidth*0.01)+40, calibrationRoutineShare.displayText2);
//SpringReturn Table

if (calibrationRoutineShare.calibStep  <= 2)
    {
    float Col[15]; for (int x = 0; x < 15; x++) Col[x] = (x*135+95);
    float Row[45]; for (int x = 0; x < 45; x++) Row[x] = (x*15+95);
    drawText(backgroundImage, 11.5, "Bold_Underline", "Verdana", Qt::AlignCenter, QPen(Qt::black),
             Col[0], Row[1], "Left Stick");
    drawText(backgroundImage, 11.5, "Bold_Underline", "Verdana", Qt::AlignCenter,QPen(Qt::black),
             Col[1], Row[1], "Right Stick");
    for (int x = 0; x <= 14; x++)  //Display all points in Calibration Array
        {
        QString LJfontStyle = "Normal"; QString RJfontStyle = "Normal"; float RJfontSize; float LJfontSize;  //recent item is bold
        if (x==(CtrlCalibShare.LJ_ZeroArrLast)) {LJfontStyle = "Bold";      LJfontSize = 12;}
        if (x!=(CtrlCalibShare.LJ_ZeroArrLast)) {LJfontStyle = "Normal";    LJfontSize = 11.5;}
        if (x==(CtrlCalibShare.RJ_ZeroArrLast)) {RJfontStyle = "Bold";      RJfontSize = 12;}
        if ((x!=CtrlCalibShare.RJ_ZeroArrLast)) {RJfontStyle = "Normal";    RJfontSize = 11.5;}
        drawText(backgroundImage, LJfontSize, LJfontStyle, "Verdana", Qt::AlignCenter,QPen(Qt::black), Col[0], Row[x+2],
             QString::number(CtrlCalibShare.LJ_Mag[x])+
             QString::fromUtf8(" ?")+
             QString::number(((float)CtrlCalibShare.LJ_Ang[x])/10)+QString::fromUtf8("?"));
        drawText(backgroundImage, RJfontSize, RJfontStyle, "Verdana", Qt::AlignCenter,QPen(Qt::black), Col[1], Row[x+2],
             QString::number(CtrlCalibShare.RJ_Mag[x])+
             QString::fromUtf8(" ?")+
             QString::number(((float)CtrlCalibShare.RJ_Ang[x])/10)+QString::fromUtf8("?"));
        }
    //Descriptions
    drawText(backgroundImage, 12, "Underline", "Verdana", Qt::AlignCenter,QPen(Qt::black),
             (Col[0]+ Col[1])/2, Row[20]-5, "Averages");
    //Averages at bottom
    drawText(backgroundImage, 12, "Bold", "Verdana", Qt::AlignCenter,QPen(Qt::black), Col[0]-15, Row[21],
             QString::number(CtrlCalibShare.LJ_Offset_Mag)+
             QString::fromUtf8(" ?")+
            QString::number(((float)CtrlCalibShare.LJ_Offset_Ang)/10)+"?");
    drawText(backgroundImage, 12, "Bold", "Verdana", Qt::AlignCenter,QPen(Qt::black), Col[1]+15, Row[21],
             QString::number(CtrlCalibShare.RJ_Offset_Mag)+
             QString::fromUtf8(" ?")+
             QString::number(((float)CtrlCalibShare.RJ_Offset_Ang)/10)+QString::fromUtf8("?"));
    drawText(backgroundImage, 11.5, "Normal", "Verdana", Qt::AlignCenter,QPen(Qt::black),
             Col[0], Row[22], "(" + QString::number(CtrlCalibShare.LJ_NumPointsinZeroArr) + " pts)");
    drawText(backgroundImage, 11.5, "Normal", "Verdana", Qt::AlignCenter,QPen(Qt::black),
             Col[1], Row[22], "(" + QString::number(CtrlCalibShare.RJ_NumPointsinZeroArr) + " pts)");
    CtrlCalibShare.newData = 0;
    }


if (!controllerConnected){
    drawText(backgroundImage, 27, "Bold", "Verdana", Qt::AlignCenter, QPen(Qt::darkRed), gWindowWidth * 0.5, gWindowHeight-55,  "***Controller NOT Connected***");
    }
if (HelicopterMode){
    drawText(backgroundImage, 27, "Bold", "Verdana", Qt::AlignCenter, QPen(Qt::darkRed), gWindowWidth * 0.5, 55,  "***Helicopter Mode***");
    }
}


#endif // MODE_01_CALIBRATECONTROLLER_H
