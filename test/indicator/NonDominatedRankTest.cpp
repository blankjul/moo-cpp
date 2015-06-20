#include "IndicatorTest.h"
#include "indicator/NonDominatedRank.h"
#include <unordered_map>

class NonDominatedRankTest : public IndicatorTest {
public:

    moo::Population<moo::Identity> population = createPopulationFromVector(std::vector<std::vector<double>> {
            {0.44, 2.04}, {0.58, 1.18}, {1.43, 0.19}, {3.06, 0.04}, {2.42, 1.13}
    });
};



TEST_F(NonDominatedRankTest, RankOrderTest) {
    auto m = moo::NonDominatedRank::calculate(population);
    EXPECT_EQ(0, m[population[0]]);
    EXPECT_EQ(0, m[population[1]]);
    EXPECT_EQ(0, m[population[2]]);
    EXPECT_EQ(0, m[population[3]]);
    EXPECT_EQ(1, m[population[4]]);
}

TEST_F(NonDominatedRankTest, RankOrderTestOnlyForSomeIndividuals) {
    auto m = moo::NonDominatedRank::calculate_(population, 4);
    int inf = std::numeric_limits<int>::max();
    EXPECT_EQ(inf , m[population[4]]);
}

