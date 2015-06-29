#include "AbstractBenchmark.h"
#include "algorithms/nsgaII/NSGAII.h"



class NSGAII : public AbstractBenchmark {
};


BENCHMARK_F(NSGAII, BM_SolveKursawe)(benchmark::State& state) {
    moo::Kursawe k;
    moo::NSGAII<moo::Kursawe> nsga(k);
    nsga.populationSize = 1000;
    while (state.KeepRunning())  nsga.solve();
}

