#ifndef TINARG_H
#define TINARG_H

#include "commands.h"

#include <iostream>
#include <string>

class TINARG
{
public:
    TINARG();
    void Start_Game();
private:
    Commands *Command = new Commands();
    std::string game;
    bool Start_Okay = FALSE;
};

#endif // TINARG_H
