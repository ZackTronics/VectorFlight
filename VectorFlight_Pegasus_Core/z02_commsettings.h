#ifndef Z02_COMMSETTINGS_H
#define Z02_COMMSETTINGS_H

#include <QMainWindow>

namespace Ui {
class z02_commSettings;
}

class z02_commSettings : public QMainWindow
{
    Q_OBJECT


public:
    explicit z02_commSettings(QWidget *parent = 0);
    ~z02_commSettings();



protected:
    void keyPressEvent(QKeyEvent *event);
    //bool event ( QEvent * event ) ;     //see not in commsettings.cpp
    //void  focusOutEvent ( QFocusEvent * event );
     void  closeEvent( QCloseEvent * event );

private:
    Ui::z02_commSettings *ui;
        QTimer *timer5;



public slots:
        void periodicRefresh();


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    int applySettings();
    void on_comboBox_currentIndexChanged(const QString &arg1);
    void on_comboBox_2_currentIndexChanged(const QString &arg1);
};




#endif // Z02_COMMSETTINGS_H
