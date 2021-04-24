/*************************************************************************
** Program Filename: Tool.h
** Author: Megan MCCormick
** Date: 5/10/15
** Description: Prototypes for Tool class
** Input: None
** Output: None
*************************************************************************/
#ifndef TOOL_H
#define TOOL_H

class Tool {
	protected:
	int strength;
	char type;
	public:
	Tool();
	Tool(int,char);
	void setStrength(int);
	virtual char get_type();
	virtual int get_strength();
};
#endif