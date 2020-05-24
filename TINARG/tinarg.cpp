#include "tinarg.h"

TINARG::TINARG()
{
    Talk = new Communication();
    Command = new Commands();
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
            if( message_recv == Command->Get_Command(0) )
            {
                Talk->Send_Message( "You're already logged in, bro!", name_recv );
            }
            else if( message_recv == Command->Get_Command(1) )
            {
                if( name_recv == "Jethro" )
                {
                    it = stats.begin();
                    while(it != stats.end())
                    {
                        Talk->Send_Message( "The server is now closing!", it->first );
                        it++;
                    }
                    break;
                }
                else
                {
                    Talk->Send_Message( "You're not Jethro", name_recv );
                }
            }
            else if( message_recv == Command->Get_Command(2) )
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
            else if( message_recv == Command->Get_Command(3) )
            {
                pos = stats[name_recv]->Get_Place();
                Talk->Send_Message( std::to_string( pos ), name_recv );
            }
            else if( message_recv == Command->Get_Command(4) )
            {
                dice = Command->Dice();
                pos = stats[name_recv]->Get_Place() + dice;
                stats[name_recv]->Set_Place( pos );
                message_appended.append( Command->interaction( stats[name_recv] ) );
                message_appended.append( "\n" );
                message_appended.append( "You're at position: " );
                message_appended.append( std::to_string( stats[name_recv]->Get_Place() ) );
                Talk->Send_Message( message_appended, name_recv );
            }
            else if( message_recv == Command->Get_Command(5) )
            {
                delete stats[name_recv];
                stats.erase( name_recv );
                Talk->Send_Message( "Bye!", name_recv );
            }
            else if( message_recv == Command->Get_Command(6) )
            {
                Talk->Send_Message( std::to_string( stats[name_recv]->Get_lvl() ), name_recv );
            }
            else
            {
                for( i = 0; i <= 6; i++ )
                {
                    message_appended.append(Command->Get_Command( i ));
                    message_appended.append("\n");
                }
                Talk->Send_Message( message_appended, name_recv );
            }
        }
        else if( stats.find( name_recv ) == stats.end() )
        {
            if( message_recv == "login" )
            {
                stats[name_recv] = new Statistics();
                stats[name_recv]->Set_Place(0);
                stats[name_recv]->Set_lvl(0);
                Talk->Send_Message( "Welcome!", name_recv );
            }
            else
            {
                Talk->Send_Message( "First type login please!", name_recv );
            }
        }
    }
    delete Talk;
    delete Command;
}
