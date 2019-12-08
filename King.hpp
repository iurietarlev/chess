#ifndef KING_HPP 
#define KING_HPP

#include"Piece.hpp"

class ChessBoard;
class King: public Piece{
public:
		
  bool already_moved;
  King (color c, shape s, ChessBoard* cb);
  bool is_move_valid(int row_from, int col_from,
		     int row_to, int col_to) override;
  ~King() override;
};

#endif
