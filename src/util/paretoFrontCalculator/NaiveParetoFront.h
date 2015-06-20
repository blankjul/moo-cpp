#ifndef MOO_NAIVEPARETOFRONT_H
#define MOO_NAIVEPARETOFRONT_H

#include "ParetoFront.h"

namespace moo {


    class NaiveParetoFront : public ParetoFrontCalc<NaiveParetoFront> {

    public:

        template <typename Trait>
        static Population<Trait> getParetoFront(const Population<Trait> & pop)
        {
            Population<Trait> front;
            for (int i = 0; i < pop.size(); ++i) {
                IndividualPtr<Trait> ind = pop[i];
                if (!pop.isNonDominated(ind)) front.push_back(ind);
            }
            return front;
        }



    };

}

#endif //MOO_NAIVEPARETOFRONT_H
