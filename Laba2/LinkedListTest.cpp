#include "LinkedListTest.h"
#include "LinkedList.h"
#include <iostream>
int testLength()
{
	int len = 3;
	LinkedList<int> Ll;
	Ll.append(1);
	Ll.append(5);
	Ll.append(14);
	if (Ll.getLength() == len)
		std::cout << "Test of function Length Correct" << std::endl;
	else
		std::cout << "Test of function Length Failed" << std::endl;
	return 0;
}

int testGetFirst()
{
	LinkedList<int> Ll;
	Ll.append(1);
	Ll.append(5);
	Ll.append(14);
	int temp = Ll.getFirst();
	if (temp == 1)
		std::cout << "Test of function GetFirst Correct" << std::endl;
	else
		std::cout << "Test of function GetFirst Failed" << std::endl;
	return 0;
}

int testGetLast()
{
	LinkedList<int> Ll;
	Ll.append(1);
	Ll.append(5);
	Ll.append(14);
	int temp = Ll.getLast();
	if (temp == 14)
		std::cout << "Test of function GetLast Correct" << std::endl;
	else
		std::cout << "Test of function GetLast Failed" << std::endl;
	return 0;
}

int testGetIn()
{
	LinkedList<int> Ll;
	Ll.append(1);
	Ll.append(5);
	Ll.append(14);
	int temp = Ll.get(1);
	if (temp == 5)
		std::cout << "Test of function GetIn Correct" << std::endl;
	else
		std::cout << "Test of function GetIn Failed" << std::endl;
	return 0;
}

int testGetSubList()
{
	int initArray[7] = { 1,5,14,75,73,750,10 };
	unsigned int count = 0;
	LinkedList<int> Ll(initArray, 7);
	LinkedList<int>* Lt;
	Lt = Ll.getSubList(2, 5);
	LinkedList<int> Lm;
	Lm.append(14);
	Lm.append(75);
	Lm.append(73);
	Lm.append(750);
	for (unsigned int i = 0; i < 4; i++)
	{
		if (Lm.get(i) == Lt->get(i))
			count++;
	}
	if (count == 4)
		std::cout << "Test of function GetSubList Correct" << std::endl;
	else
		std::cout << "Test of function GetSubList Failed" << std::endl;
	return 0;
}

int testConcat()
{
	unsigned int count = 0;
	LinkedList<int> Ll;
	Ll.append(1);
	Ll.append(5);
	Ll.append(14);
	LinkedList<int> Lm;
	Lm.append(19);
	Lm.append(75);
	Lm.append(73);
	Lm.append(750);
	Ll.concat(&Lm);
	LinkedList<int> Lk;
	Lk.append(1);
	Lk.append(5);
	Lk.append(14);
	Lk.append(19);
	Lk.append(75);
	Lk.append(73);
	Lk.append(750);
	for (unsigned int i = 0; i < Lk.getLength(); i++)
	{
		if (Lk.get(i) == Ll.get(i))
			count++;
	}
	if (count == Lk.getLength())
		std::cout << "Test of function Concat Correct" << std::endl;
	else
		std::cout << "Test of function Concat Failed" << std::endl;
	return 0;
}

int testCopyList()
{
	int initArray[7] = { 1,5,14,75,73,750,10 };
	unsigned int count = 0;
	LinkedList<int> Ll(initArray, 7);
	LinkedList<int> Lm(Ll);
	for (unsigned int i = 0; i < Ll.getLength(); i++)
	{
		if (Ll.get(i) == Lm.get(i))
			count++;
	}
	if (count == Ll.getLength())
		std::cout << "Test of function Copy Correct" << std::endl;
	else
		std::cout << "Test of function Copy Failed" << std::endl;
	return 0;
}

int testList()
{
	int initArray[3] = { 1,2,3 };
	int appendArray[4] = { 1,2,3,4 };
	int prependArray[5] = { 5,1,2,3,4 };
	int insertArray[6] = { 5,1,2,99,3,4 };
	LinkedList<int> Ll(initArray, 3);
	int errorCount = 0;
	for (unsigned int i = 0; i < 3; i++)
	{
		if (Ll.get(i) != initArray[i])
			errorCount++;
	}
	Ll.append(4);
	for (unsigned int i = 0; i < 4; i++)
	{
		if (Ll.get(i) != appendArray[i])
			errorCount++;
	}
	Ll.prepend(5);
	for (unsigned int i = 0; i < 5; i++)
	{
		if (Ll.get(i) != prependArray[i])
			errorCount++;
	}
	Ll.insertAt(99, 3);
	for (unsigned int i = 0; i < 5; i++)
	{
		if (Ll.get(i) != insertArray[i])
			errorCount++;
	}
	if (errorCount == 0)
		std::cout << "Test of function insert, etc Correct" << std::endl;
	else
		std::cout << "Test of all function  Failed" << std::endl;
	return 0;
}