#include "AbstractTest.h"
#include "algorithms/nsgaII/NSGAII.h"
#include "algorithms/nsgaII/NSGAIISettings.h"
#include "problems/Identity.h"


class NSGAIITest : public AbstractTest {
public:
};

TEST_F(NSGAIITest, SolveWithoutThrow) {
    moo::NSGAII<moo::NSGAIISettings<moo::Identity>> nsga;
    moo::Identity p;
    nsga.solve(p);
}
