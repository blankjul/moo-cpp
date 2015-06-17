#include "AbstractTest.h"
#include "variables/Real.h"

class RealTest : public AbstractTest {
public:
    moo::Real r = moo::Real(5,0,10);
};


TEST_F(RealTest, SetValueOutOfBounds) {
    ASSERT_THROW(r.setValue(20), std::runtime_error);
}


TEST_F(RealTest, RandomValueInBounds) {
    moo::Real rnd =  r.random();
    EXPECT_TRUE(rnd.getValue() > 0 && rnd.getValue() < 10);
}
