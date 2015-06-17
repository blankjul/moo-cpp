#include "AbstractTest.h"
#include "model/Population.h"
#include "problems/Kursawe.h"

class PopulationTest : public AbstractTest {
public:
};




TEST_F(PopulationTest, CreateRandomPopulation) {
    moo::Population<moo::Kursawe> pop {100};
}


