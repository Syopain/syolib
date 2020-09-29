#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H
#include <initializer_list>
#include <string>
#include <stdexcept>
#include <memory>
#include <list>

namespace syo {

    template <typename T> struct ListNode {
        T data{};
        std::shared_ptr<ListNode> next = nullptr;
        ListNode(const T& data = T{}, std::shared_ptr<ListNode> next = nullptr)
            : data(data), next(next) { }
    };

    template <typename T> class ForwardList {
    public:
        using size_type = unsigned long long;
        class iterator;

        ForwardList();
        ForwardList(const ForwardList<T>& from);
        ForwardList(size_type size, const T& val = T{});
        ForwardList(std::initializer_list<T> il);
        ForwardList& operator=(const ForwardList& from);

        T& operator[](size_type index);
        const T& operator[](size_type index) const;
        iterator begin() const { return iterator(head_->next); }
        iterator end() const { return iterator(); }
        size_type length() const;
        int index_of(const T& value) const;
        iterator insert(iterator pos, const T& value);
        iterator insert_after(iterator pos, const T& value);
        iterator erase(iterator pos);
        iterator erase_after(iterator pos);

        void reverse();
    private:
        std::shared_ptr<ListNode<T>> head_;

        void copy(const ForwardList<T>& from);

    };

    template <typename T> class ForwardList<T>::iterator {
    public:
        iterator(std::shared_ptr<ListNode<T>> ptr = nullptr) : ptr_(ptr) { }
        T& operator*() const { return ptr_->data; }
        T* operator->() const {return & this->operator*(); }
        iterator& operator++() { ptr_ = ptr_->next; return *this; }
        iterator operator++(int) { auto ret = *this; ++*this; return ret; }
        bool operator==(const iterator& rhs) { return ptr_ == rhs.ptr_; }
        bool operator!=(const iterator& rhs) { return ptr_ != rhs.ptr_; }

    private:
        std::shared_ptr<ListNode<T>> ptr_;
        friend class ForwardList;
/*
        friend bool operator==(const iterator& lhs, const iterator& rhs);
        friend bool operator!=(const iterator& lhs, const iterator& rhs);
*/
    };

    //non-member function:

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const ForwardList<T>& vec);

    //定义在类外无法实例化
    template <typename T>
    bool operator==(const typename ForwardList<T>::iterator& lhs, const typename ForwardList<T>::iterator& rhs);
    template <typename T>
    bool operator!=(const typename ForwardList<T>::iterator& lhs, const typename ForwardList<T>::iterator& rhs);

}

#include "forward_list.hpp"
#endif // FORWARD_LIST_H
