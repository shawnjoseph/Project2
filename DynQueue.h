#ifndef PROJECT2_DYNQUEUE_H
#define PROJECT2_DYNQUEUE_H

#include <iostream>

using namespace std;

template<class Type>
class DynQueue {
private:
    Type *array;
    int ihead;
    int itail;
    int count;
    int initialSize;
    int arraySize;

public:
    DynQueue() :
            initialSize(13), count(0), arraySize(initialSize), ihead(-1), itail(-1) {
        array = new Type[initialSize];
    }

    DynQueue(int initialSize)
            : count(0), ihead(-1), itail(-1) {
        this->initialSize = initialSize;
        arraySize = initialSize;
        array = new Type[initialSize];
    }

    ~DynQueue() {
        delete[] array;
        count = 0;
        ihead = -1;
        itail = -1;
    }

    Type front() const {
        if(empty()) {
            cerr << "Error. Queue is Empty." << endl;
        }
        else
            cout << "Front: " << array[ihead] << endl;
            return array[ihead];
        }

    Type back() const {
        if(empty()) {
            cerr << "Error. Queue is Empty." << endl;
        }
        else
            cout << "Back: " << array[itail] << endl;
        return array[itail];
    }

    int size() const {
        cout << "Size: " << count << endl;
        return count;
    }

    int capacity() const {
        cout << "Capacity: " << arraySize << endl;
        return arraySize;
    }

    bool empty() const { return count == 0; }

    void display() {
        if(empty()){
            cerr << "Error. Queue is Empty." << endl;
        }
        else{
            for (int i = count - 1; i >= 0; i--) {
                cout << array[i] << " -> ";
            }
            cout << "\n";
        }

    }

    void enqueue(Type const &data) {
        if (count < arraySize - 1) {
            ihead = 0;
            itail = count;
            array[count] = data;
            count++;
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
            array[count] = data;
            count++;
        }
    }

    Type dequeue() {
        Type val = array[ihead];
        if (empty()) {
            cerr << "Error. Queue is Empty." << endl;
        }
        else {
            for (int i = 0; i < count; i++) {
                array[i] = array[i + 1];
            }
            count--;
            itail = count - 1;
        }
        if (count == arraySize / 4) {
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
        Type * temp;
        temp = new Type[initialSize];
        DynQueue::~DynQueue();
        arraySize = initialSize;
        array = temp;
    }

    int erase(Type const &data) {
        int counter = 0;
        int size = count;
        Type *temp = new Type[arraySize];
        for (int i = 0, j = 0; i < size; i++, j++) {
            Type tmp_val = array[i];
            if(tmp_val != data ){
                temp[j] = tmp_val;
            }
            else{
                j--;
                counter++;
                count--;
            }
        }
        delete [] array;
        array = temp;

        if (count == arraySize / 4) {
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


#endif //PROJECT2_DYNQUEUE_H
