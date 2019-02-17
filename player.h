#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>

class Player
{
  private:
    std::string playerName;
  public:
    std::string getPlayerName() { return playerName; };
    void setPlayerName(std::string);
};

#endif
