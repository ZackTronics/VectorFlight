#ifndef SUPERVAR1_H
#define SUPERVAR1_H
#include "Globals/globalDefines.h"
#include <QString>
#include "allFunctions.h"


#define usint unsigned short int


//REPLACE ALL THESE LOOPS WITH getArrayIndex!!!

varIDtype getVarID(QString varName){
    for(int x=0;x<num_uint8  ;x++){if(Vars.Name_uint8  [x]== varName)return Vars.ID_uint8  [x];}
    for(int x=0;x<num_uint16 ;x++){if(Vars.Name_uint16 [x]== varName)return Vars.ID_uint16 [x];}
    for(int x=0;x<num_uint32 ;x++){if(Vars.Name_uint32 [x]== varName)return Vars.ID_uint32 [x];}
    for(int x=0;x<num_uint64 ;x++){if(Vars.Name_uint64 [x]== varName)return Vars.ID_uint64 [x];}
    for(int x=0;x<num_int16  ;x++){if(Vars.Name_int16  [x]== varName)return Vars.ID_int16  [x];}
    for(int x=0;x<num_int32  ;x++){if(Vars.Name_int32  [x]== varName)return Vars.ID_int32  [x];}
    for(int x=0;x<num_float32;x++){if(Vars.Name_float32[x]== varName)return Vars.ID_float32[x];}
    for(int x=0;x<num_float64;x++){if(Vars.Name_float64[x]== varName)return Vars.ID_float64[x];}
    for(int x=0;x<num_QString;x++){if(Vars.Name_QString[x]== varName)return Vars.ID_QString[x];}
    qDebug() << "Failure in getVarID(QString varName) " + varName;  return 0;}

//fixme
//make array index a lookup table to improve performance
int getArrayIndex(QString varName){return getArrayIndex(getVarID(varName));   }
int getArrayIndex(varIDtype varID){
    static unsigned short int table[maxAllowedVarID];
    if (table[varID]==0){
        for(int x=0;x<num_uint8  ;x++){if(Vars.ID_uint8    [x]== varID  ){table[varID] = x; return x;}}
        for(int x=0;x<num_uint16 ;x++){if(Vars.ID_uint16   [x]== varID  ){table[varID] = x; return x;}}
        for(int x=0;x<num_uint32 ;x++){if(Vars.ID_uint32   [x]== varID  ){table[varID] = x; return x;}}
        for(int x=0;x<num_uint64 ;x++){if(Vars.ID_uint64   [x]== varID  ){table[varID] = x; return x;}}
        for(int x=0;x<num_int16  ;x++){if(Vars.ID_int16    [x]== varID  ){table[varID] = x; return x;}}
        for(int x=0;x<num_int32  ;x++){if(Vars.ID_int32    [x]== varID  ){table[varID] = x; return x;}}
        for(int x=0;x<num_float32;x++){if(Vars.ID_float32  [x]== varID  ){table[varID] = x; return x;}}
        for(int x=0;x<num_float64;x++){if(Vars.ID_float64  [x]== varID  ){table[varID] = x; return x;}}
        for(int x=0;x<num_QString;x++){if(Vars.ID_QString  [x]== varID  ){table[varID] = x; return x;}}
    }else{
        return table[varID];
    }
    qDebug() << "Failure in getArrayIndex( varID) " + varID;         return 0;}



unsigned char enumTypes(QString type){
    if (type == "uint8")   return 1;
    if (type == "uint16")  return 2;
    if (type == "uint32")  return 3;
    if (type == "uint64")  return 4;
    if (type == "int16")   return 5;
    if (type == "int32")   return 6;
    if (type == "float32") return 7;
    if (type == "float64") return 8;
    if (type == "QString") return 9;
    return 0;
    }

QString revEnumTypes(short int type){
    if (type == mac_uint8)   return "uint8";
    if (type == mac_uint16)  return "uint16";
    if (type == mac_uint32)  return "uint32";
    if (type == mac_uint64)  return "uint64";
    if (type == mac_int16)   return "int16";
    if (type == mac_int32)   return "int32";
    if (type == mac_float32) return "float32";
    if (type == mac_float64) return "float64";
    if (type == mac_QString) return "QString";
    return 0;
    }



//PSOC
void getTypeAndArrIndex(varIDtype varID, unsigned short int &index, unsigned short int &type){
    static unsigned short int table1[maxAllowedVarID];  //index
    static unsigned short int table2[maxAllowedVarID];  //type
    if (table1[varID]==0){
        for(int x=0;x<num_uint8  ;x++){if(Vars.ID_uint8    [x]== varID  ){table1[varID] = x; table2[varID] =  Vars.Type_uint8   [x];}}
        for(int x=0;x<num_uint16 ;x++){if(Vars.ID_uint16   [x]== varID  ){table1[varID] = x; table2[varID] =  Vars.Type_uint16  [x];}}
        for(int x=0;x<num_uint32 ;x++){if(Vars.ID_uint32   [x]== varID  ){table1[varID] = x; table2[varID] =  Vars.Type_uint32  [x];}}
        for(int x=0;x<num_uint64 ;x++){if(Vars.ID_uint64   [x]== varID  ){table1[varID] = x; table2[varID] =  Vars.Type_uint64  [x];}}
        for(int x=0;x<num_int16  ;x++){if(Vars.ID_int16    [x]== varID  ){table1[varID] = x; table2[varID] =  Vars.Type_int16   [x];}}
        for(int x=0;x<num_int32  ;x++){if(Vars.ID_int32    [x]== varID  ){table1[varID] = x; table2[varID] =  Vars.Type_int32   [x];}}
        for(int x=0;x<num_float32;x++){if(Vars.ID_float32  [x]== varID  ){table1[varID] = x; table2[varID] =  Vars.Type_float32 [x];}}
        for(int x=0;x<num_float64;x++){if(Vars.ID_float64  [x]== varID  ){table1[varID] = x; table2[varID] =  Vars.Type_float64 [x];}}
        for(int x=0;x<num_QString;x++){if(Vars.ID_QString  [x]== varID  ){table1[varID] = x; table2[varID] =  Vars.Type_QString [x];}}
        }
        index  = table1[varID];
        type   = table2[varID];
    }

int getLength(varIDtype varID){
usint varType; usint i;  getTypeAndArrIndex(varID,i,varType);
    if (varType ==mac_uint8  )  return 1;
    if (varType ==mac_uint16 )  return 2;
    if (varType ==mac_uint32 )  return 4;
    if (varType ==mac_uint64 )  return 8;
    if (varType ==mac_int16  )  return 2;
    if (varType ==mac_int32  )  return 4;
    if (varType ==mac_float32)  return 4;
    if (varType ==mac_float64)  return 8;
    if (varType ==mac_QString)  return 50;
    return 0;
    }

int getSize(varIDtype varID){
    return getLength(varID);
    }


//"uint8"   "uint16"    "uint32"    "uint64"    "int16"    "int32"   "float32"    "float64"  //"QString"
short int getType(varIDtype varID){
   static short int table[maxAllowedVarID];
    if (table[varID]==0){
        for(int x=0;x<num_uint8  ;x++){if(Vars.ID_uint8    [x]== varID  ){table[varID]=Vars.Type_uint8  [x]; return Vars.Type_uint8  [x];}}
        for(int x=0;x<num_uint16 ;x++){if(Vars.ID_uint16   [x]== varID  ){table[varID]=Vars.Type_uint16 [x]; return Vars.Type_uint16 [x];}}
        for(int x=0;x<num_uint32 ;x++){if(Vars.ID_uint32   [x]== varID  ){table[varID]=Vars.Type_uint32 [x]; return Vars.Type_uint32 [x];}}
        for(int x=0;x<num_uint64 ;x++){if(Vars.ID_uint64   [x]== varID  ){table[varID]=Vars.Type_uint64 [x]; return Vars.Type_uint64 [x];}}
        for(int x=0;x<num_int16  ;x++){if(Vars.ID_int16    [x]== varID  ){table[varID]=Vars.Type_int16  [x]; return Vars.Type_int16  [x];}}
        for(int x=0;x<num_int32  ;x++){if(Vars.ID_int32    [x]== varID  ){table[varID]=Vars.Type_int32  [x]; return Vars.Type_int32  [x];}}
        for(int x=0;x<num_float32;x++){if(Vars.ID_float32  [x]== varID  ){table[varID]=Vars.Type_float32[x]; return Vars.Type_float32[x];}}
        for(int x=0;x<num_float64;x++){if(Vars.ID_float64  [x]== varID  ){table[varID]=Vars.Type_float64[x]; return Vars.Type_float64[x];}}
        for(int x=0;x<num_QString;x++){if(Vars.ID_QString  [x]== varID  ){table[varID]=Vars.Type_QString[x]; return Vars.Type_QString[x];}}
    }else{
        return table[varID];
    }
     qDebug() << "Failure in getType( varID) " << varID;             return 0;
}



int getFlags(QString   varName){
    int r = getVarID(varName);
    if (r>0) {return  getFlags(r);
        }else{qDebug() << "Failure in getFlags( varName) " << varName;            return 0;}
    }








int getFlags(varIDtype varID)  {
    usint varType; usint i;  getTypeAndArrIndex(varID,i,varType);
    //qDebug() << __PRETTY_FUNCTION__;
//    qDebug() << varID << varType << i;
    if (varType ==mac_uint8  )  return Vars.retainFlags_uint8  [i];
    if (varType ==mac_uint16 )  return Vars.retainFlags_uint16 [i];
    if (varType ==mac_uint32 )  return Vars.retainFlags_uint32 [i];
    if (varType ==mac_uint64 )  return Vars.retainFlags_uint64 [i];
    if (varType ==mac_int16  )  return Vars.retainFlags_int16  [i];
    if (varType ==mac_int32  )  return Vars.retainFlags_int32  [i];
    if (varType ==mac_float32)  return Vars.retainFlags_float32[i];
    if (varType ==mac_float64)  return Vars.retainFlags_float64[i];
    if (varType ==mac_QString)  return Vars.retainFlags_QString[i];
    qDebug() << "Failure in getFlags( varID) " << varID;             return 0;}

int getBoardAddress(varIDtype varID){
usint varType; usint i;  getTypeAndArrIndex(varID,i,varType);
    if (varType ==mac_uint8  )  return Vars.BoardAddress_uint8  [i];
    if (varType ==mac_uint16 )  return Vars.BoardAddress_uint16 [i];
    if (varType ==mac_uint32 )  return Vars.BoardAddress_uint32 [i];
    if (varType ==mac_uint64 )  return Vars.BoardAddress_uint64 [i];
    if (varType ==mac_int16  )  return Vars.BoardAddress_int16  [i];
    if (varType ==mac_int32  )  return Vars.BoardAddress_int32  [i];
    if (varType ==mac_float32)  return Vars.BoardAddress_float32[i];
    if (varType ==mac_float64)  return Vars.BoardAddress_float64[i];
    if (varType ==mac_QString)  return Vars.BoardAddress_QString[i];
    qDebug() << "Failure in getBoardAddress( varID) " << varID;          return 0;}

int getVarClass(varIDtype varID){
usint varType; usint i;  getTypeAndArrIndex(varID,i,varType);
    if (varType ==mac_uint8  )  return Vars.pollRate_uint8  [i];
    if (varType ==mac_uint16 )  return Vars.pollRate_uint16 [i];
    if (varType ==mac_uint32 )  return Vars.pollRate_uint32 [i];
    if (varType ==mac_uint64 )  return Vars.pollRate_uint64 [i];
    if (varType ==mac_int16  )  return Vars.pollRate_int16  [i];
    if (varType ==mac_int32  )  return Vars.pollRate_int32  [i];
    if (varType ==mac_float32)  return Vars.pollRate_float32[i];
    if (varType ==mac_float64)  return Vars.pollRate_float64[i];
    if (varType ==mac_QString)  return Vars.pollRate_QString[i];
    qDebug() << "Failure in getVarClass( varID) " << varID;          return 0;}

QString getName(varIDtype varID){
usint varType; usint i;  getTypeAndArrIndex(varID,i,varType);
    if (varType ==mac_uint8  )  return Vars.Name_uint8  [i];
    if (varType ==mac_uint16 )  return Vars.Name_uint16 [i];
    if (varType ==mac_uint32 )  return Vars.Name_uint32 [i];
    if (varType ==mac_uint64 )  return Vars.Name_uint64 [i];
    if (varType ==mac_int16  )  return Vars.Name_int16  [i];
    if (varType ==mac_int32  )  return Vars.Name_int32  [i];
    if (varType ==mac_float32)  return Vars.Name_float32[i];
    if (varType ==mac_float64)  return Vars.Name_float64[i];
    if (varType ==mac_QString)  return Vars.Name_QString[i];
    qDebug() << "Failure in getName( varID) " << varID;              return "";}

QString getDescription(varIDtype varID){
usint varType; usint i;  getTypeAndArrIndex(varID,i,varType);
    if (varType ==mac_uint8  )  return Vars.Description_uint8  [i];
    if (varType ==mac_uint16 )  return Vars.Description_uint16 [i];
    if (varType ==mac_uint32 )  return Vars.Description_uint32 [i];
    if (varType ==mac_uint64 )  return Vars.Description_uint64 [i];
    if (varType ==mac_int16  )  return Vars.Description_int16  [i];
    if (varType ==mac_int32  )  return Vars.Description_int32  [i];
    if (varType ==mac_float32)  return Vars.Description_float32[i];
    if (varType ==mac_float64)  return Vars.Description_float64[i];
    if (varType ==mac_QString)  return Vars.Description_QString[i];
    qDebug() << "getDescription(varIDtype varID)" << varID;             return "";}

QString getValAsString(varIDtype varID){
usint varType; usint i;  getTypeAndArrIndex(varID,i,varType);
    if (varType ==mac_uint8  )  return QString::number(*Vars.Ptr_uint8  [i]);
    if (varType ==mac_uint16 )  return QString::number(*Vars.Ptr_uint16 [i]);
    if (varType ==mac_uint32 )  return QString::number(*Vars.Ptr_uint32 [i]);
    if (varType ==mac_uint64 )  return QString::number(*Vars.Ptr_uint64 [i]);
    if (varType ==mac_int16  )  return QString::number(*Vars.Ptr_int16  [i]);
    if (varType ==mac_int32  )  return QString::number(*Vars.Ptr_int32  [i]);
    if (varType ==mac_float32)  return QString::number(*Vars.Ptr_float32[i]);
    if (varType ==mac_float64)  return QString::number(*Vars.Ptr_float64[i]);
    if (varType ==mac_QString)  return *Vars.Ptr_QString[i];

    qDebug() << "Failure in getValAsString( varID) " << varID;        return "";}

QByteArray getValAsQByteArray(varIDtype varID){
usint varType; usint i;  getTypeAndArrIndex(varID,i,varType);
    if (varType ==mac_uint8  )  return num2QByteArray(*Vars.Ptr_uint8  [i]);
    if (varType ==mac_uint16 )  return num2QByteArray(*Vars.Ptr_uint16 [i]);
    if (varType ==mac_uint32 )  return num2QByteArray(*Vars.Ptr_uint32 [i]);
    if (varType ==mac_uint64 )  return num2QByteArray(*Vars.Ptr_uint64 [i]);
    if (varType ==mac_int16  )  return num2QByteArray(*Vars.Ptr_int16  [i]);
    if (varType ==mac_int32  )  return num2QByteArray(*Vars.Ptr_int32  [i]);
    if (varType ==mac_float32)  return num2QByteArray(*Vars.Ptr_float32[i]);
    if (varType ==mac_float64)  return num2QByteArray(*Vars.Ptr_float64[i]);
    if (varType ==mac_QString)  {QString s=*Vars.Ptr_QString[i];return s.toUtf8();}
    qDebug() << "Error in QByteArray getValAsQByteArray(varIDtype varID){";
    return "";
    }



QByteArray getCachedVal1AsQByteArray(varIDtype varID){
usint varType; usint i;  getTypeAndArrIndex(varID,i,varType);
    if (varType ==mac_uint8  )  return num2QByteArray(Vars.Cached1_uint8  [i]);
    if (varType ==mac_uint16 )  return num2QByteArray(Vars.Cached1_uint16 [i]);
    if (varType ==mac_uint32 )  return num2QByteArray(Vars.Cached1_uint32 [i]);
    if (varType ==mac_uint64 )  return num2QByteArray(Vars.Cached1_uint64 [i]);
    if (varType ==mac_int16  )  return num2QByteArray(Vars.Cached1_int16  [i]);
    if (varType ==mac_int32  )  return num2QByteArray(Vars.Cached1_int32  [i]);
    if (varType ==mac_float32)  return num2QByteArray(Vars.Cached1_float32[i]);
    if (varType ==mac_float64)  return num2QByteArray(Vars.Cached1_float64[i]);
    if (varType ==mac_QString)  {QString s=Vars.Cached1_QString[i];return s.toUtf8();}
    qDebug() << "Failure getCachedVal1AsQByteArray( varID)" << varID;  return "";}

QByteArray getQbarrCache(varIDtype varID){
usint varType; usint i;  getTypeAndArrIndex(varID,i,varType);
    if (varType ==mac_uint8  )  return Vars.QbarrCache_uint8  [i];
    if (varType ==mac_uint16 )  return Vars.QbarrCache_uint16 [i];
    if (varType ==mac_uint32 )  return Vars.QbarrCache_uint32 [i];
    if (varType ==mac_uint64 )  return Vars.QbarrCache_uint64 [i];
    if (varType ==mac_int16  )  return Vars.QbarrCache_int16  [i];
    if (varType ==mac_int32  )  return Vars.QbarrCache_int32  [i];
    if (varType ==mac_float32)  return Vars.QbarrCache_float32[i];
    if (varType ==mac_float64)  return Vars.QbarrCache_float64[i];
    if (varType ==mac_QString)  return Vars.QbarrCache_QString[i];
    qDebug() << "Failure getQbarrCache( varID)" << varID;  return "";}


unsigned char           getCachedVal2As_uint8  (varIDtype varID){return  Vars.Cached2_uint8   [getArrayIndex(varID)];}
unsigned short int      getCachedVal2As_uint16 (varIDtype varID){return  Vars.Cached2_uint16  [getArrayIndex(varID)];}
unsigned int            getCachedVal2As_uint32 (varIDtype varID){return  Vars.Cached2_uint32  [getArrayIndex(varID)];}
unsigned long long int  getCachedVal2As_uint64 (varIDtype varID){return  Vars.Cached2_uint64  [getArrayIndex(varID)];}
signed short int        getCachedVal2As_int16  (varIDtype varID){return  Vars.Cached2_int16   [getArrayIndex(varID)];}
signed int              getCachedVal2As_int32  (varIDtype varID){return  Vars.Cached2_int32   [getArrayIndex(varID)];}
float                   getCachedVal2As_float32(varIDtype varID){return  Vars.Cached2_float32 [getArrayIndex(varID)];}
double                  getCachedVal2As_float64(varIDtype varID){return  Vars.Cached2_float64 [getArrayIndex(varID)];}
QString                 getCachedVal2As_QString(varIDtype varID){return  Vars.Cached2_QString [getArrayIndex(varID)];}

unsigned char           getVal2As_uint8  (varIDtype varID){return  *Vars.Ptr_uint8   [getArrayIndex(varID)];}
unsigned short int      getVal2As_uint16 (varIDtype varID){return  *Vars.Ptr_uint16  [getArrayIndex(varID)];}
unsigned int            getVal2As_uint32 (varIDtype varID){return  *Vars.Ptr_uint32  [getArrayIndex(varID)];}
unsigned long long int  getVal2As_uint64 (varIDtype varID){return  *Vars.Ptr_uint64  [getArrayIndex(varID)];}
signed short int        getVal2As_int16  (varIDtype varID){return  *Vars.Ptr_int16   [getArrayIndex(varID)];}
signed int              getVal2As_int32  (varIDtype varID){return  *Vars.Ptr_int32   [getArrayIndex(varID)];}
float                   getVal2As_float32(varIDtype varID){return  *Vars.Ptr_float32 [getArrayIndex(varID)];}
double                  getVal2As_float64(varIDtype varID){return  *Vars.Ptr_float64 [getArrayIndex(varID)];}
QString                 getVal2As_QString(varIDtype varID){return  *Vars.Ptr_QString [getArrayIndex(varID)];}

void setCachedValue2(varIDtype varID, unsigned char          newValue) {Vars.Cached2_uint8   [getArrayIndex(varID)]= newValue;}
void setCachedValue2(varIDtype varID, unsigned short int     newValue) {Vars.Cached2_uint16  [getArrayIndex(varID)]= newValue;}
void setCachedValue2(varIDtype varID, unsigned int           newValue) {Vars.Cached2_uint32  [getArrayIndex(varID)]= newValue;}
void setCachedValue2(varIDtype varID, unsigned long long int newValue) {Vars.Cached2_uint64  [getArrayIndex(varID)]= newValue;}
void setCachedValue2(varIDtype varID, signed short int       newValue) {Vars.Cached2_int16   [getArrayIndex(varID)]= newValue;}
void setCachedValue2(varIDtype varID, signed int             newValue) {Vars.Cached2_int32   [getArrayIndex(varID)]= newValue;}
void setCachedValue2(varIDtype varID, float                  newValue) {Vars.Cached2_float32 [getArrayIndex(varID)]= newValue;}
void setCachedValue2(varIDtype varID, double                 newValue) {Vars.Cached2_float64 [getArrayIndex(varID)]= newValue;}
void setCachedValue2(varIDtype varID, QString                newValue) {Vars.Cached2_QString [getArrayIndex(varID)]= newValue;}

void setCachedValue3(varIDtype varID, unsigned char          newValue) {Vars.Cached3_uint8   [getArrayIndex(varID)]= newValue;}
void setCachedValue3(varIDtype varID, unsigned short int     newValue) {Vars.Cached3_uint16  [getArrayIndex(varID)]= newValue;}
void setCachedValue3(varIDtype varID, unsigned int           newValue) {Vars.Cached3_uint32  [getArrayIndex(varID)]= newValue;}
void setCachedValue3(varIDtype varID, unsigned long long int newValue) {Vars.Cached3_uint64  [getArrayIndex(varID)]= newValue;}
void setCachedValue3(varIDtype varID, signed short int       newValue) {Vars.Cached3_int16   [getArrayIndex(varID)]= newValue;}
void setCachedValue3(varIDtype varID, signed int             newValue) {Vars.Cached3_int32   [getArrayIndex(varID)]= newValue;}
void setCachedValue3(varIDtype varID, float                  newValue) {Vars.Cached3_float32 [getArrayIndex(varID)]= newValue;}
void setCachedValue3(varIDtype varID, double                 newValue) {Vars.Cached3_float64 [getArrayIndex(varID)]= newValue;}
void setCachedValue3(varIDtype varID, QString                newValue) {Vars.Cached3_QString [getArrayIndex(varID)]= newValue;}



//can any of the next 3 functions be eliminated?
void setCachedValue3(varIDtype varID, QByteArray newValue){  //number like 0xFFAABBCC
    int success = 0;
    usint varType; usint i;  getTypeAndArrIndex(varID,i,varType);
    if (varType ==mac_uint8  ) {Vars.Cached3_uint8  [i]= (unsigned char)    QByteArray2lluint(newValue) ; success = 1;}
    if (varType ==mac_uint16 ) {Vars.Cached3_uint16 [i]= (usint)            QByteArray2lluint(newValue) ; success = 1;}
    if (varType ==mac_uint32 ) {Vars.Cached3_uint32 [i]= (unsigned int)     QByteArray2lluint(newValue) ; success = 1;}
    if (varType ==mac_uint64 ) {Vars.Cached3_uint64 [i]= (ullint)           QByteArray2lluint(newValue) ; success = 1;}
    if (varType ==mac_int16  ) {Vars.Cached3_int16  [i]= (short int)        QByteArray2lluint(newValue) ; success = 1;}
    if (varType ==mac_int32  ) {Vars.Cached3_int32  [i]= (int)              QByteArray2lluint(newValue) ; success = 1;}
    if (varType ==mac_float32) {Vars.Cached3_float32[i]=                    QByteArray2float (newValue) ; success = 1;}
    if (varType ==mac_float64) {Vars.Cached3_float64[i]=                    QByteArray2double(newValue) ; success = 1;}
    if (varType ==mac_QString) {Vars.Cached3_QString[i]= QString::fromUtf8                   (newValue) ; success = 1;}
    if (success ==0) qDebug() << "Unable to setValue( varID, QByteArray newValue) " << varID << newValue;}


//can any of the next 3 functions be eliminated?
void setValue(varIDtype varID, QByteArray newValue){  //number like 0xFFAABBCC
    int success = 0;
    usint varType; usint i;  getTypeAndArrIndex(varID,i,varType);
    if (varType ==mac_uint8  ) {*Vars.Ptr_uint8  [i]= (unsigned char)    QByteArray2lluint(newValue) ; success = 1;}
    if (varType ==mac_uint16 ) {*Vars.Ptr_uint16 [i]= (usint)            QByteArray2lluint(newValue) ; success = 1;}
    if (varType ==mac_uint32 ) {*Vars.Ptr_uint32 [i]= (unsigned int)     QByteArray2lluint(newValue) ; success = 1;}
    if (varType ==mac_uint64 ) {*Vars.Ptr_uint64 [i]= (ullint)           QByteArray2lluint(newValue) ; success = 1;}
    if (varType ==mac_int16  ) {*Vars.Ptr_int16  [i]= (short int)        QByteArray2lluint(newValue) ; success = 1;}
    if (varType ==mac_int32  ) {*Vars.Ptr_int32  [i]= (int)              QByteArray2lluint(newValue) ; success = 1;}
    if (varType ==mac_float32) {*Vars.Ptr_float32[i]=                    QByteArray2float (newValue) ; success = 1;}
    if (varType ==mac_float64) {*Vars.Ptr_float64[i]=                    QByteArray2double(newValue) ; success = 1;}
    if (varType ==mac_QString) {*Vars.Ptr_QString[i]= QString::fromUtf8                   (newValue) ; success = 1;}
    if (success ==0) qDebug() << "Unable to setValue( varID, QByteArray newValue) " << varID << newValue;}

void setValue(varIDtype varID, QString newValue){     //These numeric strings like 0.345
    int success = 0;
    usint varType; usint i;  getTypeAndArrIndex(varID,i,varType);
    if (varType ==mac_uint8  )   {*Vars.Ptr_uint8  [i]= newValue.toInt(); success = 1;}
    if (varType ==mac_uint16 )   {*Vars.Ptr_uint16 [i]= newValue.toUShort(); success = 1;}
    if (varType ==mac_uint32 )   {*Vars.Ptr_uint32 [i]= newValue.toUInt(); success = 1;}
    if (varType ==mac_uint64 )   {*Vars.Ptr_uint64 [i]= newValue.toULongLong(); success = 1;}
    if (varType ==mac_int16  )   {*Vars.Ptr_int16  [i]= newValue.toShort(); success = 1;}
    if (varType ==mac_int32  )   {*Vars.Ptr_int32  [i]= newValue.toInt(); success = 1;}
    if (varType ==mac_float32)   {*Vars.Ptr_float32[i]= newValue.toFloat(); success = 1;}
    if (varType ==mac_float64)   {*Vars.Ptr_float64[i]= newValue.toDouble(); success = 1;}
    if (varType ==mac_QString)   {*Vars.Ptr_QString[i]= newValue; success = 1;}
    if (success ==0) qDebug() << "Unable to setValue( varID, QString newValue) " << varID << newValue;}


void setCachedValue1(varIDtype varID, QByteArray newValue){  //number like 0xFFAABBCC
    int success = 0;
    usint varType; usint i;  getTypeAndArrIndex(varID,i,varType);
    if (varType ==mac_uint8  ) {Vars.Cached1_uint8  [i]= (unsigned char) QByteArray2lluint(newValue) ; success = 1;}
    if (varType ==mac_uint16 ) {Vars.Cached1_uint16 [i]= (usint)         QByteArray2lluint(newValue) ; success = 1;}
    if (varType ==mac_uint32 ) {Vars.Cached1_uint32 [i]= (unsigned int)  QByteArray2lluint(newValue) ; success = 1;}
    if (varType ==mac_uint64 ) {Vars.Cached1_uint64 [i]= (ullint)        QByteArray2lluint(newValue) ; success = 1;}
    if (varType ==mac_int16  ) {Vars.Cached1_int16  [i]= (short int)     QByteArray2lluint(newValue) ; success = 1;}
    if (varType ==mac_int32  ) {Vars.Cached1_int32  [i]= (int)           QByteArray2lluint(newValue) ; success = 1;}
    if (varType ==mac_float32) {Vars.Cached1_float32[i]=                 QByteArray2float (newValue) ; success = 1;}
    if (varType ==mac_float64) {Vars.Cached1_float64[i]=                 QByteArray2double(newValue) ; success = 1;}
    if (varType ==mac_QString) {Vars.Cached1_QString[i]= QString::fromUtf8                (newValue) ; success = 1;}
    if (success ==0) qDebug() << "Unable to setCachedValue1( varID, QByteArray newValue) " << varID << newValue;}

void setCachedValue1(varIDtype varID, QString newValue){     //These numeric strings like 0.345
    int success = 0;
    usint varType; usint i;  getTypeAndArrIndex(varID,i,varType);
    if (varType ==mac_uint8  ) {Vars.Cached1_uint8  [i]= newValue.toInt(); success = 1;}
    if (varType ==mac_uint16 ) {Vars.Cached1_uint16 [i]= newValue.toUShort(); success = 1;}
    if (varType ==mac_uint32 ) {Vars.Cached1_uint32 [i]= newValue.toUInt(); success = 1;}
    if (varType ==mac_uint64 ) {Vars.Cached1_uint64 [i]= newValue.toULongLong(); success = 1;}
    if (varType ==mac_int16  ) {Vars.Cached1_int16  [i]= newValue.toShort(); success = 1;}
    if (varType ==mac_int32  ) {Vars.Cached1_int32  [i]= newValue.toInt(); success = 1;}
    if (varType ==mac_float32) {Vars.Cached1_float32[i]= newValue.toFloat(); success = 1;}
    if (varType ==mac_float64) {Vars.Cached1_float64[i]= newValue.toDouble(); success = 1;}
    if (varType ==mac_QString) {Vars.Cached1_QString[i]= newValue; success = 1;}
    if (success ==0) qDebug() << "Unable to setCachedValue1( varID, QString newValue " << varID << newValue;}

void setQbarrCache(varIDtype varID, QByteArray newValue){  //number like 0xFFAABBCC
    int success = 0;
    usint varType; usint i;  getTypeAndArrIndex(varID,i,varType);
    if (varType ==mac_uint8  ) {Vars.QbarrCache_uint8  [i] = newValue; success = 1;}
    if (varType ==mac_uint16 ) {Vars.QbarrCache_uint16 [i] = newValue; success = 1;}
    if (varType ==mac_uint32 ) {Vars.QbarrCache_uint32 [i] = newValue; success = 1;}
    if (varType ==mac_uint64 ) {Vars.QbarrCache_uint64 [i] = newValue; success = 1;}
    if (varType ==mac_int16  ) {Vars.QbarrCache_int16  [i] = newValue; success = 1;}
    if (varType ==mac_int32  ) {Vars.QbarrCache_int32  [i] = newValue; success = 1;}
    if (varType ==mac_float32) {Vars.QbarrCache_float32[i] = newValue; success = 1;}
    if (varType ==mac_float64) {Vars.QbarrCache_float64 [i] = newValue; success = 1;}
    if (varType ==mac_QString) {Vars.QbarrCache_QString[i] = newValue; success = 1;}
    if (success ==0) qDebug() << "Unable to setCachedValue1( varID, QString newValue " << varID << newValue;}





//please move this function up in this file abou 200 lines up to where it goes
QString getValAsStringC3(varIDtype varID){
usint varType; usint i;  getTypeAndArrIndex(varID,i,varType);
    if (varType ==mac_uint8  )  return QString::number(Vars.Cached3_uint8  [i]);
    if (varType ==mac_uint16 )  return QString::number(Vars.Cached3_uint16 [i]);
    if (varType ==mac_uint32 )  return QString::number(Vars.Cached3_uint32 [i]);
    if (varType ==mac_uint64 )  return QString::number(Vars.Cached3_uint64 [i]);
    if (varType ==mac_int16  )  return QString::number(Vars.Cached3_int16  [i]);
    if (varType ==mac_int32  )  return QString::number(Vars.Cached3_int32  [i]);
    if (varType ==mac_float32)  return QString::number(Vars.Cached3_float32[i]);
    if (varType ==mac_float64)  return QString::number(Vars.Cached3_float64[i]);
    if (varType ==mac_QString)  return Vars.Cached3_QString[i];

    qDebug() << "Failure in getValAsString( varID) " + varID;        return "";}


void PleaseXmitChanges(){
    if (connectionStatus != 0){
    for (int x = 1; x <=largestVarID; x++){
        if (getFlags(x) & plsHandshk){
                usint varType; usint i;  getTypeAndArrIndex(x,i,varType);
                if (varType ==mac_uint8  )  if (*Vars.Ptr_uint8  [i] != Vars.Cached3_uint8  [i] ){pushSuperVarWrite(x);}//qDebug() << "argggh" << x<< getValAsString (x)<< getValAsStringC3 (x);}
                if (varType ==mac_uint16 )   if(*Vars.Ptr_uint16 [i] != Vars.Cached3_uint16 [i] ){pushSuperVarWrite(x);}//qDebug() << "argggh" << x<< getValAsString (x)<< getValAsStringC3 (x);}
                if (varType ==mac_uint32 )   if(*Vars.Ptr_uint32 [i] != Vars.Cached3_uint32 [i] ){pushSuperVarWrite(x);}//qDebug() << "argggh" << x<< getValAsString (x)<< getValAsStringC3 (x);}
                if (varType ==mac_uint64 )   if(*Vars.Ptr_uint64 [i] != Vars.Cached3_uint64 [i] ){pushSuperVarWrite(x);}//qDebug() << "argggh" << x<< getValAsString (x)<< getValAsStringC3 (x);}
                if (varType ==mac_int16  )   if(*Vars.Ptr_int16  [i] != Vars.Cached3_int16  [i] ){pushSuperVarWrite(x);}//qDebug() << "argggh" << x<< getValAsString (x)<< getValAsStringC3 (x);}
                if (varType ==mac_int32  )   if(*Vars.Ptr_int32  [i] != Vars.Cached3_int32  [i] ){pushSuperVarWrite(x);}//qDebug() << "argggh" << x<< getValAsString (x)<< getValAsStringC3 (x);}
                if (varType ==mac_float32)   if(*Vars.Ptr_float32[i] != Vars.Cached3_float32[i] ){pushSuperVarWrite(x);}//qDebug() << "argggh" << x<< getValAsString (x)<< getValAsStringC3 (x);}
                if (varType ==mac_float64)   if(*Vars.Ptr_float64[i] != Vars.Cached3_float64[i] ){pushSuperVarWrite(x);}//qDebug() << "argggh" << x<< getValAsString (x)<< getValAsStringC3 (x);}
                if (varType ==mac_QString)   if(*Vars.Ptr_QString[i] != Vars.Cached3_QString[i] ){pushSuperVarWrite(x);}//qDebug() << "argggh" << x<< getValAsString (x)<< getValAsStringC3 (x);}
            }
        }
    releaseOutPacket(criticalPacket);
    }
}



//************************************************************************************************************************
//************************************************************************************************************************
//************************************************************************************************************************
//************************************************************************************************************************
//*********************************************************************
void detectOverflow(int i, int maxIndex, QString messageTxt){
    if(i > (maxIndex-1)){
        QMessageBox msgBox;
        msgBox.setText("Please close this program and contact developer\n\nArray Overflow!\n\nFrom: " +messageTxt + "\n\nmaxIndex=" + QString::number(i));        msgBox.exec();        }
    }
//*********************************************************************
//Set Variable Data
//*********************************************************************
unsigned char      PointHere_uint8Zero      = 0;
unsigned short int PointHere_uint16Zero     = 0;
unsigned int       PointHere_uint32Zero     = 0;
ullint             PointHere_uint64Zero     = 0;
short int          PointHere_int16Zero      = 0;
int                PointHere_int32Zero      = 0;
float              PointHere_float32Zero    = 0;
double             PointHere_float64Zero    = 0;
QString            PointHere_QStringZero("");

//FIXME
//only the first 50 characters are analyzed because that is all that is analyzed on the flightboard
//the size of the strings on the flight board should potentially be increased
void calcParamSetChecksum(QString varName){
   QByteArray Name; Name.append(varName.toLocal8Bit());
   unsigned int varSum = 0;
   int x;
   for (x = 0; x < Name.length(); x++){
       //qDebug() <<Name.at(x) << (int) Name.at(x);
       if (x == 50) break;
       varSum = varSum + (int) Name.at(x);
    }
    paramSetChecksum = paramSetChecksum + x + varSum;
    }

void addSuperVar(unsigned char &globalVariable,
    QString varName, int retainFlags, int pollRate, QString description){
    static int i = -1;if(i == -1) {for(int x=0;x<num_uint8 ;x++)  Vars.Ptr_uint8[x]= &PointHere_uint8Zero;}  //this prevents crash from uninitialized array
    QString errText = "addSuperVar unsigned char";
    i++; largestVarID++; detectOverflow(i,num_uint8,errText);Vars.ID_uint8[i]=largestVarID;
     Vars.Type_uint8[i]         = mac_uint8;
     Vars.Description_uint8[i]  = description;
     Vars.retainFlags_uint8[i]  = retainFlags;
     Vars.Ptr_uint8[i]          = &globalVariable;
     Vars.Name_uint8[i]         = varName;
     Vars.pollRate_uint8[i]     = pollRate;
     Vars.BoardAddress_uint8[i] = nextBoardAddress; nextBoardAddress += 8 / 8;
     calcParamSetChecksum(varName);
    }
void addSuperVar(unsigned short int &globalVariable,
    QString varName, int retainFlags, int pollRate, QString description){
    static int i = -1;if(i == -1) {for(int x=0;x<num_uint16 ;x++)  Vars.Ptr_uint16[x]= &PointHere_uint16Zero;}  //this prevents crash from uninitialized array
    QString errText = "addSuperVar unsigned short int";
    i++; largestVarID++; detectOverflow(i,num_uint16,errText);Vars.ID_uint16[i]=largestVarID;
     Vars.Type_uint16[i]         = mac_uint16;
     Vars.Description_uint16[i]  = description;
     Vars.retainFlags_uint16[i]  = retainFlags;
     Vars.Ptr_uint16[i]          = &globalVariable;
     Vars.Name_uint16[i]         = varName;
     Vars.pollRate_uint16[i]     = pollRate;
     Vars.BoardAddress_uint16[i] = nextBoardAddress; nextBoardAddress += 16/ 8;
     calcParamSetChecksum(varName);
    }
void addSuperVar(unsigned int &globalVariable,
    QString varName, int retainFlags, int pollRate, QString description){
    static int i = -1;if(i == -1) {for(int x=0;x<num_uint32 ;x++)  Vars.Ptr_uint32[x]= &PointHere_uint32Zero;}  //this prevents crash from uninitialized array
    QString errText = "addSuperVar uint";
    i++; largestVarID++; detectOverflow(i,num_uint32,errText);Vars.ID_uint32[i]=largestVarID;
     Vars.Type_uint32[i]         = mac_uint32;
     Vars.Description_uint32[i]  = description;
     Vars.retainFlags_uint32[i]  = retainFlags;
     Vars.Ptr_uint32[i]          = &globalVariable;
     Vars.Name_uint32[i]         = varName;
     Vars.pollRate_uint32[i]     = pollRate;
     Vars.BoardAddress_uint32[i] = nextBoardAddress; nextBoardAddress += 32/ 8;
     calcParamSetChecksum(varName);
    }
void addSuperVar(ullint &globalVariable,
    QString varName, int retainFlags, int pollRate, QString description){
    static int i = -1;if(i == -1) {for(int x=0;x<num_uint64 ;x++)  Vars.Ptr_uint64[x]= &PointHere_uint64Zero;}  //this prevents crash from uninitialized array
    QString errText = "addSuperVar ullint";
    i++; largestVarID++; detectOverflow(i,num_uint64,errText);Vars.ID_uint64[i]=largestVarID;
     Vars.Type_uint64[i]         = mac_uint64;
     Vars.Description_uint64[i]  = description;
     Vars.retainFlags_uint64[i]  = retainFlags;
     Vars.Ptr_uint64[i]          = &globalVariable;
     Vars.Name_uint64[i]         = varName;
     Vars.pollRate_uint64[i]     = pollRate;
     Vars.BoardAddress_uint64[i] = nextBoardAddress; nextBoardAddress += 64/ 8;
     calcParamSetChecksum(varName);
    }
void addSuperVar(short int &globalVariable,
    QString varName, int retainFlags, int pollRate, QString description){
    static int i = -1;if(i == -1) {for(int x=0;x<num_int16 ;x++)  Vars.Ptr_int16[x]= &PointHere_int16Zero;}  //this prevents crash from uninitialized array
    QString errText = "addSuperVar short int";
    i++; largestVarID++; detectOverflow(i,num_int16,errText);Vars.ID_int16[i]=largestVarID;
     Vars.Type_int16[i]          = mac_int16;
     Vars.Description_int16[i]   = description;
     Vars.retainFlags_int16[i]   = retainFlags;
     Vars.Ptr_int16[i]           = &globalVariable;
     Vars.Name_int16[i]          = varName;
     Vars.pollRate_int16[i]      = pollRate;
     Vars.BoardAddress_int16[i]  = nextBoardAddress; nextBoardAddress += 16/ 8;
     calcParamSetChecksum(varName);
    }
void addSuperVar(int &globalVariable,
    QString varName, int retainFlags, int pollRate, QString description){
    static int i = -1;if(i == -1) {for(int x=0;x<num_int32 ;x++)  Vars.Ptr_int32[x]= &PointHere_int32Zero;}  //this prevents crash from uninitialized array
    QString errText = "addSuperVar int";
    i++; largestVarID++; detectOverflow(i,num_int32,errText);Vars.ID_int32[i]=largestVarID;
     Vars.Type_int32[i]         = mac_int32;
     Vars.Description_int32[i]  = description;
     Vars.retainFlags_int32[i]  = retainFlags;
     Vars.Ptr_int32[i]          = &globalVariable;
     Vars.Name_int32[i]         = varName;
     Vars.pollRate_int32[i]     = pollRate;
     Vars.BoardAddress_int32[i] = nextBoardAddress; nextBoardAddress += 32/ 8;
     calcParamSetChecksum(varName);
    }

void addSuperVar(float &globalVariable,
    QString varName, int retainFlags, int pollRate, QString description){
    static int i = -1;if(i == -1) {for(int x=0;x<num_float32 ;x++)  Vars.Ptr_float32[x]= &PointHere_float32Zero;}  //this prevents crash from uninitialized array
    QString errText = "addSuperVar float";
    i++; largestVarID++;    detectOverflow(i,num_float32,errText);
     Vars.ID_float32[i]           = largestVarID;
     Vars.Type_float32[i]         = mac_float32;
     Vars.Description_float32[i]  = description;
     Vars.retainFlags_float32[i]  = retainFlags;
     Vars.Ptr_float32[i]          = &globalVariable;
     Vars.Name_float32[i]         = varName;
     Vars.pollRate_float32[i]     = pollRate;
     Vars.BoardAddress_float32[i] = nextBoardAddress; nextBoardAddress += 32/ 8;
     calcParamSetChecksum(varName);
    }
void addSuperVar(double &globalVariable,
    QString varName, int retainFlags, int pollRate, QString description){
    static int i = -1;if(i == -1) {for(int x=0;x<num_float64 ;x++)  Vars.Ptr_float64[x]= &PointHere_float64Zero;}  //this prevents crash from uninitialized array
    QString errText = "addSuperVar double";
    i++; largestVarID++; detectOverflow(i,num_float64,errText);
     Vars.ID_float64[i]           = largestVarID;
     Vars.Type_float64[i]         = mac_float64;
     Vars.Description_float64[i]  = description;
     Vars.retainFlags_float64[i]  = retainFlags;
     Vars.Ptr_float64[i]          = &globalVariable;
     Vars.Name_float64[i]         = varName;
     Vars.pollRate_float64[i]     = pollRate;
     Vars.BoardAddress_float64[i] = nextBoardAddress; nextBoardAddress += 64/ 8;
     calcParamSetChecksum(varName);
    }
void addSuperVar(QString &globalVariable,
    QString varName, int retainFlags, int pollRate, QString description){
    static int i = -1; if(i == -1) {for(int x=0;x<num_QString ;x++)  Vars.Ptr_QString[x]= &PointHere_QStringZero;}  //this prevents crash from uninitialized array
    QString errText = "addSuperVar QString";
    i++; largestVarID++; detectOverflow(i,num_QString,errText);Vars.ID_QString[i]=largestVarID;
     Vars.Type_QString[i]         = mac_QString;
     Vars.Description_QString[i]  = description;
     Vars.retainFlags_QString[i]  = retainFlags;
     Vars.Ptr_QString[i]          = &globalVariable;
     Vars.Name_QString[i]         = varName;
     Vars.pollRate_QString[i]     = pollRate;
     Vars.BoardAddress_QString[i] = nextBoardAddress; nextBoardAddress += 50;  // the longest represent of ipv6 is 45 characters
     calcParamSetChecksum(varName);
    }

#endif // SUPERVAR1_H
