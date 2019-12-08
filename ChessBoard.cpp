#include<iostream>
#include<cstring>
#include"ChessBoard.hpp"
#include"Exceptions.hpp"
#include"Piece.hpp"
#include"Rook.hpp"
#include"Bishop.hpp"
#include"King.hpp"
#include"Queen.hpp"
#include"Knight.hpp"

using namespace std;

ChessBoard::ChessBoard() : turn(WHITE) 
{setBoard();}

ChessBoard::~ChessBoard()  
{
  cleanBoard();
}

void ChessBoard::cleanBoard(){
  for(int row = 0; row < 8; row++)
    for(int col = 0; col < 8; col++)
      if(board[row][col] != nullptr){
	delete board[row][col];
	board[row][col] = nullptr;}
}

void ChessBoard::resetBoard(){
  cleanBoard();
  setBoard();
  turn = WHITE;
}

	 
void ChessBoard::setBoard(){
  cout << "A new chess game is started!" << endl;
  nr_of_pieces_left = 32;
  
  for(int row = 0; row < 8; row++)
    for(int col = 0; col < 8; col++)
      board[row][col] = nullptr;
  
  //pawns
  for(int col = 0; col < 8; col++)
    {
      board[1][col] = new Pawn(BLACK, p, this);
      board[6][col] = new Pawn(WHITE, P, this);
    }
  
  //Rooks
  board[7][0] = new Rook(WHITE, R, this);
  board[7][7] = new Rook(WHITE, R, this);
  board[0][0] = new Rook(BLACK, r, this);
  board[0][7] = new Rook(BLACK, r, this);
  
  //Bishops

  board[7][2] = new Bishop(WHITE, B, this);
  board[7][5] = new Bishop(WHITE, B, this);
  board[0][2] = new Bishop(BLACK, b, this);
  board[0][5] = new Bishop(BLACK, b, this);

  //Knights

  board[7][1] = new Knight(WHITE, N, this);
  board[7][6] = new Knight(WHITE, N, this);
  board[0][1] = new Knight(BLACK, n, this);
  board[0][6] = new Knight(BLACK, n, this);

  
  //Queen

  board[7][3] = new Queen(WHITE, Q, this);
  board[0][3] = new Queen(BLACK, q, this);

  
  //King
  board[7][4] = new King(WHITE, K, this);
  board[0][4] = new King(BLACK, k, this);
  white_king_row = 7; white_king_col = 4;
  black_king_row = 0; black_king_col = 4;
}
  

void ChessBoard::submitMove(const char* from, const char* to){

  int row_from = convert_char_to_int(from[1]);
  int col_from = convert_char_to_int(from[0]);  
  int row_to = convert_char_to_int(to[1]);
  int col_to = convert_char_to_int(to[0]);
  
  string piece_color;
  string piece_shape;
  
  //check for valid position
  try{
    validate_pos(from);
    validate_pos(to);

    validate_piece_at_pos(row_from, col_from, from);

    piece_color =convert_col_to_string(board[row_from][col_from]->getColor());
    piece_shape =convert_shape_to_string(board[row_from][col_from]->getShape());
      
    validate_turn(row_from, col_from);
    
    validate_no_clash_with_own_piece(row_from, col_from, row_to, col_to, to);

    validate_move(row_from, col_from, row_to, col_to, to);

    validate_castling(row_from, col_from, row_to, col_to, to);

    movePiece(row_from, col_from, row_to, col_to);

    validate_no_check(row_from, col_from, row_to, col_to, to);
    
  }
  catch(const exception& e){
    cout << e.what() << endl;
    return;
  }

  //record if any of rooks or kings moved from default pos
  if(is_kg(row_to, col_to))
    static_cast<King*>(board[row_to][col_to])->already_moved = true;
  
  if(is_rook(row_to, col_to))
    static_cast<Rook*>(board[row_to][col_to])->already_moved = true;

  
  //print statement for valid move
  cout << piece_color << "'s " << piece_shape << " moves from "
       << from << " to " << to;
  
  //print statement addition if opponent's piece attacked
  if(deleted_piece != nullptr)
    cout << " taking "
	 << convert_col_to_string(deleted_piece->getColor()) << "'s "
	 << convert_shape_to_string(deleted_piece->getShape());

  cout<< endl;
  

  //deallocate memory for deleted piece
  if(deleted_piece != nullptr){
    nr_of_pieces_left--;
    delete deleted_piece;}
  
  color opposite_turn = (turn==BLACK) ? WHITE : BLACK;
  bool check_opposite = is_in_check(opposite_turn);

  //check the following and throw exceptions to main if true
  is_in_checkmate(opposite_turn, check_opposite);
  is_stalemate(opposite_turn, check_opposite);
  is_draw();
  
  if(check_opposite)
    cout << convert_col_to_string(opposite_turn)
	 << " is in check" << endl;
  
  turn = opposite_turn;
   
}



void ChessBoard::validate_no_check(int row_from, int col_from,
				   int row_to, int col_to, const char * to){
  if(is_in_check(turn)){
    string piece_color =						\
      convert_col_to_string(board[row_from][col_from]->getColor());
    string piece_shape =						\
      convert_shape_to_string(board[row_from][col_from]->getShape());
	
    undoMovePiece(row_from, col_from, row_to, col_to);
    throw CanNotMove(piece_color, piece_shape, to);
  }		 
}

void ChessBoard::validate_turn(int row_from, int col_from){
  color piece_clr = getPiece(row_from,col_from)->getColor();
  if(piece_clr != turn)
    throw NotYourTurn(convert_col_to_string(piece_clr));
}
  

void ChessBoard::validate_piece_at_pos(int row_from, int col_from,
				       const char * pos){
  if(getPiece(row_from, col_from) == nullptr)
    throw NoPieceAtPos(pos);
}


void ChessBoard::validate_pos(const char * pos)
{
  char coord_x =  pos[1] ;  // numeric x axis
  char coord_y =  pos[0];   // alphabetic y axis  
  int length = strlen(pos);
    
  if (length != 2                                               
      || !(isupper(coord_y)  && coord_y <= 'H')
      || !(isdigit(coord_x) && coord_x != '0'))
    {
      throw InvalidPos(pos);
    }
}

void ChessBoard::validate_no_clash_with_own_piece(int row_from, int col_from,
					  int row_to, int col_to, const char * to){

  string piece_color =							\
    convert_col_to_string(getPiece(row_from,col_from)->getColor());
  string piece_shape =							\
    convert_shape_to_string(getPiece(row_from,col_from)->getShape());

  if(getPiece(row_to, col_to) != nullptr &&
     (getPiece(row_from,col_from)->getColor() ==
      getPiece(row_to,col_to)->getColor()))
    {
      throw CanNotMove(piece_color, piece_shape, to);
    }
}





void ChessBoard::validate_move(int row_from, int col_from,
			       int row_to, int col_to, const char * to){
  string piece_color =							\
    convert_col_to_string(getPiece(row_from,col_from)->getColor());
  string piece_shape =							\
    convert_shape_to_string(getPiece(row_from,col_from)->getShape());
  
  if(!getPiece(row_from,col_from)->
     is_move_valid(row_from, col_from,row_to, col_to))
    {
      throw CanNotMove(piece_color, piece_shape, to);
    }
}  

void ChessBoard::validate_castling(int row_from, int col_from,
				    int row_to, int col_to, const char * to){

  string piece_color =							\
    convert_col_to_string(getPiece(row_from,col_from)->getColor());
  string piece_shape =							\
    convert_shape_to_string(getPiece(row_from,col_from)->getShape());
  

  if(is_kg(row_from, col_from) && abs(col_to - col_from) > 1){
    if(col_to > col_from){
      for(int i = col_from; i <= col_to; i++)
	if(is_in_check_if_kg_mv_to(turn, row_to, i)){
	  throw CanNotMove(piece_color, piece_shape, to);
	}
      movePiece(row_to, 7, row_to, 5);
    }
      
    if(col_to < col_from){
      for(int i = col_from; i >= col_to; i--)
	if(is_in_check_if_kg_mv_to(turn, row_to, i)){
	  throw CanNotMove(piece_color, piece_shape, to);
	}
      movePiece(row_to, 0, row_to, 3);
    }
  }
}





void ChessBoard::is_in_checkmate(color clr, bool opponent_check){
  if(opponent_check && !kg_can_run_away(clr) &&
     !kg_can_be_shielded(clr)){
    throw CheckMate(convert_col_to_string(clr)); 
  }
}
  
void ChessBoard::is_stalemate(color clr, bool opponent_check){
  if(!opponent_check && !kg_can_run_away(clr) &&
     !kg_can_be_shielded(clr)){
    throw StaleMate();
  }
}

void ChessBoard::is_draw(){
  if(nr_of_pieces_left == 2)
    throw Draw();
}

bool ChessBoard::is_in_check(color c){
  int kr = getKingRow(c);
  int kc = getKingCol(c);

  color opposite = (c==WHITE ? BLACK : WHITE);
  
  for( int i = 0; i < 8; i++)
    for( int j = 0; j < 8; j++)
      if(getPiece(i, j) != nullptr)
	if(getPiece(i, j)->getColor() == opposite)
	  if(getPiece(i,j)->is_move_valid(i,j,kr,kc))
	    {return true;
	      cout << "r: " << i << ", c: "<< j <<endl;}
  
  return false;
}

bool ChessBoard::is_in_check_if_kg_mv_to(color c, int row_to, int col_to){
  int kr = getKingRow(c);
  int kc = getKingCol(c);
  color opposite = (c==WHITE ? BLACK : WHITE);

  simulateMove(kr, kc, row_to, col_to);
  
  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 8; j++)
      if(getPiece(i, j) != nullptr)
	if(getPiece(i, j)->getColor() == opposite)
	  if(getPiece(i,j)->is_move_valid(i,j,row_to, col_to)){
	    simulateUndoMove(kr, kc, row_to, col_to);
	    return true;
	    cout << "r: " << i << ", c: "<< j <<endl;
	  }

  simulateUndoMove(kr, kc, row_to, col_to);
  return false;
}

bool ChessBoard::kg_can_run_away(color clr){
  int kr = getKingRow(clr);
  int kc = getKingCol(clr);
  
  for(int r = kr - 1; r <= kr + 1; r++)
    for(int c = kc - 1; c <= kc + 1; c++)
      if(c >= 0 && r >= 0 && c <= 7 && r <= 7){
	if(!(kr == r && kc == c) &&	 
	   getPiece(kr, kc)->is_move_valid(kr,kc,r,c) &&
	   getPiece(r,c) == nullptr)
	  if(!is_in_check_if_kg_mv_to(clr, r, c))
	    return true;
      }
  return false;
}


bool ChessBoard::is_kg(int row, int col)
{
  if(!is_nullptr(row, col))
    if(getPiece(row,col)->getShape() == K ||
       getPiece(row,col)->getShape() == k)
      return true;
  
  return false;
}


bool ChessBoard::is_rook(int row, int col)
{
  if(!is_nullptr(row, col))
    if(getPiece(row,col)->getShape() == R ||
       getPiece(row,col)->getShape() == r)
      return true;
  
  return false;
}




bool ChessBoard::is_nullptr(int row, int col){
  if(getPiece(row,col) == nullptr)
    return true;
  
  return false;
}

bool ChessBoard::kg_can_be_shielded(color clr){
  color opposite = (clr==WHITE ? BLACK : WHITE);
  
  for(int r = 0; r <= 7; r++)
    for(int c = 0; c <= 7; c++)
      for(int i = 0; i <= 7; i++)
	for(int j = 0; j <= 7; j++)
	  if(!is_nullptr(i,j) &&
	     !( i == r && j == c) &&
	     !is_kg(i,j) &&
	     getPiece(i, j)->getColor() == clr &&
	     getPiece(i, j)->is_move_valid(i,j, r,c))
	    {
	      if((!is_nullptr(r,c) && (getPiece(r,c)->getColor() == opposite))
		 || is_nullptr(r,c)){
		simulateMove(i,j,r,c);
		if(!is_in_check(clr))
		  {simulateUndoMove(i,j,r,c);
		    return true;
		  }
		else
 		  {simulateUndoMove(i,j,r,c);}
	      }
	    }
  return false;
}




	  
  
int ChessBoard::getKingRow(color c)
{
  if(c == WHITE)
    return white_king_row;
  else
    return black_king_row;
}

 
int ChessBoard::getKingCol(color c)
{
  if(c == WHITE)
    return white_king_col;
  else
    return black_king_col;
}



void ChessBoard::print_board(){
  cout << "     ";
  for (int r=0; r<8; r++) 
    cout << (char) ('A'+r) << "   ";
  
  cout << endl;  
  
  cout << "   +---+---+---+---+---+---+---+---+" << '\n';
  for(int row = 0; row < 8; row++)
    {
      cout << " " << (char) ('8'-row) << " |";
      for(int i = 0; i < 8; i++)
	{
	  cout << " ";
	  if(board[row][i] != nullptr)
	    cout << convert_shape_to_symbol(board[row][i]->getShape());
	  else
	    cout << " ";
	  
	  
	  
	  if(i!=7)
	    cout << " :";
	}
      cout << " |" << '\n';
      cout << "   +---+---+---+---+---+---+---+---+" << '\n';
    }
}


int ChessBoard::convert_char_to_int(char character)
{
  int integer;
  if (isupper(character))
    integer = character - 'A'; 
  else if (islower(character))
    integer = character - 'a'; 
  else if (isdigit(character))
    integer = abs(character - '8');
  else
    integer = -1; //return -1 if conversion not possible
  return integer;
}

char ChessBoard::convert_shape_to_symbol(shape s){
  switch(s)
    {
      //white pieces
    case(R): return 'R'; 
    case(N): return 'N';
    case(B): return 'B'; 
    case(K): return 'K'; 
    case(Q): return 'Q'; 
    case(P): return 'P'; 

      //black pieces
    case(r): return 'r'; 
    case(n): return 'n'; 
    case(b): return 'b'; 
    case(k): return 'k'; 
    case(q): return 'q'; 
    default: return 'p';
    }
}

string ChessBoard::convert_shape_to_string(shape s){
  switch(s)
    {
      //white pieces
    case(R): return "Rook"; 
    case(N): return "Knight";
    case(B): return "Bishop";
    case(K): return "King"; 
    case(Q): return "Queen"; 
    case(P): return "Pawn";
      
      //black pieces
    case(r): return "Rook"; 
    case(n): return "Knight";
    case(b): return "Bishop";
    case(k): return "King"; 
    case(q): return "Queen"; 
    default: return "Pawn"; 
    
    }
}


string ChessBoard::convert_col_to_string(color c){
  switch(c){  
  case(WHITE): return "White";
  default: return "Black";
  }
}    
    

Piece * ChessBoard::getPiece(int row, int col)
{
  return board[row][col];
}

void ChessBoard::movePiece(int row_from, int col_from, int row_to, int col_to)
{
  deleted_piece = board[row_to][col_to];
  board[row_to][col_to] = board[row_from][col_from];
  board[row_from][col_from] = nullptr;
  if_kg_store_pos(row_to, col_to);
}

void ChessBoard::undoMovePiece(int row_from, int col_from, int row_to, int col_to)
{
  board[row_from][col_from] = board[row_to][col_to];
  board[row_to][col_to] = deleted_piece;
  deleted_piece = nullptr;
  if_kg_store_pos(row_from, col_from);
}


void ChessBoard::simulateMove(int row_from, int col_from, int row_to, int col_to)
{
  temp_piece = board[row_to][col_to];
  board[row_to][col_to] = board[row_from][col_from];
  board[row_from][col_from] = nullptr;
}

void ChessBoard::simulateUndoMove(int row_from, int col_from, int row_to, int col_to)
{
  board[row_from][col_from] = board[row_to][col_to];
  board[row_to][col_to] = temp_piece;
  temp_piece = nullptr;
}


void ChessBoard::if_kg_store_pos(int row, int col){
  if(getPiece(row,col)->getShape() == K)
    {white_king_row = row; white_king_col = col;}
  if(getPiece(row,col)->getShape() == k)
    {black_king_row = row; black_king_col = col;}  
}


  


 
