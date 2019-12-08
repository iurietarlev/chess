#include<iostream>
#include"King.hpp"
#include"Rook.hpp"
#include"Piece.hpp"
#include"ChessBoard.hpp"

using namespace std;

King::~King() {}

King::King(color c, shape s, ChessBoard* cb)
  : Piece(c, s, cb), already_moved(false) {};

bool King::is_move_valid(int row_from, int col_from, int row_to, int col_to){
  if(//(diagonal_path_check(row_from, col_from, row_to, col_to, cb) ||
     //straight_path_check(row_from, col_from, row_to, col_to, cb)) &&
     (abs(row_from - row_to) <= 1) && (abs(col_from - col_to) <= 1))
    return true;
  
  //check castling move
  if(already_moved == false && row_from == row_to &&
     straight_path_check(row_from, col_from, row_to, col_to, cb))
    {
      
      //if castling move to the left
      if(col_to == col_from - 2){
	if(cb->getPiece(row_from,0) != nullptr)
	  if((cb->getPiece(row_from,0)->getShape() == r ||
	      cb->getPiece(row_from,0)->getShape() == R) &&
	     static_cast<Rook*>(cb->getPiece(row_from,0))->already_moved == false)
	    return true;
      }
      
      //if castling move to the right
      if(col_to == col_from + 2){
	if(cb->getPiece(row_from,7) != nullptr)
	  if((cb->getPiece(row_from,7)->getShape() == r ||
	      cb->getPiece(row_from,7)->getShape() == R) &&
	     static_cast<Rook*>(cb->getPiece(row_from,7))->already_moved == false)
	    return true;
      }
    }
  return false; 
}


