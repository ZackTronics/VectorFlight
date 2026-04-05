#ifndef CONVQBARR2NUMS_H
#define CONVQBARR2NUMS_H


int bQDebugQByteArray2floatErrors   = 1;


//*******************************************
//The output of this function can be casts as any desired integer-like data type
//such ints or unsigned ints, bytes, unsigned bytes, etc
//
long long int QByteArray2lluint(QByteArray S)
    {
    unsigned long long int sum =0;
    for (int x = 0; x < S.length(); x++)
            {
        if (isBigEndian){
           // sum = sum +   (unsigned char) S.at(S.length()-x-1) * pow((double)256,(x));  //FIXME BIG ENDIAN DOES NOT WORK CORRECTLY
            sum = sum + ((unsigned long long int) ((unsigned char) S.at(x)) << ((S.length()-1)-x) * 8);
            }
        else{
          //sum = sum +  (unsigned char) S.at(S.length()-x-1) * pow((double)256,((S.length()-1)-x));
            sum = sum + ((unsigned long long int) ((unsigned char) S.at(S.length()-x-1)) << ((S.length()-1)-x) * 8);
            }
        }
    return sum;
    }

//*******************************************
float QByteArray2float(QByteArray S)
    {
    if (S.length() != 4) return 0;

    float theResult;
    char SS[4];
    for (unsigned int x = 0; x < sizeof(theResult); x++){
        SS[x] = S.at(x);
        }
    memcpy(&theResult, SS, sizeof(theResult));
    return theResult;
    /*
    if (S.length() ==4){
        unsigned int uintS = QByteArray2lluint(S);
        //qDebug() << "uintS=" << uintS;  //displays dec. rep. of QByteArray to test QByteArray2Float
        unsigned int sign     = (uintS & 0x80000000); //01111111 10000000 00000000 00000000
        unsigned int exponent = (uintS & 0x7F800000); //01111111 10000000 00000000 00000000
        unsigned int mantessa = (uintS & 0x007FFFFF); //00000000 01111111 11111111 11111111
        float normalizedExponent = (float) ((signed char) ((exponent>>23) - 127));
        float normalizedMantessa = (float) 1 + (float) mantessa / pow((float)2,(float)23);
        //qDebug() << "sign" << sign;
        //qDebug() << "exponent" << normalizedExponent;
        //qDebug() << "mantessa" << normalizedMantessa;
        float theVar = normalizedMantessa * pow((float)2,(float)normalizedExponent);
        if (sign != 0) theVar = theVar * (float) (-1);
        //Test for near Zero
        if (fabs(theVar) < pow((float) 10, (float) -38)) theVar = 0;
        return theVar;
    }else{
        QByteArray ErrorMessage;
        ErrorMessage.append ("Error in Function 'float QByteArray2float(QByteArray S)' Unable To Convert ");
        ErrorMessage.append (QString::number(S.length()));
        ErrorMessage.append (" Byte QByteArray to float.");
        qDebug() << ErrorMessage;
        if (bQDebugQByteArray2floatErrors){
            pleaseAppendToFile(ErrorMessage, "/errorLog.txt");
            }
        return 0;
        }
*/
    }


//*******************************************
double QByteArray2double(QByteArray S){
    if (S.length() != 8) return 0;

    double theResult;
    char SS[8];
    for (unsigned int x = 0; x < sizeof(theResult); x++){
        SS[x] = S.at(x);
        }
    memcpy(&theResult, SS, sizeof(theResult));
    return theResult;
    /*
    if (S.length() ==8){
        //TEST FOR SPECIAL CASE OF EXACTLY ZERO
            QByteArray double_Zero;
            double_Zero.resize(sizeof(double));
            QDataStream out(&double_Zero, QIODevice::WriteOnly);
            if (isBigEndian){out.setByteOrder(QDataStream::BigEndian);}
            else {           out.setByteOrder(QDataStream::LittleEndian);}
            out.setFloatingPointPrecision(QDataStream::DoublePrecision);	// use 8 bytes
            out << (double) 0;
            if (S == double_Zero) return 0;
        //ELSE perform conversion
        unsigned long long int uintS = QByteArray2lluint(S);
        //qDebug() << "uintS=" << uintS;  //displays dec. rep. of QByteArray to test QByteArray2double
        unsigned long long int sign     = (uintS & 0x8000000000000000); //01111111 10000000 00000000 00000000
        unsigned long long int exponent = (uintS & 0x7FF0000000000000); //01111111 10000000 00000000 00000000
        unsigned long long int mantessa = (uintS & 0x000FFFFFFFFFFFFF); //00000000 01111111 11111111 11111111
        double normalizedExponent = (double) ((signed char) ((exponent>>52) - 1023));
        double normalizedMantessa = (double) 1 + (double) mantessa / pow((double)2,(double)52);
        //qDebug() << "sign" << sign;
        //qDebug() << "exponent" << normalizedExponent;
        //qDebug() << "mantessa" << normalizedMantessa;
        double thedouble = normalizedMantessa * pow((double)2,(double)normalizedExponent);
        if (sign != 0) thedouble = thedouble * (double) (-1);
        //Test for near Zero
        return thedouble;
    }else{
        QByteArray ErrorMessage;
        ErrorMessage.append ("Error in Function 'double QByteArray2double(QByteArray S)' Unable To Convert ");
        ErrorMessage.append (QString::number(S.length()));
        ErrorMessage.append (" Byte QByteArray to double.");
        qDebug() << ErrorMessage;
        if (bQDebugQByteArray2floatErrors){
            pleaseAppendToFile(ErrorMessage, "/errorLog.txt");
            }
        return 0;
        } */
    }





#endif // CONVQBARR2NUMS_H
