#include <problems/Kursawe.h>
#include "AbstractTest.h"
#include "model/PopulationFactory.h"
#include "operators/selection/BinaryTournamentSelection.h"


struct cmp
{
    template<typename T>
    bool operator()(moo::IndividualPtr<T> a, moo::IndividualPtr<T> b)
    {
        return a->getOutput()[0] < b->getOutput()[0];
    }
};



class SelectionTest : public AbstractTest {
public:

    moo::Population<moo::Kursawe> pop = moo::PopulationFactory<moo::Kursawe>::createRandomPopulation(100);
};


TEST_F(SelectionTest, SelectOneThrowError) {
    ASSERT_THROW(moo::BinaryTournamentSelection<cmp>::select(pop), std::runtime_error);
}

TEST_F(SelectionTest, SelectMultipleNoThrow) {
    moo::BinaryTournamentSelection<cmp>::selectMultiple(pop);
    ASSERT_NO_THROW(moo::BinaryTournamentSelection<cmp>::selectMultiple(pop));
}