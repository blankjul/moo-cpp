#ifndef MOO_POPULATION_H
#define MOO_POPULATION_H

#include "Individual.h"
#include <vector>

namespace moo {

    template<typename Input>
    class Population : public std::vector<IndividualPtr<Input>> {
    public:
        bool isNonDominated(IndividualPtr<Input> & ind) {
            for (auto entry : *this) {
                if (ind->isDominatedBy(*entry)) return true;
            }
            return false;
        }


    };

}


#endif //MOO_POPULATION_H