#ifndef SPACE
#define SPACE

#include <unit.h>
#include <block.h>
#include <point.h>
#include <vector>
#include <iostream>

class Space {
    // This type represents an arrangement of blocks in 3D space.

    typedef std::vector<Unit> Units;

    Units units_;      // Sequence of block+position
    Point lowerBound_; // Current lower bound
    Point upperBound_; // Current upper bound

  public:
    // CREATORS
    Space();

    // MANIPULATORS
    void append(const Unit& unit);
        // Add the specified 'unit' to this space.

    // ACCESSORS
    bool isEmpty(const Point& position) const;
        // Return whether the specified 'position' is occupied by a block.

    bool isBounded(const Point& bounds) const;
        // Return whether the distribution of the blocks in this space is
        // bounded by the specified 'bounds', i.e, whether the blocks are all
        // within the cuboid specified by 'bounds'.

    const Unit& last() const;
        // Return the unit that was last appended to this space.

    void print(std::ostream& os = std::cout) const;
        // Print this object to the specified stream.

    void printInstructions(std::ostream& os = std::cout) const;
        // Print human friendly instructions for arranging the Rubik's chain
        // into the distribution represented by this class.
};

inline
std::ostream& operator<<(std::ostream& os, const Space& obj)
{
    obj.print(os);
    return os;
}

#endif
