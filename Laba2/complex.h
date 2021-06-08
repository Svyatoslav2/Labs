#pragma once
#include <iostream>
#include "DynamicArray.h"
using namespace std;

class Complex {
public:
    double real, im;
    Complex() : real(), im() {}
    Complex(double real, double im=0) {
        this->real = real;
        this->im = im;
    }
    Complex(const Complex& temp) {
        real = temp.real;
        im = temp.im;
    };
    void set(double real=0, double im=0)
    {
        this->real = real;
        this->im = im;
    };
    Complex operator+(const Complex& x) const {
        double i, j;
        i = this->real + x.real;
        j = this->im + x.im;
        return Complex(i, j);
    }
    Complex& operator=(const Complex& x)  {
        this->real =  x.real;
        this->im =  x.im;
        return *this;
    }
    Complex operator-(const Complex& x) const {
        double i, j;
        i = this->real - x.real;
        j = this->im - x.im;
        return Complex(i, j);
    }
    Complex operator*(const Complex& x) const {
        double i, j;
        i = this->real * x.real+(-1)* (this->im * x.im);
        j = this->im * x.real+this->real * x.im;
        return Complex(i, j);
    }
    Complex operator/(Complex& x) const {
        double i, j, k;
        k = real * real + x.im * x.im;
        i = (real * x.real + im * x.im) / k;
        j = (x.real * im - real * x.im) / k;
        return Complex(i, j);
    }
    friend ostream& operator<<(ostream& out, const Complex& x) {
        if (x.im < 0)
            out  <<" "<< x.real<<"  -" << x.im << "*i ";
        else
            out  << " " << x.real << "  +" << x.im << "*i ";
        return out;
    }
    friend istream& operator>>(istream& in, Complex& complex) {
        std::cout << "Input real part: ";
        in >> complex.real;
        std::cout << "Input imaginary part: ";
        in >> complex.im;
        return in;
    }
  
};