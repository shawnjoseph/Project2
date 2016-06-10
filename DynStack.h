#ifndef PROJECT2_STACK_H
#define PROJECT2_STACK_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <class Type> class DynStack {
private:
    DynStack<Type> * array;
    int count,
        initialSize,
        arraySize;

public:
    DynStack()
            : count(0), initialSize(13), arraySize(13)
    {}

    DynStack(int initialSize)
            :count(0)
    {
        this->initialSize = initialSize;
        arraySize = initialSize;
    }

    ~DynStack(){
        delete [] array;
    }

    Type top() const {
        if(count == 0){ throw 404;}
        return this->arraySize;
    }
//
    int size() const {cout << count << endl; return count; }
//
    int capacity() const { cout << "Cap :" << initialSize << endl; return initialSize; }
//
    bool isEmpty() const { return count == 0; }
//
//    void Display() const {}

    void push(Type const & data) {
        if (count == initialSize) {
            initialSize = initialSize * 2;
            cout << "initialSize changed. " << initialSize << endl;
            DynStack<Type> *temp = new DynStack<Type>(initialSize);
            for (int i = count; i > 0 ; i--) {
                temp[i*2] = array[i];
            }
            delete[] array;
            array = temp;
            count++;
            this->arraySize = data;
            arraySize--;
        }
        else{
            count++;
            this->arraySize = data;
            arraySize--;
        }
    }
//
//    Type pop() {                    //Add Underflow Exception
//        Type * tmp = array[arraySize];
//        Type value = tmp;
//        if(arraySize != -1){
//            arraySize--;
//            if(count <= (arraySize/2) && arraySize > initialSize){
//                Type * temp = new DynStack(arraySize/2);
//                for(int i = 0; i < arraySize; i++){
//                    temp[i] = array[i];
//                }
//                delete [] array;
//                array = temp;
//            }
//        }
//        delete tmp;
//        return value;
//    }
//
//    void clear() {
//        Type * tmp = array[arraySize];
//
//        while(tmp != nullptr){
//            tmp = array[arraySize];
//            if(arraySize != -1){
//                arraySize--;
//            }
//            delete tmp;
//        }
//
//    }

//    int erase (Type const & data) {
//        Type * temp = new DynStack(arraySize);
//        if(array[arraySize] == data){
//            pop();
//        }
//    }

};


#endif //PROJECT2_STACK_H
