#ifndef MOO_POLYNOMIALMUTATION_H
#define MOO_POLYNOMIALMUTATION_H


#include "util/Random.h"
#include "Mutation.h"

namespace moo {

    class PolynomialMutation : public Mutation<PolynomialMutation> {

    public:

        template <typename T> static void mutate_(T & in, double prob = -1) {
            if (prob == -1) prob = 1 / (double) in.size();
            auto random = Random::getInstance();
            for (unsigned int i = 0; i < in.size(); ++i) {
                if (random->rndDouble() < prob) in[i] = in[i].random();
            }
        }

    };

}


#endif //MOO_POLYNOMIALMUTATION_H
