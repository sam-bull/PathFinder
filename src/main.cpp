#include "pathfinder.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PathFinder w;
    w.show();

    return a.exec();
}
