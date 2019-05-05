#include "health.h"
#include <QFont>
#include <viewgame.h>

extern ViewGame* vgame;  // объявили использование указателя на внешнюю глобальную переменную класса Game (для того чтобы через нее можно было добраться до переменных и методов класса Game

Health::Health(QGraphicsItem *parent): QGraphicsTextItem (parent)     //Копируем конструктор по умолчанию из класса родителя QGraphicsTextItem
{
    healt = 3;          // Присваиваем переменной score первоночальное значение

    setPlainText(QString("Health: ") + QString::number(healt));     // Зададим строку для вывода на экран у созданного объекта при помощи родительского метода
    setDefaultTextColor(Qt::blue);                      //Установим цвет по умолчанию для текста blue
    setFont(QFont("times",16));         //Установим тип и размер шрифта при помощи библиотеки QFont (передаем ссылку на объект типа QFont c параметрами (тип шрифта, размер шрифта)

}

void Health::decrease()
{
    healt--;
    setPlainText(QString("Health: ") + QString::number(healt));     // При каждом уменьшении жизни выводим на экран
}

int Health::getHealth()
{
    return healt;
}
