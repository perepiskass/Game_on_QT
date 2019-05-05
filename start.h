#ifndef START_H
#define START_H


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
#include <QGraphicsTextItem>
#include <QFont>


class Start: public QGraphicsScene
{
    Q_OBJECT
public:
    Start();
protected:
    bool eventFilter(QObject *obj, QEvent *event);
    QGraphicsTextItem *NameGame;
    QGraphicsTextItem *StartGame;
    QGraphicsTextItem *ExitGame;


};

#endif // START_H
