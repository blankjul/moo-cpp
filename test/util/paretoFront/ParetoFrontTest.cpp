
#include "AbstractTest.h"
#include "model/Population.h"
#include "util/paretoFrontCalculator/ContUpdatedParetoFront.h"
#include "util/paretoFrontCalculator/NaiveParetoFront.h"
#include "util/paretoFrontCalculator/KungParetoFront.h"
#include "problems/Kursawe.h"



class ParetoFrontTest : public AbstractTest {
public:
    moo::Population<moo::Kursawe> pop {100};
};



TEST_F(ParetoFrontTest, CheckIfFunctionIsWorkingCorrectly) {
    moo::ContUpdatedParetoFront::getParetoFront(pop);
}

TEST_F(ParetoFrontTest, GetParetoFrontFastCorrectness) {
    auto m = moo::NaiveParetoFront::getParetoFront(pop);
    auto mfast = moo::ContUpdatedParetoFront::getParetoFront(pop);
    EXPECT_EQ(m, mfast);
}

TEST_F(ParetoFrontTest, GetParetoFrontKungCorrectness) {
    auto m = moo::NaiveParetoFront::getParetoFront(pop);
    auto mkung = moo::KungParetoFront::getParetoFront(pop);

    std::set<moo::IndividualPtr<moo::Kursawe>> s1;
    s1.insert(m.begin(), m.end());

    std::set<moo::IndividualPtr<moo::Kursawe>> s2;
    s2.insert(mkung.begin(), mkung.end());

    EXPECT_EQ(s1, s2);
}

