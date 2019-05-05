#include "viewgame.h"
#include <QList>

ViewGame::ViewGame()
{
    StartGame();
}

void ViewGame::StartGame()
{
    start = new Start();
    start->installEventFilter(start);
    setScene(start);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем горизонтальный скролл бар
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключаем вертикальный скролл бар
    setFixedSize(800,600);
}

void ViewGame::PlayGame()
{
    scene = new Game();
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем горизонтальный скролл бар
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключаем вертикальный скролл бар для того что бы вид не увеличивался бесконечно пока летит пуля
    setFixedSize(800,600);
}

void ViewGame::EndGame()
{
    QList<QGraphicsItem *> DelItems = scene->items();
    for (auto it : DelItems)
    {
        scene->removeItem(it);
        delete it;
    }
    delete scene;
    StartGame();
}

void ViewGame::ExitGame()
{
    delete start;
    exit(0);
}
