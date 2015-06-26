#include <problems/Identity.h>
#include <model/ParetoFront.h>
#include "AbstractTest.h"
#include "model/Population.h"
#include "problems/Kursawe.h"
#include <unordered_map>
#include "util/paretoFrontCalculator/ContUpdatedParetoFront.h"
#include "indicator/IndicatorTest.h"


class ParetoFrontTest : public IndicatorTest {
public:
    moo::Population<moo::Identity> population = createPopulationFromVector(std::vector<std::vector<double>> {
            {0.44, 2.04}, {0.58, 1.18}, {1.43, 0.19}, {3.06, 0.04}, {2.42, 1.13}
    });

    moo::Population<moo::Identity> other = createPopulationFromVector(std::vector<std::vector<double>> {
            {0.31, 6.10}, {0.22, 7.09}, {0.79, 3.97}, {0.27, 6.93}
    });
    moo::Population<moo::Identity> random{100};

    moo::ParetoFront<moo::Identity> front;

};


TEST_F(ParetoFrontTest, CorrectParetoFrontSavedSmall) {
    auto result = moo::ContUpdatedParetoFront::getParetoFront(population);
    for (auto entry : population) front.add(entry);
    EXPECT_EQ(result, front.getPopulation());
}


TEST_F(ParetoFrontTest, CorrectParetoFrontSavedLarge) {
    auto result = moo::ContUpdatedParetoFront::getParetoFront(random);
    for (auto entry : random) front.add(entry);
    EXPECT_EQ(result, front.getPopulation());
}




