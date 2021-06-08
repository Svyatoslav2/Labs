#define _CRT_SECURE_NO_WARNINGS

#include "LinkedList.h"
#include "DynamicArray.h"
#include "DynamicArrayTest.h"
#include "LinkedListTest.h"
#include "ArraySequenceTest.h"
#include "ListSequenceTest.h"
#include "ListSequence.h"
#include "ArraySequence.h"
#include "complex.h"
#include "Matrix.h"
#include <iostream>
#include <string.h>
void ManualTest();
void AutoTest();
void dynamicArray();
void linkedList();
void sequence();
void matrix();
template<typename T> void startArraySequence();
template<typename T> void PrependListCreate();
template<typename T> void AppendListCreate();
template<typename T> void PrependListCreateSequence();
template<typename T> void AppendListCreateSequence();
template <typename T> void startMatrix();
void AppendList();
void arraySequence();
void listSequence();
void PrependList();
void PrependListSequence();
void AppendListSequence();
template<typename T> void StartArray();
int main()
{
	char ch=0;
	while (ch != 'x')
	{
		std::cout << "==== MAIN MENU ====" << std::endl;
		std::cout << "Choose variant" << std::endl;
		std::cout << "1-Manual input" << std::endl;
		std::cout << "2-AutoTest" << std::endl;
		std::cout << "x-for exit" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case '1':ManualTest(); break;
		case '2':AutoTest(); break;
		}
	}
		return 0;
}
void ManualTest()
{
	char ch = 0;
	while (ch != 'x')
	{
		std::cout << "=== MANUAL TEST MENU ===" << std::endl;
		std::cout << "Choose variant" << std::endl;
		std::cout << "1-DynamicArray" << std::endl;
		std::cout << "2-LinkedList" << std::endl;
		std::cout << "3-Sequence" << std::endl;
		std::cout << "4-Matrix" << std::endl;
		std::cout << "x-for exit" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case '1':dynamicArray(); break;
		case '2':linkedList(); break;
		case '3':sequence(); break;
		case '4':matrix(); break;

		}
	}
	while ((getchar()) != '\n');
}



void matrix()
{
	char ch = 0;
	while (ch != 'x')
	{
		std::cout << "=== MATRIX TEST MENU ===" << std::endl;
		std::cout << "Choose type of data" << std::endl;
		std::cout << "1-int" << std::endl;
		std::cout << "2-double" << std::endl;
		std::cout << "3-complex" << std::endl;
		std::cout << "x-for exit" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case('1'):startMatrix<int>(); break;
		case('2'):startMatrix<double>(); break;
		case('3'):startMatrix<Complex>(); break;
		}
	}
}


template <typename T> 
void startMatrix() 
{
	size_t size;
	char ch = 0;
	T emp;
	std::cout << "Input dimension" << std::endl;
	std::cin >> size;
	Matrix<T>temp(size);
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			std::cout << "Input data:  " << std::endl;
			std::cin >> emp;
			temp.set(i, j, emp);
		}
	}
	temp.print();


	while (ch != 'x')
	{
		std::cout << "Choose function" << std::endl;
		std::cout << "1-summ" << std::endl;
		std::cout << "2-multiplication by scalar" << std::endl;
		std::cout << "3-normal" << std::endl;
		std::cout << "x-for exit" << std::endl;
		std::cin >> ch;

		switch (ch)
		{
		case('1'): 
		{
			Matrix<T> newp(size);
			Matrix<T> res(size);
			std::cout << "Input new matrix" << std::endl;
			for (size_t i = 0; i < size; i++)
			{
				for (size_t j = 0; j < size; j++)
				{
					std::cout << "Input data ";
					std::cin >> emp;
					newp.set(i, j, emp);
				}
			}
			res = temp.summMatrix(newp);
			res.print();
		};
		break;
	case('2'): 
		{
			T scal;
			std::cout << "Input scalar ";
			std::cin >> scal;
			Matrix<T> res=temp.scalar(scal);
			res.print();
		};
		break;
		case('3'): 
		{
			try 
			{
				std::cout << temp.norma() << std::endl;
			}
			catch(std::exception *e)
			{
				std::cout <<"ERROR: " << e->what() << std::endl << std::endl;
			}
		};
		break;
		}
	}
}

void sequence() 

{
	char ch = 0;
	while (ch != 'x')
	{
		std::cout << "=== SEQUENCE TEST MENU ===" << std::endl;

		std::cout << "Choose variant" << std::endl;
		std::cout << "1-ArraySequence" << std::endl;
		std::cout << "2-ListSequence" << std::endl;
		std::cout << "x-for exit" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case '1':arraySequence(); break;
		case '2':listSequence(); break;
		}
	}
}
void arraySequence()
{
	char ch = 0;
	while (ch != 'x')
	{
		std::cout << "Choose type of data" << std::endl;
		std::cout << "1-int" << std::endl;
		std::cout << "2-float" << std::endl;
		std::cout << "x-for exit" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case('1'):startArraySequence<int>(); break;
		case('2'):startArraySequence<float>(); break;
		}
	}
	while ((getchar()) != '\n');
}
template<typename T>
void startArraySequence()
{

	size_t len = 0;
	std::cout << "Print len of array ";
	std::cin >> len;
	ArraySequence<T> Da(len);
	T temp;
	for (size_t i = 0; i < len; i++)
	{
		std::cout << "Input data ";
		std::cin >> temp;
		Da.set(i, temp);
	}

	char ch = 0;


	while (ch != 'x')
	{
		std::cout << "Choose function" << std::endl;
		std::cout << "1-get" << std::endl;
		std::cout << "2-getSize" << std::endl;
		std::cout << "3-Concat" << std::endl;
		std::cout << "4-getSubArray" << std::endl;
		std::cout << "5-append" << std::endl;
		std::cout << "6-prepend" << std::endl;
		std::cout << "7-insertAt" << std::endl;
		std::cout << "x-for exit" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case('1'):
			size_t number;
			std::cout << "Choose number" << std::endl;
			std::cin >> number;
			std::cout << "value: " << Da.get(number) << std::endl;
			break;
		case('2'):std::cout << "Size:  " << Da.getSize() << std::endl; while ((getchar()) != '\n'); break;
		case('3'):
		{
			size_t leng;
			std::cout << "Print len of new array ";
			std::cin >> leng;
			ArraySequence<T> Dt(leng);
			
			T tem;
			for (size_t i = 0; i < leng; i++)
			{
				std::cout << "Input new data ";
				std::cin >> tem;
				Dt.set(i, tem);
			}
			ArraySequence<T> Df(*Da.concat(Dt)) ;
			Df.print();
		}
		break;
		case('4'):
		{	size_t number1;
		size_t number2;
		std::cout << "Choose first number" << std::endl;
		std::cin >> number1;
		std::cout << "Choose last number" << std::endl;
		std::cin >> number2;
		ArraySequence<T> Ds(*Da.GetSubSequence(number1, number2));
		Ds.print();
		}	break;
		case('5'):
		{	T temp;
		std::cout << "Print data: ";
		std::cin >> temp;
		Da.append(temp);
		Da.print();
		}	break;
		case('6'):
		{	T temp;
		std::cout << "Print data: ";
		std::cin >> temp;
		Da.prepend(temp);
		Da.print();
		}	break;
		case('7'):
		{T temp;
		size_t count;
		std::cout << "Print data: ";
		std::cin >> temp;
		std::cout << "Print count: ";
		std::cin >> count;
		Da.insertAt(temp, count);
		Da.print();
		}break;
		}
	}
	while ((getchar()) != '\n');

}
void listSequence() 
{
	char ch = 0;
	while (ch != 'x')
	{
		std::cout << "Choose type of input" << std::endl;
		std::cout << "1-append" << std::endl;
		std::cout << "2-prepend" << std::endl;
		std::cout << "x-for exit" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case('1'):AppendListSequence(); break;
		case('2'):PrependListSequence(); break;
		}

	}
	while ((getchar()) != '\n');
}
void AppendListSequence()
{
	char ch = 0;
	while (ch != 'x')
	{
		std::cout << "Choose type of data" << std::endl;
		std::cout << "1-int" << std::endl;
		std::cout << "2-float" << std::endl;
		std::cout << "3-string" << std::endl;
		std::cout << "x-for exit" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case('1'):AppendListCreateSequence<int>(); break;
		case('2'):AppendListCreateSequence<float>(); break;
		case('3'):AppendListCreateSequence<std::string>(); break;
		}
	}
	while ((getchar()) != '\n');




}
void PrependListSequence()
{
	char ch = 0;
	while (ch != 'x')
	{
		std::cout << "Choose type of data" << std::endl;
		std::cout << "1-int" << std::endl;
		std::cout << "2-float" << std::endl;
		std::cout << "3-string" << std::endl;
		std::cout << "x-for exit" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case('1'):PrependListCreateSequence<int>(); break;
		case('2'):PrependListCreateSequence<float>(); break;
		case('3'):PrependListCreateSequence<std::string>(); break;
		}
	}
	while ((getchar()) != '\n');


}
void dynamicArray() 
{
	char ch = 0;
	while (ch != 'x')
	{
		std::cout << "=== DYNAMIC ARRAY TEST MENU ===" << std::endl;
		std::cout << "Choose type of data" << std::endl;
		std::cout << "1-int" << std::endl;
		std::cout << "2-float" << std::endl;
		std::cout << "x-for exit" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case('1'):StartArray<int>(); break;
		case('2'):StartArray<float>(); break;
		}

	}

	
	while ((getchar()) != '\n');
}
template <typename T> void read(T& item)
{
	std::cout << "Input data ";
	std::cin >> item;
}

template <> void read(std::string& item)
{
	std::cout << "Input data ";
	std::cin.ignore(32767, '\n');
	std::getline(std::cin, item);
}
void linkedList()
{
	char ch = 0;
	while (ch != 'x')
	{
		std::cout << "=== LINKED LIST TEST MENU ===" << std::endl;
		std::cout << "Choose type of input" << std::endl;
		std::cout << "1-append" << std::endl;
		std::cout << "2-prepend" << std::endl;
		std::cout << "x-for exit" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case('1'):AppendList(); break;
		case('2'):PrependList(); break;
		}

	}
	while ((getchar()) != '\n');

}
template<typename T>
void PrependListCreateSequence() 
{
	
	char ans = 'y';
	ListSequence<T> Ll;
	T temp;
	while (ans == 'y')
	{
		read(temp);
		Ll.prepend(temp);
		std::cout << "Continue (y/n) ? ";
		std::cin >> ans;
	}
	char ch = 0;


	while (ch != 'x')
	{
		std::cout << "=================" << std::endl;
		std::cout << "Choose function" << std::endl;
		std::cout << "1-getFirst" << std::endl;
		std::cout << "2-getLast" << std::endl;
		std::cout << "3-get" << std::endl;
		std::cout << "4-getLength" << std::endl;
		std::cout << "5-getSubList" << std::endl;
		std::cout << "6-append" << std::endl;
		std::cout << "7-prepend" << std::endl;
		std::cout << "8-insertAt" << std::endl;
		std::cout << "9-concat" << std::endl;
		std::cout << "x-for exit" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case('1'):std::cout << "First element: " << Ll.getFirst() << std::endl; break;
		case('2'):std::cout << "Last element: " << Ll.getLast() << std::endl; break;
		case('3'): {
			size_t t;
			std::cout << "Input number : ";
			std::cin >> t;
			std::cout << "Item : " << Ll.get(t) << std::endl;
		}break;
		case('4'):std::cout << "Length: : " << Ll.getSize() << std::endl; break;
		case('5'): {
			ListSequence<T>* pll;;
			size_t t1;
			size_t t2;
			std::cout << "Input first number : ";
			std::cin >> t1;
			std::cout << "Input last number : ";
			std::cin >> t2;
			std::cout << "SubList : " << std::endl;
			pll = Ll.GetSubSequence(t1, t2);
			pll->print();
		}break;
		case('6'):
		{
			T temp;
			std::cout << "Print data: ";
			std::cin >> temp;
			Ll.append(temp);
			Ll.print();
		}break;
		case('7'):
		{
			T temp;
			std::cout << "Print data: ";
			std::cin >> temp;
			Ll.prepend(temp);
			Ll.print();
		}break;
		case('8'):
		{
			T temp;
			size_t count;
			std::cout << "Print data: ";
			std::cin >> temp;
			std::cout << "Print count: ";
			std::cin >> count;
			Ll.insertAt(temp, count);
			Ll.print();
		}break;
		case('9'):
		{
			char ans = 'y';
			ListSequence<T> Ll1;
			T temp;
			while (ans == 'y')
			{
				read(temp);
				Ll1.append(temp);
				std::cout << "Continue (y/n) ? ";
				std::cin >> ans;
			}
			
			ListSequence<T> Lt(*Ll.concat(Ll1));
			Lt.print();
		}break;
		}
	}
	Ll.print();
	

}
template<typename T>
void AppendListCreateSequence() 
{
	char ans = 'y';
	
	ListSequence<T> Ll;
	
	T temp;

	while (ans == 'y')
	{
		read(temp);
		Ll.append(temp);
		std::cout << "Continue (y/n) ? ";
		std::cin >> ans;
	}
	char ch = 0;

	
	while (ch != 'x')
	{
		std::cout << "=================" << std::endl;
		std::cout << "Choose function" << std::endl;
		std::cout << "1-getFirst" << std::endl;
		std::cout << "2-getLast" << std::endl;
		std::cout << "3-get" << std::endl;
		std::cout << "4-getLength" << std::endl;
		std::cout << "5-getSubList" << std::endl;
		std::cout << "6-append" << std::endl;
		std::cout << "7-prepend" << std::endl;
		std::cout << "8-insertAt" << std::endl;
		std::cout << "9-concat" << std::endl;
		std::cout << "x-for exit" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case('1'):std::cout << "First element: " << Ll.getFirst() << std::endl; break;
		case('2'):std::cout << "Last element: " << Ll.getLast() << std::endl; break;
		case('3'): {
			size_t t;
			std::cout << "Input number : ";
			std::cin >> t;
			std::cout << "Item : " << Ll.get(t) << std::endl;
		}break;
		case('4'):std::cout << "Length: : " << Ll.getSize() << std::endl; break;
		case('5'): {
			ListSequence<T>* pll;;
			size_t t1;
			size_t t2;
			std::cout << "Input first number : ";
			std::cin >> t1;
			std::cout << "Input last number : ";
			std::cin >> t2;
			std::cout << "SubList : " << std::endl;
			pll = Ll.GetSubSequence(t1, t2);
			pll->print();
		}break;
		
		case('6'):
		{
			T temp;
			std::cout << "Print data: ";
			std::cin >> temp;
			Ll.append(temp);
			Ll.print();
		}break;
		case('7'):
		{
			T temp;
			std::cout << "Print data: ";
			std::cin >> temp;
			Ll.prepend(temp);
			Ll.print();
		}break;
		case('8'):
		{
			T temp;
			size_t count;
			std::cout << "Print data: ";
			std::cin >> temp;
			std::cout << "Print count: ";
			std::cin >> count;
			Ll.insertAt(temp, count);
			Ll.print();
		}break;
		
		case('9'):
		{
			char ans = 'y';
			ListSequence<T> Ll1;
			T temp;
			while (ans == 'y')
			{
				read(temp);
				Ll1.append(temp);
				std::cout << "Continue (y/n) ? ";
				std::cin >> ans;
			}
			ListSequence<T> Lt(*Ll.concat(Ll1));
			Lt.print();
		}break;
		}
	}
	
	Ll.print();



}

void AppendList()
{

	char ch = 0;
	while (ch != 'x')
	{
		std::cout << "Choose type of data" << std::endl;
		std::cout << "1-int" << std::endl;
		std::cout << "2-float" << std::endl;
		std::cout << "3-string" << std::endl;
		std::cout << "x-for exit" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case('1'):AppendListCreate<int>(); break;
		case('2'):AppendListCreate<float>(); break;
		case('3'):AppendListCreate<std::string>(); break;
		}
	}
	while ((getchar()) != '\n');
}
void PrependList()
{
	char ch = 0;
	while (ch != 'x')
	{
		std::cout << "Choose type of data" << std::endl;
		std::cout << "1-int" << std::endl;
		std::cout << "2-float" << std::endl;
		std::cout << "3-string" << std::endl;
		std::cout << "x-for exit" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case('1'):PrependListCreate<int>(); break;
		case('2'):PrependListCreate<float>(); break;
		case('3'):PrependListCreate<std::string>(); break;
		}
	}
	while ((getchar()) != '\n');
}
template<typename T>
void PrependListCreate() 
{
	char ans = 'y';
	LinkedList<T> Ll;
	T temp;
	while (ans == 'y')
	{
		read(temp);
		Ll.prepend(temp);
		std::cout << "Continue (y/n) ? ";
		std::cin >> ans;
	}
	char ch = 0;


	while (ch != 'x')
	{
		std::cout << "Choose function" << std::endl;
		std::cout << "1-getFirst" << std::endl;
		std::cout << "2-getLast" << std::endl;
		std::cout << "3-get" << std::endl;
		std::cout << "4-getLength" << std::endl;
		std::cout << "5-getSubList" << std::endl;
		std::cout << "6-append" << std::endl;
		std::cout << "7-prepend" << std::endl;
		std::cout << "8-insertAt" << std::endl;
		std::cout << "9-concat" << std::endl;
		std::cout << "x-for exit" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case('1'):std::cout << "First element: " << Ll.getFirst() << std::endl; break;
		case('2'):std::cout << "Last element: " << Ll.getLast() << std::endl; break;
		case('3'): {
			size_t t;
			std::cout << "Input number : ";
			std::cin >> t;
			std::cout << "Item : " << Ll.get(t) << std::endl;
		}break;
		case('4'):std::cout << "Length: : " << Ll.getLength() << std::endl; break;
		case('5'): {
			LinkedList<T>* pll;;
			size_t t1;
			size_t t2;
			std::cout << "Input first number : ";
			std::cin >> t1;
			std::cout << "Input last number : ";
			std::cin >> t2;
			std::cout << "SubList : " << std::endl;
			pll = Ll.getSubList(t1, t2);
			pll->print();
		}break;
		case('6'):
		{
			T temp;
			std::cout << "Print data: ";
			std::cin >> temp;
			Ll.append(temp);
			Ll.print();
		}break;
		case('7'):
		{
			T temp;
			std::cout << "Print data: ";
			std::cin >> temp;
			Ll.prepend(temp);
			Ll.print();
		}break;
		case('8'):
		{
			T temp;
			size_t count;
			std::cout << "Print data: ";
			std::cin >> temp;
			std::cout << "Print count: ";
			std::cin >> count;
			Ll.insertAt(temp, count);
			Ll.print();
		}break;
		case('9'):
		{
			char ans = 'y';
			LinkedList<T> Ll1;
			T temp;
			while (ans == 'y')
			{
				read(temp);
				Ll1.append(temp);
				std::cout << "Continue (y/n) ? ";
				std::cin >> ans;
			}
			Ll.concat(&Ll1);;
			Ll.print();
		}break;
		}
	}
	Ll.print();
}

template<typename T>
void AppendListCreate()
{
	char ans = 'y';
	LinkedList<T> Ll;
	T temp;
	while (ans=='y')
	{
		//std::cout << "Input data ";
		//std::cin >> temp;
		read(temp);
		Ll.append(temp);
		std::cout << "Continue (y/n) ? ";
		std::cin >> ans;		
	}
	char ch = 0;


	while (ch != 'x')
	{
		std::cout << "Choose function" << std::endl;
		std::cout << "1-getFirst" << std::endl;
		std::cout << "2-getLast" << std::endl;
		std::cout << "3-get" << std::endl;
		std::cout << "4-getLength" << std::endl;
		std::cout << "5-getSubList" << std::endl;
		std::cout << "6-append" << std::endl;
		std::cout << "7-prepend" << std::endl;
		std::cout << "8-insertAt" << std::endl;
		std::cout << "9-concat" << std::endl;
		std::cout << "x-for exit" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case('1'):std::cout << "First element: " << Ll.getFirst() << std::endl; break;
		case('2'):std::cout << "Last element: " << Ll.getLast() << std::endl; break;
		case('3'): {
			size_t t;
			std::cout << "Input number : " ;
			std::cin >> t;
			std::cout << "Item : " << Ll.get(t) << std::endl;
		}break;
		case('4'):std::cout << "Length: : " << Ll.getLength() << std::endl; break;
		case('5'): {
			LinkedList<T>* pll;;
			size_t t1;
			size_t t2;
			std::cout << "Input first number : ";
			std::cin >> t1;
			std::cout << "Input last number : ";
			std::cin >> t2;
			std::cout << "SubList : "  << std::endl;
			pll=Ll.getSubList(t1, t2);
			pll->print();
		}break;
		case('6'):
			{
			T temp;
			std::cout << "Print data: ";
			std::cin >> temp;
			Ll.append(temp);
			Ll.print();
			}break;
		case('7'):
		{
			T temp;
			std::cout << "Print data: ";
			std::cin >> temp;
			Ll.prepend(temp);
			Ll.print();
		}break;
		case('8'):
		{
			T temp;
			size_t count;
			std::cout << "Print data: ";
			std::cin >> temp;
			std::cout << "Print count: ";
			std::cin >> count;
			Ll.insertAt(temp,count);
			Ll.print();
		}break;
		case('9'):
		{
			char ans = 'y';
			LinkedList<T> Ll1;
			T temp;
			while (ans == 'y')
			{
				read(temp);
				Ll1.append(temp);
				std::cout << "Continue (y/n) ? ";
				std::cin >> ans;
			}
			Ll.concat(&Ll1);;
			Ll.print();
			}break;
		}
	}
	Ll.print();
}

template<typename T>
void StartArray()
{
	size_t len = 0;
	std::cout << "Print len of array ";
	std::cin >> len;
	DynamicArray<T> Da(len);
	T temp;
	for (size_t i = 0; i < len; i++)
	{
		std::cout << "Input data ";
		std::cin >> temp;
		Da.set(i, temp);
	}
	
	char ch = 0;
	 

	while (ch != 'x')
	{
		std::cout << "Choose function" << std::endl;
		std::cout << "1-get" << std::endl;
		std::cout << "2-getSize" << std::endl;
		std::cout << "3-Resize" << std::endl;
		std::cout << "4-Concat" << std::endl;
		std::cout << "5-getSubArray" << std::endl;
		std::cout << "x-for exit" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case('1'):
			size_t number;
			std::cout << "Choose number" << std::endl;
			std::cin >> number;
			std::cout<<"value: "<<Da.get(number)<<std::endl;
			break;
		case('2'):std::cout << "Size:  " << Da.getSize() << std::endl; while ((getchar()) != '\n'); break;
		case('3'):
			size_t newlen;
			std::cout << "Print new length" << std::endl;
			std::cin>>newlen;
			Da.resize(newlen);
			Da.print();
			break;
		case('4'):
		{
		size_t leng;
		std::cout << "Print len of new array ";
		std::cin >> leng;
		DynamicArray<T> Dt(leng);
		T tem;
		for (size_t i = 0; i < leng; i++)
		{
			std::cout << "Input new data ";
			std::cin >> tem;
			Dt.set(i, tem);
		}
		Da.concatArray(Dt);
		Da.print();
		}
		break;
		case('5'):
			size_t number1;
			size_t number2;
			std::cout << "Choose first number" << std::endl;
			std::cin >> number1;
			std::cout << "Choose last number" << std::endl;
			std::cin >> number2;
			DynamicArray<T> Ds(*Da.getSubArray(number1, number2));
			Ds.print();
			break;
		}
	}
	while ((getchar()) != '\n');
}
void AutoTest()
{
	std::cout << "=== AUTO TEST ===" << std::endl;
	std::cout << "DynamicArrayTest" << std::endl;
	testSet();
	testLen();
	testGet();
	testResise();
	testCopy();
	testGetSubArray();
	testConcatArray();
	std::cout << "ArraySequenceTest" << std::endl;
	testSets();
	testLens();
	testGets();
	testResises();
	testCopys();
	testGetSubArrays();
	testConcatArraySequence();
	std::cout << "LinkedListTest" << std::endl;
	testLength();
	testGetIn();
	testGetLast();
	testGetFirst();
	testGetSubList();
	testConcat();
	testCopyList();
	testList();
	std::cout << "ListSequenceTest" << std::endl;
	testLengths();
	testGetIns();
	testGetLasts();
	testGetFirsts();
	testGetSubLists();
	testConcats();
	testCopyLists();
	testLists();
	std::cout << "=== AUTO TEST DONE ===" << std::endl << std::endl;
	while ((getchar()) != '\n');
}