
#ifndef MOO_VARIABLECOLLECTION_H
#define MOO_VARIABLECOLLECTION_H

#include <vector>



namespace moo {

    template <typename Type>
    class VariableCollection : public std::vector<Type>
    {

    public:

        std::vector<Type> getRandom() const{
            std::vector<Type> result;
            for(auto value : *this) {
                result.push_back(value.getRandom());
            }
            return result;
        }

    };

}

#endif //MOO_VARIABLECOLLECTION_H
