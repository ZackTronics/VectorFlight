# -------------------------------------------------
# Pegasus Control - Project File
# -------------------------------------------------

# *** CONFIGURATION SWITCH ***
# Uncomment the line below to build for Raspberry Pi Flight Controller.
# Leave commented out to build for Desktop Simulator.
# CONFIG += pi_target

TARGET = SendingUnit
TEMPLATE = app

# -------------------------------------------------
# 1. COMMON SETTINGS (Used by both)
# -------------------------------------------------
QT += core gui network widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Common Sources (Core Logic & UI)
SOURCES += main.cpp \
    z01_mainwindow.cpp \
    z02_commsettings.cpp \
    z03_variablelist.cpp \
    z04_commstatistics.cpp \
    z05_aircraftgeometry.cpp \
    z06_autopilotsettings.cpp

# Common Headers
HEADERS += z01_mainwindow.h \
    z02_commsettings.h \
    z00_globals.h \
    z01___drawController.h \
    z03_variablelist.h \
    z04_commstatistics.h \
    z05_aircraftgeometry.h \
    z06_autopilotsettings.h \
    Startup.h \
    allFunctions.h \
    Display/Mode_04_viewLogs.h  \
    Display/Mode_03_viewRmtCtrlMode.h \
    Display/Mode_02_viewController.h \
    Display/Mode_01_calibrateController.h \
    Display/Mode_00_normalMode.h \
    Display/Mode_05_heliSimulation.h \
    Display/updateDisplay.h \
    Display/Functions/drawText.h \
    Display/Functions/drawController.h \
    Globals/globalDefines.h \
    Globals/globalStructs.h \
    Globals/superVar2.h \
    Globals/superVar1.h \
    Globals/globalVars.h \
    Globals/superVar_Declarations.h \
    UserInput/joystickCalib.h \
    UserInput/keyPressEvent.h \
    UserInput/menuBar.h \
    UserInput/Modes_and_Buttons.h \
    UserInput/mouseEvents.h \
    UserInput/JoystickProcess.h \
    Communications/Functions/OtherFunctions.h \
    Communications/Functions/ConvNums2QBArrs.h \
    Communications/Functions/ConvQBArr2Nums.h \
    Communications/Functions/transmitSuperVars.h \
    Communications/Flightboard.h \
    Communications/Recieve1.h \
    Communications/Recieve2.h \
    Communications/Send1.h \
    Communications/Send2.h \
    Communications/Send3.h \
    Communications/TCP_VarHandshake.h \
    Communications/Flightboard/I2C_Comms.h \
    systemDependent/joystickPoll_win.h \
    systemDependent/joystickPoll_win_Functions.h \
    systemDependent/joystickPoll_Dummy.h \
    systemDependent/joystickPoll_HelicopterMode.h \
    systemDependent/joystickPoll_Linux.h

# UI Forms
FORMS += z01_mainwindow.ui \
    z02_commsettings.ui \
    z03_variablelist.ui \
    z04_commstatistics.ui \
    z05_aircraftgeometry.ui \
    z06_autopilotsettings.ui

# -------------------------------------------------
# 2. TARGET SPECIFIC SETTINGS
# -------------------------------------------------

pi_target {
    # --- RASPBERRY PI CONFIGURATION ---
    message(Building for Raspberry Pi / Flight Controller)

    # This defines the macro that your C++ code checks (#ifdef TARGET_HARDWARE_PI)
    DEFINES += TARGET_HARDWARE_PI

    # Installation path for the Pi
    target.path = /myDeploymentDir/
    INSTALLS += target

} else {
    # --- DESKTOP SIMULATOR CONFIGURATION (Default) ---
    message(Building for Desktop Simulator)

    # OpenGL and Multimedia are only needed for the visual sim
    QT += opengl multimedia
    LIBS += -lopengl32

    # Simulator-only Sources
    SOURCES += Globals/objman.cpp

    # Simulator-only Headers
    HEADERS += Globals/objman.h \
               OpenGL/GL_0_Classes.h \
               OpenGL/GL_1_Helicopter.h \
               OpenGL/GL_2_Render.h \
               OpenGL/GL_3_Window.h \
               OpenGL/GL_4_Animate.h \
               OpenGL/z01_SimFlightControl.h
}
