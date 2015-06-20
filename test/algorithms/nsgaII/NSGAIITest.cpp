#include "AbstractTest.h"
#include "algorithms/nsgaII/NSGAII.h"
#include "problems/Kursawe.h"


class NSGAIITest : public AbstractTest {
public:
};

TEST_F(NSGAIITest, SolveWithoutThrow) {
    std::clock_t start;
    double duration;

    start = std::clock();
    moo::NSGAII<moo::Kursawe> nsga;
    moo::Kursawe p;

    nsga.solve(p);

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"printf: "<< duration <<'\n';


}

