#ifndef ALLFUNCTIONS_H
#define ALLFUNCTIONS_H

#include "Globals/globalDefines.h"

//From Globals.ALLFunctions.h
int         getArrayIndex           (varIDtype        varID);
int         getFlags                (varIDtype        varID);
QString     getName                 (varIDtype        varID);
int         getBoardAddress         (varIDtype        varID);
int         getVarClass             (varIDtype        varID);
varIDtype   getVarID                (QString    varName);
int         getFlags                (QString    varName);
int         getArrayIndex           (QString    varName);
short int    getType                 (varIDtype       varID);
QString     getDescription          (varIDtype        varID);
QString     getValAsString          (varIDtype        varID);
QByteArray  getValAsQByteArray      (varIDtype        varID);
QByteArray getQbarrCache(varIDtype        varID);
QByteArray  getCachedVal1AsQByteArray(varIDtype        varID);
void        setCachedValue3         (varIDtype        varID,      QByteArray  newValue);
void        setValue                (varIDtype        varID,      QByteArray  newValue);
void        setValue                (varIDtype        varID,      QString     newValue);



void        setQbarrCache           (varIDtype        varID,      QByteArray  newValue);
void        setCachedValue          (varIDtype        varID,      QByteArray  newValue);
void        setCachedValue          (varIDtype        varID,      QString     newValue);
QString     revEnumTypes            (short int         type);
void        PleaseXmitChanges();


unsigned char           getCachedVal2As_uint8  (varIDtype varID);
unsigned short int      getCachedVal2As_uint16 (varIDtype varID);
unsigned int            getCachedVal2As_uint32 (varIDtype varID);
unsigned long long int  getCachedVal2As_uint64 (varIDtype varID);
signed short int        getCachedVal2As_int16  (varIDtype varID);
signed int              getCachedVal2As_int32  (varIDtype varID);
float                   getCachedVal2As_float32(varIDtype varID);
double                  getCachedVal2As_float64(varIDtype varID);
QString                 getCachedVal2As_QString(varIDtype varID);

unsigned char           getVal2As_uint8  (varIDtype varID);
unsigned short int      getVal2As_uint16 (varIDtype varID);
unsigned int            getVal2As_uint32 (varIDtype varID);
unsigned long long int  getVal2As_uint64 (varIDtype varID);
signed short int        getVal2As_int16  (varIDtype varID);
signed int              getVal2As_int32  (varIDtype varID);
float                   getVal2As_float32(varIDtype varID);
double                  getVal2As_float64(varIDtype varID);
QString                 getVal2As_QString(varIDtype varID);
int getLength(varIDtype varID);

void setCachedValue2(varIDtype varID, unsigned char          newValue);
void setCachedValue2(varIDtype varID, unsigned short int     newValue);
void setCachedValue2(varIDtype varID, unsigned int           newValue);
void setCachedValue2(varIDtype varID, unsigned long long int newValue);
void setCachedValue2(varIDtype varID, signed short int       newValue);
void setCachedValue2(varIDtype varID, signed int             newValue);
void setCachedValue2(varIDtype varID, float                  newValue);
void setCachedValue2(varIDtype varID, double                 newValue);
void setCachedValue2(varIDtype varID, QString                newValue);



void setQbarrCache(varIDtype varID, QByteArray newValue);

//
void pushSuperVarWrite(varIDtype varID);
void pushSuperVarWrite(QString varName);
//
void addSuperVar(unsigned char       &globalVariable, QString varName, int retainFlags, int pollRate, QString description);
void addSuperVar(unsigned short int  &globalVariable, QString varName, int retainFlags, int pollRate, QString description);
void addSuperVar(unsigned int        &globalVariable, QString varName, int retainFlags, int pollRate, QString description);
void addSuperVar(ullint              &globalVariable, QString varName, int retainFlags, int pollRate, QString description);
void addSuperVar(short int           &globalVariable, QString varName, int retainFlags, int pollRate, QString description);
void addSuperVar(int                 &globalVariable, QString varName, int retainFlags, int pollRate, QString description);
void addSuperVar(float               &globalVariable, QString varName, int retainFlags, int pollRate, QString description);
void addSuperVar(double              &globalVariable, QString varName, int retainFlags, int pollRate, QString description);
void addSuperVar(QString             &globalVariable, QString varName, int retainFlags, int pollRate, QString description);

void releaseOutPacket(int isCrucial);
void detectOverflow(int i, int maxIndex, QString messageTxt);
varIDtype  getVarID(QString varName);




//***************************************************************************************************
//***************************************************************************************************
//FROM COMMUNICATIOSN.FUNCTIONS.Allfunctions2.h

//this file can be included to provide access to the following fuctions
QByteArray num2QByteArray(double X);
QByteArray num2QByteArray(float X);
QByteArray num2QByteArray(unsigned long long int X);
QByteArray num2QByteArray(long long int X);
QByteArray num2QByteArray(unsigned int X);
QByteArray num2QByteArray(int X);
QByteArray num2QByteArray(unsigned short int X);
QByteArray num2QByteArray(short int X);
QByteArray num2QByteArray(unsigned char X);
QByteArray num2QByteArray(char X);
long long int QByteArray2lluint(QByteArray S);
float QByteArray2float(QByteArray S);
double QByteArray2double(QByteArray S);
QByteArray QByteArray2Hex(QByteArray &datagram);
QByteArray num2Hex(float X);

short int PeriodicityFunction(unsigned int eventNumber, unsigned int periodMsecs);

//Globals-->superVar1.h
int getSize(varIDtype varID);



#endif // ALLFUNCTIONS_H
