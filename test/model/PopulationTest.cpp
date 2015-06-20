#include <problems/Identity.h>
#include <indicator/IndicatorTest.h>
#include "AbstractTest.h"
#include "model/Population.h"
#include "problems/Kursawe.h"
#include <unordered_map>
#include "util/paretoFrontCalculator/ContUpdatedParetoFront.h"

class PopulationTest : public IndicatorTest {
public:
    moo::Population<moo::Identity> population = createPopulationFromVector(std::vector<std::vector<double>> {
            {0.44, 2.04}, {0.58, 1.18}, {1.43, 0.19}, {3.06, 0.04}, {2.42, 1.13}
    });

    moo::Population<moo::Identity> other = createPopulationFromVector(std::vector<std::vector<double>> {
            {0.31, 6.10}, {0.22, 7.09}, {0.79, 3.97}, {0.27, 6.93}
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


TEST_F(PopulationTest, SortByVectorAscending) {
    moo::Population<moo::Kursawe> pop {4};
    auto before = pop;
    std::vector<int> v {1,3,2,4};
    pop.sortByVector(v);
    ASSERT_THAT(pop, ElementsAre(before[0], before[2],before[1],before[3]));
}

TEST_F(PopulationTest, SortByVectorDescending) {
    moo::Population<moo::Kursawe> pop {4};
    std::vector<int> v {1,3,2,4};
    auto before = pop;
    pop.sortByVector(v, true);
    ASSERT_THAT(pop, ElementsAre(before[3], before[1],before[2],before[0]));
}

TEST_F(PopulationTest, SortByObjectiveOne) {
    auto before = other;
    other.sortByObjective(0, true);
    ASSERT_THAT(other, ElementsAre(before[2],before[0],before[3],before[1]));
}


TEST_F(PopulationTest, SortByObjectiveTwo) {
    auto before = other;
    other.sortByObjective(1, true);
    ASSERT_THAT(other, ElementsAre(before[1],before[3],before[0],before[2]));
}


TEST_F(PopulationTest, SortByMap) {
    std::unordered_map<moo::IndividualPtr<moo::Identity>,double> m;
    for (unsigned int i = 0; i < other.size(); ++i) {
        m[other[i]] = other[i]->getOutput()[0];
    }
    auto before = other;
    other.sortByObjective(0);
    before.sortByMap(m);
    EXPECT_EQ(before, other);
}



