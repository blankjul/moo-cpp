
#ifndef MOO_NSGAIICOMPARATOR_H
#define MOO_NSGAIICOMPARATOR_H


#include "model/Individual.h"
#include <unordered_map>

template <typename Trait>
class RankAndCrowdedComperator
{

public:


    std::unordered_map<moo::IndividualPtr<Trait>,int>* rank;
    std::unordered_map<moo::IndividualPtr<Trait>,double>* crowded;


    RankAndCrowdedComperator(std::unordered_map<moo::IndividualPtr<Trait>, int>* indRank,
                             std::unordered_map<moo::IndividualPtr<Trait>, double>* indCrowded)  {
        rank = indRank;
        crowded = indCrowded;
    }

    bool operator()(moo::IndividualPtr<Trait> a, moo::IndividualPtr<Trait> b)
    {
        if (rank->find(a) == rank->end() || rank->find(b) == rank->end() )
            throw std::runtime_error("Please calculate the rank indicator first!");

        if ((*rank)[a] < (*rank)[b]) return true;
        else if ((*rank)[a] > (*rank)[b]) return false;
        else {

            if (crowded->find(a) == crowded->end() || crowded->find(b) == crowded->end() )
                throw std::runtime_error("Please calculate the crowding indicator first!");

            if ((*crowded)[a] > (*crowded)[b]) return true;
            else if ((*crowded)[a] < (*crowded)[b]) return false;
            else return std::tie((*crowded)[a]) < std::tie((*crowded)[b]);
        }
    }


};

#endif //MOO_NSGAIICOMPARATOR_H
