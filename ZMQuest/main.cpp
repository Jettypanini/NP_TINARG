#include <stdio.h>
#include <iostream>
#include <zmq.h>
#include <string.h>
#include <string>
#include <pthread.h>

void * context;
void * context_2;
void * context_3;

void *game_task(void *name)
{
   std::string &player =  *static_cast<std::string*>(name);

   context = zmq_ctx_new();
   context_2 = zmq_ctx_new();

   std::string send_Message;
   char recv_Message[256];
   int length_recv;
   std::string s;
   std::string msg_recv;
   std::string message;
   std::string subs = "TINARG>reaction>";
   std::string temp;

   subs = "TINARG>reaction>";
   subs.append( player );
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
       std::getline( std::cin, s );

       //Bericht wordt in een char[] gestoken met het adres
       temp.append( s );
       send_Message.append( player );
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
   zmq_ctx_shutdown( context );
   zmq_ctx_term( context );
   zmq_ctx_shutdown( context_2 );
   zmq_ctx_term( context_2 );

   pthread_exit(NULL);
}

void *chat_task(void *name)
{
   std::string &player =  *static_cast<std::string*>(name);

   context_3 = zmq_ctx_new();

   std::string subs;
   std::string msg_recv;
   std::string Sender;
   std::string message;

   char recv_Message[256];
   int length_recv;

   subs = "TINARG>chat!>";
   subs.append( player );
   subs.append( ">" );

   void * chatter = zmq_socket( context_3, ZMQ_SUB );
   zmq_connect( chatter, "tcp://benternet.pxl-ea-ict.be:24042" );
   zmq_setsockopt( chatter, ZMQ_SUBSCRIBE, subs.c_str(), subs.length() );

   for(;;)
   {
       //Reactie wordt ontvangen
       length_recv = zmq_recv( chatter, recv_Message, 256, 0 );

       //Reactie wordt in string gestoken
       msg_recv = recv_Message;
       //Het 4e deel van het bericht is wat we nodig hebben
       msg_recv.erase(0, msg_recv.find(">") + 1);
       msg_recv.erase(0, msg_recv.find(">") + 1);
       msg_recv.erase(0, msg_recv.find(">") + 1);
       Sender = msg_recv.substr( 0, msg_recv.find(">") );
       msg_recv.erase(0, msg_recv.find(">") + 1);
       message = msg_recv.substr( 0, msg_recv.find(">") );
       std::cout << std::endl << Sender << ": " << message << std::endl << std::endl;
   }

   zmq_ctx_shutdown( context_3 );
   zmq_ctx_term( context_3 );
   pthread_exit(NULL);
}

int main( int argc, char * argv[] )
{
    pthread_t threads[2];

    std::string name;

    //Naam van gebruiker wordt opgevraagd
    std::cout << "What's your name?" << std::endl;
    std::cin >> name;
    system("cls");


    pthread_create(&threads[0], NULL, game_task, static_cast<void*>(&name));
    pthread_create(&threads[1], NULL, chat_task, static_cast<void*>(&name));

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    return 0;
}
