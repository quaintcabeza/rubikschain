#ifndef RUBIKSCHAIN
#define RUBIKSCHAIN

#include <point.h>
#include <block.h>
#include <axis.h>
#include <deque>
#include <iostream>

class RubiksChain {
    // This class represents the Rubik's chain as a sequence of constrained
    // blocks.

    typedef std::deque<Block> BlockQueue;
    BlockQueue blocks_;

  public:
    // MANIPULATORS
    void append(Axis::Value axis, int direction = 1);
        // Append a new block to the Rubik's chain along the specified 'axis'
        // and in the specified 'direction'.  Note that 'direction' is '1' or
        // '-1'.

    Block pop();
        // Pop and return the first block in the Rubik's chain.

    void rotate(Axis::Value about);
        // Rotate all blocks in this chain about the specified axis.

    // ACCESSORS
    Block peek() const;
        // Return the first block in the Rubik's chain.

    bool empty() const;
        // Return 'true' if there is at least one block in this chain,
        // otherwise return 'false'.

    void print(std::ostream& os = std::cout) const;
        // Print this object to the specified 'os'.
};

inline
std::ostream& operator<<(std::ostream& os, const RubiksChain& obj)
{
    obj.print(os);
    return os;
}

#endif
