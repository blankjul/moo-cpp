#ifndef MOO_POPFAC_H
#define MOO_POPFAC_H

#include "model/Evaluator.h"
#include "model/Population.h"

namespace moo {

    template<typename Traits>
    class PopulationFactory {

    public:

    static Population<Traits> createRandomPopulation(int n) {
        Population<Traits> pop(n);
        Evaluator<Traits> eval;
        eval.evaluateAll(pop);
        return pop;
    }


    };
}


#endif //MOO_POPFAC_H
