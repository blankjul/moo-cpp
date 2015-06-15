#ifndef MOO_IDENTITY_H
#define MOO_IDENTITY_H

#include <utility>
#include "model/Problem.h"

namespace moo {

    class Identity : public Problem<std::vector<double>,std::vector<double>> {

    public:

        virtual std::vector<double> evaluate_(const std::vector<double> & x) {
            std::vector<double> result = x;
            return result;
        }

        virtual std::vector<double> getInput() {
            return std::vector<double>();
        };

        virtual std::vector<double> getOutput() {
            return std::vector<double>();
        };

    };

}

#endif //MOO_IDENTITY_H

