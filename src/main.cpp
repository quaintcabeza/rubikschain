#include <rubikschain.h>
#include <vectorutil.h>
#include <space.h>
#include <solver.h>
#include <iostream>

using namespace std;
int main()
{
    RubiksChain chain;
    chain.append(Axis::X);
    chain.append(Axis::X);
    chain.append(Axis::Y);
    chain.append(Axis::X);
    chain.append(Axis::Y);
    chain.append(Axis::Y);
    chain.append(Axis::X);
    chain.append(Axis::Y);
    chain.append(Axis::Y);
    chain.append(Axis::X);
    chain.append(Axis::Y);
    chain.append(Axis::X);
    chain.append(Axis::X);
    chain.append(Axis::Y);
    chain.append(Axis::Y);
    chain.append(Axis::X);
    chain.append(Axis::Y);
    chain.append(Axis::X);
    chain.append(Axis::Y);
    chain.append(Axis::Y);
    chain.append(Axis::X);
    chain.append(Axis::X);
    chain.append(Axis::Y);
    chain.append(Axis::Y);
    chain.append(Axis::X);
    chain.append(Axis::X);

    Solver solver(chain, { 3, 3, 3 });
    Space solution;
    int rc = solver.solve(&solution);
    if (0 == rc) {
        cout << "Solution: \n"
             << solution << endl << endl;
        cout << "Instructions: \n";
        solution.printInstructions();
        cout << endl;
    }
    else {
        cout << "No solution found" << endl;
    }
}
