#include "TreeTest.h"
#include "BinaryTree.h"
using namespace std;
int MapCheck(int a) {
    return a % 3;
}
string MapCheckString(string a) {
    return a + " hello";
}
bool IsEven(int a) {
    return a % 2 == 0;
}
int ReduceCheck(int a, int b) {
    return a + b;
}

void InitTest() {
    Tree<int> tree = Tree<int>();

    tree.Append(0);
    tree.Append(1);
    tree.Append(2);
    tree.Append(3);
    tree.Append(4);

    Tree<int> tree1 = Tree<int>({ 0, 1, 2, 3, 4 });
    if(tree.SearchSubTree(tree1))
        cout << "InitTest completed" << endl;
    else
        cout << "InitTest failed" << endl;
}

void SearchAppendTest() {
    Tree<int> tree = Tree<int>();
    tree.Append(1);
    tree.Append(2);
    tree.Append(2);
    if(tree.Search(1))
        cout << "SearchAppendTest completed" << endl;
    else
        cout << "SearchAppendTest failed" << endl;
}

void RemoveTest() {
    Tree<int> tree = Tree<int>();
    tree.Append(1);
    tree.Append(2);
    tree.Append(3);
    tree.Append(4);
    tree.Append(5);
    tree.Remove(3);
    if(tree.Search(1))
        cout << "RemoveTest completed" << endl;
    else
        cout << "RemoveTest failed" << endl;
 
    if(tree.Search(3))
        cout << "RemoveTest completed" << endl;
    else
        cout << "RemoveTest failed" << endl;
}

void SubTreeTest() {
    Tree<int> tree = Tree<int>({ 0, 1, 2, 3, 4 });
    Tree<int> tree1 = Tree<int>({ 0, 1, 2, 3, 4 });
    if(tree.SearchSubTree(tree1))
        cout << "SubTreeTest completed" << endl;
    else
        cout << "SubTreeTest failed" << endl;

    Tree<string> tree2 = Tree<string>({ "apple", "", "banana", "aboba", "1" });
    Tree<string> tree3 = Tree<string>({ "apple", "", "banana", "aboba", "1" });
    if(tree2.SearchSubTree(tree3))
        cout << "SubTreeTest completed" << endl;
    else
        cout << "SubTreeTest failed" << endl;


}

void MapTreeTest() {
    Tree<int> tree = Tree<int>({ 0, 1, 2, 3, 4 });
    Tree<int> treeMap = tree.Map(MapCheck);
    if(treeMap.SearchSubTree(Tree<int>({ 0, 4, 8, 12, 16 })))
        cout << "MapTreeTest completed" << endl;
    else
        cout << "MapTreeTest failed" << endl;

    Tree<string> treeString = Tree<string>({ "", "hi", "good", "hello", "110" });
    Tree<string> treeMapString = treeString.Map(MapCheckString);
    if(treeMapString.SearchSubTree(Tree<string>({ " hello", "hi hello", "good hello", "hello hello", "110 hello" })))
        cout << "MapTreeTest completed" << endl;
    else
        cout << "MapTreeTest failed" << endl;
}

void WhereTreeTest() {
    Tree<int> tree = Tree<int>({ 0, 1, 2, 3, 4 });
    Tree<int> treeMap = tree.Where(IsEven);
    if(treeMap.SearchSubTree(Tree<int>({ 0, 2, 4 })))
        cout << "WhereTreeTest completed" << endl;
    else
        cout << "WhereTreeTest failed" << endl;
}
void ReduceTest()
{


    Tree<int> tree = Tree<int>({ 0, 1, 2, 3, 4 });
    if(tree.Reduce(ReduceCheck, 0)==10)
        cout << "ReduceTreeTest completed" << endl;
    else
        cout << "ReduceTreeTest failed" << endl;
}