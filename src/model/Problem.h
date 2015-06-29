#ifndef MOO_PROBLEM_H
#define MOO_PROBLEM_H

#include <iostream>
#include "ParetoFront.h"

namespace moo {

    template <typename DerivedClass>
    class Problem {
        
        public:

        int numOfEvaluations = 0;
        
        static int getNumOfObjectives() {
            return DerivedClass::getOutput().size();
        }
        
       
        

    };

}




#endif //MOO_PROBLEM_H
