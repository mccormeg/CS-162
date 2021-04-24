/*************************************************************************
** Program Filename: Scissors.cpp
** Author: Megan MCCormick
** Date: 5/10/15
** Description: Function definitions for Scissors
** Input: None
** Output: None
*************************************************************************/
#include "Scissors.h"
#include <iostream>
using namespace std;
/*********************************************************************************
** Function: Scissors()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
Scissors::Scissors(){
	strength = 1;
	type = 's';
}
/*********************************************************************************
** Function: Scissors(int a)
** Description: Constructor for Scissors
** Parameters: int a
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
Scissors::Scissors(int a){
	strength = a;
	type = 's';
}
/*********************************************************************************
** Function: fight(Tool a) 
** Description: Compares tools
** Parameters: Tool a
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
int Scissors::fight(Tool a){
	int str;
	str = strength;
	if (a.get_type()== 'p'){
		str = str*2;
		if(str>a.get_strength()){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if(a.get_type()== 'r'){
		str = str/2;
		if(str>a.get_strength()){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if(a.get_type()=='s'){
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