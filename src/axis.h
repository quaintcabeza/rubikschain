#ifndef AXIS
#define AXIS

#include <iostream>

struct Axis {
    // This enum identifies 3D cartesian axes.

    enum Value { X, Y, Z};
};

inline
std::ostream& operator<<(std::ostream& os, const Axis::Value& axis)
{
    switch(axis) {
        case Axis::X: {
            os << "X";
        } break;
        case Axis::Y: {
            os << "Y";
        } break;
        case Axis::Z: {
            os << "Z";
        } break;
    }
    return os;
}

#endif
