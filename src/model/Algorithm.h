#ifndef MOO_ALGORITHM_H
#define MOO_ALGORITHM_H


namespace moo {

    template <typename Trait>
    class Algorithm {

    public:

        typename Trait::OutputType solve(const Trait&  p);

    };

}




#endif //MOO_ALGORITHM_H
