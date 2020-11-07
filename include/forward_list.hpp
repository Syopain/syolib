#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP
#include "forward_list.h"

namespace syo {

    template <typename T>
    ForwardList<T>::ForwardList() :
        head_(std::make_shared<ListNode<T>>())
    {

    }

    template <typename T>
    ForwardList<T>::ForwardList(const ForwardList<T>& from) :
        head_(std::make_shared<ListNode<T>>())
    {
        copy(from);
    }

    template <typename T>
    ForwardList<T>::ForwardList(size_type size, const T& val) :
        head_(std::make_shared<ListNode<T>>())
    {
        auto p = head_;
        for (size_type i = 0; i < size; ++i) {
            p->next_ = std::make_shared<ListNode<T>>(val);
            p = p->next_;
        }
    }

    template <typename T>
    ForwardList<T>::ForwardList(std::initializer_list<T> il) :
        head_(std::make_shared<ListNode<T>>())
    {
        auto p = head_;
        for (const auto& it : il) {
            p->next_ = std::make_shared<ListNode<T>>(it);
            p = p->next_;
        }
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
        auto p = head_->next_->next_;
        if (!p) return;
        head_->next_->next_ = nullptr;

        auto next_p = p;
        while (p) {
            next_p = next_p->next_;
            p->next_ = head_->next_;
            head_->next_ = p;
            p = next_p;
        }
    }

    template <typename T>
    typename ForwardList<T>::iterator ForwardList<T>::insert(iterator pos, const T& value)
    {
        auto p = head_;
        while (p->next_ != pos.ptr_) {
            p = p->next_;
        }
        return insert_after(iterator(p), value);
    }

    template <typename T>
    typename ForwardList<T>::iterator ForwardList<T>::insert_after(iterator pos, const T& value)
    {
        auto p = std::make_shared<ListNode<T>>(value);

        p->next_ = pos.ptr_->next_;
        pos.ptr_->next_ = p;
        return ++pos;
    }

    template <typename T>
    typename ForwardList<T>::iterator ForwardList<T>::erase(iterator pos)
    {
        auto p = head_;
        while (p->next_ != pos.ptr_) {
            p = p->next_;
        }
        return erase_after(iterator(p));
    }
    template <typename T>
    typename ForwardList<T>::iterator ForwardList<T>::erase_after(iterator pos)
    {
        if (pos.ptr_ == nullptr || pos.ptr_->next_ == nullptr)
            return end();

        pos.ptr_->next_ = pos.ptr_->next_->next_;
        return ++pos;
    }

    template <typename T>
    inline
    void ForwardList<T>::copy(const ForwardList<T>& from)
    {
        auto p = head_;
        auto q = from.head_;
        while (q->next_) {
            p->next_ = std::make_shared<ListNode<T>>(q->next_->data_);
            p = p->next_;
            q = q->next_;
        }
    }

    //Non-member function:

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
