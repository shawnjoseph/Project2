#include <iostream>
#include "CommandProcessor.h"


using namespace std;

Command_States CommandProcessor::command_state = Initial;

Menu *CommandProcessor::menus[NR_CMD_STATES];

// Create Stack, Queue, HashMap here
DynStack<string> *stack = new DynStack<string>();
DynQueue<string> *queue = new DynQueue<string>();
HashMap<string, string> *hashMap = new HashMap<string, string>();


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
        cout << "Top: " << stack->top() << endl;
    } else if (cmd == "Get Size") {
        stack->size();
    } else if (cmd == "Is List Empty") {
        stack->isEmpty();
    } else if (cmd == "Get Capacity/Array Size") {
        stack->capacity();
    } else if (cmd == "Display Stack") {
        stack->display();
    } else if (cmd == "Push") {
        string input;
        cout << "Enter value: " << endl;
        getline(cin, input);
        stack->push(input);
    } else if (cmd == "Pop") {
        stack->pop();
    } else if (cmd == "Clear") {
        stack->clear();
    } else if (cmd == "Erase") {
        string input;
        cout << "Enter value to erase from stack: " << endl;
        getline(cin, input);
        cout << stack->erase(input) << " values were erased." << endl;
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
        if (queue->empty()) {
            cout << "Queue is Empty." << endl;
        } else {
            cout << "Queue is not Empty." << endl;
        }
    } else if (cmd == "Get Capacity/Array Size") {
        queue->capacity();
    } else if (cmd == "Display Queue") {
        queue->display();
    } else if (cmd == "Enqueue") {
        string input;
        cout << "Enter value to enqueue: " << endl;
        getline(cin, input);
        queue->enqueue(input);
    } else if (cmd == "Dequeue") {
        queue->dequeue();
    } else if (cmd == "Clear") {
        queue->clear();
    } else if (cmd == "Erase") {
        string input;
        cout << "Enter value to erase from queue: " << endl;
        getline(cin, input);
        cout << queue->erase(input) << " values were erased." << endl;
    } else if (cmd == "Exit") {
        exit(0);
    } else {
        cout << "Error" << endl;
    }
}


void CommandProcessor::ProcessHashTable(const string &cmd) {
    if (cmd == "Insert") {
        string key;
        cout << "Enter key value of node: " << endl;
        getline(cin, key);
        string value;
        cout << "Enter value of node: " << endl;
        getline(cin, value);
        hashMap->insertValue(key, value);
        hashMap->print();
    } else if (cmd == "Delete") {
        string key;
        cout << "Enter key to delete: " << endl;
        getline(cin, key);
        hashMap->deleteValue(key);
        hashMap->print();
    } else if (cmd == "Search") {
        string key;
        cout << "Enter key to search for: " << endl;
        getline(cin, key);
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
