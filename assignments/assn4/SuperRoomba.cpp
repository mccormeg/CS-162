/*********************************************************************************
** Program: SuperRoomba.cpp
** Author: Megan McCormick
** Date: 05/26/2015
** Description: All fuctions for SuperRoomba
** Input: None
** Output: None
**********************************************************************************/
#include"SuperRoomba.h"
#include<iostream>
using namespace std;
/*********************************************************************************
** Function: clean_floor(Floor &f)
** Description: Clean floor
** Parameters: Floor &f
** Pre-Conditions: Dirty floor
** Post-conditions: Clean floor
*********************************************************************************/
void SuperRoomba::clean_floor(Floor &f){
	set_up(f);
	for (int i =0; i<f.get_row(); i++){
		for (int k = 0; k<f.get_col()-1; k++){
			if(dead() ==1){
				break;
			}
			if (i%2 == 0){
				f.move_right();
				change();
				prt(f);
			}
			else if(i%2 == 1){
				f.move_left();
				change();
				prt(f);
			}
			else if (f.full()==1){
				break;
			}
			
		}
		if(dead() ==1){
			break;
			cout<<"Oh no! You killed your Roomba"<<endl;
		}
		if (f.full()==1){
				break;
		}
		else {
			change();
			prt(f);
			f.move_down();	
		}
	}
}
/*********************************************************************************
** Function: set_up(Floor &f)
** Description: Puts roomba in the left hand top corner
** Parameters: Floor &f
** Pre-Conditions: Roomba placement
** Post-conditions: Left hand corner
*********************************************************************************/
void SuperRoomba::set_up(Floor &f){
	int r, c;
	r = f.get_obj_row();
	c = f.get_obj_col();
	for (int i = 0; i<r; i++){
		f.move_up();
		change();
		prt(f);
	}
	for (int j = 0; j < c; j++){
		f.move_left();
		change();
		prt(f);
	}
}
/*********************************************************************************
** Function: prt(Floor &f)
** Description: Prints
** Parameters: Floor &f
** Pre-Conditions: None
** Post-conditions: Printed values
*********************************************************************************/
void SuperRoomba::prt(Floor &f){
	if (get_total_moves() % get_view() == 0){
		print();
		f.print();
	}
	
}
/*********************************************************************************
** Function:change()
** Description: Changes battery value, change total moves value
** Parameters: None
** Pre-Conditions: Original values
** Post-conditions: New values
*********************************************************************************/
void SuperRoomba::change(){
	change_battery();
	change_total_moves();
}