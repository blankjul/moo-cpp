
#include "benchmark/benchmark.h"



#include "benchmark/benchmark.h"
#include "model/Population.h"
#include "problems/Kursawe.h"
#include "indicator/NonDominatedRank.h"
#include "indicator/FastNonDominatedRank.h"




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