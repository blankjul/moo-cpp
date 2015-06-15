#ifndef MOO_MUTATION_H
#define MOO_MUTATION_H

#include "model/Population.h"

namespace moo {


    /**
     * All mutation operator should inherit from this class just to make clear
     * it is used as a mutation operator. The function is the template for the subclasses
     * that has to be implement, although template functions are not allowed to be virtual.
     */
    class Mutation {

    public:

        template <typename T> void mutate(IndividualPtr<T> & ind);

    };

}


#endif //MOO_MUTATION_H
