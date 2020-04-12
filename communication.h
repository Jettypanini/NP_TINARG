#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <iostream>
#include <bits/stdc++.h>
#include <string>

class Communication
{
public:
    Communication();
    std::string Recv_Message();
    void Send_Message( std::string data );
private:
    std::string incoming;
    std::string message;
};

#endif // COMMUNICATION_H
