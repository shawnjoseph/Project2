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
    bool isEmpty() const {
        if (count == 0) {
            cout << "Yes. Stack is Empty.\n";
        } else {
            "No. Stack is Not Empty.\n";
        }
        return count == 0;
    }
//
    void display() {
        if(count == 0){ cout << "Stack is empty\n" << endl; }
        else
            for(int i = myTop; i >= 0; i--){
                cout << "#" << myTop + 1 - i << " " << array[i] << endl;
            };
 }

    void push(Type const & data) {
        if (myTop < arraySize - 1) {
            myTop++;
            count++;
            array[myTop] = data;
        }
        else
        {
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
                temp[i] = array[i];
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
        int counter = 0;
        Type *temp = new Type[arraySize];
        for(int i = 0, j=0; i < arraySize; i++, j++){
            Type tmp_val = array[i];
            if(tmp_val != data ){
                temp[j] = tmp_val;
            }
            else{
                j--;
                counter++;
                myTop--;
            }
        }

        delete [] array;
        array = temp;

        if (myTop == arraySize / 4) {
            arraySize = arraySize / 2;
            Type *temp2;
            temp2 = new Type[arraySize];

            for (int i = 0; i < count; i++) {
                temp2[i] = array[i];
            }
            delete[] array;
            array = temp2;
        }
        return counter;
    }


};


#endif //PROJECT2_STACK_H
