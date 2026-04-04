#ifndef OTHERFUNCTIONS_H
#define OTHERFUNCTIONS_H

#include <math.h>
#include "ConvNums2QBArrs.h"
#include "ConvQBArr2Nums.h"

short int PeriodicityFunction(unsigned int eventNumber, unsigned int periodMsecs){
    static unsigned long long int lastTimeEvent[10];
    ullint mcecsSinceEvent = QDateTime::currentDateTime().toMSecsSinceEpoch() - lastTimeEvent[eventNumber];
    if (mcecsSinceEvent > periodMsecs){
        lastTimeEvent[eventNumber] = QDateTime::currentDateTime().toMSecsSinceEpoch();
        return 1;
        }
    return 0;
}

//Bind to the Socket on program startup, or if settings change.
void MainWindow::rebindUDPSocket(){
    if      (enumIPAddressingMode == 0){
        udpSocket->abort();
        bool isSuccessful = udpSocket->bind(QHostAddress(QHostAddress::Any), num_SocketPort);         //QHostAddress::AnyIPv6  For IPV6
        if (!isSuccessful){
            QMessageBox msgBox;
            msgBox.setText("Unable to Bind Incoming Traffic - Are multiple instances of this program running?  This instance of the program will be unable to receive network traffic.");
            msgBox.exec();
            }
        }
    else if (enumIPAddressingMode ==  1){
        udpSocket->abort();
        bool isSuccessful = udpSocket->bind(QHostAddress(QHostAddress::AnyIPv6), num_SocketPort);         //QHostAddress::AnyIPv6  For IPV6
        if (!isSuccessful){
            QMessageBox msgBox;
            msgBox.setText("Unable to Bind Incoming Traffic - Are multiple instances of this program running?  This instance of the program will be unable to receive network traffic.");
            msgBox.exec();
            }
        }
}



//**************************
//  Calculate CRC X25
//  http://www.lammertbies.nl/forum/viewtopic.php?t=1528
//**************************
#define uint16_t unsigned short int
#define uint8_t unsigned char
uint16_t crcx25(uint8_t *data, size_t len) {
  uint16_t crc = 0xFFFF;
  int i;
  if (len > 0) do {
    crc = crc ^ *data++;
    for (i=0; i<8; i++) {
        if (crc & 1) crc = (crc >> 1) ^ 0x8408;
        else crc >>= 1;
    }
  } while (--len);
  return(~crc);
}





//*******************************************
QByteArray QByteArray2Hex(QByteArray &datagram)
{
    QByteArray fnOutput;
    for (int j = 0; j < datagram.length(); j++)
    {
        char c;
        c = datagram.at(j);
        char nibble[2];
        nibble[0] = (c & 0x0F);
        nibble[1] = (c & 0xF0) >> 4;
        for (int k = 0; k <=1; k++)           {
            if (nibble[k] <= 9)
                nibble[k] = nibble[k] + 48;   //The number 0 is ascii code #48
            else if (nibble[k] == 10) nibble[k] = 'A';
            else if (nibble[k] == 11) nibble[k] = 'B';
            else if (nibble[k] == 12) nibble[k] = 'C';
            else if (nibble[k] == 13) nibble[k] = 'D';
            else if (nibble[k] == 14) nibble[k] = 'E';
            else if (nibble[k] == 15) nibble[k] = 'F';
            }
        QByteArray B;
        B.append(nibble[1]);    B.append(nibble[0]);
        fnOutput.append(B);     fnOutput.append(" ");
     }
return fnOutput;
}


//*******************************************
QByteArray num2Hex(float X)                  {QByteArray y = num2QByteArray(X); return QByteArray2Hex(y);}
//QByteArray num2Hex(double X)                 {QByteArray y = num2QByteArray(X); return QByteArray2Hex(y);}
QByteArray num2Hex(         long long int X) {QByteArray y = num2QByteArray(X); return QByteArray2Hex(y);}
QByteArray num2Hex(unsigned long long int X) {QByteArray y = num2QByteArray(X); return QByteArray2Hex(y);}
QByteArray num2Hex(         int X)           {QByteArray y = num2QByteArray(X); return QByteArray2Hex(y);}
QByteArray num2Hex(unsigned int X)           {QByteArray y = num2QByteArray(X); return QByteArray2Hex(y);}
QByteArray num2Hex(         short int X)     {QByteArray y = num2QByteArray(X); return QByteArray2Hex(y);}
QByteArray num2Hex(unsigned short int X)     {QByteArray y = num2QByteArray(X); return QByteArray2Hex(y);}
QByteArray num2Hex(         char X)          {QByteArray y = num2QByteArray(X); return QByteArray2Hex(y);}
QByteArray num2Hex(unsigned char X)          {QByteArray y = num2QByteArray(X); return QByteArray2Hex(y);}









#endif // OTHERFUNCTIONS_H
