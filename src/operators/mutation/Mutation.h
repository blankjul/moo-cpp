#ifndef MOO_MUTATION_H
#define MOO_MUTATION_H

#include "model/Individual.h"

namespace moo {


    template <typename DerivedClass>
    class Mutation {

    public:


        template <typename Trait> static void mutate(IndividualPtr<Trait> & ind)
        {
            typename Trait::InputType in = ind->getInput();
            DerivedClass::mutate_(in);
            ind->setInput(in);
        }


    };

}


#endif //MOO_MUTATION_H
