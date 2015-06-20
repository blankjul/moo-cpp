#include "AbstractTest.h"
#include "model/Individual.h"
#include "problems/Kursawe.h"




class KursaweTest : public AbstractTest {
public:
    moo::Kursawe k;
};

TEST_F(KursaweTest, CheckIfFunctionIsWorkingCorrectly) {
    moo::VariableCollection<moo::Real> col;
    for (int i = 0; i < 3; ++i) col.push_back(moo::Real(3));
    auto result = k.evaluate(col);
    EXPECT_NEAR(-8.5609, result[0], 0.01);
    EXPECT_NEAR(21.5703, result[1], 0.01);

}

