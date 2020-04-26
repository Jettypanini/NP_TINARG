#include <stdio.h>
#include <iostream>
#include <zmq.h>
#include <string.h>
#include <string>

void * context; //Global context, because you only need one !
void * context_2;

int main( int argc, char * argv[] )
{
    context = zmq_ctx_new();
    context_2 = zmq_ctx_new();

    char send_Message[256] = "TINARG>action>" ;
    char recv_Message[256];
    int length_recv, length_send, i;
    std::string s;
    std::string name;
    std::string msg_recv;
    std::string message;

    std::cout << "What's your name?" << std::endl;
    std::cin >> name;
    system("cls");
    char subs[name.length()+17];

    strcpy( subs, "TINARG>reaction>" );
    strcat( subs, name.c_str() );
    strcat( subs, ">" );

    void * pusher = zmq_socket( context, ZMQ_PUSH );
    zmq_connect( pusher, "tcp://benternet.pxl-ea-ict.be:24041" );

    void * subscriber = zmq_socket( context_2, ZMQ_SUB );
    zmq_connect( subscriber, "tcp://benternet.pxl-ea-ict.be:24042" );
    zmq_setsockopt( subscriber, ZMQ_SUBSCRIBE, subs, strlen(subs) );

    std::cout << "Welcome to the game of TINARG!" << std::endl;
    std::cout << "Please type start to start the game." << std::endl;

    for(;;)
    {
        strcpy( send_Message, "TINARG>action>" );
        strcpy( recv_Message, "" );
        msg_recv = "";

        std::cout << name << ">";
        length_send = sizeof(send_Message);
        std::cin >> s;

        char temp[s.length()+1];
        strcpy( temp, s.c_str() );

        strcat( send_Message, name.c_str() );
        strcat( send_Message, ">" );
        length_send += name.length() + 1;
        strcat( send_Message, temp );
        length_send += sizeof(temp);

        zmq_send( pusher, send_Message, length_send, 0 );

        length_recv = zmq_recv( subscriber, recv_Message, 256, 0 );

        msg_recv = recv_Message;

        msg_recv.erase(0, msg_recv.find(">") + 1);
        msg_recv.erase(0, msg_recv.find(">") + 1);
        msg_recv.erase(0, msg_recv.find(">") + 1);
        message = msg_recv.substr( 0, msg_recv.find(">") );
        std::cout << message << std::endl << std::endl;
    }

    zmq_close( pusher );
    zmq_close( subscriber );
    zmq_ctx_shutdown( context ); //optional for cleaning lady order (get ready you l*zy f*ck)
    zmq_ctx_term( context ); //cleaning lady goes to work
    zmq_ctx_shutdown( context_2 ); //optional for cleaning lady order (get ready you l*zy f*ck)
    zmq_ctx_term( context_2 );
    return 0;
}
