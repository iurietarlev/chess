#include <iostream>
#include "Piece.hpp"
#include "ChessBoard.hpp"
#include "enums.hpp"

using namespace std;

Piece::Piece(color c, shape s, ChessBoard * cb) :
  c(c), s(s), cb(cb){}

shape Piece::getShape(){ return s; }

color Piece::getColor(){ return c; }

bool Piece::straight_path_check(int row_from,
				int col_from, int row_to,
				int col_to, ChessBoard *cb){
  
  //check if the move is straight 
  if(!(row_from == row_to) && !(col_from == col_to))
    return false;
  
  //move straight horizontally
  if(row_from == row_to){
    if(col_from > col_to)
      for(int i = col_from - 1; i > col_to; i--)
	if(cb->getPiece(row_from, i) != nullptr)
	  return false;
    
    if(col_from < col_to)
      for(int i = col_from + 1; i < col_to; i++)
	if(cb->getPiece(row_from, i) != nullptr)
	  return false;
  }
  
  //move straight vertically 
  if(col_from == col_to){
    if(row_from > row_to)
      for(int i = row_from - 1; i > row_to; i--)
	if(cb->getPiece(i, col_from) != nullptr)
	  return false;
    
    if(row_from < row_to)
      for(int i = row_from + 1; i < row_to; i++)
	if(cb->getPiece(i, col_from) != nullptr)
	  return false;
  }
  
  return true;
}

bool Piece::diagonal_path_check(int row_from, int col_from, int row_to,
				int col_to, ChessBoard *cb){
  
  //check if the move is diagonal
  if(abs(row_to - row_from) != abs(col_to - col_from))
    return false;

  if(col_to > col_from)
    {
      if(row_to > row_from){
	int step = 1;
	while(step < row_to - row_from){
	  if(cb->getPiece(row_from + step, col_from + step) != nullptr)
	    {return false;}
	  step++;
	}
      }

      if(row_to < row_from){
	int step = 1;
	while(step < row_from - row_to){
	  if(cb->getPiece(row_from - step, col_from + step) != nullptr)
	    {return false;}
	  step++;
	}
      }
    }
  
  if(col_to < col_from)
    {
      if(row_to > row_from){
	int step = 1;
	while(step < row_to - row_from){
	  if(cb->getPiece(row_from + step, col_from - step) != nullptr)
	    {return false;}
	  step++;
	}
      }

      
      if(row_to < row_from){
	int step = 1;
	while(step < row_from - row_to){
	  if(cb->getPiece(row_from - step, col_from - step) != nullptr)
 	    {return false;}
	  step++;
	}
      }
    }
  
  return true;
  
}
   


/*
bool Piece::is_move_valid(int row_from, int col_from,
			  int row_to, int col_to)
{ return false; }
*/
