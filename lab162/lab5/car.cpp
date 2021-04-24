#include "./car.h"

car::car():vehicle(){}

car::car(int x):vehicle(x){}


int car::get_toll(int seats){
   return seats*20;
}