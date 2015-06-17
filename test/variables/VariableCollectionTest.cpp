#include "AbstractTest.h"
#include "variables/VariableCollection.h"
#include "variables/Real.h"

class VariableCollectionTest : public AbstractTest {
public:
    moo::VariableCollection<moo::Real> col;
};


TEST_F(VariableCollectionTest, CreateEmptyInputCollection) {
    moo::VariableCollection<moo::Real> col;
}


TEST_F(VariableCollectionTest, RandomAtEmptyContainer) {
    col.random();
}

TEST_F(VariableCollectionTest, CollectionWithMultipleEntries) {
    moo::VariableCollection<moo::Real> col { 10, moo::Real(0,0,0) };
}