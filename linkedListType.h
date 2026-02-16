#ifndef linkedListType_H
#define linkedListType_H

#include <iostream>
#include <cassert> // for the assert function
#include "linkedListIterator.h"

template <class Type>
class linkedListType
{
public:
    const linkedListType<Type>& operator=(const linkedListType<Type>& otherList)
    {
        if (this != &otherList)
        {
            copyList(otherList);
        }
        return *this;
    }

    bool initializeList() const
    {
        return (first == nullptr);
    }

    bool isEmptyList() const
    {
        return (first == nullptr);
    }

    void print() const
    {
        nodeType<Type>* current = first;
        while (current != nullptr)
        {
            std::cout << current->info << " ";
            current = current->link;
        }
        std::cout << std::endl;
    }

    int length() const 
    {
        return count;
    }

    void destroyList()
    {
        nodeType<Type>* temp;
        while (first != nullptr)
        {
            temp = first;
            first = first->link;
            delete temp;
        }
        last = nullptr;
        count = 0;
    }

    Type front() const
    {
        assert(first != nullptr);
        return first->info;
    }

    Type back() const
    {
        assert(last != nullptr);
        return last->info;
    }

    virtual bool search(const Type& searchItem) const = 0;
    virtual void insertFirst(const Type& newItem) = 0;
    virtual void insertLast(const Type& newItem) = 0;
    virtual void deleteNode(const Type& deleteItem) = 0;

    linkedListIterator<Type> begin()
    {
        return linkedListIterator<Type>(first);
    }

    linkedListIterator<Type> end()
    {
        return linkedListIterator<Type>(nullptr);
    }

    linkedListType()
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }

    linkedListType(const linkedListType<Type>& otherList)
    {
        first = nullptr;
        copyList(otherList);
    }

    virtual ~linkedListType()
    {
        destroyList();
    }

protected:
    int count;
    nodeType<Type>* first;
    nodeType<Type>* last;   

private:
    void copyList(const linkedListType<Type>& otherList)
    {
        nodeType<Type>* newNode;
        nodeType<Type>* current;

        if (first != nullptr)
        {
            destroyList();
        }

        if (otherList.first == nullptr)
        {
            first = nullptr;
            last = nullptr;
            count = 0;
        }
        else
        {
            current = otherList.first;
            count = otherList.count;

            first = new nodeType<Type>;
            first->info = current->info;
            first->link = nullptr;
            last = first;
            current = current->link;

            while (current != nullptr)
            {
                newNode = new nodeType<Type>;
                newNode->info = current->info;
                newNode->link = nullptr;
                last->link = newNode;
                last = newNode;
                current = current->link;
            }
        }
    }

};

#endif