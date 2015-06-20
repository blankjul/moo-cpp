
#include "AbstractBenchmark.h"
#include "indicator/CrowdingDistance.h"


class CrowdedDistance : public AbstractBenchmark {
};


BENCHMARK_F(CrowdedDistance, BM_CalcCrowdingComplete)(benchmark::State& state) {
    std::vector<double> min;
    std::vector<double> max;
    moo::CrowdingDistance::bounds_(population, min, max);
    while (state.KeepRunning()) {
        moo::CrowdingDistance::calculate_(population, min, max);
    }
}


BENCHMARK_F(CrowdedDistance, BM_CalcCrowding)(benchmark::State& state) {
    while (state.KeepRunning()) {
        int numOfObjectives = population[0]->getOutput().size();
        for (int i = 0; i < numOfObjectives; ++i) {
            auto  func = [&i](const moo::IndividualPtr <moo::Kursawe> &lhs, const moo::IndividualPtr <moo::Kursawe> &rhs) {
                return lhs->getOutput()[i] > rhs->getOutput()[i];
            };
            std::sort(population.begin(), population.end(), func);
        }
    }
}

BENCHMARK_F(CrowdedDistance, BM_CalcCrowdingByIndices)(benchmark::State& state) {
    auto pop = population;
    while (state.KeepRunning()) {
        int numOfObjectives = population[0]->getOutput().size();
        for (int i = 0; i < numOfObjectives; ++i) {
            std::vector<int> v;
            for (unsigned int j = 0; j < population.size(); ++j) v.push_back(j);
            auto  func = [&pop,&i](const int & lhs, const int & rhs) {
                return pop[lhs]->getOutput()[i] > pop[rhs]->getOutput()[i];
            };
            std::sort(v.begin(), v.end(), func);
        }
    }
}



BENCHMARK_F(CrowdedDistance, BM_CalcCrowdingByExtraStruct)(benchmark::State& state) {

    struct Obj {
        moo::IndividualPtr<moo::Kursawe> ptr;
        std::vector<double> output;
    };

    std::vector<Obj> v;

    for(auto entry : population) {
        Obj o;
        o.ptr = entry;
        o.output = entry->getOutput();
        v.push_back(o);
    }



    while (state.KeepRunning()) {
        int numOfObjectives = v[0].output.size();
        for (int i = 0; i < numOfObjectives; ++i) {
            auto  func = [&i](const Obj & lhs, const Obj & rhs) {
                return lhs.output[i] > rhs.output[i];
            };
            std::sort(v.begin(), v.end(), func);
        }
    }
}
