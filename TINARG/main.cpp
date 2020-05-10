#include <tinarg.h>
int main()
{
    TINARG *Game = new TINARG();
    Game->Start_Game();
    delete Game;
    return 0;
}
