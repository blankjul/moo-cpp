
#ifndef MOO_NSGAII_H
#define MOO_NSGAII_H

#include "model/Algorithm.h"
#include "model/ParetoFront.h"
#include "indicator/NonDominatedRank.h"
#include "indicator/CrowdingDistance.h"
#include "model/PopulationFactory.h"
#include <iostream>


#include <operators/selection/BinaryTournamentSelection.h>
#include "Comparator.h"


namespace moo {



    template <typename Settings>
    class NSGAII : public Algorithm<typename Settings::problem> {

        typedef typename Settings::problem Trait;

    private:

        int generation;

    public:

        virtual ParetoFront solve(typename Settings::problem& p) {

            // init a random population
            Population<Trait> population = moo::PopulationFactory<Trait>::createRandomPopulation(Settings::populationSize);

            while (generation <= 100) {

                ++generation;

                // calculate the indicator for the whole population
                auto indCrowded = CrowdingDistance::calculate(population);
                auto indRank = NonDominatedRank::calculate(population);

                // use the binary tournament select for the mating pool generation -> each element exactly two times!
                Population<Trait> matingPool;
                //for (int i = 0; i < 2; ++i) {
                    //RankAndCrowdedComperator<Trait> cmp(indRank, indCrowded);
                    //BinaryTournamentSelection<RankAndCrowdedComperator<Trait> > selector;
                    //auto tmp = selectMultiple(population);
                    //matingPool.insert(tmp.begin(), tmp.end);
                //}





            }




        }




    };

}

#endif //MOO_NSGAII_H
