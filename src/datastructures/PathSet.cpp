#include "PathSet.h"

PathSet::PathSet()
{
    // Upon initialisation, the PathSet is empty
    fEmpty = true;
}

void PathSet::push(Path p)
{
    // If the PathSet was previously empty, it no longer is now
    if (fEmpty)
        fEmpty = false;

    // Add the vector to fContents
    fContents.insert(fContents.end(), p);
}
