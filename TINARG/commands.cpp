#include "commands.h"

Commands::Commands()
{

}

void Commands::Print_Start_Com()
{
    std::cout << std::endl << "List of current usable commands" << std::endl;
    for( int i=0; i<2; i++ )
    {
        for( int j=0; j<2; j++ )
        {
           if( Start_Commands[i][j].length() < 8 )
           {
               tabs = "\t\t";
           }
           else
           {
               tabs = "\t";
           }
           std::cout << Start_Commands[i][j] << tabs;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
