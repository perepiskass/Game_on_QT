#include <QApplication>
#include <viewgame.h>


ViewGame* vgame;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    vgame = new ViewGame();
    vgame->show();

    return a.exec();
}
