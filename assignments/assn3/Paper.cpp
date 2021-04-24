/*************************************************************************
** Program Filename: Paper.cpp
** Author: Megan MCCormick
** Date: 5/10/15
** Description: Function definitions for Paper class
** Input: None
** Output: None
*************************************************************************/
#include "Paper.h"
#include<iostream>
using namespace std;
/*********************************************************************************
** Function: Paper()
** Description: Defualt constructor 
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
Paper::Paper(){
	strength = 1;
	type = 'p';
}
/*********************************************************************************
** Function: Paper(int a)
** Description: Non-defualt constructor
** Parameters: int a
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
Paper::Paper(int a){
	strength = a;
	type = 'p';
}
/*********************************************************************************
** Function: fight(Tool a)
** Description: Compares tools and returns an int
** Parameters: Tool a
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
int Paper::fight(Tool a){
	int str;
	str = strength;
	if (a.get_type()== 'r'){
		str = str*2;
		if(str>a.get_strength()){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if(a.get_type()== 's'){
		str = str/2;
		if(str>a.get_strength()){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if(a.get_type()=='p'){
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