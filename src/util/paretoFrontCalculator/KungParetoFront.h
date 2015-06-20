#ifndef MOO_KUNGPARETOFRONT_H
#define MOO_KUNGPARETOFRONT_H


#include "ParetoFront.h"
#include "model/Individual.h"
#include <unordered_map>

namespace moo {


    class KungParetoFront : public ParetoFrontCalc<KungParetoFront> {

    public:


        template <typename T>
        static void sortByObjectiveInplaceReverse(Population<T>& population, int objective) {
            IndividualComparator<T> func = [&objective]( const IndividualPtr<T>& lhs, const IndividualPtr<T>& rhs )
            {
                return lhs->getOutput()[objective] < rhs->getOutput()[objective];
            };
            std::sort(population.begin(), population.end(), func);
        }


        template <typename Trait>
        static Population<Trait> getParetoFront(const Population<Trait> & pop)
        {
            Population<Trait> front;

            Population<Trait> copy = pop;
            sortByObjectiveInplaceReverse(copy,0);

            auto res = split(copy);

            return kung(res.first, res.second);
        }


        template <typename Trait>
        static Population<Trait> kung(const Population<Trait> & T, const Population<Trait> & B) {

            if (T.size() <= 1 && B.size() <= 1) {

                return merge(T, B);

            } else {

                auto a = split(T);
                auto first = kung(a.first, a.second);

                auto b = split(B);
                auto second = kung(b.first, b.second);

                return merge(first, second);
            }
        }

        template <typename Trait>
        static Population<Trait> merge(const Population<Trait> & T, const Population<Trait> & B) {
            Population<Trait> M = T;
            for (int i = 0; i < B.size(); ++i) {
                bool isNonDominated = true;
                for (int j = 0; j < T.size(); ++j) {
                    if (B[i]->isDominatedBy(*T[j])) {
                        isNonDominated = false;
                        break;
                    }
                }
                if (isNonDominated) M.push_back(B[i]);
            }
            return M;
        }


        template <typename Trait>
        static std::pair<Population<Trait>,Population<Trait>> split(const Population<Trait> & population) {
            Population<Trait> T;
            Population<Trait> B;
            int point = population.size() / 2;
            for (int i = 0; i < point; ++i) T.push_back(population[i]);
            for (int i = point; i < population.size(); ++i) B.push_back(population[i]);
            return std::make_pair(T,B);
        }






    };

}




#endif //MOO_KUNGPARETOFRONT_H
