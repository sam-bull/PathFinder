#ifndef PATHSTACK_H
#define PATHSTACK_H

#include "PathSet.h"

class PathStack : public PathSet
{
public:
    // Constructor
    PathStack();

    // Implementation of PathSet's function pop()
    Path pop();
};

#endif // PATHSTACK_H
