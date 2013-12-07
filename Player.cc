using namespace std;

Player::Player(PlayerColour c){
}

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

int Player::takeTurn()
{
  while(!Player::validMove())
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
  if(Piece::validMove())
  {  Piece*& ptr_fromPiece = board[fromRow][fromColumn]; // References to pointers, so
    Piece*& ptr_toPiece = board[toRow][toColumn];       // changing them will change board
    // ...
    int victory = (ptr_toPiece&&(ptr_toPiece->type==KING))?1:0;
    if(ptr_toPiece)delete ptr_toPiece;
    ptr_toPiece = ptr_fromPiece;
    ptr_fromPiece = 0;
    if(victory)
    {
      exercise1::displayBoard();
      cout<<endl<<"Congrats, You win."<<endl<<endl;
      exit(0);
    }
  return 1;
  }
  return 0;
}
