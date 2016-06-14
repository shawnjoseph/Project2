#pragma once
#include <iostream>
using namespace std;

template <class Key, class Value> class HashMap {
private:
    // To be filled in later
    int size;
    int loadFactor;

public:

    HashMap() {
        
        size = 0;
    }


    Value search(Key query) {
        // Searches for a value in the hashmap
        cout << "Search has been activated" << endl;

    }

    void insertValue(Key key) {
        // Inserts a value into the hashmap
        cout << "Insert has been activated" << endl;
    }

    void deleteValue(Key key) {
        // Deletes a value from the hashmap
        cout << "Delete has been activated" << endl;
    }


};