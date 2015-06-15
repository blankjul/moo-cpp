#ifndef MOO_CROSSOVER_H
#define MOO_CROSSOVER_H

#include "model/Population.h"

namespace moo {


    /**
     * Abstract class for all crossovers. All subclasses should provided the crossover templated function.
     */
    class Crossover {

    public:

        template <typename T> IndividualPtr<T> crossover(IndividualPtr<T> & a, IndividualPtr<T> & b);


    };

}


#endif //MOO_MUTATION_H
