#include "commands.h"

Commands::Commands()
{

}

short Commands::Dice()
{
    return (rand() % 6 + 1);
}
