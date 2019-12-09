#include"Exceptions.hpp"

#include<iostream>
#include<exception>
#include<string>

using namespace std;

AnyError::AnyError () {}
AnyError::~AnyError () {}
const char * AnyError:: what () const noexcept {
  return explanation.c_str ();
}

  
StaleMate::StaleMate():
  AnyError(){
  explanation = "It is a stalemate";
}
StaleMate::~StaleMate(){}


CheckMate::CheckMate(const string &clr):
  AnyError(){
  explanation = clr + " is in checkmate";
}

CheckMate::~CheckMate(){}


Draw::Draw():
  AnyError(){
  explanation = "It is a draw";
}
Draw::~Draw(){}

CanNotMove::CanNotMove(const string &clr, const string &shp, const string &to):
  AnyError(){
  explanation = clr + "'s " + shp + " cannot move to " + to + "!";
}
CanNotMove::~CanNotMove(){}


InvalidPos::InvalidPos(const string &pos):
  AnyError(){
  explanation = "Invalid position: "
    + pos + '!' ;
}
InvalidPos::~InvalidPos(){}


NoPieceAtPos::NoPieceAtPos(const string &pos):
  AnyError(){
  explanation = "There is no piece at position "
    + pos + "!";
}
NoPieceAtPos::~NoPieceAtPos(){}


NotYourTurn::NotYourTurn(const string &piece_clr):
  AnyError(){
  explanation = "It is not " + piece_clr
	 + "'s turn to move!";
}
NotYourTurn::~NotYourTurn(){}


