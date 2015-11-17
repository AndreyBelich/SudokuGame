#include <QApplication>
#include "gamewidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWidget widget;
    widget.show();
    return a.exec();
}
