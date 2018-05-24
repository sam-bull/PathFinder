#include "Algorithm.h"

Algorithm::Algorithm(Coordinate start, Coordinate goal, int size)
{
    // Set the start and goal
    fStart = start;
    fGoal = goal;
    // Create the map as a size x size grid
    int i, j;
    for (i = 0; i < size+2; ++i)
        for (j = 0; j < size+2; ++j)
        {
            if (i == 0 || i == size+1 || j == 0 || j == size+1)
                fSpace[i][j] = IMPASSABLE;
            else fSpace[i][j] = PASSABLE;
        }
}

Path Algorithm::search()
{
    return Path();
}

void Algorithm::addObstacles(std::vector<Coordinate> obstacles)
{
    // For each Coordinate in obstacles, set the co-ordinate for it in fSpace to be impassable
    std::vector<Coordinate>::iterator it;
    int i = 0;
    for (it = obstacles.begin(); it < obstacles.end(); ++it, ++i)
    {
        fSpace[obstacles[i].getX()][obstacles[i].getY()] = IMPASSABLE;
    }

}

void Algorithm::changeMap(std::vector<Coordinate> terrain)
{
    // For each Coordinate in terrain, set the co-ordinate for it in fSpace to have the corresponding value
    std::vector<Coordinate>::iterator it;
    int i = 0;
    for (it = terrain.begin(); it < terrain.end(); ++it, ++i)
    {
        fSpace[terrain[i].getX()][terrain[i].getY()] = terrain[i].getValue();
    }
}

// Function to find a path from the start to the goal in space


bool Algorithm::isIn(std::vector <Coordinate> v, Coordinate c)
{
    int i = 0;
    std::vector<Coordinate>::iterator it;
    for (it = v.begin() ; it < v.end(); ++it, ++i)
        if (v[i] == c)
            return true;
    return false;
}
