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
    void Send_Chat( std::string data, std::string listener, std::string sender );
    std::string Get_Name();
    std::string Get_Message();
    std::string Get_Listener();
    std::string Get_Chat();
    std::string Get_Victim();
private:
    void * context;
    void * context_2;
    void * context_3;
    void * context_4;

    std::string subs = "TINARG>action>";
    std::string send_Message;
    char recv_Message[256];
    int length, i;

    size_t pos = 0;

    void * pusher;
    void * subscriber;
    void * chatter;
    void * smitter;

    std::string msg_recv;
    std::string delim = ">";
    std::string name_Person;
    std::string message;
    std::string listener;
    std::string chat_msg;
    std::string smite_victim;
};

#endif // COMMUNICATION_H
