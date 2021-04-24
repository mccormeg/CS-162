/*************************************************************************
** Program Filename: Scissors.h
** Author: Megan MCCormick
** Date: 5/10/15
** Description: Prototypes for Scissors class
** Input: None
** Output: None
*************************************************************************/
#ifndef SCISSORS_H
#define SCISSORS_H
#include "Tool.h"
class Scissors : public Tool{
	public: 
	Scissors();
	Scissors(int);
	int fight(Tool);
};
#endif