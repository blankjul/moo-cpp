#ifndef MOO_MUTATION_H
#define MOO_MUTATION_H

#include "model/Individual.h"

namespace moo {


    template <typename DerivedClass>
    class Mutation {

    public:


        template <typename Trait> static IndividualPtr<Trait> mutate(IndividualPtr<Trait> & ind)
        {
            typename Trait::InputType in = ind->getInput();
            DerivedClass::mutate_(in);
            return std::make_shared<Individual<Trait>>(in);
        }


    };

}


#endif //MOO_MUTATION_H
