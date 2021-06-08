#pragma once
#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
using namespace std;

template<class T>
class Sequence  {
public:
    Sequence() {}
    T getFirst() { return get(0); };
    T getLast() { return get(this->getSize() - 1); };
    Sequence<T>* getSubsequence(int startIndex, int endIndex) {};
    virtual void set(size_t index, T value) = 0;
    virtual unsigned int getSize() =0;
    virtual T get(size_t index) = 0;
    virtual void append(T item) = 0;
    virtual void prepend(T item) = 0;
    virtual void insertAt(T item, size_t index) = 0;
    virtual Sequence<T>* concat(Sequence<T>& list) = 0;
    virtual ~Sequence() {};
}; 

#endif SEQUENCE_H
