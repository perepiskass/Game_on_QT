#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QGraphicsScene>
#include <player.h>
#include <score.h>
#include <health.h>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>         //Для подключения данной библиотеки требуется подключить модуль multimedia (в *.pro в данном случае)
#include <QBrush>               //Для добавления заднего фона в игру
#include <QImage>
#include <start.h>

class Game: public QGraphicsScene
{
public:
    Game();
    ~Game();
    QGraphicsScene *scene;
    Player *player;
    Score *score;
    Health *health;
private:
    QTimer *timer;
    QMediaPlayer *music;

};

#endif // GAME_H
