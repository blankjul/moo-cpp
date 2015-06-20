#ifndef MOO_SELECTOR_H
#define MOO_SELECTOR_H

#include "model/Population.h"

namespace moo {

    template <typename DerivedClass>
    class Selection {

    public:


        template <typename Trait> IndividualPtr<Trait> select(const Population<Trait> & population) {
            return static_cast<DerivedClass*>(this)->select_(population);
        }

        template <typename Trait> Population<Trait> selectMultiple(const Population<Trait> & population, int n) {
            return static_cast<DerivedClass*>(this)->selectMultiple_(population, n);
        }



    };

}


#endif //MOO_SELECTOR_H
