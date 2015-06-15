#ifndef MOO_BINARYSELECTOR_H
#define MOO_BINARYSELECTOR_H

#include <algorithm>
#include "Selection.h"
#include "model/Individual.h"
#include <iostream>


namespace moo {

    template <typename Comparator>
    class BinaryTournamentSelection : public Selection {

    private:

        Comparator cmp;


        template<typename T> IndividualPtr<T> pop_back(Population<T> &  pop) {
            IndividualPtr<T> a = pop.back();
            pop.pop_back();
            return a;
        }


    public:


        BinaryTournamentSelection(Comparator cmp) : cmp(cmp) {}


        template<typename T> IndividualPtr<T> select(const Population<T> & population) {
            throw std::runtime_error("BinaryTournamentSelection does not allow to select only single individuals!");
        }


        template<typename T> Population<T> select(const Population<T> & population, int n) {

            Population<T> result;
            Population<T> queue;

            while (result.size() <= n) {

                if (queue.size() < 2) {
                    queue = population;
                    std::random_shuffle(queue.begin(), queue.end());
                }

                IndividualPtr<T> a = pop_back(queue);

                if (result.size() == n) break;
                IndividualPtr<T> b = pop_back(queue);

                result.push_back(std::max(a,b,cmp));
            }

            return result;
        }




    };

}


#endif //MOO_BINARYSELECTOR_H
