#ifndef MOO_SELECTOR_H
#define MOO_SELECTOR_H

#include "model/Population.h"

namespace moo {


    class Selection {

    public:


        template <typename T> IndividualPtr<T> select(const Population<T> &population) ;

        template <typename T> Population<T> select(const Population<T> &population, int n) {
            Population<T> result;
            for (int i = 0; i < n; ++i) {
                result.push_back(select(population));
            }
            return result;
        }



    };

}


#endif //MOO_SELECTOR_H
