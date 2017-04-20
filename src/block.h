#ifndef BLOCK
#define BLOCK

#include <point.h>
#include <axis.h>

struct Block {
    // This simple type represents a single block of the Rubik's chain.

    Axis::Value rotationAxis; // rotaion contraint

    Point translationVector;  // relative position to previous block in the
                              // chain
};

inline
std::ostream& operator<<(std::ostream& os, const Block& block)
{
    os << "Rotation: " << block.rotationAxis
       << ", Translation: " << block.translationVector;
    return os;
}

#endif
