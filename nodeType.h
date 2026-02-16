#ifndef nodeType_H
#define nodeType_H

template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type>* link;
}; 

#endif