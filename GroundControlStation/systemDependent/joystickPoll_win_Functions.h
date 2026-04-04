#ifndef JOYSTICKPOLL_WIN_FUNCTIONS_H
#define JOYSTICKPOLL_WIN_FUNCTIONS_H


// No MFC
#define WIN32_LEAN_AND_MEAN

//this requires the MSVC version of QT to be installed
//In My case the full filename was qt-windows-opensource-5.0.1-msvc2010_32-x86-offline.exe
//It is also necessarry to isntall Visual C++ 2010 Express  onto the system before it would work
//
//If you recieve the message "The application has failed to start because XINPUT9_1_0.dll was not found."
//install directx_Jun2010_redist

// We need the Windows Header and the XInput Header
#define NOMINMAX  //this prevents an error about undefined tokens :: in QDateTime.  This must appear before include windows.h
#include <windows.h>
#include "C:\Program Files (x86)\Microsoft SDKs\Windows\v7.0A\Include\XInput.h"
//#include "C:\Program Files\Microsoft SDKs\Windows\v7.0A\Include\XInput.h"       //Windows XP d

#pragma comment(lib, "XInput.lib")


// XBOX Controller Class Definition
class CXBOXController
{
private:
    XINPUT_STATE _controllerState;
    int _controllerNum;
public:
    CXBOXController(int playerNumber);
    XINPUT_STATE GetState();
    bool IsConnected();
    void Vibrate(int leftVal = 0, int rightVal = 0);
};

#define XINPUT_GAMEPAD_DPAD_UP          0x0001
#define XINPUT_GAMEPAD_DPAD_DOWN        0x0002
#define XINPUT_GAMEPAD_DPAD_LEFT        0x0004
#define XINPUT_GAMEPAD_DPAD_RIGHT       0x0008
#define XINPUT_GAMEPAD_START            0x0010
#define XINPUT_GAMEPAD_BACK             0x0020
#define XINPUT_GAMEPAD_LEFT_THUMB       0x0040
#define XINPUT_GAMEPAD_RIGHT_THUMB      0x0080
#define XINPUT_GAMEPAD_LEFT_SHOULDER    0x0100
#define XINPUT_GAMEPAD_RIGHT_SHOULDER   0x0200
#define XINPUT_GAMEPAD_A                0x1000
#define XINPUT_GAMEPAD_B                0x2000
#define XINPUT_GAMEPAD_X                0x4000
#define XINPUT_GAMEPAD_Y                0x8000



CXBOXController::CXBOXController(int playerNumber)
{
    // Set the Controller Number
    _controllerNum = playerNumber - 1;
}

XINPUT_STATE CXBOXController::GetState()
{
    // Zeroise the state
    ZeroMemory(&_controllerState, sizeof(XINPUT_STATE));

    // Get the state
    XInputGetState(_controllerNum, &_controllerState);

    return _controllerState;
}

bool CXBOXController::IsConnected()
{
    // Zeroise the state
    ZeroMemory(&_controllerState, sizeof(XINPUT_STATE));

    // Get the state
    DWORD Result = XInputGetState(_controllerNum, &_controllerState);

    if(Result == ERROR_SUCCESS)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CXBOXController::Vibrate(int leftVal, int rightVal)
{
    // Create a Vibraton State
    XINPUT_VIBRATION Vibration;

    // Zeroise the Vibration
    ZeroMemory(&Vibration, sizeof(XINPUT_VIBRATION));

    // Set the Vibration Values
    Vibration.wLeftMotorSpeed = leftVal;
    Vibration.wRightMotorSpeed = rightVal;

    // Vibrate the controller
    XInputSetState(_controllerNum, &Vibration);
}


CXBOXController* Player1;


#endif // JOYSTICKPOLL_WIN_FUNCTIONS_H
