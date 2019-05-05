#ifndef VIEWGAME_H
#define VIEWGAME_H

#include <QGraphicsView>
#include <game.h>
#include <start.h>


class ViewGame:public QGraphicsView
{
public:
    ViewGame();
    void StartGame();
    void PlayGame();
    void EndGame();
    void ExitGame();

    Game *scene;
    Start *start;

};

#endif // VIEWGAME_H
