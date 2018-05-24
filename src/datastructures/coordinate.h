#ifndef COORDINATE_H
#define COORDINATE_H

#include <string>

/*
 * Class to define a co-ordinate with a position (x, y) and a value
 */

class Coordinate
{
public:
    // Default constructor; sets position to (0, 0) and fValue to 1
    Coordinate();
    // Position constructor; sets position to (x, y) and fValue to 1
    Coordinate(int x, int y);
    // Full constructor; sets position to (x, y) and fValue to value
    Coordinate(int x, int y, int value);

    // Getters
    int getX() { return fX; }
    int getY() { return fY; }
    int getValue() { return fValue; }

    // Setter
    void setValue(int newValue) { fValue = newValue; }

    // ToString
    std::string toString();

    enum direction{north=1, east=2, south=3, west=4};

    // Function to return the Coordinate to the north/east/south/west of this Coordinate
    Coordinate getAdjacent(int direction);

    // Operators
    bool operator == (Coordinate c);
    Coordinate operator = (Coordinate c) { fX = c.getX(); fY = c.getY(); fValue = c.getValue(); return c; }

private:
    // (fX, fY) is the position of the Coordinate in space
    int fX;
    int fY;
    // fValue is the value of the Coordinate
    int fValue;
};

#endif // COORDINATE_H
