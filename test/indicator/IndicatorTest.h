#include "AbstractTest.h"
#include "indicator/Util.h"
#include "problems/Identity.h"
#include <limits>


class IndicatorTest : public AbstractTest {
public:


    moo::Population<moo::Identity> createPopulationFromVector(const std::vector<std::vector<double>>& data) {
        moo::Population<moo::Identity> result;
        for (auto v : data) {
            auto ind = std::make_shared<moo::Individual<moo::Identity>>(v);
            result.push_back(ind);
        }
        return result;
    }

    moo::Population<moo::Identity> population = createPopulationFromVector(std::vector<std::vector<double>> {
            {0.31, 6.10}, {0.22, 7.09}, {0.79, 3.97}, {0.27, 6.93}
    });


};


