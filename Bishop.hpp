#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "Piece.hpp"

class ChessBoard;

class Bishop: public Piece{  
public:
  Bishop (color c, shape s, ChessBoard* cb);
  bool is_move_valid(int row_from, int col_from,
		     int row_to, int col_to) override;
  ~Bishop() override;
};

#endif
