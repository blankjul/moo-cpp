#ifndef MOO_POPULATION_H
#define MOO_POPULATION_H


#include "Individual.h"
#include <vector>
#include <list>
#include <stack>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <initializer_list>



namespace moo {




    template<typename Trait>
    class Population : public std::vector<IndividualPtr<Trait>>  {

        class ContUpdatedParetoFront;

    public:

        Population (std::initializer_list<IndividualPtr<Trait>> list) : std::vector<IndividualPtr<Trait>>(list) {}
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
        void sortByVector(const std::vector<T> & v, bool isDescending = false) {
            std::unordered_map<IndividualPtr<Trait>, T> m;
            for (int i = 0; i < this->size(); ++i) m[(*this)[i]] = v[i];
            sortByMap(m, isDescending);
        }

        template <typename T>
        std::vector<int> sortedIndexByVector(const std::vector<T> & v, bool isDescending = false) const{
            std::vector<int> index = getIndex();
            if (isDescending) {
                std::sort(index.begin(), index.end(),[&v]( const int & lhs, const int & rhs)
                {return v[lhs] > v[rhs];});
            } else std::sort(index.begin(), index.end(),[&v]( const int & lhs, const int & rhs )
                {return v[lhs] < v[rhs];});
            return index;
        }


        template <typename T>
        void sortByMap(std::unordered_map<IndividualPtr<Trait>, T> & m, bool isDescending = false) {
            if (isDescending) {
                std::sort(this->begin(), this->end(),[&m]( const IndividualPtr<Trait> & lhs, const IndividualPtr<Trait> & rhs )
                {return m[lhs] > m[rhs];});
            } else std::sort(this->begin(), this->end(),[&m]( const IndividualPtr<Trait> & lhs, const IndividualPtr<Trait> & rhs )
                {return m[lhs] < m[rhs];});
        }


        void sortByObjective(int objective, bool isDescending = false) {
            sortByVector(getObjective(objective), isDescending);
        }

        std::vector<int> getIndex() const {
            std::vector<int> index (this->size());
            for (int k = 0; k < this->size(); ++k) index[k] = k;
            return index;
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