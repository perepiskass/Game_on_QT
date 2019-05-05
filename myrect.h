#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QObject>
#include <enemy.h>




class MyRect: public QObject, public QGraphicsRectItem
{
    Q_OBJECT            //Добавили макро класса QObjuct для того что бы соединить слот и сиглан при помощи функции connect

public:
    MyRect();
    void keyPressEvent(QKeyEvent *event);
public slots:
    void Spawn();
};

#endif // MYRECT_H
