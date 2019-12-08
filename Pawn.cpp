#include<iostream>
#include "Pawn.hpp"
#include "Piece.hpp"
#include "ChessBoard.h"

using namespace std;

Pawn::Pawn(color c, shape s, ChessBoard* cb)
 : Piece(c, s, cb){};

Pawn::~Pawn() {}


bool Pawn::is_move_valid(int row_from, int col_from, int row_to, int col_to) {
  
  //check if move in straight line
  if(straight_path_check(row_from, col_from, row_to, col_to, cb)){
    if(cb->getPiece(row_to, col_to) == nullptr){
      if(c == WHITE){
	
	if(row_to == (row_from - 1))
	  return true;
	
	if(row_from == 6 && (row_to == row_from - 2))
	  return  true;
      }
      
      if(c == BLACK){
	if(row_to == (row_from + 1))
	  return true;
	
	if(row_from == 1 && (row_to == row_from + 2))
	  return true;
      }
    }
  }
  
  //check if attack move diagonal is valid
  if(c == WHITE)
    if((row_to == row_from - 1) &&
       ((col_to == col_from + 1) || (col_to == col_from - 1)))
      if(cb->getPiece(row_to,col_to) != nullptr)
	return true;
  
  if(c == BLACK)
    if((row_to == row_from + 1) &&
       ((col_to == col_from + 1) || (col_to == col_from - 1)))
      if(cb->getPiece(row_to,col_to) != nullptr)
	return true;
  
  return false;
}


