#pragma once
#ifndef LISTSEQUENCE_H
#define LISTSEQUENCE_H
#include "Sequence.h"
#include "LinkedList.h"
#include <iostream>
#include <cstring>
using namespace std;

template<class T>
class ListSequence : public Sequence<T> {
private:
    LinkedList<T> data;
public:
    ListSequence() {};

    ListSequence(T* items, size_t count) {
        data = LinkedList<T>(items, count);
    }
    ListSequence(ListSequence<T> & list) {
        for (unsigned int i =0 ; i < list.getSize(); i++)
            data.append(list.data.get(i));
    }
    void set(size_t index, T value)
    {
        return data.insertAt(value,index);
    };
    T get(unsigned int index)
    {
        return data.get(index);
    };
    unsigned int getSize() {
        return  data.getLength();
    }
    void append(T item)
    {
        data.append(item);
    }
    void prepend(T item)
    {
        data.prepend(item);
     }
    void insertAt(T item, size_t index)
    {
        data.insertAt(item, index);
    }
    ListSequence<T>* concat(Sequence<T>& list) {
        ListSequence<T>* concat = new ListSequence<T>();
        for (unsigned int i = 0; i < data.getLength(); ++i) {
            concat->append(data.get(i));
        }
        for (unsigned int i = 0; i < list.getSize(); ++i) {
            concat->append(list.get(i));
        }
        return concat;
    }
    ListSequence<T>* GetSubSequence(unsigned int startIndex, unsigned int endIndex)
    {
      ListSequence<T> *subseq = new ListSequence<T>();
      for (unsigned int i = startIndex; i <= endIndex; i++)
            subseq->append(this->data.get(i));
      return subseq ;

    }
    void print()
    {
        data.print();
    }
};

#endif LISTSEQUENCE_H