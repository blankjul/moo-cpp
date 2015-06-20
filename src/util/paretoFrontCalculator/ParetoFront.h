#ifndef MOO_PARETOFRONTCALC_H
#define MOO_PARETOFRONTCALC_H

#include "model/Population.h"


namespace moo {


    template <typename DerivedClass>
    class ParetoFrontCalc {

    public:


        template <typename Trait>
        static Population<Trait> getParetoFront(const Population<Trait> & pop)
        {
            return DerivedClass::getParetoFront(pop);
        }

    };

}



#endif //MOO_PARETOFRONTCALC_H
