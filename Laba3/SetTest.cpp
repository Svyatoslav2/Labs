//
// Created by lokt0 on 23.05.2021.
//

#include "Assign.h"
#include "BinaryTree.h"
#include "SetTest.h"
#include <iostream>
#include <string>


using namespace std;

int MapCheck1(int a) {
    return a / 3;
}
string MapCheckString1(string a) {
    return a + " aboba";
}
bool IsEven1(int a) {
    return a % 2 == 0;
}
int ReduceCheck1(int a, int b) {
    return a + b;
}

void initTest() {
    Set<int> set = Set<int>();
    set.Add(0);
    set.Add(1);
    set.Add(2);
    set.Add(3);
    set.Add(4);

    Set<int> set1 = Set<int>({ 0, 1, 2, 3, 4 });
    if (set.IsSubSet(set1))
        cout << "InitTest completed" << endl;
    else
        cout << "InitTest failed" << endl;
}

void deleteTest() {
    Set<int> set = Set<int>();
    set.Add(0);
    set.Add(1);
    set.Add(2);
    set.Add(3);
    set.Delete(0);
    set.Delete(2);
    set.Display();

    Set<int> set1 = Set<int>({ 1, 3});
    if (set.IsSubSet(set1))
        cout << "DeleteTest completed" << endl;
    else
        cout << "DeleteTest failed" << endl;
}

void SubSetTest() {
    Set<int> set = Set<int>({ 2, 4 });
    Set<int> set1 = Set<int>({ 0, 1, 2, 3, 4 });
    if (set1.IsSubSet(set))
        cout << "SubSetTest completed" << endl;
    else
        cout << "SubSetTest failed" << endl;


  
}


void MapTest() {
    Set<int> set = Set<int>({ 4, 3, 2, 1 });
    Set<int> mapSet = Set<int>(set.MapSet(MapCheck1));
    mapSet.Display();
    if (mapSet.IsEqual(Set<int>({ -12, -9, -6, 0 })))
        cout << "MapTest completed" << endl;
    else
        cout << "MapTest failed" << endl;

    Set<string> setString = Set<string>({ "", "0" });
    Set<string> mapSetString = setString.MapSet(MapCheckString1);
    mapSetString.Display();
    if(mapSetString.IsEqual(Set<string>({ " aboba", "0 aboba" })))
        cout << "MapTest completed" << endl;
    else
        cout << "MapTest failed" << endl;

}

void  WhereTest() {
    Set<int> set = Set<int>({ -4, -3, -2, 0 });
    Set<int> mapSet = set.WhereSet(IsEven1);
    mapSet.Display();
    if(mapSet.IsEqual(Set<int>({ -4, -2, 0 })))
        cout << "WhereTest completed" << endl;
    else
        cout << "WhereTest failed" << endl;
}


void Inersection() {
    Set<int> set = Set<int>({ 1, 2, 3, 4, 5 });
    Set<int> set1 = Set<int>({ 4, 5, 6, 7, 8 });
    Set<int> intersection = set & set1;
    if(intersection.IsSubSet(Set<int>({ 4, 5 })))
        cout << "intersectionTest completed" << endl;
    else
        cout << "intersectionTest failed" << endl;
}

void  UnionTest() {
    Set<int> set = Set<int>({ 1, 2, 3, 4, 5 });
    Set<int> set1 = Set<int>({ 4, 5, 6, 7, 8 });
    Set<int> uni = set | set1;
    if(uni.IsSubSet(Set<int>({ 1, 2, 3, 4, 5, 6, 7, 8 })))
        cout << "UnionTest completed" << endl;
    else
        cout << "UnionTest failed" << endl;
}

void SubstractionTest() {
    Set<int> set = Set<int>({ 1, 2, 3, 4, 5 });
    Set<int> set1 = Set<int>({ 4, 5, 6, 7, 8 });
    Set<int> sub = set - set1;
    if(sub.IsSubSet(Set<int>({ 1, 2, 3 })))
        cout << "SubstractionTest completed" << endl;
    else
        cout << "SubstractionTest failed" << endl;
}

void EqualTest() {
    Set<int> set = Set<int>({ 1, 2, 3, 4, 5 });
    Set<int> set1 = Set<int>(set);
    if(set1 == set)
        cout << "EqualTest completed" << endl;
    else
        cout << "EqualTest failed" << endl;
}
