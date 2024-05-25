#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>


template<typename T>
class Vector {
public:
    Vector();
    Vector(size_t);
    Vector(size_t, const T&);
    Vector(const Vector&);
    ~Vector();
    //functions
    void push_back(const T&);
    void pop_back();
    void insert(const size_t&, const T&);
    void erase(const size_t&);
    const size_t size() const;
    const bool isEmpty() const;
    void reallocate();
    //operators
    T& operator[](size_t);
    const T& operator[](size_t) const;
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Vector<U>&);
    Vector& operator=(const Vector&);

    //iterator
    class Iterator{
    public:
        Iterator(T*);
        Iterator &operator++(); 
        Iterator &operator++(int);
        Iterator &operator--(); 
        Iterator &operator--(int);
        bool operator!=(const Iterator&) const;
        bool operator==(const Iterator&) const;
        T& operator*();
        T* operator->();
    private:
        T* it;
    };

    //iterator functions
    Iterator begin() const;
    Iterator end() const;

private:
    size_t capacity_;
    size_t size_;
    T* data_;
};


#include "vector.inl"
#endif