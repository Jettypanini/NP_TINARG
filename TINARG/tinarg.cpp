#include "tinarg.h"

TINARG::TINARG()
{
    Talk = new Communication();
}

void TINARG::Start_Game()
{
    /*stats["Dave"] = new Statistics();
    stats["Dwight"] = new Statistics();
    stats["Carol"] = new Statistics();*/
    for(;;)
    {
        message_recv.clear();
        name_recv.clear();
        message_appended.clear();

        Talk->Recv_Message();
        message_recv = Talk->Get_Message();
        name_recv = Talk->Get_Name();

        if( stats.find( name_recv ) != stats.end() )
        {
            if( message_recv == "shutdown" )
            {
                if( name_recv == "Jethro" )
                {
                    Talk->Send_Message( "The server is now closing!", name_recv );
                    break;
                }
                else
                {
                    Talk->Send_Message( "You're not Jethro", name_recv );
                }
            }
            else if( message_recv == "list players" )
            {
                it = stats.begin();
                while(it != stats.end())
                    {
                        message_appended.append( it->first );
                        message_appended.append( "\n" );
                        it++;
                    }
                Talk->Send_Message( message_appended, name_recv );
            }
            else if( message_recv == "get position" )
            {
                pos = stats[name_recv]->Get_Place();
                Talk->Send_Message( std::to_string( pos ), name_recv );
            }
            else if( message_recv == "throw dice" )
            {
                dice = Command->Dice();
                pos = stats[name_recv]->Get_Place() + dice;
                stats[name_recv]->Set_Place( pos );
                Talk->Send_Message( std::to_string( dice ), name_recv );
            }
            else
            {
                Talk->Send_Message( message_recv, name_recv );
            }
        }
        else if( stats.find( name_recv ) == stats.end() )
        {
            if( message_recv == "login" )
            {
                stats[name_recv] = new Statistics();
                stats[name_recv]->Set_Place(0);
                Talk->Send_Message( "Welcome!", name_recv );
            }
            else
            {
                Talk->Send_Message( "First type login please!", name_recv );
            }
        }
    }
    delete Talk;
}
