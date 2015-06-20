
#ifndef MOO_NSGAII_H
#define MOO_NSGAII_H

#include "model/Algorithm.h"
#include "model/ParetoFront.h"
#include "indicator/NonDominatedRank.h"
#include "indicator/FastNonDominatedRank.h"
#include "indicator/CrowdingDistance.h"
#include "indicator/Util.h"
#include "util/Random.h"
#include <iostream>

#include "util/paretoFrontCalculator/ContUpdatedParetoFront.h"
#include <operators/selection/BinaryTournamentSelection.h>
#include <operators/selection/RandomSelection.h>
#include <operators/crossover/SinglePointCrossover.h>
#include <operators/crossover/SBXCrossover.h>
#include <operators/mutation/PolynomialMutation.h>
#include "Comparator.h"


namespace moo {



    template <typename Trait>
    class NSGAII : public Algorithm<Trait> {


    private:

        int populationSize = 10;
        double propMutation = 0.2;
        int maxGeneration = 100;
        bool verbose = false;

        Population<Trait> population;
        std::unordered_map<IndividualPtr<Trait>, double> indCrowding;
        std::unordered_map<IndividualPtr<Trait>, int> indRank;


    public:

        void waitForKey() {
            do
            {
                std::cout << '\n' <<"Press a key to continue...";
            } while (std::cin.get() != '\n');
        }


        void print(Population<Trait> & population, bool alsoRankAndCrowding = false, bool onlyParetoFront = false) {
            std::cout << "---------------------------\n";
            std::cout << "size: " << population.size() << std::endl;
            std::cout << "---------------------------\n";
            auto pool = (onlyParetoFront) ? ContUpdatedParetoFront::getParetoFront(population) : population;
            for (int i = 0; i < pool.size(); ++i) {
                auto entry = pool[i];
                if (alsoRankAndCrowding) std::cout << " [rank:" << indRank[entry]<< ",crowded:" << indCrowding[entry] << "]";
                std::cout << entry->getOutput()[0] << ", " << entry->getOutput()[1]<<std::endl;
            }
            std::cout << "---------------------------\n";
        }


        void truncate(Population<Trait>& pop, int n) {
            auto it = pop.begin();
            for (int l = 0; l < n; ++l) {
                if (it == pop.end()) return;
                ++it;
            }
            if (it != pop.end()) pop.erase(it, pop.end());
        }


        virtual ParetoFront solve(Trait& p) {

            // initialize a random population with predefined size
            population = Population<Trait> {populationSize};
            indCrowding = CrowdingDistance::calculate(population);
            indRank = NonDominatedRank::calculate(population);

            int generation = 0;
            while (generation++ < maxGeneration) {

                // create the mating pool using BinaryTournamentSelection
                RankAndCrowdedComperator<Trait> cmp(&indRank, &indCrowding);
                BinaryTournamentSelection<RankAndCrowdedComperator<Trait>> selector(cmp);
                Population<Trait> matingPool = selector.selectMultiple(population, populationSize * 2);


                // create all the offsprings
                for (int j = 0; j < matingPool.size() - 1; j += 2) {
                    IndividualPtr<Trait> off = SBXCrossover::crossover(matingPool[j], matingPool[j+1]);
                    if (Random::getInstance()->rndDouble() < propMutation) off = PolynomialMutation::mutate(off);
                    population.push_back(off);
                }


                // Only save the best population with the best ranks (save time by ignoring worse fronts!)
                indRank = NonDominatedRank::calculate_(population, populationSize);
                sortByIndicatorInplaceReverse(population, indRank);
                truncate(population, populationSize);

                // now for the last front use the crowding distance to ensure that the best individuals remains
                indCrowding = CrowdingDistance::calculate(population);
                RankAndCrowdedComperator<Trait>  comp(&indRank, &indCrowding);
                std::sort(population.begin(), population.end(), comp);
                truncate(population, populationSize);

            }


            if (verbose) print(population, true, true);
            if (verbose) print(population);


            for (auto entry :  ContUpdatedParetoFront::getParetoFront(population)) {
                if (verbose) std::cout << entry->getOutput()[0] << ", " << entry->getOutput()[1] << std::endl;
            }


        }




    };

}

#endif //MOO_NSGAII_H
