#pragma once
#include <iostream>

namespace ds
{
    // second arg is a null value
    template <class T, T nullvalue>
    class DynamicArray
    {
    public:
        // Constructors
        DynamicArray(int size) : size(size), data(new T[size])
        {
            for (size_t i = 0; i != size; ++i)
            {
                // hardcoded 0
                data[i] = 0;
            }
        }

        DynamicArray(const T *items, int count) : size(count), data(new T[size])
        {
            for (size_t i = 0; i != size; ++i)
            {
                data[i] = items[i];
            }
        }

        DynamicArray(DynamicArray const &other) : size(other.size), data(new T[size])
        {
            for (size_t i = 0; i != size; ++i)
            {
                data[i] = other.data[i];
            }
        }

        DynamicArray() : size(0), data(nullptr)
        {
        }

        // Destructor
        ~DynamicArray()
        {
            delete[] data;
        }

        // Operators
        bool operator==(DynamicArray<T> other)
        {
            if (size != other.getSize())
                return 0;

            for (int i = 0; i < other.getSize(); i++)
            {
                if (data[i] != other.data[i])
                    return 0;
            }
            return 1;
        }

        // const method returning reference
        T &operator[](int index) const
        {
            validateAccessByIndex(index, __FUNCTION__);
            return data[index];
        }

        // Function for swapping one array's data for another's.
        void swapArray(DynamicArray &other)
        {
            std::swap(size, other.size);
            std::swap(data, other.data);
        }

        DynamicArray &operator=(DynamicArray const &other)
        {
            if (this != &other)
            {
                DynamicArray(other).swapArray(*this);
            }
            return *this;
        }

        // Getters and setters
        size_t getSize() const
        {
            return size;
        }

        T &get(int index)
        {
            validateListNotEmpty(__FUNCTION__);
            validateIndex(index, __FUNCTION__);
            return data[index];
        }

        T getValue(int index) const
        {
            validateListNotEmpty(__FUNCTION__);
            validateIndex(index, __FUNCTION__);
            return data[index];
        }

        void set(T value, int index)
        {
            validateListNotEmpty(__FUNCTION__);
            validateIndex(index, __FUNCTION__);
            data[index] = value;
        }

        void resize(size_t newSize)
        {
            DynamicArray newArray(newSize);
            size_t n = newSize > size ? size : newSize;
            for (size_t i = 0; i != n; ++i)
            {
                newArray.data[i] = data[i];
            }
            swapArray(newArray);
        }

    private:
        size_t size;
        T *data;

        void validateListNotEmpty(const char *function) const
        {
            if (size == 0)
            {
                std::cout << function << "function failed" << std::endl;
                throw std::logic_error("ReadingEmptyList");
            }
        }

        void validateIndex(int index, const char *function) const
        {
            if (index >= size)
            {
                std::cout << function << "function failed" << std::endl;
                throw std::invalid_argument("IndexOutOfRange");
            }
            if (index < 0)
            {
                std::cout << function << "function failed" << std::endl;
                throw std::invalid_argument("NegativeIndexValue");
            }
        }

        void validateAccessByIndex(int index, const char *function) const
        {
            validateListNotEmpty(__FUNCTION__);
            validateIndex(index, function);
        }
    };
}