#ifndef STACK_H
#define STACK_H
#include "vector.h"

namespace syo {

    template <typename T, typename CONT = Vector<T>> class Stack {
    public:
        void push(T const& val);
        void pop();
        T top() const;
        bool empty() const { return elems.empty(); }
    private:
        CONT elems;
    };

}

#include "stack.hpp"
#endif // STACK_H
