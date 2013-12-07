#ifndef PIECE_H
#define PIECE_H
class Piece
{
  public:
    PieceType type;
    PlayerColour colour;

    Piece(PieceType t, PlayerColour c):type{t},colour{c}{}
};
#endif
