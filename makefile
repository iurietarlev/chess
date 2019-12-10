OBJ = ChessMain.o Piece.o ChessBoard.o Pawn.o Exceptions.o \
      Rook.o Bishop.o King.o Queen.o Knight.o
CXX = g++
CXXFLAGS = -Wall -g 
EXE = chess

$(EXE): $(OBJ)
	$(CXX) $^ -o $@ 

%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -MMD -c $<

-include $(OBJ:.o=.d)

.PHONY: clean

clean:
	rm -f *.o *.d $(EXE)
