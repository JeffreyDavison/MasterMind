//validation Header file
//This is the interface for the class validation
//this ensures the player does not input something they shouldn't

#ifndef VALIDATION_H//if not defined
#define VALIDATION_H//

#include <iostream>
using namespace std;

class validation
{
public:
	validation(void); //constructor
	virtual ~validation(void);//deconstructor

	bool TurnInput(string input);
	bool playAgainInput(string input);
	bool codeInput(string input);

};
#endif //end the if not defined statement


