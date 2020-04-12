#ifndef TINARG_H
#define TINARG_H

#include "commands.h"
#include "communication.h"
#include "player_stats.h"

#include <iostream>
#include <string>

class TINARG
{
public:
    TINARG();
    void Start_Game();
private:
    Commands *Command;
    Communication *Talk;
    Player_Stats *statistics;
    std::string game;
    std::string login_name;
    std::string new_password;
    bool Start_Okay = FALSE;
};

#endif // TINARG_H
