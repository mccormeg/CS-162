/*********************************************************************************
** Program:Floor.h
** Author: Megan McCormick
** Date: 05/26/2015
** Description: Floor class definition and function prototypes 
** Input: None
** Output: None
**********************************************************************************/
#ifndef FLOOR_H
#define FLOOR_H
#include<vector>
#include<cstdlib>
using namespace std;

class Floor {
	private:
		vector < vector <char> > v;
		int obj_row; //Holds an object’s current row position
		int obj_col; //Holds an object’s current col position
		int row;
		int col;
	public:
		Floor();
		Floor(int r , int c, int pr, int pc);
		vector < vector <char> > set_v();
		char get_v(int,int);
		void set_obj_row();
		void set_obj_col();
		int get_obj_row();
		int get_obj_col();
		int get_row();
		int get_col();
		int check_pos();
		void move_up();
		void move_down();
		void move_left();
		void move_right();
		void print();
		bool full();
		
	//The functionality of a floor is to create the floor
	//plan, as well as determining if an object’s
	//position is at the edge of the room

};
#endif