#include <iostream>
#include "CommandProcessor.h"

using namespace std;

int main() {
//    DynStack<int> * stack1 = new DynStack<int>();
//    DynStack<int> * stack2 = new DynStack<int>(12);
//    stack2->push(1);
//    stack2->push(10);
//    stack2->push(100);
//    stack2->push(1);
//    stack2->push(100);
//    stack2->push(10);
//    stack2->push(1);
//    stack2->push(100);
//    stack2->push(999);
//    stack2->push(99);
////    stack2->push(9);
//    stack2->push(999);
//    stack2->push(99);
//    stack2->push(9);
////    stack2->pop();
////    stack2->Display();
////    stack2->erase(1);
//    stack2->display();
////    stack1->isEmpty() == true ? cout << "Yes" << endl : cout << "No" << endl;
////    cout << "Hello, World!" << endl;
    CommandProcessor::Process_Commands();
    return 0;
}