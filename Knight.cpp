#include"Knight.hpp"
#include"Piece.hpp"
#include"ChessBoard.h"


Knight::Knight(color c, shape s, ChessBoard* cb)
  : Piece(c, s, cb){}

Knight::~Knight(){}


bool Knight::is_move_valid(int row_from, int col_from, int row_to, int col_to){
  if((((abs(row_from - row_to) == 1) && (abs(col_from - col_to) == 2)) ||
      ((abs(row_from - row_to) == 2) && (abs(col_from - col_to) == 1))))       
    return true;
  
  return false;
}
