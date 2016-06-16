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

    ~DynQueue(){
        delete [] array;
    }

    Type front() const { return array[ihead]; }
    Type back() const { return array[itail]; }

    int size() const{ return count; }
    int capacity() const{ return arraySize; }
    bool empty() const{ return ihead == itail; }

    void display(){}

    Type enqueue(Type const & data){
        int newTail = (itail + 1)%arraySize;
        if(newTail != ihead){
            array[itail]=data;
            itail=newTail;
        }
        else {
            exit(0);
        }
    }
    Type dequeue(){
        if(!empty()){
            ihead = (ihead+1)%arraySize;
        }
    }
    void clear(){}
    int erase(Type const & data){}



};


#endif //PROJECT2_DYNQUEUE_H