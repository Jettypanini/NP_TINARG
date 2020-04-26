#include "player_stats.h"


Player_Stats::Player_Stats()
{

}

void Player_Stats::Add_Players(std::string new_name)
{
    stats * temp;
    temp = new stats;

    temp->name = new_name;
    temp->lvl = 1;
    temp->stage = 1;
    temp->health = 1;
    temp->attack = 1;
    temp->defense = 1;
    temp->magic = 1;
    temp->next = nullptr;

    if( head == nullptr )
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void Player_Stats::Print_Players()
{
    stats * temp = head;

    while( temp->next != nullptr )
    {
        std::cout << temp->name << std::endl;
        std::cout << temp->next->name << std::endl;
        temp = temp->next;
    }
}

bool Player_Stats::Find_Player( std::string player_name )
{
    stats * temp = head;

    while( temp->next != nullptr )
    {
        if( temp->name == player_name )
        {
            std::cout << "\t found: " << temp->name << std::endl;
            return 1;
        }
        else
        {
            std::cout << "\t Not: " << temp->name << std::endl;
          temp = temp->next;
        }
    }
    return 0;
}
