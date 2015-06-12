
#ifndef MOO_VARIABLE_H
#define MOO_VARIABLE_H

#include <vector>

namespace moo {

    template <typename Type>
    class Variable
    {

    protected:

        std::vector<Type> v;
        Type value;

    public:


        Variable() {};

        Variable(Type value) : value(value) {
            setValue(value);
        }

        Type getValue() const {
            return value;
        }

        virtual void setValue(Type value) {
            Variable::value = value;
            if (v.empty()) v.push_back(value);
            else v[0] = value;
        }

        virtual Type getRandom() = 0;




    typename std::vector<Type>::iterator begin() { return v.begin(); }
    typename std::vector<Type>::const_iterator begin() const { return v.cbegin(); }
    typename std::vector<Type>::iterator end() { return v.end(); }
    typename std::vector<Type>::const_iterator end() const { return v.cend();}


    };

    template <typename Type> bool operator< (const Variable<Type>& lhs, const Variable<Type>& rhs){
        return lhs.getValue() < rhs.getValue(); }

    template <typename Type> bool operator> (const Variable<Type>& lhs, const Variable<Type>& rhs){
        return lhs.getValue() > rhs.getValue();}

    template <typename Type> bool operator<=(const Variable<Type>& lhs, const Variable<Type>& rhs){
        return lhs.getValue() <= rhs.getValue();}

    template <typename Type> bool operator>=(const Variable<Type>& lhs, const Variable<Type>& rhs){
        return lhs.getValue() >= rhs.getValue();}

    template <typename Type> bool operator==(const Variable<Type>& lhs, const Variable<Type>& rhs){
        return lhs.getValue() == rhs.getValue();}

    template <typename Type> bool operator!=(const Variable<Type>& lhs, const Variable<Type>& rhs){
        return lhs.getValue() != rhs.getValue();}

}

#endif //MOO_VARIABLE_H