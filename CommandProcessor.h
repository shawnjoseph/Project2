#pragma once
#include <string>
#include <sstream>
#include "Menu.h"
enum Command_States { Initial, Stack, Queue,  HashMap, Done };
using namespace std;

class CommandProcessor
{
public:
    static void Process_Commands();

private:
    static const int NR_CMD_STATES = (int)Done + 1;
    static Command_States command_state;
    static Menu* menus[NR_CMD_STATES];

    static void Create_Menus();
    static void Process_Initial_Cmd(const string& cmd);
//    static void ProcessCyclicLinkedList(const string& cmd);
//    static void ProcessDoublyLinkedList(const string& cmd);

    CommandProcessor(void) {};
};
