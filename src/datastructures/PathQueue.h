#ifndef PATHQUEUE_H
#define PATHQUEUE_H

#include "PathSet.h"

class PathQueue : public PathSet
{
public:
    // Constructor
    PathQueue();

    // Implementation of PathSet's function pop()
    Path pop();
};

#endif // PATHQUEUE_H
