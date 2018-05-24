#ifndef PATHPRIORITYQUEUE_H
#define PATHPRIORITYQUEUE_H

#include "PathSet.h"

class PathPriorityQueue : public PathSet
{
public:
    // Constructor
    PathPriorityQueue();

    // Implementation of PathSet's function pop()
    Path pop();
};

#endif // PATHPRIORITYQUEUE_H
