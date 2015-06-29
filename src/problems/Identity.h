#ifndef MOO_IDENTITY_H
#define MOO_IDENTITY_H

#include <vector>
#include "model/Problem.h"
#include "util/Random.h"
#include <initializer_list>

namespace moo {

    struct Mock : public std::vector<double>  {

        Mock() {}
        Mock (std::initializer_list<double> list) : std::vector<double>(list) {}
        Mock (const std::vector<double>& v) {
            for (unsigned int i = 0; i < v.size(); ++i) {
                push_back(v[i]);
            }
        }

        Mock random() const {
            std::vector<double> v;
            auto random = Random::getInstance();
            for (unsigned int i = 0; i < size(); ++i) {
                v.push_back(random->rndDouble());
            }
            return Mock(v);
        }
    };



class Identity : public Problem<Identity>
{

    public:

        typedef Mock InputType;
        typedef std::vector<double> OutputType;


        static OutputType evaluate(const InputType& input) {
            return input;
        }

        static InputType getInput() {
            return Mock(std::vector<double>(2));
        }

        static OutputType getOutput() {
            return std::vector<double>(2);
        }
};



}

#endif //MOO_IDENTITY_H
