#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>

class Statistics
{
public:
    Statistics();
    short Get_Place();
    short Get_lvl();
    bool Get_smurf_troph();
    void Set_Place( short number );
    void Set_lvl( short number );
    void Set_smurf_troph();
private:
    short pos;
    short lvl;

    bool smurf_trophy;
};
#endif // STATISTICS_H
