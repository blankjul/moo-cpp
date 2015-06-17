
#ifndef MOO_VARIABLECOLLECTION_H
#define MOO_VARIABLECOLLECTION_H

#include <vector>



namespace moo {

    template <typename Type>
    class VariableCollection : public std::vector<Type>
    {

    public:


        VariableCollection() : std::vector<Type>() { }
        VariableCollection(int n, const Type& val) : std::vector<Type>(n, val) { }

        VariableCollection random() const {
            VariableCollection result;
            for(auto value : *this) {
                result.push_back(value.random());
            }
            return result;
        }

    };

}

#endif //MOO_VARIABLECOLLECTION_H
