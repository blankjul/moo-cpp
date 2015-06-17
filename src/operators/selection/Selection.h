#ifndef MOO_SELECTOR_H
#define MOO_SELECTOR_H

#include "model/Population.h"

namespace moo {

    template <typename DerivedClass>
    class Selection {

    public:


        template <typename Trait> IndividualPtr<Trait> static select(const Population<Trait> & population) {
            return DerivedClass::select_(population);
        }

        template <typename Trait> Population<Trait> static selectMultiple(const Population<Trait> & population) {
            return DerivedClass::selectMultiple_(population);
        }



    };

}


#endif //MOO_SELECTOR_H
