#pragma once
#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "DynamicArray.h"
template<typename T>
class Matrix
{
private:
	DynamicArray<T> Da;
	size_t size;
public:
	Matrix() : Da(0), size(0)
	{
	};
	Matrix(size_t size) :Da(size*size){
		this->size = size;
	};
	Matrix(const Matrix& temp) : size(temp.size), Da(temp.size* temp.size)
	{
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
				this->Da.set(i*size+j, temp.get(i, j));
		}
	};
	//0 элемент-координаты 0;0
	void set(size_t row, size_t col, T value)
	{
		size_t temp = (row) * size+(col);
		Da.set(temp, value);
	}
	T get(size_t row, size_t col) const
	{
		return Da.get(row * size + col);
	}

	Matrix summMatrix(const Matrix& m)
	{
		Matrix<T>* Dt=new Matrix<T>(size);
		for (size_t i = 0; i < size; i++)
		{
			for(size_t j = 0; j < size; j++)
			{
				Dt->set(i, j, this->get(i, j) + m.get(i, j));
			}
		}
		return *Dt;
	}

	Matrix& operator=(const Matrix& m) {
		this->size = m.size;
		this->Da.resize(size * size);
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++){
				this->Da.set( i*size+j, m.get(i, j));
			}
		}
		return *this;
	}


	Matrix scalar(T scalar)
	{
		
		Matrix<T> *Dt = new Matrix<T>(size);
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
				Dt->set(i, j, get(i, j) *scalar);
		}

		return *Dt;
	}



	double norma()
	{
		T newtemp;
		if (std::strcmp(typeid(this->Da.get(0)).name(), "class Complex") == 0)
			throw new std::exception("This type of data unsupported");
		newtemp = Da.get(0) * Da.get(0);
		for (unsigned int i = 1; i < size*size; i++)
		{
			newtemp = newtemp + Da.get(i) * Da.get(i);
		}

		return sqrt(newtemp);
		
	}

	void print()
	{
	
		for (size_t i = 0; i < size; i++)
		{
			std::cout << "| ";
			for (size_t j = 0; j < size; j++)
				std::cout<< get(i, j)<<" ";
			std::cout << "|" << std::endl;;
		}
	}
private:
	double sqrt(double newtemp) {
		return std::sqrt(newtemp);
	}
	double sqrt(Complex newtemp) {
		return 0;
	}
};
