#include "header.h"
using namespace std;

extern Piece* board[8][8];

int Player::validMove()
{ int inRange=0; // now check and set to 1 if move is in range:
  if ((fromRow < 0) || (fromRow > 7))
    cerr << "Error - FromRow must be between 1 and 8" << endl;
  else if ((fromColumn < 0) || (fromColumn > 7))
    cerr << "Error - FromColumn must be between a and h" << endl;
  else if ((toRow < 0) || (toRow > 7))
    cerr << "Error - ToRow must be between 1 and 8" << endl;
  else if ((toColumn < 0) || (toColumn > 7))
    cerr << "Error - ToColumn must be between a and h" << endl;
  else inRange=1;
  if (!inRange) return 0; // not a valid move
  if (!(board[fromRow][fromColumn]))
  { cerr << "Error - There is no piece in your From position" << endl;
    return 0; // not a valid move
  }
  return board[fromRow][fromColumn]->validMove(colour,fromRow,fromColumn,toRow,toColumn);
}

Player::Player(PlayerColour _colour)
{ int pawnRow,kingRow;
  colour = _colour;
  if (colour == WHITE)      {pawnRow=1; kingRow=0;}
  else if (colour == BLACK) {pawnRow=6; kingRow=7;}
  else { cerr << "Error in Player constructor" << endl; exit(1);} // should never happen
  int column; for (column=0;column<8;column++)
  { board[pawnRow][column] = new Piece(PAWN,colour);
    PieceType pieceType;
    switch (column)
    { case 0: pieceType=CASTLE; break;
      case 1: pieceType=KNIGHT; break;
      case 2: pieceType=BISHOP; break;
      case 3: pieceType=QUEEN;  break;
      case 4: pieceType=KING;   break;
      case 5: pieceType=BISHOP; break;
      case 6: pieceType=KNIGHT; break;
      case 7: pieceType=CASTLE; break;
    }
    board[kingRow][column] = new Piece(pieceType,colour);
  }
}

void Player::displayBoard()
{ int row,column;
  cout << endl << "  ";
  for (column=0;column<=7;column++) cout << (char) (((int)'a')+column);
  cout << endl << " ."; for (column=0;column<=7;column++) cout << '-';
  cout << "." << endl;
  for (row=7;row>=0;row--)
  { cout << 1+row << "|";
    for (column=0;column<=7;column++)
    { if (board[row][column])
      { Piece& piece = *(board[row][column]);
        char pieceCharacter;
        switch (piece.getType())
        { case PAWN  : pieceCharacter='P'; break;
          case CASTLE: pieceCharacter='C'; break;
          case KNIGHT: pieceCharacter='N'; break;
          case BISHOP: pieceCharacter='B'; break;
          case QUEEN : pieceCharacter='Q'; break;
          case KING  : pieceCharacter='K'; break;
        }
        if (piece.getColour() == WHITE)
          pieceCharacter = (char) ((int) pieceCharacter + (int) 'a' - (int) 'A');
        cout << pieceCharacter;
      }
      else cout << ' ';
    }
    cout << "|" << 1+row << "   ";
    switch (row)
    { case 7: cout << "Black is upper case: PCNBQK"; break;
      case 6: cout << "P = Pawn";                    break;
      case 5: cout << "C = Castle";                  break;
      case 4: cout << "N = kNight";                  break;
      case 3: cout << "B = Bishop";                  break;
      case 2: cout << "Q = Queen";                   break;
      case 1: cout << "K = King";                    break;
      case 0: cout << "White is lower case: pcnbqk"; break;
    }
    cout << endl;
  }
  cout << " .";
  for (column=0;column<=7;column++) cout << '-'; cout << "." << endl << "  ";
  for (column=0;column<=7;column++) cout << (char) (((int)'a')+column);
  cout << endl;
}

void Player::inputMove()
{ char fromColumnChar,toColumnChar;
  while (true)
  { cout << endl << colour << ", please enter a move in the form" << endl
         << "FromRow FromColumn ToRow ToColumn, eg. 1 b 3 c :" << endl;
    cin >> fromRow >> fromColumnChar >> toRow >> toColumnChar;
    if (!cin.fail()) break;
    cerr << "Error - Bad input type" << endl;
    cin.clear();          // clear error flags
    cin.ignore(999,'\n'); // ignore rest of input
  }
  fromRow--; toRow--;
  fromColumn = ((int) fromColumnChar) - ((int) 'a');
  toColumn   = ((int) toColumnChar  ) - ((int) 'a');
}


void Player::carryOutMove()
{ Piece*& ptr_fromPiece = board[fromRow][fromColumn]; // References to pointers, so
  Piece*& ptr_toPiece = board[toRow][toColumn];       // changing them will change board
  int victory = (ptr_toPiece&&(ptr_toPiece->getType()==KING))?1:0;
  if (ptr_toPiece) delete ptr_toPiece;
  ptr_toPiece = ptr_fromPiece; // NB: would not change board if just using new pointers
  ptr_fromPiece = 0;           // but works because using references to board's pointers
  if (victory)
  { displayBoard();
    cout << endl << "Congratulations " << colour << " - You have won." << endl << endl;
    exit(0);
  }
}

void Player::takeTurn()
{ do {displayBoard(); inputMove();} while (!validMove());
  carryOutMove();
}
