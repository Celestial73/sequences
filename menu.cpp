#include <iostream>
#include "PrintFunctions.h"
#include "./DataStructures/LinkedList.h"
#include "./DataStructures/DynamicArray.h"
#include "./DataStructures/ArraySequence.h"
#include "./DataStructures/ListSequence.h"
#include "./tests/DynamicArray_tests.h"
#include "./tests/LinkedList_tests.h"
#include "./tests/ArraySequence_tests.h"
#include "./tests/listSequence_tests.h"
#include "menu.h"

int getIntegerInRange(int max, int min)
{
    while (true)
    {
        int number;
        std::cin >> number;
        if (number <= max && number >= min)
        {
            return number;
        }
    }
}

void menu()
{
    int manageNumber;
    while (true)
    {
        printMainMenu();
        manageNumber = getIntegerInRange(1, 3);
        switch (manageNumber)
        {
        case 1:
            testArray();
            break;
        case 2:
            break;
        case 3:
            break;

        default:
            return;
        }
    }
}

void runTests()
{
    testLinkedList();
    testDynamicArray();
    testArraySequence();
    testListSequence();
}

void chooseTestSubject()
{
}

void testArray()
{
    cout << "What do you want to test?" << endl;
    int manageNumber;
    printOperationChoice();
    manageNumber = getIntegerInRange(1, 5);
    switch (manageNumber)
    {
    case 1:
        arrayManualCreation();
    case 2:

        break;
    default:
        return;
    }
}

void arrayManualCreation()
{
    int manageNumber;
    printTypes();
    manageNumber = getIntegerInRange(1, 2);
    switch (manageNumber)
    {
    case 1:

    case 2:
        // ds::ArraySequence<float> arr = createArrayManually(createFloat);
        break;
    default:
        return;
    }
}

void testIntegerArrayManualCreation()
{
    ds::ArraySequence<int> arr = createArrayManually(createInteger);
    printIntegerArray(&arr);
}

template <class T>
ds::ArraySequence<T> createArrayManually(T createElement())
{
    int length = 0;
    cout << "Enter the length (<100)" << endl;
    length = getIntegerInRange(0, 99);
    ds::ArraySequence<T> newArray = ds::ArraySequence<T>();
    for (int i = 0; i < length; i++)
    {
        cout << "[" << i << "] element =" << endl;
        newArray.append(createElement());
    }
    return newArray;
};

int createInteger()
{
    int number;
    std::cin >> number;
    return number;
}

void printInteger(int number)
{
    cout << number << endl;
}

float createFloat()
{
    float number;
    std::cin >> number;
    return number;
}