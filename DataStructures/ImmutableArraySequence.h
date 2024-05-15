#pragma once

#include "DynamicArray.h"
#include "ImmutableSequence.h"

namespace ds
{
    template <class T>
    class ImmutableArraySequence : public ImmutableSequence<T>
    {

    private:
        DynamicArray<T> array;

    public:
        ImmutableArraySequence(T *items, int count)
        {
            array = DynamicArray<T>(items, count);
        }

        ImmutableArraySequence()
        {
            array = DynamicArray<T>();
        }
        ImmutableArraySequence(int size)
        {
            array = DynamicArray<T>(size);
        }

        ImmutableArraySequence(const ImmutableArraySequence<T> &other)
        {
            array = other.array;
        }

        explicit ImmutableArraySequence(const DynamicArray<T> &data)
        {
            array = data;
        }

        explicit ImmutableArraySequence(const ImmutableSequence<T> *other)
        {
            for (int i = 0; i < other->getSize(); i++)
            {
                append(other->get(i));
            }
        }
        void swapImmutableArraySequence(ImmutableArraySequence<T> &other)
        {
            std::swap(array, other.array);
        }

        int getSize() const
        {
            return array.getSize();
        }

        T getFirst() const
        {
            return array[0];
        }

        T getLast() const
        {
            return array[array.getSize() - 1];
        }

        T get(int index) const
        {
            return array.getValue(index);
        }

        T operator[](int index) const
        {
            return array[index];
        }

        bool operator==(ImmutableArraySequence<T> other)
        {
            return array == other.array;
        }

        ImmutableArraySequence<T> *set(const T item, int index) const
        {
            DynamicArray<T> newArray = DynamicArray<T>(array);
            newArray[index] = item;
            ImmutableArraySequence<T> *newSeq = new ImmutableArraySequence<T>(newArray);

            return newSeq;
        }

        ImmutableArraySequence<T> *getSubsequence(int startIndex, int endIndex) const
        {
            if (startIndex > endIndex)
            {
                std::cout << __FUNCTION__ << "function failed" << std::endl;
                throw std::invalid_argument("InvalidRange");
            }

            ImmutableArraySequence<T> *subSequence = new ImmutableArraySequence<T>;
            for (size_t i = startIndex; i <= endIndex; i++)
            {
                subSequence->append(array.getValue(i));
            }
            return subSequence;
        }

        ImmutableArraySequence<T> *append(T item) const
        {
            int currentSize = getSize();
            DynamicArray<T> newArray = DynamicArray<T>(currentSize + 1);
            for (int i = 0; i < currentSize; i++)
            {
                newArray.set(get(i), i);
            }
            newArray.set(item, currentSize);
            ImmutableArraySequence<T> *newSeq = new ImmutableArraySequence<T>(newArray);
            return newSeq;
        }

        ImmutableArraySequence<T> *prepend(T item) const
        {
            int currentSize = getSize();
            DynamicArray<T> newArray = DynamicArray<T>(currentSize + 1);
            for (int i = 1; i < currentSize + 1; i++)
            {
                newArray.set(get(i - 1), i);
            }
            newArray.set(item, 0);
            ImmutableArraySequence<T> *newSeq = new ImmutableArraySequence<T>(newArray);
            return newSeq;
        }

        ImmutableArraySequence<T> *insertAt(T item, int index) const
        {
            ImmutableArraySequence<T> *newSeq = new ImmutableArraySequence<T>(this);
            newSeq->array.resize(getSize() + 1);
            for (int i = newSeq->array.getSize() - 2; i >= index; i--)
            {
                newSeq->array.set(newSeq->array[i], i + 1);
            }
            newSeq->array[index] = item;
            return newSeq;
        }

        ImmutableArraySequence<T> *copySequence() const
        {
            return (new ImmutableArraySequence<T>(*this));
        }

        ImmutableArraySequence<T> *concat(const ImmutableSequence<T> &other) const
        {
            int thisSize = getSize();
            int otherSize = other.getSize();
            DynamicArray<T> newArray = DynamicArray<T>(this->array);
            newArray.resize(thisSize + otherSize);
            for (int i = 0; i < otherSize; i++)
            {
                newArray.set(other.get(i), thisSize + i);
            }
            ImmutableArraySequence<T> *newSeq = new ImmutableArraySequence<T>(newArray);
            return newSeq;
        }
    };
}