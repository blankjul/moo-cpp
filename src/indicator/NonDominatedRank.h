
#ifndef MOO_NONDOMINATEDRANK_H
#define MOO_NONDOMINATEDRANK_H

#include "model/Individual.h"
#include "model/Population.h"
#include "Indicator.h"
#include <vector>
#include <iostream>


namespace moo {

    template <typename T>
    class NonDominatedRank : public Indicator<T, int> {

    public:

        std::unordered_map<IndividualPtr<T>, int> calculate(Population<T> pop) {

            std::unordered_map<IndividualPtr<T>, int> m;
            int counter = 0;

            while (!pop.empty()) {
                for (IndividualPtr<T> entry : getParetoFront(pop, true)) {
                    m[entry] = counter;
                }
                ++counter;
            }
            return m;
        }


        Population<T> getParetoFront(Population<T> & population, bool removeFromPopulation = false)  {

            Population<T> front;

            for (int i = 0; i < population.size(); ++i) {
                IndividualPtr<T> ind = population[i];
                if (!population.isNonDominated(ind)) front.push_back(ind);
            }

            if (removeFromPopulation) {
                for (auto entry : front) {
                    auto it = std::find(population.begin(), population.end(), entry);
                    if(it != population.end()) population.erase(it);
                }
            }

            return front;
        }
    };



}



#endif //MOO_NONDOMINATEDRANK_H
