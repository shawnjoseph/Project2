#ifndef PROJECT2_DYNQUEUE_H
#define PROJECT2_DYNQUEUE_H
#include <iostream>
using namespace std;

template <class Type> class DynQueue {
private:
    Type * array;
    int ihead;
    int itail;
    int count;
    int initialSize;
    int arraySize;

public:
    DynQueue():
            initialSize(13), count(0), arraySize(initialSize), ihead(-1), itail(-1)
    {}

    DynQueue(int initialSize)
            :count(0),ihead(-1),itail(-1)
    {
        this->initialSize = initialSize;
        arraySize = initialSize;
    }



};


#endif //PROJECT2_DYNQUEUE_H
