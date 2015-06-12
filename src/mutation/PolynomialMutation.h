#ifndef MOO_MUTATION_H
#define MOO_MUTATION_H

#include <algorithm>
#include "model/Population.h"
#include "util/Random.h"

namespace moo {

    template <typename T>
    class PolynomialMutation {

    public:

        void mutate(IndividualPtr<T> & ind) {

            std::vector<T> variables;
            std::copy(ind->getInput().begin(),ind->getInput().end(), std::back_inserter(variables) );

            double prob = 1 / variables.size();


            for (int i = 0; i < variables.size(); ++i) {
                if (rndDouble() < prob) variables[i] = variables[i].getRandom();
            }

            ind->setInput(variables);

        }


    };

}


#endif //MOO_MUTATION_H
