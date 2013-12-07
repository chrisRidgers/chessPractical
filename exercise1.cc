// C++ Guided Practical Exercise 1

#include "header.h"
using namespace std;

//enum PieceType {PAWN,CASTLE,KNIGHT,BISHOP,QUEEN,KING};
//enum PlayerColour {BLACK,WHITE};

/*struct Piece
{ PieceType type;
  PlayerColour colour;
};
*/

Piece* board [8][8]; // [row,bottom=0][column,left=0]

void putPlayersPieces(PlayerColour colour)
{ // Hint: best done with if, for and switch statements
  int pawnRow;
  int kingRow;
  
  if(colour==WHITE){pawnRow=1; kingRow=0;}
  else 
  if(colour==BLACK){pawnRow=6; kingRow=7;}

  for(int i=0;i<8;i++)
  {
    PieceType pieceType;

    board[pawnRow][i]=new Piece(pieceType,colour);
    board[pawnRow][i]->type=PAWN;
    board[pawnRow][i]->colour=colour;
    switch(i)
    {
      case 0: pieceType=CASTLE;	break;
      case 1: pieceType=KNIGHT; break;
      case 2: pieceType=BISHOP; break;
      case 3: pieceType=QUEEN; break;
      case 4: pieceType=KING; break;
      case 5: pieceType=BISHOP; break;
      case 6: pieceType=KNIGHT; break;
      case 7: pieceType=CASTLE; break;
    }
    board[kingRow][i]=new Piece(pieceType,colour);
    board[kingRow][i]->type=pieceType;
    board[kingRow][i]->colour=colour;
  }
}

void displayBoard()
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
	switch (piece.type)
	{ case PAWN  : pieceCharacter='P'; break;
	  case CASTLE: pieceCharacter='C'; break;
	  case KNIGHT: pieceCharacter='N'; break;
	  case BISHOP: pieceCharacter='B'; break;
	  case QUEEN : pieceCharacter='Q'; break;
	  case KING  : pieceCharacter='K'; break;
	}
	if (piece.colour == WHITE)
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

//For the sake of this solution only, four global move variables:
int fromRow,fromColumn,toRow,toColumn;

void inputMove()
{ char fromColumnChar,toColumnChar;
  while (true)
  { cout << endl << "Please enter a move in the form" << endl
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

void carryOutMove()
{ Piece*& ptr_fromPiece = board[fromRow][fromColumn]; // References to pointers, so
  Piece*& ptr_toPiece = board[toRow][toColumn];       // changing them will change board
  // ...
  int victory = (ptr_toPiece&&(ptr_toPiece->type==KING))?1:0;
  if(ptr_toPiece)delete ptr_toPiece;
  ptr_toPiece = ptr_fromPiece;
  ptr_fromPiece = 0;
  if(victory)
  {
    displayBoard();
    cout<<endl<<"Congrats, You win."<<endl<<endl;
    exit(0);
  }
}
                     /*
int main()
{ int r,c; for (r=0;r<8;r++) for (c=0;c<8;c++) board[r][c]=0; // board elements all 0
  putPlayersPieces(WHITE);
  putPlayersPieces(BLACK);
  while (true)
  { displayBoard();
    inputMove();
    carryOutMove();
  }
  return 0;
}
*/
int main()
{ int r,c; for (r=0;r<8;r++) for (c=0;c<8;c++) board[r][c]=0; // board elements all 0
  putPlayersPieces(WHITE);
  putPlayersPieces(BLACK);
  Player *White = new Player(WHITE);
  Player *Black = new Player(BLACK);
  while (true)
  { displayBoard();
    White->takeTurn();
    Black->takeTurn();
  }
  return 0;
}
