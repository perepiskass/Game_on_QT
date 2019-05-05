#include "enemy.h"
#include <QTimer>
#include <QDebug>
#include <stdlib.h>            //Для подключения функции rand()
#include <viewgame.h>

extern ViewGame* vgame;  // объявили использование указателя на внешнюю глобальную переменную класса Game (для того чтобы через нее можно было добраться до переменных и методов класса Game

Enemy::Enemy(): QObject (), QGraphicsPixmapItem ()
{
    int random_number = rand() % 700;       //Зададим при создании рандомное значение x (левый верхний угол прямоугольника) от 0 до 700 т.к. ширина равна 100 и x не должен выходить за 800 пикселей
    setPos(random_number,0);

    setPixmap(QPixmap(":/images/Enemy_front.png").scaled(100,100,Qt::IgnoreAspectRatio)); //Cоздаем игрока из изображения

    timer = new QTimer(); //Создали объект типа QTimer для  того что бы подсоединить к нему слот функцию move()
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));   //Соединяем сиглал от таймера со слотом move этого объекта
    timer->start(50);          //Устанавливаем счетчик для объекта timer (каждые 50 милесекунд будет выполянться метод move)

}
void Enemy::move()          //Метод сдвига врага вниз
{
    setPos(x(),y()+5);      //Вниз по y на 5 пикселей
    if ((pos().y() + pixmap().height()) > 600)     // Если позиция по координате (y+высота) стала больше 600 в ситеме координат scene то удалим этот объект из scene
    {
        vgame->scene->health->decrease();   //Если враг проскочил то уменьшаем жизни

        scene()->removeItem(this);  // Удаляем объект враг из объекта scene класса QGraphicsScene
        //qDebug() << "Враг проскочил и был удален";
        delete this;                // Удаляем сам объект враг из памяти
        if (vgame->scene->health->getHealth() == 0) vgame->EndGame();
    }

}

Enemy::~Enemy()
{
    delete timer;
}
