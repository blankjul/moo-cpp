#include "algorithms/moead/MOEAD.h"
#include "problems/Kursawe.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>


int main(int argc, char** argv) {
        std::ofstream* out = nullptr;
    
    if (argc < 4) {
        std::cout << "Please define population and maxGeneration!\n";
        return 1;
    }  


    
    if (argc == 5) {
        out = new std::ofstream();
        out->open(argv[4]);
    }
    
    moo::Kursawe p;
    moo::MOEAD<moo::Kursawe> moead(p);
        
    moead.populationSize = atoi(argv[1]);
    moead.T = atoi(argv[2]);
    moead.maxGeneration = atoi(argv[3]);

    std::clock_t start;
    double duration;
    start = std::clock();
    moead.solve(&std::cout, out);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"time: "<< duration <<'\n';
    
    if (out != nullptr) out->close();
    return 0;
 
}

