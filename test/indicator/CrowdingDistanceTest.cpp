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


TEST_F(CrowdingDistanceTest, CrowdedDistance) {
    MapType m = moo::CrowdingDistance::calculate_(population, min, max);
    EXPECT_NEAR(0.63, m[population[0]], 0.1);
    EXPECT_EQ(inf, m[population[1]]);
    EXPECT_EQ(inf, m[population[2]]);
    EXPECT_NEAR(0.12, m[population[3]], 0.1);
}


TEST_F(CrowdingDistanceTest, CrowdedDistanceAndSort) {
    MapType m = moo::CrowdingDistance::calculate_(population, min, max);
    auto result = sortByIndicator(population, m);
    ASSERT_THAT(result, ElementsAre(population[1],population[2],population[0],population[3]));
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
    auto res = moo::getObjective(population, 0);
    ASSERT_THAT(res, ElementsAre(0.31, 0.22, 0.79, 0.27));
}
TEST_F(CrowdingDistanceTest, GetObjectiveUtilFunctionCorrectValuesSecond) {
    auto res = moo::getObjective(population, 1);
    ASSERT_THAT(res, ElementsAre(6.10, 7.09, 3.97, 6.93));
}





