/*************************************************************************
** Program Filename: Tool.cpp
** Author: Megan MCCormick
** Date: 5/10/15
** Description: Defines all functions associated with the Tool class
** Input: None
** Output: None
*************************************************************************/
#include "Tool.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"
/*********************************************************************************
** Function: Tool()
** Description: Defult constructor
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
Tool::Tool(){}
/*********************************************************************************
** Function: Tool(int a,char b)
** Description: Sets values through constructor
** Parameters: int a,char b
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
Tool::Tool(int a,char b){
	strength = a;
	type = b;
}
/*********************************************************************************
** Function: setStrength(int a)
** Description: Sets strength
** Parameters: int a
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
void Tool::setStrength(int a){
	strength = a;
}
/*********************************************************************************
** Function: get_type()
** Description: Returns type
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
char Tool::get_type(){
	return type;
}
/*********************************************************************************
** Function: get_strength()
** Description: Returns strength
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
int Tool::get_strength(){
	return strength;
}