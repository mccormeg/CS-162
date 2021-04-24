/*************************************************************************
** Program Filename: Rock.cpp
** Author: Megan MCCormick
** Date: 5/10/15
** Description: Function definitions for Rock class
** Input: None
** Output: None
*************************************************************************/
#include "Rock.h"
#include <iostream>
using namespace std;

/*********************************************************************************
** Function: Rock()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
Rock::Rock(){
	strength = 1;
	type = 'r';
}
/*********************************************************************************
** Function: Rock(int a)
** Description: None default constructor
** Parameters: int a
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
Rock::Rock(int a){
	strength = a;
	type = 'r';
}
/*********************************************************************************
** Function: fight(Tool a)
** Description: Compares tools
** Parameters: Tool a
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
int Rock::fight(Tool a){
		int str;
	str = strength;
	if (a.get_type()== 's'){
		str = str*2;
		if(str>a.get_strength()){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if(a.get_type()== 'p'){
		str = str/2;
		if(str>a.get_strength()){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if(a.get_type()=='r'){
		if (str>a.get_strength()){
			return 1;
		}
		else if(str = a.get_strength()){
			return 2;
		}
		else {
			return 0;
		}
	
	}	
}