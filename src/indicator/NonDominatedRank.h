
#ifndef MOO_NONDOMINATEDRANK_H
#define MOO_NONDOMINATEDRANK_H


#include "Indicator.h"
#include "util/paretoFrontCalculator/ContUpdatedParetoFront.h"
#include <vector>



namespace moo {


    class NonDominatedRank : public Indicator<NonDominatedRank, int> {

    public:

        template <typename T>
        static std::unordered_map<IndividualPtr<T>, int> calculate_(Population<T> pop, int onlyForBestIndividuals = -1) {

            if (onlyForBestIndividuals == -1) onlyForBestIndividuals = pop.size();
            std::unordered_map<IndividualPtr<T>, int> m;
            int rank = 0;
            int numOfObservedInds = 0;

            while (!pop.empty() && (numOfObservedInds < onlyForBestIndividuals)) {

                auto front = ContUpdatedParetoFront::getParetoFront(pop);
                pop.remove(front);

                for (IndividualPtr<T> entry : front) {
                    m[entry] = rank;
                    ++numOfObservedInds;
                }
                ++rank;
            }
            for (IndividualPtr<T> entry : pop) m[entry] = std::numeric_limits<int>::max();
            return m;
        }


    };



}



#endif //MOO_NONDOMINATEDRANK_H
