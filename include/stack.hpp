#ifndef STACK_HPP
#define STACK_HPP
#include "stack.h"

namespace syo {

    template <typename T, typename CONT>
    void Stack<T, CONT>::push(T const& val)
    {
        elems_.push_back(val);
    }

    template <typename T, typename CONT>
    void Stack<T, CONT>::pop()
    {
        if (elems_.empty()) {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        elems_.pop_back();
    }

    template <typename T, typename CONT>
    T Stack<T, CONT>::top() const
    {
        if (elems_.empty()) {
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elems_.back();
    }

    template<typename T, typename CONT>
    void Stack<T, CONT>::removeAll(T const& val)
    {
        Stack<T, CONT> temp;
        while (!this->empty()) {
            if (this->top() == val) {
                this->pop();
            }
            else {
                temp.push(this->top());
                this->pop();
            }
        }
        while (!temp.empty()) {
            this->push(temp.top());
            temp.pop();
        }
    }

    template <typename T>
    void Stack<T, syo::ForwardList<T>>::push(T const& val)
    {
        elems.insert(elems.begin(), val);
    }

    template <typename T>
    void Stack<T, syo::ForwardList<T>>::pop()
    {
        if (elems.empty()) {
            throw std::out_of_range("Stack<syo::ForwardList<>>::pop(): empty stack");
        }
        elems.erase(elems.begin());
    }

    template <typename T>
    T Stack<T, syo::ForwardList<T>>::top() const
    {
        if (elems.empty()) {
            throw std::out_of_range("Stack<syo::ForWardList<>>::top(): empty stack");
        }
        return *elems.begin();
    }

    template<typename T>
    void Stack<T, syo::ForwardList<T>>::removeAll(T const& val)
    {
        Stack<T, syo::ForwardList<T>> temp;
        while (!this->empty()) {
            if (this->top() == val) {
                this->pop();
            }
            else {
                temp.push(this->top());
                this->pop();
            }
        }
        while (!temp.empty()) {
            this->push(temp.top());
            temp.pop();
        }
    }

    //Non-member function:
    template <typename T, typename CONT>
    std::ostream& operator<<(std::ostream& os, Stack<T, CONT> const& stack)
    {
        auto temp = stack;
        while (!temp.empty()) {
            os << temp.top() << ' ';
            temp.pop();
        }
        return os;
    }
}

#endif // STACK_HPP
