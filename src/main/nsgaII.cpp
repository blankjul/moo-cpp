#include <iostream>
#include <cstdlib>
#include <fstream>
#include <bits/error_constants.h>
#include "algorithms/nsgaII/NSGAII.h"
#include "problems/Kursawe.h"
#include <ctime>

using namespace std;


int main(int argc, char** argv) {
    ofstream* out = nullptr;
    
    if (argc < 3) {
        std::cout << "Please define population and maxGeneration!";
        return 1;
    }  


    
    if (argc == 4) {
        out = new ofstream();
        out->open(argv[3]);
    }
    
    moo::Kursawe p;
    moo::NSGAII<moo::Kursawe> nsga(p);
        
    nsga.populationSize = atoi(argv[1]);
    nsga.maxGeneration = atoi(argv[2]);
    
    std::clock_t start;
    double duration;
    start = std::clock();
    nsga.solve(&std::cout, out);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"time: "<< duration <<'\n';

    
    
    if (out != nullptr) out->close();
    return 0;
}

