#pragma once
#include <string>
#include <sstream>
#include "Menu.h"
#include "DynStack.h"
#include "HashMap.h"
#include "DynQueue.h"
enum Command_States { Initial, Stack, Queue, HashTable, Done };
using namespace std;

class CommandProcessor
{
public:
    static void Process_Commands();

private:
    static const int NR_CMD_STATES = (int)Done;
    static Command_States command_state;
    static Menu* menus[NR_CMD_STATES];

    static void Create_Menus();
    static void Process_Initial_Cmd(const string& cmd);
    static void ProcessStack(const string& cmd);
    static void ProcessQueue(const string& cmd);
    static void ProcessHashTable(const string& cmd);


    CommandProcessor(void) {};
};
