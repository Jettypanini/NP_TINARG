#ifndef TINARG_H
#define TINARG_H

#include "communication.h"
#include "statistics.h"
#include "commands.h"

#include <iostream>
#include <string>
#include <map>
#include <iterator>

class TINARG
{
public:
    TINARG();
    void Start_Game();
private:
    Communication *Talk;
    Commands *Command;

    std::map<std::string, Statistics*> stats;
    std::map<std::string, Statistics*>::iterator it;

    std::string name_recv;
    std::string message_recv;
    std::string message_appended;
    std::string attack_victim;

    bool found;
    short pos, dice, i;
};

#endif // TINARG_H
