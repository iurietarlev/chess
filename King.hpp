#ifndef KING_HPP 
#define KING_HPP

#include"Piece.hpp"
#include"ChessBoard.h"

class King: public Piece{
public:
  King (color c, shape s, ChessBoard* cb);
  ~King() override;

  //determine if move of this piece form source to
  //destination is a valid one
  bool is_move_valid(int row_from, int col_from,
		     int row_to, int col_to) override;
  
  // flag that stands true if piece has moved once
  bool already_moved;
};

#endif
