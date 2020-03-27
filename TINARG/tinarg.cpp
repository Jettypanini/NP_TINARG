#include "tinarg.h"

TINARG::TINARG()
{

}

void TINARG::Start_Game()
{
    std::cout << "\"new\" or \"continue\"?" << std::endl;
    while(!Start_Okay)
    {
        std::cin >> game;
        if( game == "new" )
        {
            std::cout << "Welcome to the game!" << std::endl;
            Start_Okay = TRUE;
        }
        else if( game == "continue" )
        {
            std::cout << "Give in your password to continue!" << std::endl;
            Start_Okay = TRUE;
        }
        else if( game == "list" )
        {
            Command->Print_Start_Com();
        }
        else
        {
            std::cout << "Typed something wrong? Try again!" << std::endl;
        }
    }
    std::cout << "It works!!" << std::endl;
}
