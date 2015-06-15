#include "AbstractTest.h"
#include "model/Individual.h"
#include "problems/Kursawe.h"



class KursaweTest : public AbstractTest {
public:
    moo::Kursawe k;
};

TEST_F(KursaweTest, CheckIfFunctionIsWorkingCorrectly) {
    //std::vector<double> result = k.evaluate(std::vector<double>{3,3,3});
    //EXPECT_NEAR(-8.5609, result[0], 0.01);
    //EXPECT_NEAR(21.5703, result[1], 0.01);
}
