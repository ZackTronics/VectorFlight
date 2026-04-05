#include "z01_mainwindow.h"
#include "ui_z01_mainwindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QKeyEvent>
#include <QDir>
#include <QUdpSocket>
#ifdef TARGET_HARDWARE_PI
//#include <QtWidgets>
#endif
#ifndef TARGET_HARDWARE_PI
    
#endif

#include "Globals/globalDefines.h"
#include "Globals/globalStructs.h"
#include "Globals/globalVars.h"
#include "Globals/superVar_Declarations.h"
#include "Globals/superVar1.h"
#include "Globals/superVar2.h"
#ifdef TARGET_HARDWARE_PI
//    
#endif
#ifndef TARGET_HARDWARE_PI
#include "OpenGL/GL_0_Classes.h"
#include "OpenGL/GL_1_Helicopter.h"
#include "OpenGL/GL_2_Render.h"
#include "OpenGL/GL_3_Window.h"
#include "OpenGL/GL_4_Animate.h"
#include "OpenGL/z01_SimFlightControl.h"
#endif


#include "Display/Functions/drawController.h"
//*****************************************
//***   Modifiable Parames See Globals-->globalDefines.h for more modifieable params
//*****************************************
#ifdef TARGET_HARDWARE_PI
//#include "systemDependent/joystickPoll_HelicopterMode.h"
#endif
#ifndef TARGET_HARDWARE_PI
#include "systemDependent/joystickPoll_Dummy.h"
#include "systemDependent/joystickPoll_Linux.h"
#include "systemDependent/joystickPoll_win.h"
#endif
//*****************************************
//*****************************************
#include "UserInput/JoystickProcess.h"
#include "UserInput/joystickCalib.h"
#include "UserInput/Modes_and_Buttons.h"
#include "Display/Mode_04_viewLogs.h"
#include "Display/Mode_03_viewRmtCtrlMode.h"
#include "Display/Mode_02_viewController.h"
#include "Display/Mode_01_calibrateController.h"
#include "Display/Mode_00_normalMode.h"
#include "Display/Mode_05_heliSimulation.h"
#include "Display/updateDisplay.h"
#include "UserInput/keyPressEvent.h"
#include "UserInput/mouseEvents.h"
#include "z02_commsettings.h"
#include "z03_variablelist.h"
#include "z04_commstatistics.h"
#include "z05_aircraftgeometry.h"
#include "z06_autopilotsettings.h"
#include "UserInput/menuBar.h"
#include "Communications/Functions/OtherFunctions.h"
#include "Communications/Functions/ConvQBArr2Nums.h"
#include "Communications/Functions/ConvNums2QBArrs.h"
#include "Communications/Functions/transmitSuperVars.h"
#include "Communications/TCP_VarHandshake.h"
#include "Communications/Send1.h"
#include "Communications/Send2.h"
#include "Communications/Send3.h"
#include "Communications/Recieve1.h"
#include "Communications/Recieve2.h"
#include "Communications/Flightboard.h"
#include "Communications/Flightboard/I2C_Comms.h"
#include "Startup.h" //must be at the end because it starts the monitoring of retain variables which could have been declared anywhere
#ifdef TARGET_HARDWARE_PI
//    
#endif
#ifndef TARGET_HARDWARE_PI
#include <QGLFormat>    
#endif


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("Pegasus Control"));
    Startup();   //QTimer timer1 timer2 timer timer4

    //this connection sends incoming packets to a slot found in dataReceived.h
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(udpPacketReceived()));
#ifdef TARGET_HARDWARE_PI
//    
#endif
#ifndef TARGET_HARDWARE_PI
    connect(this, SIGNAL(Released_JoyNum(int)), this, SLOT(zeroJoysick(int)));
    choppaGlWidget = new  Heli_GLWidget;    
#endif

}








MainWindow::~MainWindow(){
    //monitorRetainDataForChangesToSave();
    writeRetainDataToFile(defaultSettingsFileName);  //we always write to file because sometimes they don't get written.  Perhaps we are masking a bug by doing this.
    delete ui;
}

//I don't know what the change event does
void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

//this causes all windows to close when the mainWindow is closed
void   MainWindow::closeEvent(QCloseEvent*){
    writeRetainDataToFile(defaultSettingsFileName);
    qApp->quit();
    }


void MainWindow::letsPollJoystickIfConditionsMet(){
    if (!HelicopterMode)    pollJoystick();
    }


void MainWindow::animateSimulation(){
    qDebug() << "hello";
}



//on_action MAIN MENUY BAR ACTIONS  --->  SEE UserInput-->Modes_and_Buttons.h









