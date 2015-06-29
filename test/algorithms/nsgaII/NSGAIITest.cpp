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
    moo::Kursawe p;

    moo::NSGAII<moo::Kursawe> nsga(p);

    nsga.solve();

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"printf: "<< duration <<'\n';


}

