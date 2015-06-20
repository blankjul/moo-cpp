#include <problems/Kursawe.h>
#include "AbstractTest.h"
#include "operators/selection/BinaryTournamentSelection.h"


struct cmp
{
    template<typename T>
    bool operator()(moo::IndividualPtr<T> a, moo::IndividualPtr<T> b)
    {
        return a->getOutput()[0] < b->getOutput()[0];
    }
};


cmp mock;
moo::BinaryTournamentSelection<cmp> sel(mock);



class SelectionTest : public AbstractTest {
public:
    moo::Population<moo::Kursawe> pop {100};
};


TEST_F(SelectionTest, SelectOneThrowError) {
    ASSERT_THROW(sel.select(pop), std::runtime_error);
}

TEST_F(SelectionTest, SelectMultipleNoThrow) {
    auto pool = sel.selectMultiple(pop, 50);
    EXPECT_EQ(50, pool.size());
}