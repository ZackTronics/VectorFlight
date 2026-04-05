#ifndef Z06_AUTOPILOTSETTINGS_H
#define Z06_AUTOPILOTSETTINGS_H

#include <QMainWindow>

namespace Ui {
class z06_AutopilotSettings;
}

class z06_AutopilotSettings : public QMainWindow
{
    Q_OBJECT

public:
    explicit z06_AutopilotSettings(QWidget *parent = 0);
    ~z06_AutopilotSettings();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
    void applySettings();

private:
    Ui::z06_AutopilotSettings *ui;
            QTimer *timer5;

public slots:
        void periodicRefresh();

};

#endif // Z06_AUTOPILOTSETTINGS_H
