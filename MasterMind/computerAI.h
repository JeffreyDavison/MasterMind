//computerAI Header file
//This is the interface for the class AI


#ifndef computerAI_H//if not defined
#define computerAI_H//

#include <iostream>
using namespace std;

class computerAI
{
private:
	

public:
	string code[4];
	int duplicate;
	computerAI(void); //constructor
	virtual ~computerAI(void);//deconstructor

	void createCode();
	void keyPeg(string pegArray[12][4], string boardArray[12][4], int currentTurn);
	bool winCheck( string boardArray[12][4], int currentTurn);
};
#endif //end the if not defined statement

