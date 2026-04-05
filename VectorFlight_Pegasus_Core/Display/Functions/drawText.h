#ifndef DRAWTEXT_H
#define DRAWTEXT_H




//Drawtext
void drawText(QImage &image, float size, QString fontStyle, QString fontType, int alignment, QPen myPen, float xPos, float yPos, QString textString)
    {
    UNUSED(image);
    #define boxSizingFactor 1
    float boxHeight = size * 1.7;
    float boxWidth = (float) textString.length() * size * (float) boxSizingFactor;  //increase
    QPainter p;     p.begin(&backgroundImage);
    QFont myFont    = QFont(fontType, (size));
    if (fontStyle.toUpper().contains("BOLD"))       myFont.setBold(1);
    if (fontStyle.toUpper().contains("ITALIC"))     myFont.setItalic(1);
    if (fontStyle.toUpper().contains("UNDERLINE"))  myFont.setUnderline(1);
    p.setFont(myFont);
    p.setPen(myPen);

    if (alignment == Qt::AlignLeft)     xPos = xPos + boxWidth /2;
    if (alignment == Qt::AlignRight)    xPos = xPos - boxWidth /2;

    p.drawText(QRect( (xPos-(boxWidth /2)    ),
                      (yPos-(boxHeight/2)-2.5),
                      boxWidth,
                      boxHeight),
                      alignment,textString);
    }


#endif // DRAWTEXT_H
