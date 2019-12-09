#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include<iostream>
#include<exception>
#include<string>

using namespace std;
class AnyError : public exception {
protected :
  string explanation ;
public :
  AnyError();
  ~AnyError () override;
  const char * what () const noexcept override;
};


class StaleMate : public AnyError {
public :
  StaleMate ();
  ~StaleMate() override;
};


class CheckMate : public AnyError {
public :
  CheckMate (const string &clr);
  ~CheckMate() override;
};


class Draw : public AnyError {
public :
  Draw ();
  ~Draw() override;
};

class CanNotMove : public AnyError {
public :
  CanNotMove (const string &clr, const string &shp, const string &to);
  ~CanNotMove() override;
};


class InvalidPos : public AnyError {
public :
  InvalidPos (const string &pos);
  ~InvalidPos() override;
};


class NoPieceAtPos : public AnyError {
public :
  NoPieceAtPos (const string &pos);
  ~NoPieceAtPos() override;
};

class NotYourTurn : public AnyError {
public :
  NotYourTurn (const string &piece_clr);
  ~NotYourTurn() override;
};


class GameOver : public AnyError {
public :
  GameOver ();
  ~GameOver() override;
};





#endif
