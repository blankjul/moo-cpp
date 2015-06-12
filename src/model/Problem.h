

#ifndef MOO_PROBLEM_H
#define MOO_PROBLEM_H

#include <vector>
#include <memory>

namespace moo {

   template <typename Input, typename Output = std::vector<double>>
   class Problem
   {

   public:
      virtual Output evaluate(const Input&) = 0;
   };

   template<typename T>
   using ProblemPtr = std::shared_ptr<Problem<T>>;


}

#endif //MOO_PROBLEM_H
