#ifndef unorderedLinkedList_H
#define unorderedLinkedList_H

#include "linkedListType.h"
template <class Type>
class unorderedLinkedList : public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const
    {
        nodeType<Type>* current = this->first;
        while (current != nullptr)
        {
            if (current->info == searchItem)
            {
                return true;
            }
            current = current->link;
        }
        return false;
    }

    void insertFirst(const Type& newItem)
    {
        nodeType<Type>* newNode = new nodeType<Type>;
        newNode->info = newItem;
        newNode->link = this->first;
        this->first = newNode;
        this->count++;
        if (this->last == nullptr)
        {
            this->last = newNode;
        }
    }

    void insertLast(const Type& newItem)
    {
        nodeType<Type>* newNode = new nodeType<Type>;
        newNode->info = newItem;
        newNode->link = nullptr;
        if (this->first == nullptr)
        {
            this->first = newNode;
            this->last = newNode;
        }
        else
        {
            this->last->link = newNode;
            this->last = newNode;
        }
        this->count++;
    }

    void deleteNode(const Type& deleteItem)
    {
        nodeType<Type> *current, *trailCurrent;
        if(this->first == nullptr)
        {
            return;
        }
        if(this->first->info == deleteItem)
        {
            current = this->first;
            this->first = this->first->link;
            delete current;
            this->count--;
            if(this->first == nullptr)
            {
                this->last = nullptr;
            }
        }
        else
        {
            trailCurrent = this->first;
            current = this->first->link;
            while(current != nullptr)
            {
                if(current->info == deleteItem)
                {
                    trailCurrent->link = current->link;
                    if(current == this->last)
                    {
                        this->last = trailCurrent;
                    }
                    delete current;
                    this->count--;
                    return;
                }
                trailCurrent = current;
                current = current->link;
            }
        }
    }

};

#endif