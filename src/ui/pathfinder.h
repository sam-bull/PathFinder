#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <QMainWindow>

#include "BFS.h"
#include "DFS.h"
#include "AStar.h"

namespace Ui {
class PathFinder;
}

class PathFinder : public QMainWindow
{
    Q_OBJECT

public:
    explicit PathFinder(QWidget *parent = 0);
    ~PathFinder();

private slots:
    void on_find_clicked();
    void on_selectAlgorithm_currentIndexChanged(int index);

    void on_addObst_clicked();

    void on_resetObst_clicked();

    void on_addTerrain_clicked();

    void on_resetTerrain_clicked();

    void on_preset0_toggled(bool checked);

    void on_preset1_toggled(bool checked);

    void on_preset2_toggled(bool checked);

    void on_preset3_toggled(bool checked);

    void on_preset4_toggled(bool checked);

private:
    Ui::PathFinder *ui;
    int fAlg;
    std::vector<Coordinate> fObstacles;
    std::vector<Coordinate> fTerrain;
};

#endif // PATHFINDER_H
