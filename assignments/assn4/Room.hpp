/*********************************************************************************
** Program: Room.hpp
** Author: Megan McCormick
** Date: 05/26/2015
** Description: HPP file for ROom
** Input: None
** Output: None
**********************************************************************************/
#ifndef ROOM_HPP
#define ROOM_HPP
#include"Floor.h"
#include"Roomba.h"
#include<cstdlib>
template <typename T>
class Room {
	private:
		Floor f;
		T *obj; //obj could be a Roomba, Person, etc.
	public:
		Room(){}
/*********************************************************************************
** Function: ~Room()
** Description: destructor
** Parameters: None
** Pre-Conditions: None
** Post-conditions: Destroy
*********************************************************************************/
		~Room(){
			delete [] obj;
		}
/*********************************************************************************
** Function: set_roomba(T roomba)
** Description: Sets roomba
** Parameters: T roomba
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
		void set_roomba(T roomba){
			obj = roomba;
		}

/*********************************************************************************
** Function: T* get_obj()
** Description: returns obj
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
		T* get_obj(){
			return obj;
		}
/*********************************************************************************
** Function: set_floor(Floor flo)
** Description: sets Floor
** Parameters: Floor
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
		void set_floor(Floor flo){
			f = flo;
		}
		
		
		//The functionality of a room is to view it, put
		//objects in it, take objects out of it, etc.
/*********************************************************************************
** Function: clean_room()
** Description: cleans room
** Parameters: None
** Pre-Conditions: Dirty
** Post-conditions: Clean
*********************************************************************************/
		void clean_room() {
			if(obj!=NULL)
				obj->clean_floor(f);
		}
/*********************************************************************************
** Function: set_roomba(Roomba *r)
** Description: sets Roomba
** Parameters: Romba *r
** Pre-Conditions: None
** Post-conditions: Roomba
*********************************************************************************/
		void set_roomba(Roomba *r){
			obj = r;
		}
		
};
#endif




