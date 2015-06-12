
#ifndef MOO_RANDOM_H
#define MOO_RANDOM_H



namespace moo {

    double rndDouble() {
        return  ((double) std::rand() / (RAND_MAX));
    }

}


#endif //MOO_RANDOM_H
