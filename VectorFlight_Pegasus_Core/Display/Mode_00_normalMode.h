#ifndef MODE_00_NORMALMODE_H
#define MODE_00_NORMALMODE_H


//Global Variables
extern QImage backgroundImage;


//***************60*(gWindowWidth*0.01)************************
//  Initial Mode
//***************************************
void MainWindow::normalMode()   //The declarations can be found in "z01_mainwindow.h"
{//0=enter 1=refresh 2=resize 3=exit

    //Set BackgroundImage to Grey
    QPainter p;
    p.begin(&backgroundImage);
    p.setBrush(Qt::gray);
    p.drawRect(0,0,gWindowWidth,gWindowHeight);
    p.end();

    int YposOfLineNum[51];
    for (int x = 0; x < 50; x++){
        YposOfLineNum[x] = gWindowHeight -(50 + (x * 14));
    }
#define   normalLeftPen backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::black)

//Display Connection Status

    QString connectInfo = "";
    if (sTargetIPAddress == "127.0.0.1") connectInfo = " loopback connection";

    if (connectionStatus == 0)  drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::darkRed),   5, YposOfLineNum[25],  "Comms=|Bad|");
    if (connectionStatus == 1)  drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::yellow),    5, YposOfLineNum[25],  "Comms=|+  |");
    if (connectionStatus == 2)  drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::green),     5, YposOfLineNum[25],  "Comms=|++ |");
    if (connectionStatus == 3)  drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::green),     5, YposOfLineNum[25],  "Comms=|+++|");
    if (connectionStatus == 3)  drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::green),     5, YposOfLineNum[25],  "Comms=|+++|");

    if (paramSetVersion == 0 )  drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::darkRed),   150, YposOfLineNum[15],  "NO PARAMETER SET LOADED!  COMMS ARE DISABLED.");
    //qDebug() << (sTargetIPAddress != "::ffff:127.0.0.1");

    if (!((sTargetIPAddress == "127.0.0.1")||(sTargetIPAddress == "::ffff:127.0.0.1")) && (I2C_Error != 0 ))                                   drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::darkRed),   200, YposOfLineNum[9],  "FLIGHTBOARD IS DEAD!  Do not fly!");
    if (!((sTargetIPAddress == "127.0.0.1")||(sTargetIPAddress == "::ffff:127.0.0.1")) && (paramSetChecksum_Flightboard != paramSetChecksum))  drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::darkRed),   200, YposOfLineNum[10],  "Incompatible Flightboard Software version.  Do not fly!!");



    if (AutoPilot_Enabled)  drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::yellow),     5, YposOfLineNum[27],  "AUTOPILOT ENABLED press A to disengage");

    if (simuHeli.isAnimate) {
        drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::green),    5, YposOfLineNum[21],  "Simulation Running!");
        }
    if (simuHeli.hasAnimated) {
        if (simuHeli.isAnimate   == 0) drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::yellow),    5, YposOfLineNum[21],  "SIMULATION PAUSED - Press Start.");
        }

if (!HelicopterMode){
    if (HandshakeStep == 0)     drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::darkRed),   200, YposOfLineNum[25],  "Starting Handshake");
    if (HandshakeStep == 1)     drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::darkRed),   200, YposOfLineNum[25],  "Sending Variable Read Requests");
    if (HandshakeStep == 2)     drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::darkRed),   200, YposOfLineNum[25],  "Waiting for response from chopper");
    if (HandshakeStep == 3)     drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::darkRed),   200, YposOfLineNum[25],  "Comparing chopper's info to local info.");
    if (HandshakeStep == 4)     drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::darkRed),   200, YposOfLineNum[25],  "Waiting on user's command.");
    if (HandshakeStep == 5)     drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::darkRed),   200, YposOfLineNum[25],  "Waiting for acknowledgment from chopper.");
    if (HandshakeStep == 6)     drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::darkRed),   200, YposOfLineNum[25],  "Unknown Handshake State");
    if (HandshakeStep == 7)     drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::darkRed),   200, YposOfLineNum[25],  "Unknown Handshake State");
    if (HandshakeStep == 8)     drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::darkRed),   200, YposOfLineNum[25],  "Unknown Handshake State");
    if (HandshakeStep == 9)     drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::darkRed),   200, YposOfLineNum[25],  "Unknown Handshake State");
    if (HandshakeStep == 10)    drawText(backgroundImage, 12, "Bold", "Courier", Qt::AlignLeft, QPen(Qt::darkRed),   200, YposOfLineNum[25],  "");



                        //Display noise about pingexam
                        if(examinePingStep<2)
                                           {drawText(normalLeftPen, 5, YposOfLineNum[24],  "PingExam Wait");}
                        if ((examinePingStep < 5) && (examinePingStep>=2))
                                           {drawText(normalLeftPen, 5, YposOfLineNum[24],  "PingExam "+ QString::number((100*(uliPacketsSent - uliPacketsSentWhenExaminePingStarted))/examinePing_NumberOfPackets) +"%");}
                        }

//Display "Helicopter Mode"  or "Normal Mode"
    if (!controllerConnected){
        drawText(normalLeftPen, gWindowWidth * 0.5, gWindowHeight-55,  "***Controller NOT Connected***");        }
    if (HelicopterMode){
        drawText(normalLeftPen, gWindowWidth * 0.5, gWindowHeight * 0.5,  "Helicopter Mode");        }


if (UserInput_ControlAzimuthIsHeliRelative)   drawText(normalLeftPen, 5, YposOfLineNum[6],  "Perspective - User");
else                                drawText(normalLeftPen, 5, YposOfLineNum[6],  "Perspective - Heli");
if (UserInput_AutoLateral == 0)            drawText(normalLeftPen, 5, YposOfLineNum[7],  "Manual Roll");
if (UserInput_AutoLateral == 1)            drawText(normalLeftPen, 5, YposOfLineNum[7],  "Auto Roll");
if (UserInput_AutoYaw     == 0)               drawText(normalLeftPen, 5, YposOfLineNum[8],  "Manual Yaw");
if (UserInput_AutoYaw     == 1)               drawText(normalLeftPen, 5, YposOfLineNum[8],  "Assisted Yaw");
if (UserInput_AutoYaw     == 2)               drawText(normalLeftPen, 5, YposOfLineNum[8],  "Auto Yaw");
if (UserInput_AutoClimb   == 0)               drawText(normalLeftPen, 5, YposOfLineNum[9],  "Manual Throttle");
if (UserInput_AutoClimb   == 1)               drawText(normalLeftPen, 5, YposOfLineNum[9],  "Assisted Throttle");
if (UserInput_AutoClimb   == 2)               drawText(normalLeftPen, 5, YposOfLineNum[9],  "Auto Altitude");

drawText(normalLeftPen, 5, YposOfLineNum[11],  "Velocity      " + QString::number(Motion_Lateral_Velocity_Mag, 'f', 1));
drawText(normalLeftPen, 5, YposOfLineNum[12],  "Altitude(R)   " + QString::number(Position_Altitude, 'f', 1));
drawText(normalLeftPen, 5, YposOfLineNum[13],  "CraftAzimuth    " + QString::number(Position_FromOrigin_Azimuth, 'f', 1));
drawText(normalLeftPen, 5, YposOfLineNum[14],  "CraftDistance    " + QString::number(Position_FromOrigin_Distance, 'f', 1));


//drawText(normalLeftPen, 5, YposOfLineNum[15],  "Autopilot    " + QString::number(AutoPilot_Enabled));

if (AutoPilot_Enabled == 0)                 drawText(normalLeftPen, 5, YposOfLineNum[15],  "Manual Pilot");
if (AutoPilot_Enabled == 1)                 drawText(normalLeftPen, 5, YposOfLineNum[15],  "Autopilot - Fly Home");
if (AutoPilot_Enabled == 2)                 drawText(normalLeftPen, 5, YposOfLineNum[15],  "Autopilot - Land");;
if (AutoPilot_Enabled == 3)                 drawText(normalLeftPen, 5, YposOfLineNum[15],  "Autopilot - Hold");
if (AutoPilot_Enabled == 4)                 drawText(normalLeftPen, 5, YposOfLineNum[15],  "Autopilot - Up");
if (AutoPilot_Enabled == 5)                 drawText(normalLeftPen, 5, YposOfLineNum[15],  "Motors Locked - Press A to Release.");

if (tooHigh > 0)                 drawText(normalLeftPen, 5, YposOfLineNum[16],  "Ceiling Reached!");

drawText(normalLeftPen, 5, YposOfLineNum[17],  "Battery:\t" + QString::number(Battery_PercentRemainingFiltered, 'f', 0) + "%");




}

#endif // MODE_00_NORMALMODE_H
