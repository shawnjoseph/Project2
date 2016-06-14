#ifndef PROJECT2_STACK_H
#define PROJECT2_STACK_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <class Type> class DynStack {
private:
    Type * array = nullptr;
    int count,
        initialSize,
        arraySize;

public:
    DynStack()
            : count(0), initialSize(13), arraySize(initialSize - 1)
    {
        array = new Type[initialSize];
    }

    DynStack(int initialSize)
            :count(0)
    {
        this->initialSize = initialSize;
        arraySize = initialSize - 1;
        array = new Type[initialSize];
    }

    ~DynStack(){
        delete [] array;
    }

    Type top() const {
        if(count == 0){ cout << "Error Stack Empty" << endl; }
        return this->array[arraySize + 1];
    }
//
    int size() const {cout << "Size: " << count << endl; return count; }
//
    int capacity() const { cout << "Cap :" << initialSize << endl; return initialSize; }
//
    bool isEmpty() const { return count == 0; }
//
    void Display() {
        if(count == 0){ cout << "Stack is empty" << endl; }
        else
            for(int i = arraySize; i < initialSize; i++){
                if(array[i] == NULL){ continue; } //counts past top
                cout << "#" << i << " " << array[i] << endl;
            };
 }

    void push(Type const & data) {
        if (count == initialSize) {
            initialSize = initialSize * 2;
            Type * temp ;
            temp = new Type[initialSize];
            for (int i = 0; i < count; i++) {
                temp[initialSize - 1 - i] = array[count - 1 - i];
            }
            delete[] array;
            array = temp;
            arraySize = count - 1;
            count++;
            this->array[arraySize] = data;
            arraySize--;
        }
        else{
            count++;
            this->array[arraySize] = data;
            arraySize--;
        }
    }

    Type pop() {                    //Add Underflow Exception
        Type value = array[arraySize + 1];
        array[arraySize + 1] = array[arraySize++];
        count--;
        if(count == initialSize/4){

            initialSize = initialSize/2;
            arraySize = arraySize/2 - 2;
            Type * temp ;
            temp = new Type[initialSize];
            for (int i = 0; i < count; i++) {
                temp[initialSize - 1 - i] = array[initialSize*2 - 1 - i];
            }
            delete [] array;
            array = temp;
        }
        return value;
    }

    void clear() {
        Type * temp = new Type[initialSize];
        DynStack::~DynStack();
        array = temp;
        arraySize = initialSize - 1;
        }

    int erase (Type const & data) {
        int i = initialSize - 1;
        Type * temp = new Type[initialSize];
        while(top() != NULL){
            int tmp_val;
            tmp_val = pop();
            if(tmp_val != data){
                temp[i] = tmp_val;
            }
            i--;
        }           //Work on getting values in temp back to array
//        delete [] array;
//        array = temp;
//        cout << "arraySize: " << arraySize << endl;
//        cout << "initialSize: " << initialSize << endl;
//        cout << "count : " << count << endl;
//        for(int i = 0; i < initialSize; i++){
//            array[initialSize - 1 - i] = temp[i];
//        }
//        delete temp;
    }

};


#endif //PROJECT2_STACK_H
