#include <iostream>
#include "PrintFunctions.h"
#include "./DataStructures/LinkedList.h"
#include "./DataStructures/DynamicArray.h"
#include "./DataStructures/ArraySequence.h"
#include "./DataStructures/ListSequence.h"
#include "./tests/DynamicArray_tests.h"
#include "./tests/LinkedList_tests.h"
#include "./tests/ArraySequence_tests.h"
#include "./tests/ImmutableArraySequence_tests.h"
#include "./tests/listSequence_tests.h"

// Array
void testArray();
void arrayManualCreation();
void arrayGetElement();
void arrayInsertElement();
void arrayGetSubArray();
void arrayConcatenate();
template <class T>
ds::ArraySequence<T> createArrayManually(T createElement());
ds::ArraySequence<int> createRandomIntegerArray();
void testIntegerArrayManualCreation();
void testFloatArrayManualCreation();

// Utility
int createInteger();
float createFloat();
void printFloat(float);
void printInteger(int);
void runTests();
int createRandomIntNumber(int maxNumber);

int getIntegerInRange(int min, int max)
{
    while (true)
    {
        int number;
        std::cin >> number;
        if (number <= max && number >= min)
        {
            return number;
        }
        cout << "Number out of range" << endl;
    }
}

void menu()
{
    int manageNumber;
    while (true)
    {
        printMainMenu();
        manageNumber = getIntegerInRange(1, 4);
        switch (manageNumber)
        {
        case 1:
            testArray();
            break;
        // case 2:
        //     cout << "I'm sorry, the interface for testing the listSequence is non-existent. The structure itself is fully functional though." << endl;
        //     break;
        case 2:
            runTests();
            break;
        case 3:
            return;
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
    // testImmutableArraySequence();
    testListSequence();
}

void testArray()
{
    int manageNumber;
    printOperationChoice();
    manageNumber = getIntegerInRange(1, 5);
    switch (manageNumber)
    {
    case 1:
        arrayManualCreation();
        break;
    case 2:
        arrayGetElement();
        break;
    case 3:
        arrayInsertElement();
        break;
    case 4:
        arrayGetSubArray();
        break;
    case 5:
        arrayConcatenate();
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
        testIntegerArrayManualCreation();
        break;
    case 2:
        testFloatArrayManualCreation();
        break;
    default:
        return;
    }
}

void testFloatArrayManualCreation()
{
    ds::ArraySequence<float> arr = createArrayManually(createFloat);
    printArray<float>(&arr, printFloat);
}
void testIntegerArrayManualCreation()
{
    ds::ArraySequence<int> arr = createArrayManually(createInteger);
    printArray<int>(&arr, printInteger);
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

void printFloat(float number)
{
    cout << number << endl;
}

void arrayConcatenate()
{
    ds::ArraySequence<int> arr = createRandomIntegerArray();
    cout << "Here's an array of 10 random integers: " << endl;
    printArray(&arr, printInteger);
    cout << "Let's create a new integer array to concatenate it to that array" << endl;

    ds::ArraySequence<int> arr2 = createArrayManually(createInteger);
    arr.concat(arr2);
    cout << "The concatenated array is: " << endl;
    printArray(&arr, printInteger);
}

void arrayGetSubArray()
{
    ds::ArraySequence<int> arr = createRandomIntegerArray();
    cout << "Here's an array of 10 random integers: " << endl;
    printArray(&arr, printInteger);
    int startIndex, endIndex;
    while (true)
    {
        cout << "Pick the start index of the subarray:" << endl;
        cin >> startIndex;
        cout << "Pick the end index of the subarray:" << endl;
        cin >> endIndex;
        if (startIndex < endIndex && endIndex >= 0 && endIndex < 10 && startIndex >= 0 && startIndex < 10)
        {
            break;
        }
        cout << "Invalid indexes provided! Try again. " << endl;
    }
    ds::ArraySequence<int> *subArr = arr.getSubsequence(startIndex, endIndex);
    cout << "The subarray is: " << endl;
    printArray(subArr, printInteger);
    delete subArr;
}

void arrayInsertElement()
{
    ds::ArraySequence<int> arr = createRandomIntegerArray();
    cout << "Here's an array of 10 random integers: " << endl;
    printArray(&arr, printInteger);
    int index, element;
    cout << "Pick an index to insert a new element in:" << endl;
    cin >> index;
    cout << "Input the new element " << endl;
    cin >> element;
    arr.insertAt(element, index);
    cout << "Array after insertion: " << endl;
    printArray(&arr, printInteger);
}

void arrayGetElement()
{
    ds::ArraySequence<int> arr = createRandomIntegerArray();
    cout << "Here's an array of 10 random integers: " << endl;
    printArray(&arr, printInteger);
    int index;
    cout << "Pick an index to get the element of the array" << endl;
    cin >> index;
    cout << "The element is: " << arr.get(index) << endl;
}

ds::ArraySequence<int> createRandomIntegerArray()
{
    int length = 10;
    ds::ArraySequence<int> newArray = ds::ArraySequence<int>();
    for (int i = 0; i < length; i++)
    {
        newArray.append(createRandomIntNumber(100));
    }
    return newArray;
};

int createRandomIntNumber(int maxNumber)
{
    return rand() % maxNumber;
}