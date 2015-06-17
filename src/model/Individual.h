#ifndef MOO_INDIVIDUAL_H
#define MOO_INDIVIDUAL_H

#include <vector>
#include <memory>


namespace moo {





    template<typename Trait> class Individual;
    template<typename Trait> using IndividualPtr = std::shared_ptr<Individual<Trait>>;
    template<typename Trait> using IndividualComparator = std::function<bool(const IndividualPtr<Trait>&,const IndividualPtr<Trait>&)>;

    template< typename Trait>
    class Individual
    {

        // the problem could set the output variable for the evaluation!
        template<class T> friend class Evaluator;


    private:

        typename Trait::InputType input;
        typename Trait::OutputType output;
        bool evaluated;


    public:

        Individual() {}
        Individual(const typename Trait::InputType& i) : input(i), evaluated(false) {};


        bool isDominating(Individual& other) const{
            for (unsigned int i = 0; i < getOutput().size(); ++i) {
                if (output[i] > other.output[i]) return false;
            }
            return !isEqual(other);
        }

        bool isDominatedBy(Individual& other) const{
            for (unsigned int i = 0; i < getOutput().size(); ++i) {
                if (output[i] < other.output[i]) return false;
            }
            return !isEqual(other);
        }

        bool isEqual(Individual& other) const{
            for (unsigned int i = 0; i < getOutput().size(); ++i) {
                if (other.output[i] != output[i]) return false;
            }
            return true;
        }

        /*
        bool isDominating(IndividualPtr& other) const { return isDominating(*other);}

        bool isDominatedBy(IndividualPtr& other) const { return isDominatedBy(*other);}

        bool isEqual(IndividualPtr& other) const { return isEqual(*other);}

         */

        typename Trait::InputType getInput() const { return input; }

        typename Trait::OutputType getOutput() const {
            if (!evaluated) throw std::runtime_error("Please evaluate the individual first!");
            return output;
        }

        bool isEvaluated() const { return evaluated;}

        void setInput(const typename Trait::InputType& in) {
            input = in;
            evaluated = false;
        }




    };




}


#endif //MOO_INDIVIDUAL_H