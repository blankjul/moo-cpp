
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
    class MOEAD : public Algorithm<MOEAD<Trait>, Trait> {
    private:

        std::vector<Weights> weights;
        std::vector<std::vector<int>> nearest;
        std::vector<double> refPoint;
        int populationSize = 1000;
        Population<Trait> pop;
        std::vector<double> fitness;
        
        ParetoFront<Trait> f;


        int T = 20;
        double propMutation = 0.2;
        RandomSelection selection;

    public:

        MOEAD(Trait problem) : Algorithm<MOEAD<Trait>, Trait>(problem) {}

        void init_() {
            weights = Weights::getWeights(populationSize);
            fitness = std::vector<double>(populationSize, std::numeric_limits<double>::max());
            for (auto w : weights) nearest.push_back(w.getNearestNeighborByIndex(weights, T));
            for (int i = 0; i < pop.size(); ++i) fitness[i] = Weights::getWeightedSum(weights[i], pop[i]->getOutput());
            pop = Population<Trait>{populationSize};
            refPoint = getReferencePoint(pop);
        }

        void next_() {
            
            for (int i = 0; i < pop.size(); ++i) {
                
                auto a = pop[nearest[i][Random::getInstance()->rndInt(0,nearest[i].size())]];
                auto b = pop[nearest[i][Random::getInstance()->rndInt(0,nearest[i].size())]];
                IndividualPtr<Trait> off = SBXCrossover::crossover(a, b);
                if (Random::getInstance()->rndDouble() < propMutation) off = PolynomialMutation::mutate(off);

                updateReferencePoint(refPoint, off);

                for (auto nearestWeightIndex : nearest[i]) {

                    double value = Weights::getWeightedSum(weights[nearestWeightIndex], pop[i]->getOutput());

                    if (value < fitness[i]) {
                        pop[i] = off;
                        fitness[i] = value;
                    }
                    f.add(off);
                }
            }
        }

        void info_(std::ostream& os) {
        }

   
        
        ParetoFront<Trait> front_() {
            return f;
        }

   
        static 
        void updateReferencePoint(std::vector<double>& ref, const IndividualPtr<Trait> & ind) {
            int numOfObjectives = Trait::getOutput().size();
            auto v = ind->getOutput();
            for (int i = 0; i < numOfObjectives; ++i) {
                ref[i] = std::min(ref[i], v[i]);
            }
        }

     
        static 
        std::vector<double> getReferencePoint(const Population<Trait> & pop) {
            int numOfObjectives = Trait::getOutput().size();
            std::vector<double> ref(numOfObjectives);
            for (int i = 0; i < numOfObjectives; ++i) {
                auto v = pop.getObjective(i);
                ref[i] = *(std::min_element(v.begin(), v.end()));
            }
            return ref;
        }

    };
    
}

#endif //MOO_MOEAD_H
