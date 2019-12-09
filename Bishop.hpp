#ifndef BISHOP_HPP
#define BISHOP_HPP

#include"Piece.hpp"
#include"ChessBoard.h"

class Bishop: public Piece{  
public:
  Bishop (color c, shape s, ChessBoard* cb);
  ~Bishop() override;
  
  //determine if move of this piece form source to
  //destination is a valid one
  bool is_move_valid(int row_from, int col_from,
		     int row_to, int col_to) override;
};

#endif
