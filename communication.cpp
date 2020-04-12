#include "communication.h"

Communication::Communication()
{

}

std::string Communication::Recv_Message()
{

    std::cin >> message;
/*
    std::string word = "";
      for ( auto x : incoming )
      {
          if ( x == ' ' )
          {
              std::cout << word;
              word = "";
          }
          else
          {
              word = word + x;
          }
      }
*/
    return message;
}

void Communication::Send_Message( std::string data )
{
    std::cout << data << std::endl;
}
