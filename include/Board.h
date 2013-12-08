class Board{
  public:
    Board getBoard() {return board;};
    Board():board{new Piece* board[8][8]}{};
  private:
    Board board;
};
