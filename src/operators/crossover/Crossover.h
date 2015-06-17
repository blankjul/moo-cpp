#ifndef MOO_CROSSOVER_H
#define MOO_CROSSOVER_H

#include <memory>
#include "model/Individual.h"

namespace moo {


    template <typename DerivedClass>
    class Crossover {

    public:


        template <typename Trait> static IndividualPtr<Trait> crossover(IndividualPtr<Trait> & a, IndividualPtr<Trait> & b)
        {
            typename Trait::InputType in = DerivedClass::crossover_(a->getInput(),b->getInput());
            return std::make_shared<moo::Individual<Trait>>(in);
        }


    };

}


#endif //MOO_MUTATION_H
