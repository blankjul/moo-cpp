#ifndef MOO_POPULATION_H
#define MOO_POPULATION_H


#include "Individual.h"
#include <vector>
#include <list>
#include <stack>
#include <iostream>
#include <algorithm>
#include <unordered_map>



namespace moo {




    template<typename Trait>
    class Population : public std::vector<IndividualPtr<Trait>>  {

        class ContUpdatedParetoFront;

    public:

        Population() : std::vector<IndividualPtr<Trait>>() {}

        Population(const std::vector<IndividualPtr<Trait>> &individuals) : std::vector<IndividualPtr<Trait>>(individuals){ }

        Population(int n) {
            for (int i = 0; i < n; ++i) {
                typename Trait::InputType in = Trait::getInput().random();
                auto ind = std::make_shared<Individual<Trait>>(in);
                this->push_back(ind);
            }
        }


        bool isNonDominated(const IndividualPtr<Trait> & ind) const {
            for (auto entry : *this) {
                if (ind->isDominatedBy(*entry)) return true;
            }
            return false;
        }


        const IndividualPtr<Trait> pop_back_and_delete() {
            IndividualPtr<Trait> a = this->back();
            this->pop_back();
            return a;
        }

        void remove(const Population<Trait> & pop)  {
            for (auto entry : pop) {
                this->erase(std::remove(this->begin(), this->end(), entry), this->end());
            }
        }


        typename Trait::OutputType getObjective (int objective) const {
            typename Trait::OutputType v;
            for (int j = 0; j < this->size(); ++j) v.push_back(getValue(j, objective));
            return v;
        }


        double getValue(int index, int objective) const {
            return (*this)[index]->getOutput()[objective];
        }


        template<typename T>
        Population<Trait> sortByVector(const std::vector<T> & v, bool isDescending = false) {
            std::vector<int> index;
            for (int i = 0; i < this->size(); ++i) index.push_back(i);
            auto asc = [&v]( const int & lhs, const int & rhs ) { return v[lhs] < v[rhs];};
            auto desc = [&v]( const int & lhs, const int & rhs ) { return v[lhs] > v[rhs];};
            if (isDescending) std::sort(index.begin(), index.end(), desc);
            else std::sort(index.begin(), index.end(), asc);
            Population<Trait> result(v.size());
            for (int j = 0; j < index.size(); ++j) result[j] = (*this)[index[j]];
            return result;
        }



        template <typename T>
        Population<Trait> sortByMap(std::unordered_map<IndividualPtr<Trait>, T> & m, bool isDescending = false) {
            std::vector<T> v;
            for (int i = 0; i < this->size(); ++i) v.push_back(m[(*this)[i]]);
            return sortByVector(v, isDescending);
        }



        Population<Trait> sortByObjective(int objective, bool isDescending = false) {
            return sortByVector(getObjective(objective), isDescending);
        }


        friend std::ostream & operator<<(std::ostream & s, const Population<Trait> & pop) {
            std::cout << "---------------------------\n";
            std::cout << "Size: " << pop.size() << std::endl;
            std::cout << "---------------------------\n";
            for (int i = 0; i < pop.size(); ++i) {
                auto entry = pop[i];
                std::cout << entry->getOutput()[0] << ", " << entry->getOutput()[1]<<std::endl;
            }
            std::cout << "---------------------------\n";
            return s;
        }




    };




}


#endif //MOO_POPULATION_H