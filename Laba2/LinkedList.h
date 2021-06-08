#pragma once
#include <iostream>
#include <stdexcept>

template <class T>
class LinkedList
{
	template <class T>
	class Node
	{
	public:
		T data;
		Node* next;
		Node(T myData) : data(myData), next(0) {};
		Node(T myData, Node* node) :data(myData)
		{
			if (node->next == 0)
			{
				next = 0;
				node->next = this;
			}
			else
				next = node;
		}
	};

private:
	Node<T>* first;
	unsigned int len;
public:

	LinkedList() :first(0), len(0) {};
	LinkedList(T* items, unsigned int count)
	{
		len = 0;
		for (unsigned int i = 0; i < count; i++)
			append(items[i]);
	};
	LinkedList(LinkedList <T>& list)
	{
		len = 0;
		unsigned int lenlist = list.getLength();
		for (unsigned int i = 0; i < lenlist; i++)
			append(list.get(i));
	};
	~LinkedList() 
	{
		if (first != 0)
		{
			Node<T>* tempNode = first->next;
			Node<T>* temp = tempNode;
			delete first;
			while (tempNode != 0)
			{
				tempNode = tempNode->next;
				delete temp;
				temp = tempNode;
			}
		}
	};

	T getFirst()
	{
		return first->data;
	};

	T getLast()
	{
		Node<T>* last = first;
		while (last->next)
		{
			last = last->next;
		}
		return last->data;
	};

	T get(unsigned int index)
	{
		Node<T>* next = first;
		if (index > len)
			throw std::out_of_range("Index larger then list");
		for (unsigned int i = 0; i < index; i++)
			next = next->next;
		return next->data;
	};

	unsigned int getLength() 
	{ 
		return len; 
	};
	
	void append(T item)
	{
		Node<T>* last = first;
		if (first == 0)
			first = new Node<T>(item);
		else
		{
			while (last->next)
				last = last->next;
			Node<T>* newNode = new Node<T>(item, last);
		}
		len++;
	};

	void prepend(T item)
	{
		if (first == 0)
		{
			first = new Node<T>(item);
			len=1;
		}
		else
		{
			if (first->next == 0)
			{
				Node<T>* newNode = new Node<T>(item, first);
				Node<T>* temp = first;
				first = newNode;
				newNode = temp;
				newNode->next = 0;
				first->next = newNode;
				len++;
			}
			else
			{
				Node<T>* newNode = new Node<T>(item, first);
				len++;
				first = newNode;
			}
		}
	};

	void insertAt(T item,unsigned int index)
	{
		if (index > len)
			throw std::out_of_range("Index larger then list");
		if (index == len - 1) 
		{
			this->append(item);
			return;
		}
		else if (index == 0) 
		{
			this->prepend(item);
			return;
		}
		//Ќужно изменить указатель на следующий элемент в предыдущем узле на вставл€емый узел 
		//в вставл€емом узле указатель смотрит на прежний следующий элемент
		Node<T>* prev = first;
		Node<T>* pos = first->next;
		for (unsigned int i = 1; i < index; i++)
		{
			prev = pos;
			pos = pos->next;
		}
		Node<T>* newNode = new Node<T>(item, pos);
		prev->next = newNode;
		len++;
	};

	LinkedList<T>* concat(LinkedList<T>* list)
	{
		for (unsigned int i = 0; i < list->getLength(); i++)
			append(list->get(i));
		return this;
	};

	LinkedList<T>* getSubList(unsigned int startIndex, unsigned int endIndex)
	{
		if ((endIndex >= len) || (startIndex >= endIndex) || (startIndex >= len))
			throw std::out_of_range("Wrong index ");
		LinkedList<T>* res = new LinkedList();
		Node<T>* start = first;
		for (unsigned int i = 0; i <= endIndex; i++) {
			if (i >= startIndex)
				res->append(start->data);
			start = start->next;
		}
		return res;
	};

	LinkedList<T>& operator=( LinkedList<T>& list)
	{
		this->clear();
		for (size_t i = 0; i < list.getLength(); i++)
			this->append(list.get(i));
		return *this;
	}

	void clear() 
	{
		while (first->next != 0)
		{
			Node<T>* prev = first;
			first = first->next;
			delete prev;
		}
		delete first;
	}

	void print()
	{
		Node<T>* node = first;
		std::cout << "LINKED LIST" << std::endl;
		std::cout << "SIZE " << len << std::endl;
		for (size_t i = 0; i < len; i++)
		{
			std::cout << "Pos:  " << i << "  Value: " << node->data << std::endl;
			node = node->next;
		}
	}
};
