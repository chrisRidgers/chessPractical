#ifndef PIECE_H
#define PIECE_H
class Piece
{
  public:
    PieceType getType();
    PlayerColour getColour();
    int validMove(PlayerColour testColour,
	int fromRow,int fromColumn,int toRow, int toColumn);

    Piece(PieceType _type, PlayerColour _colour):type{_type},colour{_colour}{}
  private:
    PieceType type;
    PlayerColour colour;
};
#endif
