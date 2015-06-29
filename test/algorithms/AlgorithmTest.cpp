#include "AbstractTest.h"
#include "algorithms/nsgaII/NSGAII.h"
#include "problems/Identity.h"
#include "problems/Kursawe.h"


class AlgorithmTest : public AbstractTest {
public:
};

TEST_F(AlgorithmTest, SolveWithoutThrow) {
    moo::Kursawe p;
    moo::NSGAII<moo::Kursawe> solver(p);
    solver.solve();
}

