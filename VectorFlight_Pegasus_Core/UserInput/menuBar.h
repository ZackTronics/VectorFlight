#ifndef Z01__MENUBARACTIONS_H
#define Z01__MENUBARACTIONS_H

void ZTransmitCritical(QString variableName);

//extern int varListIsOpen;

//**************************************************************
//          OPEN NEW WINDOWS
//
//*************************************************************

void MainWindow::on_actionAutopilot_Settings_triggered()
{
    if (!AutopilotSettingsIsOpen){
        z06_AutopilotSettings *X = new z06_AutopilotSettings;
        X->setAttribute(Qt::WA_DeleteOnClose, true);  //makes it delete rather than just hide when it is X'd out
        //X->setFocusPolicy(Qt::StrongFocus);
        //X->setWindowModality(Qt::WindowModal);
        X->show();
        int popupWidth  = 720;
        int popupHeight = 550;
        X->setGeometry(this->x() + (this->width())/2 - (popupWidth / 2),
                       this->y() + (this->height())/2 - (popupHeight / 2),
                                                    popupWidth, popupHeight);
    }

}


//Triggered Communications--->Settings
void MainWindow::on_actionSettings_triggered()
{
    if (!commSettingsIsOpen)
    {
        z02_commSettings *X = new z02_commSettings;
        X->setAttribute(Qt::WA_DeleteOnClose, true);  //makes it delete rather than just hide when it is X'd out
        //X->setFocusPolicy(Qt::StrongFocus);
        //X->setWindowModality(Qt::WindowModal);
        X->show();
        int popupWidth  = 720;
        int popupHeight = 550;
        X->setGeometry(this->x() + (this->width())/2 - (popupWidth / 2),
                       this->y() + (this->height())/2 - (popupHeight / 2),
                                                    popupWidth, popupHeight);
    }
}


//Triggered Communications--->Statistics
void MainWindow::on_actionStatistics_triggered()
{

    if (!commStatisticsIsOpen){
    z04_commStatistics *X = new z04_commStatistics;
    X->setAttribute(Qt::WA_DeleteOnClose, true);  //makes it delete rather than just hide when it is X'd out
    //X->setFocusPolicy(Qt::StrongFocus);
    //X->setWindowModality(Qt::WindowModal);
    X->show();
    int popupWidth  = 720;
    int popupHeight = 550;
    X->setGeometry(this->x() + (this->width())/2 - (popupWidth / 2),
                   this->y() + (this->height())/2 - (popupHeight / 2),
                                                popupWidth, popupHeight);
    }
  }



//Triggered Debug--->Variable List

void MainWindow::on_actionMotion_Characteristics_triggered()
{
    if (!varListIsOpen){
        listToView  = listOf_MotionVars;
        z03_variableList *X = new z03_variableList;
        X->setAttribute(Qt::WA_DeleteOnClose, true);
        X->show();
        }
}


void MainWindow::on_actionAircraft_Status_triggered()
{
    if (!varListIsOpen){
        listToView  = listOf_CraftStatus;
        z03_variableList *X = new z03_variableList;
        X->setAttribute(Qt::WA_DeleteOnClose, true);
        X->show();
        }
}



void MainWindow::on_actionAircraft_Geometry_triggered()
{

    if (!aircraftGeometryIsOpen){
        z05_AircraftGeometry *X = new z05_AircraftGeometry;
        X->setAttribute(Qt::WA_DeleteOnClose, true);
        X->show();
        }
}


void MainWindow::on_actionLoad_Default_Settings_triggered()
{    int msgboxResult;
     QMessageBox msgBox;
     msgBox.setText("Please go to the file menu and pick a parmeter set to load.\n\n");
     msgBox.setStandardButtons(QMessageBox::Ok );
     msgboxResult = msgBox.exec();
      UNUSED(msgboxResult);
    }

void MainWindow::on_actionSave_all_settings_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Settings"), "./", tr("Settings Files (*.stz)"));
        if (fileName != ""){
            //qDebug() <<"Filename=" << fileName;
            if (fileName.right(4).toUpper() != ".STZ"){
                fileName = fileName + ".stz"    ;
            }
            writeRetainDataToFile(fileName);
        }
    }

void MainWindow::on_actionLoad_settings_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Settings"), "./", tr("Settings Files (*.stz)"));
    if (fileName != ""){
        QMessageBox msgBox;
        msgBox.setText("Are you sure you want to apply?\n\n");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        int msgboxResult = msgBox.exec();

       if ((msgboxResult == (QMessageBox::Ok))){
            int eCode = readRetainDataFromFile(fileName);
            UNUSED(eCode);
            //HandshakeStep = 0;
           }
    }
}


//Mark Origin
void MainWindow::on_actionMark_Origin_triggered()
{
    Command_PleaseMarkThisAsOrigin++;
    ZTransmitCritical("Command_PleaseMarkThisAsOrigin");
    QMessageBox msgBox;
    msgBox.setText("Command Sent.\n\n");
    msgBox.setStandardButtons(QMessageBox::Ok);
    int msgboxResult = msgBox.exec();
    UNUSED(msgboxResult);
}



#endif // Z01__MENUBARACTIONS_H
