#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP
#include "forward_list.h"

namespace syo {


    template <typename T>
    ForwardList<T>::ForwardList() :
        head_(std::make_shared<ListNode<T>>()),
        tail_(std::make_shared<ListNode<T>>())
    {

    }

    template <typename T>
    ForwardList<T>::ForwardList(const ForwardList<T>& from) :
        head_(std::make_shared<ListNode<T>>()),
        tail_(std::make_shared<ListNode<T>>())
    {
        copy(from);
    }

    template <typename T>
    ForwardList<T>::ForwardList(size_type size, const T& val) :
        head_(std::make_shared<ListNode<T>>()),
        tail_(std::make_shared<ListNode<T>>())
    {
        auto p = head_;
        for (size_type i = 0; i < size; ++i) {
            p->next = std::make_shared<ListNode<T>>(val);
            p = p->next;
        }
        tail_ = p;
    }

    template <typename T>
    ForwardList<T>::ForwardList(std::initializer_list<T> il) :
        head_(std::make_shared<ListNode<T>>()),
        tail_(std::make_shared<ListNode<T>>())
    {
        auto p = head_;
        for (const auto& it : il) {
            p->next = std::make_shared<ListNode<T>>(it);
            p = p->next;
        }
        tail_ = p;
    }

    template <typename T>
    ForwardList<T>& ForwardList<T>::operator=(const ForwardList<T>& from)
    {
        copy(from);
        return *this;
    }

    template <typename T>
    inline
    T& ForwardList<T>::operator[](size_type index)
    {
        auto iter = begin();
        for (size_type i = 0; i < index; ++i) {
            ++iter;
        }
        return *iter;
    }

    template <typename T>
    inline
    const T& ForwardList<T>::operator[](size_type index) const
    {
        auto iter = begin();
        for (size_type i = 0; i < index; ++i) {
            ++iter;
        }
        return *iter;
    }

    template <typename T>
    typename ForwardList<T>::size_type ForwardList<T>::length() const
    {
        size_type length = 0;
        for (auto iter = begin(); iter != end(); ++iter) {
            length++;
        }
        return length;
    }

    template <typename T>
    int ForwardList<T>::index_of(const T& value) const
    {
        int index = 0;
        for (const auto& item : *this) {
            if (item == value) {
                return index;
            }
            else {
                ++index;
            }
        }
        return -1;
    }

    template <typename T>
    void ForwardList<T>::reverse()
    {
        auto p = head_->next;


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
        tail_ = p;
    }

    //non-member function:

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const ForwardList<T>& lst)
    {
        for (auto item : lst) {
            os << item << " ";
        }
        return os;
    }

    template <typename T>
    bool operator==(const typename ForwardList<T>::iterator& lhs, const typename ForwardList<T>::iterator& rhs)
    {
        return lhs.ptr_ == rhs.ptr_;
    }
    template <typename T>
    bool operator!=(typename ForwardList<T>::iterator const& lhs, typename ForwardList<T>::iterator const& rhs)
    {
        return lhs.ptr_ != rhs.ptr_;
    }

}

#endif // FORWARD_LIST_HPP
