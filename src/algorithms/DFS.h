#ifndef DFS_H
#define DFS_H

#include "Algorithm.h"
#include "PathStack.h"

class DFS : public Algorithm
{
public:
    DFS(Coordinate start, Coordinate goal, int size) : Algorithm(start, goal, size) {}
    Path search() { PathStack PS; return searchWith(PS); }
};

#endif // DFS_H
