#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"

//breaking circular dependency
class ChessBoard;
 
class Pawn : public Piece{
  
public:
  Pawn(color c, shape s, ChessBoard* cb);
  bool is_move_valid(int row_from, int col_from,
		     int row_to, int col_to) override;  
  ~Pawn() override;
};



#endif
