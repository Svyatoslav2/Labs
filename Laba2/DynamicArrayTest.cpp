#include "DynamicArray.h"
#include "DynamicArrayTest.h"
#include <iostream>
int testSet() 
{
	int test[3] = { 5,8,18 };
	DynamicArray<int> Da(3);
	Da.set(0, 5);
	Da.set(1, 8);
	Da.set(2, 15);
	int count = 0;
	for (unsigned int i = 0; i < 3; i++)
	{
		if (test[i] == Da.get(i))
			count++;	
	}
	if(count==2)
		std::cout << "Test of function Set Correct" << std::endl;
	else
		std::cout << "Test of function Set Failed" << std::endl;

	return 0;
}

int testLen()
{
	DynamicArray<int> Da(3);
	int len = Da.getSize();
	if(len==3)
		std::cout << "Test of function getSize Correct" << std::endl;
	else
		std::cout << "Test of function getSize Failed" << std::endl;
	return 0;
}

int testGet()
{
	DynamicArray<int> Da(3);
	Da.set(0, 5);
	Da.set(1, 8);
	Da.set(2, 15);
	if (Da.get(1) == 8)
		std::cout << "Test of function Get Correct" << std::endl;
	else
		std::cout << "Test of function Get Failed" << std::endl;
	return 0;
}

int testResise()
{
	DynamicArray<int> Da(6);
	Da.set(0, 5);
	Da.set(1, 8);
	Da.set(2, 15);
	Da.set(3, 5);
	Da.set(4, 3);
	Da.set(5, 86);
	DynamicArray<int> Db(3);
	Db.set(0, 5);
	Db.set(1, 8);
	Db.set(2, 15);
	Da.resize(3);
	unsigned int count = 0;
	for (unsigned int i = 0; i < 3; i++)
	{
		if (Da.get(i) == Db.get(i))
			count++;
	}
	if (count == 3)
		std::cout << "Test of function Resise Correct" << std::endl;
	else
		std::cout << "Test of function Resise Failed" << std::endl;
	return 0;
}

int testCopy() 
{
	DynamicArray<int> Da(3);
	Da.set(0, 5);
	Da.set(1, 8);
	Da.set(2, 15);
	DynamicArray<int> Db(Da);
	int count = 0;
	for (unsigned int i = 0; i < 3; i++)
	{
		if (Db.get(i) == Da.get(i))
			count++;
	}
	if (count == 3)
		std::cout << "Test of function Copy Correct" << std::endl;
	else
		std::cout << "Test of function Copy Failed" << std::endl;
	return 0;

}
int testGetSubArray()
{
	int initArray[7] = { 1,5,14,75,73,750,10 };
	int TestArray[4] = { 14,75,73,750 };
	unsigned int count = 0;
	DynamicArray<int> Ll(initArray, 7);
	DynamicArray<int> L1(*Ll.getSubArray(2, 5));
	if (L1.getSize() == 4)
	{
		for (unsigned int i = 0; i < L1.getSize(); i++)
		{
			if (TestArray[i] == L1.get(i))
				count++;
		}
	}
	if(count==4)
		std::cout << "Test of function GetSubArray Correct" << std::endl;
	else
		std::cout << "Test of function GetSubArray Failed" << std::endl;
	return 0;
}

int testConcatArray()
{

	int initArray[7] = { 1,5,14,75,73,750,10 };
	int TestArray[4] = { 14,75,73,750 };
	unsigned int count = 0;
	DynamicArray<int> Ll(initArray, 7);
	DynamicArray<int> Lt(TestArray, 4);
	Ll.concatArray(Lt);
	for (unsigned int i = 0; i < 7; i++)
	{
		if (Ll.get(i) == initArray[i])
			count++;
	}

	for (unsigned int i = 0; i < 4; i++)
	{
		if (Ll.get(7+i) == TestArray[i])
			count++;
	}
	if(count==11)
		std::cout << "Test of function Concat Correct" << std::endl;
	else
		std::cout << "Test of function Concat Failed" << std::endl;
	return 0;
}