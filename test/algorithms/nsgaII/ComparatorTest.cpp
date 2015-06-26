#include "AbstractTest.h"
#include "algorithms/nsgaII/Comparator.h"
#include "operators/selection/BinaryTournamentSelection.h"
#include "problems/Identity.h"
#include "indicator/NonDominatedRank.h"
#include "indicator/CrowdingDistance.h"
#include <algorithm>
#include <variables/Real.h>
#include <variables/VariableCollection.h>
#include <problems/Kursawe.h>


class ComparatorTest : public AbstractTest {
public:
    moo::Population<moo::Identity> random {100};
    moo::IndividualPtr<moo::Kursawe> a = std::make_shared<moo::Individual<moo::Kursawe>>(moo::VariableCollection<moo::Real> { 10, moo::Real(1,0,10) });
    moo::IndividualPtr<moo::Kursawe> b = std::make_shared<moo::Individual<moo::Kursawe>>(moo::VariableCollection<moo::Real> { 10, moo::Real(1,0,10) });

    std::unordered_map<moo::IndividualPtr<moo::Kursawe>, int> indRank;
    std::unordered_map<moo::IndividualPtr<moo::Kursawe>, double> indCrowding;





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


TEST_F(ComparatorTest, ComparatorPreferHigherRank) {
    indRank[a] = 0;
    indRank[b] = 1;
    RankAndCrowdedComperator<moo::Kursawe> cmp(&indRank, &indCrowding);
    EXPECT_TRUE(cmp(a,b));
}

TEST_F(ComparatorTest, ComparatorSameRankPreferCrowding) {
    indRank[a] = 0;
    indRank[b] = 0;
    indCrowding[a] = 1000;
    indCrowding[b] = 999;
    RankAndCrowdedComperator<moo::Kursawe> cmp(&indRank, &indCrowding);
    EXPECT_TRUE(cmp(a,b));
    EXPECT_EQ(a, std::min(a,b,cmp));
}

TEST_F(ComparatorTest, ComparatorPreferSecondBecauseOfRank) {
    indRank[a] = 1;
    indRank[b] = 0;
    RankAndCrowdedComperator<moo::Kursawe> cmp(&indRank, &indCrowding);
    EXPECT_FALSE(cmp(a,b));
    EXPECT_EQ(b, std::min(a,b,cmp));
}

