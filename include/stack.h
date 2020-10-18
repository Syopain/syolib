#ifndef STACK_H
#define STACK_H
#include "vector.h"
#include "forward_list.h"

namespace syo {

    template <typename T, typename CONT = Vector<T>>
    class Stack {
    public:
        using size_type = typename CONT::size_type;

        void push(T const& val);
        void pop();
        T top() const;
        bool empty() const { return elems.empty(); }
        size_type size() const { return elems.size(); }

        //Exercise extension member function:
        void removeAll(T const& val);
    private:
        CONT elems;
    };

    template <typename T>
    class Stack<T, syo::ForwardList<T>> {
    public:
        using size_type = typename ForwardList<T>::size_type;

        void push(T const& val);
        void pop();
        T top() const;
        bool empty() const { return elems.empty(); }
        size_type size() const { return elems.size(); }

        //Exercise extension member function:
        void removeAll(T const& val);
    private:
        ForwardList<T> elems;
    };

    //Non-member function:
    template <typename T, typename CONT>
    std::ostream& operator<<(std::ostream& os, Stack<T, CONT> const& stack);
}

#include "stack.hpp"
#endif // STACK_H
