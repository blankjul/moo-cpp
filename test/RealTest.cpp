#include "AbstractTest.h"
#include "variables/Real.h"


class RealTest : public AbstractTest {
public:
    moo::Real  r = moo::Real(2, 0, 5);

};


TEST_F(RealTest, RandomValue) {
    double rnd = r.getRandom();
    EXPECT_TRUE(rnd > 0 && rnd < 5);
}

TEST_F(RealTest, CompareRealValuesGreater) {
    EXPECT_TRUE(moo::Real(2, 0, 5) > moo::Real(0, 0, 5));
}

TEST_F(RealTest, CompareRealValuesEqual) {
    EXPECT_TRUE(moo::Real(2, 0, 5) == moo::Real(2, 0, 5));
}

TEST_F(RealTest, SetValueOutOfBounds) {
    ASSERT_THROW(r.setValue(20), std::runtime_error);
}

TEST_F(RealTest, SetValueInBounds) {
    ASSERT_EQ(2, r.getValue());
}

