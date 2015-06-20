#include "AbstractTest.h"
#include "problems/Kursawe.h"
#include "operators/crossover/SinglePointCrossover.h"
#include "operators/crossover/SBXCrossover.h"

#include <memory>



class CrossoverTest : public AbstractTest {
public:
    typedef moo::VariableCollection<moo::Real> input;
    moo::IndividualPtr<moo::Kursawe> a = std::make_shared<moo::Individual<moo::Kursawe>>(input { 3, moo::Real(0,0,10) });
    moo::IndividualPtr<moo::Kursawe> b = std::make_shared<moo::Individual<moo::Kursawe>>(input { 3, moo::Real(10,0,10)});
};


TEST_F(CrossoverTest, NoThrowWhenCallSBXCrossoverInheritanceWorks) {
    ASSERT_NO_THROW(moo::SBXCrossover::crossover(a,b));
}

TEST_F(CrossoverTest, NoThrowWhenCallCrossoverInheritanceWorks) {
    ASSERT_NO_THROW(moo::SinglePointCrossover::crossover(a,b));
}


TEST_F(CrossoverTest, CrossoverWorksAtPoint) {
    input ex = b->getInput();
    ex[0] = a->getInput()[0];
    input off = moo::SinglePointCrossover::crossover_(a->getInput(),b->getInput(), 1);
    EXPECT_TRUE(ex == off);
}



TEST_F(CrossoverTest, ThrowCauseWrongSize) {
    moo::IndividualPtr<moo::Kursawe> c = std::make_shared<moo::Individual<moo::Kursawe>>(input { 10, moo::Real(10,0,10)});
    ASSERT_THROW(moo::SinglePointCrossover::crossover(a,c), std::runtime_error);
}

