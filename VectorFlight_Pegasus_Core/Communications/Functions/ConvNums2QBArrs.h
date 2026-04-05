#ifndef CONVNUMS2QBARRS_H
#define CONVNUMS2QBARRS_H



//*******************************************
QByteArray num2QByteArray(float testVariable1) {    //long int is the same size as regular intz
    char outputArray[4];
    memcpy(outputArray, &testVariable1, 4);
    QByteArray   Qarr;
    for (unsigned int x = 0; x < 4; x++){
        Qarr.append(outputArray[x]);
        }
    return Qarr;

    /*
    unsigned int    sign = 0;
    float           mantessa = 0;
    int             exp = 0;
    unsigned int    theResult;
    if (testVariable1 ==0){theResult = 0;}
    else{   if (testVariable1 < 0) {
                sign =  0x80000000;
                testVariable1 = testVariable1 * -1.0;
                }
            int watchdog = 0;
            while (1){
                watchdog++;
                if (watchdog > 512) {                        QMessageBox msgBox;
                    //if (testVariable1 = INFINITY){
                        qDebug() << "INFINITY AND BEYOND detected in conversion from float to bit stream!";
                    //    return  num2QByteArray((float) 777777777777777);
                    //    }
                   // if (testVariable1 = -INFINITY){
                    //    qDebug() << "INFINITY AND BEYOND detected in conversion from float to bit stream!";
                    //    return  num2QByteArray((float) -777777777777777);
                     //   }
                    //msgBox.setText("Infinite loop detected in conversion from float to bit stream!.");
                    //msgBox.exec();
                    QByteArray   Y = num2QByteArray(0); return Y; break;} //this code can be eliminated
                mantessa = testVariable1 / powf(2,exp);
                if      (mantessa >= 1 && mantessa < 2) {break;}
                else if (mantessa >= 2.0)               {exp = exp + 1;}
                else if (mantessa < 1   )               {exp = exp - 1;}
                }
            unsigned int fixedExponent =   ((exp+127)<<23);
            unsigned int fixedMantessa = (float) (mantessa -1) * pow((float)2,(float)23);
            theResult = sign + fixedExponent + fixedMantessa;
            }
    QByteArray   Y = num2QByteArray(theResult);
    return Y;
    */
}



//*******************************************
QByteArray num2QByteArray(double testVariable2) {    //long int is the same size as regular int
    char outputArray[8];
    memcpy(outputArray, &testVariable2, 8);
    QByteArray   Qarr;
    for (unsigned int x = 0; x < 8; x++){
        Qarr.append(outputArray[x]);
        }
    return Qarr;
/*
    unsigned long long int sign = 0;
    double mantessa = 0;
    long long int exp = 0;
    unsigned long long int    theResult;

    if (testVariable2 ==0){theResult = 0;theResult = 0;}
    else{   if (testVariable2 < 0) {
                sign =  0x8000000000000000;
                testVariable2 = testVariable2 * -1.0;
                }
            long long int watchdog = 0;
            while (1){
                watchdog++;
                if (watchdog > 512) {                        QMessageBox msgBox;
                    msgBox.setText("Infinite loop detected in conversion from double to bit stream!.");
                    msgBox.exec();
                    QByteArray   Y = num2QByteArray(0); return Y; break;} //this code can be eliminated
                mantessa = testVariable2 / powf(2,exp);
                if      (mantessa >= 1 && mantessa < 2) {break;}
                else if (mantessa >= 2.0)               {exp = exp + 1;}
                else if (mantessa < 1   )               {exp = exp - 1;}
                }
            unsigned long long int fixedExponent =   ((exp+1023)<<52);
            unsigned long long int fixedMantessa = (double) (mantessa -1) * pow((double)2,(double)52);
            theResult = sign | (fixedExponent + fixedMantessa);  //Fixme is this quite right?
            }
    QByteArray   Y = num2QByteArray(theResult);
    return Y;
    */
    }
























//*******************************************
QByteArray num2QByteArray(unsigned long long int X) {    //long int is the same size as regular int
    if (DbgNum2QbyteArray) qDebug() << "Dbg_longlongint";
    QByteArray datagram;
    char byteNum[8];
    byteNum[0] = (X & 0x00000000000000FF);
    byteNum[1] = (X & 0x000000000000FF00) >> 8;
    byteNum[2] = (X & 0x0000000000FF0000) >> 16;
    byteNum[3] = (X & 0x00000000FF000000) >> 24;
    byteNum[4] = (X & 0x000000FF00000000) >> 32;
    byteNum[5] = (X & 0x0000FF0000000000) >> 40;
    byteNum[6] = (X & 0x00FF000000000000) >> 48;
    byteNum[7] = (X & 0xFF00000000000000) >> 56;
    if (!isBigEndian)     for (int x = 0; x <= 7; x++)    datagram.append(byteNum[x]);
    else if (isBigEndian) for (int x = 7; x >= 0; x--)    datagram.append(byteNum[x]);
    return datagram;
}
QByteArray num2QByteArray(long long int X) {    //long int is the same size as regular int
    if (DbgNum2QbyteArray) qDebug() << "Dbg_longlongint";
    QByteArray datagram;
    char byteNum[8];
    byteNum[0] = (X & 0x00000000000000FF);
    byteNum[1] = (X & 0x000000000000FF00) >> 8;
    byteNum[2] = (X & 0x0000000000FF0000) >> 16;
    byteNum[3] = (X & 0x00000000FF000000) >> 24;
    byteNum[4] = (X & 0x000000FF00000000) >> 32;
    byteNum[5] = (X & 0x0000FF0000000000) >> 40;
    byteNum[6] = (X & 0x00FF000000000000) >> 48;
    byteNum[7] = (X & 0xFF00000000000000) >> 56;
    if (!isBigEndian)     for (int x = 0; x <= 7; x++)    datagram.append(byteNum[x]);
    else if (isBigEndian) for (int x = 7; x >= 0; x--)    datagram.append(byteNum[x]);
    return datagram;
}




//*******************************************
QByteArray num2QByteArray(unsigned int X) {    //long int is the same size as regular int
    if (DbgNum2QbyteArray) qDebug() << "Dbg_int";
    QByteArray datagram;
    char byteNum[4];
    byteNum[0] = (X & 0x000000FF);
    byteNum[1] = (X & 0x0000FF00) >> 8;
    byteNum[2] = (X & 0x00FF0000) >> 16;
    byteNum[3] = (X & 0xFF000000) >> 24;
    if (!isBigEndian)     for (int x = 0; x <= 3; x++)    datagram.append(byteNum[x]);
    else if (isBigEndian) for (int x = 3; x >= 0; x--)    datagram.append(byteNum[x]);
    return datagram;
}
QByteArray num2QByteArray(int X) {    //long int is the same size as regular int
    if (DbgNum2QbyteArray) qDebug() << "Dbg_int";
    QByteArray datagram;
    char byteNum[4];
    byteNum[0] = (X & 0x000000FF);
    byteNum[1] = (X & 0x0000FF00) >> 8;
    byteNum[2] = (X & 0x00FF0000) >> 16;
    byteNum[3] = (X & 0xFF000000) >> 24;
    if (!isBigEndian)     for (int x = 0; x <= 3; x++)    datagram.append(byteNum[x]);
    else if (isBigEndian) for (int x = 3; x >= 0; x--)    datagram.append(byteNum[x]);
    return datagram;
}




//*******************************************
QByteArray num2QByteArray(unsigned short int X)   {
    if (DbgNum2QbyteArray) qDebug() << "Dbg_unsigned short int";
    QByteArray datagram;
    char byteNum[2];
    byteNum[0] = (X & 0x00FF);
    byteNum[1] = (X & 0xFF00) >> 8;
    if (!isBigEndian)     for (int x = 0; x <= 1; x++)    datagram.append(byteNum[x]);
    else if (isBigEndian) for (int x = 1; x >= 0; x--)    datagram.append(byteNum[x]);
    return datagram;
}
QByteArray num2QByteArray(short int X)   {
    if (DbgNum2QbyteArray) qDebug() << "Dbg_unsigned short int";
    QByteArray datagram;
    char byteNum[2];
    byteNum[0] = (X & 0x00FF);
    byteNum[1] = (X & 0xFF00) >> 8;
    if (!isBigEndian)     for (int x = 0; x <= 1; x++)    datagram.append(byteNum[x]);
    else if (isBigEndian) for (int x = 1; x >= 0; x--)    datagram.append(byteNum[x]);
    return datagram;
}




//*******************************************
QByteArray num2QByteArray(unsigned char X)   {
    if (DbgNum2QbyteArray) qDebug() << "Dbg_unsigned char";
    QByteArray datagram;
    datagram.append(X);
    return datagram;
}
QByteArray num2QByteArray(char X)   {
    if (DbgNum2QbyteArray) qDebug() << "Dbg_char";
    QByteArray datagram;
    datagram.append(X);
    return datagram;
}



#endif // CONVNUMS2QBARRS_H
