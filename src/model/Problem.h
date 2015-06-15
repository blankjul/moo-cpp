#ifndef MOO_PROBLEM_H
#define MOO_PROBLEM_H

#include <vector>
#include <memory>
#include <unordered_map>
#include "Individual.h"
#include "Population.h"

namespace moo {

   template <typename Input, typename Output = std::vector<double>>
   class Problem
   {

   private:

      std::unordered_map< IndividualPtr<Input> , Output> m;

   public:


      virtual Output evaluate_(const Input&) = 0;
      virtual Input getInput() = 0;
      virtual Output getOutput() = 0;

      int numOfObjectives() {return getOutput().size();}
      int numOfVariables() {return getInput().size();}


      Output evaluate(IndividualPtr<Input>& ind) {
         if (m.find(ind) == m.end()) {
            ind->output = evaluate_(ind->getInput());
            ind->evaluated = true;
            m[ind] = ind->output;
         }
         return m[ind];
      }

      void evaluateAll(Population<Input>& pop) {
         for(auto ind : pop) evaluate(ind);
      }



   };

}

#endif //MOO_PROBLEM_H
