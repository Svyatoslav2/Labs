#pragma once

#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H


#include "Sequence.h"
#include "DynamicArray.h"
#include <iostream>
#include <cstring>
using namespace std;

template<class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T> data;

public:
    ArraySequence() {
        data = DynamicArray<T>();
    }
    ArraySequence(size_t count) {
        data = DynamicArray<T>(count);
    }
    ArraySequence(T* items, size_t count) {
        this->data = DynamicArray<T>(items, count);
    }
    ArraySequence(ArraySequence<T> const& list) {
        data = DynamicArray<T>(list.data);
    }
    ArraySequence(DynamicArray<T>& list)
    {
        data = DynamicArray<T>(list);
    }
    void set(size_t index, T value)
    {
        return data.set(index, value);
    };
    T get(unsigned int index)
    {
        return data.get(index);
    };
    unsigned int getSize() {
        return  data.getSize();
    }
    void append(T item)
    {
        data.resize(data.getSize() + 1);
        data.set(data.getSize()-1, item);
        }
    void prepend(T item)
    {
        DynamicArray<T>* newArray = 0;
        newArray = new DynamicArray<T>(data);
        data.resize(data.getSize() + 1);
        for (unsigned int i = 1; i < data.getSize(); i++)
        {
            data.set(i, newArray->get(i-1));
        }
        data.set(0, item);
    }
    void insertAt(T item,size_t index)
    {
        DynamicArray<T>* newArray = 0;
        newArray = new DynamicArray<T>(data);
        data.resize(data.getSize() + 1);
        for (unsigned int i = index; i < data.getSize(); i++)
        {
            data.set(i, newArray->get(i - 1));
        }
        data.set(index, item);
    }
    ArraySequence<T>* concat(Sequence<T>& list) {
        ArraySequence<T>* concat = new ArraySequence<T>(data.getSize()+list.getSize());
        for (unsigned int i = 0; i < data.getSize(); ++i) {
            concat->set(i,data[i]);
        }
        unsigned int k = data.getSize();
        for (unsigned int i = 0; i < list.getSize(); i++) {
            concat->set(k+i,list.get(i));
        }
        return concat;
    }
     DynamicArray<T>* GetSubSequence(unsigned int startIndex, unsigned int endIndex)
    {
        return data.getSubArray(startIndex, endIndex);
        
    }
    void print()
    {
        data.print();
    }
};

#endif ARRAYSEQUENCE_H