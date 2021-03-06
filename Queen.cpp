#include"Queen.hpp"
#include "Piece.hpp"
#include"ChessBoard.h"


Queen::Queen(color c, shape s, ChessBoard* cb)
  : Piece(c, s, cb){}

Queen::~Queen() {}


bool Queen::is_move_valid(int row_from, int col_from, int row_to, int col_to){
  if(diagonal_path_check(row_from, col_from, row_to, col_to, cb) ||
     straight_path_check(row_from, col_from, row_to, col_to, cb))
    return true;
  return false;
}


