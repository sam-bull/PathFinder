#ifndef ASTAR_H
#define ASTAR_H

#include "Algorithm.h"
#include "PathPriorityQueue.h"

class AStar : public Algorithm
{
public:
    AStar(Coordinate start, Coordinate goal, int size) : Algorithm(start, goal, size) {}
    Path search() { PathPriorityQueue PPQ; return searchWith(PPQ); }
};

#endif // ASTAR_H
