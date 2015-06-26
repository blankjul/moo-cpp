#include <model/ParetoFront.h>
#include "AbstractBenchmark.h"
#include "util/paretoFrontCalculator/ContUpdatedParetoFront.h"
#include "util/paretoFrontCalculator/NaiveParetoFront.h"
#include "util/paretoFrontCalculator/KungParetoFront.h"


class ParetoFront : public AbstractBenchmark {
public:


};



BENCHMARK_F(ParetoFront, BM_getParetoFrontNaive)(benchmark::State& state) {
    while (state.KeepRunning()) moo::NaiveParetoFront::getParetoFront(population);;
}

BENCHMARK_F(ParetoFront, BM_getParetoFrontContUpdated)(benchmark::State& state) {
    while (state.KeepRunning()) moo::ContUpdatedParetoFront::getParetoFront(population);;
}

BENCHMARK_F(ParetoFront, BM_getParetoFrontContUpdatedVector)(benchmark::State& state) {
    moo::ParetoFront<moo::Kursawe> front;
    while (state.KeepRunning()) for (unsigned int i = 0; i < population.size(); ++i) front.add(population[i]);
}


BENCHMARK_F(ParetoFront, BM_getParetoFrontKung)(benchmark::State& state) {
    while (state.KeepRunning()) moo::KungParetoFront::getParetoFront(population);
}

BENCHMARK_F(ParetoFront, BM_DereferencePointer)(benchmark::State& state) {
    while (state.KeepRunning())  {
        std::vector<moo::Individual<moo::Kursawe>> elements;
        for (auto entry : population) elements.push_back(*entry);
    }
}

