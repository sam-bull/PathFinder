#include "PathPriorityQueue.h"
#include <stdexcept>

PathPriorityQueue::PathPriorityQueue() : PathSet()
{}

Path PathPriorityQueue::pop()
{
    // If the set is empty, there is nothing to return, so throw an exception
    if (fEmpty)
        throw std::invalid_argument( "PathPriorityQueue is empty" );

    // Get the lowest-value Path in the set
    Path lowest = fContents[0];
    int position = 0;
    int i = 0;
    std::vector<Path>::iterator it;
    for (it = fContents.begin() ; it < fContents.end(); ++it, ++i)
    {
        if (fContents[i].getTotalValue() < lowest.getTotalValue())
        {
            lowest = fContents[i];
            position = i;
        }
    }
    // Remove it from fContents,
    fContents.erase(fContents.begin()+position);

    // Return it
    return lowest;
}
