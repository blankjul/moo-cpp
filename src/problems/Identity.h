#ifndef MOO_IDENTITY_H
#define MOO_IDENTITY_H

#include <utility>
#include "model/Problem.h"

namespace moo {

    class Identity : public Problem<std::vector<double>> {

    public:
        std::vector<double> evaluate(const std::vector<double> & x) {
            std::vector<double> result = x;
            return result;
        }

    };

}

#endif //MOO_IDENTITY_H

