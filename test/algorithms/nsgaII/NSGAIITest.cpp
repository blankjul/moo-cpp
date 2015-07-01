#include "AbstractTest.h"
#include "algorithms/nsgaII/NSGAII.h"
#include "problems/Kursawe.h"


class NSGAIITest : public AbstractTest {
public:
};

TEST_F(NSGAIITest, SolveWithoutThrow) {

    moo::Kursawe p;
    moo::NSGAII<moo::Kursawe> nsga(p);
    nsga.maxGeneration = 1;
    nsga.populationSize = 100;
    nsga.solve();


}

