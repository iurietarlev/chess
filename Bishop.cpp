#include"Piece.hpp"
#include"Bishop.hpp"
#include"ChessBoard.h"


Bishop::Bishop(color c, shape s, ChessBoard* cb)
  : Piece(c, s, cb){}

Bishop::~Bishop() {}


bool Bishop::is_move_valid(int row_from, int col_from, int row_to, int col_to){
  if(diagonal_path_check(row_from, col_from, row_to, col_to, cb))
    return true;
  
  return false;
}

