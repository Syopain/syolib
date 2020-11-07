#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H
#include <string>
#include <stdexcept>
#include <memory>

namespace syo {

    template <typename T>
    class ForwardList;

    template <typename T>
    class ListNode {
    public:
        ListNode(const T& data = T{}, std::shared_ptr<ListNode> next = nullptr)
            : data_(data), next_(next) { }
    private:
        T data_{};
        std::shared_ptr<ListNode> next_ = nullptr;
        friend class ForwardList<T>;
    };

    template <typename T>
    class ForwardList {
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
        iterator begin() const { return iterator(head_->next_); }
        iterator end() const { return iterator(); }
        bool empty() const { return begin() == end(); }
        size_type length() const;
        size_type size() const { return length(); };
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
        T& operator*() const { return ptr_->data_; }
        T* operator->() const {return & this->operator*(); }
        iterator& operator++() { ptr_ = ptr_->next_; return *this; }
        iterator operator++(int) { auto ret = *this; ++*this; return ret; }
        bool operator==(const iterator& rhs) { return ptr_ == rhs.ptr_; }
        bool operator!=(const iterator& rhs) { return ptr_ != rhs.ptr_; }

    private:
        std::shared_ptr<ListNode<T>> ptr_;
        friend class ForwardList<T>;
/*
        friend bool operator==(const iterator& lhs, const iterator& rhs);
        friend bool operator!=(const iterator& lhs, const iterator& rhs);
*/
    };

    //Non-member function:

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const ForwardList<T>& vec);

    //error: defined as a non-member function cannot be instantiated
    template <typename T>
    bool operator==(const typename ForwardList<T>::iterator& lhs, const typename ForwardList<T>::iterator& rhs);
    template <typename T>
    bool operator!=(const typename ForwardList<T>::iterator& lhs, const typename ForwardList<T>::iterator& rhs);

}

#include "forward_list.hpp"
#endif // FORWARD_LIST_H
