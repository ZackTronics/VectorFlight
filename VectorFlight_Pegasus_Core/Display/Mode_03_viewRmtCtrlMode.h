#ifndef MODE_03_VIEWRMTCTRLMODE_H
#define MODE_03_VIEWRMTCTRLMODE_H

extern QImage backgroundImage;

//***************************************
//  Mode function template
//***************************************
void MainWindow::viewRmtCtrlMode()  //The declarations can be found in "z01_mainwindow.h"
{//0=enter 1=refresh 2=resize 3=exit

    //This code scales and positions the drawController request to maximize size on the screen
    float controllerRatio        = 1.55;
    float WindowViewableHeight   = gWindowHeight-35;
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
    //qDebug() << "xPosition" << xPosition << "\tyPosition" << yPosition << "\tsizeRequested" << sizeRequested;
    drawController(&CtrlRx1, backgroundImage, xPosition, yPosition + 0.01,  sizeRequested );

}

#endif // MODE_03_VIEWRMTCTRLMODE_H
