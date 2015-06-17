
#ifndef MOO_NONDOMINATEDRANK_H
#define MOO_NONDOMINATEDRANK_H


#include "Indicator.h"
#include <vector>



namespace moo {


    class NonDominatedRank : public Indicator<NonDominatedRank, int> {

    public:

        template <typename T>
        static std::unordered_map<IndividualPtr<T>, int> calculate_(Population<T> pop) {

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


        template <typename T>
        static Population<T> getParetoFront(Population<T> & population, bool removeFromPopulation = false)  {

            std::vector<IndividualPtr<T>> front;

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

            return Population<T>(front);
        }
    };



}



#endif //MOO_NONDOMINATEDRANK_H
