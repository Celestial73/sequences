#include "ImmutableArraySequence_tests.h"

void testImmutableArraySequenceItemsConstructor()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::ImmutableArraySequence<int> arrSeq(items, 5);
    IS_TRUE(arrSeq.getSize() == 5);
    for (size_t i = 0; i < arrSeq.getSize(); i++)
    {
        IS_TRUE(arrSeq.get(i) == (i + 1));
    }
    std::cout << "ImmutableArraySequence itemsConstructor test passed" << std::endl;
}

void testImmutableArraySequenceGetters()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::ImmutableArraySequence<int> arrSeq(items, 5);
    IS_TRUE(arrSeq.getSize() == 5);
    IS_TRUE(arrSeq[2] == 3);
    IS_TRUE(arrSeq.get(4) == 5);
    IS_TRUE(arrSeq.getLast() == 5);
    IS_TRUE(arrSeq.getFirst() == 1);
    std::cout << "ImmutableArraySequence getters test passed" << std::endl;
}
void testImmutableArraySequenceSetters()
{
    try
    {
        int items[] = {1, 2, 3, 4, 5};
        ds::ImmutableArraySequence<int> arrSeq(items, 5);
        ds::ImmutableArraySequence<int> *seqWithSet = arrSeq.set(10, 0);
        IS_TRUE((*seqWithSet)[0] == 10);
        delete seqWithSet;
        ds::ImmutableArraySequence<int> *seqWithInsert = arrSeq.insertAt(20, 1);
        IS_TRUE((*seqWithInsert)[1] == 20);
        delete seqWithInsert;
        ds::ImmutableArraySequence<int> *seqWithPrepend = arrSeq.prepend(100);
        IS_TRUE(seqWithPrepend->getFirst() == 100);
        delete seqWithPrepend;
        ds::ImmutableArraySequence<int> *seqWithAppend = arrSeq.append(200);
        IS_TRUE(seqWithAppend->getLast() == 200);
        delete seqWithAppend;
        std::cout << "ImmutableArraySequence setters test passed" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl;
    }
}

void testImmutableArraySequenceSizeConsturctor()
{
    ds::ImmutableArraySequence<int> arrSeq(5);
    IS_TRUE(arrSeq.getSize() == 5);
    std::cout << "ImmutableArraySequence SizeConstructor test passed" << std::endl;
}

void testImmutableArraySequenceCopyConstructor()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::ImmutableArraySequence<int> arrSeq(items, 5);
    ds::ImmutableArraySequence<int> copiedSeq(arrSeq);
    IS_TRUE(copiedSeq.getSize() == 5);
    for (size_t i = 0; i < copiedSeq.getSize(); i++)
    {
        IS_TRUE(arrSeq.get(i) == (i + 1));
    }
    std::cout << "ImmutableArraySequence CopyConstructor test passed" << std::endl;
}

void testImmutableArraySequenceBracketsOperator()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::ImmutableArraySequence<int> arrSeq(items, 5);
    IS_TRUE(arrSeq[2] == 3);
    std::cout << "ImmutableArraySequence bracketsOperator test passed" << std::endl;
}

void testImmutableArraySequenceConcat()
{
    int items1[] = {1, 2, 3, 4, 5};
    int items2[] = {6, 7, 8, 9, 10};
    ds::ImmutableArraySequence<int> arrSeq1(items1, 5);
    ds::ImmutableArraySequence<int> arrSeq2(items2, 5);
    ds::ImmutableArraySequence<int> *concatSeq = arrSeq1.concat(arrSeq2);
    for (size_t i = 0; i < 10; i++)
    {
        IS_TRUE(concatSeq->get(i) == (i + 1));
    }

    std::cout << "ImmutableArraySequence concat test passed" << std::endl;
    delete concatSeq;
}

void testImmutableArraySequenceAssignmentOperator()
{
    int items[] = {1, 2, 3, 4, 5};
    ds::ImmutableArraySequence<int> arrSeq(items, 5);
    ds::ImmutableArraySequence<int> assignSeq = arrSeq;
    IS_TRUE(arrSeq.getSize() == 5);
    for (size_t i = 0; i < arrSeq.getSize(); i++)
    {
        IS_TRUE(arrSeq.get(i) == (i + 1));
    }
    std::cout << "ImmutableArraySequence assignmentOperator test passed" << std::endl;
}

void testImmutableArraySequence()
{
    testImmutableArraySequenceBracketsOperator();
    testImmutableArraySequenceCopyConstructor();
    testImmutableArraySequenceConcat();
    testImmutableArraySequenceSizeConsturctor();
    testImmutableArraySequenceAssignmentOperator();
    testImmutableArraySequenceItemsConstructor();
    testImmutableArraySequenceSetters();
    testImmutableArraySequenceGetters();
    std::cout
        << "IMMUTABLE ARRAYSEQUENCE TESTS PASSED" << std::endl
        << std::endl;
}