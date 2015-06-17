#ifndef MOO_BINARYSELECTOR_H
#define MOO_BINARYSELECTOR_H

#include <algorithm>
#include "Selection.h"


namespace moo {

    template<typename Comparator>
    class BinaryTournamentSelection : public Selection<BinaryTournamentSelection<Comparator>> {


    public:


        template<typename Trait> IndividualPtr<Trait> static select_(const Population<Trait> & population) {
            throw std::runtime_error("BinaryTournamentSelection does not allow to select only single individuals!");
        }


        template<typename Trait> Population<Trait> static selectMultiple_(const Population<Trait> & population) {

            Population<Trait> result;

            Population<Trait> queue = population;
            std::random_shuffle(queue.begin(), queue.end());

            while (queue.size() >= 2) {
                IndividualPtr<Trait> a = queue.pop_back_and_delete();
                IndividualPtr<Trait> b = queue.pop_back_and_delete();
                result.push_back(std::max(a, b, Comparator()));
            }
            if (queue.size() == 1) result.push_back(queue.pop_back_and_delete());
            return result;
        }




    };

}


#endif //MOO_BINARYSELECTOR_H
