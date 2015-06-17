#include "IndicatorTest.h"

TEST_F(IndicatorTest, SortByObjectiveOne) {
    auto res = moo::sortByObjective(population, 0);
    ASSERT_THAT(res, ElementsAre(population[2],population[0],population[3],population[1]));
}


TEST_F(IndicatorTest, SortByObjectiveTwo) {
    auto res = moo::sortByObjective(population, 1);
    ASSERT_THAT(res, ElementsAre(population[1],population[3],population[0],population[2]));
}



