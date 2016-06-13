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
    void Display() const {
        if(count == 0){ cout << "Stack is empty" << endl; }
        else
            for(int i = arraySize; i < initialSize; i++){
                if(array[i] == NULL){ continue; } //counts past top
                cout << "#" << i + 1 << " : " << array[i] << endl;
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
        array[arraySize++] = array[arraySize++];
        count--;
        if(count == initialSize/4){

            initialSize = initialSize/2;
            Type * temp ;
            temp = new Type[initialSize];
            for (int i = 0; i < count; i++) {
                temp[initialSize - 1 - i] = array[initialSize*2 - 1 - i];
                cout << i + 1 << " : " << temp[initialSize - 1 - i] << endl;
            }
            delete [] array;
            array = temp;
        }
        return value;
    }

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
