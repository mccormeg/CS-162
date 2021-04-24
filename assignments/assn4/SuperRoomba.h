/*********************************************************************************
** Program: SuperRoomba
** Author: Megan McCormick
** Date: 05/26/2015
** Description: The mos super Roomba 
** Input: None
** Output: Clean
**********************************************************************************/
#ifndef SROOMBA_H
#define SROOMBA_H
#include"Roomba.h"
class SuperRoomba : public Roomba {
	private:
		void clean_floor(Floor&);
		void set_up(Floor &);
		void prt(Floor &);
		void change();
};
#endif