#ifndef HEALTH_H
#define HEALTH_H


#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem
{
public:
    Health(QGraphicsItem *parent = 0);  // В конструктор по умолчанию будет передаватьс указатель на объект QGraphicsItem (если не передаем то там при создании будет 0)
    void decrease();                    //Метод увеличения score
    int getHealth();                     //Метод получения значения score
private:
    int healt;
};

#endif // HEALTH_H
