#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem (parent)     //Копируем конструктор по умолчанию из класса родителя QGraphicsTextItem
{
    score = 0;          // Присваиваем переменной score первоночальное значение

    setPlainText(QString("Score: ") + QString::number(score));     // Зададим строку для вывода на экран у созданного объекта при помощи родительского метода
    setDefaultTextColor(Qt::red);                      //Установим цвет по умолчанию для текста red
    setFont(QFont("times",16));         //Установим тип и размер шрифта при помощи библиотеки QFont (передаем ссылку на объект типа QFont c параметрами (тип шрифта, размер шрифта)

}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ") + QString::number(score));     // При каждом увеличении выводим на экран
}

int Score::getScore()
{
    return score;
}
