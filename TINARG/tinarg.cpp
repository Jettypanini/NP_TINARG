#include "tinarg.h"

TINARG::TINARG()
{
    Talk = new Communication();
}

void TINARG::Start_Game()
{
    for(;;)
    {
        message_recv.clear();
        name_recv.clear();
        std::cout << message_recv << std::endl;
        Talk->Recv_Message();
        message_recv = Talk->Get_Message();
        name_recv = Talk->Get_Name();

        if( message_recv == "wachtwoord" )
        {
            Talk->Send_Message( "The server is now closing!", name_recv );
            break;
        }

        Talk->Send_Message( message_recv, name_recv );
    }

    delete Talk;
}
