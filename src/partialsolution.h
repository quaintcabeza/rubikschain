#ifndef PARTIALSOLUTION
#define PARTIALSOLUTION

#include <space.h>
#include <rubikschain.h>

struct PartialSolution {
    // This simple type represents a partial solution space, and the Rubik's
    // chain with constrained blocks that need to be fit in the space.

    Space space;
    RubiksChain rubiksChain;
};

#endif
