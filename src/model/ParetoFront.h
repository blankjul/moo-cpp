#ifndef MOO_FRONT_H
#define MOO_FRONT_H

#include "model/Population.h"
#include <unordered_set>
#include "json/json.h"

namespace moo {


    template <typename Trait>
    class ParetoFront {
    private:

        std::list<IndividualPtr<Trait>> front;

    public:

        Population<Trait> getPopulation() const {
            Population<Trait> result;
            for(auto ind : front) result.push_back(ind);
            return result;
        }

        bool add(const IndividualPtr<Trait> & ind) {
            // for every element of front
            for (auto it = front.begin(); it != front.end(); ) {
                // of one elements dominates ind -> does not belong to front
                if ((*it)->isDominating(*ind) || (*it)->isEqual(*ind)) return false;
                // else remove all elements that are dominated by ind
                if ((*it)->isDominatedBy(*ind)) front.erase(it++);
                else ++it;
            }
            front.push_back(ind);
            return true;
        }
        
        

     Json::Value json() {
        Json::Value root;
        auto f = getPopulation();
        if (f.size() == 0) {
            Json::Value obj;
            Json::Value tmp;
            obj.append(tmp);
            root.append(obj);
            root.append(obj);
        } else {
            for (int k = 0; k < Trait::getNumOfObjectives(); ++k) {
                auto v = f.getObjective(k);
                Json::Value obj;
                for (int i = 0; v.size() != 0 &&  i < v.size(); ++i) {
                    obj.append(v[i]);
                }
                root.append(obj);
            }
            return root;
        }
    }



    };
    


}




#endif //MOO_FRONT_H
