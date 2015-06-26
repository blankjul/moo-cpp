#include "AbstractBenchmark.h"
#include "model/Population.h"



class Population : public AbstractBenchmark {
public:
    std::vector<moo::Individual<moo::Kursawe>> dereference (const std::vector<moo::IndividualPtr<moo::Kursawe>>& population) {
        std::vector<moo::Individual<moo::Kursawe>> elements;
        for (auto entry : population) elements.push_back(*entry);
        return elements;
    }
};


BENCHMARK_F(Population, BM_SortByPointer)(benchmark::State& state) {
    auto func = []( const moo::IndividualPtr<moo::Kursawe> & lhs, const moo::IndividualPtr<moo::Kursawe> & rhs )
    {
        return lhs->getOutput()[0] > rhs->getOutput()[0];
    };
    while (state.KeepRunning())  std::sort(population.begin(), population.end(), func);
}

BENCHMARK_F(Population, BM_SortByObj)(benchmark::State& state) {
    std::vector<moo::Individual<moo::Kursawe>> elements = dereference(population);
    auto func = [](const moo::Individual<moo::Kursawe> &lhs, const moo::Individual<moo::Kursawe> &rhs) {
        return lhs.getOutput()[0] < rhs.getOutput()[0];
    };
    while (state.KeepRunning()) {
        std::sort(elements.begin(), elements.end(), func);
    }
}


BENCHMARK_F(Population, BM_SortByIndexVector)(benchmark::State& state) {
    auto v = population.getObjective(0);
    while (state.KeepRunning()) population.sortedIndexByVector(v);
}






BENCHMARK_F(Population, BM_CopyPopulationByPointer)(benchmark::State& state) {
    while (state.KeepRunning())  auto tmp = population;
}

BENCHMARK_F(Population, BM_CopyPopulationByObj)(benchmark::State& state) {
    std::vector<moo::Individual<moo::Kursawe>> elements = dereference(population);
    while (state.KeepRunning())  auto tmp = elements;
}


