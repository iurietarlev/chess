OBJ = ChessMain.o Piece.o ChessBoard.o Pawn.o Exceptions.o \
      Rook.o Bishop.o King.o Queen.o Knight.o
CXX = g++
CXXFLAGS = -Wall -g #-Wextra
EXE = chess

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

#-include $(OBJ:.o = .d)

ChessMain.o: ChessBoard.h Exceptions.hpp 
ChessBoard.o: ChessBoard.h enums.hpp Exceptions.hpp Piece.hpp \
	Pawn.hpp Rook.hpp Bishop.hpp Knight.hpp King.hpp Queen.hpp
Piece.o: Piece.hpp enums.hpp ChessBoard.h
Pawn.o: Pawn.hpp Piece.hpp ChessBoard.h
Exceptions.o: Exceptions.hpp			
Rook.o: Rook.hpp Piece.hpp ChessBoard.h
Bishop.o: Bishop.hpp Piece.hpp ChessBoard.h
King.o: King.hpp Rook.hpp Piece.hpp ChessBoard.h
Queen.o: Queen.hpp Piece.hpp ChessBoard.h
Knight.o: Knight.hpp Piece.hpp ChessBoard.h

.PHONY: clean

clean:
	rm -f *.o $(EXE)
