#pragma once

namespace ds
{
    template <typename T>
    class ImmutableSequence
    {
    public:
        // const to all methods
        virtual T getFirst() = 0;
        virtual T getLast() = 0;
        virtual T &get(int index) const = 0;
        virtual T &operator[](int index) const = 0;
        virtual void set(T data, int index) = 0;
        virtual int getSize() const = 0;
        virtual ImmutableSequence<T> *insertAt(const T data, int index) = 0;
        virtual ImmutableSequence<T> *append(T value) = 0;
        virtual ImmutableSequence<T> *prepend(T value) = 0;
        virtual ImmutableSequence<T> *copySequence() = 0;
        virtual ImmutableSequence<T> *getSubsequence(int startIndex, int endIndex) = 0;
        virtual ImmutableSequence<T> *concat(ImmutableSequence<T> *other) = 0;
    };
}