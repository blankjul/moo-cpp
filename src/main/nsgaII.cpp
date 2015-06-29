#include <iostream>
#include <cstdlib>
#include "algorithms/nsgaII/NSGAII.h"
#include "problems/Kursawe.h"

using namespace std;


int main(int argc, char** argv) {
    moo::Kursawe p;
    moo::NSGAII<moo::Kursawe> nsga(p);
    nsga.verbose = true;
    nsga.json = true;
    nsga.solve();
    return 0;
}

