#ifndef MOO_SELECTOR_H
#define MOO_SELECTOR_H

#include "model/Population.h"

namespace moo {

    template <typename T>
    class Selection {

    protected:

        const Population<T> & population;

    public:


        Selection(const Population<T> &population) : population(population) {}

        virtual IndividualPtr<T> select() = 0;


        Population<T> select(int n) {
            Population<T> pop;
            for (int i = 0; i < n; ++i) {
                pop.push_back(select());
            }
            return pop;
        }



    };

}


#endif //MOO_SELECTOR_H
