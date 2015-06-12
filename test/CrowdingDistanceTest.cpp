#include "AbstractTest.h"
#include "indicator/CrowdedDistance.h"
#include <limits>


class CrowdingDistanceTest : public AbstractTest {
public:
    double inf = std::numeric_limits<double>::infinity();

    typedef std::unordered_map<moo::IndividualPtr<input>, double> MapType;

    moo::Population<std::vector<double>> population = getExamplePopulation();
    moo::Population<input> originial = population;

    moo::CrowdedDistance<input> crowded;

    std::vector<double> min {0.1,0};
    std::vector<double> max {1,60};



};

TEST_F(CrowdingDistanceTest, SortByObjectiveOne) {
    crowded.sortByObjective(population, 0);
    ASSERT_THAT(population, ElementsAre(originial[2],originial[0],originial[3],originial[1]));
}


TEST_F(CrowdingDistanceTest, SortByObjectiveTwo) {
    crowded.sortByObjective(population, 1);
    ASSERT_THAT(population, ElementsAre(originial[1],originial[3],originial[0],originial[2]));
}


TEST_F(CrowdingDistanceTest, CrowdedDistance) {
    MapType m = crowded.calculate(population, &min, &max);
    EXPECT_NEAR(0.63, m[population[0]], 0.1);
    EXPECT_EQ(inf, m[population[1]]);
    EXPECT_EQ(inf, m[population[2]]);
    EXPECT_NEAR(0.12, m[population[3]], 0.1);
}

TEST_F(CrowdingDistanceTest, CrowdedDistanceSortInplace) {
    MapType m = crowded.calculate(population, &min, &max);
    crowded.sortByIndicator(population, m);
    ASSERT_THAT(population, ElementsAre(originial[1],originial[2],originial[0],originial[3]));
}



TEST_F(CrowdingDistanceTest, CrowdedDistanceWrongBoundSize) {
    std::vector<double> min{0.1};
    ASSERT_THROW(crowded.calculate(population, &min, &max), std::runtime_error);
}
