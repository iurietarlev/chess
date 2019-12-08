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


	/* FOOLS MATE */

	/*
	try{
	
	cb.submitMove("F2", "F3");
	cb.print_board();


	cb.submitMove("E7", "E5");
	cb.print_board();

	
	cb.submitMove("G2", "G4");
	cb.print_board();	

	
	cb.submitMove("D8", "H4");
	cb.print_board();
	
	*/

	try{
	  /* Castling */
	  
	  
	/* Stale mate */
	  cb.submitMove("A1", "B1");
	  cb.print_board();

	  cb.submitMove("E8", "G8");
	  cb.print_board();

	  cb.submitMove("E1", "C1");
	  cb.print_board();
	  /*
	  cb.submitMove("E8", "G8");
	  cb.print_board();
	  
	  cb.submitMove("C1", "E1");
	  cb.print_board();
	  */
	  
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
	cb.print_board(); */

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
	
	

	


	/*	
	cb.submitMove("H7", "H5");
	cb.print_board();
	
	cb.submitMove("E2", "E4");
	cb.print_board();
	
	cb.submitMove("E7", "E6");
	cb.print_board();

	cb.submitMove("F1", "D3");
	cb.print_board();

	cb.submitMove("F8", "B4");
	cb.print_board();

	cb.submitMove("G1", "F3");
	cb.print_board();

	cb.submitMove("B4", "D2");
	cb.print_board();
	
	cb.submitMove("E1", "F1");
	cb.print_board();

	cb.submitMove("D8", "G5");
	cb.print_board();

	cb.submitMove("F1", "G1");
	cb.print_board();

	cb.submitMove("G5", "E3");
	cb.print_board();

	cb.submitMove("F1", "E2");
	cb.print_board();

	
	cb.submitMove("A2", "A4");
	cb.print_board();
	
	cb.submitMove("E3" , "E1");
	cb.print_board();
	
	cb.submitMove("D3" , "F1");
	cb.print_board();

	*/


	
	
	/*
	cb.submitMove("D7", "D2");
	cb.print_board();
	
	cb.submitMove("E7", "E5");
	cb.print_board();
	
	cb.submitMove("F7", "F4");
	cb.print_board();

	cb.submitMove("F7", "F4");
	cb.print_board();

	cb.submitMove("D2", "D4");
	cb.print_board();

	cb.submitMove("E7", "E5");
	cb.print_board();

	cb.submitMove("D4", "D5");
	cb.print_board();

	cb.submitMove("G7", "G5");
	cb.print_board();
	
	
	cb.submitMove("D5", "D7");
	cb.print_board();
	*/
	



	/*
	cb.submitMove("D7", "D6");
	cout << '\n';
	
	cb.submitMove("D4", "H6");
	cout << '\n';

	cb.submitMove("D2", "D4");
	cout << '\n';

	cb.submitMove("F8", "B4");
	cout << '\n';

	*/
	cout << "========================\n";
	cout << "Testing the Chess Engine\n";
	cout << "========================\n\n";

	//ChessBoard cb;

	/*
	cout << '\n';

	cb.submitMove("D7", "D6");
	cout << '\n';

	cb.submitMove("D4", "H6");
	cout << '\n';

	cb.submitMove("D2", "D4");
	cout << '\n';

	cb.submitMove("F8", "B4");
	cout << '\n';
	*/


	/*

	
	cout << "=========================\n";
	cout << "Alekhine vs. Vasic (1931)\n";
	cout << "=========================\n\n";

	
	//cb.resetBoard();
	cout << '\n';

	cb.submitMove("E2", "E4");
	cb.submitMove("E7", "E6");
	cout << '\n';
	cb.print_board();
	
	cb.submitMove("D2", "D4");
	cb.submitMove("D7", "D5");
	cout << '\n';
	cb.print_board();
	
	cb.submitMove("B1", "C3");
	cb.submitMove("F8", "B4");
	cout << '\n';
	cb.print_board();
	
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
	cb.print_board();
*/
	return 0;  
}
