#include "AbstractTest.h"
#include "algorithms/nsgaII/Comparator.h"
#include "model/PopulationFactory.h"
#include "problems/Identity.h"
#include "indicator/NonDominatedRank.h"
#include "indicator/CrowdingDistance.h"
#include <algorithm>



class ComparatorTest : public AbstractTest {
public:
    moo::Population<moo::Identity> random = moo::PopulationFactory<moo::Identity>::createRandomPopulation(100);
};

TEST_F(ComparatorTest, ExecuteNoErrorThrown) {

    auto indRank = moo::NonDominatedRank::calculate(random);
    auto indCrowding = moo::CrowdingDistance::calculate(random);

    RankAndCrowdedComperator<moo::Identity> cmp(&indRank, &indCrowding);
    std:sort(random.begin(), random.end(), cmp);

    for (unsigned int i = 0; i < random.size() - 1; ++i) {
        EXPECT_TRUE(indRank[random[i]] <= indRank[random[i+1]]);
    }

    for (unsigned int i = 0; i < random.size() - 1; ++i) {
        if (indRank[random[i]] == indRank[random[i+1]]) EXPECT_TRUE( indCrowding[random[i]] >= indCrowding[random[i+1]]);
    }


}

