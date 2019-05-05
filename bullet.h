#ifndef BULLET_H
#define BULLET_H

//#include <QGraphicsRectItem>   //Заменим библиотеку работы с прямоугольниками на библиотеку для работы с изображениями (для ввода в игру картинок)
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>



class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT            //Добавили макро класса QObjuct для того что бы соединить слот и сиглан при помощи функции connect
public:
    Bullet();
public slots:
    void move();
};

#endif // BULLET_H
