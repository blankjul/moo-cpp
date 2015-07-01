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

            // function for adding an element to the front
            auto func = [&front](const IndividualPtr<Trait> & ind) {
                // for every element of front
                for (auto it = front.begin(); it != front.end(); ) {
                    // of one elements dominates ind -> does not belong to front
                    if ((*it)->isDominating(*ind)) return false;
                    // else remove all elements that are dominated by ind
                    if ((*it)->isDominatedBy(*ind)) front.erase(it++);
                    else ++it;

                }
                front.push_back(ind);
                return true;
            };

            for (unsigned int i = 0; i < pop.size(); ++i) func(pop[i]);

            Population<Trait> result;
            for(auto ind : front) result.push_back(ind);

            return result;
        }



    };

}

#endif //MOO_CONTUPDATEDPARETOFRONT_H
