#ifndef MOO_INDICATOR_H
#define MOO_INDICATOR_H

#include <algorithm>
#include <unordered_map>
#include "model/Individual.h"
#include "model/Population.h"

namespace moo {


    template <typename DerivedClass, typename IndicatorType>
    class Indicator {

    public:

        template <typename Trait> std::unordered_map<IndividualPtr<Trait>, IndicatorType> static calculate(const Population<Trait> & population) {
            return DerivedClass::calculate_(population);
        }


    };



}


#endif //MOO_INDICATOR_H
