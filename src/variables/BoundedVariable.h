
#ifndef MOO_BOUNDEDVARIABLE_H
#define MOO_BOUNDEDVARIABLE_H

#include "Variable.h"
#include <stdexcept>

namespace moo {

    template <typename Type>
    class BoundedVariable : public Variable<Type>
    {

    protected:

        Type lowerBound;
        Type upperBound;

    public:


        BoundedVariable(){}
        BoundedVariable(Type lower, Type upper) : lowerBound(lower), upperBound(upper) {};
        BoundedVariable(Type v, Type lower, Type upper) : Variable<Type>(v), lowerBound(lower), upperBound(upper) {};


        virtual void setValue(Type value) {
            if (value < lowerBound || value > upperBound) throw std::runtime_error("Boundary Exception.");
            setValue(value);
        };

        Type getLowerBound() const {
            return lowerBound;
        }

        void setLowerBound(Type lowerBound) {
            lowerBound = lowerBound;
        }

        Type getUpperBound() const {
            return upperBound;
        }

        void setUpperBound(Type upperBound) {
            upperBound = upperBound;
        }
    };

}

#endif //MOO_BOUNDEDVARIABLE_H
