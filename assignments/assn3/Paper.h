/*************************************************************************
** Program Filename: Paper.h
** Author: Megan MCCormick
** Date: 5/10/15
** Description: Function prototypes for Paper class
** Input: None
** Output: None
*************************************************************************/
#ifndef PAPER_H
#define PAPER_H
#include "Tool.h"
class Paper : public Tool{
	public:
	Paper();
	Paper(int);
	int fight(Tool);
};
#endif 