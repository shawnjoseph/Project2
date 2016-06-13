#include <iostream>
#include "DynStack.h"

using namespace std;

int main() {
    DynStack<int> * stack1 = new DynStack<int>();
    DynStack<int> * stack2 = new DynStack<int>(12);
    stack2->push(1);
    stack2->push(10);
    stack2->push(100);
    stack2->push(1);
//    stack2->push(10);
//    stack2->push(100);
//    stack2->push(1);
//    stack2->push(10);
//    stack2->push(100);
//    stack2->push(1);
//    stack2->push(10);
//    stack2->push(100);
//    stack2->push(1);
//    stack2->push(10);
//    stack2->push(100);
//    stack2->push(1);
//    stack2->push(10);
//    stack2->push(100);
//    stack2->push(1);
//    stack2->push(10);
//    stack2->push(100);
//    stack2->push(1);
//    stack2->push(10);
//    stack2->push(100);
//    stack2->Display();
    cout << "Popped: " << stack2->pop() << endl;
//    stack2->push(100);
//    stack2->Display();
//    stack1->isEmpty() == true ? cout << "Yes" << endl : cout << "No" << endl;
//    cout << "Hello, World!" << endl;
    return 0;
}