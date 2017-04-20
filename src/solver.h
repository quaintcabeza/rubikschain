#ifndef SOLVER
#define SOLVER

#include <partialsolution.h>
#include <point.h>
#include <rubikschain.h>
#include <space.h>
#include <deque>

class Solver {
    // This mechanism solves a specified Rubik's chain to fit into a gived
    // bounded cuboid.

    std::deque<PartialSolution> partialSolutions_;
    Point bounds_;

  public:
    // CREATORS
    Solver(const RubiksChain& rubiksChain, const Point& bounds);
        // Created a mechanism that will solve the specified Rubik's chain such
        // that all the blocks lie within the cuboid represented by the
        // specfied 'bounds'.

    // MANIPULATORS
    int solve(Space *solution);
        // Load into the specified 'solution' the solution to the Rubik's
        // chain.  Return 0 on success or non-zero if no solution is found.
};

#endif
