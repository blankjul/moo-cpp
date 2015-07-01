
#include "benchmark/benchmark.h"
#include "model/Population.h"
#include "problems/Kursawe.h"

#ifndef MOO_ABSTRACT_BENCHMARK_H
#define MOO_ABSTRACT_BENCHMARK_H



class AbstractBenchmark : public benchmark::Fixture {

public:
    moo::Population<moo::Kursawe> population {10000};
};




#endif //MOO_ABSTRACT_BENCHMARK_H