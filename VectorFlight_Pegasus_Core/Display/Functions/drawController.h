#ifndef DRAWCONTROLLER_H
#define DRAWCONTROLLER_H
#include <QPainter>
#include <math.h>




//*******************************************
//  Draws the controller named ctrl     arguments are    - X,Y,Scale
//*******************************************
void MainWindow::drawController(struct Struct_XBox360Controller* Controller, QImage &image, float xOffset, float yOffset, float xScaleK)
{
int xRes = gWindowWidth;
int yRes = gWindowHeight;





uint cGray  = qRgb(192 ,192,192);

//Blank the entire image, enclosed in Brackets to limit scope of QPainter Object
QPainter p;
p.begin(&image);

p.setBrush(Qt::gray);
p.drawRect(0,0,xRes,yRes);


//qRgb(192 ,192,192)
//Qt::gray


//drawController(&Ctrl, backgroundImage, 0.5, .0, .1);
//center everything so that an incomeing xScale of 1 causes it to be sized such that horizontal resolution fits the window
//and an incoming offset of 0,0, puts the controller as far up and as far left as it can be without going off the screen

xScaleK = xScaleK * 1.52;
xOffset = xOffset*100/xScaleK - 17;
yOffset = yOffset*100/xScaleK - 16.2;

QPen solidLine(QColor(qRgb(0,0,0)), 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
p.setPen(solidLine);
#define numPoints 36
float x[numPoints] = {25,29,33,37,42,48,52,58,64,67,71,75,80,83,83,82,81,79,75,72,67,62,59,50,41,38,32,28,25,21,19,17,17,17,20,25};
float y[numPoints]=  {19.2,17.4,16.2,16.8,18.6,19.2,19.2,18.6,16.8,16.2,17.4,19.2,30.6,43.2,49.2,52.2,55.2,56.4,56.4,55.2,51.6,48,46.8,46.8,47.4,48,52.2,55.2,56.4,56.4,55.2,51.6,48.6,42,30,19.2};
for (int i = 0; i < numPoints; i++) {x[i] = x[i] + xOffset;y[i] = y[i] + yOffset;}
for (int i = 1; i < numPoints; i++) p.drawLine( (x[i]   )*xRes*0.01*xScaleK,
                                                (y[i]   )*xRes*0.01*xScaleK,
                                                (x[i-1] )*xRes*0.01*xScaleK,
                                                (y[i-1] )*xRes*0.01*xScaleK);


//***  Back GUIDE Start  *****************
float Guide_X       =50;    float Guide_Y       =25;    float Guide_Width   =6 ;    float Guide_Height  =6;
float Start_X       =57;    float Start_Y       =25;    float Start_Width   =3 ;    float Start_Height  =1.5 ;
float Back_X        =43;    float Back_Y        =25;    float Back_Width    =3 ;    float Back_Height   =1.5 ;
Guide_X = Guide_X + xOffset;     Guide_Y = Guide_Y + yOffset;
Start_X = Start_X + xOffset;     Start_Y = Start_Y + yOffset;
Back_X = Back_X + xOffset;    Back_Y = Back_Y + yOffset;
QBrush blackNoFill(Qt::black,  Qt::NoBrush);
//Guide
    {    p.setBrush(blackNoFill);
    p.drawEllipse(  (Guide_X-(Guide_Width  / 2)) * (xRes * 0.01*xScaleK),
                    (Guide_Y-(Guide_Height / 2)) * (xRes * 0.01*xScaleK),
                    (Guide_Width               ) * (xRes * 0.01*xScaleK),
                    (Guide_Height              ) * (xRes * 0.01*xScaleK));
    }
if (Controller->Guide)    {
    p.setBrush(Qt::black);
    p.drawEllipse((Guide_X-(Guide_Width/2))     *(xRes*0.01*xScaleK),
                  (Guide_Y-(Guide_Height/2))    *(xRes*0.01*xScaleK),
                  (Guide_Width             )    *(xRes*0.01*xScaleK),
                  (Guide_Height            )    *(xRes*0.01*xScaleK));
    }
//Back
    {    p.setBrush(blackNoFill);
    p.drawEllipse((Back_X-(Back_Width/2))   *(xRes*0.01*xScaleK),
                  (Back_Y-(Back_Height/2))  *(xRes*0.01*xScaleK),
                  (Back_Width            )  *(xRes*0.01*xScaleK),
                  (Back_Height           )    *(xRes*0.01*xScaleK));
    }
if (Controller->Back)    {
    p.setBrush(Qt::black);
    p.drawEllipse((Back_X-(Back_Width/2))   *(xRes*0.01*xScaleK),
                  (Back_Y-(Back_Height/2))  *(xRes*0.01*xScaleK),
                  (Back_Width            )  *(xRes*0.01*xScaleK),
                  (Back_Height           )  *(xRes*0.01*xScaleK));
    }
//Start
    {    p.setBrush(blackNoFill);
    p.drawEllipse((Start_X-(Start_Width/2))  *(xRes*0.01*xScaleK),
                  (Start_Y-(Start_Height/2)) *(xRes*0.01*xScaleK),
                  (Start_Width             ) *(xRes*0.01*xScaleK),
                  (Start_Height            ) *(xRes*0.01*xScaleK));
    }
if (Controller->Start)    {
    p.setBrush(Qt::black);
    p.drawEllipse((Start_X-(Start_Width/2))  *(xRes*0.01*xScaleK),
                  (Start_Y-(Start_Height/2)) *(xRes*0.01*xScaleK),
                  (Start_Width             ) *(xRes*0.01*xScaleK),
                  (Start_Height            ) *(xRes*0.01*xScaleK));
    }



//***  REGULAR BUTTONS A B X Y   *****************
float buttonY_X       =69;    float buttonY_Y       =22;    float buttonY_Width   =3 ;    float buttonY_Height  =3;

float buttonX_X       =65;    float buttonX_Y       =25;    float buttonX_Width   =3 ;    float buttonX_Height  =3;
float buttonB_X       =73;    float buttonB_Y       =25;    float buttonB_Width   =3 ;    float buttonB_Height  =3;

float buttonA_X       =69;    float buttonA_Y       =28;    float buttonA_Width   =3 ;    float buttonA_Height  =3;

buttonX_X = buttonX_X + xOffset;    buttonX_Y = buttonX_Y + yOffset;
buttonY_X = buttonY_X + xOffset;    buttonY_Y = buttonY_Y + yOffset;
buttonA_X = buttonA_X + xOffset;    buttonA_Y = buttonA_Y + yOffset;
buttonB_X = buttonB_X + xOffset;    buttonB_Y = buttonB_Y + yOffset;
//X, Outline Always, filled if pressed
    {    p.setBrush(blackNoFill);
    p.drawEllipse((buttonX_X-(buttonX_Width/2))  *(xRes*0.01*xScaleK),
                  (buttonX_Y-(buttonX_Height/2)) *(xRes*0.01*xScaleK),
                  (buttonX_Width               ) *(xRes*0.01*xScaleK),
                  (buttonX_Height              ) *(xRes*0.01*xScaleK));
    }
if (Controller->X)    {
    p.setBrush(Qt::blue);
    p.drawEllipse((buttonX_X-(buttonX_Width/2))  *(xRes*0.01*xScaleK),
                  (buttonX_Y-(buttonX_Height/2)) *(xRes*0.01*xScaleK),
                  (buttonX_Width               ) *(xRes*0.01*xScaleK),
                  (buttonX_Height              ) *(xRes*0.01*xScaleK));
    }
//Y, Outline Always, filled if pressed
    {    p.setBrush(blackNoFill);
    p.drawEllipse((buttonY_X-(buttonY_Width/2))  *(xRes*0.01*xScaleK),
                  (buttonY_Y-(buttonY_Height/2)) *(xRes*0.01*xScaleK),
                  (buttonY_Width               ) *(xRes*0.01*xScaleK),
                  (buttonY_Height              ) *(xRes*0.01*xScaleK));
    }
if (Controller->Y)    {
    p.setBrush(Qt::darkYellow);
    p.drawEllipse((buttonY_X-(buttonY_Width/2))  *(xRes*0.01*xScaleK),
                  (buttonY_Y-(buttonY_Height/2)) *(xRes*0.01*xScaleK),
                  (buttonY_Width              )  *(xRes*0.01*xScaleK),
                  (buttonY_Height             )  *(xRes*0.01*xScaleK));
    }
//A, Outline Always, filled if pressed
    {    p.setBrush(blackNoFill);
    p.drawEllipse((buttonA_X-(buttonA_Width/2))  *(xRes*0.01*xScaleK),
                  (buttonA_Y-(buttonA_Height/2)) *(xRes*0.01*xScaleK),
                  (buttonA_Width              )  *(xRes*0.01*xScaleK),
                  (buttonA_Height             )  *(xRes*0.01*xScaleK));
    }
if (Controller->A)    {
    p.setBrush(Qt::green);
    p.drawEllipse((buttonA_X-(buttonA_Width/2))  *(xRes*0.01*xScaleK),
                  (buttonA_Y-(buttonA_Height/2)) *(xRes*0.01*xScaleK),
                  (buttonA_Width               ) *(xRes*0.01*xScaleK),
                  (buttonA_Height              ) *(xRes*0.01*xScaleK));
    }
//B, Outline Always, filled if pressed
    {    p.setBrush(blackNoFill);
    p.drawEllipse((buttonB_X-(buttonB_Width/2))  *(xRes*0.01*xScaleK),
                  (buttonB_Y-(buttonB_Height/2)) *(xRes*0.01*xScaleK),
                  (buttonB_Width               ) *(xRes*0.01*xScaleK),
                  (buttonB_Height              ) *(xRes*0.01*xScaleK));
    }
if (Controller->B)    {
    p.setBrush(Qt::red);
    p.drawEllipse((buttonB_X-(buttonB_Width/2))   *(xRes*0.01*xScaleK),
                  (buttonB_Y-(buttonB_Height/2))  *(xRes*0.01*xScaleK),
                  (buttonB_Width                ) *(xRes*0.01*xScaleK),
                  (buttonB_Height               ) *(xRes*0.01*xScaleK));
    }



//***  BUMPERS   *****************
float RB_X       =68;    float RB_Y       =16.75;    float RB_Width   =6 ;    float RB_Height  =1.5;
float LB_X       =33;    float LB_Y       =16.75;    float LB_Width   =6 ;    float LB_Height  =1.5 ;
RB_X = RB_X + xOffset;    RB_Y = RB_Y + yOffset;
LB_X = LB_X + xOffset;    LB_Y = LB_Y + yOffset;
//RB
    {
    p.setBrush(blackNoFill);
    p.drawRect((RB_X-(RB_Width/2))  *(xRes*0.01*xScaleK),
               (RB_Y-(RB_Height/2)) *(xRes*0.01*xScaleK),
               (RB_Width          ) *(xRes*0.01*xScaleK),
               (RB_Height         ) *(xRes*0.01*xScaleK));
    p.setBrush(	QColor (cGray));
    p.drawRect((RB_X-(RB_Width/2))  *(xRes*0.01*xScaleK),
               (RB_Y-(RB_Height/2)) *(xRes*0.01*xScaleK),
               (RB_Width          ) *(xRes*0.01*xScaleK),
               (RB_Height         ) *(xRes*0.01*xScaleK));
    }
if (Controller->RB)    {
    p.setBrush(Qt::black);
    p.drawRect((RB_X-(RB_Width/2))  *(xRes*0.01*xScaleK),
               (RB_Y-(RB_Height/2)) *(xRes*0.01*xScaleK),
               (RB_Width          ) *(xRes*0.01*xScaleK),
               (RB_Height         ) *(xRes*0.01*xScaleK));
    }
//LB
    {
    p.setBrush(blackNoFill);
    p.drawRect((LB_X-(LB_Width/2))  *(xRes*0.01*xScaleK),
               (LB_Y-(LB_Height/2)) *(xRes*0.01*xScaleK),
               (LB_Width         )  *(xRes*0.01*xScaleK),
               (LB_Height        )  *(xRes*0.01*xScaleK));
    p.setBrush(QColor (cGray));
    p.drawRect((LB_X-(LB_Width/2))  *(xRes*0.01*xScaleK),
               (LB_Y-(LB_Height/2)) *(xRes*0.01*xScaleK),
               (LB_Width          ) *(xRes*0.01*xScaleK),
               (LB_Height         ) *(xRes*0.01*xScaleK));
    }
if (Controller->LB)    {
    p.setBrush(Qt::black);
    p.drawRect((LB_X-(LB_Width/2))  *(xRes*0.01*xScaleK),
               (LB_Y-(LB_Height/2)) *(xRes*0.01*xScaleK),
               (LB_Width          ) *(xRes*0.01*xScaleK),
               (LB_Height         ) *(xRes*0.01*xScaleK));
    }










//***  DIRECTIONAL KEYPAD   *****************
float KPD_Xpos = 41 + xOffset;
float KPD_Ypos = 35 + yOffset;
//up
if ((Controller->KPD_Y) == 1)  p.setBrush(Qt::black);
if ((Controller->KPD_Y) != 1)  p.setBrush(blackNoFill);
p.drawRect(   (KPD_Xpos     ) *(xRes*0.01*xScaleK),
              (KPD_Ypos     ) *(xRes*0.01*xScaleK),
              (2            ) *(xRes*0.01*xScaleK),
              (2            ) *(xRes*0.01*xScaleK));
//down
if ((Controller->KPD_Y) == -1)  p.setBrush(Qt::black);
if ((Controller->KPD_Y) != -1)  p.setBrush(blackNoFill);
p.drawRect(   (KPD_Xpos     ) *(xRes*0.01*xScaleK),
              (KPD_Ypos +4  ) *(xRes*0.01*xScaleK),
              (2            ) *(xRes*0.01*xScaleK),
              (2            ) *(xRes*0.01*xScaleK));
//left
if ((Controller->KPD_X) == -1)  p.setBrush(Qt::black);
if ((Controller->KPD_X) != -1)  p.setBrush(blackNoFill);
p.drawRect(   (KPD_Xpos - 2 ) *(xRes*0.01*xScaleK),
              (KPD_Ypos + 2 ) *(xRes*0.01*xScaleK),
              (2            ) *(xRes*0.01*xScaleK),
              (2            ) *(xRes*0.01*xScaleK));
//right
if ((Controller->KPD_X) == 1)  p.setBrush(Qt::black);
if ((Controller->KPD_X) != 1)  p.setBrush(blackNoFill);
p.drawRect(   (KPD_Xpos + 2 ) *(xRes*0.01*xScaleK),
              (KPD_Ypos + 2 ) *(xRes*0.01*xScaleK),
              (2            ) *(xRes*0.01*xScaleK),
              (2            ) *(xRes*0.01*xScaleK));



//***  TRIGGERS   *****************
float RT_Perim_Height  =5; float RT_X =59.5; float RT_Y =17; float RT_Width =1.5; float RT_Height  =1.5;
float LT_Perim_Height  =5; float LT_X =40;   float LT_Y =17; float LT_Width =1.5; float LT_Height  =1.5;
RT_X = RT_X + xOffset;    RT_Y = RT_Y + yOffset;
LT_X = LT_X + xOffset;    LT_Y = LT_Y + yOffset;

float boxWidth  = 20;   //Display numbers above triggers
float boxHeight = 5;
p.setFont(QFont("Verdana", (standardTextSize)));
int minimalTextSizeForText = 640;

p.setBrush(blackNoFill);
if (gWindowWidth*xScaleK >= minimalTextSizeForText)
p.drawText(QRect( (RT_X-(boxWidth /2)    )  *(xRes*0.01*xScaleK),
                  (RT_Y-(boxHeight/2)-2.5)  *(xRes*0.01*xScaleK),
                  (boxWidth              )  *(xRes*0.01*xScaleK),
                  (boxHeight             )  *(xRes*0.01*xScaleK)),
                  Qt::AlignCenter, QString::number(Controller->RT));
if (gWindowWidth*xScaleK >= minimalTextSizeForText)
p.drawText(QRect( (LT_X-(boxWidth /2)    )  *(xRes*0.01*xScaleK),
                  (LT_Y-(boxHeight/2)-2.5)  *(xRes*0.01*xScaleK),
                  (boxWidth              )  *(xRes*0.01*xScaleK),
                  (boxHeight             )  *(xRes*0.01*xScaleK)),
                  Qt::AlignCenter, QString::number(Controller->LT));

//Perimeters
    {
    QBrush b1(Qt::black,  Qt::NoBrush);    p.setBrush(b1);
    p.drawRect((RT_X-(RT_Width/2))  *(xRes*0.01*xScaleK),
               (RT_Y             )  *(xRes*0.01*xScaleK),
               (RT_Width         )  *(xRes*0.01*xScaleK),
               (RT_Perim_Height  )  *(xRes*0.01*xScaleK));
    p.setBrush(QColor (cGray));
    p.drawRect((RT_X-(RT_Width/2))  *(xRes*0.01*xScaleK),
               (RT_Y             )  *(xRes*0.01*xScaleK),
               (RT_Width         )  *(xRes*0.01*xScaleK),
               (RT_Perim_Height  )  *(xRes*0.01*xScaleK));
    }
    {
    QBrush b1(Qt::black,  Qt::NoBrush);    p.setBrush(b1);
    p.drawRect((LT_X-(LT_Width/2))  *(xRes*0.01*xScaleK),
               (LT_Y             )  *(xRes*0.01*xScaleK),
               (LT_Width         )  *(xRes*0.01*xScaleK),
               (LT_Perim_Height  )  *(xRes*0.01*xScaleK));
    p.setBrush(QColor (cGray));
    p.drawRect((LT_X-(LT_Width/2))  *(xRes*0.01*xScaleK),
               (LT_Y             )  *(xRes*0.01*xScaleK),
               (LT_Width         )  *(xRes*0.01*xScaleK),
               (LT_Perim_Height  )  *(xRes*0.01*xScaleK));
    }
//Indicator Dots
float LT_Ymov = ((float) (Controller->LT)  / (float) 65535) * (LT_Perim_Height - LT_Height);
    {
    p.setBrush(Qt::black);
    p.drawRect((LT_X-(LT_Width/2))  *(xRes*0.01*xScaleK),
               (LT_Ymov +LT_Y    )  *(xRes*0.01*xScaleK),
               (LT_Width         )  *(xRes*0.01*xScaleK),
               (LT_Height        )  *(xRes*0.01*xScaleK));
    }
float RT_Ymov = ((float) (Controller->RT)  / (float) 65535) * (RT_Perim_Height - RT_Height);
    {
    p.setBrush(Qt::black);
    p.drawRect((RT_X-(RT_Width/2))  *(xRes*0.01*xScaleK),
               (RT_Ymov +RT_Y    )  *(xRes*0.01*xScaleK),
               (RT_Width         )  *(xRes*0.01*xScaleK),
               (RT_Height        )  *(xRes*0.01*xScaleK));
    }








//***  ANALOG JOYSTICKS   *****************
//Right Joystick
float RJ_X       =60;    float RJ_Y       =38;    float RJ_Width   =3 ;    float RJ_Height  =3;    float RJPerim_Width   =12 ;    float RJPerim_Height  =12;
RJ_X = RJ_X + xOffset;    RJ_Y = RJ_Y + yOffset;
p.setBrush(blackNoFill);








//Outer Perimieter
p.drawEllipse((RJ_X  - (RJPerim_Width/2)        ) *(xRes*0.01*xScaleK),
              (RJ_Y  - (RJPerim_Width/2)        ) *(xRes*0.01*xScaleK),
              (RJPerim_Width                    ) *(xRes*0.01*xScaleK),
              (RJPerim_Height                   ) *(xRes*0.01*xScaleK));
//Inner
p.drawEllipse((RJ_X  - (RJ_Width/2)           ) *(xRes*0.01*xScaleK),
              (RJ_Y  - (RJ_Width/2)           ) *(xRes*0.01*xScaleK),
              (RJ_Width                       ) *(xRes*0.01*xScaleK),
              (RJ_Height                      ) *(xRes*0.01*xScaleK));
float RJ_Ymov = sin ((((float) (Controller->RJ_Ang))-900)*0.0017452778) * (float) (Controller->RJ_Mag)*((RJPerim_Width-RJ_Width)/2)/32767;
float RJ_Xmov = cos ((((float) (Controller->RJ_Ang))-900)*0.0017452778) * (float) (Controller->RJ_Mag)*((RJPerim_Width-RJ_Width)/2)/32767;
    if (Controller->RJ)    p.setBrush(Qt::black);
    p.drawEllipse((RJ_X  - (RJ_Width/2) + RJ_Xmov ) *(xRes*0.01*xScaleK),
                  (RJ_Y  - (RJ_Width/2) + RJ_Ymov ) *(xRes*0.01*xScaleK),
                  (RJ_Width                       ) *(xRes*0.01*xScaleK),
                  (RJ_Height                      ) *(xRes*0.01*xScaleK));

//NOTE:  Y coordinate scaling factor is unity with X axis
//Right Joystick
float LJ_X =31; float LJ_Y =27; float LJ_Width =3; float LJ_Height =3; float LJPerim_Width =12; float LJPerim_Height =12;
LJ_X = LJ_X + xOffset;    LJ_Y = LJ_Y + yOffset;
p.setBrush(blackNoFill);
//Outer Perimieter
p.drawEllipse((LJ_X  - (LJPerim_Width/2)       ) *(xRes*0.01*xScaleK),
              (LJ_Y  - (LJPerim_Width/2)       ) *(xRes*0.01*xScaleK),
              (LJPerim_Width                   ) *(xRes*0.01*xScaleK),
              (LJPerim_Height                  ) *(xRes*0.01*xScaleK));
//Inner
p.drawEllipse((LJ_X  - (LJ_Width/2)           ) *(xRes*0.01*xScaleK),
              (LJ_Y  - (LJ_Width/2)           ) *(xRes*0.01*xScaleK),
              (LJ_Width                       ) *(xRes*0.01*xScaleK),
              (LJ_Height                      ) *(xRes*0.01*xScaleK));
float LJ_Ymov = sin ((((float) (Controller->LJ_Ang))-900)*0.0017452778) * (float) (Controller->LJ_Mag)*((LJPerim_Width-LJ_Width)/2)/32767;
float LJ_Xmov = cos ((((float) (Controller->LJ_Ang))-900)*0.0017452778) * (float) (Controller->LJ_Mag)*((LJPerim_Width-LJ_Width)/2)/32767;
    p.setBrush(blackNoFill);
    if (Controller->LJ)    p.setBrush(Qt::black);
    p.drawEllipse((LJ_X  - (LJ_Width/2) + LJ_Xmov ) *(xRes*0.01*xScaleK),
                  (LJ_Y  - (LJ_Width/2) + LJ_Ymov ) *(xRes*0.01*xScaleK),
                  (LJ_Width                       ) *(xRes*0.01*xScaleK),
                  (LJ_Height                      ) *(xRes*0.01*xScaleK));

//Draw Text
    p.setBrush(blackNoFill);
    if (gWindowWidth*xScaleK >= minimalTextSizeForText)
    p.drawText(QRect( (RJ_X-(boxWidth /2)    )  *(xRes*0.01*xScaleK),
                      (RJ_Y-(boxHeight/2)+7.5)  *(xRes*0.01*xScaleK),
                      (boxWidth              )  *(xRes*0.01*xScaleK),
                      (boxHeight             )  *(xRes*0.01*xScaleK)),
               Qt::AlignCenter,
               QString::number(Controller->RJ_Mag)+"@"+QString::number(((float)Controller->RJ_Ang)/10)+""
               );

    p.setBrush(blackNoFill);
    if (gWindowWidth*xScaleK >= minimalTextSizeForText)
    p.drawText(QRect( (LJ_X-(boxWidth /2)    )  *(xRes*0.01*xScaleK),
                      (LJ_Y-(boxHeight/2)+7.5)  *(xRes*0.01*xScaleK),
                      (boxWidth              )  *(xRes*0.01*xScaleK),
                      (boxHeight             )  *(xRes*0.01*xScaleK)),
               Qt::AlignCenter,
               QString::number(Controller->LJ_Mag)+"@"+QString::number(((float)Controller->LJ_Ang)/10)+""
               );


p.end();

}




#endif // DRAWCONTROLLER_H
