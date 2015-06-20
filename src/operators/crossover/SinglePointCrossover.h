#ifndef MOO_SINGLEPOINTCROSSOVER_H
#define MOO_SINGLEPOINTCROSSOVER_H

#include "Crossover.h"
#include "util/Random.h"

namespace moo {


    class SinglePointCrossover : public Crossover<SinglePointCrossover> {

    public:

        template <typename T>
        static T crossover_(const T & a, const T & b, int point = -1) {
            T off = a;
            if (point < 0 || point > a.size()) point = Random::getInstance()->rndInt(0,b.size());
            for (int i = point; i < b.size(); ++i) {
                off[i] = b[i];
            }
            return off;
        }




    };

}


#endif //MOO_SINGLEPOINTCROSSOVER_H
