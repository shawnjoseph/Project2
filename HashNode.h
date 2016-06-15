#pragma once
#include <iostream>

template <class Key, class Value> class HashNode {
private:
    Key key;
    Value value;
public:
    HashNode *next;
    HashNode(Key key, Value value) {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    Key getKey() {
        return key;
    }

    Value getValue() {
        return value;
    }
};