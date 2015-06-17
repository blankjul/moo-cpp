#include "AbstractTest.h"
#include "problems/Kursawe.h"
#include "model/Individual.h"
#include "operators/mutation/PolynomialMutation.h"

#include <memory>



class MutationTest : public AbstractTest {
public:
    moo::VariableCollection<moo::Real> col { 10, moo::Real(1,0,10) };
    moo::IndividualPtr<moo::Kursawe> a = std::make_shared<moo::Individual<moo::Kursawe>>(col);
};



TEST_F(MutationTest, NoThrowWhenCallMutateInheritanceWorks) {
    ASSERT_NO_THROW(moo::PolynomialMutation::mutate(a));
}

TEST_F(MutationTest, MutateWorksNotEqual) {
    auto copy = a->getInput();
    moo::PolynomialMutation::mutate_(copy, 1);
    EXPECT_NE(copy, a->getInput());
}