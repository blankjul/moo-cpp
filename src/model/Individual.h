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

    private:

        const typename Trait::InputType input;
        typename Trait::OutputType output;

    public:

        Individual() {}
        Individual(const typename Trait::InputType& i, bool eval = true) : input(i) {
            if (eval) evaluate();
        };


        bool isDominating(const Individual& other) const {
            for (unsigned int i = 0; i < getOutput().size(); ++i) {
                if (output[i] > other.output[i]) return false;
            }
            return !isEqual(other);
        }

        bool isDominatedBy(const Individual& other) const {
            for (unsigned int i = 0; i < getOutput().size(); ++i) {
                if (output[i] < other.output[i]) return false;
            }
            return !isEqual(other);
        }

        bool isEqual(const Individual& other) const {
            for (unsigned int i = 0; i < getOutput().size(); ++i) {
                if (other.output[i] != output[i]) return false;
            }
            return true;
        }

        void evaluate() {
            output = Trait::evaluate(input);
        }

        /*
        bool isDominating(IndividualPtr& other) const { return isDominating(*other);}

        bool isDominatedBy(IndividualPtr& other) const { return isDominatedBy(*other);}

        bool isEqual(IndividualPtr& other) const { return isEqual(*other);}

         */

        const typename Trait::InputType & getInput() const { return input; }

        const typename Trait::OutputType & getOutput() const {
            return output;
        }


    };




}


#endif //MOO_INDIVIDUAL_H