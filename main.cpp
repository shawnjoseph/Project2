#include <iostream>
#include "DynQueue.h"
#include "CommandProcessor.h"

using namespace std;

int main() {
//    CommandProcessor::Process_Commands();
    DynQueue<int> * queue1 = new DynQueue<int>(12);
    queue1->clear();
    queue1->enqueue(30);
    queue1->enqueue(20);
    queue1->enqueue(20);
    queue1->enqueue(30);
    queue1->enqueue(30);
    queue1->enqueue(20);
    queue1->enqueue(20);
    queue1->enqueue(30);
    queue1->size();
    queue1->capacity();
    queue1->empty();
    queue1->display();
    queue1->front();
    queue1->back();
    queue1->erase(20);
    queue1->size();
    queue1->display();
    return 0;
}