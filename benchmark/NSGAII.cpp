#include "AbstractBenchmark.h"
#include "algorithms/nsgaII/NSGAII.h"



class NSGAII : public AbstractBenchmark {
};


BENCHMARK_F(NSGAII, BM_SolveKursawe)(benchmark::State& state) {
    moo::NSGAII<moo::Kursawe> nsga;
    nsga.maxGeneration = 10;
    nsga.populationSize = 1000;
    moo::Kursawe k;
    while (state.KeepRunning())  nsga.solve(k);
}

