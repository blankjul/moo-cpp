#ifndef MOO_INDIVIDUAL_H
#define MOO_INDIVIDUAL_H

#include "Problem.h"
#include <vector>
#include <memory>

namespace moo {




    template <typename Input = std::vector<double>>
    class Individual
    {


    private:

        ProblemPtr<Input> problem;
        Input input;
        std::vector<double> output;

    public:

        Individual(const ProblemPtr<Input>& p, const Input& i) : input(i), problem(p){};

        const std::vector<double>& evaluate() {
            if (output.empty()) output = problem->evaluate(input);
            return output;
        }

        bool isDominating(Individual& other) {
            for (int i = 0; i < evaluate().size(); ++i) {
                if (evaluate()[i] > other.evaluate()[i]) return false;
            }
            return !isEqual(other);
        }

        bool isDominatedBy(Individual& other) {
            for (int i = 0; i < evaluate().size(); ++i) {
                if (evaluate()[i] < other.evaluate()[i]) return false;
            }
            return !isEqual(other);
        }


        bool isEqual(Individual& other) {
            for (int i = 0; i < evaluate().size(); ++i) {
                if (other.evaluate()[i] != evaluate()[i]) return false;
            }
            return true;
        }

        int countObjectives() {
            return evaluate().size();
        }

        Input getInput() const {
            return input;
        }


        void setInput(Input input) {
            Individual::input = input;
            output.clear();
        }
    };

    template<typename T> using IndividualPtr = std::shared_ptr<Individual<T>>;

    template<typename T> IndividualPtr<T> createIndividual(const ProblemPtr<T>& p,const T& i) {
        return std::make_shared<Individual<T>>(i,p);
    }



}


#endif //MOO_INDIVIDUAL_H