#include "IndicatorTest.h"
#include "indicator/CrowdingDistance.h"



class CrowdingDistanceTest : public IndicatorTest {
public:
    moo::Population<moo::Identity> random {100};
    std::vector<double> min {0.1,0};
    std::vector<double> max {1,60};

    double inf = std::numeric_limits<double>::infinity();

    typedef std::unordered_map<moo::IndividualPtr<moo::Identity>, double> MapType;

};

TEST_F(CrowdingDistanceTest, ExecuteNoErrorThrown) {
    moo::CrowdingDistance::calculate(random);
}


TEST_F(CrowdingDistanceTest, CrowdedDistanceSmallExample) {
    MapType m = moo::CrowdingDistance::calculate_(population, min, max);
    EXPECT_NEAR(0.63, m[population[0]], 0.1);
    EXPECT_EQ(inf, m[population[1]]);
    EXPECT_EQ(inf, m[population[2]]);
    EXPECT_NEAR(0.12, m[population[3]], 0.1);
}


TEST_F(CrowdingDistanceTest, CrowdedDistanceSmallAndSort) {
    MapType m = moo::CrowdingDistance::calculate_(population, min, max);
    auto before = population;
    population.sortByMap(m, true);
    ASSERT_THAT(population, ElementsAre(before[1],before[2],before[0],before[3]));
}


TEST_F(CrowdingDistanceTest, CrowdedDistanceWrongBoundSize) {
    std::vector<double> min{0.1};
    ASSERT_THROW(moo::CrowdingDistance::calculate_(population, min, max), std::runtime_error);
}



TEST_F(CrowdingDistanceTest, CorrectBoundsMaxLargerMin) {
    std::vector<double> min;
    std::vector<double> max;
    moo::CrowdingDistance::bounds_(random, min, max);
    for (unsigned int i = 0; i < min.size(); ++i) {
        EXPECT_TRUE(min[i] <= max[i]);
    }
}


TEST_F(CrowdingDistanceTest, GetObjectiveUtilFunctionCorrectValuesFirst) {
    auto res = population.getObjective(0);
    ASSERT_THAT(res, ElementsAre(0.31, 0.22, 0.79, 0.27));
}
TEST_F(CrowdingDistanceTest, GetObjectiveUtilFunctionCorrectValuesSecond) {
    auto res = population.getObjective(1);
    ASSERT_THAT(res, ElementsAre(6.10, 7.09, 3.97, 6.93));
}





