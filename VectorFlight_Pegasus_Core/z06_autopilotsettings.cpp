#include "z06_autopilotsettings.h"
#include "ui_z06_autopilotsettings.h"
#include "allFunctions.h"
#include <qtimer.h>

extern float Setpoint_Ceiling_SeaLevel;
extern float Setpoint_Ceiling_DistanceAboveTakeoff;
extern float AutoPilot_descentRate;
extern float AutoPilot_CommLoss_Delay_PositionHold;
extern float AutoPilot_CommLoss_Delay_ReturnHome;
extern float AutoPilot_CommLoss_Delay_Land;
extern float AutoPilot_LowBatt_Percent_KillSystem;
extern int AutoPilot_CommLoss_Delay_PositionHold_Enabled;
extern int AutoPilot_CommLoss_Delay_ReturnHome_Enabled;
extern int AutoPilot_CommLoss_Delay_Land_Enabled;
extern int AutoPilot_LowBatt_Percent_ReturnHome_Enabled;
extern int AutoPilot_LowBatt_Percent_LandNow_Enabled;
extern int AutoPilot_LowBatt_Percent_KillSystem_Enabled;
extern int AutoPilot_LowBatt_Percent_ReturnHome_AutoSetEnabled;


extern float AutoPilot_LowBatt_Percent_ReturnHome;
extern float AutoPilot_LowBatt_Percent_LandNow;
extern float AutoPilot_LowBatt_Percent_TimeDelay;
extern float AutoPilot_ReturnHomeAltitudeAboveTakeoff;
extern float AutoPilot_ReturnHomeAltitudeObjectiveToleranceReqd;
extern float AutoPilot_distanceNeededToStopAircraft;
extern float AutoPilot_MaxTransitSpeed;


z06_AutopilotSettings::z06_AutopilotSettings(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::z06_AutopilotSettings)
{
    ui->setupUi(this);

    ui->lineEdit_15->setText(QString::number(Setpoint_Ceiling_DistanceAboveTakeoff));
    ui->lineEdit_2->setText(QString::number(Setpoint_Ceiling_SeaLevel));
    ui->lineEdit_3->setText(QString::number(- AutoPilot_descentRate));
    ui->lineEdit_4->setText(QString::number(AutoPilot_CommLoss_Delay_PositionHold)       );
    ui->checkBox_1->setChecked             (AutoPilot_CommLoss_Delay_PositionHold_Enabled);
    ui->lineEdit_5->setText(QString::number(AutoPilot_CommLoss_Delay_ReturnHome));
    ui->lineEdit_6->setText(QString::number(AutoPilot_CommLoss_Delay_Land));
    ui->lineEdit_7->setText(QString::number(AutoPilot_LowBatt_Percent_ReturnHome));
    ui->checkBox_4->setChecked             (AutoPilot_LowBatt_Percent_ReturnHome_Enabled);
    ui->checkBox_7->setChecked              (AutoPilot_LowBatt_Percent_ReturnHome_AutoSetEnabled);
    ui->lineEdit_8->setText(QString::number(AutoPilot_LowBatt_Percent_LandNow));
    ui->checkBox_5->setChecked             (AutoPilot_LowBatt_Percent_LandNow_Enabled);
    ui->lineEdit_14->setText(QString::number(AutoPilot_LowBatt_Percent_KillSystem));
    ui->checkBox_6->setChecked              (AutoPilot_LowBatt_Percent_KillSystem_Enabled);
    ui->lineEdit_9->setText(QString::number(AutoPilot_LowBatt_Percent_TimeDelay));
    ui->lineEdit_10->setText(QString::number(AutoPilot_ReturnHomeAltitudeAboveTakeoff));
    ui->lineEdit_11->setText(QString::number(AutoPilot_ReturnHomeAltitudeObjectiveToleranceReqd));
    ui->lineEdit_12->setText(QString::number(AutoPilot_distanceNeededToStopAircraft));
    ui->lineEdit_13->setText(QString::number(100 *AutoPilot_MaxTransitSpeed));

    ui->checkBox_2->setChecked             (AutoPilot_CommLoss_Delay_ReturnHome_Enabled);
    ui->checkBox_3->setChecked             (AutoPilot_CommLoss_Delay_Land_Enabled);









    timer5=new QTimer(this);
    connect(timer5, SIGNAL(timeout()), this, SLOT(periodicRefresh()));
    timer5->start(30);





}

/*
AutoPilot_LowBatt_Percent_ReturnHome_AutoSetEnabled
AutoPilot_LowBatt_Percent_ReturnHome
AutoPilot_LowBatt_Percent_LandNow
AutoPilot_LowBatt_Percent_TimeDelay
AutoPilot_ReturnHomeAltitudeAboveTakeoff
AutoPilot_ReturnHomeAltitudeObjectiveToleranceReqd
AutoPilot_distanceNeededToStopAircraft
AutoPilot_wayPointDistanceTolerance
AutoPilot_MaxTransitSpeed
*/

z06_AutopilotSettings::~z06_AutopilotSettings()
{
    delete ui;
}


//OK
void z06_AutopilotSettings::on_pushButton_3_clicked()
{
    applySettings();
    close();
}


//Cancel
void z06_AutopilotSettings::on_pushButton_2_clicked()
{
    close();
}


//Cancel
void z06_AutopilotSettings::on_pushButton_clicked()
{
    applySettings();
}


//Apply
void z06_AutopilotSettings::applySettings()
    {
    Setpoint_Ceiling_DistanceAboveTakeoff                   = ui->lineEdit_15->text().toFloat();
    Setpoint_Ceiling_SeaLevel                               = ui->lineEdit_2->text().toFloat();
    AutoPilot_descentRate                                   = - ui->lineEdit_3->text().toFloat();
    AutoPilot_CommLoss_Delay_PositionHold                   = ui->lineEdit_4->text().toFloat();
    AutoPilot_CommLoss_Delay_ReturnHome                     = ui->lineEdit_5->text().toFloat();
    AutoPilot_CommLoss_Delay_Land                           = ui->lineEdit_6->text().toFloat();
    AutoPilot_LowBatt_Percent_ReturnHome                    = ui->lineEdit_7->text().toFloat();
    AutoPilot_LowBatt_Percent_LandNow                       = ui->lineEdit_8->text().toFloat();
    AutoPilot_LowBatt_Percent_TimeDelay                     = ui->lineEdit_9->text().toFloat();
    AutoPilot_LowBatt_Percent_KillSystem                    = ui->lineEdit_14->text().toFloat();
    AutoPilot_ReturnHomeAltitudeAboveTakeoff                = ui->lineEdit_10->text().toFloat();
    AutoPilot_ReturnHomeAltitudeObjectiveToleranceReqd      = ui->lineEdit_11->text().toFloat();
    AutoPilot_distanceNeededToStopAircraft           = ui->lineEdit_12->text().toFloat();
    AutoPilot_MaxTransitSpeed                               = ui->lineEdit_13->text().toFloat() / 100.0;

    AutoPilot_CommLoss_Delay_PositionHold_Enabled           = ui->checkBox_1->checkState() && 1;
    AutoPilot_CommLoss_Delay_ReturnHome_Enabled             = ui->checkBox_2->checkState() && 1;
    AutoPilot_CommLoss_Delay_Land_Enabled                   = ui->checkBox_3->checkState() && 1;
    AutoPilot_LowBatt_Percent_ReturnHome_Enabled            = ui->checkBox_4->checkState() && 1;
    AutoPilot_LowBatt_Percent_LandNow_Enabled               = ui->checkBox_5->checkState() && 1;
    AutoPilot_LowBatt_Percent_KillSystem_Enabled            = ui->checkBox_6->checkState() && 1;
    AutoPilot_LowBatt_Percent_ReturnHome_AutoSetEnabled     = ui->checkBox_7->checkState() && 1;
    PleaseXmitChanges();

    }



//*****************
//Periodic Refresh
//*****************
void z06_AutopilotSettings::periodicRefresh(){
    if (ui->checkBox_1->checkState() && 1)   ui->lineEdit_4->setDisabled(0); else   ui->lineEdit_4->setDisabled(1);
    if (ui->checkBox_2->checkState() && 1)   ui->lineEdit_5->setDisabled(0); else   ui->lineEdit_5->setDisabled(1);
    if (ui->checkBox_3->checkState() && 1)   ui->lineEdit_6->setDisabled(0); else   ui->lineEdit_6->setDisabled(1);
    if (ui->checkBox_4->checkState() && 1)   ui->lineEdit_7->setDisabled(0);  else   ui->lineEdit_7->setDisabled(1);
    if (ui->checkBox_5->checkState() && 1)   ui->lineEdit_8->setDisabled(0);  else   ui->lineEdit_8->setDisabled(1);
    if (ui->checkBox_6->checkState() && 1)   ui->lineEdit_14->setDisabled(0); else   ui->lineEdit_14->setDisabled(1);



}
