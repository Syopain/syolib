#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "vector.h"

namespace syo {

    template <typename T>
    Vector<T>::Vector(size_type size, const T &val) :
        size_(size),
        capacity_(size)
    {
        if (size > 0) {
            p_arr_ = new T[capacity_] {};
            if(val != T{})
                for(size_type i = 0; i < size_; ++i) {
                    p_arr_[i] = val;
                }
        }
    }

    template <typename T>
    Vector<T>::Vector(const Vector<T> &from) :
        size_(from.size_),
        capacity_(from.capacity_)
    {
        copy(from);
    }

    template <typename T>
    Vector<T>::Vector(initializer_list<T> il) :
        size_(il.size()),
        capacity_(il.size())
    {
        p_arr_ = new T[capacity_] {};
        auto p = p_arr_;
        for (const auto &elem : il) {
            *p++ = elem;
        }
    }

    template <typename T>
    Vector<T>::~Vector()
    {
        delete [] p_arr_;
        p_arr_ = nullptr;
    }

    template <typename T>
    inline Vector<T>& Vector<T>::operator=(const Vector<T> &from)
    {
        if (p_arr_ != from.p_arr_) {
            size_ = from.size_;
            capacity_ = from.capacity_;
            copy(from);
        }
        return *this;
    }

    template <typename T>
    inline T& Vector<T>::at(size_type index)
    {
        check(index, "range of out on at()!");
        return p_arr_[index];
    }

    template <typename T>
    inline const T& Vector<T>::at(size_type index) const
    {
        check(index, "range of out on at()!");
        return p_arr_[index];
    }

    template <typename T>
    inline T& Vector<T>::front()
    {
        check(0, "front() on empty Vector!");
        return p_arr_[0];
    }

    template <typename T>
    inline const T& Vector<T>::front() const {
        check(0, "front() on empty Vector!");
        return p_arr_[0];
    }

    template <typename T>
    inline T& Vector<T>::back()
    {
        check(0, "back() on empty Vector!");
        return p_arr_[size_ - 1];
    }

    template <typename T>
    inline const T& Vector<T>::back() const
    {
        check(0, "back() on empty Vector!");
        return p_arr_[size_ - 1];
    }

    template <typename T>
    inline void Vector<T>::push_back(const T &val)
    {
        reserve(size() + 1);
        p_arr_[size_++] = val;
    }

    template <typename T>
    inline void Vector<T>::pop_back()
    {
        check(0, "pop_back() on empty Vector!");
        --size_;
    }

    template <typename T>
    inline void Vector<T>::insert(size_type index, size_type num, const T &val)
    {
        reserve(size() + num);
        size_ += num;
        for (auto i = size() - 1; i >= index + num; --i) {
            p_arr_[i] = p_arr_[i - num];
        }
        for (auto i = index; i != index + num; ++i) {
            p_arr_[i] = val;
        }
    }

    template <typename T>
    inline void Vector<T>::remove(size_type index, size_type num)
    {
        check(num, "remove() on Vector that too small!");
        size_ -= num;
        for (auto i = index; i < size(); ++i) {
            p_arr_[i] = p_arr_[i + num];
        }
    }

    template <typename T>
    inline void Vector<T>::reserve(size_type size)
    {
        if (capacity_ >= size)
            return;

        if (capacity_ < MINSIZE) capacity_ = MINSIZE;

        int multiple = 1;
        while (multiple * capacity_ < size)  multiple *= 2;

        capacity_ *= multiple;
        auto delp = p_arr_;
        p_arr_ = new T[capacity_] {};
        for (size_type i = 0; i != size_; ++i) {
            p_arr_[i] = delp[i];
        }
        delete [] delp;
    }

    template<typename T>
    void Vector<T>::insert_in_order(const T &val)
    {
        size_type index = 0;
        while (index != size() && p_arr_[index] < val) {
            ++index;
        }
        insert(index, val);
    }

    template<typename T>
    void Vector<T>::sort_by_sign()
    {
        T *left = p_arr_;
        T *right = p_arr_ + size() - 1;
        while (left < right) {
            while (*left <= 0) left++;
            while (*right >= 0) right--;
            if (left < right) {
                std::swap(*left, *right);
            }
        }
    }

    //non-member function:

    template <typename T>
    std::ostream& operator<<(std::ostream &os, const Vector<T> &vec)
    {
        for (size_t i = 0; i < vec.size(); ++i) {
            os << vec[i] << ' ';
        }
        return os;
    }
}

#endif
