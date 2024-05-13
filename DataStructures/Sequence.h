#pragma once

namespace ds
{
    template <typename T>
    class Sequence
    {
    public:
        virtual T &getFirst() = 0;
        virtual T &getLast() = 0;
        virtual T &get(int index) = 0;
        virtual T getValue(int index) const = 0;
        virtual T &operator[](int index) = 0;
        virtual int getSize() const = 0;
        virtual Sequence<T> *set(const T &data, int index) = 0;
        virtual Sequence<T> *insertAt(const T &value, int index) = 0;
        virtual Sequence<T> *append(const T &value) = 0;
        virtual Sequence<T> *prepend(const T &value) = 0;
        virtual Sequence<T> *copySequence() = 0;
        virtual Sequence<T> *getSubsequence(int startIndex, int endIndex) = 0;
        // const reference
        virtual Sequence<T> *concat(const Sequence<T> &other) = 0;
    };
}