#ifndef MOO_CONTUPDATEDPARETOFRONT_H
#define MOO_CONTUPDATEDPARETOFRONT_H

#include "ParetoFront.h"
#include <list>


namespace moo {


    class ContUpdatedParetoFront : public ParetoFrontCalc<ContUpdatedParetoFront> {

    public:

        template <typename Trait>
        static Population<Trait> getParetoFront(const Population<Trait> & pop)
        {
            std::list<IndividualPtr<Trait>> front;
            if (pop.empty()) return Population<Trait>();

            front.push_back(pop[0]);
            for (int i = 1; i < pop.size(); ++i) {
                bool isNonDominated = true;
                auto ind = pop[i];

                for (auto it = front.begin(); it != front.end(); ) {
                    if ((*it)->isDominating(*ind)) {
                        isNonDominated = false;
                        break;
                    }
                    if ((*it)->isDominatedBy(*ind)){
                        front.erase(it++);
                    } else ++it;

                }
                if (isNonDominated) front.push_back(ind);
            }

            Population<Trait> result;
            for(auto ind : front) result.push_back(ind);

            return result;
        }



    };

}

#endif //MOO_CONTUPDATEDPARETOFRONT_H
