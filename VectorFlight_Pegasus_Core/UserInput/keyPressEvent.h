#ifndef KEYBOARDPROCESS_H
#define KEYBOARDPROCESS_H



void MainWindow::keyPressEvent(QKeyEvent *event)
{
int inkey = event->key();
//ALL MODES
if (inkey==49) on_pushButton_1_clicked();
if (inkey==50) on_pushButton_2_clicked();
if (inkey==51) on_pushButton_3_clicked();
if (inkey==52) on_pushButton_4_clicked();
if (inkey==53) on_pushButton_5_clicked();
if (inkey==54) on_pushButton_6_clicked();
if (inkey==55) on_pushButton_7_clicked();



//SPECIAL MODES

if ((gProgMode == num_normalMode)||(gProgMode == num_viewHeliSimulationMode))
    {
      if (inkey==16777216) { //esc
        if  (menuNum == 2  )   {menuNum = 1; populateMenu();}
        if  (menuNum == 3  )   {menuNum = 1; populateMenu();}
      }
    }


if (gProgMode == num_calibrateMode)
    {

    if (inkey==16777216) calibrationGoBack();  //esc

    if (calibrationRoutineShare.calibStep == 2){
        if ((inkey == 16777220 ) || (inkey == 16777221))   {   //enter
            calibrationRoutineShare.calibStep ++;
            }
        }

    else if (calibrationRoutineShare.calibStep == 3){
        if ((inkey == 16777220 ) || (inkey == 16777221))   {       //enter
             on_enteringInitialMode();
            }
        }

    }

if (gProgMode == num_viewControllerMode)
    {
    if (inkey == 16777216 )  {       //esc
         //on_enteringInitialMode();
        calibrationGoBack();
        }
    }



//Detect CTRL + "+" and CTRL + "-"
//See UserInput--->mouseEvents.h
    if ((inkey == 61) && (QApplication::keyboardModifiers() && Qt::ControlModifier))
        zoomLevel = zoomLevel * 1.1;
    if ((inkey == 45) && (QApplication::keyboardModifiers() && Qt::ControlModifier))
       zoomLevel = zoomLevel / 1.1;
    if (zoomLevel < 0.2) zoomLevel = 0.2;
    if (zoomLevel > 5) zoomLevel = 5;

}


#endif // KEYBOARDPROCESS_H
