#ifndef MOO_INDIVIDUAL_H
#define MOO_INDIVIDUAL_H

#include <vector>
#include <memory>


namespace moo {


    // forward declaration of the Problem class for the friendship!
    template <typename Input, typename Output> class Problem;

    template <typename Input = std::vector<double>, typename Output = std::vector<double>>
    class Individual
    {

        // the problem could set the output variable for the evaluation!
        friend class Problem<Input,Output>;

    private:

        Input input;
        Output output;
        bool evaluated;


    public:

        Individual(const Input& i) : input(i), evaluated(false) {};

        bool isDominating(Individual& other) const{
            for (int i = 0; i < getOutput().size(); ++i) {
                if (output[i] > other.output[i]) return false;
            }
            return !isEqual(other);
        }

        bool isDominatedBy(Individual& other) const{
            for (int i = 0; i < getOutput().size(); ++i) {
                if (output[i] < other.output[i]) return false;
            }
            return !isEqual(other);
        }

        bool isEqual(Individual& other) const{
            for (int i = 0; i < getOutput().size(); ++i) {
                if (other.output[i] != output[i]) return false;
            }
            return true;
        }

        bool isDominating(std::shared_ptr<Individual<Input>>& other) const { return isDominating(*other);}

        bool isDominatedBy(std::shared_ptr<Individual<Input>>& other) const { return isDominatedBy(*other);}

        bool isEqual(std::shared_ptr<Individual<Input>>& other) const { return isEqual(*other);}

        int countObjectives() { return getOutput().size();}

        Input getInput() const { return input; }

        Output getOutput() const {
            if (!evaluated) throw std::runtime_error("Please evaluate the individual first!");
            return output;
        }

        bool isEvaluated() const { return evaluated;}

        void setInput(Input in) {
            input = in;
            evaluated = false;
        }


    };

    template<typename Input> using IndividualPtr = std::shared_ptr<Individual<Input>>;

    template<typename Input> IndividualPtr<Input> createIndividual(const Input& i) {
        return std::make_shared<Individual<Input>>(i);
    }


}


#endif //MOO_INDIVIDUAL_H