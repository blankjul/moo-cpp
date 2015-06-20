#include <string>
#include "benchmark/benchmark.h"
#include "model/Population.h"
#include "problems/Identity.h"


class ParetoFront : public benchmark::Fixture {
public:
    moo::Population<moo::Identity> p{100000};
};



BENCHMARK_F(ParetoFront, BM_getParetoFrontByBookkeeping)(benchmark::State& state) {
    while (state.KeepRunning()) p.getParetoFrontByBookkeeping();
}

BENCHMARK_F(ParetoFront, BM_getParetoFront)(benchmark::State& state) {
    while (state.KeepRunning()) p.getParetoFront();
}


BENCHMARK_F(ParetoFront, BM_getParetoFrontByKung)(benchmark::State& state) {
    while (state.KeepRunning()) p.getParetoFrontByKung();
}

// Augment the main() program to invoke benchmarks if specified
// via the --benchmarks command line flag.  E.g.,
//       my_unittest --benchmark_filter=all
//       my_unittest --benchmark_filter=BM_StringCreation
//       my_unittest --benchmark_filter=String
//       my_unittest --benchmark_filter='Copy|Creation'
int main(int argc, char** argv) {
    benchmark::Initialize(&argc, (const char **) argv);
    benchmark::RunSpecifiedBenchmarks();
    return 0;
}