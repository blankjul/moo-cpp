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

