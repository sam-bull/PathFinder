#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

#include "Path.h"

namespace Ui {
class MapWindow;
}

class MapWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MapWindow(QWidget *parent = 0);
    ~MapWindow();
    void setSize(int newSize);
    void setRoute(int sX, int sY, int gX, int gY, char alg);
    void setObstacles(std::vector<Coordinate> obstacles);
    void setTerrain(std::vector<Coordinate> terrain);

private:
    Ui::MapWindow *ui;

    int fSize;
    int fSX, fSY, fGX, fGY;
    char fAlg;
    std::vector<Coordinate> fObstacles;
    std::vector<Coordinate> fTerrain;

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MAPWINDOW_H
