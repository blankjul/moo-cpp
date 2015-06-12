#include "AbstractTest.h"
#include "variables/VariableCollection.h"
#include "variables/BoundedVariable.h"

typedef moo::VariableCollection<moo::BoundedVariable<double>> input;

class SomeProblem : public moo::Problem<input> {

public:
    std::vector<double> evaluate(const input & vars) {
        return std::vector<double> {0,0,0};
    }

};




class MutationTest : public AbstractTest {
public:


};



TEST_F(MutationTest, MutateOneValue) {



}
