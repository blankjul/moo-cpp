#include "AbstractTest.h"
#include "algorithms/moead/MOEAD.h"
#include "problems/Kursawe.h"


class WeightsTest : public AbstractTest {
public:
    moo::Weights w1 = moo::Weights{1,0,0};
    moo::Weights w2 = moo::Weights{1,0,0};
    moo::Weights w3 = moo::Weights{0,1,0};

    std::vector<moo::Weights> weights{moo::Weights{1,0,0}, moo::Weights{0,0,1},
                                      moo::Weights{0.9,0,0},moo::Weights{0.8,0,0}};
};

TEST_F(WeightsTest, CalculateDistanceToOtherVectorIsZero) {
    EXPECT_EQ(0,w1.getDistance(w2) );
}

TEST_F(WeightsTest, GetWeightsNoError) {
    moo::Weights::getWeights(33);
}


TEST_F(WeightsTest, CalculateDistanceToOtherVectorNotEqual) {
    EXPECT_EQ(std::sqrt(2),w1.getDistance(w3) );
}

TEST_F(WeightsTest, GetNearstNeighbors) {
    ASSERT_THAT(w1.getNearestNeighborByIndex(weights,3), ElementsAre(0,2,3));
}