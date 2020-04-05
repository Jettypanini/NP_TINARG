#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <string>

#define TRUE 1
#define FALSE 0

class Commands
{
public:
    Commands();
    void Print_Start_Com();
private:
    std::string Start_Commands[2][2] = { { "new",       "When you're new to the game" },
                                         { "continue",  "When you already played this game before" } };
    std::string tabs;
};

#endif // COMMANDS_H
