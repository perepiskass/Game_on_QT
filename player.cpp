#include "player.h"
#include <bullet.h>
#include <QDebug>
#include <viewgame.h>

extern ViewGame* vgame;  // объявили использование указателя на внешнюю глобальную переменную класса Game (для того чтобы через нее можно было добраться до переменных и методов класса Game


Player::Player()
{
    //Создание звука выстрела---------------
    soundShoot = new QMediaPlayer();                            //Создадим объект в памяти
    soundShoot->setMedia(QUrl("qrc:/sounds/shoot.mp3")); // Присвоим данному объекту звук выстрела
}

void Player::keyPressEvent(QKeyEvent *event)
{
    //Движение игрока
    if(event->key() == Qt::Key_Left && pos().x() > 0)
    {
        setPos(x()-10,y());   // При нажатие передвигаем в лево пока левая граница прямоугольниа больше 0 в системе координат scene
        this->setPixmap(QPixmap(":/images/Su-47_rightside.png").scaled(50,100,Qt::IgnoreAspectRatio)); //Cоздаем игрока из изображения

    }
      else if(event->key() == Qt::Key_Right && pos().x()+100 < 800)
    {
        setPos(x()+10,y()); // При нажатии передвигаем в право пока правая граница прямоугльника (x+100) меньше чем 800 в системе координат scene
        this->setPixmap(QPixmap(":/images/Su-47_leftside.png").scaled(50,100,Qt::IgnoreAspectRatio)); //Cоздаем игрока из изображения
    }
    //Стрельба игрока
    else if(event->key() == Qt::Key_Space)  //При нажатии на кнопку space создаем объект bullet класса Bullet
    {
        Bullet *bullet = new Bullet();
        bullet->setPos(x()+45,y());            //Зададим начальную позицию для объета пуля относительно координат прямоугольника
        scene()->addItem(bullet);           //Добавим наш объект в объект scene класса QGraphicsScene (созданного в main)

        //Добавим звук выстрела при нажатии на space
        if (soundShoot->state() == QMediaPlayer::PlayingState) soundShoot->setPosition(0); //Если звук при нажатии кнопки уже воспроизводился (от другого выстрела) то переводим состояние в 0
        else if (soundShoot->state() == QMediaPlayer::StoppedState) soundShoot->play();    //Если звук не воспроизводится то запускаем воспроизведение
    }
    else if(event->key() == Qt::Key_Escape)
    {
        vgame->EndGame();
    }

}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    if(event->type()==QEvent::KeyRelease && (event->key() == Qt::Key_Left || event->key() == Qt::Key_Right))
        this->setPixmap(QPixmap(":/images/Su-47_front.png").scaled(100,100,Qt::IgnoreAspectRatio)); //Cоздаем игрока из изображения
}

void Player::Spawn()        //Слот функция создания врагов
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);

}
