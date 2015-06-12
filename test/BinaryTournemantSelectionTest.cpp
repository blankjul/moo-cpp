#include "AbstractTest.h"
#include "selection/BinaryTournamentSelection.h"
#include "model/Problem.h"


struct cmp
{
    template<typename T>
    bool operator()(moo::IndividualPtr<T> a, moo::IndividualPtr<T> b)
    {
        return a->evaluate()[0] < b->evaluate()[0];
    }
};



class BinaryTournamentSelectionTest : public AbstractTest {
public:
};


TEST_F(BinaryTournamentSelectionTest, CreateOneElementRandom) {
    moo::Population<input> pop = getExamplePopulation();
    cmp comp;
    moo::BinaryTournamentSelection<input,cmp> selector(pop, comp);

    selector.select();

}