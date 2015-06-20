
#ifndef MOO_VARIABLE_H
#define MOO_VARIABLE_H

#include <iostream>

namespace moo {

    template<typename Type>
    class Variable {

    protected:

        Type value;

    public:

        Variable() { }
        Variable(Type value) : value(value) { }


        Type getValue() const {
            return value;
        }

        virtual void setValue(const Type& value) {
            Variable::value = value;
        }



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

    template <typename Type> std::ostream & operator<<(std::ostream &os, const Variable<Type>& rhs)
    {
        return os << rhs.getValue();
    }
}

#endif //MOO_VARIABLE_H
