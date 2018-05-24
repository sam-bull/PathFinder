#ifndef ALGORITHM_H
#define ALGORITHM_H

#ifndef PASSABLE
#define PASSABLE 1
#endif // PASSABLE

#ifndef IMPASSABLE
#define IMPASSABLE -1
#endif // IMPASSABLE

#include <iostream>

#include "coordinate.h"
#include "Path.h"
#include "PathSet.h"
#include "PathPriorityQueue.h"
#include "PathStack.h"
#include "PathQueue.h"

class Algorithm
{
public:
    // Constructor
    Algorithm(Coordinate start, Coordinate goal, int size);
    // Function to find a path between start and goal
    virtual Path search() = 0;
    // Function to add obstacles to the map
    void addObstacles(std::vector<Coordinate> obstacles);
    // Function to change the terrain of the map
    void changeMap(std::vector<Coordinate> terrain);

    template<typename T> Path searchWith(T pathSet)
    {
        // Check both start and goal are accessible
        if (fSpace[fStart.getX()][fStart.getY()] == -1 || fSpace[fGoal.getX()][fGoal.getY()] == -1) return Path();

        Path pStart;

        // Add the starting co-ordinate
        fStart.setValue(fSpace[fStart.getX()][fStart.getY()]);
        pStart.add(fStart);
        pathSet.push(pStart);

        // Create a vector of Coordinates to store the points that have already been visited, so we don't visit them again
        std::vector <Coordinate> V;
        V.insert(V.end(), fStart);

        // While there are still points yet to check
        while(!pathSet.isEmpty())
        {
            // Get the next point to check from the front of the queue
            Path pCurrent = pathSet.pop();
            Coordinate cCurrent = pCurrent.getEnd();

            // Check if it is the goal
            if (cCurrent == fGoal)
                return pCurrent;

            // For point that is adjacent to the current point...
            int i;
            for (i = 1; i <= 4; ++i)
            {
                Coordinate next = cCurrent.getAdjacent(i);
                next.setValue(fSpace[next.getX()][next.getY()]);

                // Check if it is reachable and has not already been checked
                if (!isIn(V, next) && fSpace[next.getX()][next.getY()] > 0)
                {
                    // Add it to the list of points visited (even though we haven't technically visited it yet, we will, and don't want to add it to the list of points to check twice)
                    V.insert(V.end(), next);

                    // Add it to the list of points to check
                    Path pNext = pCurrent;
                    pNext.add(next);
                    pathSet.push(pNext);
                }
            }
        }
        // If the code has reached this point, something has gone wrong. Return an empty Coordinate.
        return Path();
    }

protected:
    Coordinate fStart;
    Coordinate fGoal;
    int fSpace[10][10];
    // Function to deternime whether  a Coordinate is in a vector of Coordinates
    bool isIn(std::vector<Coordinate> v, Coordinate c);
};

#endif // ALGORITHM_H
