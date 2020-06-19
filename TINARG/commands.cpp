#include "commands.h"

Commands::Commands()
{
    Commands_List["login"] = 0;
    Commands_List["shutdown"] = 1;
    Commands_List["list players"] = 2;
    Commands_List["get position"] = 3;
    Commands_List["roll dice"] = 4;
    Commands_List["logout"] = 5;
    Commands_List["get level"] = 6;
    Commands_List["chat"] = 7;
    Commands_List["smite"] = 8;
    Commands_List["attack"] = 9;
}

short Commands::Dice()
{
    return (rand() % 6 + 1);
}

std::string Commands::interaction(Statistics *stats)
{
    if( stats->Get_Place() > 20 and stats->Get_smurf_troph() == false )
    {
        stats->Set_Place( 20 );
    }

    switch( stats->Get_Place() )
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 6:
        case 8:
        case 12:
        case 14:
        case 16:
        case 18:
                interaction_msg = "You just stepped on a smurf! You bastard!";
                interaction_msg.append("\n");
                interaction_msg.append("Lvl up!");
                stats->Set_lvl( stats->Get_lvl()+1 );
                break;
        case 10:
                interaction_msg = "You stepped on smurfette? Not cool man!";
                interaction_msg.append("\n");
                interaction_msg.append("2 lvl up!");
                stats->Set_lvl( stats->Get_lvl()+2 );
                break;
        case 20:
                if( stats->Get_lvl() > 9 )
                {
                    interaction_msg = "And now you've killed papa smurf! How do you sleep at night?";
                    interaction_msg.append("\n");
                    interaction_msg.append("You've got his corpse as a trophy.");
                    interaction_msg.append("\n");
                    interaction_msg.append("You can go to the next world.");
                    stats->Set_smurf_troph();
                }
                else
                {
                    interaction_msg = "Looks like you lost your way!";
                    interaction_msg.append("\n");
                    interaction_msg.append("Get back to position 11 and come back at lvl 10.");
                    stats->Set_Place( 11 );
                    break;
                }
        break; default:
                interaction_msg = "Nothin' special";
                break;
    }
    return interaction_msg;
}

std::string Commands::Get_Command( short pos )
{

    it = Commands_List.begin();
    while(it != Commands_List.end())
    {
        if( it->second == pos )
        {
            command = it->first;
        }
        it++;
    }
    return command;
}
