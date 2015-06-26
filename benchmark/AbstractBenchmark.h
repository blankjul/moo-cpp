
#include "benchmark/benchmark.h"
#include "model/Population.h"
#include "problems/Kursawe.h"

#ifndef MOO_ABSTRACT_BENCHMARK_H
#define MOO_ABSTRACT_BENCHMARK_H


class BenchmarkPopulation
{
public:
    static BenchmarkPopulation * getInstance() { return _singletonInst;};

    moo::Population<moo::Kursawe> small{1000};
    moo::Population<moo::Kursawe> large{1000000};

private:

    static BenchmarkPopulation * _singletonInst ;
    BenchmarkPopulation() { }
    BenchmarkPopulation(BenchmarkPopulation const&);
    void operator=(BenchmarkPopulation const&);
};


class AbstractBenchmark : public benchmark::Fixture {

public:
    moo::Population<moo::Kursawe> population {100000};
};




#endif //MOO_ABSTRACT_BENCHMARK_H