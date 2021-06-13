#include <iostream>
#include "Person.h"
#include "BinaryTree.h"
#include "Assign.h"
#include "SetTest.h"
#include "TreeTest.h"
using namespace std;

void AutoTest();
const char* Message[] = { "0. Quit",
                      "1. Add value",
                      "2. Remove value",
                      "3. Print",
                      "4. Print like list",
                      "5. Union",
                      "6. Intersection",
                      "7. IsSequel",
                      "8. Subset",
                      "9. Search",
                      "10.Substraction"};

const char* Message1[] = { "0. Quit",
                      "1. Int",
                      "2. Double",
                      "3. Float",
                      "4. People",
                      "5. String",
                      "6. AutoTest"};

const char* Message2[] = { "0. Quit",
                      "1. Tree",
                      "2. Set" };

const char* Message3[] = { "0. Quit",
                      "1. Add value",
                      "2. Remove value",
                      "3. Print",
                      "4. Print as string",
                      "5. Subset",
                      "6. Search",
                      "7. Union",
                      "8.Extract Tree"
                        };

template<int N>
int Dialog(const char* (&msgs)[N]) {
    string error;
    int choice = -1;
    do {
        cout << error;
        error = "You're wrong. Try again!\n";
        for (int i = 0; i < N; ++i) {
            cout << msgs[i] << endl;
        }
        cout << "Make your choice: \n";
        cin >> choice;
    } while (choice < 0 || choice >= N);
    return choice;
}



template<typename T>
void StartUI() {
    int res = 1;
    string tmp;
    Set<T> set = Set<T>();
    while (res != 0) {
        res = Dialog(Message);
        switch (res) {
        case 0:
            break;
        case 1: {
            T value;
            cin >> value;
            set.Add(value);
        }
              break;
        case 2: {
            T value1;
            cin >> value1;
            set.Remove(value1);
        }
              break;
        case 3:
            set.Display();
            break;
        case 4:
            set.Display(true);
            break;
        case 5:
        {
            char ch = 0;

            Set<T> settemp = Set<T>();
            cout << "New set" << endl;
            while (ch != 'x')
            {
                T value;
                cin >> value;
                settemp.Add(value);
                cout << "Continue?";
                cin >> ch;
            }
            Set<T> uni = set | settemp;
            uni.Display();
        }break;
        case 6:
        {
            char ch = 0;

            Set<T> settemp = Set<T>();
            cout << "New set" << endl;
            while (ch != 'x')
            {
                T value;
                cin >> value;
                settemp.Add(value);
                cout << "Continue?";
                cin >> ch;
                set.Search(value);
            }

            Set<T> intersection = set & settemp;
            intersection.Display();
        }break;
        case 7:
        {
            char ch = 0;

            Set<T> settemp = Set<T>();
            cout << "New set" << endl;
            while (ch != 'x')
            {
                T value;
                cin >> value;
                settemp.Add(value);
                cout << "Continue?";
                cin >> ch;
                set.Search(value);
            }

            if (set == settemp)
            {
                cout << "Sets Equal" << endl;
            }
            else
                cout << "Sets different" << endl;
        }break;
        case 8:
        {
            char ch = 0;

            Set<T> settemp = Set<T>();
            cout << "New set" << endl;
            while (ch != 'x')
            {
                T value;
                cin >> value;
                settemp.Add(value);
                cout << "Continue?";
                cin >> ch;
                set.Search(value);
            }

            if (settemp.IsSubSet(set))
            {
                cout << "Sets include" << endl;
            }
            else
                cout << "Sets dont include" << endl;
        }break;
        case 9:
        {cout << "search element" << endl;
            T value;
            cin >> value;
            if (set.Contains(value))
                cout << "Elements include" << endl;
            else

                cout << "Elements doesnt include" << endl;
        } break;
        case 10:
        {
            char ch = 0;

            Set<T> settemp = Set<T>();
            cout << "New set" << endl;
            while (ch != 'x')
            {
                T value;
                cin >> value;
                settemp.Add(value);
                cout << "Continue?";
                cin >> ch;
                set.Search(value);
            }

            Set<T> subs = set - settemp;
            subs.Display();
        }break;
        default: {
            cout << "Wrong choice\n";
            break;
        }
        }
    }
}

template<typename T>
void StartUIT() {
    int res = 1;
    string tmp;
    Tree<T> tree = Tree<T>();
    while (res != 0) {
        res = Dialog(Message3);
        switch (res) {
        case 0:
            break;
        case 1: {
            T value;
            cin >> value;
            tree.Append(value);
        }
              break;
        case 2: {
            T value1;
            cin >> value1;
            tree.Remove(value1);
        }
              break;
        case 3:
            tree.printInorder(tree.root, 10);
            break;
        case 4:
            tree.Output();
            break;
        case 5:
        {
            char ch = 0;

            Tree<T> treet = Tree<T>();
            cout << "New set" << endl;
            while (ch != 'x')
            {
                T value;
                cin >> value;
                treet.Append(value);
                cout << "Continue?";
                cin >> ch;
            }

            if (tree.SearchSubTree(treet))
                cout << "SubTree included" << endl;
            else
                cout << "SubTree included" << endl;
        }break;
        case 6:
        {
        cout << "search element" << endl;
        T value;
        cin >> value;
        if (tree.Search(value))
            cout << "Elements include" << endl;
        else

            cout << "Elements doesnt include" << endl;
        } break;
        case 7:
        {
            char ch = 0;

            Tree<T> settemp = Tree<T>();
            cout << "New tree" << endl;
            while (ch != 'x')
            {
                T value;
                cin >> value;
                settemp.Append(value);
                cout << "Continue?";
                cin >> ch;
            }
            Tree<T> uni = tree | settemp;
            uni.printInorder(uni.root, 10);;
        }break;
        case 8:
        {
            T value1;
            cin >> value1;
            Tree<T> treetemp =Tree<T> (tree.SubTree(value1));
            
            treetemp.printInorder(treetemp.root, 10);;
        }break;
        default: {
            cout << "Wrong choice\n";
            break;
        }

        }
    }
}


int main() {
    int res = 1;
    cout << "Choose set or tree:" << endl;
    res = Dialog(Message2);
    switch (res) {
    case(1): {
            cout << "Enter data type:" << endl;
            int rest = 1;
            rest = Dialog(Message1);
            switch (rest) {
            case 0:
                break;
            case 1:
                StartUIT<int>();
                break;
            case 2:
                StartUIT<double>();
                break;
            case 3:
                StartUIT<float>();
                break;
            case 4:
                StartUIT<Person>();
                break;
            case 5:
                StartUIT<std::string>();
                break;
            case 6:
                AutoTest();
                break;
            default: {
                cout << "Wrong choice\n";
                break;
            }
            }
            break;
        }
    case(2): {
        cout << "Enter data type:" << endl;
        int rest = 1;
        rest = Dialog(Message1);
        switch (rest) {
        case 0:
            break;
        case 1:
            StartUI<int>();
            break;
        case 2:
            StartUI<double>();
            break;
        case 3:
            StartUI<float>();
            break;
        case 4:
            StartUI<Person>();
            break;
        case 5:
            StartUI<std::string>();
            break;
        case 6:
            AutoTest();
            break;
        default: {
            cout << "Wrong choice\n";
            break;
        }
        }
        break;
    }
    }
    return 0;
}

void AutoTest()
{
    cout << "=====================" << endl;
    cout << "======SET TESTS======" << endl;
    initTest();
    deleteTest();
    SubSetTest();
    UnionTest();
    SubstractionTest();
    Inersection();
    EqualTest();
    WhereTest();
    MapTest();
    cout << "======TREE TESTS======" << endl;
    InitTest();
    SearchAppendTest();
    RemoveTest();
    SubTreeTest();
    MapTreeTest();
    WhereTreeTest();
    ReduceTest();
}
