#include "start.h"
#include <viewgame.h>

extern ViewGame* vgame;  // объявили использование указателя на внешнюю глобальную переменную класса Game (для того чтобы через нее можно было добраться до переменных и методов класса Game


Start::Start()
{
  setSceneRect(0,0,800,600);   //Зададим размеры сцены действия стартовыми размерами 800 на 600
  setBackgroundBrush(QBrush(QImage(":/images/Su-47.png")));
  NameGame = addText("Su-47",QFont("arial",34));
  NameGame->setDefaultTextColor(Qt::red);
  NameGame->setPos(600,80);
  StartGame = addText("Для старта игры нажмите пробел",QFont("time",22));
  StartGame->setPos(50,350);
  StartGame->setDefaultTextColor(Qt::blue);
  ExitGame = addText("Для выхода из игры нажмите Ecs",QFont("time",18));
  ExitGame->setPos(50,400);
  ExitGame->setDefaultTextColor(Qt::blue);
}

bool Start::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == this && event->type() == QEvent::KeyPress)
    {

        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if(keyEvent->key() == Qt::Key_Space)
        {
            //qDebug()<< "Кнопка Space нажата";
            this->removeEventFilter(this);
            delete this;
            vgame->PlayGame();

        }
          else if(keyEvent->key() == Qt::Key_Escape)
        {
            //qDebug()<< "Кнопка Escape нажата";
            vgame->ExitGame();
        }
        //qDebug()<< "Кнопка нажата";

        return true;
    }
    else return QObject::eventFilter(obj, event);
}
