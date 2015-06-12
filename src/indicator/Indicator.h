#ifndef MOO_INDICATOR_H
#define MOO_INDICATOR_H

#include <unordered_map>

namespace moo {

    template <typename T, typename IndicatorType>
    class Indicator {
    public:


        //virtual std::unordered_map<IndividualPtr<T>, IndicatorType> calculate(Population<T> pop);


        std::vector<double> getObjective(Population<T>& population, int objective)  {
            std::vector<double> result;
            for (int j = 0; j < population.size(); ++j) {
                result.push_back(getValue(population, j, objective));
            }
            return result;
        }


        void sortByIndicator(Population<T> & population, std::unordered_map<IndividualPtr<T>, IndicatorType> & m) {
            sort( population.begin(), population.end(), [&m]( const IndividualPtr<T>& lhs, const IndividualPtr<T>& rhs )
            {
                return m[lhs] > m[rhs];
            });
        }


        double getValue(Population<T>& population, int index, int objective)  {
            return population[index]->evaluate()[objective];
        }



        void sortByObjective(Population<T>& population, int objective)  {
            sort( population.begin(), population.end(), [objective]( const IndividualPtr<T>& lhs, const IndividualPtr<T>& rhs )
            {
                return lhs->evaluate()[objective] > rhs->evaluate()[objective];
            });
        }



    };

}


#endif //MOO_INDICATOR_H
