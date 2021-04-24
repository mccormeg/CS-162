/*********************************************************************************
** Program: BetterRoomba.h
** Author: Megan McCormick
** Date: 05/26
** Description: Class definition and function prototypes for BetterRoomba
** Input: None
** Output: None
**********************************************************************************/
#ifndef BROOMBA_H
#define BROOMBA_H
#include"Roomba.h"
class BetterRoomba : public Roomba { 
	private:
		void clean_floor(Floor&);
		void set_up(Floor &);
		void prt(Floor &);
		void change();
		void spirial(Floor &);
		void square(Floor &);
};
#endif