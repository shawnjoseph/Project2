#pragma once
#include <iostream>
#include "HashNode.h"

using namespace std;

template <class Key, class Value> class HashMap {
private:
    // To be filled in later
    int tableSize;
    int numOfEntries;
    double loadFactor;
    const double THRESHOLD = 0.5;
    Key hashResult;

    HashNode<Key, Value> **table;

public:

    HashMap() {
        tableSize = 10;
        table = new HashNode<Key, Value> *[tableSize]();
        numOfEntries = 0;
        // Set all values to NULL as default
        for(int i=0; i < 10; i++) {
            table[i] = NULL;
        }
    }

    ~HashMap() {
        // Fill this in later
    }


    Value search(Key query) {
        // Searches for a value in the hashmap
        cout << "Search has been activated" << endl;
        hashResult = hash<Key>{}(query);
        if(table[hashResult] != NULL) {
            // If a result is found
            if(table[hashResult]->next != NULL) {
                // Means that there is more than one value there
                HashNode<Key, Value> *ptr = table[hashResult];
                int arraySize = 0;
                while(ptr != nullptr) {
                    // Figuring out the size array should be
                    arraySize++;
                    ptr = ptr->next;
                }
                Value *result[arraySize];
                ptr = table[hashResult];
                cout << "List of results: " << endl;
                for(int i=0; i < arraySize; i++) {
                    *result[i] = *ptr;
                    ptr = ptr->next;
                    cout << *result[i] << endl;
                }
                return result;

            } else {
                // Means there's only one value there
                Value result = table[hashResult];
                return result;
            }
        } else {
            cout << "Search query not found!" << endl;
            return NULL;
        }
    }

    void insertValue(Key key, Value value) {
        // Inserts a value into the hashmap
        cout << "Insert has been activated" << endl;
        numOfEntries++;
        loadFactor = numOfEntries / tableSize;
        hashResult = hash<Key>{}(key);
        // Debugging
        cout << "Hash result is: " << hashResult << endl;

        if(*(table[hashResult]) == NULL) {
            table[hashResult] = value;
        } else {
            // Means there's already a value in there,
            // must implement chaining
            HashNode<Key, Value> *ptr = table[hashResult];
            while(ptr->next != nullptr) {
                // Just setting ptr to the last node
            }
            ptr->next = value;
        }

        // Checking to see if need to increase size of HashMap
        if(loadFactor > THRESHOLD) {
            int oldTableSize = tableSize;
            tableSize *= 2;
            cout << "Resizing array to " << tableSize << endl;
            HashNode<Key, Value> **temp = table;
            table = new HashNode<Key, Value> *[tableSize];
            for(int i=0; i < oldTableSize; i++) {
                table[i] = temp[i];
            }
            delete temp;
        }

    }

    void deleteValue(Key key) {
        // Deletes a value from the hashmap
        if(table[hashResult] != NULL) {
            if(table[hashResult]->next != NULL) {
                // There's more than one value
                HashNode<Key, Value> *temp = table[hashResult];
                while(temp->next != NULL) {
                    HashNode<Key, Value> *toDelete = temp;
                    temp = temp->next;
                    delete(toDelete);
                }
                delete temp;
            }
        }
        cout << "Delete has been activated" << endl;
    }


};