#ifndef PROJECT2_STACK_H
#define PROJECT2_STACK_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <class Type> class DynStack {
private:
    Type * array = NULL;
    int count,
        initialSize,
        arraySize,
        myTop;

public:
    DynStack()
            : count(0), initialSize(13), arraySize(initialSize), myTop(-1)
    {
        array = new Type[initialSize];
    }

    DynStack(int initialSize)
            :count(0), myTop(-1)
    {
        this->initialSize = initialSize;
        arraySize = initialSize;
        array = new Type[initialSize];
    }

    ~DynStack(){
        delete [] array;
    }

    Type top() const {
        if(myTop == -1){ cout << "Error Stack Empty" << endl; }
        return this->array[myTop];
    }
//
    int size() const {cout << "Size: " << count << endl; return count; }
//
    int capacity() const { cout << "Capacity: " << arraySize << endl; return arraySize; }
//
    bool isEmpty() const { return count == 0; }
//
    void display() {
        if(count == 0){ cout << "Stack is empty" << endl; }
        else
            for(int i = myTop; i >= 0; i--){
                cout << "#" << myTop - i << " " << array[i] << endl;
            };
 }

    void push(Type const & data) {
        if (myTop < capacity() - 1) {
            myTop++;
            array[myTop] = data;
        }
        else {
            arraySize = arraySize * 2;
            Type *temp;
            temp = new Type[arraySize];
            for (int i = 0; i < count; i++) {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
            count++;
            myTop++;
            this->array[myTop] = data;
        }
    }

    Type pop() {
        Type val  = array[myTop];

        if(myTop == -1) {
            cerr << "Error: Stack is Empty." << endl;
        }
        else {
            myTop--;
            count--;
        }
        if(myTop == arraySize/4) {
            arraySize = arraySize / 2;
            Type *temp;
            temp = new Type[arraySize];

            for (int i = 0; i < count; i++) {
                temp[i] == array[i];
            }
            delete[] array;
            array = temp;
        }
        return val;
    }

    void clear() {
        Type * temp = new Type[initialSize];
        DynStack::~DynStack();
        array = temp;
        arraySize = initialSize;
        }

    int erase (Type const & data) {
        int counter;
        Type * temp  = new Type[arraySize];
        while(myTop != 0){
            Type tmp_val = pop();
            if(tmp_val != data){
                temp[myTop] = tmp_val;
                myTop--;
            }
        }
    }
//        int i = initialSize - 1;
//        Type * temp = new Type[initialSize];
//        while(top() != 0){
//            int tmp_val;
//            tmp_val = pop();
//            if(tmp_val != data){
//                temp[i] = tmp_val;
//                i--;
//            }
//        }
//        delete [] array;
//        count = 0;
//        initialSize = 12;
//        arraySize = initialSize - 1;
//        array = new Type[initialSize];
//        for(int i = 0; i < initialSize*2; i++){
//            if(temp[i] != NULL){
//                this->push(temp[i]);
//            }
//        }
//        cout << "count: " << count << endl;
//        arraySize--;
//        initialSize++;
//        cout << "arraySize: "<< arraySize << endl;
//        cout << "initialSize :" << initialSize << endl;
//    }


};


#endif //PROJECT2_STACK_H
