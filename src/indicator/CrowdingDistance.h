
#ifndef MOO_CROWDEDDISTANCE_H
#define MOO_CROWDEDDISTANCE_H

#include "Indicator.h"
#include "Util.h"
#include <vector>
#include <map>
#include <limits>




namespace moo {


    class CrowdingDistance : public Indicator<CrowdingDistance, double> {

        template<typename T> using Map = std::unordered_map<IndividualPtr<T>, double>;


    public:

        template <typename T>
        static Map<T> calculate_(const Population<T> & pop) {
            std::vector<double> min;
            std::vector<double> max;
            for (int j = 0; j < T::getOutput().size(); ++j) {
                auto v = getObjective(pop,j);
                min.push_back(*std::min(v.begin(), v.end()));
                max.push_back(*std::max(v.begin(), v.end()));
            }
            return calculate_(pop, min, max);
        }


        template <typename T>
        static Map<T> calculate_(const Population<T> & pop, std::vector<double>& min, std::vector<double>& max ) {

            typedef typename std::vector<IndividualPtr<T>>::iterator Iterator;
            Map<T> m;

            for (auto it = pop.begin(); it != pop.end(); ++it) m[*it] = 0;

            int numOfObjectives = pop[0]->getOutput().size();
            if (min.size() != numOfObjectives || max.size() != numOfObjectives) throw std::runtime_error("The boundary size and objective size does not match!");

            for (int i = 0; i < numOfObjectives; ++i) {
                auto sorted = sortByObjective(pop, i);
                double denominator = max[i] - min[i];

                m[sorted[0]] = std::numeric_limits<double>::infinity();
                m[sorted[sorted.size()-1]] = std::numeric_limits<double>::infinity();

                for (int j = 1; j < sorted.size() - 1; ++j) {
                    m[sorted[j]] += (getValue(sorted, j-1, i) - getValue(sorted, j+1, i)) / denominator;
                }
            }

            return m;
        }




    };



}





#endif //MOO_CROWDEDDISTANCE_H
