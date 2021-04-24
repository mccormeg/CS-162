/*********************************************************************************
** Program: movie.h
** Author: Megan McCormick
** Date: 04/26/15
** Description: Function prototypes
** Input: None
** Output: None
**********************************************************************************/
#ifndef MOVIE_H
#define MOVIE_H
#include<iostream>
#include<string>

using namespace std;

class movie{
   public:
      movie();
      movie(int);
	  movie(char*);
      ~movie();//destructor
      movie(const movie &);//copy constructor
      void operator = (const movie &);// assignment operator overload
	  void set_name();
	  void set_stars();
	  void set_cast(int);
	  void set_rating();
	  void set_copies();
	  string get_name();
	  int get_stars();
	  int get_num_cast();
	  string get_cast(int);
	  string get_rating();
	  int get_copies();	  
   private:
      string name;
      int stars;
      int num_cast;
      string *cast;
      string rating;
      int copies;
};
#endif
