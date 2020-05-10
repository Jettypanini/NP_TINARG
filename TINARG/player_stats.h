#ifndef PLAYER_STATS_H
#define PLAYER_STATS_H

#include <string>
#include <iostream>

class Player_Stats
{
public:
    Player_Stats(  );
    void Add_Players( std::string new_name );
    void Print_Players();
    bool Find_Player( std::string player_name );
private:
    struct stats
    {
        std::string name;
        short stage;
        short lvl;
        short exp;
        short health;
        short attack;
        short defense;
        short magic;
        stats * next = nullptr;
    };
    stats * head;
};

#endif // PLAYER_STATS_H
