#pragma once

#include "DynamicArray.h"
#include "Sequence.h"

namespace ds
{
    template <class T>
    class ArraySequence : public Sequence<T>
    {

    private:
        DynamicArray<T> array;

    public:
        // Constructors
        ArraySequence(const T *items, int count)
        {
            array = DynamicArray<T>(items, count);
        }

        ArraySequence()
        {
            array = DynamicArray<T>();
        }
        ArraySequence(int size)
        {
            array = DynamicArray<T>(size);
        }

        ArraySequence(const ArraySequence<T> &other)
        {
            array = other.array;
        }

        explicit ArraySequence(const DynamicArray<T> &data)
        {
            array = data;
        }

        explicit ArraySequence(const Sequence<T> *other)
        {
            for (int i = 0; i < other->getSize(); i++)
            {
                append(other->get(i));
            }
        }

        T &operator[](int index)
        {
            return array[index];
        }

        ArraySequence<T> &operator=(ArraySequence<T> other)
        {
            array = other.array;
            return *this;
        }

        bool operator==(ArraySequence<T> other)
        {
            return array == other.array;
        }

        // Getters and setters
        int getSize() const
        {
            return array.getSize();
        }

        T &getFirst()
        {
            return array[0];
        }

        T &getLast()
        {
            return array[array.getSize() - 1];
        }

        T &get(int index)
        {
            return array.get(index);
        }

        T getValue(int index) const
        {
            return array.getValue(index);
        }

        ArraySequence<T> *set(const T &item, int index)
        {
            array.set(item, index);
            return this;
        }

        ArraySequence<T> *getSubsequence(int startIndex, int endIndex)
        {
            if (startIndex > endIndex)
            {
                std::cout << __FUNCTION__ << "function failed" << std::endl;
                throw std::invalid_argument("InvalidRange");
            }
            ArraySequence<T> *subSequence = new ArraySequence<T>;
            for (size_t i = startIndex; i <= endIndex; i++)
            {
                subSequence->append(array.get(i));
            }
            return subSequence;
        }

        ArraySequence<T> *append(const T &item)
        {
            array.resize(getSize() + 1);
            array[getSize() - 1] = item;
            return this;
        }

        ArraySequence<T> *prepend(const T &item)
        {
            array.resize(array.getSize() + 1);
            for (int i = array.getSize() - 2; i >= 0; i--)
            {
                array[i + 1] = array[i];
            }
            array[0] = item;
            return this;
        }

        ArraySequence<T> *insertAt(const T &item, int index)
        {
            array.resize(array.getSize() + 1);
            for (int i = array.getSize() - 2; i >= index; i--)
            {
                array[i + 1] = array[i];
            }
            array[index] = item;
            return this;
        }

        ArraySequence<T> *copySequence()
        {
            return (new ArraySequence<T>(*this));
        }

        ArraySequence<T> *concat(const Sequence<T> &other)
        {
            int otherSize = other.getSize();
            for (int i = 0; i < otherSize; i++)
            {
                this->append(other.getValue(i));
            }
            return this;
        }
    };
}