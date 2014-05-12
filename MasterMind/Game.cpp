// Directives to resource
#include <ioStream> 
#include <string>
#include <sstream>
#include <ctime>
#include <conio.h>

#include "computerAI.h"
#include "Validation.h"
//Declare namespace
using namespace std;

//Create ComputerAI Object

computerAI aiObject;
validation valObject;

//Set window size
int windowSize = system("mode con lines=37 cols=59");

//Declare Variables



//prototypes
int main();
void game();
int menu();
void helpMenu();
void printBoard(string[12][4], string[12][4], int currentTurn);
void gameOver(string[12][4], string[12][4],string result);
int getMenuInput();
void userGuess(string boardArray[][4], int currentTurn, string userInput);
bool playAgain();

//Main Method
int main()
{
	bool again = false;
	do{
	helpMenu();
	game();
	again = playAgain();
	}while(again != false);
	return 0;
}//end main

//controls the sequence of the game
void game()
{

	int turns = menu();
	

	int turn = 0;
	bool won = false;
	bool valid = false;
	string userInput;
	string boardArray[][4] = {  
	 {" "," "," "," "} ,/*  initializers for row indexed by 0 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 1 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 2 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 3 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 4 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 5 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 6 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 7 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 8 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 9 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 10 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 11*/
	};

		string pegArray[][4] = {  
	 {" "," "," "," "} ,/*  initializers for row indexed by 0 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 1 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 2 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 3 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 4 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 5 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 6 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 7 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 8 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 9 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 10 */
	 {" "," "," "," "} ,/*  initializers for row indexed by 11*/
	};
	
	if(turns <=10)
	{

		for(int i = turns; i < 12; i++)
		{
			for(int i2 = 0; i2 < 4; i2++)
			{
				boardArray[i][i2] = "-";
				pegArray[i][i2] = "-";
			}
		}
		
	}
		
		aiObject.createCode();

	for(int currentTurn=0; currentTurn < turns; currentTurn++ )
	{

		do{
		printBoard(boardArray, pegArray, currentTurn);
		getline(cin,userInput);
		valid = valObject.codeInput(userInput);
		}while(valid != true);
		userGuess(boardArray, currentTurn, userInput);
		aiObject.keyPeg(pegArray, boardArray, currentTurn);
		won = aiObject.winCheck(boardArray, currentTurn);
		if(won == true)
		{
			currentTurn = turns;
			gameOver(boardArray, pegArray,"Win");
		}
	}
	if(won == false)
		{
			gameOver(boardArray, pegArray,"Lose");
		}

}//end game

// Prints the main menu
int menu()
{
	bool valid  = false;
	string userInput;
	do
	{
		cout << " =======================================================" << endl;
		cout << "|			Master Mind			|" << endl;
		cout << " =======================================================" << endl;
		cout << "|							|" << endl;
		cout << "|							|" << endl;
		cout << "|							|" << endl;
		cout << "|				    			|" << endl;
		cout << "|				    			|" << endl;
		cout << "|				    			|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|				    			|" << endl;
		cout << "|			    				|" << endl;
		cout << "|		Pick the Number of turns??  		|" << endl;
		cout << "|				    			|" << endl;
		cout << "|			12 (Standard)			|" << endl;
		cout << "|			10 (Harder)     		|" << endl;
		cout << "|			 8 (Hardest)     		|" << endl;
		cout << "|				    			|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|				    			|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|				    			|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|				    			|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|				    			|" << endl;
		cout << " =======================================================" << endl;
		cout << " I pick number: ";

	
	getline(cin,userInput);
	valid = valObject.TurnInput(userInput);
	}while(valid != true);
	int turnsInput;

	stringstream(userInput) >> turnsInput;
	return turnsInput;
}//end printMenu


// Prints the main menu
void helpMenu()
{
	cout << " =======================================================" << endl;
		cout << "|			Master Mind			|" << endl;
		cout << " =======================================================" << endl;
		cout << "|							|" << endl;
		cout << "|			How to Play			|" << endl;
		cout << "|							|" << endl;
		cout << "|		 You Must Crack the Code!!		|" << endl;
		cout << "|	 the code is 4 digits long and contains		|" << endl;
		cout << "|       the numbers 1-6, there may be duplicates!	|" << endl;
			cout << "|			    				|" << endl;
		cout << "|     once you guess the code you will get feedback	|" << endl;
		cout << "|     an 'x' means right you have a right number in 	|" << endl;
		cout << "|  the right spot an 'o' means right number wrong spot 	|" << endl;
		cout << "|			       			    	|" << endl;
		cout << "|   at the end of the game the correct code will be  	|" << endl;
		cout << "|		shown at the top of the board 		|" << endl;
		cout << "|				    			|" << endl;
		cout << "|		 Good Luck, get Cracking!  		|" << endl;
		cout << "|				    			|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|				    			|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|				    			|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|				    			|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			 Created by: Jeffrey Davison	|" << endl;
		cout << " =======================================================" << endl;
		cin.get();
		
}//end help menu


//Prints the game board and updates the current state
void printBoard(string boardArray[][4], string pegArray[][4],int currentTurn)
{
			cout << " =======================================================" << endl;
		cout << "|	 		Master Mind			|" << endl;
		cout << " =======================================================" << endl;
		cout << "|	 						|" << endl;
		cout << "|     _____________________________ 		    	|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "|    |   ?   ?   ?   ?   |  	   |			|" << endl;
		cout << "|    |___________________|_________|	     		|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "| 12 |   "<<boardArray[11][0]<<"   "<<boardArray[11][1]<<"   "<<boardArray[11][2]<<"   "<<boardArray[11][3]<<"   | "
			<<pegArray[11][0]<<" "<<pegArray[11][1]<<" "<<pegArray[11][2]<<" "<<pegArray[11][3]<<" |	  Turn: " << currentTurn+1 <<"  	|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "| 11 |   "<<boardArray[10][0]<<"   "<<boardArray[10][1]<<"   "<<boardArray[10][2]<<"   "<<boardArray[10][3]<<"   | "
			<<pegArray[10][0]<<" "<<pegArray[10][1]<<" "<<pegArray[10][2]<<" "<<pegArray[10][3]<<" |			|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "| 10 |   "<<boardArray[9][0]<<"   "<<boardArray[9][1]<<"   "<<boardArray[9][2]<<"   "<<boardArray[9][3]<<"   | "
			<<pegArray[9][0]<<" "<<pegArray[9][1]<<" "<<pegArray[9][2]<<" "<<pegArray[9][3]<<" | 'x' = Right Number |" << endl;
		cout << "|    |		 	 |  	   |       Right Spot   |" << endl;
		cout << "|  9 |   "<<boardArray[8][0]<<"   "<<boardArray[8][1]<<"   "<<boardArray[8][2]<<"   "<<boardArray[8][3]<<"   | "
			<<pegArray[8][0]<<" "<<pegArray[8][1]<<" "<<pegArray[8][2]<<" "<<pegArray[8][3]<<" |			|" << endl;
		cout << "|    |		 	 |  	   | 'o' = Right Number |" << endl;
		cout << "|  8 |   "<<boardArray[7][0]<<"   "<<boardArray[7][1]<<"   "<<boardArray[7][2]<<"   "<<boardArray[7][3]<<"   | "
			<<pegArray[7][0]<<" "<<pegArray[7][1]<<" "<<pegArray[7][2]<<" "<<pegArray[7][3]<<" |       Wrong Spot   |" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "|  7 |   "<<boardArray[6][0]<<"   "<<boardArray[6][1]<<"   "<<boardArray[6][2]<<"   "<<boardArray[6][3]<<"   | "
			<<pegArray[6][0]<<" "<<pegArray[6][1]<<" "<<pegArray[6][2]<<" "<<pegArray[6][3]<<" |			|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "|  6 |   "<<boardArray[5][0]<<"   "<<boardArray[5][1]<<"   "<<boardArray[5][2]<<"   "<<boardArray[5][3]<<"   | "
			<<pegArray[5][0]<<" "<<pegArray[5][1]<<" "<<pegArray[5][2]<<" "<<pegArray[5][3]<<" |			|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "|  5 |   "<<boardArray[4][0]<<"   "<<boardArray[4][1]<<"   "<<boardArray[4][2]<<"   "<<boardArray[4][3]<<"   | "
			<<pegArray[4][0]<<" "<<pegArray[4][1]<<" "<<pegArray[4][2]<<" "<<pegArray[4][3]<<" |			|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "|  4 |   "<<boardArray[3][0]<<"   "<<boardArray[3][1]<<"   "<<boardArray[3][2]<<"   "<<boardArray[3][3]<<"   | "
			<<pegArray[3][0]<<" "<<pegArray[3][1]<<" "<<pegArray[3][2]<<" "<<pegArray[3][3]<<" |			|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "|  3 |   "<<boardArray[2][0]<<"   "<<boardArray[2][1]<<"   "<<boardArray[2][2]<<"   "<<boardArray[2][3]<<"   | "
			<<pegArray[2][0]<<" "<<pegArray[2][1]<<" "<<pegArray[2][2]<<" "<<pegArray[2][3]<<" |			|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "|  2 |   "<<boardArray[1][0]<<"   "<<boardArray[1][1]<<"   "<<boardArray[1][2]<<"   "<<boardArray[1][3]<<"   | "
			<<pegArray[1][0]<<" "<<pegArray[1][1]<<" "<<pegArray[1][2]<<" "<<pegArray[1][3]<<" |			|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "|  1 |   "<<boardArray[0][0]<<"   "<<boardArray[0][1]<<"   "<<boardArray[0][2]<<"   "<<boardArray[0][3]<<"   | "
			<<pegArray[0][0]<<" "<<pegArray[0][1]<<" "<<pegArray[0][2]<<" "<<pegArray[0][3]<<" |			|" << endl;

		cout << "|    |___________________|_________|	     		|" << endl;
		cout << "|	 						|" << endl;
		cout << "|    input example: 1234				|" << endl;

		cout << " =======================================================" << endl;
		cout << " I pick number: ";
		
}//end printBoard

//Prints the ending screen of the game with win or lose result
void gameOver(string boardArray[][4], string pegArray[][4],string result)
{
	cout << " =======================================================" << endl;
		cout << "|	 		Master Mind			|" << endl;
		cout << " =======================================================" << endl;
		cout << "|	 						|" << endl;
		cout << "|     _____________________________ 		    	|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "|    |   "<<aiObject.code[0]<<"   "<<aiObject.code[1]<<"   "<<aiObject.code[2]<<"   "<<aiObject.code[3]<<"   |  	   |			|" << endl;
		cout << "|    |___________________|_________|	     		|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "| 12 |   "<<boardArray[11][0]<<"   "<<boardArray[11][1]<<"   "<<boardArray[11][2]<<"   "<<boardArray[11][3]<<"   | "
			<<pegArray[11][0]<<" "<<pegArray[11][1]<<" "<<pegArray[11][2]<<" "<<pegArray[11][3]<<" |	  You " << result <<"!  	|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "| 11 |   "<<boardArray[10][0]<<"   "<<boardArray[10][1]<<"   "<<boardArray[10][2]<<"   "<<boardArray[10][3]<<"   | "
			<<pegArray[10][0]<<" "<<pegArray[10][1]<<" "<<pegArray[10][2]<<" "<<pegArray[10][3]<<" |			|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "| 10 |   "<<boardArray[9][0]<<"   "<<boardArray[9][1]<<"   "<<boardArray[9][2]<<"   "<<boardArray[9][3]<<"   | "
			<<pegArray[9][0]<<" "<<pegArray[9][1]<<" "<<pegArray[9][2]<<" "<<pegArray[9][3]<<" |			|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "|  9 |   "<<boardArray[8][0]<<"   "<<boardArray[8][1]<<"   "<<boardArray[8][2]<<"   "<<boardArray[8][3]<<"   | "
			<<pegArray[8][0]<<" "<<pegArray[8][1]<<" "<<pegArray[8][2]<<" "<<pegArray[8][3]<<" |			|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "|  8 |   "<<boardArray[7][0]<<"   "<<boardArray[7][1]<<"   "<<boardArray[7][2]<<"   "<<boardArray[7][3]<<"   | "
			<<pegArray[7][0]<<" "<<pegArray[7][1]<<" "<<pegArray[7][2]<<" "<<pegArray[7][3]<<" |			|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "|  7 |   "<<boardArray[6][0]<<"   "<<boardArray[6][1]<<"   "<<boardArray[6][2]<<"   "<<boardArray[6][3]<<"   | "
			<<pegArray[6][0]<<" "<<pegArray[6][1]<<" "<<pegArray[6][2]<<" "<<pegArray[6][3]<<" |			|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "|  6 |   "<<boardArray[5][0]<<"   "<<boardArray[5][1]<<"   "<<boardArray[5][2]<<"   "<<boardArray[5][3]<<"   | "
			<<pegArray[5][0]<<" "<<pegArray[5][1]<<" "<<pegArray[5][2]<<" "<<pegArray[5][3]<<" |			|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "|  5 |   "<<boardArray[4][0]<<"   "<<boardArray[4][1]<<"   "<<boardArray[4][2]<<"   "<<boardArray[4][3]<<"   | "
			<<pegArray[4][0]<<" "<<pegArray[4][1]<<" "<<pegArray[4][2]<<" "<<pegArray[4][3]<<" |			|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "|  4 |   "<<boardArray[3][0]<<"   "<<boardArray[3][1]<<"   "<<boardArray[3][2]<<"   "<<boardArray[3][3]<<"   | "
			<<pegArray[3][0]<<" "<<pegArray[3][1]<<" "<<pegArray[3][2]<<" "<<pegArray[3][3]<<" |			|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "|  3 |   "<<boardArray[2][0]<<"   "<<boardArray[2][1]<<"   "<<boardArray[2][2]<<"   "<<boardArray[2][3]<<"   | "
			<<pegArray[2][0]<<" "<<pegArray[2][1]<<" "<<pegArray[2][2]<<" "<<pegArray[2][3]<<" |			|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "|  2 |   "<<boardArray[1][0]<<"   "<<boardArray[1][1]<<"   "<<boardArray[1][2]<<"   "<<boardArray[1][3]<<"   | "
			<<pegArray[1][0]<<" "<<pegArray[1][1]<<" "<<pegArray[1][2]<<" "<<pegArray[1][3]<<" |			|" << endl;
		cout << "|    |		 	 |  	   |			|" << endl;
		cout << "|  1 |   "<<boardArray[0][0]<<"   "<<boardArray[0][1]<<"   "<<boardArray[0][2]<<"   "<<boardArray[0][3]<<"   | "
			<<pegArray[0][0]<<" "<<pegArray[0][1]<<" "<<pegArray[0][2]<<" "<<pegArray[0][3]<<" |			|" << endl;

		cout << "|    |___________________|_________|	     		|" << endl;
		cout << "|	 						|" << endl;
		cout << "| 							|" << endl;

		cout << " =======================================================" << endl;
		cin.get();
}//end gameOver

bool playAgain()
{
	bool again = false;
	bool valid = false;
	string userInput;

	do{
	cout << " =======================================================" << endl;
		cout << "|			Master Mind			|" << endl;
		cout << " =======================================================" << endl;
		cout << "|							|" << endl;
		cout << "|							|" << endl;
		cout << "|							|" << endl;
		cout << "|				    			|" << endl;
		cout << "|				    			|" << endl;
		cout << "|				    			|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|				    			|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			Play Again??  			|" << endl;
		cout << "|				    			|" << endl;
		cout << "|			Yes   -  1			|" << endl;
		cout << "|			No    -  2    			|" << endl;
		cout << "|				    			|" << endl;
		cout << "|				    			|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|				    			|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|				    			|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|				    			|" << endl;
		cout << "|			    				|" << endl;
		cout << "|			    				|" << endl;
		cout << "|				    			|" << endl;
		cout << " =======================================================" << endl;
		
		getline(cin,userInput);
		valid = valObject.playAgainInput(userInput);
		}while(valid != true);
		
	if(userInput == "1")
	{
		again = true;
	}
	else if(userInput == "2")
	{
		again = false;
	}

	return again;
}

//Gets the menu input from the user
int getMenuInput()
{
	int input;
	string userInput;
	getline(cin,userInput);
	stringstream(userInput) >> input;
	return input;
}//end getMenuInput

//Gets the users code guess
void userGuess(string boardArray[][4], int turn, string s)
{
	for(int i=0; i<4;i++)
	{
		boardArray[turn][i] = s[i];
	}
	
}//end userGuess