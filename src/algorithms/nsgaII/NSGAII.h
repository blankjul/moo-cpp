
#ifndef MOO_NSGAII_H
#define MOO_NSGAII_H

#include "model/Algorithm.h"
#include "model/ParetoFront.h"
#include "indicator/NonDominatedRank.h"
#include "indicator/FastNonDominatedRank.h"
#include "indicator/CrowdingDistance.h"
#include "util/Random.h"
#include <iostream>

#include "util/paretoFrontCalculator/ContUpdatedParetoFront.h"
#include <operators/selection/BinaryTournamentSelection.h>
#include <operators/selection/RandomSelection.h>
#include <operators/crossover/SinglePointCrossover.h>
#include <operators/crossover/SBXCrossover.h>
#include <operators/mutation/PolynomialMutation.h>
#include "util/paretoFrontCalculator/ContUpdatedParetoFront.h"
#include "Comparator.h"


namespace moo {


    template <typename Trait>
    class NSGAII : public Algorithm<NSGAII<Trait>, Trait> {

    private:


        Population<Trait> population;
        std::unordered_map<IndividualPtr<Trait>, double> indCrowding;
        std::unordered_map<IndividualPtr<Trait>, int> indRank;


    public:
        
        NSGAII(Trait problem) : Algorithm<NSGAII<Trait>, Trait>(problem) {}
        int populationSize = 1000;
        double propMutation = 0.2;


        void init_() {
            population = Population<Trait> {populationSize};
            indCrowding = CrowdingDistance::calculate(population);
            indRank = NonDominatedRank::calculate(population);
        }

        void next_() {
            
            // create the mating pool using BinaryTournamentSelection
            RankAndCrowdedComperator<Trait> cmp(&indRank, &indCrowding);
            BinaryTournamentSelection<RankAndCrowdedComperator<Trait>> selector(cmp);
            Population<Trait> matingPool = selector.selectMultiple(population, populationSize * 2);


            // create all the offsprings
            for (unsigned int j = 0; j < matingPool.size() - 1; j += 2) {
                IndividualPtr<Trait> off = SBXCrossover::crossover(matingPool[j], matingPool[j+1]);
                if (Random::getInstance()->rndDouble() < propMutation) off = PolynomialMutation::mutate(off);
                population.push_back(off);
            }


            // now for the last front use the crowding distance to ensure that the best individuals remains
            indRank = NonDominatedRank::calculate(population);
            indCrowding = CrowdingDistance::calculate(population);
            RankAndCrowdedComperator<Trait>  comp(&indRank, &indCrowding);
            std::sort(population.begin(), population.end(), comp);

            /*
            std::cout << "---------------------------\n";
            for(auto entry : population) {
                std::cout << entry->getOutput()[0] << ", " << entry->getOutput()[1] << " | rank: " << indRank[entry] << " | crowding: " ;
                std::cout << indCrowding[entry] << std::endl;
            }
            std::cout << "---------------------------\n";
            Algorithm<NSGAII<Trait>, Trait>::waitForKey();
             */

            // truncate the population
            Population<Trait> next;
            for (int l = 0; l < populationSize; ++l) next.push_back(population[l]);
            population = next;
        }
        
        
        void info_(std::ostream& os) {
            auto last = population[population.size()-1];
            os << "pareto front: " << indRank[last] << " | worst crowding: " ;
            os << indCrowding[last] << std::endl;
        }
        
        

        
        ParetoFront<Trait> front_() {
            ParetoFront<Trait> f;
            for(unsigned int i = 0; i < population.size(); ++i) f.add(population[i]);
            return f;
        }





    };

}

#endif //MOO_NSGAII_H
