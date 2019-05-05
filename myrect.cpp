#include "myrect.h"
#include "bullet.h"
#include <QDebug>

MyRect::MyRect()
{

}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    //Движение прямоугольника
    if(event->key() == Qt::Key_Left && pos().x() > 0) setPos(x()-10,y());   // При нажатие передвигаем в лево пока левая граница прямоугольниа больше 0 в системе координат scene
    else if(event->key() == Qt::Key_Right && pos().x()+100 < 800) setPos(x()+10,y()); // При нажатии передвигаем в право пока правая граница прямоугльника (x+100) меньше чем 800 в системе координат scene
    //else if(event->key() == Qt::Key_Up) setPos(x(),y()-10);
    //else if(event->key() == Qt::Key_Down) setPos(x(),y()+10);
    //Стрельба прямоугольника
    else if(event->key() == Qt::Key_Space)  //При нажатии на кнопку space создаем объект bullet класса Bullet
    {
        Bullet *bullet = new Bullet();
        bullet->setPos(x()+45,y());            //Зададим начальную позицию для объета пуля относительно координат прямоугольника
        scene()->addItem(bullet);           //Добавим наш объект в объект scene класса QGraphicsScene (созданного в main)
    }
}

void MyRect::Spawn()        //Слот функция создания врагов
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);

}
