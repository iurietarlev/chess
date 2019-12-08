#ifndef KNIGHT_HPP
#define KNIGHT_HPP 

#include"Piece.hpp"
class ChessBoard;

class Knight: public Piece{
  
public:
  Knight (color c, shape s, ChessBoard* cb);
  bool is_move_valid(int row_from, int col_from,
		     int row_to, int col_to) override;
  ~Knight() override;
};

#endif
