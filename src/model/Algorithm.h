#ifndef MOO_ALGORITHM_H
#define MOO_ALGORITHM_H

namespace moo {

    template <typename Problem, typename Result>
    class Algorithm {
    public:
        virtual Result solve(Problem&) = 0;
    };

}


#endif //MOO_ALGORITHM_H
