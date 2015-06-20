#include <problems/Identity.h>
#include <indicator/IndicatorTest.h>
#include "AbstractTest.h"
#include "model/Population.h"
#include "problems/Kursawe.h"
#include "util/paretoFrontCalculator/ContUpdatedParetoFront.h"

class PopulationTest : public IndicatorTest {
public:
moo::Population<moo::Identity> population = createPopulationFromVector(std::vector<std::vector<double>> {
        {0.44, 2.04}, {0.58, 1.18}, {1.43, 0.19}, {3.06, 0.04}, {2.42, 1.13}
});
    moo::Population<moo::Identity> random{10};

};


TEST_F(PopulationTest, Sort) {
    auto result = moo::ContUpdatedParetoFront::getParetoFront(population);
    EXPECT_EQ(4, result.size());
}

TEST_F(PopulationTest, SortAndErease) {
    moo::Population<moo::Identity> result = moo::ContUpdatedParetoFront::getParetoFront(population);
    population.remove(result);
    EXPECT_EQ(4, result.size());
    EXPECT_EQ(1, population.size());
}


TEST_F(PopulationTest, RemoveEmptyFrontNothingChange) {
    moo::Population<moo::Identity> empty;
    int size = population.size();
    population.remove(empty);
    EXPECT_EQ(size, population.size());
}


TEST_F(PopulationTest, CreateRandomPopulation) {
    moo::Population<moo::Kursawe> pop {100};
    EXPECT_EQ(100, pop.size());
}

