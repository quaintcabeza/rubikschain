#include <solver.h>
#include <vectorutil.h>

// CREATORS
Solver::Solver(const RubiksChain& chain, const Point& bounds)
:bounds_(bounds)
{
    Space space;
    partialSolutions_.push_back({ space, chain });
}

// MANIPULATORS
int Solver::solve(Space *solution)
{
    if (partialSolutions_.empty()) {
        // Termination condition
        return -1;                                                    // RETURN
    }

    // Pop leading partial solution.  If no more blocks left in the Rubik's
    // chain, we're done.
    PartialSolution partialSolution = partialSolutions_.front();
    partialSolutions_.pop_front();
    Space& space = partialSolution.space;
    RubiksChain& chain = partialSolution.rubiksChain;
    if (chain.empty()) {
        // Termination condition
        *solution = space;
        return 0;                                                     // RETURN
    }

    // Pop leading block from chain, and check if it fits
    const Block block = chain.pop();
    const Point position = VectorUtil::getPosition(block,
                                                   space.last().position);

    if (!space.isEmpty(position)) {
        // Bail out
        return solve(solution);                                       // RETURN
    }
    space.append({position, block});
    if (!space.isBounded(bounds_)) {
        // Bail out
        return solve(solution);                                       // RETURN
    }

    // Block fits in solution space. Add this space to queue of partial
    // solutions, along with all the rotations of the constraint that's
    // possible.
    partialSolutions_.push_back({ space, chain }); // No rotation
    if (block.rotationAxis != chain.peek().rotationAxis) {
        RubiksChain rotatedChain = chain;
        for (unsigned int i = 0; i < 3; ++i) { // add three rotations
            rotatedChain.rotate(block.rotationAxis);
            partialSolutions_.push_back({ space, rotatedChain });
        }
    }

    // Continue searching for solution
    return solve(solution);
}
