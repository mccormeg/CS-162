#include "./motorcycle.h"
motorcycle::motorcycle():vehicle(){}

motorcycle::motorcycle(int x):vehicle(x){}


int motorcycle::get_toll(int s){
	return s*20;
}