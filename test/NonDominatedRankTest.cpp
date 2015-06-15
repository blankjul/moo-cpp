#include "AbstractTest.h"
#include "indicator/NonDominatedRank.h"
#include <unordered_map>

class NonDominatedRankTest : public AbstractTest {
public:
    typedef std::vector<double> input;

    moo::Population<input> getPopulation() {
        std::vector<std::vector<double>> data;
        data.push_back(std::vector<double> {0.44, 2.04});
        data.push_back(std::vector<double> {0.58, 1.18});
        data.push_back(std::vector<double> {1.43, 0.19});
        data.push_back(std::vector<double> {3.06, 0.04});
        data.push_back(std::vector<double> {2.42, 1.13});
        return createPopulationFromVector(data);
    }
    moo::NonDominatedRank sort;
    moo::Population<std::vector<double>> population = getPopulation();
};

TEST_F(NonDominatedRankTest, Sort) {
    moo::Population<std::vector<double>> result = sort.getParetoFront(population);
    EXPECT_EQ(4, result.size());
}

TEST_F(NonDominatedRankTest, SortAndErease) {
    moo::Population<std::vector<double>> result = sort.getParetoFront(population, true);
    EXPECT_EQ(4, result.size());
    EXPECT_EQ(1, population.size());
}

TEST_F(NonDominatedRankTest, RankOrderTest) {
    auto m = sort.calculate(population);
    EXPECT_EQ(0, m[population[0]]);
    EXPECT_EQ(0, m[population[1]]);
    EXPECT_EQ(0, m[population[2]]);
    EXPECT_EQ(0, m[population[3]]);
    EXPECT_EQ(1, m[population[4]]);
}
