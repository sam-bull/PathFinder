#include "pathfinder.h"
#include "ui_pathfinder.h"
#include "mapwindow.h"

PathFinder::PathFinder(QWidget *parent) : QMainWindow(parent), ui(new Ui::PathFinder)
{
    ui->setupUi(this);
    fObstacles = std::vector<Coordinate>();
}

PathFinder::~PathFinder()
{
    delete ui;
}

void PathFinder::on_find_clicked()
{
    // Get the values of the start co-ordinate
    int startX = ui->startX->text().toInt();
    int startY = ui->startY->text().toInt();
    // Get the values of the goal co-ordinate
    int goalX = ui->goalX->text().toInt();
    int goalY = ui->goalY->text().toInt();

    int mapSize = ui->mapSize->text().toInt();

    // Check that the map size is valid
    if (mapSize > 0 && mapSize < 16)
    {
        // Check that an algorithm has been selected
        if (fAlg > 0)
        {
            // Check that the start and goal co-ordinates are valid
            if (startX > 0 && startX <= mapSize &&
                    startY > 0 && startY <= mapSize &&
                    goalX > 0 && goalX <= mapSize &&
                    goalY > 0 && goalY <= mapSize)
            {
                char c;
                switch (fAlg)
                {
                case 1 : c = 'b';
                case 2 : c = 'd';
                case 3 : c = 'a';
                }
                ui->warningLabel->setText(" ");
                MapWindow map;
                map.setModal(true);
                map.setSize(mapSize);
                map.setRoute(startX, startY, goalX, goalY, c);
                map.setTerrain(fTerrain);
                map.setObstacles(fObstacles);
                map.exec();
            }
            else ui->warningLabel->setText("Those are not valid co-ordinates. Make sure you enter values from 1 to " + QString::number(mapSize) + " inclusive in the form (x, y).");
        }
        else ui->warningLabel->setText("You must select an algorithm first!");
    }
    else ui->warningLabel->setText("Map size must be between 0 and 16 exclusive.");


}

void PathFinder::on_selectAlgorithm_currentIndexChanged(int index)
{
    fAlg = index;
}

void PathFinder::on_addObst_clicked()
{
    // Get the values of the start co-ordinate
    int x = ui->newObstX->text().toInt();
    int y = ui->newObstY->text().toInt();

    // Check that they are valid
    if (x < 1 || x > 10 || y < 1 || x > 10)
        ui->obstWarning->setText("Those are not valid co-ordinates. Make sure you enter values from 1 to 10 inclusive in the form (x, y).");

    else
    {
        ui->obstWarning->setText("");

        // Add the obstacle co-ordinates to fObstacles
        fObstacles.insert(fObstacles.end(), Coordinate(x, y));

        // Reset the text entry boxes
        ui->newObstX->setText("");
        ui->newObstY->setText("");

        // Add the new obstacle to the list displayed to the user
        ui->obstList->append(QString::fromStdString(fObstacles[fObstacles.size()-1].toString()) + "\n");
    }
}

void PathFinder::on_resetObst_clicked()
{
    fObstacles.clear();
    ui->obstList->setText("");
}

void PathFinder::on_addTerrain_clicked()
{
    // Get the values of the start co-ordinate
    int x = ui->newTerrainX->text().toInt();
    int y = ui->newTerrainY->text().toInt();
    QString value_s = ui->newTerrainValue->text();
    int value = value_s.toInt();

    // Check that they are valid
    if (x < 1 || x > 10 || y < 1 || x > 10)
        ui->terrainWarning->setText("Those are not valid co-ordinates. Make sure you enter values from 1 to 10 inclusive in the form (x, y).");
    else if (value < 1 || value > 10)
        ui->terrainWarning->setText("The value of the terrain must be between 1 (most passable) to 10 (least passable)");
    else
    {
        ui->terrainWarning->setText("");

        fTerrain.insert(fTerrain.end(), Coordinate(x, y, value));

        ui->newTerrainX->setText("");
        ui->newTerrainY->setText("");
        ui->newTerrainValue->setText("");

        ui->terrainList->append(QString::fromStdString(fTerrain[fTerrain.size()-1].toString()) + ", " + value_s + "\n");
    }
}

void PathFinder::on_resetTerrain_clicked()
{
    fTerrain.clear();
    ui->terrainList->setText("");
}

// Preset 0: no obstacles
void PathFinder::on_preset0_toggled(bool checked)
{
    if (checked)
    {
        fObstacles.clear();
        ui->obstList->setText("");
        fTerrain.clear();
        ui->terrainList->setText("");
    }
}

// Preset 1: obstacles, no terrain
void PathFinder::on_preset1_toggled(bool checked)
{
    if (checked)
    {
        // Remove any obstacles already entered
        fObstacles.clear();
        ui->obstList->setText("");

        int x = 0, y = 0;

        // Set the value of 10 randomly selected co-ordinates to be an obstacle
        for (int i = 0; i < 10; i++)
        {
            x = 10*((double)std::rand()/RAND_MAX) + 1;
            y = 10*((double)std::rand()/RAND_MAX) + 1;
            fObstacles.insert(fObstacles.end(), Coordinate(x, y));
            ui->obstList->append(QString::fromStdString(Coordinate(x, y).toString()) + "\n");
        }

        // Remove any terrain changes
        fTerrain.clear();
        ui->terrainList->setText("");
    }
}

// Preset 2: no obstacles, varying terrain
void PathFinder::on_preset2_toggled(bool checked)
{
    if (checked)
    {
        // Remove any obstacles
        fObstacles.clear();
        ui->obstList->setText("");

        // Remove any terrain changes already entered
        fTerrain.clear();
        ui->terrainList->setText("");

        int x = 0, y = 0, value = 0;

        // Set the value of 20 randomly selected co-ordinates to be a randomly selected value
        for (int i=0; i<20; i++)
        {
            x = 10*((double)std::rand()/RAND_MAX) + 1;
            y = 10*((double)std::rand()/RAND_MAX) + 1;
            value = 10*((double)std::rand()/RAND_MAX) + 1;
            fTerrain.insert(fTerrain.end(), Coordinate(x, y, value));
            ui->terrainList->append(QString::fromStdString(Coordinate(x, y).toString()) + ", " + value + "\n");
        }
    }
}

void PathFinder::on_preset3_toggled(bool checked)
{
    if (checked)
    {
        // Remove any obstacles already entered
        fObstacles.clear();
        ui->obstList->setText("");

        int x = 0, y = 0, value = 0;

        // Set the value of 10 randomly selected co-ordinates to be an obstacle
        for (int i = 0; i < 10; i++)
        {
            x = 10*std::rand()/RAND_MAX + 1;
            y = 10*std::rand()/RAND_MAX + 1;
            fObstacles.insert(fObstacles.end(), Coordinate(x, y));
            ui->obstList->append(QString::fromStdString(Coordinate(x, y).toString()) + "\n");
        }

        // Remove any terrain changes already entered
        fTerrain.clear();
        ui->terrainList->setText("");

        // Set the value of 20 randomly selected co-ordinates to be a randomly selected value
        for (int i = 0; i < 20; i++)
        {
            x = 10*((double)std::rand()/RAND_MAX) + 1;
            y = 10*((double)std::rand()/RAND_MAX) + 1;
            value =  10*((double)std::rand()/RAND_MAX) + 1;
            fTerrain.insert(fTerrain.end(), Coordinate(x, y, value));
            ui->terrainList->append(QString::fromStdString(Coordinate(x, y).toString()) + ", " + value + "\n");
        }
    }
}

void PathFinder::on_preset4_toggled(bool checked)
{
    if (checked)
    {
        // Remove any obstacles already entered
        fObstacles.clear();
        ui->obstList->setText("");

        int x = 0, y = 0, value = 0;

        // Set the value of 10 randomly selected co-ordinates to be an obstacle
        for (int i = 0; i < 10; i++)
        {
            x = 10*((double)std::rand()/RAND_MAX) + 1;
            y = 10*((double)std::rand()/RAND_MAX) + 1;
            fObstacles.insert(fObstacles.end(), Coordinate(x, y));
            ui->obstList->append(QString::fromStdString(Coordinate(x, y).toString()) + "\n");
        }

        // Remove any terrain changes already entered
        fTerrain.clear();
        ui->terrainList->setText("");

        // Set the value of 30 randomly selected co-ordinates to be a randomly selected value
        for (int i = 0; i < 30; i++)
        {
            x = 10*((double)std::rand()/RAND_MAX) + 1;
            y = 10*((double)std::rand()/RAND_MAX) + 1;
            value = 10*((double)std::rand()/RAND_MAX) + 1;
            fTerrain.insert(fTerrain.end(), Coordinate(x, y, value));
            ui->terrainList->append(QString::fromStdString(Coordinate(x, y).toString()) + ", " + value + "\n");
        }
    }

}
