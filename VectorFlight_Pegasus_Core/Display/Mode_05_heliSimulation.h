#ifndef MODE_05_HELISIMULATION_H
#define MODE_05_HELISIMULATION_H

#include <QtOpenGL/qglcolormap.h>
void drawSimulation(QImage &image, float xOffset, float yOffset, float xScaleK);


void routineFunction();

//***************60*(gWindowWidth*0.01)************************
//  Initial Mode
//***************************************
void MainWindow::heliSimulationMode()   //The declarations can be found in "z01_mainwindow.h"
{//0=enter 1=refresh 2=resize 3=exit
    normalMode() ;  //we still print normalMode Stuff

#ifdef TARGET_HARDWARE_PI
//
#endif
#ifndef TARGET_HARDWARE_PI
    drawSimulate(); // This draws OpenGL Portion
#endif
}







#endif // MODE_05_HELISIMULATION_H
