#ifndef MOO_KURSAWE_H
#define MOO_KURSAWE_H

#include <utility>
#include "model/Problem.h"

namespace moo {

    class Kursawe : public Problem<std::vector<double>> {

    public:
        std::vector<double> evaluate(const std::vector<double> & x) {

            std::vector<double> fx(2,0);
            int numberOfVariables_ = x.size();
            double aux, xi, xj;

            for (int var = 0; var < numberOfVariables_ - 1; var++) {
                xi = x[var] *  x[var];
                xj = x[var+1] * x[var+1] ;
                aux = (-0.2) * sqrt(xi + xj);
                fx[0] += (-10.0) * exp(aux);
            }

            for (int var = 0; var < numberOfVariables_ ; var++) {
                fx[1] += pow(fabs(x[var]), 0.8) +
                         5.0 * sin(pow(x[var], 3.0));
            }

            return fx;
        }

    };

}

#endif //MOO_KURSAWE_H

