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
ChessBoard.o: ChessBoard.h Pawn.hpp enums.hpp Exceptions.hpp
Piece.o: Piece.hpp 	
Pawn.o: Pawn.hpp Piece.hpp
Exceptions.o: Exceptions.hpp			
Rook.o: Rook.hpp Piece.hpp
Bishop.o: Bishop.hpp Piece.hpp
King.o: King.hpp Rook.hpp Piece.hpp
Queen.o: Queen.hpp Piece.hpp
Knight.o: Knight.hpp Piece.hpp	

.PHONY: clean

clean:
	rm -f *.o $(EXE)
