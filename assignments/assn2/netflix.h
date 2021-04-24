/*********************************************************************************
** Program: netflix.h
** Author: Megan McCormick
** Date: 04/26/15
** Description: Function prototypes
** Input: None
** Output: None
**********************************************************************************/
#ifndef NETFLIX_H
#define NETFLIX_H
#include"./movie.h"

class movie;

class netflix{
   public:
      netflix();
      netflix(int);
      ~netflix();//destructor
      netflix(const netflix &);//copy constructor
      void operator =(const netflix &); //assignment operator overload
	  void set_m(int,int &);
	  movie* get_m();
	  private:
      movie *m;
      int num_movies;
};
#endif
