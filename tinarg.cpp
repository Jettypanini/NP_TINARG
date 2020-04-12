#include "tinarg.h"

TINARG::TINARG()
{
    Command = new Commands();
    Talk = new Communication();
    statistics = new Player_Stats();
}

void TINARG::Start_Game()
{
    /*statistics->Add_Players( "Jethro", "password" );
    statistics->Add_Players( "Roger", "DobbitTV" );
    statistics->Add_Players( "Marc", "Corona" );
    statistics->Add_Players( "Joke", "bomen_kappen123" );
    statistics->Print_Players();*/
    Talk->Send_Message( "Login name: " );
    login_name = Talk->Recv_Message();
    if( statistics->Find_Player( login_name ) )
    {
        Talk->Send_Message( "Welcome back" );
    }
    else
    {
        Talk->Send_Message( "Creating new account...\nFill in your password: " );
        new_password = Talk->Recv_Message();
        statistics->Add_Players( login_name, new_password );
    }

    statistics->Print_Players();
}
