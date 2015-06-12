
#ifndef MOO_CROWDEDDISTANCE_H
#define MOO_CROWDEDDISTANCE_H

#include "Indicator.h"
#include "model/Individual.h"
#include "model/Population.h"
#include <vector>
#include <map>
#include <limits>




namespace moo {


    template <typename T>
    class CrowdedDistance : public Indicator<T, double> {

    private:

        std::vector<double> min;
        std::vector<double> max;

    public:


        std::unordered_map<IndividualPtr<T>, double> calculate(Population<T> pop, std::vector<double>* min, std::vector<double>* max ) {

            typedef typename Population<T>::iterator Iterator;
            std::unordered_map<IndividualPtr<T>, double> m;

            for (Iterator it = pop.begin(); it != pop.end(); ++it) m[*it] = 0;

            int numOfObjectives = pop[0]->evaluate().size();
            if (min->size() != numOfObjectives || max->size() != numOfObjectives) throw std::runtime_error("The boundary size and objective size does not match!");

            for (int i = 0; i < numOfObjectives; ++i) {
                this->sortByObjective(pop, i);

                double denominator = (*max)[i] - (*min)[i];

                m[pop[0]] = std::numeric_limits<double>::infinity();
                m[pop[pop.size()-1]] = std::numeric_limits<double>::infinity();

                for (int j = 1; j < pop.size() - 1; ++j) {
                    m[pop[j]] += (this->getValue(pop, j-1, i) - this->getValue(pop, j+1, i)) / denominator;
                }
            }

            return m;
        }




    };



}





#endif //MOO_CROWDEDDISTANCE_H
