#ifndef GL_2_RENDER_H
#define GL_2_RENDER_H

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
#ifdef TARGET_HARDWARE_PI
//
#endif
#ifndef TARGET_HARDWARE_PI
    #include <QtWidgets>
#endif

#include <QtOpenGL>
#include <math.h>

extern QImage backgroundImage;

extern int gWindowWidth;
extern int gWindowHeight;

#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif

Heli_GLWidget::Heli_GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent){
    heli = 0;
    xRot = 0;
    yRot = 0;
    zRot = 0;


}

QSize Heli_GLWidget::minimumSizeHint() const {
    return QSize(50, 50);
}
QSize Heli_GLWidget::sizeHint() const    {
    return QSize(400, 400);
}




void Heli_GLWidget::initializeGL(){
    qglClearColor(QColor::fromRgbF(0.70, 0.70, 1.0, 0.0));

    heli = new heli_QObject(this, 64);
    heli->setColor(QColor::fromRgbF(0.40, 0.40, 0.20, 0.0));

    QDir        myDir("./model");
    QStringList fileList = myDir.entryList();
    if (fileList.size() == 0){
        QMessageBox msgBox;
        msgBox.setText("3d Models not found in folder './model'.  Please get them or the simulator won't work.");
        msgBox.exec();
    }


    objTreeLeaf = new ObjMan("model/treeleaf.obj", "model/treeleaf.png", this);
    //objTreeLeaf = new ObjMan("E:\\model\\treeleaf.obj", "model/treeleaf.png", this);
    objTrunkLeaf = new ObjMan("model/treetrunk.obj", "model/treetrunk.jpg", this);
    objGround = new ObjMan("model/ground.obj", "model/ground.jpg", this);
    objSky = new ObjMan("model/sky.obj", "model/sky.jpg", this);
    objGrass = new ObjMan("model/grass1.obj", "model/grass.png", this);
    objGrass2 = new ObjMan("model/grass2.obj", "model/grass2.png", this);

    objHexcopter = new ObjMan("model/hexcopt2.obj", "model/hexcopt.png", this);

    glEnable(GL_DEPTH_TEST); //this is important it makes it not look really stupid/wierd
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.3f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);




    //static GLfloat lightPosition[4] = { 0.5, 5.0, 0.0, 0 };

    envPos.setX(9);
    envPos.setY(-3);
    envPos.setZ(-231);

    hctPos.setX(0);
    hctPos.setY(-0.5);
    hctPos.setZ(-25);
}

float qNormalizeAngle(float angle){
    while (angle < 0)           angle += 360;
    while (angle > 360)         angle -= 360;
    return angle;
    }
void Heli_GLWidget::paintGL(){
        //backgroundImage = grabFrameBuffer();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    static GLfloat lightPosition[4] = { 0.6, -1.0, 0.0, 0.0 };
    //static GLfloat ambColor[4] = {1.0, 1.0, 1.0, 1.0};
    static GLfloat ambColor[4] = {0.6, 0.6, 0.6, 1.0};
    static GLfloat diffColor[4] = {1.0, 1.0, 1.0, 1.0};
    //static GLfloat blackColor[4] = {0.5, 0.5, 0.5, 1.0};
    static GLfloat specColor[4] = {1.0, 1.0, 1.0, 1.0};

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
        glEnable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT, GL_SPECULAR, diffColor);
    glMaterialf(GL_FRONT, GL_SHININESS, 16.0f);

    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambColor);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffColor);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specColor);

    glEnable(GL_MULTISAMPLE);

    glMatrixMode(GL_MODELVIEW);
    QMatrix4x4 modMat;


    glLoadIdentity();

    //modMat.scale(2, 2, 2);



    float copX = hctPos.x() + aRot / 20;// / 10;
    float copY = hctPos.y() + bRot / 50;// / 10;
    float copZ = hctPos.z() - cRot / 15;// / 10;




    //if ( copZ < -71 )
    //    copZ = -71;


    //SCALE THE POSITION SO THAT IT IS COMPATIBLE WITH MY FLIGHT SIMULATOR
    float XScale = 10;
    float YScale = 7;
    float ZScale = 30;
    copX =  copX * XScale;
    copY = (copY * YScale) + (YScale / 2.0) - 2.0;
    copZ =  copZ * ZScale + ZScale * 27 - 50;


    //qDebug() << copX << copY << copZ;

    modMat.translate(copX, copY, copZ);



/*    if ( cRot < 32 )
        cRot = 32;
    if ( cRot > 210 )
        cRot = 210;

    if ( bRot > 24 )
        bRot = 24;

    if ( aRot < -20 )
        aRot = -20;
    if ( aRot > 20 )
        aRot = 20;


    modMat.translate((float) (aRot /3.5),
                 (float) (bRot /3.5) - 1.0,
                -(float) (cRot /1.0) - 2.0   );
*/


    float Heading = -xRot+180;
    float Incline =  yRot;
    float Azimuth =  -zRot+180;


   float deg = 3.1415926535898 / 180.0;


   //tilt amount and tilt heading should never be negative.... or should they?


    modMat.rotate( qNormalizeAngle(-90.f), 1.f, 0.f, 0.f);
            //This levels the heli as starting pint

    float correctedHeading = Heading;
   // if ((Incline <= 90) || (  Incline >= 270 ) )correctedHeading = Heading; else correctedHeading = Heading -180;

    modMat.rotate(qNormalizeAngle( correctedHeading ) , 0.0, 0.0, 1.0);                          //Yaw for proper Heading


    Azimuth = Azimuth - Heading;
    modMat.rotate(qNormalizeAngle( Incline ) , cos(Azimuth*deg), sin(Azimuth*deg), 0.0);    //Then Roll in direction of proper Azimuth
    modMat.scale(3, 3, 3);
    glMultMatrixf(modMat.data());

    objHexcopter->Draw(true);

    glLoadIdentity();
    modMat.setToIdentity();
    modMat.translate(envPos.x(), envPos.y(), envPos.z());
    glMultMatrixf(modMat.data());
    //glMultMatrixf()

    //Draw Environment
    //objTrunkLeaf->Draw(true);
    //objTreeLeaf->Draw(false);
    objGround->Draw(false);
    objSky->Draw(false);
    objGrass->Draw(false);
    objGrass2->Draw(false);

    return;
/*    glDisable( GL_TEXTURE_2D );
    glLoadIdentity();

    glTranslatef((float) (aRot /3.5),
                 (float) (bRot /3.5) - 1.0,
                -(float) (cRot /1.0) - 2.0   );




    float Heading = -xRot;
    float Incline =  yRot;
    float Azimuth =  -zRot+180;


   float deg = 3.1415926535898 / 180.0;


   //tilt amount and tilt heading should never be negative.... or should they?


    glRotatef(qNormalizeAngle( -90     ) , 1.0, 0.0, 0.0);                              //This levels the heli as starting pint

    float correctedHeading = Heading;
   // if ((Incline <= 90) || (  Incline >= 270 ) )correctedHeading = Heading; else correctedHeading = Heading -180;

    glRotatef(qNormalizeAngle( correctedHeading ) , 0.0, 0.0, 1.0);                          //Yaw for proper Heading


    Azimuth = Azimuth - Heading;
    glRotatef(qNormalizeAngle( Incline ) , cos(Azimuth*deg), sin(Azimuth*deg), 0.0);    //Then Roll in direction of proper Azimuth




    //glRotatef(qNormalizeAngle( Heading ) , 0.0, 0.0, 1.0);                          //fixme compensate for


    glRotatef(qNormalizeAngle( Heading )        ,
              cos((90-Incline)*deg)*cos(Azimuth*deg) ,
              cos((90-Incline)*deg)*sin(Azimuth*deg) ,
              sin((90-Incline)*deg)                  );                          //fixme compensate for





//Yaw Pitch Roll -    Roll and Yaw both Yaw if Pitch is Zero
                        //Pitch becomes roll if yaw is 90

//Pitch Yaw Roll -  Roll becomes Pitch if Yaw is 90

//Pitch Roll Yaw - Pitch and Yaw seem intertwined


    heli->draw();
*/
}

void Heli_GLWidget::keyPressEvent(QKeyEvent *event)
{
    if ( event->key() == Qt::Key_Q )
    {
        envPos.setY(envPos.y() - 1.f);
        hctPos.setY(hctPos.y() - 1.f);
    }
    else if ( event->key() == Qt::Key_E )
    {
        envPos.setY(envPos.y() + 1.f);
        hctPos.setY(hctPos.y() + 1.f);
    }
    else if ( event->key() == Qt::Key_A )
    {
        envPos.setX(envPos.x() + 1.f);
        hctPos.setX(hctPos.x() + 1.f);
    }
    else if ( event->key() == Qt::Key_D )
    {
        envPos.setX(envPos.x() - 1.f);
        hctPos.setX(hctPos.x() - 1.f);
    }
    else if ( event->key() == Qt::Key_W )
    {
        envPos.setZ(envPos.z() + 1.f);
        hctPos.setZ(hctPos.z() + 1.f);
    }
    else if ( event->key() == Qt::Key_S )
    {
        envPos.setZ(envPos.z() - 1.f);
        hctPos.setZ(hctPos.z() - 1.f);
    }
}

void Heli_GLWidget::resizeGL(int width, int height){
    //int side = qMin(width, height);
    //int min = qMin((int) (width*(9.25/18.0)), height);
    //glViewport(0,0,(int) min*(18.0/9.25), min);
    glViewport(0, 0, width, height);
    //glViewport(0,0,w,h);
    //glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
glLoadIdentity();
    glScalef(10, 10, 1);
#ifdef QT_OPENGL_ES_1
    glFrustum (-1.7, 1.7, -1.0, 1.0,2, 20000.0);
#else
    glFrustum (-1.7, 1.7, -1.0, 1.0, 2, 20000.0);
#endif
    glMatrixMode(GL_MODELVIEW);

    }


#endif // GL_2_RENDER_H
