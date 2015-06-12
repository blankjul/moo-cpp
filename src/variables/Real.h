
#ifndef MOO_REAL_H
#define MOO_REAL_H

#include "BoundedVariable.h"

namespace moo {

    class Real : public BoundedVariable<double>
    {

    public:

        Real(double value, double lower, double upper) : BoundedVariable(value, lower, upper) {};
        Real(double lower, double upper) : BoundedVariable(lower, upper) {};

        double getRandom(){
            double f = (double)rand() / RAND_MAX;
            return lowerBound + f * (upperBound - lowerBound);
        }

    };



}

#endif //MOO_REAL_H
