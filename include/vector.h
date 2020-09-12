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
        Vector(size_type size, const T &val = T{});
        Vector(const Vector<T> &from);
        Vector(initializer_list<T> il);
        Vector& operator=(const Vector<T> &from);
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

        void push_back(const T &val);
        void pop_back();
        void insert(size_type index, size_type num, const T &val);
        void remove(size_type index, size_type num);
        void reserve( size_type size);

    private:
        T *p_arr_ = nullptr;
        size_type size_ = 0;
        size_type capacity_ = 0;

        void expand_capacity(int multiple);
        void check(size_type i, const string &msg) const
        {
            if(i < 0 || i >= size_) throw std::out_of_range(msg);
        }
        void copy(const Vector<T> &from)
        {
            delete [] p_arr_;
            p_arr_ = new T[from.capacity()] {};
            for (size_type i = 0; i < from.size(); ++i) {
                p_arr_[i] = from.p_arr_[i];
            }
        }
    };

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
    Vector<T>& Vector<T>::operator=(const Vector<T> &from)
    {
        if (p_arr_ != from.p_arr_) {
            size_ = from.size_;
            capacity_ = from.capacity_;
            copy(from);
        }
        return *this;
    }

    template <typename T>
    T& Vector<T>::at(size_type index)
    {
        check(index, "range of out on at()!");
        return p_arr_[index];
    }

    template <typename T>
    const T& Vector<T>::at(size_type index) const
    {
        check(index, "range of out on at()!");
        return p_arr_[index];
    }

    template <typename T>
    T& Vector<T>::front()
    {
        check(0, "front() on empty Vector!");
        return p_arr_[0];
    }

    template <typename T>
    const T& Vector<T>::front() const {
        check(0, "front() on empty Vector!");
        return p_arr_[0];
    }

    template <typename T>
    T& Vector<T>::back()
    {
        check(0, "back() on empty Vector!");
        return p_arr_[size_ - 1];
    }

    template <typename T>
    const T& Vector<T>::back() const
    {
        check(0, "back() on empty Vector!");
        return p_arr_[size_ - 1];
    }

    template <typename T>
    void Vector<T>::push_back(const T &val)
    {
        reserve(size() + 1);
        p_arr_[size_++] = val;
    }

    template <typename T>
    void Vector<T>::pop_back()
    {
        check(0, "pop_back() on empty Vector!");
        --size_;
    }

    template <typename T>
    void Vector<T>::insert(size_type index, size_type num, const T &val)
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
    void Vector<T>::remove(size_type index, size_type num)
    {
        check(num, "remove() on Vector that too small!");
        size_ -= num;
        for (auto i = index; i < size(); ++i) {
            p_arr_[i] = p_arr_[i + num];
        }
    }

    template <typename T>
    void Vector<T>::reserve(size_type size)
    {
        if (capacity_ >= size)
            return;

        if (capacity_ < MINSIZE) capacity_ = MINSIZE;

        int multiple = 2;
        while (multiple * capacity_ < size)
            multiple *= 2;
        expand_capacity(multiple);
    }

    template<typename T>
    void Vector<T>::expand_capacity(int multiple)
    {
        capacity_ *= multiple;
        auto delp = p_arr_;
        p_arr_ = new T[capacity_] {};
        for (size_type i = 0; i != size(); ++i) {
            p_arr_[i] = delp[i];
        }
        delete [] delp;
    }
}

#endif // VECTOR_H
