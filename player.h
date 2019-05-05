#ifndef PLAYER_H
#define PLAYER_H


#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QObject>
#include <enemy.h>
#include <QMediaPlayer>




class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT            //Добавили макро класса QObjuct для того что бы соединить слот и сиглан при помощи функции connect

public:
    Player();
    void keyPressEvent(QKeyEvent *event);   //Переопределим метод класса QObject нажатия клавиши
    void keyReleaseEvent(QKeyEvent *event); //Переопределим метод класса QObject отпускания клавиши
public slots:
    void Spawn();
private:
    QMediaPlayer *soundShoot;

};

#endif // PLAYER_H
