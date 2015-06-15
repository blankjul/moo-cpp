#include <problems/Kursawe.h>
#include "AbstractTest.h"
#include "mutation/PolynomialMutation.h"
#include "crossover/SinglePointCrossover.h"


class RecombinationTest : public AbstractTest {
public:

    typedef moo::VariableCollection<moo::Real> input;

    std::shared_ptr<moo::Kursawe> problem = std::make_shared<moo::Kursawe>();
    moo::PolynomialMutation m;
    moo::SinglePointCrossover c;
    moo::IndividualPtr<input> a = std::make_shared<moo::Individual<input>>(problem->getInput().getRandom());
    moo::IndividualPtr<input> b = std::make_shared<moo::Individual<input>>(problem->getInput().getRandom());
};



TEST_F(RecombinationTest, MutateOneValue) {
    m.mutate(a);
}



TEST_F(RecombinationTest, CrossoverOfMultipleValues) {
    auto off = c.crossover(a, b);
}
