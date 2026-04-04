#ifndef GL_3_ANIMATE_H
#define GL_3_ANIMATE_H

#include <math.h>


extern int gWindowWidth;
extern int gWindowHeight;
//*******************************************************
void drawCircle(QImage &image, QPainter &p, float sizeRequested, float xOffset, float yOffset, float x, float y, float diameter){
    UNUSED(image);
    x = x + xOffset;     y = y + yOffset;
    QPen solidLine(QColor(qRgb(0,0,0)), 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    p.setPen(solidLine);
    p.setBrush(Qt::gray);
    p.drawEllipse(  (x-(diameter / 2)) * (gWindowWidth * 0.01*sizeRequested),
                    (y-(diameter / 2)) * (gWindowWidth * 0.01*sizeRequested),
                    (diameter        ) * (gWindowWidth * 0.01*sizeRequested),
                    (diameter        ) * (gWindowWidth * 0.01*sizeRequested));    }

//****************************************************************************************


HelContWnd::HelContWnd(){

        mainLayout = new QVBoxLayout;

        /*
        xSlider = createSlider();
        ySlider = createSlider();
        zSlider = createSlider();
        aSlider = createSlider();
        bSlider = createSlider();
        cSlider = createSlider();
       horizontalGroupBox1 = new QGroupBox(tr("Initial Conditions"));
       QHBoxLayout *layout1 = new QHBoxLayout;
       layout1->addWidget(xSlider);
       layout1->addWidget(ySlider);
       layout1->addWidget(zSlider);
       layout1->addWidget(aSlider);
       layout1->addWidget(bSlider);
       layout1->addWidget(cSlider);
       horizontalGroupBox1->setLayout(layout1);*/
/*
       lineEdit1 = new  QLineEdit;
       lineEdit2 = new  QLineEdit;
       lineEdit3 = new  QLineEdit;
       lineEdit4 = new  QLineEdit;
       lineEdit5 = new  QLineEdit;
       lineEdit6 = new  QLineEdit;
       horizontalGroupBox2 = new QGroupBox(tr("Initial Conditions (Numeric Display)"));
       QHBoxLayout *layout2 = new QHBoxLayout;
       layout2->addWidget(lineEdit1); lineEdit1->setEnabled(0);
       layout2->addWidget(lineEdit2); lineEdit2->setEnabled(0);
       layout2->addWidget(lineEdit3); lineEdit3->setEnabled(0);
       layout2->addWidget(lineEdit4); lineEdit4->setEnabled(0);
       layout2->addWidget(lineEdit5); lineEdit5->setEnabled(0);
       layout2->addWidget(lineEdit6); lineEdit6->setEnabled(0);
       horizontalGroupBox2->setLayout(layout2);*/
/*
       label1 = new  QLabel;    label1->setText("Heading");
       label2 = new  QLabel;    label2->setText("TiltHeading");
       label3 = new  QLabel;    label3->setText("TiltAmount");
       label4 = new  QLabel;    label4->setText("X");
       label5 = new  QLabel;    label5->setText("Y");
       label6 = new  QLabel;    label6->setText("Z - Distance");
       horizontalGroupBox3 = new QGroupBox(tr("Parameter"));
       QHBoxLayout *layout3 = new QHBoxLayout;
       layout3->addWidget(label1);
       layout3->addWidget(label2);
       layout3->addWidget(label3);
       layout3->addWidget(label4);
       layout3->addWidget(label5);
       layout3->addWidget(label6);
       horizontalGroupBox3->setLayout(layout3);
       */

       isAnimating      = new  QPushButton; isAnimating->setText("Animate");
       resetSimulation  = new  QPushButton; resetSimulation->setText("Reset Simulation");
       horizontalGroupBox4 = new QGroupBox(tr("Actions"));
       QHBoxLayout *layout4 = new QHBoxLayout;
       layout4->addWidget(isAnimating);
       layout4->addWidget(resetSimulation);
       horizontalGroupBox4->setLayout(layout4);

       /*
       QHBoxLayout *layout5 = new QHBoxLayout;
       horizontalGroupBox5 = new QGroupBox(tr("Initial Velocity (Roll=RPM, Move=MPH)"));
       label10 = new  QLabel;    label10->setText("Yaw Rate");
       label20 = new  QLabel;    label20->setText("Roll Velocity");
       label30 = new  QLabel;    label30->setText("Roll Azimuth");
       label40 = new  QLabel;    label40->setText("X Velocity");
       label50 = new  QLabel;    label50->setText("Y Velocity");
       label60 = new  QLabel;    label60->setText("Z Velocity");
       layout5->addWidget(label10);
       layout5->addWidget(label20);
       layout5->addWidget(label30);
       layout5->addWidget(label40);
       layout5->addWidget(label50);
       layout5->addWidget(label60);
       horizontalGroupBox5->setLayout(layout5);*/

      /* QHBoxLayout *layout6 = new QHBoxLayout;
       horizontalGroupBox6 = new QGroupBox();
       lineEdit10 = new  QLineEdit;     lineEdit10->setText("0");
       lineEdit20 = new  QLineEdit;     lineEdit20->setText("0");
       lineEdit30 = new  QLineEdit;     lineEdit30->setText("0");
       lineEdit40 = new  QLineEdit;     lineEdit40->setText("0");
       lineEdit50 = new  QLineEdit;     lineEdit50->setText("0");
       lineEdit60 = new  QLineEdit;     lineEdit60->setText("0");
       layout6->addWidget(lineEdit10);
       layout6->addWidget(lineEdit20);
       layout6->addWidget(lineEdit30);
       layout6->addWidget(lineEdit40);
       layout6->addWidget(lineEdit50);
       layout6->addWidget(lineEdit60);
       horizontalGroupBox6->setLayout(layout6);*/

     //  mainLayout->addWidget(horizontalGroupBox3);
      // mainLayout->addWidget(horizontalGroupBox1);
      // mainLayout->addWidget(horizontalGroupBox2);
       mainLayout->addWidget(horizontalGroupBox4);
       //mainLayout->addWidget(horizontalGroupBox5);
      // mainLayout->addWidget(horizontalGroupBox6);
       setLayout(mainLayout);
/*
       connect(xSlider, SIGNAL(valueChanged(int)), this, SLOT(getSliderPosition_x(int)));
       connect(ySlider, SIGNAL(valueChanged(int)), this, SLOT(getSliderPosition_y(int)));
       connect(zSlider, SIGNAL(valueChanged(int)), this, SLOT(getSliderPosition_z(int)));
       connect(aSlider, SIGNAL(valueChanged(int)), this, SLOT(getSliderPosition_a(int)));
       connect(bSlider, SIGNAL(valueChanged(int)), this, SLOT(getSliderPosition_b(int)));
       connect(cSlider, SIGNAL(valueChanged(int)), this, SLOT(getSliderPosition_c(int)));

       connect(lineEdit10, SIGNAL(textChanged(QString)), this, SLOT(textChangedA(QString)));
       connect(lineEdit20, SIGNAL(textChanged(QString)), this, SLOT(textChangedB(QString)));
       connect(lineEdit30, SIGNAL(textChanged(QString)), this, SLOT(textChangedC(QString)));
       connect(lineEdit40, SIGNAL(textChanged(QString)), this, SLOT(textChangedD(QString)));
       connect(lineEdit50, SIGNAL(textChanged(QString)), this, SLOT(textChangedE(QString)));
       connect(lineEdit60, SIGNAL(textChanged(QString)), this, SLOT(textChangedF(QString)));
*/
       connect(isAnimating, SIGNAL(clicked()),          this, SLOT(animatePressed()));
       connect(resetSimulation, SIGNAL(clicked()),  this, SLOT(resetPressed()));
/*
       xSlider->setValue(16);
       ySlider->setValue(16);
       zSlider->setValue(16);
       aSlider->setValue(180*16);
       bSlider->setValue(0);
       cSlider->setValue(75*16);
       lineEdit5->setText("0");
       setWindowTitle(tr("Position and Orientation"));
*/

       resetPressed();
       animatePressed();
       //Initialize Heli Vars;    VARIABLES*******





       simuHeli.mass        = simuHeli.CenterOfCraftMass + simuHeli.propAndMotorMass *numberOfMotors;
       simuHeli.yawMoment   = simuHeli.CenterOfCraftMass * powf(simuHeli.CenterOfCraftRadius,2) /2
                             + simuHeli.propAndMotorMass * simuHeli.armLength * numberOfMotors;
       simuHeli.rollMoment  = simuHeli.CenterOfCraftMass * powf(simuHeli.CenterOfCraftRadius,2) /4
                             + simuHeli.propAndMotorMass * simuHeli.armLength * 0.866 * 2;


       //Set position and start animation
       simuHeli.NoseAzimuth  = 0;
       simuHeli.TiltAmount   = 0;
       simuHeli.TiltAzimuth  = 0;
       simuHeli.pos_X        = 0;
       simuHeli.pos_Y        = 0;
       simuHeli.pos_Z        = 50;
       simuHeli.isAnimate      = 1;
       simuHeli.hasAnimated    = 1;
       setAnimText();

       //MotorTorque = 0.0534 ft*motorMaxThrust;

    }


QSlider *HelContWnd::createSlider(){
    QSlider *slider = new QSlider(Qt::Vertical);
    slider->setRange(0, 360 * 16);
    slider->setSingleStep(1);
    slider->setPageStep(15 * 16);
    slider->setTickInterval(15 * 16);
    slider->setTickPosition(QSlider::TicksRight);
    return slider;
}

void HelContWnd::getSliderPosition_x(int x)
{
    simuHeli.Heli_d = (x/16);
    lineEdit1->setText(QString::number(simuHeli.Heli_d));
    Position_X = simuHeli.Heli_d;
}
void HelContWnd::getSliderPosition_y(int x)
{
    simuHeli.Heli_f = (x/16);
    lineEdit2->setText(QString::number(simuHeli.Heli_f));
    Position_Z = simuHeli.Heli_f;
}
void HelContWnd::getSliderPosition_z(int x)
{
    simuHeli.Heli_e = ((x/16));
    lineEdit3->setText(QString::number(simuHeli.Heli_e));
    Position_Y = simuHeli.Heli_e;
}
void HelContWnd::getSliderPosition_a(int x)
{
    simuHeli.Heli_a = (x-(16*180))/36;
    lineEdit4->setText(QString::number(simuHeli.Heli_a));
    Position_A = simuHeli.Heli_a;
}
void HelContWnd::getSliderPosition_b(int x)
{
    simuHeli.Heli_b = (x)/36;
    lineEdit5->setText(QString::number(simuHeli.Heli_b));
    Position_B = simuHeli.Heli_b;
}
void HelContWnd::getSliderPosition_c(int x){
    simuHeli.Heli_c = powf((float)((float)x/320.0), 3);
    lineEdit6->setText(QString::number(simuHeli.Heli_c));
    Position_C = simuHeli.Heli_c;
}

void HelContWnd::textChangedA(QString t) {simuHeli.YawRate      = t.toFloat();}
void HelContWnd::textChangedB(QString t) {simuHeli.RollVelocity = t.toFloat();}
void HelContWnd::textChangedC(QString t) {simuHeli.RollAzimuth  = t.toFloat();}
void HelContWnd::textChangedD(QString t) {simuHeli.Velocity_X   = t.toFloat();}
void HelContWnd::textChangedE(QString t) {simuHeli.Velocity_Y   = t.toFloat();}
void HelContWnd::textChangedF(QString t) {simuHeli.Velocity_Z   = t.toFloat();}


void HelContWnd::animatePressed() {
    if (!simuHeli.isAnimate){
//        set velocyity back to the user defined value
//        simuHeli.YawRate        =  lineEdit10->text().toFloat();
//        simuHeli.RollVelocity   =  lineEdit20->text().toFloat();
//        simuHeli.RollAzimuth    =  lineEdit30->text().toFloat();
//        simuHeli.Velocity_X     =  lineEdit40->text().toFloat();
//        simuHeli.Velocity_Y     =  lineEdit50->text().toFloat();
//        simuHeli.Velocity_Z     =  lineEdit60->text().toFloat();

        //go
        simuHeli.isAnimate      = 1;
        simuHeli.hasAnimated    = 1;
        setAnimText();

        }
    else{
        simuHeli.isAnimate      = 0;
        setAnimText();
        }
    }
void HelContWnd::resetPressed() {
    simuHeli.hasAnimated = 0;
    simuHeli.isAnimate   = 0;
    setAnimText();
    }
void HelContWnd::setAnimText(){
    if (simuHeli.isAnimate){
        isAnimating->setText("Stop");
        }
    else{
        isAnimating->setText("Animate");
        }
    }


#endif // GL_3_ANIMATE_H
