/**********************************************
 * This is the main for the chess game program
 * which is designed using objected oriented 
 * design principles. All the functionality
 * can be tested by creating an object of class
 * ChessBoard and using the function submitMove.
 * Below a couple of quick tests are written, 
 * to test edge cases for check, checkmate, 
 * stalemate and castling.
 * ********************************************/

//Author: Iurie Tarlev


#include"ChessBoard.h"
#include<iostream>

using namespace std;

int main() {

  cout << "========================\n";
  cout << "Testing the Chess Engine\n";
  cout << "========================\n\n";

  ChessBoard cb;
  cout << '\n';

  //incorrect turn's move
  cb.submitMove("D7", "D6");
  cout << '\n';

  //attempt to move a piece from a position with none
  cb.submitMove("D4", "H6");
  cout << '\n';

  //attempt valid move
  cb.submitMove("D2", "D4");
  cout << '\n';

  //attempt invalid move of bishop 
  cb.submitMove("F8", "B4");
  cout << '\n';

  
  cout << "========================\n";
  cout << "  Test Fools CheckMate  \n";
  cout << "========================\n\n";
  cb.resetBoard();
 
  cb.submitMove("F2", "F3");
  cb.submitMove("E7", "E5");
  cout << endl;
  
  cb.submitMove("G2", "G4");
  cb.submitMove("D8", "H4");
  cout << endl;
  
  cb.print_board();

  
  cout << "========================\n";
  cout << "Test Move after chekmate\n";
  cout << "========================\n\n";

  cb.submitMove("D8", "H4");
  cout << endl;

  
  cout << "========================\n";
  cout << "=== Check Stale Mate ===\n";
  cout << "========================\n\n";

  cb.resetBoard();
  
  cb.submitMove("E2", "E3");
  cb.submitMove("A7", "A5");
  cout << endl;
  
  cb.submitMove("D1", "H5");
  cb.submitMove("A8", "A6");
  cout << endl;
  
  cb.submitMove("H5", "A5");
  cb.submitMove("H5", "A5");
  cout << endl;
  
  cb.submitMove("H7", "H5");
  cb.submitMove("H2", "H4");
  cout << endl;
  
  cb.submitMove("A6", "H6");
  cb.submitMove("A5", "C7");
  cout << endl;
  
  cb.submitMove("F7", "F6");
  cb.submitMove("C7", "D7");
  cout << endl;
  
  cb.submitMove("E8", "F7");
  cb.submitMove("D7", "B7");
  cout << endl;

  cb.submitMove("D8", "D3");
  cb.submitMove("B7", "B8");
  cout << endl;
  
  cb.submitMove("D3", "H7");
  cb.submitMove("B8", "C8");
  cout << endl;
  
  cb.submitMove("F7", "G6");
  cb.submitMove("C8", "E6");
  cout << endl;

  cb.print_board(); 
  
  cout << "=========================\n";
  cout << "Test Move after stalemate\n";
  cout << "=========================\n\n";
 
  cb.submitMove("D8", "H4");
  cout << endl;
  
  cout << "=========================\n";
  cout << "====== Test Castling ====\n";
  cout << "=========================\n\n";

  cb.resetBoard();
  
  cb.submitMove("G2", "G4");
  cb.submitMove("H7", "H5");
  cout << endl;
  
  cb.submitMove("G1", "F3");
  cb.submitMove("H8", "H6");
  cout << endl;
  
  cb.submitMove("G4", "H5");
  cb.submitMove("H6", "G6");
  cout << endl;
  
  cb.submitMove("F1", "H3");
  cb.submitMove("A7", "A5");
  cout << endl;
  
  //attempt to caslte should fail
  cout << "CASTLING SHOULD FAIL: \n";
  cb.submitMove("E1", "G1"); 
  cb.print_board(); 
    
  cb.submitMove("B2", "B4");
  cb.print_board(); 
	
  cb.submitMove("G6", "F6");
  cb.print_board(); 

  //attempt to caslte should succeed
  cout << "CASTLING SHOULD SUCCEED: \n";
  cb.submitMove("E1", "G1");
  cb.print_board(); 
  
   
  cout << "=========================\n";
  cout << "===== Test Castling 2====\n";
  cout << "=========================\n\n";

  cb.resetBoard();
  
  cb.submitMove("G2", "G4");
  cb.submitMove("H7", "H5");
  cout << endl;
  
  cb.submitMove("G1", "F3");
  cb.submitMove("H8", "H6");
  cout << endl;
  
  cb.submitMove("G4", "H5");
  cb.submitMove("H6", "G6");
  cout << endl;
  
  cb.submitMove("F1", "H3");
  cb.submitMove("A7", "A5");
  cout << endl;
  
  cb.submitMove("F3", "D4"); 
  cb.print_board(); 
    
  cb.submitMove("G6", "F6");
  cb.print_board(); 
	
  cb.submitMove("F2", "F4");
  cb.print_board(); 

  cb.submitMove("F6", "F4");
  cb.print_board(); 

  cout << "CASTLING SHOULD FAIL: \n";
  cb.submitMove("E1", "G1");
  cb.print_board(); 

  cout << "CASTLING SHOULD FAIL:: \n";
  cb.submitMove("E1", "G1");
  cb.print_board(); 

  cb.submitMove("D4", "B5");
  cb.print_board(); 

  cb.submitMove("F4", "D4");
  cb.print_board(); 
  
  cout << "CASTLING SHOULD SUCCEED: \n";
  cb.submitMove("E1", "G1");
  cb.print_board(); 

  

  cout << "=========================\n";
  cout << "    Is king in check? \n";
  cout << "=========================\n\n";
  
  cb.submitMove("D4", "G4");
  cb.print_board(); 


 
  cout << "=========================\n";
  cout << "Alekhine vs. Vasic (1931)\n";
  cout << "=========================\n\n";

  cb.resetBoard();
  cout << '\n';

  cb.submitMove("E2", "E4");
  cb.submitMove("E7", "E6");
  cout << '\n';

  cb.submitMove("D2", "D4");
  cb.submitMove("D7", "D5");
  cout << '\n';

  cb.submitMove("B1", "C3");
  cb.submitMove("F8", "B4");
  cout << '\n';

  cb.submitMove("F1", "D3");
  cb.submitMove("B4", "C3");
  cout << '\n';

  cb.submitMove("B2", "C3");
  cb.submitMove("H7", "H6");
  cout << '\n';

  cb.submitMove("C1", "A3");
  cb.submitMove("B8", "D7");
  cout << '\n';

  cb.submitMove("D1", "E2");
  cb.submitMove("D5", "E4");
  cout << '\n';

  cb.submitMove("D3", "E4");
  cb.submitMove("G8", "F6");
  cout << '\n';

  cb.submitMove("E4", "D3");
  cb.submitMove("B7", "B6");
  cout << '\n';

  cb.submitMove("E2", "E6");
  cb.submitMove("F7", "E6");
  cout << '\n';
    
  cb.submitMove("D3", "G6");
  cout << '\n';

  
  
  return 0;
}
