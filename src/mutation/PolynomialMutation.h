#ifndef MOO_POLYNOMIALMUTATION_H
#define MOO_POLYNOMIALMUTATION_H

#include <algorithm>
#include "model/Population.h"
#include "util/Random.h"

namespace moo {

    class PolynomialMutation {

    public:

        template <typename T> void mutate(IndividualPtr<T> & ind) {

            T v = ind->getInput();
            double prob = 1 / v.size();

            for (int i = 0; i < v.size(); ++i) {
                if (rndDouble() < prob) v[i] = v[i].getRandom();
            }
            ind->setInput(v);
        }

    };

}


#endif //MOO_POLYNOMIALMUTATION_H
