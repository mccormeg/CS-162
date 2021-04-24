/*********************************************************************************
** Program: Roomba.h
** Author: Megan McCormick
** Date: 05/26/2015
** Description: Class definitiona and fuction prototypes
** Input: None	
** Output: None
**********************************************************************************/
#ifndef ROOMBA_H
#define ROOMBA_H
#include"Floor.h"
class Roomba {
	private:
		int battery; //how many moves it can make
		int total_moves; //total moves needed to clean
		int view;
	public:
		Roomba();
		Roomba(int,int);
		void set_battery(int);
		void set_view(int);
		void change_battery();
		void change_total_moves();
		int get_view();
		int get_battery();
		int get_total_moves();
		virtual void clean_floor(Floor&);
		bool dead();
		void print();
	//The Roomba needs to be able to clean a floor, and
	//move left, right, up, down

};
#endif