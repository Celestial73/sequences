#pragma once
#include <iostream>
using namespace std;

namespace ds
{
    template <typename T>
    class Node
    {
    public:
        // Constructors

        // null element
        Node() : data(NULL), next(NULL){};
        // make const reference
        Node(const T &data) : data(data), next(NULL){};

        // Getters and setters
        void setData(const T &data)
        {
            this->data = data;
        };

        T &getData()
        {
            return this->data;
        };

        void setNext(Node<T> *node)
        {
            this->next = node;
        };

        Node<T> *getNext() const
        {
            return this->next;
        };

    private:
        T data;
        Node<T> *next;
    };

    template <typename T>
    class LinkedList
    {
    public:
        // Constructors
        LinkedList() : head(NULL), tail(NULL), size(0){};

        LinkedList(const T *items, int count) : head(NULL), tail(NULL), size(0)
        {
            for (size_t i = 0; i < count; i++)
            {
                append(items[i]);
            }
        };
        LinkedList(int count) : head(NULL), tail(NULL), size(0)
        {
            for (size_t i = 0; i < count; i++)
            {
                append(0);
            }
        };

        LinkedList(LinkedList const &other) : size(0), head(NULL), tail(NULL)
        {
            Node<T> *otherListTraverseNode = other.head;
            for (size_t i = 0; i < other.size; i++)
            {
                this->append(otherListTraverseNode->getData());
                otherListTraverseNode = otherListTraverseNode->getNext();
            }
        }

        ~LinkedList()
        {
            Node<T> *traverseNode1 = head;
            Node<T> *traverseNode2;
            while (traverseNode1)
            {
                traverseNode2 = traverseNode1->getNext();
                delete traverseNode1;
                traverseNode1 = traverseNode2;
            }
        }

        // Operators
        T &operator[](int index)
        {
            return get(index);
        }

        void swapList(LinkedList &other)
        {
            std::swap(size, other.size);
            std::swap(head, other.head);
            std::swap(tail, other.tail);
        }

        LinkedList &operator=(LinkedList const &other)
        {
            if (this != &other)
            {
                LinkedList(other).swapList(*this);
            }
            return *this;
        }

        bool operator==(LinkedList<T> other)
        {
            if (size != other.getSize())
                return 0;

            Node<T> *thisListNode = this->head;
            Node<T> *otherListNode = other.head;
            for (int i = 0; i < other.getSize(); i++)
            {
                if (thisListNode->getData() != otherListNode->getData())
                {
                    return 0;
                }
                thisListNode = thisListNode->getNext();
                otherListNode = otherListNode->getNext();
            }
            return 1;
        }

        // Getters and Setters
        int getSize() const
        {
            return this->size;
        }
        T &getFirst()
        {
            validateListNotEmpty(__FUNCTION__);
            return this->head->getData();
        }
        T &getLast()
        {
            validateListNotEmpty(__FUNCTION__);
            return this->tail->getData();
        }

        T &get(int index)
        {
            validateAccessByIndex(index, __FUNCTION__);
            Node<T> *traverseNode = this->head;
            size_t i = 0;
            while (i != index)
            {
                traverseNode = traverseNode->getNext();
                i++;
            }
            return traverseNode->getData();
        }
        T getValue(int index) const
        {
            validateAccessByIndex(index, __FUNCTION__);
            Node<T> *traverseNode = this->head;
            size_t i = 0;
            while (i != index)
            {
                traverseNode = traverseNode->getNext();
                i++;
            }
            return traverseNode->getData();
        }

        void set(const T &item, int index)
        {
            Node<T> *accessedNode = getNode(index);
            accessedNode->setData(item);
        }

        void append(const T data)
        {
            Node<T> *newNode = new Node<T>(data);
            if (size == 0)
            {
                this->head = newNode;
                this->tail = newNode;
                this->head->setNext(NULL);
                this->size++;
                return;
            }
            this->tail->setNext(newNode);
            this->tail = newNode;
            this->size++;
            return;
        }
        void prepend(const T &data)
        {
            Node<T> *newNode = new Node<T>(data);

            if (size == 0)
            {
                this->head = newNode;
                this->tail = newNode;
                this->head->setNext(NULL);
                this->size++;
                return;
            }
            newNode->setNext(this->head);
            this->head = newNode;
            this->size++;
            return;
        };

        LinkedList<T> *getSublist(int startIndex, int endIndex) const
        {
            validateAccessByIndex(startIndex, __FUNCTION__);
            validateAccessByIndex(endIndex, __FUNCTION__);
            if (startIndex > endIndex)
            {
                std::cout << __FUNCTION__ << " function failed" << std::endl;
                throw std::invalid_argument("InvalidIndexRange");
            }
            LinkedList<T> *sublist = new LinkedList<T>();
            Node<T> *traverseNode = this->getNode(startIndex);
            for (size_t i = startIndex; i <= endIndex; i++)
            {
                sublist->append(traverseNode->getData());
                if (i != endIndex)
                {
                    traverseNode = traverseNode->getNext();
                }
            }
            return sublist;
        }

        void insertAt(const T &data, int index)
        {
            validateListNotEmpty(__FUNCTION__);
            // Can't use validateAccessByIndex(), because (index == size) case is acceptable
            // validateAccessByIndex() would throw an exception
            if (index > size)
            {
                std::cout << __FUNCTION__ << " function failed" << std::endl;
                throw std::invalid_argument("IndexOutOfRange");
            }
            Node<T> *newNode = new ds::Node<T>(data);
            if (index == 0)
            {
                newNode->setNext(this->head);
                this->head = newNode;
                return;
            }
            if (index == size)
            {
                this->tail->setNext(newNode);
                this->tail = newNode;
                return;
            }
            Node<T> *traverseNode = this->head;
            size_t i = 0;
            while (i != index - 1)
            {
                traverseNode = traverseNode->getNext();
                i++;
            }
            newNode->setNext(traverseNode->getNext());
            traverseNode->setNext(newNode);
            size++;
            return;
        }

        void printList()
        {
            Node<T> *traverseNode = this->head;

            while (traverseNode != NULL)
            {
                cout << traverseNode->getData() << endl;
                traverseNode = traverseNode->getNext();
            }
            cout << endl;
        };

        // Appends the passed list to this list
        LinkedList<T> *concat(LinkedList<T> *other) const
        {
            LinkedList<T> *newList = new LinkedList<T>();

            Node<T> *thisListNode = this->head;
            Node<T> *otherListNode = other->head;

            for (size_t i = 0; i < this->size; i++)
            {
                newList->append(thisListNode->getData());
                thisListNode = thisListNode->getNext();
            }
            for (size_t i = 0; i < other->getSize(); i++)
            {
                newList->append(otherListNode->getData());
                otherListNode = otherListNode->getNext();
            }
            return newList;
        }

    private:
        Node<T> *head;
        Node<T> *tail;
        int size;
        void validateListNotEmpty(const char *function) const
        {
            if (size == 0)
            {
                std::cout << function << " function failed" << std::endl;
                throw std::logic_error("ReadingEmptyList");
            }
        }

        void validateIndex(int index, const char *function) const
        {
            if (index >= size)
            {
                std::cout << function << " function failed" << std::endl;
                throw std::invalid_argument("IndexOutOfRange");
            }
            if (index < 0)
            {
                std::cout << function << " function failed" << std::endl;
                throw std::invalid_argument("NegativeIndexValue");
            }
        }

        void validateAccessByIndex(int index, const char *function) const
        {
            validateListNotEmpty(function);
            validateIndex(index, function);
        }

        Node<T> *getNode(int index) const
        {
            validateAccessByIndex(index, __FUNCTION__);
            Node<T> *traverseNode = this->head;
            size_t i = 0;
            while (i != index)
            {
                traverseNode = traverseNode->getNext();
                i++;
            }
            return traverseNode;
        }
    };
};
