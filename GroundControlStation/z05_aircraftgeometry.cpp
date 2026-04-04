#include "z05_aircraftgeometry.h"
#include "ui_z05_aircraftgeometry.h"
#include "Globals/globalStructs.h"
#include "allFunctions.h"
//#include "globals.h"
#include <QMessageBox>
#include <qtimer.h>
#include <QDebug>
#include <QWidget>
#include <QKeyEvent>
#include <QUdpSocket>
#include "Globals/globalDefines.h"

extern QString sTargetIPAddress;
extern int aircraftGeometryIsOpen;
extern float angle_motor_[7];
extern unsigned char doesRotateClockwise_motor[7];
extern int connectionStatus;
extern unsigned char numberOfMotors;
extern float motor_ResponseTC;


z05_AircraftGeometry::z05_AircraftGeometry(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::z05_AircraftGeometry)
{
    ui->setupUi(this);

    aircraftGeometryIsOpen = 1;

    timer20=new QTimer(this);
    connect(timer20, SIGNAL(timeout()), this, SLOT(periodicRefreshGeom()));
    timer20->start(30);

    ui->lineEdit->setText(QString::number(angle_motor_[1]));
    ui->checkBox->setChecked(doesRotateClockwise_motor[1]);
    ui->lineEdit_2->setText(QString::number(angle_motor_[2]));
    ui->checkBox_2->setChecked(doesRotateClockwise_motor[2]);
    ui->lineEdit_3->setText(QString::number(angle_motor_[3]));
    ui->checkBox_3->setChecked(doesRotateClockwise_motor[3]);
    ui->lineEdit_4->setText(QString::number(angle_motor_[4]));
    ui->checkBox_4->setChecked(doesRotateClockwise_motor[4]);
    ui->lineEdit_5->setText(QString::number(angle_motor_[5]));
    ui->checkBox_5->setChecked(doesRotateClockwise_motor[5]);
    ui->lineEdit_6->setText(QString::number(angle_motor_[6]));
    ui->checkBox_6->setChecked(doesRotateClockwise_motor[6]);

    ui->lineEdit_7->setText(QString::number(numberOfMotors));
    ui->lineEdit_8->setText(QString::number(motor_ResponseTC));




}

z05_AircraftGeometry::~z05_AircraftGeometry()
{
    delete ui;
}


//*****************
//Periodic Refresh
//*****************
void z05_AircraftGeometry::periodicRefreshGeom(){

int n = ui->lineEdit_7->text().toInt();

if (n < 1) ui->lineEdit->setDisabled(1);
if (n < 2) ui->lineEdit_2->setDisabled(1);
if (n < 3) ui->lineEdit_3->setDisabled(1);
if (n < 4) ui->lineEdit_4->setDisabled(1);
if (n < 5) ui->lineEdit_5->setDisabled(1);
if (n < 6) ui->lineEdit_6->setDisabled(1);

if (n >= 1) ui->lineEdit->setDisabled(0);
if (n >= 2) ui->lineEdit_2->setDisabled(0);
if (n >= 3) ui->lineEdit_3->setDisabled(0);
if (n >= 4) ui->lineEdit_4->setDisabled(0);
if (n >= 5) ui->lineEdit_5->setDisabled(0);
if (n >= 6) ui->lineEdit_6->setDisabled(0);



  //  static int x;
  //  x++;
  //  qDebug() << x;


}

void  z05_AircraftGeometry::closeEvent(QCloseEvent *event){
    UNUSED(*event);
    aircraftGeometryIsOpen = 0;
}




//*********************************************************
//This function contains everything that happens when you click Apply Settings
//This function is used by the Apply and OK button.
//*********************************************************
int z05_AircraftGeometry::applySettings()
    {
    int GeomSettingsWereApplied = 0;
    int msgboxResult;
    QMessageBox msgBox;
    msgBox.setText("Are you sure you want to apply?\n\n");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgboxResult = msgBox.exec();

        if ((msgboxResult == (QMessageBox::Ok))){
            angle_motor_[1] = ui->lineEdit->text().toFloat();
            angle_motor_[2] = ui->lineEdit_2->text().toFloat();
            angle_motor_[3] = ui->lineEdit_3->text().toFloat();
            angle_motor_[4] = ui->lineEdit_4->text().toFloat();
            angle_motor_[5] = ui->lineEdit_5->text().toFloat();
            angle_motor_[6] = ui->lineEdit_6->text().toFloat();
            doesRotateClockwise_motor[1] = ui->checkBox->checkState() && 1;
            doesRotateClockwise_motor[2] = ui->checkBox_2->checkState() && 1;
            doesRotateClockwise_motor[3] = ui->checkBox_3->checkState() && 1;
            doesRotateClockwise_motor[4] = ui->checkBox_4->checkState() && 1;
            doesRotateClockwise_motor[5] = ui->checkBox_5->checkState() && 1;
            doesRotateClockwise_motor[6] = ui->checkBox_6->checkState() && 1;

            numberOfMotors          = ui->lineEdit_7->text().toInt();
            motor_ResponseTC            = ui->lineEdit_8->text().toFloat();


            PleaseXmitChanges();

            GeomSettingsWereApplied = 1;
        }
        return  GeomSettingsWereApplied;
    }

//*****************
//Cancel Button
//*****************
void z05_AircraftGeometry::on_pushButton_2_clicked()
    {
    qDebug() << "Close";
    close();
    }

//*****************
//OK Button
//*****************
void z05_AircraftGeometry::on_pushButton_3_clicked()
    {
    qDebug() << "OK";
    int GeomSettingsWereApplied = applySettings();
    if (GeomSettingsWereApplied) close();
    }




void z05_AircraftGeometry::on_checkBox_clicked(){}
void z05_AircraftGeometry::on_checkBox_2_clicked(){}
void z05_AircraftGeometry::on_checkBox_3_clicked(){}
void z05_AircraftGeometry::on_checkBox_4_clicked(){}
void z05_AircraftGeometry::on_checkBox_5_clicked(){}
void z05_AircraftGeometry::on_checkBox_6_clicked(){}


void z05_AircraftGeometry::on_pushButton_4_clicked()
{
    ui->lineEdit->setText(QString::number(30.0));
    ui->checkBox->setChecked(1);
    ui->lineEdit_2->setText(QString::number(90.0));
    ui->checkBox_2->setChecked(0);
    ui->lineEdit_3->setText(QString::number(150.0));
    ui->checkBox_3->setChecked(1);
    ui->lineEdit_4->setText(QString::number(210.0));
    ui->checkBox_4->setChecked(0);
    ui->lineEdit_5->setText(QString::number(270.0));
    ui->checkBox_5->setChecked(1);
    ui->lineEdit_6->setText(QString::number(330.0));
    ui->checkBox_6->setChecked(0);

    ui->lineEdit_7->setText(QString::number(6));

}

void z05_AircraftGeometry::on_pushButton_5_clicked()
{
    ui->lineEdit->setText(QString::number(45.0));
    ui->checkBox->setChecked(1);
    ui->lineEdit_2->setText(QString::number(135.0));
    ui->checkBox_2->setChecked(0);
    ui->lineEdit_3->setText(QString::number(225.0));
    ui->checkBox_3->setChecked(1);
    ui->lineEdit_4->setText(QString::number(315.0));
    ui->checkBox_4->setChecked(0);
    ui->lineEdit_5->setText(QString::number(0));
    ui->checkBox_5->setChecked(0);
    ui->lineEdit_6->setText(QString::number(0));
    ui->checkBox_6->setChecked(0);

    ui->lineEdit_7->setText(QString::number(4));
}
