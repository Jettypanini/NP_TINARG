#ifndef TINARG_H
#define TINARG_H

#include "communication.h"

#include <iostream>
#include <string>

class TINARG
{
public:
    TINARG();
    void Start_Game();
private:
    Communication *Talk;

    std::string name_recv;
    std::string message_recv;
};

#endif // TINARG_H
