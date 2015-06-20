
#ifndef MOO_FASTNONDOMINATEDRANK_H
#define MOO_FASTNONDOMINATEDRANK_H


#include "Indicator.h"
#include <vector>



namespace moo {


    class FastNonDominatedRank : public Indicator<FastNonDominatedRank, int> {

    public:

        template <typename T>
        static std::unordered_map<IndividualPtr<T>, int> calculate_(Population<T> pop, int onlyForBestIndividuals = -1) {

            int numOfObservedInds = 0;
            if (onlyForBestIndividuals == -1) onlyForBestIndividuals = pop.size();

            std::unordered_map<IndividualPtr<T>, int> m;
            for(auto entry : pop) m[entry] = std::numeric_limits<int>::max();

            std::vector<std::vector<int>> mDominates(pop.size(), std::vector<int>());
            std::vector<int> mIsDominatedBy(pop.size(), 0);


            std::vector<int> front;

            for (int i = 0; i < pop.size(); ++i) {
                for (int j = 0; j < pop.size(); ++j) {
                    if (i == j) continue;
                    else if (pop[i]->isDominating(*pop[j])) mDominates[i].push_back(j);
                    else if (pop[i]->isDominatedBy(*pop[j])) mIsDominatedBy[i] += 1;
                }
                if (mIsDominatedBy[i] == 0) {
                    front.push_back(i);
                    m[pop[i]] = 0;
                }
            }
            numOfObservedInds += front.size();

            int rank = 1;
            while(!front.empty() && (numOfObservedInds < onlyForBestIndividuals)) {
                std::vector<int> nextFront;
                for( int i : front) {
                    for ( int j : mDominates[i]) {
                        mIsDominatedBy[j] -= 1;
                        if (mIsDominatedBy[j] == 0) {
                            nextFront.push_back(j);
                            m[pop[j]] = rank;
                        }
                    }
                }
                front = nextFront;
                numOfObservedInds += front.size();
                ++rank;
            }



            return m;
        }


    };



}



#endif //MOO_FASTNONDOMINATEDRANK_H
