#ifndef MOO_INDICATORUTIL_H
#define MOO_INDICATORUTIL_H

#include <algorithm>
#include <unordered_map>
#include "model/Individual.h"
#include "model/Population.h"

namespace moo {


        template <typename T>
        Population<T> sort(const Population<T>& population, IndividualComparator<T>& func) {
            auto v = population;
            std::sort(v.begin(), v.end(), func);
            return Population<T>(v);
        }

        template <typename T>
        Population<T> sortByObjective(const Population<T>& population, int objective) {
            IndividualComparator<T> func = [&objective]( const IndividualPtr<T>& lhs, const IndividualPtr<T>& rhs )
            {
                return lhs->getOutput()[objective] > rhs->getOutput()[objective];
            };
            return sort(population, func);
        }

    template <typename T>
    void sortByObjectiveInplace(Population<T>& population, int objective) {
        IndividualComparator<T> func = [&objective]( const IndividualPtr<T>& lhs, const IndividualPtr<T>& rhs )
        {
            return lhs->getOutput()[objective] > rhs->getOutput()[objective];
        };
        std::sort(population.begin(), population.end(), func);
    }

    template <typename T>
    void sortByObjectiveInplaceReverse(Population<T>& population, int objective) {
        IndividualComparator<T> func = [&objective]( const IndividualPtr<T>& lhs, const IndividualPtr<T>& rhs )
        {
            return lhs->getOutput()[objective] < rhs->getOutput()[objective];
        };
        std::sort(population.begin(), population.end(), func);
    }

        template <typename T,typename IndicatorType  >
        Population<T> sortByIndicator(const Population<T>& population, std::unordered_map<IndividualPtr<T>, IndicatorType> & m) {
            IndividualComparator<T> func = [&m]( const IndividualPtr<T>& lhs, const IndividualPtr<T>& rhs )
            {
                return m[lhs] > m[rhs];
            };
            return sort(population, func);
        }

        template <typename T,typename IndicatorType  >
        void sortByIndicatorInplace(Population<T>& population, std::unordered_map<IndividualPtr<T>, IndicatorType> & m) {
        IndividualComparator<T> func = [&m]( const IndividualPtr<T>& lhs, const IndividualPtr<T>& rhs )
        {
            return m[lhs] > m[rhs];
        };
            std::sort(population.begin(), population.end(), func);

         }

    template <typename T,typename IndicatorType  >
    void sortByIndicatorInplaceReverse(Population<T>& population, std::unordered_map<IndividualPtr<T>, IndicatorType> & m) {
        IndividualComparator<T> func = [&m]( const IndividualPtr<T>& lhs, const IndividualPtr<T>& rhs )
        {
            return m[lhs] < m[rhs];
        };
        std::sort(population.begin(), population.end(), func);

    }





}


#endif //MOO_INDICATORUTIL_H
