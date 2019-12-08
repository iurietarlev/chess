#ifndef PIECE_HPP
#define PIECE_HPP

#include "enums.hpp" 

// declare because one or more
// functions have ChessBoard object/pointer/reference
 
class ChessBoard;

class Piece{
protected:
  color c;
  shape s;  
  ChessBoard * cb;  
  bool diagonal_path_check(int row_from, int col_from, int row_to,
		      int col_to, ChessBoard *cb);
  bool straight_path_check(int row_from,
				int col_from, int row_to,
		      int col_to, ChessBoard *cb);
public:
  
  Piece(color c, shape s, ChessBoard *cb);
  virtual ~Piece(){};
  shape getShape();
  color getColor();
  
  virtual bool is_move_valid(int row_from, int col_from,
			     int row_to, int col_to) = 0;
  
};
  
#endif
