#pragma once

#include "LinkedList.h"
#include "Sequence.h"

namespace ds
{
    template <class T>
    class ListSequence : public Sequence<T>
    {

    private:
        LinkedList<T> list;

    public:
        // Constructors
        ListSequence(const T *items, int count)
        {
            list = LinkedList<T>(items, count);
        }

        ListSequence() = default;
        ListSequence(int size)
        {
            list = LinkedList<T>(size);
        }

        ListSequence(const ListSequence<T> &other)
        {
            list = other.list;
        }

        explicit ListSequence(const LinkedList<T> &data)
        {
            list = data;
        }

        explicit ListSequence(const Sequence<T> *other)
        {
            for (int i = 0; i < other->getSize(); i++)
            {
                append(other->get(i));
            }
        }

        // Operators
        T &operator[](int index)
        {
            return list[index];
        }

        ListSequence<T> &operator=(ListSequence<T> other)
        {
            list = other.list;
            return *this;
        }

        int operator==(ListSequence<T> other)
        {
            return list == other.list;
        }

        // Getters and setters
        T &getFirst()
        {
            return list[0];
        }

        T &getLast()
        {
            return list[list.getSize() - 1];
        }

        T &get(int index)
        {
            return list.get(index);
        }

        T getValue(int index) const
        {
            return list.getValue(index);
        }

        int getSize() const
        {
            return list.getSize();
        }
        Sequence<T> *set(const T &item, int index)
        {
            list.set(item, index);
            return this;
        }

        Sequence<T> *copySequence()
        {
            return (new ListSequence<T>(*this));
        }

        ListSequence<T> *append(const T &item)
        {
            list.append(item);
            return this;
        }

        ListSequence<T> *getSubsequence(int startIndex, int endIndex)
        {

            ListSequence<T> *subSequence = new ListSequence<T>(*list.getSublist(startIndex, endIndex));
            return subSequence;
        }

        ListSequence<T> *prepend(const T &item)
        {
            list.prepend(item);
            return this;
        }

        ListSequence<T> *insertAt(const T &item, int index)
        {
            list.insertAt(item, index);
            return this;
        }

        ListSequence<T> *concat(const Sequence<T> &other)
        {
            int otherSize = other.getSize();
            for (int i = 0; i < otherSize; i++)
            {
                append(other.getValue(i));
            }
            return this;
        }
    };
}