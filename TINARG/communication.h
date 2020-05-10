#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <stdio.h>
#include <iostream>
#include <zmq.h>
#include <string.h>

class Communication
{
public:
    Communication();
    ~Communication();
    void Recv_Message();
    void Send_Message( std::string data, std::string name_client );
    std::string Get_Name();
    std::string Get_Message();
private:
    void * context;
    void * context_2;

    std::string subs = "TINARG>action>";
    std::string send_Message;
    char recv_Message[256];
    int length, i;

    size_t pos = 0;

    void * pusher;
    void * subscriber;

    std::string msg_recv;
    std::string delim = ">";
    std::string name_Person;
    std::string message;
};

#endif // COMMUNICATION_H
