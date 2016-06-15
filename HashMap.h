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
    HashNode<Key, Value> ***table;

public:

    HashMap() {
        tableSize = 10;
        // Create 2D array of pointers:
        table = new HashNode<Key, Value> **[tableSize];
        for (int i = 0; i < tableSize; ++i) {
            table[i] = new HashNode<Key, Value> *[COL];
        }
        numOfEntries = 0;
        // Set all values to NULL as default
        for (int i = 0; i < tableSize; ++i) {
            for (int j = 0; j < COL; ++j) {
                table[i][j] = NULL;
            }
        }
    }

    ~HashMap() {
        // Fill this in later
    }


    Value search(Key query) {
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
         */

        for (int i = 0; i < tableSize; i++) {

            if (table[i][0] == hashResult) {
                // If a result is found
                if ((table[i][1]->next) == NULL) {
                    // Means that there is more than one value there
                    HashNode<Key, Value> *ptr = table[i][1];
                    int arraySize = 0;
                    while (ptr != NULL) {
                        // Figuring out the size array should be
                        arraySize++;
                        ptr = ptr->next;
                    }
                    Value *result[arraySize];
                    ptr = table[i][1];
                    cout << "List of results: " << endl;
                    for (int j = 0; j < arraySize; j++) {
                        *result[j] = *ptr;
                        ptr = ptr->next;
                        cout << *result[j] << endl;
                    }
                    return result;

                } else {
                    // Means there's only one value there
                    Value result = table[i][1];
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
            if(*(table[i][0]) == hashResult) {
                table[i][1] = value;
            } else {
                // Means there's already a value in there,
                // must implement chaining
                HashNode<Key, Value> *ptr = table[i][1];
                while (ptr->next != NULL) {
                    // Just setting ptr to the last node
                }
                ptr->next = value;
            }
        }
        // Checking to see if need to increase size of HashMap
        if(loadFactor > THRESHOLD) {
            int oldTableSize = tableSize;
            tableSize *= 2;
            cout << "Resizing array to " << tableSize << endl;
            HashNode<Key, Value> ***temp = table;
            table = new HashNode<Key, Value> **[tableSize];
            for (int i = 0; i < tableSize; ++i) {
                table[i] = new HashNode<Key, Value> *[COL];
            }
            for(int i=0; i < oldTableSize; i++) {
                table[i] = temp[i];
            }
            delete temp;
        }

    }

    void deleteValue(Key key) {
        // Deletes a value from the hashmap
        for(int i=0; i < tableSize; i++) {
            if (table[i][0] != hashResult) {
                if (table[i][1]->next != NULL) {
                    // There's more than one value
                    HashNode<Key, Value> *temp = table[i][1];
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

    bool operator==(HashNode<Key, Value>& a) {
        return (this == a);
    }
};

