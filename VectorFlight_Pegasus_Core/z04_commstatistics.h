#ifndef Z04_COMMSTATISTICS_H
#define Z04_COMMSTATISTICS_H

#include <QMainWindow>

namespace Ui {
class z04_commStatistics;
}

class z04_commStatistics : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit z04_commStatistics(QWidget *parent = 0);
    ~z04_commStatistics();

protected:
     void  closeEvent( QCloseEvent * event );


public slots:
        void periodicRefresh();

private:
    Ui::z04_commStatistics *ui;
      QTimer *timer8;

private slots:
        void on_pushButton_clicked();
        void on_pushButton_2_clicked();
};

#endif // Z04_COMMSTATISTICS_H
