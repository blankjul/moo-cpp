
#ifndef MOO_MOEAD_H
#define MOO_MOEAD_H

#include "model/Algorithm.h"
#include "model/ParetoFront.h"
#include "Weights.h"
#include "operators/selection/RandomSelection.h"
#include "util/Random.h"
#include "operators/crossover/SBXCrossover.h"
#include "operators/mutation/PolynomialMutation.h"

namespace moo {



    template <typename Trait>
    class MOEAD : public Algorithm<Trait> {


    private:

        ParetoFront<Trait> front;
        std::vector<Weights> weights;
        std::vector<std::vector<int>> nearest;
        std::vector<double> refPoint;


        int T = 5;
        int maxGeneration = 10;
        double propMutation = 0.2;
        RandomSelection selection;


    public:


        virtual ParetoFront<Trait> solve(Trait& p) {

            weights = Weights::getWeights(100);
            int populationSize = weights.size();


            std::vector<double> fitness (populationSize, std::numeric_limits<double>::max());

            for (auto w: weights) nearest.push_back(w.getNearestNeighborByIndex(weights,T));

            Population<Trait> pop {populationSize};
            refPoint = getReferencePoint(pop);

            int generation = 0;
            while (generation++ <= maxGeneration) {

                for (int i = 0; i < populationSize; ++i) {
                    auto a = selection.select(pop);
                    auto b = selection.select(pop);
                    IndividualPtr<Trait> off = SBXCrossover::crossover(a,b);
                    if (Random::getInstance()->rndDouble() < propMutation) off = PolynomialMutation::mutate(off);

                    updateReferencePoint(refPoint, off);

                    for(auto nearestWeightIndex : nearest[i]) {

                        double value = getWeightedSum(weights[nearestWeightIndex], pop[i]->getOutput());

                        if (value < fitness[i]) {
                            pop[i] = off;
                            fitness[i] = value;
                        }
                        front.add(off);
                    }
                }
            }

            std::cout << front.getPopulation();




            return front;
        }






    };


    static double getWeightedSum(const Weights & w, const std::vector<double>& output) {
        double sum = 0;
        for (unsigned int i = 0; i < w.size(); ++i) {
            sum += w[i] * output[i];
        }
        return sum;
    }

    template <typename Trait>
    static void updateReferencePoint(std::vector<double>& ref, const IndividualPtr<Trait> & ind) {
        int numOfObjectives = Trait::getOutput().size();
        auto v = ind->getOutput();
        for (int i = 0; i < numOfObjectives; ++i) {
            ref[i] = std::min(ref[i], v[i]);
        }
    }

    template <typename Trait>
    static std::vector<double> getReferencePoint(const Population<Trait> & pop) {
        int numOfObjectives = Trait::getOutput().size();
        std::vector<double> ref (numOfObjectives);
        for (int i = 0; i < numOfObjectives; ++i) {
            auto v = pop.getObjective(i);
            ref[i] = *(std::min_element(v.begin(), v.end()));
        }
        return ref;

    }

}

#endif //MOO_MOEAD_H
