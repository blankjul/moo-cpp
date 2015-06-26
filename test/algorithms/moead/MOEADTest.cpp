#include "AbstractTest.h"
#include "algorithms/moead/MOEAD.h"
#include "problems/Identity.h"
#include "problems/Kursawe.h"


class MOEADTest : public AbstractTest {
public:

    moo::Population<moo::Identity > pop{
              std::make_shared<moo::Individual<moo::Identity>>(moo::Mock{5,4})
            , std::make_shared<moo::Individual<moo::Identity>>(moo::Mock{6,1})
            , std::make_shared<moo::Individual<moo::Identity>>(moo::Mock{1,2})
    };
};

TEST_F(MOEADTest, SolveWithoutThrow) {
    moo::MOEAD<moo::Kursawe> moead;
    moo::Kursawe p;
    moead.solve(p);
}


TEST_F(MOEADTest, CalculateReferencePoint) {
    auto ref = getReferencePoint(pop);
    std::vector<double> ex {1,1};
    EXPECT_EQ(ex , ref);
}

TEST_F(MOEADTest, UpdateReferencePoint) {
    std::vector<double> ref {5,4};
    updateReferencePoint(ref, pop[2]);
    std::vector<double> ex {1,2};
    EXPECT_EQ( ex, ref);
}

TEST_F(MOEADTest, WeightetSum) {
    auto d = moo::getWeightedSum(moo::Weights{0.5,0.5},std::vector<double> {2,2} );
    EXPECT_EQ(2 , d);
}