
#include "benchmark/benchmark.h"
#include "model/Population.h"
#include "problems/Kursawe.h"


class AbstractBenchmark : public benchmark::Fixture {
public:
    moo::Population<moo::Kursawe> population{10000};

};



