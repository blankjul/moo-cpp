#include "AbstractTest.h"
#include "model/Population.h"
#include "util/paretoFrontCalculator/ContUpdatedParetoFront.h"
#include "util/paretoFrontCalculator/NaiveParetoFront.h"
#include "util/paretoFrontCalculator/KungParetoFront.h"
#include "problems/Identity.h"



class ParetoFrontTest : public AbstractTest {
public:
    moo::Population<moo::Identity> pop {100};
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

    std::set<moo::IndividualPtr<moo::Identity>> s1;
    s1.insert(m.begin(), m.end());

    std::set<moo::IndividualPtr<moo::Identity>> s2;
    s2.insert(mkung.begin(), mkung.end());

    EXPECT_EQ(s1, s2);
}


TEST_F(ParetoFrontTest, Benchmark) {

    moo::Population<moo::Identity> pop {10000};

    std::clock_t start;
    double duration;
    start = std::clock();
    moo::NaiveParetoFront::getParetoFront(pop);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"NaiveParetoFront: "<< duration <<'\n';

    start = std::clock();
    moo::ContUpdatedParetoFront::getParetoFront(pop);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"ContUpdatedParetoFront: "<< duration <<'\n';

    start = std::clock();
    moo::KungParetoFront::getParetoFront(pop);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"KungParetoFront: "<< duration <<'\n';


}


