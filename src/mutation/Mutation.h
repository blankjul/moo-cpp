#ifndef MOO_MUTATION_H
#define MOO_MUTATION_H

#include "model/Population.h"

namespace moo {

    template <typename T>
    class Mutation {

    public:

        virtual void mutate(IndividualPtr<T> & ind) = 0;


    };

}


#endif //MOO_MUTATION_H
