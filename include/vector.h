#ifndef VECTOR_H
#define VECTOR_H
#include <string>
#include <stdexcept>
#include <memory>

namespace syo {

    template <typename T> class Vector {
    public:
        using size_type = unsigned long long;
        static const size_type MINSIZE = 16;
        class iterator;

        Vector() = default;
        Vector(const Vector<T>& from);
        Vector(size_type size, const T& val = T{});
        Vector(std::initializer_list<T> il);
        Vector& operator=(const Vector& from);
        ~Vector();

        T& operator[](size_type index) { return *(p_arr_+ index ); }
        const T& operator[](size_type index) const { return *(p_arr_ + index); }
        iterator begin() const { return iterator(p_arr_); }
        iterator end() const { return iterator(p_arr_ + size_); }
        T& at(size_type index);
        const T& at(size_type index) const;
        T& back();
        const T& back() const;
        size_type capacity() const { return capacity_; }
        void clear() { size_ = 0; }
        bool empty() const { return size_ == 0; }
        T& front();
        const T& front() const;
        size_type size() const { return size_; }

        void push_back(const T& val);
        void pop_back();
        void insert(size_type index, size_type num, const T& val);
        void insert(size_type index, const T& val) { insert(index, 1, val); }
        void remove(size_type index, size_type num);
        void reserve( size_type size);

        //Exercise extension member function:
        void insert_in_order(const T& val);   //将value插入到第一个大于它的元素之前
        void sort_by_sign();    //将所有负数元素移到所有正数元素之前

    private:
        T* p_arr_ = nullptr;
        size_type size_ = 0;
        size_type capacity_ = 0;

        void check(size_type i, const std::string& msg) const
        {
            if(i >= size_) throw std::out_of_range(msg);
        }
        void copy(const Vector<T>& from)
        {
            delete [] p_arr_;
            p_arr_ = new T[from.capacity()] {};
            for (size_type i = 0; i < from.size(); ++i) {
                p_arr_[i] = from.p_arr_[i];
            }
        }
    };

    template <typename T>
    class Vector<T>::iterator {
    public:
        using difference_type = signed long long;

        iterator(T* ptr = nullptr) : ptr_(ptr) { }
        T& operator*() const { return *ptr_; }
        T* operator->() const {return & this->operator*(); }
        iterator& operator++() { ++ptr_; return *this; }
        iterator operator++(int) { auto ret = *this; ++*this; return ret; }
        iterator& operator--() { --ptr_; return *this; }
        iterator operator--(int) { auto ret = *this; --*this; return ret; }
        bool operator==(const iterator& rhs) const { return ptr_ == rhs.ptr_; }
        bool operator!=(const iterator& rhs) const { return ptr_ != rhs.ptr_; }
        iterator& operator+=(difference_type n) { ptr_ += n; return *this; }
        iterator& operator-=(difference_type n) { return this->operator+=(-n); }
        iterator operator+(difference_type n) const { iterator temp = *this; return temp += n; }
        iterator operator-(difference_type n) const { iterator temp = *this; return temp -= n; }
        difference_type operator-(iterator const& rhs) const { return ptr_ - rhs.ptr_; }
        bool operator<(iterator const& rhs) const {return ptr_ < rhs.ptr; }
        bool operator>(iterator const& rhs) const {return ptr_ > rhs.ptr; }
        bool operator<=(iterator const& rhs) const {return ptr_ <= rhs.ptr; }
        bool operator>=(iterator const& rhs) const {return ptr_ >= rhs.ptr; }
    private:
        T* ptr_;
    };

    //Non-member function:
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Vector<T>& vec);

}

#include "vector.hpp"
#endif // VECTOR_H
