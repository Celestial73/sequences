#include "ListSequence_tests.h"

void testListSequenceItemsConstructor()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::ListSequence<int> lstSeq(items, 5);
    IS_TRUE(lstSeq.getSize() == 5);
    for (size_t i = 0; i < lstSeq.getSize(); i++)
    {
        IS_TRUE(lstSeq.get(i) == (i + 1));
    }
    std::cout << "ListSequence itemsConstructor test passed" << std::endl;
}

void testListSequenceSizeConsturctor()
{
    ds::ListSequence<int> lstSeq(5);
    IS_TRUE(lstSeq.getSize() == 5);
    for (size_t i = 0; i < lstSeq.getSize(); i++)
    {
        IS_TRUE(lstSeq.get(i) == 0);
    }
    std::cout << "ListSequence SizeConstructor test passed" << std::endl;
}

void testListSequenceCopyConstructor()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::ListSequence<int> lstSeq(items, 5);
    ds::ListSequence<int> copiedSeq(lstSeq);
    IS_TRUE(copiedSeq.getSize() == 5);
    for (size_t i = 0; i < copiedSeq.getSize(); i++)
    {
        IS_TRUE(lstSeq.get(i) == (i + 1));
    }
    std::cout << "ListSequence CopyConstructor test passed" << std::endl;
}

void testListSequenceGetSubSequence()
{
    int items[] = {1, 2, 3, 4, 5};
    int subItems[] = {2, 3, 4};
    ds::ListSequence<int> lstSeq(items, 5);
    ds::ListSequence<int> expectedSubSequence(subItems, 3);
    ds::ListSequence<int> *subSequence = lstSeq.getSubsequence(1, 3);
    IS_TRUE(subSequence->getSize() == 3);
    for (size_t i = 0; i < subSequence->getSize(); i++)
    {
        IS_TRUE(subSequence->get(i) == (i + 2));
    }
    std::cout << "ListSequence getSubSequence test passed" << std::endl;
    delete subSequence;
}

void testListSequenceGetters()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::ListSequence<int> lstSeq(items, 5);
    IS_TRUE(lstSeq.getSize() == 5);
    IS_TRUE(lstSeq[2] == 3);
    IS_TRUE(lstSeq.get(4) == 5);
    IS_TRUE(lstSeq.getLast() == 5);
    IS_TRUE(lstSeq.getFirst() == 1);
    std::cout << "ListSequence getters test passed" << std::endl;
}

void testListSequenceSetters()
{
    try
    {
        int items[] = {1, 2, 3, 4, 5};
        ds::ListSequence<int> lstSeq(items, 5);
        lstSeq.set(10, 0);
        IS_TRUE(lstSeq[0] == 10);
        lstSeq.insertAt(20, 1);
        IS_TRUE(lstSeq[1] == 20);
        lstSeq.prepend(100);
        IS_TRUE(lstSeq.getFirst() == 100);
        lstSeq.append(200);
        IS_TRUE(lstSeq.getLast() == 200);
        std::cout << "ListSequence setters test passed" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl;
    }
}

void testListSequenceBracketsOperator()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::ListSequence<int> lstSeq(items, 5);
    IS_TRUE(lstSeq[2] == 3);
    std::cout << "ListSequence bracketsOperator test passed" << std::endl;
}

void testListSequenceConcat()
{
    int items1[] = {1, 2, 3, 4, 5};
    int items2[] = {6, 7, 8, 9, 10};
    ds::ListSequence<int> lstSeq1(items1, 5);
    ds::ListSequence<int> lstSeq2(items2, 5);
    lstSeq1.concat(lstSeq2);
    for (size_t i = 0; i < 10; i++)
    {
        IS_TRUE(lstSeq1.get(i) == (i + 1));
    }
    std::cout << "ListSequence concat test passed" << std::endl;
}

void testListSequenceAssignmentOperator()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::ListSequence<int> lstSeq(items, 5);
    ds::ListSequence<int> assignSeq = lstSeq;
    IS_TRUE(lstSeq.getSize() == 5);
    for (size_t i = 0; i < lstSeq.getSize(); i++)
    {
        IS_TRUE(lstSeq.get(i) == (i + 1));
    }
    std::cout << "ListSequence assignmentOperator test passed" << std::endl;
}

void testListSequence()
{
    try
    {
        testListSequenceItemsConstructor();
        testListSequenceSizeConsturctor();
        testListSequenceCopyConstructor();
        testListSequenceGetSubSequence();
        testListSequenceConcat();
        testListSequenceGetters();
        testListSequenceSetters();
        testListSequenceBracketsOperator();
        testListSequenceAssignmentOperator();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "LISTSEQUENCE TESTS PASSED" << std::endl
              << std::endl;
}