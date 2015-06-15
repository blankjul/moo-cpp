
#ifndef MOO_REAL_H
#define MOO_REAL_H

#include "BoundedVariable.h"

namespace moo {

    class Real : public BoundedVariable<double>
    {

    public:

        Real() : BoundedVariable(0,0,0) {};
        Real(double value, double lower, double upper) : BoundedVariable(value, lower, upper) {};
        Real(double lower, double upper) : BoundedVariable(0,lower, upper) {};

        Real getRandom(){
            double value =  lowerBound + (double)rand() / RAND_MAX * (upperBound - lowerBound);
            return Real(value,lowerBound,upperBound);
        }

    };



}


#endif //MOO_REAL_H
