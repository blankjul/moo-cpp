#ifndef MOO_RANDOMSELECTION_H
#define MOO_RANDOMSELECTION_H

#include <algorithm>
#include "Selection.h"
#include  <random>
#include  <iterator>



namespace moo {


    class RandomSelection : public Selection<RandomSelection> {

    private:


        template<typename Iter, typename RandomGenerator>
        Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
            std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
            std::advance(start, dis(g));
            return start;
        }

        template<typename Iter>
        Iter select_randomly(Iter start, Iter end) {
            static std::random_device rd;
            static std::mt19937 gen(rd());
            return select_randomly(start, end, gen);
        }



    public:



        template<typename Trait>
        IndividualPtr<Trait> select_(const Population<Trait> & population) {
            return *(select_randomly(population.begin(), population.end()));
        }


        template<typename Trait>
        Population<Trait> selectMultiple_(const Population<Trait> & population, int n) {
            Population<Trait> result;
            for (int i = 0; i < n; ++i) {
                result.push_back(select_(population));
            }
            return result;
        }




    };

}


#endif //MOO_RANDOMSELECTION_H
