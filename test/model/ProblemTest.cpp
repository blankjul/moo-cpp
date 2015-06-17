#include "AbstractTest.h"
#include "problems/Identity.h"
#include "model/Evaluator.h"


class ProblemTest : public AbstractTest {
public:
};




TEST_F(ProblemTest, CreateProblemWithTemplate) {
    moo::Evaluator<moo::Identity> p;
}


