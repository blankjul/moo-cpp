#ifndef MOO_ABSTRACTTEST_H
#define MOO_ABSTRACTTEST_H

#include <iostream>
#include <vector>
#include "gmock/gmock.h"
#include "gtest/gtest.h"


#include "model/Population.h"
#include "model/Individual.h"
#include "problems/Identity.h"
#include "variables/VariableCollection.h"
#include "variables/Real.h"

using namespace ::testing;




class AbstractTest : public ::testing::Test {
public:



    typedef std::vector<double> input;


    moo::Population<input> createPopulationFromVector(std::vector<std::vector<double>>& data) {
        moo::Identity i;
        return createPopulationFromVector(data,i);
    }

    moo::Population<input> createPopulationFromVector(std::vector<std::vector<double>>& data,  moo::Problem<input>& p) {
        moo::Population<input> result;
        for (auto v : data) {
            auto ind = std::make_shared<moo::Individual<input>>(v);
            p.evaluate(ind);
            result.push_back(ind);
        }
        return result;
    }

    moo::Population<input> getExamplePopulation() {
        std::vector<std::vector<double>> data;
        data.push_back(std::vector<double> {0.31, 6.10});
        data.push_back(std::vector<double> {0.22, 7.09});
        data.push_back(std::vector<double> {0.79, 3.97});
        data.push_back(std::vector<double> {0.27, 6.93});
        return createPopulationFromVector(data);
    }

    template <typename Input> moo::IndividualPtr<Input> createIndAndEvaluate(Input i, moo::Problem<Input>& p) {
        moo::IndividualPtr<Input> ind = moo::createIndividual(i);
        p.evaluate(ind);
        return ind;
    }

};




#endif //MOO_ABSTRACTTEST_H