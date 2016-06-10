#include <iostream>
#include "DynStack.h"

using namespace std;

int main() {
    DynStack<int> * stack1 = new DynStack<int>();
    DynStack<int> * stack2 = new DynStack<int>(18);
    cout << "Stack is empty: ";
    stack1->isEmpty() == true ? cout << "Yes" << endl : cout << "No" << endl;
    stack1->capacity();
    stack2->capacity();
    stack1->push(20);
    stack1->push(30);
    stack1->push(50);
    stack1->push(80);
    stack1->push(20);
    stack1->push(30);
    stack1->push(50);
    stack1->push(80);
    stack1->push(20);
    stack1->push(30);
    stack1->push(50);
    stack1->push(80);
    stack1->push(20);
    stack1->push(30);
    stack1->push(50);
    stack1->push(80);
    stack1->push(20);
    stack1->push(30);
    stack1->push(50);
    stack1->push(80);
    stack1->size();
    stack1->capacity();
    cout << "Stack is empty: ";
    stack1->isEmpty() == true ? cout << "Yes" << endl : cout << "No" << endl;
    //stack1->top();
    cout << "Hello, World!" << endl;
    return 0;
}