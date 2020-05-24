#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

#include <statistics.h>

class Commands
{
public:
    Commands();
    short Dice();
    std::string interaction( Statistics * stats );
    std::string Get_Command( short pos );
private:
    std::map<std::string, short> Commands_List;
    std::map<std::string, short>::iterator it;

    std::string command;
    std::string interaction_msg;
};

#endif // COMMANDS_H
