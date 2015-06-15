#ifndef MOO_SINGLEPOINTCROSSOVER_H
#define MOO_SINGLEPOINTCROSSOVER_H

#include "Crossover.h"
#include "util/Random.h"

namespace moo {


    class SinglePointCrossover {

    public:

        template <typename T> IndividualPtr<T> crossover(IndividualPtr<T> & a, IndividualPtr<T> & b) {

            T genA = a->getInput();
            T genB = b->getInput();

            T genOffspring = genA;

            int point = rndInt(0,genB.size());
            for (int i = point; i < genB.size(); ++i) {
                genOffspring[i] = genB[i];
            }

            moo::IndividualPtr<T> offspring = std::make_shared<moo::Individual<T> >(genOffspring);

            return offspring;
        }


    };

}


#endif //MOO_SINGLEPOINTCROSSOVER_H
