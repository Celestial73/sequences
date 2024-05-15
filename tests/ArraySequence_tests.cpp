#include "ArraySequence_tests.h"
#include "../DataStructures/ListSequence.h"

void testGetSubSequence()
{
    int items[] = {1, 2, 3, 4, 5};
    int subItems[] = {2, 3, 4};
    ds::ArraySequence<int> arrSeq(items, 5);
    ds::ArraySequence<int> expectedSubSequence(subItems, 3);
    ds::ArraySequence<int> *subSequence = arrSeq.getSubsequence(1, 3);
    IS_TRUE(subSequence->getSize() == 3);
    for (size_t i = 0; i < subSequence->getSize(); i++)
    {
        IS_TRUE(subSequence->get(i) == (i + 2));
    }
    std::cout << "ArraySequence getSubSequence test passed" << std::endl;
    delete subSequence;
}

void testArraySequenceItemsConstructor()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::ArraySequence<int> arrSeq(items, 5);
    IS_TRUE(arrSeq.getSize() == 5);
    for (size_t i = 0; i < arrSeq.getSize(); i++)
    {
        IS_TRUE(arrSeq.get(i) == (i + 1));
    }
    std::cout << "ArraySequence itemsConstructor test passed" << std::endl;
}

void testArraySequenceGetters()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::ArraySequence<int> arrSeq(items, 5);
    IS_TRUE(arrSeq.getSize() == 5);
    IS_TRUE(arrSeq[2] == 3);
    IS_TRUE(arrSeq.get(4) == 5);
    IS_TRUE(arrSeq.getLast() == 5);
    IS_TRUE(arrSeq.getFirst() == 1);
    std::cout << "ArraySequence getters test passed" << std::endl;
}
void testArraySequenceSetters()
{
    try
    {
        int items[] = {1, 2, 3, 4, 5};
        ds::ArraySequence<int> arrSeq(items, 5);
        arrSeq.set(10, 0);
        IS_TRUE(arrSeq[0] == 10);
        arrSeq.insertAt(20, 1);
        IS_TRUE(arrSeq[1] == 20);
        arrSeq.prepend(100);
        IS_TRUE(arrSeq.getFirst() == 100);
        arrSeq.append(200);
        IS_TRUE(arrSeq.getLast() == 200);
        std::cout << "ArraySequence setters test passed" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl;
    }
}

void testArraySequenceCopyConstructor()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::ArraySequence<int> arrSeq(items, 5);
    ds::ArraySequence<int> copiedSeq(arrSeq);
    IS_TRUE(copiedSeq.getSize() == 5);
    for (size_t i = 0; i < copiedSeq.getSize(); i++)
    {
        IS_TRUE(arrSeq.get(i) == (i + 1));
    }
    std::cout << "ArraySequence CopyConstructor test passed" << std::endl;
}

void testArraySequenceBracketsOperator()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::ArraySequence<int> arrSeq(items, 5);
    IS_TRUE(arrSeq[2] == 3);
    std::cout << "ArraySequence bracketsOperator test passed" << std::endl;
}
void testArraySequenceConcat()
{
    int items1[] = {1, 2, 3, 4, 5};
    int items2[] = {6, 7, 8, 9, 10};
    ds::ArraySequence<int> arrSeq1(items1, 5);
    ds::ArraySequence<int> arrSeq2(items2, 5);
    arrSeq1.concat(arrSeq2);
    for (size_t i = 0; i < 10; i++)
    {
        IS_TRUE(arrSeq1.get(i) == (i + 1));
    }

    std::cout << "ArraySequence concat test passed" << std::endl;
}

void testArraySequenceAssignmentOperator()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::ArraySequence<int> arrSeq(items, 5);
    ds::ArraySequence<int> assignSeq = arrSeq;
    IS_TRUE(arrSeq.getSize() == 5);
    for (size_t i = 0; i < arrSeq.getSize(); i++)
    {
        IS_TRUE(arrSeq.get(i) == (i + 1));
    }
    std::cout << "ArraySequence assignmentOperator test passed" << std::endl;
}

void testArraySequence()
{
    testGetSubSequence();
    testArraySequenceItemsConstructor();
    testArraySequenceConcat();
    testArraySequenceCopyConstructor();
    testArraySequenceGetters();
    testArraySequenceSetters();
    testArraySequenceBracketsOperator();
    testArraySequenceAssignmentOperator();

    std::cout << "ARRAYSEQUENCE TESTS PASSED" << std::endl
              << std::endl;
}