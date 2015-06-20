
#ifndef MOO_REAL_H
#define MOO_REAL_H

#include "BoundedVariable.h"
#include "util/Random.h"
#include <cstdlib>

namespace moo {

    class Real : public BoundedVariable<double>
    {

    public:

        Real(double value) : BoundedVariable(value,0, 1000) {}
        Real(double value, double lower, double upper) : BoundedVariable(value, lower, upper) {};
        Real(double lower, double upper) : BoundedVariable(0,lower, upper) {};

        Real random() const {
            auto random = Random::getInstance();
            double tmp =  random->rndDouble(lowerBound, upperBound);
            return Real(tmp,lowerBound,upperBound);
        }

    };


}


#endif //MOO_REAL_H
