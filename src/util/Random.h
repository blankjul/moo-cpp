
#ifndef MOO_RANDOM_H
#define MOO_RANDOM_H



namespace moo {

    double rndDouble() {
        return  ((double) std::rand() / (RAND_MAX));
    }

    int rndInt(int min, int max) {
        return min + (std::rand() % (int)(max - min + 1));
    }


}


#endif //MOO_RANDOM_H
