#include "communication.h"

Communication::Communication()
{
    context = zmq_ctx_new();
    pusher = zmq_socket( context, ZMQ_PUSH );
    zmq_connect( pusher, "tcp://benternet.pxl-ea-ict.be:24041" );

    context_2 = zmq_ctx_new();
    subscriber = zmq_socket( context_2, ZMQ_SUB );
    zmq_connect( subscriber, "tcp://benternet.pxl-ea-ict.be:24042" );
    zmq_setsockopt( subscriber, ZMQ_SUBSCRIBE, subs, strlen(subs) );
}

Communication::~Communication()
{
    zmq_close( pusher );
    zmq_close( subscriber );
    zmq_ctx_shutdown( context );
    zmq_ctx_term( context );
    zmq_ctx_shutdown( context_2 );
    zmq_ctx_term( context_2 );
}

void Communication::Recv_Message()
{
    msg_recv.clear();
    strcpy( recv_Message, "" );
    length = zmq_recv( subscriber, recv_Message, 256, 0 );

    msg_recv = recv_Message;
    msg_recv.erase(0, msg_recv.find(">") + 1);
    msg_recv.erase(0, msg_recv.find(">") + 1);
    name_Person = msg_recv.substr( 0, msg_recv.find(">") );
    msg_recv.erase(0, msg_recv.find(">") + 1);
    message = msg_recv.substr( 0, msg_recv.find(">") );
}

void Communication::Send_Message( std::string data, std::string name_client )
{
    strcpy( send_Message, "TINARG>reaction>" );
    strcat( send_Message, name_client.c_str() );
    strcat( send_Message, ">" );
    strcat( send_Message, data.c_str() );
    strcat( send_Message, ">" );
    zmq_send( pusher, send_Message, sizeof(send_Message), 0 );
}

std::string Communication::Get_Name()
{
    return name_Person;
}

std::string Communication::Get_Message()
{
    return message;
}
