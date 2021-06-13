

#ifndef LABA3_DYNAMICARRAY_H
#define LAB3A_DYNAMICARRAY_H
#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
template<typename T>
class DynamicArray
{
private:
	T* array;
	unsigned int len;
public:
	DynamicArray() :array(0), len(0) {};
	DynamicArray(unsigned int size)
	{
		if (size > 0)
		{
			array = new T[size];
			memset(array, 0, size * sizeof(T));
		}
		else
			array = 0;
		len = size;
	};
	DynamicArray(T* items, unsigned int count)
	{
		array = 0;
		len = count;
		if (count > 0)
		{
			array = new T[count];
			memcpy(array, items, count * sizeof(T));
		}
	};

	DynamicArray(const DynamicArray<T>& dynamicArray)
	{
		array = 0;
		len = dynamicArray.len;
		if (len > 0)
		{
			array = new T[len];
			memcpy(array, dynamicArray.array, len * sizeof(T));
		}
	};

	~DynamicArray() {
		delete[] array;

	}

	T get(unsigned int index) const
	{
		if (index > len)
			throw std::out_of_range("Index larger then array");
		return array[index];
	};

	unsigned int getSize() { return len; };

	void set(size_t index, T value)
	{
		if (index >= len)
			throw std::out_of_range("Index larger then array");
		array[index] = value;
	};

	void resize(unsigned int newSize)
	{
		T* newArray = 0;
		if (newSize > 0)
		{
			newArray = new T[newSize];
			memset(newArray, 0, sizeof(T) * newSize);
			if (newSize >= len)
			{
				memcpy(newArray, array, sizeof(T) * len);
			}
			else
			{
				memcpy(newArray, array, sizeof(T) * newSize);
			}
		}
		delete[] array;
		array = newArray;
		len = newSize;
	};
	DynamicArray<T>* getSubArray(unsigned int startIndex, unsigned int endIndex)
	{
		if (startIndex > endIndex)
			throw std::out_of_range("startIndex > endIndex");
		if (endIndex >= len)
			throw std::out_of_range("endIndex >= length");

		DynamicArray<T>* newarray = new DynamicArray<T>(endIndex - startIndex + 1);
		for (unsigned int i = 0; i < endIndex - startIndex + 1; i++)
			newarray->set(i, array[startIndex + i]);
		return newarray;
	}


	DynamicArray<T>* concatArray(DynamicArray<T>& data)
	{
		unsigned int lens = len;
		this->resize(len + data.getSize());
		for (unsigned int i = 0; i < data.getSize(); ++i) {

			array[lens + i] = data.get(i);
		}
		return this;
	}
	T operator[](size_t index) { return get(index); }

	DynamicArray<T>& operator=(const DynamicArray<T>& list) {
		len = list.len;
		if (len > 0) {
			array = new T[len];
			memcpy(array, list.array, len * sizeof(T));
		}
		return *this;
	}

	void print()
	{
		std::cout << "Dynamic Array" << std::endl;
		std::cout << "SIZE " << len << std::endl;
		for (size_t i = 0; i < len; i++)
			std::cout << "Pos:  " << i << "  Value: " << array[i] << std::endl;
	}

};
#endif //LABA3_DYNAMICARRAY_H
