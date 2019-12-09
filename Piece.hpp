#ifndef PIECE_HPP
#define PIECE_HPP

#include "enums.hpp" 

// declare because one or more
// functions have ChessBoard object/pointer/reference
 
class ChessBoard;

//Abstract parent class Piece for all the piece types classes
class Piece{
protected:
  color c; //piece color
  shape s; //piece shape 
  ChessBoard * cb; //pointer to chessboard 
  
  //checks that the diagonal path between source and destination
  //is unobstructed by any other pieces
  bool diagonal_path_check(int row_from, int col_from, int row_to,
		      int col_to, ChessBoard *cb);

  //checks that the straight path between source and destination
  //is unobstructed by any other pieces
  bool straight_path_check(int row_from,
				int col_from, int row_to,
		      int col_to, ChessBoard *cb);
public:
  Piece(color c, shape s, ChessBoard *cb);
  virtual ~Piece();

  //getter functions for color and shape
  shape getShape(); 
  color getColor();

  //virtual function to determine if the move is valid 
  virtual bool is_move_valid(int row_from, int col_from,
			     int row_to, int col_to) = 0;
  
};
  
#endif
