#ifndef MOO_BINARYSELECTOR_H
#define MOO_BINARYSELECTOR_H

#include <algorithm>
#include "Selection.h"
#include "model/Individual.h"
#include <iostream>


namespace moo {

    template <typename T, typename Comparator>
    class BinaryTournamentSelection : public Selection<T> {

    private:

        Comparator cmp;
        Population<T> pool;

        IndividualPtr<T> pop_back(Population<T> &  pop) {
            IndividualPtr<T> a = pop.back();
            pop.pop_back();
            return a;
        }



    public:


        BinaryTournamentSelection(const Population<T> & population, Comparator cmp) : Selection<T> (population), cmp(cmp) {}


        IndividualPtr<T> select() {

            if (pool.empty()) {
                select(this->population.size());
            }

            return pop_back(pool);

        }

        Population<T> select(int n) {

            Population<T> copy;

            while (pool.size() <= n) {

                if (copy.size() < 2) {
                    copy = this->population;
                    std::random_shuffle(copy.begin(), copy.end());
                }

                IndividualPtr<T> a = pop_back(copy);

                if (pool.size() == n) break;
                IndividualPtr<T> b = pop_back(copy);

                std::cout << a->evaluate()[0] << ", " << a->evaluate()[1] << " vs " << b->evaluate()[0] << ", " << b->evaluate()[1] << std::endl;
                std::cout << "winner: " << std::max(a,b,cmp)->evaluate()[0]<< ", " << std::max(a,b,cmp)->evaluate()[1]<< std::endl;


                pool.push_back(std::max(a,b,cmp));
            }

            return pool;
        }






    };

}


#endif //MOO_BINARYSELECTOR_H
