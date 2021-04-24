/*********************************************************************************
** Program: Roomba.cpp
** Author: Megan McCormick
** Date: 05/26/2015
** Description: All funtions for Roomba
** Input: None
** Output: None
**********************************************************************************/
#include"Roomba.h"
#include<iostream>
using namespace std;
/*********************************************************************************
** Function: Roomba()
** Description: constructor
** Parameters: None
** Pre-Conditions: None
** Post-conditions: Defualt construtr
*********************************************************************************/

Roomba::Roomba(){
	battery = 0;
	total_moves =0;
	view = 0;
}
/*********************************************************************************
** Function: Roomba(int b, int v)
** Description: Constructor
** Parameters: int b, int v
** Pre-Conditions: No Roomba
** Post-conditions: Yes Roomba 
*********************************************************************************/
Roomba::Roomba(int b, int v){
	battery = b;
	total_moves = 0;
	view = v;
}
/*********************************************************************************
** Function: set_battery(int b)
** Description: Sets Battery
** Parameters: int b
** Pre-Conditions: None
** Post-conditions: set battery
*********************************************************************************/
void Roomba::set_battery(int b){
	battery = b;
}
/*********************************************************************************
** Function: set_view(int v)
** Description: Sets view
** Parameters: int v
** Pre-Conditions: None
** Post-conditions: set view
*********************************************************************************/
void Roomba::set_view(int v){
	view = v;
}
/*********************************************************************************
** Function: change_battery()
** Description: Changes battery
** Parameters: None
** Pre-Conditions: None
** Post-conditions: New battery value
*********************************************************************************/
void Roomba::change_battery(){
	battery --;
}
/*********************************************************************************
** Function: change_total_moves()
** Description: Changes total
** Parameters: None
** Pre-Conditions: None
** Post-conditions: New total
*********************************************************************************/
void Roomba::change_total_moves(){
	total_moves ++;
}
/*********************************************************************************
** Function: get_battery()
** Description: Gets battery
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/

int Roomba::get_battery(){
	return battery;
}
/*********************************************************************************
** Function: get_total_moves()
** Description: Gets total
** Parameters: NOne
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
int Roomba::get_total_moves(){
	return total_moves;
}
/*********************************************************************************
** Function: print()
** Description: Prints moves
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
void Roomba::print(){
	cout<<"Move: "<<total_moves<<endl;
}
/*********************************************************************************
** Function: clean_floor(Floor&)
** Description: Looks pretty
** Parameters: Floor &
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
void Roomba::clean_floor(Floor&){
	
}
/*********************************************************************************
** Function: dead()
** Description: Returns a bool when you have killed you poor Roomba
** Parameters: None
** Pre-Conditions: None
** Post-conditions: Bool
*********************************************************************************/
bool Roomba::dead(){
	if (battery == 0){
		return 1;
	}
	else 
		return 0;
}
/*********************************************************************************
** Function: get_view()
** Description: return view
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
int Roomba::get_view(){
	return view;
}