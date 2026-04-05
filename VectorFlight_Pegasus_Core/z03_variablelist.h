#ifndef Z03_VARIABLELIST_H
#define Z03_VARIABLELIST_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class z03_variableList;
}

class z03_variableList : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit z03_variableList(QWidget *parent = 0);
    QLineEdit               *lineNum[5][18];
    QLabel                  *labels[5][18];
    int                     scrollBarValue;
    ~z03_variableList();
    
private:
    Ui::z03_variableList *ui;
        QTimer *timer6;
        void wheelEvent(QWheelEvent* event);

protected:
    void keyPressEvent(QKeyEvent *event);

public slots:
    void updateDisplay();
    void updateHighlighting();
private slots:
    void on_verticalScrollBar_valueChanged(int value);


    void on_lineEdit_3001_editingFinished();
    void on_lineEdit_3002_editingFinished();
    void on_lineEdit_3003_editingFinished();
    void on_lineEdit_3004_editingFinished();
    void on_lineEdit_3005_editingFinished();
    void on_lineEdit_3006_editingFinished();
    void on_lineEdit_3007_editingFinished();
    void on_lineEdit_3008_editingFinished();
    void on_lineEdit_3009_editingFinished();
    void on_lineEdit_3010_editingFinished();
    void on_lineEdit_3011_editingFinished();
    void on_lineEdit_3012_editingFinished();
    void on_lineEdit_3013_editingFinished();
    void on_lineEdit_3014_editingFinished();
    void on_lineEdit_3015_editingFinished();
    void on_lineEdit_3016_editingFinished();
    void on_lineEdit_3017_editingFinished();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
};

#endif // Z03_VARIABLELIST_H
