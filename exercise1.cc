// C++ Guided Practical Exercise 1

#include "header.h"
using namespace std;

extern Piece* board[8][8];

int main()
{ int r,c; for (r=0;r<8;r++) for (c=0;c<8;c++) board[r][c]=0; // board elements all 0
  Player player1(WHITE);
  Player player2(BLACK);
  while (true)
  { 
    player1.takeTurn();
    player2.takeTurn();
  }
  return 0;
}
