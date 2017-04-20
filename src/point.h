#ifndef POINT
#define POINT

#include <iostream>

struct Point {
    // This simple type represents a point or vector in cartesian space.

    int x, y, z;
};

inline
std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "[" << point.x << ", " << point.y << ", " << point.z << "]";
    return os;
}

inline
bool operator==(const Point& lhs, const Point& rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

#endif
