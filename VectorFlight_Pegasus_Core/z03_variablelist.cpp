#include "z03_variablelist.h"
#include "ui_z03_variablelist.h"
#include <qtimer.h>
#include <QDebug>
#include <QLineEdit>
#include <QString>
#include "Globals/globalDefines.h"
#include "Globals/globalStructs.h"
#include <QKeyEvent>
#include <QWheelEvent>
#include "allFunctions.h"

extern Struct_superGlobalVars Vars;   //One Instance
extern                  QString sTargetIPAddress;
extern                  QString sConnectionState;
extern int              connectionStatus;
extern int              iControllerPacketInterval;
extern int              controllerConnected;
extern int              enumIPAddressingMode;
extern int              commSettingsIsOpen;
extern int              varListIsOpen;
extern int              listToView;
extern int              ListofMotionVarsMaxIndex;
extern int              varList[numberOfLists][maxListIndex];
extern int              VarList_MaxIndex[numberOfLists];
extern int              maxVarId;
extern int              HelicopterMode;
extern int              RowID[18];

extern varIDtype        largestVarID;
extern int         varList[numberOfLists][maxListIndex];
int                     lineChanged[18];
int                     lastScrollValue[numberOfLists];
int                     NoEdits_InProgress;
void                    makeListofMotionVars();
void                    makeListofCraftStatus();
void                    releaseOutPacket(int isCrucial);

void detectOverflow(int i, int maxIndex, QString messageTxt);

z03_variableList::z03_variableList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::z03_variableList){
    varListIsOpen = 1;
    ui->setupUi(this);
    if (listToView== listOf_MotionVars){
        makeListofMotionVars();
        setWindowTitle(tr("Motion Characteristics"));
        }
    if (listToView== listOf_CraftStatus){
        makeListofCraftStatus();
        setWindowTitle(tr("Aircraft Status"));
        }

    lineNum[0][1] =  ui->lineEdit_3001;  labels[1][1]  = ui->label_1001;  labels[2][1]  = ui->label_2001;  labels[3][1]  = ui->label_5001;  labels[4][1]  = ui->label_8001;
    lineNum[0][2] =  ui->lineEdit_3002;  labels[1][2]  = ui->label_1002;  labels[2][2]  = ui->label_2002;  labels[3][2]  = ui->label_5002;  labels[4][2]  = ui->label_8002;
    lineNum[0][3] =  ui->lineEdit_3003;  labels[1][3]  = ui->label_1003;  labels[2][3]  = ui->label_2003;  labels[3][3]  = ui->label_5003;  labels[4][3]  = ui->label_8003;
    lineNum[0][4] =  ui->lineEdit_3004;  labels[1][4]  = ui->label_1004;  labels[2][4]  = ui->label_2004;  labels[3][4]  = ui->label_5004;  labels[4][4]  = ui->label_8004;
    lineNum[0][5] =  ui->lineEdit_3005;  labels[1][5]  = ui->label_1005;  labels[2][5]  = ui->label_2005;  labels[3][5]  = ui->label_5005;  labels[4][5]  = ui->label_8005;
    lineNum[0][6] =  ui->lineEdit_3006;  labels[1][6]  = ui->label_1006;  labels[2][6]  = ui->label_2006;  labels[3][6]  = ui->label_5006;  labels[4][6]  = ui->label_8006;
    lineNum[0][7] =  ui->lineEdit_3007;  labels[1][7]  = ui->label_1007;  labels[2][7]  = ui->label_2007;  labels[3][7]  = ui->label_5007;  labels[4][7]  = ui->label_8007;
    lineNum[0][8] =  ui->lineEdit_3008;  labels[1][8]  = ui->label_1008;  labels[2][8]  = ui->label_2008;  labels[3][8]  = ui->label_5008;  labels[4][8]  = ui->label_8008;
    lineNum[0][9] =  ui->lineEdit_3009;  labels[1][9]  = ui->label_1009;  labels[2][9]  = ui->label_2009;  labels[3][9]  = ui->label_5009;  labels[4][9]  = ui->label_8009;
    lineNum[0][10] = ui->lineEdit_3010;  labels[1][10] = ui->label_1010;  labels[2][10] = ui->label_2010;  labels[3][10] = ui->label_5010;  labels[4][10] = ui->label_8010;
    lineNum[0][11] = ui->lineEdit_3011;  labels[1][11] = ui->label_1011;  labels[2][11] = ui->label_2011;  labels[3][11] = ui->label_5011;  labels[4][11] = ui->label_8011;
    lineNum[0][12] = ui->lineEdit_3012;  labels[1][12] = ui->label_1012;  labels[2][12] = ui->label_2012;  labels[3][12] = ui->label_5012;  labels[4][12] = ui->label_8012;
    lineNum[0][13] = ui->lineEdit_3013;  labels[1][13] = ui->label_1013;  labels[2][13] = ui->label_2013;  labels[3][13] = ui->label_5013;  labels[4][13] = ui->label_8013;
    lineNum[0][14] = ui->lineEdit_3014;  labels[1][14] = ui->label_1014;  labels[2][14] = ui->label_2014;  labels[3][14] = ui->label_5014;  labels[4][14] = ui->label_8014;
    lineNum[0][15] = ui->lineEdit_3015;  labels[1][15] = ui->label_1015;  labels[2][15] = ui->label_2015;  labels[3][15] = ui->label_5015;  labels[4][15] = ui->label_8015;
    lineNum[0][16] = ui->lineEdit_3016;  labels[1][16] = ui->label_1016;  labels[2][16] = ui->label_2016;  labels[3][16] = ui->label_5016;  labels[4][16] = ui->label_8016;
    lineNum[0][17] = ui->lineEdit_3017;  labels[1][17] = ui->label_1017;  labels[2][17] = ui->label_2017;  labels[3][17] = ui->label_5017;  labels[4][17] = ui->label_8017;

    timer6=new QTimer(this);
    connect(timer6, SIGNAL(timeout()), this, SLOT(updateHighlighting()));
    timer6->start(500);
    ui->verticalScrollBar->setValue(lastScrollValue[listToView]);
    scrollBarValue                = lastScrollValue[listToView];
    on_pushButton_3_clicked();
    updateDisplay();
    ui->lineEdit->setFocus();
    }
z03_variableList::~z03_variableList(){
    varListIsOpen = 0;
    delete ui;
    }

//*****************************************************************************************************************
void z03_variableList::updateDisplay(){
    int s = scrollBarValue;
    int i;
    int l = listToView;
    lastScrollValue[l] = s;             //incase you view a different list in interim preserve scroll value
    int max = VarList_MaxIndex[l];

    i = s-1; //Value
    for (int x = 1; x <= 17; x++){
    i++;
    if(i<=max)  {
        if (NoEdits_InProgress){
            lineNum[0][x]->setText(getValAsString(varList[l][i]));
            NoEdits_InProgress = 0;
        }else{
            if (!(lineNum[0][x]->hasFocus())){
            lineNum[0][x]->setText(getValAsString(varList[l][i]));
            }
        }
        lineNum[0][x]->setDisabled(!((getFlags(varList[l][i]) & UserEditable) && 1));
        labels[1][x]->setText(getName(varList[l][i]));
        labels[1][x]->setToolTip(getDescription(varList[l][i]));
        labels[2][x]->setText(revEnumTypes(getType(varList[l][i])));
        labels[3][x]->setText(QString::number(varList[l][i]));
        labels[4][x]->setText(QString::number(getBoardAddress(varList[l][i])));



        RowID[x] = varList[l][i];

    }
    else{
        lineNum[0][x]->setDisabled(1);
        labels[1][x]->setText("");
        labels[1][x]->setToolTip("");
        labels[2][x]->setText("");
        labels[3][x]->setText("");
        labels[4][x]->setText("");
        lineNum[0][x]->setText("");

        }
    }
}


int editInProgress;
//*****************************************************************************************************************
//  Determine if any edits are in progress.  If so, highlight the box and lock the scrollbar.
//*****************************************************************************************************************
void z03_variableList::updateHighlighting(){
    QString h   = "QLineEdit{background: yellow;}";    QString n   = "";
    editInProgress =0;
    for (int x = 1; x <= 17; x++){
        if (lineNum[0][1]->isModified()) {lineNum[0][1]->setStyleSheet(h); editInProgress = 1;}
        else{lineNum[0][1]->setStyleSheet(n);}
    }

    //look for external changes... Refresh the list if there are any.
    QString OLD_Values[18];
    for (int x = 1; x <=17; x++){
        if (OLD_Values[x] != getValAsString(RowID[x])) {
            OLD_Values[x]   = getValAsString(RowID[x]);
            updateDisplay();
            }
        }
    }

//*****************************************************************************************************************
//
//*****************************************************************************************************************
void  senD(int x){  // we use this function because we don't want to send motion charicteristics if not connected.
    if (connectionStatus > 0)   {  //we always push them because we don't re-handshake unless connection = -1
        pushSuperVarWrite(x);
        releaseOutPacket(criticalPacket);}
    }

//transmit parameters if they are edited by the user.
void z03_variableList::on_lineEdit_3001_editingFinished(){if (ui->lineEdit_3001->isModified()){setValue(RowID[ 1], ui->lineEdit_3001->text());if (getFlags(RowID[ 1]) & plsHandshk){senD(RowID[ 1]);}updateDisplay();}}
void z03_variableList::on_lineEdit_3002_editingFinished(){if (ui->lineEdit_3002->isModified()){setValue(RowID[ 2], ui->lineEdit_3002->text());if (getFlags(RowID[ 2]) & plsHandshk){senD(RowID[ 2]);}updateDisplay();}}
void z03_variableList::on_lineEdit_3003_editingFinished(){if (ui->lineEdit_3003->isModified()){setValue(RowID[ 3], ui->lineEdit_3003->text());if (getFlags(RowID[ 3]) & plsHandshk){senD(RowID[ 3]);}updateDisplay();}}
void z03_variableList::on_lineEdit_3004_editingFinished(){if (ui->lineEdit_3004->isModified()){setValue(RowID[ 4], ui->lineEdit_3004->text());if (getFlags(RowID[ 4]) & plsHandshk){senD(RowID[ 4]);}updateDisplay();}}
void z03_variableList::on_lineEdit_3005_editingFinished(){if (ui->lineEdit_3005->isModified()){setValue(RowID[ 5], ui->lineEdit_3005->text());if (getFlags(RowID[ 5]) & plsHandshk){senD(RowID[ 5]);}updateDisplay();}}
void z03_variableList::on_lineEdit_3006_editingFinished(){if (ui->lineEdit_3006->isModified()){setValue(RowID[ 6], ui->lineEdit_3006->text());if (getFlags(RowID[ 6]) & plsHandshk){senD(RowID[ 6]);}updateDisplay();}}
void z03_variableList::on_lineEdit_3007_editingFinished(){if (ui->lineEdit_3007->isModified()){setValue(RowID[ 7], ui->lineEdit_3007->text());if (getFlags(RowID[ 7]) & plsHandshk){senD(RowID[ 7]);}updateDisplay();}}
void z03_variableList::on_lineEdit_3008_editingFinished(){if (ui->lineEdit_3008->isModified()){setValue(RowID[ 8], ui->lineEdit_3008->text());if (getFlags(RowID[ 8]) & plsHandshk){senD(RowID[ 8]);}updateDisplay();}}
void z03_variableList::on_lineEdit_3009_editingFinished(){if (ui->lineEdit_3009->isModified()){setValue(RowID[ 9], ui->lineEdit_3009->text());if (getFlags(RowID[ 9]) & plsHandshk){senD(RowID[ 9]);}updateDisplay();}}
void z03_variableList::on_lineEdit_3010_editingFinished(){if (ui->lineEdit_3010->isModified()){setValue(RowID[10], ui->lineEdit_3010->text());if (getFlags(RowID[10]) & plsHandshk){senD(RowID[10]);}updateDisplay();}}
void z03_variableList::on_lineEdit_3011_editingFinished(){if (ui->lineEdit_3011->isModified()){setValue(RowID[11], ui->lineEdit_3011->text());if (getFlags(RowID[11]) & plsHandshk){senD(RowID[11]);}updateDisplay();}}
void z03_variableList::on_lineEdit_3012_editingFinished(){if (ui->lineEdit_3012->isModified()){setValue(RowID[12], ui->lineEdit_3012->text());if (getFlags(RowID[12]) & plsHandshk){senD(RowID[12]);}updateDisplay();}}
void z03_variableList::on_lineEdit_3013_editingFinished(){if (ui->lineEdit_3013->isModified()){setValue(RowID[13], ui->lineEdit_3013->text());if (getFlags(RowID[13]) & plsHandshk){senD(RowID[13]);}updateDisplay();}}
void z03_variableList::on_lineEdit_3014_editingFinished(){if (ui->lineEdit_3014->isModified()){setValue(RowID[14], ui->lineEdit_3014->text());if (getFlags(RowID[14]) & plsHandshk){senD(RowID[14]);}updateDisplay();}}
void z03_variableList::on_lineEdit_3015_editingFinished(){if (ui->lineEdit_3015->isModified()){setValue(RowID[15], ui->lineEdit_3015->text());if (getFlags(RowID[15]) & plsHandshk){senD(RowID[15]);}updateDisplay();}}
void z03_variableList::on_lineEdit_3016_editingFinished(){if (ui->lineEdit_3016->isModified()){setValue(RowID[16], ui->lineEdit_3016->text());if (getFlags(RowID[16]) & plsHandshk){senD(RowID[16]);}updateDisplay();}}
void z03_variableList::on_lineEdit_3017_editingFinished(){if (ui->lineEdit_3017->isModified()){setValue(RowID[17], ui->lineEdit_3017->text());if (getFlags(RowID[17]) & plsHandshk){senD(RowID[17]);}updateDisplay();}}

//*****************************************************************************************************************

void z03_variableList::on_verticalScrollBar_valueChanged(int value){
    static int oldScrollValue;
    if (!editInProgress){
        scrollBarValue = value;
        NoEdits_InProgress = 1;
        updateDisplay();
        }
    else{ui->verticalScrollBar->setValue(oldScrollValue);}
    oldScrollValue = value;
    }

//*****************************************************************************************************************
void z03_variableList::keyPressEvent(QKeyEvent *event){
    int inkey = event->key();
        if (inkey==16777216){  //esc
        updateDisplay();
        }
        if (inkey == 16777220 ){ //enter
            if (ui->lineEdit->hasFocus()) on_pushButton_2_clicked();
        }
    }

//*****************************************************************************************************************
void z03_variableList::wheelEvent(QWheelEvent* event)
    {
    float thumbwheelMovement = (event->angleDelta()).y() / (float) 120;
    if (thumbwheelMovement > 0) ui->verticalScrollBar->setValue(scrollBarValue -1);
    if (thumbwheelMovement < 0) ui->verticalScrollBar->setValue(scrollBarValue +1);
    }

//*****************************************************************************************************************
//Refresh Button
void z03_variableList::on_pushButton_clicked(){
    NoEdits_InProgress = 1;
    updateDisplay();
    }

//Search
void z03_variableList::on_pushButton_2_clicked(){
        int l=listOf_CraftStatus;int i=-1;QString errText="listOf_Craft overflow";
        for (int x = 1; x <= maxListIndex; x++){
        varList[l][x] = 0;
        }
    int x;
    QString testVar;
    //QString testString[25] ;
    int isMatch;
    QRegExp rx("(\\ |\\,|\\.|\\:|\\t)"); //RegEx for ' ' or ',' or '.' or ':' or '\t'
    QString Query = ui->lineEdit->text().toUpper();
    Query.replace(" ","");
    QStringList query = Query.split(rx);
    int numberOfResults = 0;
    for (x = 1; x <= largestVarID; x++){
        testVar = getName(x).toUpper();
        isMatch = 0;
        for (int j = 0; j < query.size(); ++j){
            if (testVar.contains(query.at(j))) isMatch = 1;
            }
        if (isMatch){
            numberOfResults++;
            i++; detectOverflow(i, maxListIndex, errText) ;varList[l][i] = x;
            }
        }
    VarList_MaxIndex[l] = x;
    ui->verticalScrollBar->setMinimum(0);
    numberOfResults = numberOfResults - 17;
    if (numberOfResults < 0) numberOfResults = 0;
    ui->verticalScrollBar->setMaximum(numberOfResults);
    scrollBarValue = 0;
    }

//Clear Search
void z03_variableList::on_pushButton_3_clicked(){
    ui->lineEdit->setText("");
    on_pushButton_2_clicked();
}

void z03_variableList::on_pushButton_4_clicked(){
        close();
}
