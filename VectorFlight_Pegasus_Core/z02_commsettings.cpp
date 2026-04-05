#include "z02_commsettings.h"
#include "ui_z02_commsettings.h"
#include "Globals/globalStructs.h"
//#include "globals.h"
#include "allFunctions.h"
#include <QMessageBox>
#include <qtimer.h>
#include <QDebug>
#include <QWidget>
#include <QKeyEvent>
#include <QUdpSocket>
#include "Globals/globalDefines.h"

//these variables are named in globals.h
extern QString sTargetIPAddress;
extern QString sConnectionState;

extern ullint     pollingInterval[numberOfPollingIntervals];
extern int enumIPAddressingMode;
extern int commSettingsIsOpen;
extern int HelicopterMode;
extern int HeartbeatInterval;
extern int iControllerPacketInterval;
extern int connectionStatus;
//extern unsigned int handShakeTimeout;
extern unsigned char    glbSystemID;


extern int      savePolledVarsToDisk;

extern QTimer timer4;

extern int nextSentPacketLogIndexToWrite;
extern int pauseAllTransmission;


extern struct Struct_sentPacketInfo blankSentPacketLogEntry;
extern struct Struct_sentPacketInfo sentPacketsLog[sentPacketLogLength];


void releaseOutPacket(QHostAddress   qhaAddress, int isCrucial);

//Global Variable
static int windowIsFullyOpen;


z02_commSettings::z02_commSettings(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::z02_commSettings)
{
    windowIsFullyOpen = 0;
    ui->setupUi(this);

    ui->comboBox->addItem("IPv4");
    ui->comboBox->addItem("IPv6");
    ui->comboBox->setCurrentIndex(enumIPAddressingMode);


    ui->comboBox_2->addItem("Client Computer");
    ui->comboBox_2->addItem("Serving Helicopter");
    ui->comboBox_2->setCurrentIndex(HelicopterMode);


    setWindowTitle(tr("Communications Settings"));

    timer5=new QTimer(this);
    connect(timer5, SIGNAL(timeout()), this, SLOT(periodicRefresh()));
    timer5->start(30);

    //Populate Params during Form Load
    ui->lineEdit->setText(sTargetIPAddress);
    ui->lineEdit_4->setText(QString::number(iControllerPacketInterval));
    ui->lineEdit_5->setText(QString::number(glbSystemID));
    //ui->lineEdit_6->setText(QString::number(iControllerHeartBeatMsecs));
    ui->lineEdit_7->setText(QString::number(HeartbeatInterval));
//    ui->lineEdit_10->setText(QString::number(handShakeTimeout));

    ui->lineEdit_8->setText(QString::number(pollingInterval[1]));
    ui->lineEdit_9->setText(QString::number(pollingInterval[2]));
    ui->checkBox_1->setChecked(savePolledVarsToDisk);

    ui->checkBox_2->setChecked(pauseAllTransmission);

    commSettingsIsOpen = 1;
}

void  z02_commSettings::closeEvent(QCloseEvent *event){
    commSettingsIsOpen = 0;
    UNUSED(*event);
    }

void z02_commSettings::keyPressEvent(QKeyEvent *event)
{
    int inkey = event->key();
    if (inkey == 16777216) { //ESC
        close();
        }
    if ((inkey == 16777220 ) || (inkey == 16777221))   {//ENTER
        applySettings();
        close();
        }
}

//*****************
//ComboBox - currentIndexChanged
//*****************
void z02_commSettings::on_comboBox_currentIndexChanged(const QString &arg1) {
    UNUSED(arg1);
    if (ui->comboBox->currentIndex()== 0)   ui->label_3->setText("IPv4 Address of Helicopter");
    if (ui->comboBox->currentIndex()== 1)   ui->label_3->setText("IPv6 Address of Helicopter");
    }


void z02_commSettings::on_comboBox_2_currentIndexChanged(const QString &arg1) {
    UNUSED(arg1);
    ;//do nothing, this function doesn't even need to exist

    }



//*****************
//Periodic Refresh
//*****************
void z02_commSettings::periodicRefresh(){
//ui->lineEdit_5->setText(QString::number(uliPacketsSent));
//ui->lineEdit_5->setDisabled(1);
//Close the window if it is minimized or is no longer the active window.
//    if  (QApplication::activeWindow()){
//        if (QApplication::activeWindow()->windowTitle() != "Communications Settings") {
//            close();
//            }
//        }
}




z02_commSettings::~z02_commSettings()
{
    delete ui;
}



//*********************************************************
//This function contains everything that happens when you click Apply Settings
//This function is used by the Apply and OK button.
//*********************************************************
int z02_commSettings::applySettings()
    {
    int settingsWereApplied = 0;
    int msgboxResult;
    if     (HelicopterMode != ui->comboBox_2->currentIndex()){
        QString strSysType("");
        if (HelicopterMode == 0)    strSysType.append("New Mode--->This computer is a helicopter itself.");
        if (HelicopterMode == 1)    strSysType.append("New Mode--->This computer is used by a person to control a helicopter.");
        QMessageBox msgBox;
        msgBox.setText("Are you sure you want to apply?\n\n" + strSysType);
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgboxResult = msgBox.exec();
        }
        if ((msgboxResult == (QMessageBox::Ok))||HelicopterMode == ui->comboBox_2->currentIndex()){
            //not pushed
            pauseAllTransmission        = ui->checkBox_2->checkState() && 1;
            glbSystemID                 = ui->lineEdit_5->text().toInt();
            sTargetIPAddress            = ui->lineEdit->text();
            enumIPAddressingMode        = ui->comboBox->currentIndex();
            HelicopterMode              = ui->comboBox_2->currentIndex();
            //pushed
            iControllerPacketInterval   = ui->lineEdit_4->text().toInt();
            pollingInterval[1]          = ui->lineEdit_8->text().toInt();
            pollingInterval[2]          = ui->lineEdit_9->text().toInt();
            savePolledVarsToDisk        = ui->checkBox_1->checkState() && 1;
            HeartbeatInterval           = ui->lineEdit_7->text().toInt();
//            handShakeTimeout            = ui->lineEdit_7->text().toInt();

            PleaseXmitChanges();


            //Erase noncrucial packets from sentPacketsLog
            for (int x = 0; x < sentPacketLogLength; x++) {
  //              if (!sentPacketsLog[x].crucialPacket) sentPacketsLog[x] = blankSentPacketLogEntry;
                }
            settingsWereApplied = 1;
        }
        return  settingsWereApplied;
    }

//*****************
//Apply button
//*****************
void z02_commSettings::on_pushButton_clicked()
    {
    applySettings();
    }

//*****************
//Cancel Button
//*****************
void z02_commSettings::on_pushButton_2_clicked()
    {
    close();
    }

//*****************
//OK Button
//*****************
void z02_commSettings::on_pushButton_3_clicked()
    {
    int settingsWereApplied = applySettings();
    if (settingsWereApplied) close();
    }

