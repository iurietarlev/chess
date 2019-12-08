#ifndef ROOK_HPP
#define ROOK_HPP 

#include"Piece.hpp"

class ChessBoard;
class Rook: public Piece{
  
public:
  bool already_moved;
  Rook(color c, shape s, ChessBoard* cb);
  bool is_move_valid(int row_from, int col_from,
		     int row_to, int col_to) override;
  ~Rook() override;
};

#endif
