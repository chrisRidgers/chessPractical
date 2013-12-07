#ifndef PLAYER_H
#define PLAYER_H
class Player
{
  public:
    PlayerColour colour;

    Player(PlayerColour c):colour{c}{}
    int takeTurn();
    int validMove();
};
#endif
