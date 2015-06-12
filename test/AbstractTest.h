#ifndef MOO_ABSTRACTTEST_H
#define MOO_ABSTRACTTEST_H

#include <iostream>
#include <vector>
#include "gmock/gmock.h"
#include "gtest/gtest.h"


#include "model/Population.h"
#include "model/Individual.h"
#include "problems/Identity.h"

using namespace ::testing;


class AbstractTest : public ::testing::Test {
public:

    typedef std::vector<double> input;
    moo::Population<input> createPopulationFromVector(std::vector<std::vector<double>>& data,  moo::ProblemPtr<input> identity = std::make_shared<moo::Identity>()) {
        moo::Population<input> result;
        for (auto v : data) result.push_back(std::make_shared<moo::Individual<input>>(identity, v));
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

};




#endif //MOO_ABSTRACTTEST_H