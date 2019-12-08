#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP

#include"Pawn.hpp"
#include"enums.hpp"
#include"Piece.hpp"
#include<string>

//class Piece;
class ChessBoard{
  Piece * board[8][8];   // array of pieces
  color turn;            // White's turn or Black's turn
  int nr_of_pieces_left; // nr of pieces on the board

  // pointer to deleted object Piece (used in for actual moves)
  Piece * deleted_piece; 

  // pointer to temporary object Piece (used for simulated moves)
  Piece * temp_piece;    

  // constantly updated positions of kings
  int white_king_row;
  int white_king_col;
  
  int black_king_row;
  int black_king_col;


  
  /* Validation helper functions (throwing relevant exceptions if invalid) */

  //check if the position in the range of the board 
  void validate_pos(const char* pos);

  //check if there is a piece at the 'from' position
  void validate_piece_at_pos(int row_from, int col_from,
					 const char * pos);

  //check if it is the correct turn
  void validate_turn(int row_from, int col_from);

  //check for clash with own piece
  void validate_no_clash_with_own_piece(int row_from, int col_from,
					int row_to, int col_to, const char * to);

  //check if the move is valid
  void validate_move(int row_from, int col_from,
		     int row_to, int col_to, const char * to);

  
  //check if castling move, if so if it is a valid one
  void validate_castling(int row_from, int col_from,
			  int row_to, int col_to, const char * to);

  //check if there is no check for the piece being moved
  void validate_no_check(int row_from, int col_from,
				int row_to, int col_to, const char * to);
  


  /* Other private functions */
  
  //check if the piece at this pos is king
  bool is_kg(int row, int col);
  
  //check if the piece at this pos is rook
  bool is_rook(int row, int col);
  
  //get current row of King of respective color
  int getKingRow(color c);

  //get current column of King of respective color
  int getKingCol(color c);

  //checks if the player of color c is in check
  bool is_in_check(color c);

  //checks if the player of color c is in check
  //if king moves to certain row and col
  bool is_in_check_if_kg_mv_to(color c, int row_to, int col_to);

  //checks if king can move and not be in check
  bool kg_can_run_away(color clr);

  //checks if king can be shielded by another piece
  //or another piece can attack the opponent to eliminate the check
  bool kg_can_be_shielded(color clr);

  //checks if there is no piece at respective position 
  bool is_nullptr(int row, int col);

  //if the piece moved to row and col is king, store it's new pos
  void if_kg_store_pos(int row, int col);

  //check if it is a draw
  void is_draw();

  //check if it is a stalemate
  void is_stalemate(color clr, bool opponent_check);

  //check if it is a checkmate
  void is_in_checkmate(color clr, bool opponenet_check);

  //simulate move and undo, for checking checkmate
  void simulateMove(int row_from, int col_from, int row_to, int col_to);
  void simulateUndoMove(int row_from, int col_from, int row_to, int col_to);

  //convert enum color c to a string
  std::string convert_col_to_string(color c);

  //convert enum shape s to a string
  std::string convert_shape_to_string(shape s);

  //convert enum shape s to a char (for printing of board)
  char convert_shape_to_symbol(shape s);

  //convert char to int (only within the correct range)
  int convert_char_to_int(char character);
  
public:  
  ChessBoard(); //constructor
  ~ChessBoard(); //destructor

  //submit move function which moves pieces from one pos to another
  void submitMove(const char*, const char*);

  //move a piece from one location to another and
  //if deleted a piece, store it in delted_piece
  void movePiece(int row_from, int col_from, int row_to, int col_to);

  //undo move of a piece 
  void undoMovePiece(int row_from, int col_from, int row_to, int col_to);

  //print current state of board in ASCII format
  void print_board();

  //get the object piece at specific position
  Piece* getPiece(int row, int col);

  //set board (put all objects on the board
  void setBoard();

  //clean board which deletes all objects from board
  //and deallocates dynamically allocated memory
  void cleanBoard();

  //resets the board for a new game
  //(combination of previous two functions)
  void resetBoard();
  
};

#endif
