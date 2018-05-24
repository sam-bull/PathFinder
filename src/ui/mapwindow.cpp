#include "mapwindow.h"
#include "ui_mapwindow.h"
#include "BFS.h"
#include "DFS.h"
#include "AStar.h"

MapWindow::MapWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MapWindow)
{
    ui->setupUi(this);
}

MapWindow::~MapWindow()
{
    delete ui;
}

void MapWindow::setSize(int newSize)
{
    fSize = newSize;
}

void MapWindow::setRoute(int sX, int sY, int gX, int gY, char alg)
{
    fSX = sX; fSY = sY; fGX = gX; fGY = gY; fAlg = alg;
}

void MapWindow::setObstacles(std::vector<Coordinate> obstacles)
{
    fObstacles = obstacles;
}

void MapWindow::setTerrain(std::vector<Coordinate> terrain)
{
    fTerrain = terrain;
}

void MapWindow::paintEvent(QPaintEvent *event)
{
    // Create the start and goal co-ordinates
    Coordinate start (fSX, fSY);
    Coordinate goal (fGX, fGY);

    // Create the path between them
    Path p;

    // Using the specified algorithm, find the path
    if (fAlg == 'b')
    {
        BFS robot (start, goal, fSize);
        robot.changeMap(fTerrain);
        robot.addObstacles(fObstacles);
        p = robot.search();
    }
    else if (fAlg == 'd')
    {
        DFS robot (start, goal, fSize);
        robot.changeMap(fTerrain);
        robot.addObstacles(fObstacles);
        p = robot.search();
    }
    else if (fAlg == 'a')
    {
        AStar robot (start, goal, fSize);
        robot.changeMap(fTerrain);
        robot.addObstacles(fObstacles);
        p = robot.search();
    }

    QPainter painter(this);


    // Define the co-ordinates of the top-left corner of the map
    const int mapX = 50;
    const int mapY = 100;
    // Define the units of height and width for the map grid
    const int unit = 30;
    // Define the length of a side of the map, in units
    const int length = fSize;

    this->resize(2*mapX + length*unit, 2*mapY + length*unit);

    // Draw the key above the map
    painter.setBrush(Qt::red);
    painter.drawText(mapX, 20, "Start");
    painter.drawRect(mapX, 22, unit/2, unit/2);
    painter.setBrush(Qt::green);
    painter.drawText(mapX+unit*2, 20, "Goal");
    painter.drawRect(mapX+unit*2, 22, unit/2, unit/2);
    painter.setBrush(Qt::blue);
    painter.drawText(mapX+unit*4, 20, "Path");
    painter.drawRect(mapX+unit*4, 22, unit/2, unit/2);

    painter.drawText(mapX, 60, "Passable                 Impassable");
    for (int i = 0; i < 10; i++)
    {
        painter.setBrush(QColor(255-25*i, 255-25*i, 255-25*i));
        painter.drawRect(mapX+unit*i/2, 62, unit/2, unit/2);
    }

    if (p.isEmpty())
        painter.drawText(mapX, mapY, "A valid path from the start to the goal was not found. \nPlease try again. \n(You may want to alter the obstacles present.)");
    else
    {
        // Draw the background of the map
        painter.setBrush(Qt::white);
        painter.drawRect(mapX, mapY, unit*length, unit*length);

        // Draw the inner horizontal and vertical lines
        for (int i = 0; i <= length; i++)
        {
            painter.drawLine(mapX, mapY+unit*i, mapX+unit*length, mapY+unit*i);
            painter.drawLine(mapX+unit*i, mapY, mapX+unit*i, mapY+unit*length);
        }

        // Draw the labels for the rows and columns of the map
        for (int i = 0; i <= length-1; i++)
        {
            painter.drawText(mapX-unit/2, mapY+unit*(i+0.5), QString::number(i+1));
            painter.drawText(mapX+unit*i+1, mapY-2, QString::number(i+1));
        }

        painter.drawText(mapX, 20, "Start");

        // Draw the terrain
        for (unsigned int i = 0; i < fTerrain.size(); i++)
        {
            painter.setBrush(QColor(255-25*fTerrain[i].getValue(), 255-25*fTerrain[i].getValue(), 255-25*fTerrain[i].getValue()));
            painter.drawRect(mapX+(fTerrain[i].getX()-1)*unit, mapY+(fTerrain[i].getY()-1)*unit, unit, unit);
        }

        // Draw the obstacles
        painter.setBrush(Qt::black);
        for (unsigned int i = 0; i < fObstacles.size(); i++)
        {
            painter.drawRect(mapX+(fObstacles[i].getX()-1)*unit, mapY+(fObstacles[i].getY()-1)*unit, unit, unit);
        }

        // Draw the start and goal
        painter.setBrush(Qt::red);
        painter.drawRect(mapX+(p.getStart().getX()-1)*unit, mapY+(p.getStart().getY()-1)*unit, unit, unit);

        painter.setBrush(Qt::green);
        painter.drawRect(mapX+(p.getEnd().getX()-1)*unit, mapY+(p.getEnd().getY()-1)*unit, unit, unit);

        // Draw the path
        painter.setBrush(Qt::blue);
        for (int i = 1; i < p.size()-1; i++)
        {
            painter.drawRect(mapX+(p.getContents()[i].getX()-1)*unit, mapY+(p.getContents()[i].getY()-1)*unit, unit, unit);
        }

        painter.drawText(mapX, mapY+unit*(length+2), "The cost of the final path is " + QString::number(p.getTotalValue()) + ".");
    }
}
