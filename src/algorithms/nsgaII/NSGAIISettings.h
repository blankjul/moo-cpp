#ifndef MOO_NSGASETTINGS_H
#define MOO_NSGASETTINGS_H

#include "Comparator.h"
#include <operators/selection/Selection.h>
#include <operators/selection/BinaryTournamentSelection.h>
#include <operators/crossover/SinglePointCrossover.h>
#include <operators/mutation/PolynomialMutation.h>

namespace moo {

    template<typename Trait>
    class NSGAIISettings {

    public:

        typedef Trait problem;

        static constexpr int populationSize = 100;
        static constexpr double propMutation = 0.2;
        static constexpr int maxGeneration = 10;

        typedef BinaryTournamentSelection<RankAndCrowdedComperator<Trait>> selector;
        SinglePointCrossover crossover;
        PolynomialMutation mutator;

    };

}


#endif //MOO_NSGASETTINGS_H
