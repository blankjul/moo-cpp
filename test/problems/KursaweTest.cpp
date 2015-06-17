#include "AbstractTest.h"
#include "model/Individual.h"
#include "problems/Kursawe.h"
#include "model/Evaluator.h"




class KursaweTest : public AbstractTest {
public:
    moo::Kursawe k;
    moo::Evaluator<moo::Kursawe> eval;
};

TEST_F(KursaweTest, CheckIfFunctionIsWorkingCorrectly) {
    moo::VariableCollection<moo::Real> col;
    for (int i = 0; i < 3; ++i) col.push_back(moo::Real(3));
    auto result = k.evaluate(col);
    EXPECT_NEAR(-8.5609, result[0], 0.01);
    EXPECT_NEAR(21.5703, result[1], 0.01);

}

TEST_F(KursaweTest, CorrectResultUsingEvaluator) {
    moo::VariableCollection<moo::Real> col { 3, moo::Real(3) };
    moo::IndividualPtr<moo::Kursawe> ind = std::make_shared<moo::Individual<moo::Kursawe>>(col);
    auto result = eval.evaluate(ind);
    EXPECT_NEAR(-8.5609, result[0], 0.01);
    EXPECT_NEAR(21.5703, result[1], 0.01);
}