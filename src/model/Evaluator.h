#ifndef MOO_PROBLEM_H
#define MOO_PROBLEM_H

#include <unordered_map>
#include "Population.h"


namespace moo {



    template< typename Trait>
   class Evaluator
   {

   private:

      std::unordered_map< IndividualPtr<Trait>, typename Trait::OutputType> m;


   public:

      typename Trait::OutputType evaluate(IndividualPtr<Trait> & ind) {
         ind->output = Trait::evaluate(ind->getInput());
         ind->evaluated = true;
         return ind->output;

         /*
         if (ind->isEvaluated() && m.find(ind) != m.end()) {
            return m[ind];
         } else {
            ind->output = Trait::evaluate(ind->getInput());
            ind->evaluated = true;
            m[ind] = ind->output;
            return ind->output;
         }
          */
      }


      void evaluateAll(Population<Trait> & pop) {
         for(auto ind : pop) evaluate(ind);
      }



   };

}

#endif //MOO_PROBLEM_H
