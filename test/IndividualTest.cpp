#include "AbstractTest.h"
#include "model/Individual.h"
#include "problems/Identity.h"
#include <memory>

class IndividualTest : public AbstractTest {
public:
    std::shared_ptr<moo::Identity> k = std::make_shared<moo::Identity> ();
    typedef moo::Individual<> SomeIndividual;
    SomeIndividual get() {
        SomeIndividual i(k, std::vector<double>{3,3,3});
        return i;
    }
};

TEST_F(IndividualTest, CreateIndividualNoError) {
    SomeIndividual i(k, std::vector<double>{3,3,3});
    EXPECT_EQ(3, i.evaluate().size());
}

TEST_F(IndividualTest, CheckForEqualityTrue) {
    SomeIndividual i1 = get();
    SomeIndividual i2 = get();
    EXPECT_TRUE(i1.isEqual(i2));
}

TEST_F(IndividualTest, CheckForEqualityFalse) {
    SomeIndividual i1 = get();
    SomeIndividual i2(k, std::vector<double>{0,0,0});
    EXPECT_FALSE(i1.isEqual(i2));
}

TEST_F(IndividualTest, IsDominatingOtherTrue) {
    SomeIndividual i1 = get();
    SomeIndividual i2(k, std::vector<double>{3,3,4});
    EXPECT_TRUE(i1.isDominating(i2));
    EXPECT_TRUE(i2.isDominatedBy(i1));
}

TEST_F(IndividualTest, IsNotDominatingCauseEqual) {
    SomeIndividual i1 = get();
    SomeIndividual i2 = get();
    EXPECT_FALSE(i1.isDominating(i2));
}