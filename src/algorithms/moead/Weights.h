
#ifndef MOO_WEIGHTS_H
#define MOO_WEIGHTS_H

#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <cmath>
#include <unordered_map>
#include "util/SortUtil.h"
#include "util/Random.h"


namespace moo {




    class Weights : public std::vector<double> {

    public:



        Weights (std::initializer_list<double> list) : std::vector<double>(list) {}

        static std::vector<Weights> getWeights(int n) {

            auto rndWeight = []() {
                auto r = Random::getInstance();
                std::vector<double> v = {r->rndDouble(),r->rndDouble(),r->rndDouble()};
                double sum = std::accumulate(v.begin(), v.end(), 0);
                for (unsigned int i = 0; i < v.size(); ++i) v[i] /= sum;
                return Weights{v[0], v[1], v[2]};
            };

            std::vector<Weights> weights;

            for (int i = 0; i < n; ++i) weights.push_back(rndWeight());
            return weights;

        }

        double getDistance(const Weights & w) {
            double d = 0;
            if (this->size() != w.size()) throw std::runtime_error("Weights has not the same length!");
            for (unsigned int i = 0; i < w.size(); ++i) d += ((*this)[i] - w[i]) * ((*this)[i] - w[i]);
            return std::sqrt(d);
        }

        std::vector<double> getDistanceAll(const std::vector<Weights> & w) {
            std::vector<double> d;
            for (unsigned int i = 0; i < w.size(); ++i) {
                d.push_back(getDistance(w[i]));
            }
            return d;
        }

        std::vector<int> getNearestNeighborByIndex(const std::vector<Weights> & w, unsigned int numOfNearest) {
            std::vector<double> d = getDistanceAll(w);
            auto index = SortUtil::getIndex(w.size());
            std::sort(index.begin(), index.end(),[&d]( const int & lhs, const int & rhs ){return d[lhs] < d[rhs];});
            while (index.size() > numOfNearest) index.pop_back();
            return index;
        }




    };

}

#endif //MOO_WEIGHTS_H
