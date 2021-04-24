/*********************************************************************************
** Program: Floor.cpp
** Author: Megan McCormick
** Date: 05/26
** Description: All functions for floor 
** Input: None
** Output: None
**********************************************************************************/
#include"Floor.h"
#include <fstream>
#include<iostream>
using namespace std;
/*********************************************************************************
** Function: Floor()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
Floor::Floor(){
	obj_row = 0;
	obj_col = 0;
	row = 0;
	col = 0;
}
/*********************************************************************************
** Function: Floor(int r , int c, int pr, int pc)
** Description: Sets floor
** Parameters: int r , int c, int pr, int pc
** Pre-Conditions: None
** Post-conditions: Floor
*********************************************************************************/
Floor::Floor(int r , int c, int pr, int pc){
	for (int i =0; i<r; i++){
		v.push_back(vector<char>());
	}
	for(int j =0;j<c;j++){
		for(int k = 0;k<v.size();k++){
			v[k].push_back(k*j);
		}
	}
	cout<<"Start: "<<endl;
	for(int k = 0; k<r; k++){
		for(int l = 0; l<c; l++){
			v[k][l] = 'f';
			v[pr][pc]='r';
			
			cout<<v[k][l]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	obj_row = pr;
	obj_col = pc;
	row = r;
	col = c;
}
/*********************************************************************************
** Function: get_v(int r, int c)
** Description: gets v
** Parameters: int r, int c
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
char Floor::get_v(int r, int c){
	return v[r][c];
}
/*********************************************************************************
** Function: move_up()
** Description: Moves up
** Parameters: None
** Pre-Conditions: None
** Post-conditions: Up
*********************************************************************************/
void Floor::move_up(){
	v[obj_row][obj_col]= 'c';
	obj_row -=1;
	v[obj_row][obj_col]= 'r';
	
	
}
/*********************************************************************************
** Function: move_down()
** Description: moves down
** Parameters: None
** Pre-Conditions: None
** Post-conditions: Down
*********************************************************************************/
void Floor::move_down(){
	v[obj_row][obj_col]= 'c';
	obj_row +=1;
	v[obj_row][obj_col]= 'r';
}
/*********************************************************************************
** Function: move_left()
** Description: Moves Left
** Parameters: None
** Pre-Conditions: None
** Post-conditions: Left
*********************************************************************************/
void Floor::move_left(){
	v[obj_row][obj_col]= 'c';
	obj_col -= 1;
	v[obj_row][obj_col]= 'r';
	
}
/*********************************************************************************
** Function: move_right()
** Description: Moves right
** Parameters: None
** Pre-Conditions: None
** Post-conditions: right
*********************************************************************************/
void Floor::move_right(){
	v[obj_row][obj_col]= 'c';
	obj_col += 1;
	v[obj_row][obj_col]= 'r';
	
}
/*********************************************************************************
** Function: print()
** Description: Prints stuff
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
void Floor::print(){
	for(int i = 0; i<row; i++){
		for (int j = 0; j< col; j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
/*********************************************************************************
** Function: get_obj_row()
** Description: gets obj row
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
int Floor::get_obj_row(){
	return obj_row;
}
/*********************************************************************************
** Function: get_obj_col()
** Description: gets obj col
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
int Floor::get_obj_col(){
	return obj_col;
}
/*********************************************************************************
** Function: get_row()
** Description: gets rows
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
int Floor::get_row(){
	return row;
}
/*********************************************************************************
** Function: get_col()
** Description: gets col
** Parameters: None 
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
int Floor::get_col(){
	return col;
}
/*********************************************************************************
** Function: full()
** Description: Checks if the floor is clean
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
bool Floor::full(){
	for (int i =0; i<row; i++){
		for (int j = 0; j <col; j++){
			if (v[i][j]!='c' && v[i][j]!= 'r'){
				return 0;
			}
		}
	}
	return 1;
}
