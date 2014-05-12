//Validation class implementation file
//This is the implementation part of the class



#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <conio.h>
using namespace std;

#include "Validation.h" // include header file
	

	validation::validation(void){}  //constructor
	validation::~validation(void){}//decontructor

	//Randomly creates a code for the user to crack
	bool validation::TurnInput(string input)
	{
		bool valid = true;
		int length = input.length();
		
		if(length >=1 && length <=2)
		{
			valid = false;
		}

		if(input == "12" || input == "10" || input == "8" )
		{
			valid = true;
		}else{
			valid = false;
		}
		
		return valid;
	}

	bool validation::playAgainInput(string input)
	{
		bool valid = true;
		int length = input.length();
		if(length != 1)
		{
			valid = false;
		}

		if(input == "1" || input == "2")
		{
			valid = true;
		}else{
			valid = false;
		}

		return valid;
	}

	bool validation::codeInput(string input)
	{
		bool valid = true;
		int length = input.length();
		if(length != 4)
		{
			valid = false;
		}

		for(int i =0; i<4; i++)
		{
			
			int thing = input[i];
			if(thing >= 55 || thing <= 48)
			{
				valid = false;
			}
		}
		return valid;
	}
		
	