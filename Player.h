#ifndef PLAYER_H
#define PLAYER_H
class Player
{
  public:

    Player(PlayerColour _colour):colour{_colour}{}
    void takeTurn();

  private:
    void displayBoard();
    void inputMove();
    int validMove();
    void carryOutMove();
    PlayerColour colour;
    int fromRow,fromColumn,toRow,toColumn;
};
#endif
