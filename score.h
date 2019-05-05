#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent = 0);  // В конструктор по умолчанию будет передаватьс указатель на объект QGraphicsItem (если не передаем то там при создании будет 0)
    void increase();                    //Метод увеличения score
    int getScore();                     //Метод получения значения score
private:
    int score;
};

#endif // SCORE_H
