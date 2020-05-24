#include "statistics.h"

Statistics::Statistics()
{

}

short Statistics::Get_Place()
{
    return pos;
}

short Statistics::Get_lvl()
{
    return lvl;
}

bool Statistics::Get_smurf_troph()
{
    return smurf_trophy;
}

void Statistics::Set_Place(short number)
{
    pos = number;
}

void Statistics::Set_lvl(short number)
{
    lvl = number;
}

void Statistics::Set_smurf_troph()
{
    smurf_trophy = true;
}
