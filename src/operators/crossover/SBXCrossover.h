#ifndef MOO_SBX_H
#define MOO_SBX_H

#include "Crossover.h"
#include "variables/VariableCollection.h"
#include "variables/Real.h"
#include "util/Random.h"
#include <cmath>

namespace moo {


    class SBXCrossover : public Crossover<SBXCrossover> {

    public:

        template <typename T>
        static T crossover_(const T & a, const T & b) {

            VariableCollection<Real> ra = static_cast<T>(a);
            VariableCollection<Real> rb = static_cast<T>(b);

            auto offa = ra;
            auto offb = rb;

            for (unsigned int i = 0; i < offa.size(); ++i) {
                SBXCrossover::evolve_(offa[i],offb[i], 0.5);
            }

            return offa;

        }


        static void evolve_(Real& a, Real& b, double distributionIndex) {

            double x0 = a.getValue();
            double x1 = b.getValue();

            double dx = fabs(x1 - x0);

            double lb = a.getLowerBound();
            double ub = b.getUpperBound();
            double bl;
            double bu;

            if (x0 < x1) {
                bl = 1 + 2 * (x0 - lb) / dx;
                bu = 1 + 2 * (ub - x1) / dx;
            } else {
                bl = 1 + 2 * (x1 - lb) / dx;
                bu = 1 + 2 * (ub - x0) / dx;
            }

            //use symmetric distributions
            if (bl < bu) {
                bu = bl;
            } else {
                bl = bu;
            }

            double p_bl = 1 - 1 / (2 * std::pow(bl, distributionIndex + 1));
            double p_bu = 1 - 1 / (2 * std::pow(bu, distributionIndex + 1));
            double u = Random::getInstance()->rndDouble();

            //prevent out-of-bounds values if PRNG draws the value 1.0
            if (u == 1.0) {
                u = std::nextafter(u,-1);
            }

            double u0 = u * p_bl;
            double u1 = u * p_bu;
            double b0;
            double b1;

            if (u0 <= 0.5) {
                b0 = std::pow(2 * u0, 1 / (distributionIndex + 1));
            } else {
                b0 = std::pow(0.5 / (1 - u0), 1 / (distributionIndex + 1));
            }

            if (u1 <= 0.5) {
                b1 = std::pow(2 * u1, 1 / (distributionIndex + 1));
            } else {
                b1 = std::pow(0.5 / (1 - u1), 1 / (distributionIndex + 1));
            }




            double aValue;
            double bValue;
            if (x0 < x1) {
                aValue = 0.5 * (x0 + x1 + b0 * (x0 - x1));
                bValue = 0.5 * (x0 + x1 + b1 * (x1 - x0));
            } else {
                aValue = 0.5 * (x0 + x1 + b1 * (x0 - x1));
                bValue = 0.5 * (x0 + x1 + b0 * (x1 - x0));
            }


            //guard against out-of-bounds values
            if (aValue < lb) {
                a.setValue(lb);
            } else if (aValue > ub) {
                a.setValue(ub);
            } else {
                a.setValue(aValue);
            }

            if (bValue < lb) {
                b.setValue(lb);
            } else if (bValue > ub) {
                b.setValue(ub);
            } else {
                b.setValue(bValue);
            }


            //this makes PISA's SBX compatible with other implementations
            //which swap the values
            if (Random::getInstance()->rndBool()) {
                double temp = a.getValue();
                a.setValue(b.getValue());
                b.setValue(temp);
            }




        }






    };

}


#endif //MOO_SBX_H
