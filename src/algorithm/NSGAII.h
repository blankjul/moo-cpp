
#ifndef MOO_NSGAII_H
#define MOO_NSGAII_H

#include "Algorithm.h"
#include "model/ParetoFront.h"



namespace moo {


    class NSGAII : public Algorithm<Problem,ParetoFront> {

    private:



    public:



        virtual ParetoFront solve(const Problem& p) {








            return ParetoFront();
        }





    };

}

#endif //MOO_NSGAII_H
