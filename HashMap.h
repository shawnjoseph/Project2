#pragma once
#include <iostream>
using namespace std;

template <class Type> class HashMap {
private:
    // To be filled in later
public:
    Type search(Type query) {
        // Searches for a value in the hashmap
        cout << "Search has been activated" << endl;
    }

    void insertValue(Type value) {
        // Inserts a value into the hashmap
        cout << "Insert has been activated" << endl;
    }

    void deleteValue(Type value) {
        // Deletes a value from the hashmap
        cout << "Delete has been activated" << endl;
    }


};