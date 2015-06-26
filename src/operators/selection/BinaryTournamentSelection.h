#ifndef MOO_BINARYSELECTOR_H
#define MOO_BINARYSELECTOR_H

#include <algorithm>
#include "Selection.h"


namespace moo {

    template<typename Comparator>
    class BinaryTournamentSelection : public Selection<BinaryTournamentSelection<Comparator>> {

    private:

        Comparator comp;


    public:


        BinaryTournamentSelection(const Comparator& comp) : comp(comp) {}

        template<typename Trait> IndividualPtr<Trait> select_(const Population<Trait> & population) {
            throw std::runtime_error("BinaryTournamentSelection does not allow to select only single individuals!");
        }


        template<typename Trait> Population<Trait> selectMultiple_(const Population<Trait> & population, int n) {


            Population<Trait> result;
            Population<Trait> pool;


            while (result.size() < n) {

                auto index = population.getIndex();
                std::random_shuffle(index.begin(), index.end());

                for (int i = 0; i < index.size() -1; i += 2) {
                    result.push_back(std::min(population[index[i]], population[index[i+1]]));
                    if (result.size() >= n) break;
                }

            }

            return result;

        }




    };

}


#endif //MOO_BINARYSELECTOR_H
