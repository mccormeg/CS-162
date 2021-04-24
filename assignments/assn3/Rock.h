/*************************************************************************
** Program Filename: Rock.h
** Author: Megan MCCormick
** Date: 5/10/15
** Description: Prototypes for Rock class
** Input: None
** Output: None
*************************************************************************/
#ifndef ROCK_H
#define ROCK_H
#include "Tool.h"
class Rock : public Tool{
	public:
	Rock();
	Rock(int);
	int fight(Tool);
};
#endif