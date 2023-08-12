#include "realvector.h"
#include <stdexcept>

template<class T>
RealVector<T>::RealVector() : logical_size(0), array_size(kInitialSize) {
    elems = new T[kInitialSize];
}

template<class T>
RealVector<T>::RealVector(size_t size, const T& value) : logical_size(size), array_size(size * 2) {
    elems = new T[array_size];
    std::fill(begin(), end(), value);
}

template<class T>
RealVector<T>:: ~RealVector() {
    delete [] elems;
}

template<class T>
size_t RealVector<T>:: size() const{
    return logical_size;
}

template<class T>
bool RealVector<T>::empty() const {
    return logical_size == 0;
}

template<class T>
T& RealVector<T>::operator[](size_t index) {
    return *begin() + index;
}

template<class T>
T& RealVector<T>::at(size_t index) {
    if (index >= logical_size) {
        throw std::out_of_range("Index out of bound.");
    }
    return operator[](index);
}

template<class T>
void RealVector<T>::push_back(const T &data) {
    if (size() == array_size){
        grow();
    }
    *end() = data;
    logical_size++;
}

template<class T>
void RealVector<T>::grow() {
    T* temp = new T[array_size * 2];
    std::copy(begin(), end(), temp);
    array_size *= 2;
    elems = temp;
}

template<class T>
typename RealVector<T> :: iterator RealVector<T>::begin() {
    return elems;
}

template<class T>
typename RealVector<T> :: const_iterator RealVector<T>::begin() const {
    return static_cast<const_iterator>(const_cast<RealVector<T>*> (this)->begin());
}

template<class T>
typename RealVector<T> :: iterator RealVector<T>::end() {
    return begin() + size();
}

template<class T>
typename RealVector<T> :: const_iterator RealVector<T>::end() const {
    return static_cast<const_iterator>(const_cast<RealVector<T>*>(this)->end());
}