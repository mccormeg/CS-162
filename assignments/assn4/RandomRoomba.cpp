/*********************************************************************************
** Program: RandomRoomba.cpp
** Author: Megan McCormick
** Date: 05/26/2015
** Description: All functions for RandomRoomba
** Input: None
** Output: None
**********************************************************************************/
#include"RandomRoomba.h"
#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;
/*********************************************************************************
** Function: clean_floor(Floor &f)
** Description: CLeans the floor
** Parameters: Floor &
** Pre-Conditions: Dirty
** Post-conditions: Clean
*********************************************************************************/
void RandomRoomba::clean_floor(Floor &f){
	int i;
	srand(time(NULL));
	do{
		i = rand()%4;
		if(i==0&&f.get_obj_row()!=0){
			f.move_up();
			change();
			prt(f);
		}
		else if (i == 1&& f.get_obj_row()<f.get_row()-1){
			f.move_down();
			change();
			prt(f);
		}
		else if (i == 2 && f.get_obj_col() !=0){
			f.move_left();
			change();
			prt(f);
		}
		else if (i == 3 && f.get_obj_col()<f.get_col()-1){
			f.move_right();
			change();
			prt(f);
		}
		else if(dead()==1){
			cout<<"Oh no! You killed your Roomba"<<endl;
		}
	}while(f.full()==0&& dead()==0);
}
/*********************************************************************************
** Function: prt(Floor &f)
** Description: Prints
** Parameters: Floor &f
** Pre-Conditions: None
** Post-conditions: Printed stuff
*********************************************************************************/
void RandomRoomba::prt(Floor &f){
	if (get_total_moves() % get_view() == 0){
		print();
		f.print();
	}
	
}
/*********************************************************************************
** Function: change()
** Description: Changes values
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
void RandomRoomba::change(){
	change_battery();
	change_total_moves();
}