#ifndef LABA3_BINARYTREE_H
#define LABA3_BINARYTREE_H

#include <exception>
#include <iostream>

template<class T>
class Node {
public:
    Node() : key(), height() {}
    Node(const Node& node) {
        if (&node == nullptr)
            throw std::range_error("Node cant be created from null");
        key = node.key;
        height = node.height;
        if (node.left) left = new Node(*node.left);
        if (node.right) right = new Node(*node.right);
    }
    explicit Node(Node* node) {
        if (node) {
            key = node->key;
            height = node->height;
            left = new Node(*(node->left));
            right = new Node(*(node->right));
        }
    }

    explicit Node(T key) {
       this->key = key;
       height = 1;
    }

    T key;
    int height = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};

template<class T>
class Tree {
protected:

private:
    void DestroyNode(Node<T>* node) {
        if (node) {
            if (node->left) DestroyNode(node->left);
            if (node->right) DestroyNode(node->right);
            delete node;
        }
    }

    int height(Node<T>* N)
    {
        if (N == nullptr)
            return 0;
        return N->height;
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    Node<T>* RightRotate(Node<T>* y)
    {
        Node<T>* x = y->left;
        Node<T>* temp2 = x->right;
        // Вращение
        x->right = y;
        y->left =temp2;
        // Обновление глубины
        y->height = max(height(y->left),height(y->right)) + 1;
        x->height = max(height(x->left),height(x->right)) + 1;
        return x;
    }
    Node<T>* LeftRotate(Node<T>* x)
    {
        Node<T>* y = x->right;
        Node<T>*temp2 = y->left;
        // Вращение
        y->left = x;
        x->right =temp2;
        // Обновление глубины
        x->height = max(height(x->left),height(x->right)) + 1;
        y->height = max(height(y->left),height(y->right)) + 1;
        return y;
    }
    int GetBalance(Node<T>* N)
    {
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }

    Node<T>* FindMin(Node<T>* node)
    {
        while (node->left != nullptr) 
            node = node->left;
        return node;
    }
public:
    Node<T>* root;

    void mapping(T(*mapper)(T), Node<T>* node) {
        if (mapper == nullptr)
            throw std::invalid_argument("mapper is nullptr");
        node->key = mapper(node->key);
        if (node->left) 
            mapping(mapper, node->left);
        if (node->right) 
            mapping(mapper, node->right);
    }

    void pathwhere(bool(*predicate)(T), Node<T>* node, Tree<T>* tree) {
        if (predicate == nullptr)
            throw std::invalid_argument("predicate is nullptr");
        if (predicate(node->key))
            tree->Append(node->key);
        if (node->left) 
            pathwhere(predicate, node->left, tree);
        if (node->right) 
            pathwhere(predicate, node->right, tree);
    }

    T ReducePath(T(*reducer)(T, T), T const& c, Node<T>* node) {
        if (node) {
            T res = reducer(node->key, c);
            res = ReducePath(reducer, res, node->left);
            res = ReducePath(reducer, res, node->right);
            return res;
        }
        return c;
    }
public:
    Tree() {
        root = nullptr;
    }



    Tree(std::initializer_list<T> items) :Tree() {
        for (T item : items) {
            Append(item);
        }
    }
    
   explicit Tree(const Node<T>& root) {
        this->root = new Node<T>(root);
    }
  
    Tree(const Tree& tree) : Tree() {
        if (tree.root != nullptr) root = new Node<T>(*tree.root);
    }

    ~Tree() {
        DestroyNode(root);
    }

    void Append(T key) {
        if (&key == nullptr) {
            throw std::range_error("You cant append nullptr");
        }
        root = Insert(root, key);
    }

    Node<T>* Insert(Node<T>* node, T& key)
    {
        if (node == nullptr)
        {
            Node<T>* res = new Node<T>(key);
            return(res);
        }
        if (key < node->key)
            node->left = Insert(node->left, key);
        else if (key > node->key)
            node->right = Insert(node->right, key);
        else 
            return node;
        node->height = 1 + max(height(node->left),
            height(node->right));
        int balance = GetBalance(node);
        if (balance > 1 && key < node->left->key)
            return RightRotate(node);

        if (balance < -1 && key > node->right->key)
            return LeftRotate(node);
        if (balance > 1 && key > node->left->key)
        {
            node->left = LeftRotate(node->left);
            return RightRotate(node);
        }

        if (balance < -1 && key < node->right->key)
        {
            node->right = RightRotate(node->right);
            return LeftRotate(node);
        }
        return node;
    }
    Node<T>* Remove(T key) {
        if (&key == nullptr) {
            throw std::range_error("You cant remove nullptr");
        }
        return Delete(root, key);
    }
    Node<T>* Delete(Node<T>* node, T key) {
        if (node == nullptr) return node;
        else if (key < node->key) 
            node->left = Delete(node->left, key);
        else if (key > node->key) 
            node->right = Delete(node->right, key);
        else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            }
            else if (node->left == nullptr) {
                Node<T>* temp = node;
                node = node->right;
                delete temp;
            }
            else if (node->right == nullptr) {
                Node<T>* temp = node;
                node = node->left;
                delete temp;
            }
            else {
                Node<T>* temp = FindMin(node->right);
                node->key = temp->key;
                node->right = Delete(node->right, temp->key);
            }
        }
        return node;
    }

    bool Search(T key) {
        Node<T>** current = &root;
        while (*current) {
            Node<T>& node = **current;
            if (key < node.key) {
                current = &node.left;
            }
            else {
                if (key > node.key) {
                    current = &node.right;
                }
                else {
                    return (*current)->key == key;
                }
            }
        }
        return false;
    }

    Node<T>* SearchNode(T key) {
        Node<T>** current = &root;
        while (*current) {
            Node<T>& node = **current;
            if (key < node.key) {
                current = &node.left;
            }
            else {
                if (key > node.key) {
                    current = &node.right;
                }
                else {
                    return (*current);
                }
            }
        }
        return nullptr;
    }

    Tree<T> SubTree(T key) {
        Node<T>** current = &root;
        while (*current) {
            Node<T>& node = **current;
            if (key < node.key) {
                current = &node.left;
            }
            else {
                if (key > node.key) {
                    current = &node.right;
                }
                else {
                    return Tree(**current);
                }
            }
        }
        return Tree();
    }





    bool SearchSubTree(const Tree& tree) {
        if (&tree == nullptr || tree.root == nullptr) return false;
        Node<T>** current = &root;
        T key = tree.root->key;
        while (*current) {
            Node<T>& node = **current;
            if (key < node.key) {
                current = &node.left;
            }
            else {
                if (key > node.key) {
                    current = &node.right;
                }
                else {
                    bool a1 = false;
                    if ((*current)->right != nullptr && tree.root->right != nullptr)
                        a1 = tree.root->right->key == (*current)->right->key;
                    else if ((*current)->right == nullptr && tree.root->right == nullptr)
                        a1 = true;

                    bool a2 = false;
                    if ((*current)->left != nullptr && tree.root->left != nullptr)
                        a2 = tree.root->left->key == (*current)->left->key;
                    else if ((*current)->left == nullptr && tree.root->left == nullptr)
                        a2 = true;

                    bool result = key == (*current)->key && a1 && a2;

                    return result;
                }
            }
        }
        return false;
    }

    Tree<T> Map(T(*mapper)(T)) {
        if (mapper == nullptr)
            throw std::invalid_argument("mapper is nullptr");
        Tree<T> newTree = Tree<T>(*this);
        mapping(mapper, newTree.root);
        return newTree;
    }
    Tree<T> Where(bool(*predicate)(T)) {
        if (predicate == nullptr)
            throw std::invalid_argument("predicate is nullptr");
        Tree<T> newTree = Tree<T>();
        pathwhere(predicate, this->root, &newTree);
        return newTree;
    }
    T Reduce(T(*reducer)(T, T), T const& c) {
        if (reducer == nullptr)
            throw std::invalid_argument("reducer is nullptr");
        T res = ReducePath(reducer, c, root);
        return res;
    }

    void PreOrder(Node<T>* node, int ctr)
    {
        if (node != nullptr)
        {
            std::string brackets[] = { "{", "}", "(", ")", "[", "]" };
            std::cout << brackets[ctr] << node->key << " ";
            PreOrder(node->left, (ctr + 2) % 6);
            PreOrder(node->right, (ctr + 4) % 6);
            std::cout << brackets[ctr + 1];
        }
    }
    void Output() {
        PreOrder(root, 0);
        std::cout << "\n";
    }
    void UnionPath(Node<T>* node, Tree<T>* set) {
        if (node) {
            set->Append(node->key);
            UnionPath(node->left, set);
            UnionPath(node->right, set);
        }
    }
    Tree<T> Union(Tree<T> set) {
        Tree<T> result = Tree<T>(*this);
        UnionPath(set.root, &result);
        return result;
    }
    Tree<T> operator|(Tree<T> set) {
        return Union(set);
    }

    template<typename T>
    void printInorder(Node<T>* node, size_t space)
    {
        if (node != 0)
        {
            space += 10;
            printInorder(node->right, space);


            std::cout << std::endl;
            for (size_t i = 10; i < space + 1; i++) {
                std::cout << " ";
            }
            std::cout << node->key << std::endl;

            printInorder(node->left, space);

        }
    }

};

#endif LABA3_BINARYTREE_H
