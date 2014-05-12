//computerAI class implementation file
//This is the implementation part of the class



#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <conio.h>
using namespace std;

#include "computerAI.h" // include header file
	

	computerAI::computerAI(void)
		:code(){}  //constructor
	computerAI::~computerAI(void){}//decontructor

	//Randomly creates a code for the user to crack
	void computerAI::createCode()
	{
		srand(time(0)); //seed with time

		code[0]= to_string(1 + rand() %7);
		code[1] = to_string(1 + rand() %7);
		code[2] = to_string(1 + rand() %7);
		code[3] = to_string(1 + rand() %7);
	}//end createCode

	//generates feedback to user about their guess
	void computerAI::keyPeg(string pegArray[12][4], string boardArray[12][4], int turn)
	{
		string temp[4] = {" "," "," "," "};
		int tempDup = duplicate;
		int x = 0;
		int o = 0;

		for(int i =0; i < 4; i++)
		{   
			if(boardArray[turn][i] == code[i])
			{
				temp[i] = "x";
				x++;
			}//end if
		}

		for(int i =0; i < 4; i++)
			{  
				for(int i2=0; i2 < 4; i2++)
				{
					
					if(boardArray[turn][i] == code[i2] && temp[i2] == " " && i2 != i && temp[i] != "x")
					{
						temp[i2] = "o";
						o++;
						i2=4;
					}//end if
					
				}//end for
			}//end for
			

		for(int i =0; i < 4; i++)
			{
				if(x > 0)
				{ 
				pegArray[turn][i] = "x";
				x--;
				}else if(o > 0)
				{ 
				pegArray[turn][i] = "o";
				o--;
				}
			}
		


	
	}//end keyPeg

	//checks to see if the users guess is fully correct
	bool computerAI::winCheck(string boardArray[12][4], int turn)
	{
		  
		if(boardArray[turn][0] == code[0] &&
		   boardArray[turn][1] == code[1] &&
		   boardArray[turn][2] == code[2] &&
		   boardArray[turn][3] == code[3])
		{
			return true;
		}else
		{
			return false;
		}
			
		

		return "";
	}//end WinCheck