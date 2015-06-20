#include "AbstractBenchmark.h"
#include "indicator/NonDominatedRank.h"
#include "indicator/FastNonDominatedRank.h"


class NonDominatedSorting : public AbstractBenchmark {
};



BENCHMARK_F(NonDominatedSorting, BM_NonDominatedSorting)(benchmark::State& state) {
    while (state.KeepRunning()) moo::NonDominatedRank::calculate_(population);
}


BENCHMARK_F(NonDominatedSorting, BM_FastNonDominatedSorting)(benchmark::State& state) {
    while (state.KeepRunning()) moo::FastNonDominatedRank::calculate_(population);
}


