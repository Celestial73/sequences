#include "DynamicArray_tests.h"

void testItemsConstructor()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::DynamicArray<int> arr(items, 5);
    IS_TRUE(arr.getSize() == 5);
    for (size_t i = 0; i < arr.getSize(); ++i)
    {
        IS_TRUE(arr[i] == items[i]);
    }
    std::cout << "DynamicArray itemsConstructor test passed" << std::endl;
}

void testCopyDynamicArray()
{
    ds::DynamicArray<int> arr1(5);
    ds::DynamicArray<int> arr2(arr1);
    for (size_t i = 0; i != arr1.getSize(); ++i)
    {
        IS_TRUE(arr1[i] == arr2[i]);
    }
    std::cout << "DynamicArray copy test passed" << std::endl;
}

void testArrayEquals()
{
    ds::DynamicArray<int> arr1(5);
    ds::DynamicArray<int> arr2(arr1);
    IS_TRUE(arr1 == arr2);
    arr2.resize(arr2.getSize() + 1);
    arr2[arr2.getSize() - 1] = 5;
    IS_TRUE(!(arr1 == arr2));
    std::cout << "DynamicArray equals test passed" << std::endl;
}

void testArrayGet()
{
    bool exceptionCaught = false;
    ds::DynamicArray<int> arr1(5);
    int a;
    try
    {
        a = arr1.get(10);
    }
    catch (const std::exception &e)
    {
        exceptionCaught = true;
    }
    IS_TRUE(exceptionCaught);
    if (exceptionCaught)
    {
        std::cout << "As it should have" << std::endl;
    }
    arr1.set(0, 2);
    a = arr1.get(2);
    IS_TRUE(a == 0);
    std::cout << "DynamicArray get test passed" << std::endl;
}

void testArrayAssignmentOperator()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::DynamicArray<int> arr1(items, 5);
    ds::DynamicArray<int> arr2 = arr1;
    IS_TRUE(arr1 == arr2);
    std::cout << "LinkedList assignment operator test passed" << std::endl;
}

void testArrayBrackets()
{
    bool exceptionCaught = false;
    ds::DynamicArray<int> arr1(5);
    int a;
    try
    {
        a = arr1[10];
    }
    catch (const std::exception &e)
    {
        exceptionCaught = true;
    }
    IS_TRUE(exceptionCaught);
    if (exceptionCaught)
    {
        std::cout << "As it should have" << std::endl;
    }
    arr1.set(0, 2);
    a = arr1[2];
    IS_TRUE(a == 0);
    std::cout << "DynamicArray brackets operator test passed" << std::endl;
}

void testArrayResize()
{
    ds::DynamicArray<int> arr1(5);
    arr1.resize(10);
    IS_TRUE(arr1.getSize() == 10);
    std::cout << "DynamicArray resize test passed" << std::endl;
}

void testDynamicArray()
{
    testArrayResize();
    testArrayBrackets();
    testArrayGet();
    testArrayEquals();
    testItemsConstructor();
    testCopyDynamicArray();
    std::cout << "DYNAMICARRAY TESTS PASSED" << std::endl
              << std::endl;
}