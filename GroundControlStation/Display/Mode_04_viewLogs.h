#ifndef MODE_04_VIEWCOMMSLOG_H
#define MODE_04_VIEWCOMMSLOG_H

#include <QByteArray>
#include <QColor>
#include "Functions/drawText.h"
#include <QPainter>
#include "Globals/globalDefines.h"
#include "Globals/globalStructs.h"


#include <QDateTime>






//************************************************
//This is needed by pleaseLogEvent
void pleaseAppendToFile(QByteArray &Message, QByteArray qbarrFileName)
    {
    //Make Directory if not already exist.
    if (!QDir("ProgramData").exists())  {
       QDir().mkpath("ProgramData");
       }
    //Open file for writing
    QFile file("./ProgramData/" + qbarrFileName);
    if (!file.open(QIODevice::Append | QIODevice::Text))
        qDebug() << "Error opening ./ProgramData/" << qbarrFileName <<" for output.";
    QTextStream out(&file);
    //qDebug() <<
    out <<  QDateTime::currentDateTime().toString() << "\t" << Message << "\n";
    file.close();
    }




//***********************************************************
//This function is used throught this program to request events be logged.
void pleaseLogEvent(QColor lineColor, QByteArray nextLine, int whichLog){    //z01_mainWindow.h
    if (glbLogWriteToFile[whichLog])  {
        QByteArray fileName;
        if (whichLog==defCommsLog)              fileName.append("commsLog.txt");
        if (whichLog==defEventLog)              fileName.append("eventLog.txt");
        if (whichLog==defInterval1VarsLogNum)   fileName.append("Interval1Vars.csv");
        if (whichLog==defInterval2VarsLogNum)   fileName.append("Interval2Vars.csv");
        if (whichLog==defLogAllVars)            fileName.append("PolledVariables.csv");
        pleaseAppendToFile(nextLine, fileName);
        }
    if (glbLogCanScroll[whichLog])
        {
        //qDebug() << LogDisplayBuffer[whichLog].glbNextLineToWrite << nextLine;
        LogDisplayBuffer[whichLog].rowText[LogDisplayBuffer[whichLog].glbNextLineToWrite] = nextLine;
        LogDisplayBuffer[whichLog].rowColor[LogDisplayBuffer[whichLog].glbNextLineToWrite] = lineColor;
        LogDisplayBuffer[whichLog].glbNextLineToWrite++;
        if (LogDisplayBuffer[whichLog].glbNextLineToWrite == rowBufferSize) LogDisplayBuffer[whichLog].glbNextLineToWrite = 0;
        LogDisplayBuffer[whichLog].glbNumberOfEntriesInCommsLog++;
        }
    }




//***************************************************************
//***MainWindow::viewCommsLog()
//***************************************************************
void MainWindow::viewLogs(int whichLog){
    //paint background grey
    QPainter p;
    p.begin(&backgroundImage);
    p.setBrush(Qt::lightGray);
    p.drawRect(0,0,gWindowWidth,gWindowHeight);
    p.end();
    //Determine # of rows that can be displayed
    float  lineSpacing  =   17      * zoomLevel;
    float  textSize     =   11.5    * zoomLevel;

    int rowsAvailableOnScreen = ((gWindowHeight-30) / lineSpacing);
    if (rowsAvailableOnScreen < 0) rowsAvailableOnScreen = 0;
    //Determine first index to print
    int arrayIndexToPrint = LogDisplayBuffer[whichLog].glbNextLineToWrite-1;
    if (arrayIndexToPrint < 0) arrayIndexToPrint = rowBufferSize - 1;
    for (int lineNum = 0; lineNum <= rowsAvailableOnScreen; lineNum++){
        //qDebug() << arrayIndexToPrint << LogDisplayBuffer[whichLog].rowText[arrayIndexToPrint];
        float yPosition;
        if (LogDisplayBuffer[whichLog].glbNumberOfEntriesInCommsLog >= rowsAvailableOnScreen) yPosition = gWindowHeight - (lineSpacing * lineNum)-40;
        if (LogDisplayBuffer[whichLog].glbNumberOfEntriesInCommsLog < rowsAvailableOnScreen) yPosition = gWindowHeight - (lineSpacing * lineNum)-40 - (rowsAvailableOnScreen-LogDisplayBuffer[whichLog].glbNumberOfEntriesInCommsLog)*lineSpacing;
        drawText(backgroundImage, textSize, "Normal", "Courier", Qt::AlignLeft, QPen(LogDisplayBuffer[whichLog].rowColor[arrayIndexToPrint]),
                 10, yPosition,
                 LogDisplayBuffer[whichLog].rowText[arrayIndexToPrint]);
                arrayIndexToPrint--; if (arrayIndexToPrint < 0) arrayIndexToPrint = rowBufferSize - 1;
        }

    QPainter q;
    q.begin(&backgroundImage);
    q.setBrush(Qt::lightGray);
    q.drawRect( gWindowWidth/4,
                 0,
                 gWindowWidth/2,
                 textSize*2);
    q.end();
    QByteArray qbarrLogTitle;
    if (whichLog ==0)        qbarrLogTitle.append("Log (Comms)");
    if (whichLog ==1)        qbarrLogTitle.append("Log (Events)");

    drawText(backgroundImage,textSize,"Bold","Verdana",Qt::AlignCenter,QPen(Qt::black),
           gWindowWidth/2,
           textSize,
           qbarrLogTitle);

    //the buttonPressed Slots are located in UserInput-->Modes_and_Buttons.h
    if (glbLogCanScroll[whichLog] ){
       ui->pushButton_1  ->setText("Scrolling");
       }else{
       ui->pushButton_1  ->setText("Scroll Locked");
       }
   if (glbLogWriteToFile[whichLog]){
       ui->pushButton_2  ->setText("Recording");
       }else{
       ui->pushButton_2  ->setText("Not Recording");
       }
    }

#endif // MODE_04_VIEWCOMMSLOG_H
