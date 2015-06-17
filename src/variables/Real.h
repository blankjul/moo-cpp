
#ifndef MOO_REAL_H
#define MOO_REAL_H

#include "BoundedVariable.h"
#include <cstdlib>

namespace moo {

    class Real : public BoundedVariable<double>
    {

    public:

        Real(double value) : BoundedVariable(value,0, 1000) {}
        Real(double value, double lower, double upper) : BoundedVariable(value, lower, upper) {};
        Real(double lower, double upper) : BoundedVariable(0,lower, upper) {};

        Real random() const {
            double value =  lowerBound + (double) std::rand() / RAND_MAX * (upperBound - lowerBound);
            return Real(value,lowerBound,upperBound);
        }

    };


}


#endif //MOO_REAL_H
