#ifndef ENEMY_H
#define ENEMY_H


#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>



class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT            //Добавили макро класса QObjuct для того что бы соединить слот и сиглан при помощи функции connect
public:
    Enemy();
    ~Enemy();
private:
    QTimer *timer;
public slots:
    void move();
};

#endif // ENEMY_H
