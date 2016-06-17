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

    void setValue(Value value) {
        this->value = value;
    }

    void setKey(Key key) {
        this->key = key;
    }


    bool operator==(HashNode<Key, Value>& a) {
        return (this->key == a.key);
    }
};