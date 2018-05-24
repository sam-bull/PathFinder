#include "PathQueue.h"
#include <stdexcept>

PathQueue::PathQueue() : PathSet()
{}

Path PathQueue::pop()
{
    // If the set is empty, there is nothing to return, so throw an exception
    if (fEmpty)
        throw std::invalid_argument( "PathQueue is empty" );

    // Get the least recent value added to the set
    Path first = fContents[0];

    // Remove it from fContents, so that the second-least recent value added is now the least recent
    fContents.erase(fContents.begin());

    // Return it
    return first;
}
