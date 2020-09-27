#ifndef VECTOR_H
#define VECTOR_H
#include <initializer_list>
#include <string>
#include <stdexcept>

namespace syo {

    using std::initializer_list;
    using std::string;

    template <typename T> class Vector {
    public:
        using size_type = unsigned long long;
        static const size_type MINSIZE = 16;

        Vector() = default;
        Vector(const Vector<T>& from);
        Vector(size_type size, const T& val = T{});
        Vector(initializer_list<T> il);
        Vector& operator=(const Vector& from);
        ~Vector();

        T& operator[](size_type index) { return *(p_arr_+ index ); }
        const T& operator[](size_type index) const { return *(p_arr_ + index); }
        T& at(size_type loc);
        const T& at(size_type loc) const;
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

        //extension member function:
        void insert_in_order(const T& val);   //将value插入到第一个大于它的元素之前
        void sort_by_sign();    //将所有负数元素移到所有正数元素之前

    private:
        T *p_arr_ = nullptr;
        size_type size_ = 0;
        size_type capacity_ = 0;

        void check(size_type i, const string& msg) const
        {
            if(i < 0 || i >= size_) throw std::out_of_range(msg);
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

    //non-member function:

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Vector<T>& vec);

}

#include "vector.hpp"

#endif // VECTOR_H
