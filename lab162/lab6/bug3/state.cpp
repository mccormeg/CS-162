/*
 * state.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: eecs162
 */
#include <iostream>
#include <cstring>
#include "state.h"

using namespace std;

void state::set_name(const char *n) {
	delete [] name;
	name=new char[strlen(n)+1];
	strcpy(name, n);
}

void state::display_name() {
	cout << "State is: " << name << endl;
}

void state::set_pop(int n){
    this->pop=n;
}

void state::display_pop() {
	cout << "state, " << name << ", pop: " << pop << endl;
}

state::state() {
	pop=0;
	name=NULL;
}

state::~state() {

   delete [] name;
   
}

state::state(const state &other){
	
   if(sizeof(human) ==0){

      human = NULL;
   }
   else{
      human = new char [sizeof(human)+1];
      for(int j=0;j<sizeof(human)+1; j++){
	    human[j] = other.human[j];
      }
   }
   if(sizeof(ai) ==0){

      ai = NULL;
   }
   else{
      ai = new char [sizeof(ai)+1];
      for(int j=0;j<sizeof(human)+1; j++){
	    ai[j] = other.ai[j];
      }
   }
   
}

void state::operator =(const state &other){
	
   if(human!=NULL){
	   delete [] human;
   }
    if(sizeof(human) ==0){

      human = NULL;
   }
   else{
      human = new char [sizeof(human)+1];
      for(int j=0;j<sizeof(human)+1; j++){
	    human[j] = other.human[j];
      }
   }
   if(ai!=NULL){
	   delete [] ai;
   }
   if(sizeof(ai) ==0){

      ai = NULL;
   }
   else{
      ai = new char [sizeof(ai)+1];
      for(int j=0;j<sizeof(human)+1; j++){
	    ai[j] = other.ai[j];
      }
   }
   
}