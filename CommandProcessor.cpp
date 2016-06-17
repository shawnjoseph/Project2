#include <iostream>
#include "CommandProcessor.h"


using namespace std;

Command_States CommandProcessor::command_state = Initial;

Menu *CommandProcessor::menus[NR_CMD_STATES];

// Create Stack, Queue, HashMap here
DynStack<double> *stack = new DynStack<double>();
DynQueue<double> *queue = new DynQueue<double>();
HashMap<int, int> *hashMap = new HashMap<int, int>();


void CommandProcessor::Process_Commands() {
    cout << "Process commands starting\n";


    Create_Menus();

    while (command_state != Done) {
        const string *cmd = menus[command_state]->Get_Command();

        switch (command_state) {
            case Initial:
                Process_Initial_Cmd(*cmd);
                break;

            case Stack:
                ProcessStack(*cmd);
                break;

            case Queue:
                ProcessQueue(*cmd);
                break;


            case HashTable:
                ProcessHashTable(*cmd);
                break;

            case Done:
                break;      // Can't happen
        }
    }

    cout << "Command_Processor exiting\n";
    // Process command in Initial command state

}

void CommandProcessor::Process_Initial_Cmd(const string &cmd) {
    if (cmd == "Stack") {
        command_state = Stack;
    }
    else if (cmd == "Queue") {
        command_state = Queue;
    }
    else if (cmd == "HashTable") {
        command_state = HashTable;
    }
    else {
        cout << "Quit command\n";
        command_state = Done;
    }
}

void CommandProcessor::ProcessStack(const string &cmd) {
    if (cmd == "Return Top Element") {
        stack->top();
    } else if (cmd == "Get Size") {
        stack->size();
    } else if (cmd == "Is List Empty") {
        stack->isEmpty();
    } else if (cmd == "Get Capacity/Array Size") {
        stack->capacity();
    } else if (cmd == "Display Stack") {
        stack->display();
    } else if (cmd == "Push") {
        double input;
        cout << "Enter value: " << endl;
        cin >> input;
        stack->push(input);
    } else if (cmd == "Pop") {
        stack->pop();
    } else if (cmd == "Clear") {
        stack->clear();
    } else if (cmd == "Erase") {
        double input;
        cout << "Enter value to erase from stack: " << endl;
        cin >> input;
        stack->erase(input);
    } else if (cmd == "Exit") {
        exit(0);
    } else {
        cout << "Error" << endl;
    }
}

void CommandProcessor::ProcessQueue(const string &cmd) {
    if (cmd == "Return Front Object") {
        queue->front();
    } else if (cmd == "Return Back Object") {
        queue->back();
    } else if (cmd == "Get Size") {
        queue->size();
    } else if (cmd == "Is List Empty") {
        queue->empty();
    } else if (cmd == "Get Capacity/Array Size") {
        queue->capacity();
    } else if (cmd == "Display Queue") {
        queue->display();
    } else if (cmd == "Enqueue") {
        double input;
        cout << "Enter double to enqueue: " << endl;
        cin >> input;
        queue->enqueue(input);
    } else if (cmd == "Dequeue") {
        queue->dequeue();
    } else if (cmd == "Clear") {
        queue->clear();
    } else if (cmd == "Erase") {
        double input;
        cout << "Enter value to erase from queue: " << endl;
        cin >> input;
        queue->erase(input);
    } else if (cmd == "Exit") {
        exit(0);
    } else {
        cout << "Error" << endl;
    }
}


void CommandProcessor::ProcessHashTable(const string &cmd) {
    if (cmd == "Insert") {
        int key;
        cout << "Enter key value of node: " << endl;
        cin >> key;
        int value;
        cout << "Enter value of node: " << endl;
        cin >> value;
        getchar();
        hashMap->insertValue(key, value);
        hashMap->print();
    } else if (cmd == "Delete") {
        int key;
        cout << "Enter key to delete: " << endl;
        cin >> key;
        getchar();
        hashMap->deleteValue(key);
        hashMap->print();
    } else if (cmd == "Search") {
        int key;
        cout << "Enter key to search for: " << endl;
        cin >> key;
        getchar();
        hashMap->search(key);
    } else if (cmd == "Print") {
        hashMap->print();
    } else if (cmd == "Exit") {
        exit(0);
    } else {
        cout << "Error" << endl;
    }
}

void CommandProcessor::Create_Menus() {
    // Menu for Initial command state
    Menu *menu = new Menu("Which linked list do you want to create?");
    menu->Add_Command("Stack");
    menu->Add_Command("Queue");
    menu->Add_Command("HashTable");
    menu->Add_Command("Cancel");

    menus[Initial] = menu;

    //Menu for Stack
    menu = new Menu("Enter command number:\n");
    menu->Add_Command("Return Top Element");
    menu->Add_Command("Get Size");
    menu->Add_Command("Is List Empty");
    menu->Add_Command("Get Capacity/Array Size");
    menu->Add_Command("Display Stack");
    menu->Add_Command("Push");
    menu->Add_Command("Pop");
    menu->Add_Command("Clear");
    menu->Add_Command("Erase");
    menu->Add_Command("Exit");
    menus[Stack] = menu;

    //Menu for Queue
    menu = new Menu("Enter command number:\n");
    menu->Add_Command("Return Front Object");
    menu->Add_Command("Return Back Object");
    menu->Add_Command("Get Size");
    menu->Add_Command("Is List Empty");
    menu->Add_Command("Get Capacity/Array Size");
    menu->Add_Command("Display Queue");
    menu->Add_Command("Enqueue");
    menu->Add_Command("Dequeue");
    menu->Add_Command("Clear");
    menu->Add_Command("Erase");
    menu->Add_Command("Exit");
    menus[Queue] = menu;

    //Menu for HashMap
    menu = new Menu("Enter command number:\n");
    menu->Add_Command("Insert");
    menu->Add_Command("Delete");
    menu->Add_Command("Search");
    menu->Add_Command("Print");
    menu->Add_Command("Exit");
    menus[HashTable] = menu;
}
