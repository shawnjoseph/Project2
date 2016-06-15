#pragma once
#include <iostream>
#include "HashNode.h"

using namespace std;

template <class Key, class Value> class HashMap {
private:
    // To be filled in later
    int tableSize;
    const int COL = 2;
    int numOfEntries;
    double loadFactor;
    const double THRESHOLD = 0.5;
    Key hashResult;
    HashNode<Key, Value> **table;

public:

    HashMap() {
        tableSize = 10;
        // Create 2D array of pointers:
        table = new HashNode<Key, Value> *[tableSize];
//        for (int i = 0; i < tableSize; ++i) {
//            table[i] = new HashNode<Key, Value> *[COL];
//        }
        numOfEntries = 0;
        // Set all values to NULL as default
        for (int i = 0; i < tableSize; ++i) {
            for (int j = 0; j < COL; ++j) {
                table[i] = NULL;
            }
        }
    }

    ~HashMap() {
        // Fill this in later
    }


    Value *search(Key query) {
        // Searches for a value in the hashmap
        cout << "Search has been activated" << endl;
        hashResult = hash<Key>{}(query);

        /*
         * Ok listen up idiot
         * You can't query a fucking array by a string index
         * That's what the fuck you're trying to implement
         * So here's what you're gonna do tomorrow
         * Make the array 2 dimensional,
         * with the hash key being the first part and the
         * value being the second.
         *
         * Then, in search, loop through the array looking for one
         * that matches the hash in the [x][0]
         * then check if [x][1]->next is NULL
         *
         * With insert, just loop through the array and check
         * to see if the key is already in one of the [x][0]
         * if it isn't, just push a new value
         *
         * REDACTED DO NOT USE THIS ONE
         */


        /*
         * Ok NOW LISTEN
         * Don't listen to that guy up above
         * You don't need a 2 dimensional array, you've been working for too long
         * You need to just make a 1 dimensional array of HashNodes like you were
         * Except instead of making the index the hash result
         * Do the same thing you were where you loop through the array,
         * look for the HashNode with a matching key. Except do it like this
         * table[i]->key == hashResult
         * Duh
         *
         * Do that in the AM, get some sleep
         */

        for (int i = 0; i < tableSize; i++) {

            if (table[i]->getKey() == hashResult) {
                // If a result is found
                if ((table[i]->next) == NULL) {
                    // Means that there is more than one value there
                    HashNode<Key, Value> *ptr = table[i];
                    int arraySize = 0;
                    while (ptr != NULL) {
                        // Figuring out the size array should be
                        arraySize++;
                        ptr = ptr->next;
                    }
                    Value *result = new Value[arraySize];
                    ptr = table[i];
                    cout << "List of results: " << endl;
                    for (int j = 0; j < arraySize; j++) {
                        result[j] = ptr->getValue();
                        ptr = ptr->next;
                        cout << result[j] << endl;
                    }
                    return result;

                } else {
                    // Means there's only one value there
                    Value *result = new Value[1];
                    result[0] = table[i]->getValue();
                    return result;
                }
            }
        }
        // If no result is found
        cout << "Search query not found!" << endl;
        return NULL;
    }

    void insertValue(Key key, Value value) {
        // Inserts a value into the hashmap
        cout << "Insert has been activated" << endl;
        numOfEntries++;
        loadFactor = numOfEntries / tableSize;
        hashResult = hash<Key>{}(key);
        // Debugging
        cout << "Hash result is: " << hashResult << endl;
        for(int i=0; i < tableSize; i++) {
            if(table[i]->getKey() == hashResult) {
                table[i]->setValue(value);
            } else {
                // Means there's already a value in there,
                // must implement chaining
                HashNode<Key, Value> *ptr = table[i];
                while (ptr->next != NULL) {
                    // Just setting ptr to the last node
                }
                ptr->next = new HashNode<Key, Value>(hashResult, value);
            }
        }
        // Checking to see if need to increase size of HashMap
        if(loadFactor > THRESHOLD) {
            int oldTableSize = tableSize;
            tableSize *= 2;
            cout << "Resizing array to " << tableSize << endl;
            HashNode<Key, Value> **temp = table;
            table = new HashNode<Key, Value> *[tableSize];
//            for (int i = 0; i < tableSize; ++i) {
//                table[i] = new HashNode<Key, Value> *[COL];
//            }
            for(int i=0; i < oldTableSize; i++) {
                table[i] = temp[i];
            }
            delete temp;
        }

    }

    void deleteValue(Key key) {
        // Deletes a value from the hashmap
        for(int i=0; i < tableSize; i++) {
            if (table[i]->getKey() != hashResult) {
                if (table[i]->next != NULL) {
                    // There's more than one value
                    HashNode<Key, Value> *temp = table[i];
                    while (temp->next != NULL) {
                        HashNode<Key, Value> *toDelete = temp;
                        temp = temp->next;
                        delete (toDelete);
                    }
                    delete temp;
                }
            }
        }
        cout << "Delete has been activated" << endl;
    }
};

