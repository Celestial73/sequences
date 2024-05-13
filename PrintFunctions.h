#include <iostream>
#include "./DataStructures/ArraySequence.h"
#include "./DataStructures/ListSequence.h"

using namespace std;

template <typename T>
void printArray(ds::ArraySequence<T> *array, void print(T))
{
    cout << "Array consists of " << array->getSize() << " numbers\n";
    for (int i = 0; i < array->getSize(); i++)
        print(array->get(i));
    cout << std::endl;
};

void printIntegerArray(ds::ArraySequence<int> *array)
{
    cout << "Array holds " << array->getSize() << " integers\n";
    int size = array->getSize();
    for (int i = 0; i < array->getSize(); i++)
    {
        cout << array->get(i) << std::endl;
    }
    cout << std::endl;
}

void printTypes()
{
    cout << "Choose the type" << endl;
    cout << "Enter 1 - Int" << endl;
    cout << "Enter 2 - float" << endl;
};

void printOperationChoice()
{
    cout << "What do you want to test?" << endl;

    cout << "Enter 1 - Manual creation" << endl;
    cout << "Enter 2 - Getting an element" << endl;
    cout << "Enter 3 - Inserting an element" << endl;
    cout << "Enter 4 - Getting a subsequence" << endl;
    cout << "Enter 5 - Concatenation" << endl;
};

void printManuallyQuestion()
{
    cout << "Do you want to create the structure manu" << endl;
    cout << "Enter 1 - Int" << endl;
    cout << "Enter 2 - float" << endl;
};

void printMainMenu()
{
    cout << "Enter 1 - To test an ArraySequence" << endl;
    // cout << "Enter 3 - To test a ListSequence (not available)" << endl;
    cout << "Enter 2 - To run tests" << endl;
    cout << "Enter 3 - To Cancel" << endl;
};