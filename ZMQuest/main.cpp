#include <stdio.h>
#include <iostream>
#include <zmq.h>
#include <string.h>
#include <string>

void * context;
void * context_2;

int main( int argc, char * argv[] )
{
    context = zmq_ctx_new();
    context_2 = zmq_ctx_new();

    std::string send_Message;
    char recv_Message[256];
    int length_recv;
    std::string s;
    std::string name;
    std::string msg_recv;
    std::string message;
    std::string subs = "TINARG>reaction>";
    std::string temp;

    //Naam van gebruiker wordt opgevraagd
    std::cout << "What's your name?" << std::endl;
    std::cin >> name;
    system("cls");

    //Naam van gebruiker wordt subscribed
    subs = "TINARG>reaction>";
    subs.append( name );
    subs.append( ">" );

    //Connectie met Benternet
    void * pusher = zmq_socket( context, ZMQ_PUSH );
    zmq_connect( pusher, "tcp://benternet.pxl-ea-ict.be:24041" );

    void * subscriber = zmq_socket( context_2, ZMQ_SUB );
    zmq_connect( subscriber, "tcp://benternet.pxl-ea-ict.be:24042" );
    zmq_setsockopt( subscriber, ZMQ_SUBSCRIBE, subs.c_str(), subs.length() );

    std::cout << "Welcome to the game of TINARG!" << std::endl;
    std::cout << "Please type \"login\" to start." << std::endl;

    for(;;)
    {
        //Variabelen worden leeggemaakt
        send_Message.clear();
        send_Message = "TINARG>action>";
        strcpy( recv_Message, "" );
        msg_recv.clear();

        //Bericht wordt ingegeven in de 'command line'
        std::cout << name << ">";
        std::getline( std::cin, s );

        //Bericht wordt in een char[] gestoken met het adres
        temp.append( s );
        send_Message.append( name );
        send_Message.append( ">" );
        send_Message.append( s );
        send_Message.append( ">" );
        send_Message.append( "\0" );

        if( s != "" )
        {
            //bericht wordt verzonden
            zmq_send( pusher, send_Message.c_str(), send_Message.length(), 0 );

            //Reactie wordt ontvangen
            length_recv = zmq_recv( subscriber, recv_Message, 256, 0 );

            //Reactie wordt in string gestoken
            msg_recv = recv_Message;

            //Het 4e deel van het bericht is wat we nodig hebben
            msg_recv.erase(0, msg_recv.find(">") + 1);
            msg_recv.erase(0, msg_recv.find(">") + 1);
            msg_recv.erase(0, msg_recv.find(">") + 1);
            message = msg_recv.substr( 0, msg_recv.find(">") );
            std::cout << message << std::endl << std::endl;
            if( message == "Bye!" or message == "The server is now closing!" )
            {
                break;
            }
        }
    }

    //Looks like there's gonna be a cleanup on aisle five
    zmq_close( pusher );
    zmq_close( subscriber );
    zmq_ctx_shutdown( context );
    zmq_ctx_term( context );
    zmq_ctx_shutdown( context_2 );
    zmq_ctx_term( context_2 );
    return 0;
}
