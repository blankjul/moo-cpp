#ifndef MOO_ALGORITHM_H
#define MOO_ALGORITHM_H

#include <iostream>
#include "ParetoFront.h"
#include "json/json.h"

namespace moo {

    template <typename DerivedClass, typename Trait>
    class Algorithm {
        
    private:
            
        Trait problem;
        Json::Value fronts;
        

    public:
        
        bool verbose = false;
        bool json = false;
        int maxGeneration = 100;
        
        
        Algorithm(Trait problem) : problem(problem) {}
        
        virtual ParetoFront<Trait> solve() {
            initialize();
            for(int i = 0; i < maxGeneration; ++i) {
                if (json && i % 100 == 0) fronts.append(front().json());
                next();
                if (verbose) info(std::cout);
            }
            if (json) std::cout << fronts;
            return front();
        }

        
        Trait getProblem() const {
            return problem;
        }

        void setProblem(Trait problem) {
            this->problem = problem;
        }
        
        static 
        void waitForKey() {
            do
            {
                std::cout << '\n' <<"Press a key to continue...";
            } while (std::cin.get() != '\n');
        }

        
        /**
         * Methods that must be overwritten by all implementations
         */
        
        void next() {
            return static_cast<DerivedClass*>(this)->next_();
        }
        
        void initialize() {
            return static_cast<DerivedClass*>(this)->init_();
        }

        void info(std::ostream& os) {
            return static_cast<DerivedClass*>(this)->info_(os);
        }

        ParetoFront<Trait> front() {
            return static_cast<DerivedClass*>(this)->front_();
        }
        
   

    };

}




#endif //MOO_ALGORITHM_H
