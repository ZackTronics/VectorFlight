#ifndef SUPERVAR2_H
#define SUPERVAR2_H

#include "Globals/globalDefines.h"
#include "allFunctions.h"
#include <QDateTime>
//not used but they are cool cause they allow a macro to be expanded into a string literal
#define STR_EXPAND(tok) #tok
#define STR(tok) STR_EXPAND(tok)
//these functions are at the bottom of the file for clarity
int valueInBrackets(QString inputString);
double RVAL(QString inputString);
QString parseItem(QString paramName, QString inputString);
void setVariableData();
void parseVariable(QString &entireVar);
void recurseInto(QString trimmedFile, int tagLevel, QString parentName);

//*********************************************************************
//READ FROM FILE
//*********************************************************************
int readRetainDataFromFile(QString fileName){
//    pauseAllTransmission = 1;
    QString entireFile;
    QString trimmedFile;    //whitespace removed
    static int runCountThisFunction;
    runCountThisFunction++;
    if (runCountThisFunction == 1) setVariableData();
    //read file
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))              return -1; //no file found
    QTextStream in(&file);
    while (!in.atEnd()) {entireFile.append(in.readLine());}
    //remove whitespace
    int insideString     = 0;
    int insideBrace      = 0;
    int quoteCount       = 0;
    for (int x = 0; x<entireFile.length(); x++){
        QString c = entireFile.mid(x,1);
        if (c == "\""){     quoteCount++;   if (insideString ==0){insideString = 1;} else{insideString = 0;}}
        if (!insideString){
            if (c == "<")        insideBrace = 1;
            if (c == ">")        insideBrace = 0;
            }
         if (!(insideBrace || insideString)) {
            if ((c==" ") || (c=="\t") || (c=="\n")) c.clear();
            }
        trimmedFile.append(c);
        }
    if (quoteCount % 2) {
        QMessageBox msgBox;
        msgBox.setText("Parse Error in stored Variables - Unterminated string in quotation marks.");
        msgBox.exec();}
    recurseInto(trimmedFile, 0, "root");
    //if coms are not paused when param set is loaded all floats load as INFINITY ont he RPI
//    pauseAllTransmission_PleaseCancel = 1;
//    pauseAllTransmission_timeToCancel = QDateTime::currentDateTime().toMSecsSinceEpoch() + 500;
    return 0;
}

//*********************************************************************
// recursively parse tags
//*********************************************************************
void recurseInto(QString trimmedFile, int tagLevel, QString parentName){

QString pleaseNoWarning = parentName;
int     insideString     = 0;
int     insideBrace      = 0;
int     quoteCount       = 0;
int     insideBrace_Old  = 0;
int     tagCount         = 0;
int     insideTag    = 0;
QString tagName;
QString tagContents;
QString tagStack[100000];
for (int x = 0; x<trimmedFile.length(); x++){
    QString c = trimmedFile.mid(x,1);
    if (c == "\""){     quoteCount++;   if (insideString ==0){insideString = 1;} else{insideString = 0;}}
    if (!insideString){
        if (c == "<")        insideBrace = 1;
        if (c == ">")        insideBrace = 0;
        }
    if (insideBrace){
        if (c != "<")   tagStack[tagCount].append(c);
        }
    if (insideTag) tagContents.append(c);
    if (!insideBrace && insideBrace_Old){
        if ((tagStack[tagCount].left(1) != "/") && insideTag ==0) {
            insideTag =1;
            tagName = tagStack[tagCount];
            }
        if (tagStack[tagCount].left(1) == "/") {
            if (tagName == tagStack[tagCount].mid(1)){
                insideTag =0;   tagContents = tagContents.left(tagContents.lastIndexOf("<"));
                if (tagContents.left(1) == "\""){
                    tagContents = tagContents.mid(1);
                    if (tagContents.right(1) == "\""){
                        tagContents = tagContents.left(tagContents.length()-1);
                        }
                    }
                if (tagName.toUpper() == "RETAINEDVARIABLES"){
                    recurseInto(tagContents, tagLevel+1, tagName);
                    }
                if (tagName.toUpper() == "VAR"){
                    parseVariable(tagContents);
                    }
                tagContents.clear();
                }
            }
        tagCount++;
        }
    insideBrace_Old = insideBrace;
    }
}
//************************************************************************
void parseVariable(QString &entireVar){
    QString varName = parseItem("name", entireVar);
    QString Value   = parseItem("value", entireVar);
    if (Value.contains("\"")){                      //eliminate " "
        int stringStart  =   Value.indexOf("\"");
        int stringEnd    =   Value.mid(stringStart+1).indexOf("\"");
        Value = Value.mid(stringStart+1); Value = Value.left(stringEnd);
        }

    varIDtype    x = getVarID(varName);
    if (x){
        setCachedValue1 (x,      Value);
        setValue       (x,      Value);
    }else{
#ifdef TARGET_HARDWARE_PI
//    qDebug() << "The following setting is not understoond and will not be loaded - "  << varName;
#endif
#ifndef TARGET_HARDWARE_PI
    QMessageBox msgBox;
    msgBox.setText("The following setting is not understoond and will not be loaded - " +varName);
    //msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.exec();
#endif
        }
    }
//*********************************************************************
QString parseItem(QString paramName, QString inputString){
    QString sParamValue;
    int valueStart  = 0;
    int valueEnd    = 0;
    int valueLength = 0;
    valueStart          = inputString.indexOf("<"+paramName+">") + paramName.length() +2;               //7=length of Value
    valueEnd            = inputString.indexOf("</"+paramName+">");
    valueLength = valueEnd - valueStart;
    sParamValue = inputString.mid(valueStart, valueLength).trimmed();
    return inputString.mid(valueStart, valueLength); //everything to the right of the first equal sign
    }
//*********************************************************************
//WRITE TO FILE
//*********************************************************************
void writeRetainDataToFile(QString fileName){
     static long int numberOfWrites; //for debugging
    if (!QDir("ProgramData").exists())  QDir().mkpath("ProgramData");    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox msgBox;
        msgBox.setText("Error opening "+ fileName +" for output.");
        msgBox.exec();
        }
    QTextStream out(&file);
    out << "<retainedVariables>\n";
    for (int x = 1; x <= largestVarID; x++){
        //qDebug() << "varID=" << x << " Val=" << getValAsString(x);
        //if (((getFlags(getName(x)) & defIsRetain) && !HelicopterMode) ||
        //    ((getFlags(getName(x)) & isStoredOnChopper) && HelicopterMode)){
        //FIXME
        if (getFlags(getName(x)) & defIsRetain){

            out <<"\t<var>\n"
                    <<"\t\t<name>"  << getName(x)          <<"</name>\n"
                    //<<"\t\t<type>"  << getType(x)          <<"</type>\n"
                    <<"\t\t<value>" << getValAsString(x)   <<"</value>\n"
                <<"\t</var>\n";
            setCachedValue1      (x,      getValAsQByteArray(x));
            }
        }
    out << "</retainedVariables>";
    file.close();
    numberOfWrites++;
}
//*********************************************************************
//*********************************************************************
int valueInBrackets(QString inputString){
    int openBracketPosition = 0;
    int closeBracketPosition = 0;
    QString sNumberInBrackets;
    int arrIndex;
    openBracketPosition   = inputString.indexOf("[");    closeBracketPosition  = inputString.indexOf("]");
    sNumberInBrackets     = inputString.mid(openBracketPosition+1, closeBracketPosition-openBracketPosition-1);
    arrIndex = sNumberInBrackets.toInt();
    return  arrIndex;
    }
//*********************************************************************
//  Look for changes of retain values that must be written
//*********************************************************************
void MainWindow::monitorRetainDataForChangesToSave(){
     static unsigned long int counter;       //this ensures it gets written even if defaults loaded no changes made and program closed.
    counter++;
    int pleaseUpdateFile = 0;
    if (counter == 5) pleaseUpdateFile = 1;

    for (int x = 1; x <= largestVarID; x++){
        //if (((getFlags(getName(x)) & defIsRetain) && !HelicopterMode)||
        //    ((getFlags(getName(x)) & isStoredOnChopper) && HelicopterMode)){if (getCachedValAsQByteArray(x) != getValAsQByteArray(x))   pleaseUpdateFile = 1;
        if (getFlags(getName(x)) & defIsRetain){if (getCachedVal1AsQByteArray(x) != getValAsQByteArray(x))   pleaseUpdateFile = 1;}
        }
    if (pleaseUpdateFile == 1){
        pleaseUpdateFile = 0;
        writeRetainDataToFile(defaultSettingsFileName);
        }
    }

#endif // SUPERVAR2_H
