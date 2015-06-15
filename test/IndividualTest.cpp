#include "AbstractTest.h"
#include "model/Individual.h"
#include "problems/Identity.h"
#include <memory>

class IndividualTest : public AbstractTest {
public:
    moo::Identity k;
    moo::IndividualPtr<std::vector<double>> a = createIndAndEvaluate(std::vector<double>{3,3,3}, k);
    moo::IndividualPtr<std::vector<double>> b = createIndAndEvaluate(std::vector<double>{3,3,3}, k);

};


TEST_F(IndividualTest, CheckForEqualityTrue) {
    EXPECT_TRUE(a->isEqual(b));
}

TEST_F(IndividualTest, CheckForEqualityFalse) {
    auto x = createIndAndEvaluate(std::vector<double>{0,0,0}, k);
    EXPECT_FALSE(a->isEqual(x));
}

TEST_F(IndividualTest, IsDominatingOtherTrue) {
    auto x = createIndAndEvaluate(std::vector<double>{3,3,4}, k);
    EXPECT_TRUE(a->isDominating(x));
    EXPECT_TRUE(x->isDominatedBy(a));
}

TEST_F(IndividualTest, IsNotDominatingCauseEqual) {
    EXPECT_FALSE(a->isDominating(b));
}