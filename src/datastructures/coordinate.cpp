#include "Coordinate.h"
#include <sstream>

Coordinate::Coordinate()
{
    fX = 0;
    fY = 0;
    fValue = 1;
}

Coordinate::Coordinate(int x, int y)
{
    fX = x;
    fY = y;
    fValue = 1;
}

Coordinate::Coordinate(int x, int y, int value)
{
    fX = x;
    fY = y;
    fValue = value;
}

std::string Coordinate::toString()
{
    std::stringstream ss1, ss2;
    ss1 << fX;
    ss2 << fY;
    return "(" + ss1.str() + ", " + ss2.str() + ")";
}



Coordinate Coordinate::getAdjacent(int direction)
{
    switch (direction)
    {
    case north : return Coordinate(fX, fY-1);
    case east  : return Coordinate(fX+1, fY);
    case south : return Coordinate(fX, fY+1);
    case west  : return Coordinate(fX-1, fY);
    }

    return Coordinate(0, 0);
}

bool Coordinate::operator ==(Coordinate c)
{
    if (fX == c.getX() && fY == c.getY())
        return true;
    return false;
}
