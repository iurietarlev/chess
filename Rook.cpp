#include<iostream>
#include"Rook.hpp"
#include "Piece.hpp"
#include"ChessBoard.h"

using namespace std;

Rook::Rook(color c, shape s, ChessBoard* cb)
  : Piece(c, s, cb), already_moved(false) {};

bool Rook::is_move_valid(int row_from, int col_from, int row_to, int col_to){
  if(straight_path_check(row_from, col_from, row_to, col_to, cb))
    return true;
  
  return false;
}

Rook::~Rook() {}
