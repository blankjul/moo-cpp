#include "IndicatorTest.h"
#include "indicator/NonDominatedRank.h"
#include "indicator/FastNonDominatedRank.h"
#include <unordered_map>

class FastNonDominatedRankTest : public IndicatorTest {
public:

    moo::Population<moo::Identity> population {100};
};




TEST_F(FastNonDominatedRankTest, RankOrderTestCorrect) {
    auto m = moo::NonDominatedRank::calculate(population);
    auto mfast = moo::FastNonDominatedRank::calculate(population);
    EXPECT_EQ(m, mfast);
}

TEST_F(FastNonDominatedRankTest, RankOrderTestCorrectOnlySomeIndividuals) {
    auto m = moo::NonDominatedRank::calculate_(population,20);
    auto mfast = moo::FastNonDominatedRank::calculate_(population,20);
    EXPECT_EQ(m, mfast);
}

TEST_F(FastNonDominatedRankTest, Benchmark) {
    moo::Population<moo::Identity> population {10000};


    std::clock_t start;
    double duration;
    start = std::clock();
    moo::NonDominatedRank::calculate_(population);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"NonDominatedRank: "<< duration <<'\n';


    start = std::clock();
    moo::FastNonDominatedRank::calculate_(population);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"FastNonDominatedRank: "<< duration <<'\n';

}

