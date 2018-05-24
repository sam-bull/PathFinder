#ifndef BFS_H
#define BFS_H

#include "Algorithm.h"
#include "PathQueue.h"

class BFS : public Algorithm
{
public:
    BFS(Coordinate start, Coordinate goal, int size) : Algorithm(start, goal, size) {}
    Path search() { PathQueue PQ; return searchWith(PQ); }

};

#endif // BFS_H
