#ifndef MOUSEEVENTS_H
#define MOUSEEVENTS_H
#include <QWheelEvent>

void MainWindow::wheelEvent(QWheelEvent* event)
    {

    //if (event->modifiers().testFlag(Qt::ControlModifier)) qDebug() << "Scrooll";
    float thumbwheelMovement = (event->angleDelta()).y() / (float) 120;
    if ((QApplication::keyboardModifiers() && Qt::ControlModifier)){
        //See UserInput--->keyPressEvent.h
        zoomLevel = zoomLevel * ((float) 1 + (thumbwheelMovement / (float) 10));
        if (zoomLevel < 0.2) zoomLevel = 0.2;
        if (zoomLevel > 5) zoomLevel = 5;
        }

    }





#endif // MOUSEEVENTS_H
