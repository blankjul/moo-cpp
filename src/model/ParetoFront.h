#ifndef MOO_FRONT_H
#define MOO_FRONT_H

#include "model/Population.h"
#include <unordered_set>

namespace moo {


    template <typename Trait>
    class ParetoFront {
    private:

        std::list<IndividualPtr<Trait>> front;

    public:

        Population<Trait> getPopulation() const {
            Population<Trait> result;
            for(auto ind : front) result.push_back(ind);
            return result;
        }

        bool add(const IndividualPtr<Trait> & ind) {
            // for every element of front
            for (auto it = front.begin(); it != front.end(); ) {
                // of one elements dominates ind -> does not belong to front
                if ((*it)->isDominating(*ind) || (*it)->isEqual(*ind)) return false;
                // else remove all elements that are dominated by ind
                if ((*it)->isDominatedBy(*ind)) front.erase(it++);
                else ++it;
            }
            front.push_back(ind);
            return true;
        }

    };

}




#endif //MOO_FRONT_H
