#ifndef Z05_AIRCRAFTGEOMETRY_H
#define Z05_AIRCRAFTGEOMETRY_H

#include <QMainWindow>

namespace Ui {
class z05_AircraftGeometry;
}

class z05_AircraftGeometry : public QMainWindow
{
    Q_OBJECT

public:
    explicit z05_AircraftGeometry(QWidget *parent = 0);
    ~z05_AircraftGeometry();

protected:
     void  closeEvent( QCloseEvent * event );

public slots:
        void periodicRefreshGeom();

private slots:
        int applySettings();
        //void on_pushButton_clicked();

        void on_checkBox_clicked();

        void on_checkBox_2_clicked();

        void on_checkBox_3_clicked();

        void on_checkBox_4_clicked();

        void on_checkBox_5_clicked();

        void on_checkBox_6_clicked();

        void on_pushButton_2_clicked();

        void on_pushButton_3_clicked();

        void on_pushButton_4_clicked();

        void on_pushButton_5_clicked();

private:
    Ui::z05_AircraftGeometry *ui;
    QTimer *timer20;


};

#endif // Z05_AIRCRAFTGEOMETRY_H
