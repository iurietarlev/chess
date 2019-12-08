#ifndef QUEEN_HPP
#define QUEEN_HPP 

#include"Piece.hpp"
class ChessBoard;
class Queen: public Piece{
  
public:
  Queen (color c, shape s, ChessBoard* cb);
  bool is_move_valid(int row_from, int col_from,
		     int row_to, int col_to) override;
  ~Queen() override;
};

#endif
