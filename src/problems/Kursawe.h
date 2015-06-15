#ifndef MOO_KURSAWE_H
#define MOO_KURSAWE_H

#include <utility>
#include "model/Problem.h"
#include "variables/VariableCollection.h"
#include "variables/Real.h"
#include <cmath>

namespace moo {


    class Kursawe : public Problem<VariableCollection<Real>, std::vector<double>> {

    public:

        virtual std::vector<double> evaluate_(const VariableCollection<Real> & input) {

            std::vector<double> x;
            for(auto entry : input) x.push_back(entry.getValue());

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


        virtual VariableCollection<Real> getInput() {
            VariableCollection<Real> i;
            for (int j = 0; j < 3; ++j) i.push_back(moo::Real(-5,5));
            return i;
        }


        virtual std::vector<double> getOutput() {
            return std::vector<double>(3);
        }



    };

}

#endif //MOO_KURSAWE_H

