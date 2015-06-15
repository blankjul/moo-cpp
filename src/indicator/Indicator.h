#ifndef MOO_INDICATOR_H
#define MOO_INDICATOR_H

#include <unordered_map>

namespace moo {


    template <typename IndicatorType>
    class Indicator {

    public:


        template <typename T> std::unordered_map<IndividualPtr<T>, IndicatorType> calculate(Population<T> pop);


        template <typename T> std::vector<double> getObjective(Population<T>& population, int objective)  {
            std::vector<double> result;
            for (int j = 0; j < population.size(); ++j) {
                result.push_back(getValue(population, j, objective));
            }
            return result;
        }


        template <typename T> void sortByIndicator(Population<T> & population, std::unordered_map<IndividualPtr<T>, IndicatorType> & m) {
            sort( population.begin(), population.end(), [&m]( const IndividualPtr<T>& lhs, const IndividualPtr<T>& rhs )
            {
                return m[lhs] > m[rhs];
            });
        }


        template <typename T> double getValue(Population<T>& population, int index, int objective)  {
            return population[index]->getOutput()[objective];
        }



        template <typename T> void sortByObjective(Population<T>& population, int objective)  {
            sort( population.begin(), population.end(), [objective]( const IndividualPtr<T>& lhs, const IndividualPtr<T>& rhs )
            {
                return lhs->getOutput()[objective] > rhs->getOutput()[objective];
            });
        }



    };

}


#endif //MOO_INDICATOR_H
