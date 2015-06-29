#include "algorithms/moead/MOEAD.h"
#include "problems/Kursawe.h"


int main(int argc, char** argv) {
    moo::Kursawe p;
    moo::MOEAD<moo::Kursawe> moead(p);
    moead.verbose = true;
    moead.json = true;
    moead.maxGeneration = 10000;
    moead.solve();
    return 0;
}

