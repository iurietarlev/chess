#include<iostream>
#include "Piece.hpp"
#include "Bishop.hpp"

using namespace std;

Bishop::Bishop(color c, shape s, ChessBoard* cb)
  : Piece(c, s, cb){};

bool Bishop::is_move_valid(int row_from, int col_from, int row_to, int col_to){
  if(diagonal_path_check(row_from, col_from, row_to, col_to, cb))
    return true;
  
  return false;
}

Bishop::~Bishop() {}
