#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP
#include "forward_list.h"

namespace syo {

    template <typename T>
    ForwardList<T>::ForwardList() :
        head_(std::make_shared<T>())
    {

    }

    template <typename T>
    ForwardList<T>::ForwardList(const ForwardList<T>& from) :
        head_(std::make_shared<T>())
    {
        copy(from);
    }

    template <typename T>
    ForwardList<T>::ForwardList(size_type size, const T& val) :
        head_(std::make_shared<T>())
    {
        auto p = head_;
        for (size_type i = 0; i < size; ++i) {
            p->next = std::make_shared<ListNode<T>>(val);
            p = p->next;
        }
    }

    template <typename T>
    ForwardList<T>::ForwardList(std::initializer_list<T> il) :
        head_(std::make_shared<T>())
    {
        auto p = head_;
        for (const auto& it : il) {
            p->next = std::make_shared<ListNode<T>>(it);
            p = p->next;
        }
    }

    template <typename T>
    ForwardList<T>& ForwardList<T>::operator=(const ForwardList<T>& from)
    {
        copy(from);
    }

    template <typename T>
    inline
    void ForwardList<T>::copy(const ForwardList<T>& from)
    {
        auto p = head_;
        auto q = from.head_;
        while (q->next) {
            p->next = std::make_shared<ListNode<T>>(q->next->data);
            p = p->next;
            q = q->next;
        }
    }

}

#endif // FORWARD_LIST_HPP
