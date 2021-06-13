
#ifndef LABA3_ASSIGN_H
#define LABA3_ASSIGN_H

#include "BinaryTree.h"
#include "ArraySequence.h"
#include <iostream>

using namespace std;



template<class T>
class Set : public Tree<T> {
protected:
    void UnionPath(Node<T>* node, Set<T>* set) {
        if (node) {
            set->Add(node->key);
            UnionPath(node->left, set);
            UnionPath(node->right, set);
        }
    }

    Set<T> IntersectionPath(Node<T>* root1, Node<T>* root2)
    {
        Set<T> result = Set<T>();
        ArraySequence<Node<T>*> s1, s2;

        while (true)
        {
            if (root1)
            {
                s1.append(root1);
                root1 = root1->left;
            }

            else if (root2)
            {
                s2.append(root2);
                root2 = root2->left;
            }

            else if (s1.getSize() > 0 && s2.getSize() > 0)
            {
                root1 = s1.GetLast();
                root2 = s2.GetLast();

                if (root1->key == root2->key)
                {
                    result.Append(root1->key);
                    s1.PopLast();
                    s2.PopLast();

                    root1 = root1->right;
                    root2 = root2->right;
                }

                else if (root1->key < root2->key)
                {

                    s1.PopLast();
                    root1 = root1->right;

                    root2 = NULL;
                }
                else if (root1->key > root2->key)
                {
                    s2.PopLast();
                    root2 = root2->right;
                    root1 = NULL;
                }
            }
            else  break;
        }
        return result;
    }

    Set<T> SubstractionPath(Node<T>* root1, Node<T>* root2, Set<T> set)
    {
        Set<T> result = Set<T>(set);
        ArraySequence<Node<T>*> s1, s2;

        while (true)
        {
            if (root1)
            {
                s1.append(root1);
                root1 = root1->left;
            }

            else if (root2)
            {
                s2.append(root2);
                root2 = root2->left;
            }

            else if (s1.getSize() > 0 && s2.getSize() > 0)
            {
                root1 = s1.GetLast();
                root2 = s2.GetLast();

                if (root1->key == root2->key)
                {
                    result.Delete(root1->key);
                    s1.PopLast();
                    s2.PopLast();

                    root1 = root1->right;
                    root2 = root2->right;
                }

                else if (root1->key < root2->key)
                {

                    s1.PopLast();
                    root1 = root1->right;
                    root2 = NULL;
                }
                else if (root1->key > root2->key)
                {
                    s2.PopLast();
                    root2 = root2->right;
                    root1 = NULL;
                }
            }

            else  break;
        }
        return result;
    }

    bool SubSetPath(Node<T>* root1, Node<T>* root2, Set<T> set)
    {
        Set<T> result = Set<T>();
        ArraySequence<Node<T>*> s1, s2;
        while (true)
        {
            if (root1)
            {
                s1.append(root1);
                root1 = root1->left;
            }
            else if (root2)
            {
                s2.append(root2);
                root2 = root2->left;
            }
            else if (s1.getSize() > 0 && s2.getSize() > 0)
            {
                root1 = s1.GetLast();
                root2 = s2.GetLast();

                if (root1->key == root2->key)
                {
                    result.Append(root1->key);
                    s1.PopLast();
                    s2.PopLast();
                    root1 = root1->right;
                    root2 = root2->right;
                }

                else if (root1->key < root2->key)
                {
                    s1.PopLast();
                    root1 = root1->right;
                    root2 = NULL;
                }
                else if (root1->key > root2->key)
                {
                    s2.PopLast();
                    root2 = root2->right;
                    root1 = NULL;
                }
            }
            else  break;
        }
        return set.IsEqual(result);
    }

    bool IsEqualNode(Node<T>* node1, Node<T>* node2) {
        if (node1 && node2) {
            if (node1->key == node2->key) {
                bool result = IsEqualNode(node1->left, node2->left) && IsEqualNode(node1->right, node2->right);
                return result;
            }
            else {
                return false;
            }
        }
        if (!node1 && !node2) {
            return true;
        }
        return false;
    }
    void DisplayNode(Node<T>* node) {
        if (node) {
            DisplayNode(node->left);
            cout << node->key ;
            if(node->right)
                cout << " , ";
            DisplayNode(node->right);
        }
    }
    void DisplayNode(Node<T>* node, bool isList) {
        if (node) {
            if (!isList) {
                DisplayNode(node->left);
                cout << node->key << "  ,  ";
                DisplayNode(node->right);
            }
            else {
                DisplayNode(node->left, isList);
                cout << node->key << "\n";
                DisplayNode(node->right, isList);
            }
        }
    }
public:
    Set() = default;
    Set(initializer_list<T> items) {
        for (T item : items) {
            this->Append(item);
        }
    }
    Set(const Set& set) : Tree<T>(set) {

    }
    explicit Set(const Node<T>& node) : Tree<T>(node) {

    }

    void Add(T value) {
        this->Append(value);
    }

    void Delete(T value) {
        this->Remove(value);
    }
    bool Contains(T value) {
        return this->Search(value);
    }
    Set<T> MapSet(T(*mapper)(T)) {
        if (mapper == nullptr)
            throw std::invalid_argument("mapper is NULL");
        Set<T> newSet = Set<T>(*this);
        newSet.mapping(mapper, newSet.root);
        return newSet;
    }
    Set<T> WhereSet(bool(*predicate)(T)) {
        if (predicate == nullptr)
            throw std::invalid_argument("predicate is NULL");
        Set<T> newSet = Set<T>();
        newSet.pathwhere(predicate, this->root, &newSet);
        return newSet;
    }
    T ReduceSet(T(*reducer)(T, T), T const& c) {
        if (reducer == nullptr)
            throw std::invalid_argument("reducer is NULL");
        T res = ReducePath(reducer, c, this->root);
        return res;
    }
    Set<T> Intersection(Set<T> set) {
        return IntersectionPath(set.root, this->root);
    }

    Set<T> Union(Set<T> set) {
        Set<T> result = Set<T>(*this);
        UnionPath(set.root, &result);
        return result;
    }
    Set<T> Substraction(Set<T> set) {
        return SubstractionPath(set.root, this->root, *this);
    }

    bool IsEqual(Set<T> set) {
        return IsEqualNode(set.root, this->root);
    }

    bool IsSubSet(Set<T> set) {
        return SubSetPath(set.root, this->root, set);
    }

    bool operator==(Set<T> set) {
        return IsEqual(set);
    }
    Set<T> operator&(Set<T> set) {
        return Intersection(set);
    }
    Set<T> operator|(Set<T> set) {
        return Union(set);
    }
    Set<T> operator-(Set<T> set) {
        return Substraction(set);
    }
    void Display() {
        
        cout << "(";
        if (this->root) DisplayNode(this->root);
        cout << ")\n";
    }
    void Display(bool isList) {
        cout << "(\n";
        if (this->root) DisplayNode(this->root, isList);
        cout << ")\n";
    }
};

#endif //LABA3_SET_H