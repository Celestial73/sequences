#include "LinkedList_tests.h"

void testAssignmentOperator()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::LinkedList<int> lst1(items, 5);
    ds::LinkedList<int> lst2 = lst1;
    IS_TRUE(lst1 == lst2);
    std::cout << "LinkedList assignment operator test passed" << std::endl;
}

void testEmptyConstructor()
{
    ds::LinkedList<int> lst = ds::LinkedList<int>();
    IS_TRUE(lst.getSize() == 0);
    bool exceptionCaught = false;
    int a;
    try
    {
        a = lst.getFirst();
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
    std::cout << "LinkedList empty Constructor test passed" << std::endl;
}

void testArrayConstructor()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::LinkedList<int> lst(items, 5);
    IS_TRUE(lst.getSize() == 5);
    for (size_t i = 0; i < lst.getSize(); ++i)
    {
        IS_TRUE(lst[i] == lst[i]);
    }
    std::cout << "LinkedList array constructor test passed" << std::endl;
}

void testCopyConstructor()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::LinkedList<int> lst1(items, 5);
    ds::LinkedList<int> lst2(lst1);
    for (size_t i = 0; i < lst2.getSize(); ++i)
    {
        IS_TRUE(lst1[i] == lst2[i]);
    }
    IS_TRUE(lst2.getSize() == 5);
    std::cout << "LinkedList copy constructor test passed" << std::endl;
}

void testEqualsOperator()
{
    int items[] = {1, 2, 3, 4, 5};
    int appendedArray[] = {1, 2, 3, 4, 5, 6};
    ds::LinkedList<int> lst1(items, 5);
    ds::LinkedList<int> lst2(items, 5);
    ds::LinkedList<int> lst3(appendedArray, 6);
    IS_TRUE(lst1 == lst2);
    IS_TRUE(!(lst1 == lst3));
    std::cout << "LinkedList equals operator test passed" << std::endl;
}

void testListGetters()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::LinkedList<int> lst1(items, 5);
    IS_TRUE(lst1.get(1) == 2);
    IS_TRUE(lst1[2] == 3);
    IS_TRUE(lst1.getFirst() == 1);
    IS_TRUE(lst1.getLast() == 5);

    ds::LinkedList<int> emptyList = ds::LinkedList<int>();
    bool exceptionCaught = false;
    int a;
    try
    {
        a = emptyList.getFirst();
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
    std::cout << "LinkedList getters tests passed" << std::endl;
}

void testListConcat()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8, 9, 10};
    int resArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ds::LinkedList<int> lst1(arr1, 5);
    ds::LinkedList<int> lst2(arr2, 5);
    ds::LinkedList<int> *concatedLst = lst1.concat(&lst2);

    ds::LinkedList<int> expectedResLst(resArr, 10);
    IS_TRUE(*concatedLst == expectedResLst);
    delete concatedLst;
    std::cout << "LinkedList concat test passed" << std::endl;
}

void testSublist()
{
    int arr1[] = {1, 2, 3, 4, 5};

    int resArr[] = {2, 3, 4};
    ds::LinkedList<int> lst1(arr1, 5);
    ds::LinkedList<int> *sublist = lst1.getSublist(1, 3);
    ds::LinkedList<int> expectedSublist(resArr, 3);

    IS_TRUE(*sublist == expectedSublist);
    delete sublist;
    std::cout << "LinkedList sublist test passed" << std::endl;
}

void testListSetters()
{
    int originalArray[] = {1, 2, 3, 4, 5};
    int appendedArray[] = {1, 2, 3, 4, 5, 6};
    int prependedArray[] = {0, 1, 2, 3, 4, 5};
    int insertedArray[] = {1, 2, 3, 100, 4, 5};

    ds::LinkedList<int> lst1(originalArray, 5);
    ds::LinkedList<int> appendedLstRes(appendedArray, 6);

    lst1.append(6);
    IS_TRUE(lst1 == appendedLstRes);

    ds::LinkedList<int> lst2(originalArray, 5);
    ds::LinkedList<int> prependenLstRes(prependedArray, 6);
    lst2.prepend(0);
    IS_TRUE(lst2 == prependenLstRes);

    ds::LinkedList<int> lst3(originalArray, 5);
    ds::LinkedList<int> insertedLstRes(insertedArray, 6);

    lst3.insertAt(100, 3);
    IS_TRUE(lst3 == insertedLstRes);

    std::cout << "LinkedList setters tests passed" << std::endl;
}

void testLinkedList()
{
    testAssignmentOperator();
    testSublist();
    testListConcat();
    testListSetters();
    testEqualsOperator();
    testListGetters();
    testCopyConstructor();
    testEmptyConstructor();
    testArrayConstructor();
    std::cout << "LINKEDLIST TESTS PASSED" << std::endl
              << std::endl;
}
