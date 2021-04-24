/*********************************************************************************
** Program: RandomRoomba.h
** Author: Megan McCormick
** Date: 05/26/2015
** Description: Class definition and function prototypes for RandomRoomba
** Input: None
** Output: None
**********************************************************************************/
#ifndef RROOMBA_H
#define RROOMBA_H
#include"Roomba.h"
class RandomRoomba : public Roomba {
	public:
		void clean_floor(Floor&);
		void prt(Floor &);
		void change();
};
#endif