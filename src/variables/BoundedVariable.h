
#ifndef MOO_BOUNDEDVARIABLE_H
#define MOO_BOUNDEDVARIABLE_H

#include "Variable.h"

namespace moo {

    template <typename Type>
    class BoundedVariable : public Variable<Type>
    {
    protected:

        Type lowerBound;
        Type upperBound;

    public:

        BoundedVariable(Type lower, Type upper) : lowerBound(lower), upperBound(upper) {};
        BoundedVariable(Type value, Type lower, Type upper) : Variable<Type>(value), lowerBound(lower), upperBound(upper)  {};

        void setValue(Type value) {
            if (value < lowerBound || value > upperBound) throw std::runtime_error("Boundary Exception.");
            setValue(value);
        };

    };

}

#endif //MOO_BOUNDEDVARIABLE_H
