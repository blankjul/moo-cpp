#include "Random.h"
#include <cstdlib>


double moo::rndDouble() {
    return  ((double) std::rand() / (RAND_MAX));
}

int moo::rndInt(int min, int max) {
    return min + (std::rand() % (int)(max - min + 1));
}