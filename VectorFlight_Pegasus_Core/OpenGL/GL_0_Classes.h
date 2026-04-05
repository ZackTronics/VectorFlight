#ifndef GL_0_CLASSES_H
#define GL_0_CLASSES_H
/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include <QGLWidget>
#include <QWidget>
#include <QColor>
#include <QGLWidget>
#include <QMatrix4x4>
#include <QVector3D>
#include <qmath.h>
#include <QLineEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "../Globals/objman.h"

//Note  this file is included twice somehow.  I don't know how but don't put functions here.

class heli_QObject;
class QSlider;
class Heli_GLWidget;
class Patch;
struct Geometry;

class HelContWnd : public QWidget   {
    Q_OBJECT
public:




    QGroupBox *horizontalGroupBox3;      //position and orienttation
    QLabel  *label1;
    QLabel  *label2;
    QLabel  *label3;
    QLabel  *label4;
    QLabel  *label5;
    QLabel  *label6;

    QGroupBox *horizontalGroupBox1;
    QSlider *xSlider;
    QSlider *ySlider;
    QSlider *zSlider;
    QSlider *aSlider;
    QSlider *bSlider;
    QSlider *cSlider;

    QGroupBox *horizontalGroupBox2;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit3;
    QLineEdit *lineEdit4;
    QLineEdit *lineEdit5;
    QLineEdit *lineEdit6;


    QGroupBox *horizontalGroupBox4;
    QPushButton *isAnimating;
    QPushButton *resetSimulation;


    QGroupBox *horizontalGroupBox5;
    QLabel  *label10;
    QLabel  *label20;
    QLabel  *label30;
    QLabel  *label40;
    QLabel  *label50;
    QLabel  *label60;

    QGroupBox *horizontalGroupBox6;
    QLineEdit *lineEdit10;
    QLineEdit *lineEdit20;
    QLineEdit *lineEdit30;
    QLineEdit *lineEdit40;
    QLineEdit *lineEdit50;
    QLineEdit *lineEdit60;



    QSlider *createSlider();
    Heli_GLWidget *heli_GLWidget;
    QVBoxLayout *mainLayout;
        HelContWnd();




private:

public slots:
        void setAnimText();

    void getSliderPosition_x(int x);
    void getSliderPosition_y(int x);
    void getSliderPosition_z(int x);
    void getSliderPosition_a(int x);
    void getSliderPosition_b(int x);
    void getSliderPosition_c(int x);

    void textChangedA(QString t);
    void textChangedB(QString t);
    void textChangedC(QString t);
    void textChangedD(QString t);
    void textChangedE(QString t);
    void textChangedF(QString t);

    void animatePressed();
    void resetPressed();


};





/*
void Window::getSliderPosition_x(int x){simuHeli.yawHeading             = (x/16);
   lineEdit1->setText(QString::number(simuHeli.yawHeading));}
*/


class Heli_GLWidget : public QGLWidget   {
    Q_OBJECT
public:
    Heli_GLWidget(QWidget *parent = 0);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    heli_QObject *heli;
    float xRot;
    float yRot;
    float zRot;
    float aRot;
    float bRot;
    float cRot;
    QPoint lastPos;
    QColor qtGreen;
    QColor qtPurple;
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    void keyPressEvent(QKeyEvent *event);

private:
    ObjMan  *objTreeLeaf;
    ObjMan  *objTrunkLeaf;
    ObjMan  *objGround;
    ObjMan  *objSky;
    ObjMan  *objGrass;
    ObjMan  *objGrass2;

    ObjMan  *objHexcopter;

    QVector3D   envPos;
    QVector3D   hctPos;
};

class heli_QObject : public QObject   {
public:
    explicit heli_QObject(QObject *parent, int d = 64, qreal s = 1.0);
    ~heli_QObject();
    void setColor(QColor c);
    void draw() const;
private:
    void buildGeometry(int d, qreal s);
    QList<Patch *> parts;
    Geometry *geom;
};


struct Geometry {
    QVector<GLushort> faces;
    QVector<QVector3D> vertices;
    QVector<QVector3D> normals;
    void appendSmooth(const QVector3D &a, const QVector3D &n, int from);
    void appendFaceted(const QVector3D &a, const QVector3D &n);
    void finalize();
    void loadArrays() const;
};


class Patch {
public:
    enum Smoothing { Faceted, Smooth };
    Patch(Geometry *);
    void setSmoothing(Smoothing s) { sm = s; }
    void translate(const QVector3D &t);
    void rotate(qreal deg, QVector3D axis);
    void draw() const;
    void addTri(const QVector3D &a, const QVector3D &b, const QVector3D &c, const QVector3D &n);
    void addQuad(const QVector3D &a, const QVector3D &b,  const QVector3D &c, const QVector3D &d);
    GLushort start;
    GLushort count;
    GLushort initv;
    GLfloat faceColor[4];
    QMatrix4x4 mat;
    Smoothing sm;
    Geometry *geom;
};


class Rectoid   {
public:
    void translate(const QVector3D &t)
    {
        for (int i = 0; i < parts.count(); ++i)
            parts[i]->translate(t);
    }

    void rotate(qreal deg, QVector3D axis)
    {
        for (int i = 0; i < parts.count(); ++i)
            parts[i]->rotate(deg, axis);
    }

    // No special Rectoid destructor - the parts are fetched out of this member
    // variable, and destroyed by the new owner
    QList<Patch *> parts;
};


class RectTorus : public Rectoid    {
public:
    RectTorus(Geometry *g, qreal iRad, qreal oRad, qreal depth, int numSectors);
    };
class RectPrism : public Rectoid    {
public:
    RectPrism(Geometry *g, qreal width, qreal height, qreal depth);
    };
class Rod : public Rectoid    {
public:
    Rod(Geometry *g, qreal oRad, qreal depth, int numSectors);
    };
#endif // GL_0_CLASSES_H
