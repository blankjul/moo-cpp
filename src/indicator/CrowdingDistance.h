
#ifndef MOO_CROWDEDDISTANCE_H
#define MOO_CROWDEDDISTANCE_H

#include "Indicator.h"
#include <vector>
#include <map>
#include <limits>
#include <cmath>
#include <algorithm>




namespace moo {


    class CrowdingDistance : public Indicator<CrowdingDistance, double> {

        template<typename T> using Map = std::unordered_map<IndividualPtr<T>, double>;


    public:

        template <typename T>
        static Map<T> calculate_(const Population<T> & pop) {
            std::vector<double> min;
            std::vector<double> max;
            bounds_(pop, min,max);
            return calculate_(pop, min, max);
        }

        template <typename T>
        static void bounds_(const Population<T> & pop, std::vector<double>& min, std::vector<double>& max ) {
            for (int j = 0; j < T::getOutput().size(); ++j) {
                auto v = pop.getObjective(j);
                min.push_back(*std::min_element(v.begin(), v.end()));
                max.push_back(*std::max_element(v.begin(), v.end()));
            }
        }


        template <typename T>
        static Map<T> calculate_(const Population<T> & pop, std::vector<double>& min, std::vector<double>& max ) {

            typedef typename std::vector<IndividualPtr<T>>::iterator Iterator;

            Map<T> m;
            for (auto it = pop.begin(); it != pop.end(); ++it) m[*it] = 0;

            auto sorted = pop;
            int numOfObjectives = sorted[0]->getOutput().size();
            if (min.size() != numOfObjectives || max.size() != numOfObjectives) throw std::runtime_error("The boundary size and objective size does not match!");

            for (int i = 0; i < numOfObjectives; ++i) {

                sorted = sorted.sortByObjective(i);

                double denominator = max[i] - min[i];
                if (denominator < 0) throw std::runtime_error("Error min and max values couldn't be correct!");


                m[sorted[0]] = std::numeric_limits<double>::infinity();
                m[sorted[sorted.size() - 1]] = std::numeric_limits<double>::infinity();

                for (int j = 1; j < sorted.size() - 1; ++j) {
                    if (std::isinf(m[sorted[j]])) continue;
                    m[sorted[j]] += (sorted[j+1]->getOutput()[i] - sorted[j-1]->getOutput()[i]) / denominator;
                }
            }

            return m;
        }




    };



}





#endif //MOO_CROWDEDDISTANCE_H
