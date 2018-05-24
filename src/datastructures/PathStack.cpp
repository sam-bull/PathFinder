#include <stdexcept>
#include "PathStack.h"
#include <iostream>

PathStack::PathStack() : PathSet()
{}

Path PathStack::pop()
{
    // If the set is empty, there is nothing to return, so throw an exception
    if (fEmpty)
        throw std::invalid_argument( "PathQueue is empty" );

    // Get the most recent value added to the set
    Path last = fContents[fContents.size()-1];

    // Remove it from fContents, so that the second-most recent value added is now the most recent
    fContents.erase(fContents.end());

    // Return it
    return last;
}
