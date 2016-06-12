#include <iostream>
#include "DynStack.h"

using namespace std;

int main() {
    DynStack<int> * stack1 = new DynStack<int>();
    DynStack<int> * stack2 = new DynStack<int>(3);
    cout << "Stack is empty: ";
    stack1->isEmpty() == true ? cout << "Yes" << endl : cout << "No" << endl;
//    stack1->capacity();
    stack2->push(1);
    stack2->push(10);
    stack2->push(100);
    stack2->push(1);
    stack2->push(10);
    stack2->push(100);
    stack2->push(1);
    cout << "Top :" << stack2->top() << endl;
    cout << "Pop :" << stack2->pop() << endl;
    stack2->push(10);
    cout << "Top :" << stack2->top() << endl;
    stack2->push(100);
    stack2->push(1);
    cout << "Pop :" << stack2->pop() << endl;
    cout << "Top :" << stack2->top() << endl;
    stack2->push(10);
    stack2->push(100);
    stack1->capacity();
    stack1->size();
    stack1->Display();
//    stack2->Display();
    stack1->isEmpty() == true ? cout << "Yes" << endl : cout << "No" << endl;
    cout << "Hello, World!" << endl;
    return 0;
}