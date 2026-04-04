#include "z04_commstatistics.h"
#include "ui_z04_commstatistics.h"
#include <qtimer.h>
#include <QNetworkInterface>
#include <QMessageBox>
#include "Globals/globalDefines.h"
#include "allFunctions.h"

//these variables are named in globals.h
extern int                  commStatisticsIsOpen;
extern unsigned long int    uliPacketsSent;
extern unsigned long int    uliPacketsReceived;
extern unsigned long int    uliBytesSent;
extern unsigned long int    uliBytesReceived;
extern unsigned long int    RxPacketErrorCounter_CRC;
extern unsigned long int    RxPacketErrorCounter_BadLength;
extern unsigned long int    RxPacketErrorCounter_Stub;
extern unsigned int         unackedPacketCount;
extern unsigned int         lastAckRTT;
extern float                averageRTT;
extern int                  expectedPingForThisNetwork;
extern unsigned int         packetWindow;
extern  QString             sTargetIPAddress;
extern int                  numberOfUnackedCrucialPackets;
extern float                DataRate_Recieved;
extern float                DataRate_Sent;
extern ullint               commsStatisticsRefreshCounter;








void        releaseOutPacket     (QHostAddress   qhaAddress, int isCrucial);
void        pushSuperVarRead        (varIDtype varID);

z04_commStatistics::z04_commStatistics(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::z04_commStatistics)
{
    ui->setupUi(this);
    setWindowTitle(tr("Communications Statistics"));


    timer8=new QTimer(this);
    connect(timer8, SIGNAL(timeout()), this, SLOT(periodicRefresh()));
    timer8->start(30);
    commsStatisticsRefreshCounter = 0;
    commStatisticsIsOpen = 1;
}

z04_commStatistics::~z04_commStatistics()
{
    delete ui;
}


void  z04_commStatistics::closeEvent(QCloseEvent *event){
    QCloseEvent *x;
    x = event;
    event = x;
    commStatisticsIsOpen = 0;
}



//*****************
//Periodic Refresh
//*****************
void z04_commStatistics::periodicRefresh(){
ui->lineEdit->setText(QString::number(uliPacketsSent));
ui->lineEdit->setDisabled(1);

ui->lineEdit_2->setText(QString::number(uliPacketsReceived));
ui->lineEdit_2->setDisabled(1);


ui->lineEdit_7->setText(QString::number(uliBytesSent));
ui->lineEdit_7->setDisabled(1);

ui->lineEdit_8->setText(QString::number(uliBytesReceived));
ui->lineEdit_8->setDisabled(1);

ui->lineEdit_9->setText(QString::number(unackedPacketCount));
ui->lineEdit_9->setDisabled(1);


ui->lineEdit_10->setText(QString::number(lastAckRTT) + + " (last)");
ui->lineEdit_10->setDisabled(1);

ui->lineEdit_11->setText(QString::number(averageRTT,'f', 0) + " (avg)");
ui->lineEdit_11->setDisabled(1);

ui->lineEdit_12->setText(QString::number(packetWindow));
ui->lineEdit_12->setDisabled(1);

ui->lineEdit_13->setText(QString::number(numberOfUnackedCrucialPackets));
ui->lineEdit_13->setDisabled(1);

ui->lineEdit_14->setText(QString::number(expectedPingForThisNetwork));
ui->lineEdit_14->setDisabled(1);

ui->lineEdit_15->setText(QString::number(DataRate_Sent/1000));
ui->lineEdit_15->setDisabled(1);

ui->lineEdit_16->setText(QString::number(DataRate_Recieved/1000));
ui->lineEdit_16->setDisabled(1);

//ui->checkBox->setChecked(IPV6AddressesAlso);
//ui->checkBox_2->setChecked(LinkLocalToo);

int IPV6AddressesAlso   = ui->checkBox->checkState();
int LinkLocalToo        = ui->checkBox_2->checkState();


commsStatisticsRefreshCounter++;

QString addressList;
static QString addressList_OLD;
foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
    if ((address.protocol() == QAbstractSocket::IPv4Protocol || IPV6AddressesAlso) && address != QHostAddress(QHostAddress::LocalHost))
        if (LinkLocalToo || ((address.toString().left(3) != "169") && (address.toString().left(4) != "fe80"))){
        addressList.append(address.toString() + "\n");}
    }
if ((addressList != addressList_OLD) || commsStatisticsRefreshCounter == 5) {
    ui->textEdit->setText(addressList);
    }
addressList_OLD = addressList;
//ui->textEdit->setDisabled(1);
ui->textEdit->setReadOnly(1);
}





//Close Button
void z04_commStatistics::on_pushButton_clicked()
    {
    close();
    }

//Recapture Baseline
void z04_commStatistics::on_pushButton_2_clicked()
    {
    expectedPingForThisNetwork = averageRTT +1;
    pushSuperVarWrite(getVarID("expectedPingForThisNetwork"));
    releaseOutPacket(criticalPacket);
    QMessageBox msgBox;
    msgBox.setText("Expected Ping for this network = " + QString::number(expectedPingForThisNetwork));
    msgBox.exec();
    }
