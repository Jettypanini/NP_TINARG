#include "communication.h"

Communication::Communication()
{
    context = zmq_ctx_new();
    pusher = zmq_socket( context, ZMQ_PUSH );
    zmq_connect( pusher, "tcp://benternet.pxl-ea-ict.be:24041" );

    context_2 = zmq_ctx_new();
    subscriber = zmq_socket( context_2, ZMQ_SUB );
    zmq_connect( subscriber, "tcp://benternet.pxl-ea-ict.be:24042" );
    zmq_setsockopt( subscriber, ZMQ_SUBSCRIBE, subs.c_str(), subs.length() );

    context_3 = zmq_ctx_new();
    chatter = zmq_socket( context_3, ZMQ_PUSH );
    zmq_connect( chatter, "tcp://benternet.pxl-ea-ict.be:24041" );
}

Communication::~Communication()
{
    zmq_close( pusher );
    zmq_close( subscriber );
    zmq_close( chatter );
    zmq_close( smitter );
    zmq_ctx_shutdown( context );
    zmq_ctx_term( context );
    zmq_ctx_shutdown( context_2 );
    zmq_ctx_term( context_2 );
    zmq_ctx_shutdown( context_3 );
    zmq_ctx_term( context_3 );
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
    if( message == "chat" )
    {
        msg_recv.erase(0, msg_recv.find(">") + 1);
        listener = msg_recv.substr( 0, msg_recv.find(">") );
        msg_recv.erase(0, msg_recv.find(">") + 1);
        chat_msg = msg_recv.substr( 0, msg_recv.find(">") );
    }
    else if( message == "smite" )
    {
        msg_recv.erase(0, msg_recv.find(">") + 1);
        smite_victim = msg_recv.substr( 0, msg_recv.find(">") );
    }
}

void Communication::Send_Message( std::string data, std::string name_client )
{
    send_Message.clear();
    send_Message = "TINARG>reaction>";
    send_Message.append( name_client );
    send_Message.append( ">" );
    send_Message.append( data );
    send_Message.append( ">" );
    send_Message.append( "\0" );
    zmq_send( pusher, send_Message.c_str(), send_Message.length(), 0 );
}

void Communication::Send_Chat(std::string data, std::string listener, std::string sender)
{
    send_Message.clear();
    send_Message = "TINARG>chat!>";
    send_Message.append( listener );
    send_Message.append( ">" );
    send_Message.append( sender );
    send_Message.append( ">" );
    send_Message.append( data );
    send_Message.append( ">" );
    send_Message.append( "\0" );
    zmq_send( chatter, send_Message.c_str(), send_Message.length(), 0 );
}

std::string Communication::Get_Name()
{
    return name_Person;
}

std::string Communication::Get_Message()
{
    return message;
}

std::string Communication::Get_Listener()
{
    return listener;
}

std::string Communication::Get_Chat()
{
    return chat_msg;
}

std::string Communication::Get_Victim()
{
    return smite_victim;
}


