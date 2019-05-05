#include "game.h"

Game::Game()
{
    setSceneRect(0,0,800,600);   //Зададим размеры сцены действия стартовыми размерами 800 на 600
    setBackgroundBrush(QBrush(QImage(":/images/Background1.png")));

    //Создаем игрока для помещения в сцену--------
    player = new Player();
    player->setPixmap(QPixmap(":/images/Su-47_front.png").scaled(100,100,Qt::IgnoreAspectRatio)); //Cоздаем игрока из изображения
    player->setPos(width()/2 - player->pixmap().width()/2,height() - player->pixmap().height()); // Установим новую позицию для начальной точки координат player (в ширину - половину ширины view минус половина ширины player) (в высоту - высота view минус высота прямоугольника player)
    //Делаем объек игрок в фокусе для отслеживания события нажатия клавиши
    player->setFlag(QGraphicsItem::ItemIsFocusable);  // Установим флаг на фокус для получения события нажатия клавиши в QGraphicsItem::keyPressEvent() и QGraphicsItem::keyReleaseEvent().
    player->setFocus();                               //Дадим объекту  фокус ввода с клавиатуры
    //Добавим объект(игрока) в сцену---------------------
    addItem(player);                           //Вызовим метод для добавления предмета и передадим в него созданный предмет(rect)

    //Создаем объект score в памяти и добавляем его в сцену------
    score = new Score();
    addItem(score);
    //Создаем объект health в памяти и добавляем его в сцену-----
    health = new Health();
    health->setPos(health->x(),health->y() + 25);       //Установим первоночальную позицию для объекта health (ниже по оси y на 25 пикселей)
    addItem(health);

    //Создание врагов------------------------------
    timer = new QTimer();                           //Создадим объект timer для ведения отсчета появления врага
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(Spawn()));  //Создаем связь (connect) между объектом timer (типа QTimer) его сигналом (timeout()) и объектом player, его слот методом spawn (создание врагов)
    timer->start(2000);                 //Устанавливаем таймер для отсчета 2000мсек. (Каждые 2000мсек будет вызываться слот метод spawn() у объекта player

    //Проигрывание фоновой музыки-----------------
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/BG_turbina.mp3")); // При помощи метода QUrl можем установить любой путь до файла звука, мы указываем папку с проектом для того, что бы включить звук в исполняемый фаил
    music->play();
}

Game::~Game()
{
    delete timer;
    delete music;
}


