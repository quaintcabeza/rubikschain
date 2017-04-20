#ifndef UNIT
#define UNIT

#include <block.h>
#include <point.h>

struct Unit {
    // This simple type represents a Rubik's chain block and its position in
    // space.

    Point position;
    Block block;
};

inline
std::ostream& operator<<(std::ostream& os, const Unit& unit)
{
    os << "Position: " << unit.position
       << ", Block: " << unit.block;
    return os;
}

#endif
