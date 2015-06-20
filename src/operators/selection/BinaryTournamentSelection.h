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

                pool = population;
                std::random_shuffle(pool.begin(), pool.end());

                for (int i = 0; i < pool.size() -1; i += 2) {
                    IndividualPtr<Trait> a = pool[i];
                    IndividualPtr<Trait> b = pool[i+1];

                    if (comp(a,b)) result.push_back(a);
                    else result.push_back(b);

                    if (result.size() >= n) break;
                }

            }

            return result;

        }




    };

}


#endif //MOO_BINARYSELECTOR_H
