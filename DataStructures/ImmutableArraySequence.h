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

        T getFirst()
        {
            return array[0];
        }

        T getLast()
        {
            return array[array.getSize() - 1];
        }

        T &get(int index) const
        {
            return array.get(index);
        }

        void set(T item, int index)
        {
            array.set(item, index);
        }

        T &operator[](int index) const
        {
            return array[index];
        }

        bool operator==(ImmutableArraySequence<T> other)
        {
            return array == other.array;
        }

        ImmutableArraySequence<T> *getSubsequence(int startIndex, int endIndex)
        {
            if (startIndex > endIndex)
            {
                std::cout << __FUNCTION__ << "function failed" << std::endl;
                throw std::invalid_argument("InvalidRange");
            }
            ImmutableArraySequence<T> *subSequence = new ImmutableArraySequence<T>;
            for (size_t i = startIndex; i <= endIndex; i++)
            {
                subSequence->append(array.get(i));
            }
            return subSequence;
        }

        ImmutableArraySequence<T> *append(T item)
        {
            ImmutableArraySequence<T> *newImmutableArraySequence = new ImmutableArraySequence<T>(this);
            array.resize(getSize() + 1);
            array[getSize() - 1] = item;
            swapImmutableArraySequence(*newImmutableArraySequence);
            return newImmutableArraySequence;
        }

        ImmutableArraySequence<T> *prepend(T item)
        {
            ImmutableArraySequence<T> *newImmutableArraySequence = new ImmutableArraySequence<T>(this);
            array.resize(array.getSize() + 1);
            for (int i = array.getSize() - 2; i >= 0; i--)
            {
                array[i + 1] = array[i];
            }
            array[0] = item;
            swapImmutableArraySequence(*newImmutableArraySequence);
            return newImmutableArraySequence;
        }

        ImmutableArraySequence<T> *insertAt(T item, int index)
        {
            ImmutableArraySequence<T> *newImmutableArraySequence = new ImmutableArraySequence<T>(this);
            array.resize(array.getSize() + 1);
            for (int i = array.getSize() - 2; i >= index; i--)
            {
                array[i + 1] = array[i];
            }
            array[index] = item;
            swapImmutableArraySequence(*newImmutableArraySequence);
            return newImmutableArraySequence;
        }

        ImmutableArraySequence<T> *copySequence()
        {
            return (new ImmutableArraySequence<T>(*this));
        }

        ImmutableArraySequence<T> *concat(ImmutableSequence<T> *other)
        {
            ImmutableArraySequence<T> *newImmutableArraySequence = new ImmutableArraySequence<T>(this);
            int otherSize = other->getSize();
            for (int i = 0; i < otherSize; i++)
            {
                newImmutableArraySequence->append(other->get(i));
            }
            return newImmutableArraySequence;
        }
    };
}