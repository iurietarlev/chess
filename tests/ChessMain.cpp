#include"ChessBoard.hpp"
#include<iostream>
#include<string>
#include"Exceptions.hpp"

using namespace std;

int main() {

  cout << "========================\n";
  cout << "Testing the Chess Engine\n";
  cout << "========================\n\n";
	
  ChessBoard cb;
	
  cb.print_board();
  cout << '\n';
  
  try{

    /* FOOLS MATE */
    /*    cb.submitMove("F2", "F3");
    cb.print_board();

    cb.submitMove("E7", "E5");
    cb.print_board();
	
    cb.submitMove("G2", "G4");
    cb.print_board();	
	
    cb.submitMove("D8", "H4");
    cb.print_board();
    */
	  
    /* Stale mate */
    /*		
    cb.submitMove("E2", "E3");
    cb.print_board();

	
    cb.submitMove("A7", "A5");
    cb.print_board();


	
    cb.submitMove("D1", "H5");
    cb.print_board();


    cb.submitMove("A8", "A6");
    cb.print_board();


    cb.submitMove("H5", "A5");
    cb.print_board();

	
    cb.submitMove("H5", "A5");
    cb.print_board();

	
    cb.submitMove("H7", "H5");
    cb.print_board();

	
    cb.submitMove("H2", "H4");
    cb.print_board();

	
    cb.submitMove("A6", "H6");
    cb.print_board();


    cb.submitMove("A5", "C7");
    cb.print_board();

	
    cb.submitMove("F7", "F6");
    cb.print_board();

	
    cb.submitMove("C7", "D7");
    cb.print_board();

	
    cb.submitMove("E8", "F7");
    cb.print_board();


    cb.submitMove("D7", "B7");
    cb.print_board();


	
    cb.submitMove("D8", "D3");
    cb.print_board();

	
    cb.submitMove("B7", "B8");
    cb.print_board();

    cb.submitMove("D3", "H7");
    cb.print_board();


	
    cb.submitMove("B8", "C8");
    cb.print_board();

	
    cb.submitMove("F7", "G6");
    cb.print_board(); 

	
	
    cb.submitMove("C8", "E6");
    cb.print_board(); 
    */

    /* Check castling */
    cb.submitMove("G2", "G4");
    cb.print_board();

    cb.submitMove("H7", "H5");
    cb.print_board();
    
    cb.submitMove("G1", "F3");
    cb.print_board();
	
    cb.submitMove("H8", "H6");
    cb.print_board(); 
	
    cb.submitMove("G4", "H5");
    cb.print_board(); 

    cb.submitMove("H6", "G6");
    cb.print_board();

    cb.submitMove("F1", "H3");
    cb.print_board();
    
    cb.submitMove("A7", "A5");
    cb.print_board();

    //attempt to caslte should fail
    cb.submitMove("E1", "G1"); 
    cb.print_board(); 

    
    cb.submitMove("B2", "B4");
    cb.print_board(); 
	
    cb.submitMove("G6", "F6");
    cb.print_board(); 

    //attempt to caslte should succeed
    cb.submitMove("E1", "G1");
    cb.print_board(); 
    
    
    
    //LIVE TESTING MODE
    
    string to;
    string from;
	
    while(to != "exit" || from != "exit")
      {
	cout << "Move from: ";
	cin >> from;
	    
	cout << "Move to: ";
	cin >> to;
	cb.submitMove(from.c_str(), to.c_str());
	cb.print_board();
      }	
  }
  catch(const exception& e){
    cout << e.what() << endl;
    cb.print_board();
    cout << "   ==========="
	 <<" GAME OVER! "
	 << "=========="
	 << endl;
  }                                   
  
  return 0;  
}
