#include "AbstractTest.h"
#include "model/Individual.h"
#include "problems/Identity.h"


class IndividualTest : public AbstractTest {
public:
};




TEST_F(IndividualTest, CreateIndividualWithTemplate) {
    moo::Individual<moo::Identity> ind;
}


