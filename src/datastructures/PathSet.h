#ifndef PATHSET_H
#define PATHSET_H

#include <vector>

#include "Coordinate.h"
#include "Path.h"

// Abstract class to define a set of paths. Each path is a vector of Coordinates.
class PathSet
{
public:
    // Constructor
    PathSet();

    // Function to determine if the set is empty
    bool isEmpty() { return fEmpty; }

    // Function to add a vector of Coordinates to the set
    void push(Path p);

    // Function to return the "first" vector in the set
    // Implemented differently in each type of CoordinateSet as "first" is classed differently
    virtual Path pop() = 0;

protected:
    bool fEmpty;
    std::vector <Path> fContents;
};

#endif // PATHSET_H
