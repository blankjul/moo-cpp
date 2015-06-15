#include "AbstractTest.h"
#include "algorithm/NSGAII.h"
#include "problems/Kursawe.h"


class NSGAIITest : public AbstractTest {
public:
    moo::Kursawe k;
};

TEST_F(NSGAIITest, SolveWithoutThrow) {
    moo::NSGAII<moo::Kursawe> nsga;
    nsga.solve(k);
}
