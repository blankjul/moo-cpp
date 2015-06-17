#ifndef MOO_POPULATION_H
#define MOO_POPULATION_H


#include "Individual.h"
#include <vector>

namespace moo {


    template<typename Trait>
    class Population : public std::vector<IndividualPtr<Trait>>  {

    public:

        Population() : std::vector<IndividualPtr<Trait>>() {}

        Population(const std::vector<IndividualPtr<Trait>> &individuals) : std::vector<IndividualPtr<Trait>>(individuals){ }

        Population(int n) {
            for (int i = 0; i < n; ++i) {
                typename Trait::InputType in = Trait::getInput().random();
                auto ind = std::make_shared<Individual<Trait>>(in);
                this->push_back(ind);
            }
        }



        bool isNonDominated(IndividualPtr<Trait> & ind) {
            for (auto entry : *this) {
                if (ind->isDominatedBy(*entry)) return true;
            }
            return false;
        }



        const IndividualPtr<Trait> pop_back_and_delete() {
            IndividualPtr<Trait> a = this->back();
            this->pop_back();
            return a;
        }



    };
}


#endif //MOO_POPULATION_H