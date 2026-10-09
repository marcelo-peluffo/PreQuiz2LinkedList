#pragma once
#include <iostream>

template <typename T> class Vector {
private:
    T x;
    T y;
    
public:
    Vector<T>() : x(1), y(1) {}
    Vector<T>(T x, T y) : x(x), y(y) {}
    
    void setX(T x) {
        this -> x = x;
    }
    
    void setY(T y) {
        this -> y = y;
    }
    
    const T &getX() const {
        return x;
    }
    
    const T &getY() const {
        return y;
    }
    
    friend std::ostream &operator<<(std::ostream &out, const Vector<T> &vec) {
        return out << "(" << vec.x << ", " << vec.y << ")";
    }
    
    Vector<T> operator+(const Vector<T> &vec) {
        return Vector<T>(x + vec.x, y + vec.y);
    }
    
    Vector<T> operator-(const Vector<T> &vec) {
        return Vector<T>(x - vec.x, y - vec.y);
    }
    
    Vector<T> &operator++() {
        ++x; ++y;
        return *this;
    }
    
    Vector<T> operator++(int) {
        return Vector<T>(x++, y++);
    }
    
    Vector<T> &operator--() {
        --x; --y;
        return *this;
    }
    
    Vector<T> operator--(int) {
        return Vector<T>(x--, y--);
    }
};
