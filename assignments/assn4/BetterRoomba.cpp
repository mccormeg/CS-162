/*********************************************************************************
** Program: BetterRoomba.cpp
** Author: Megan McCormick
** Date: 05/26
** Description: All functions for BetterRoomba
** Input: None
** Output: None
**********************************************************************************/
#include"BetterRoomba.h"
#include<iostream>
using namespace std;
/*********************************************************************************
** Function: clean_floor(Floor &f)
** Description: Cleans floors
** Parameters: Floor &
** Pre-Conditions: Dirty
** Post-conditions: Clean
*********************************************************************************/
void BetterRoomba::clean_floor(Floor &f){
	if(f.get_row()==f.get_col()){
		square(f);
	}	
	else {
		spirial(f);
	}
}
/*********************************************************************************
** Function: set_up(Floor &f)
** Description: Sets up the roomba in the corner
** Parameters: Floor &f
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
void BetterRoomba::set_up(Floor &f){
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
** Description: prints all the things
** Parameters: Floor &
** Pre-Conditions: None
** Post-conditions: Things
*********************************************************************************/
void BetterRoomba::prt(Floor &f){
	if (get_total_moves() % get_view() == 0){
		print();
		f.print();
	}
	
}
/*********************************************************************************
** Function: spirial(Floor &f)
** Description: does a cool spinny thing
** Parameters: Floor &f
** Pre-Conditions: Dirty
** Post-conditions: Clean
*********************************************************************************/
void BetterRoomba::spirial(Floor &f){
	int p=0,r=0, i = 0;;
	set_up(f);
	do{
		for (int j = 0;j < f.get_col()-1-i; j ++){
			if(dead() ==1){
				break;
			}
			if (f.full()==1){
				break;
			}
			f.move_right();
			change();
			prt(f);
			
		}
		r++;
		for(int k = 0; k <f.get_row()-r; k++){
			if(dead() ==1){
				break;
			}
			if (f.full()==1){
				break;
			}
			f.move_down();
			change();
			prt(f);
		}
		p++;
		for (int j = 0;j < f.get_col()-p; j ++){
			if(dead() ==1){
				break;
			}
			if (f.full()==1){
				break;
			}
			f.move_left();
			change();
			prt(f);
		}
		r++;
		for (int k = 0; k<f.get_row()-r;k++){
			if(dead() ==1){
				break;
			}
			if (f.full()==1){
				break;
			}
			f.move_up();
			change();
			prt(f);
		}
		p++;
		i++;
		if (f.full()==1){
				break;
		}
		if(dead() ==1){
			cout<<"Oh no! You killed your Roomba"<<endl;
				break;
			}
		
	}while(f.full()==0 && dead()==0);
}
/*********************************************************************************
** Function: change()
** Description: changes stuff
** Parameters: none
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
void BetterRoomba::change(){
	change_battery();
	change_total_moves();
}
/*********************************************************************************
** Function: square(Floor &f)
** Description: Does spiral on a square
** Parameters: Floor &
** Pre-Conditions: Dirty
** Post-conditions: Clean
*********************************************************************************/
void BetterRoomba::square(Floor &f){
	int p=0,r=0,i = 1;
	set_up(f);
	do{
		for (int j = 0;j < f.get_col()-i-p; j ++){
			if(dead() ==1){
				break;
			}
			if (f.full()==1){
				break;
			}
			f.move_right();
			change();
			prt(f);
			
		}
		r++;
		for(int k = 0; k <f.get_row()-r; k++){
			if(dead() ==1){
				break;
			}
			if (f.full()==1){
				break;
			}
			f.move_down();
			change();
			prt(f);
		}
		p++;
		for (int j = 0;j < f.get_col()-p; j ++){
			if(dead() ==1){
				break;
			}
			if (f.full()==1){
				break;
			}
			f.move_left();
			change();
			prt(f);
		}
		r++;
		for (int k = 0; k<f.get_row()-r;k++){
			if(dead() ==1){
				break;
			}
			if (f.full()==1){
				break;
			}
			f.move_up();
			change();
			prt(f);
		}
		p++;
		i= 0;
		if (f.full()==1){
				break;
		}
		if(dead() ==1){
			cout<<"Oh no! You killed your Roomba"<<endl;
				break;
			}
		
	}while(f.full()==0 && dead()==0);
}

