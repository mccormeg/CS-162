/*********************************************************************************
** Program: netflix.cpp
** Author: Megan McCormick
** Date: 04/26/15
** Description: netflix.cpp
** Input: None
** Output: None
**********************************************************************************/
#include"./netflix.h"
#include"./movie.h"
/*********************************************************************************
** Function: netflix()
** Description: default constructor
** Parameters: none
** Pre-Conditions: empty class 
** Post-conditions: full class
*********************************************************************************/
netflix::netflix():m(){num_movies = 1; m=new movie[num_movies];}
/*********************************************************************************
** Function:netflix
** Description: constructor
** Parameters: int
** Pre-Conditions: empty class 
** Post-conditions: full class
*********************************************************************************/
netflix::netflix(int n){
   num_movies = n;
   m = new movie [num_movies];
}
/*********************************************************************************
** Function: ~netflix()
** Description: destructor
** Parameters: none
** Pre-Conditions: array
** Post-conditions: no array
*********************************************************************************/
netflix::~netflix(){
   delete [] m;
}
/*********************************************************************************
** Function: netflix()
** Description: copy constructor 
** Parameters: cost netflix & other
** Pre-Conditions: array
** Post-conditions: copy array
*********************************************************************************/
netflix::netflix( const netflix & other){
   num_movies = other.num_movies;
   if(num_movies ==0){

      m = NULL;
   }
   else{
      m = new movie [num_movies];
      for(int i=0;i<num_movies; i++){
	    m[i] = other.m[i];
      }
   }
}
/*********************************************************************************
** Function: operator =()
** Description: operator overload
** Parameters: const netflix &other
** Pre-Conditions: array
** Post-conditions: cop array
*********************************************************************************/
void netflix::operator =(const netflix &other){
   if(m!=NULL){
	   delete [] m;
   }
   num_movies = other.num_movies;
   if(num_movies ==0){

      m = NULL;
   }
   else{
      m = new movie [num_movies];
      for(int i=0;i<num_movies; i++){
	    m[i] = other.m[i];
      }
   }
}
/*********************************************************************************
** Function: set_m()
** Description: set m
** Parameters: none
** Pre-Conditions: empty m
** Post-conditions: value m
*********************************************************************************/
void netflix::set_m(int i,int &c){
	    cout<<"How many cast members are there?"<<endl;
	    cin>>c;
		movie mo(c);
	    m[i]=mo;
}
/*********************************************************************************
** Function: get_m()
** Description: gets m
** Parameters: none
** Pre-Conditions: none
** Post-conditions: m
*********************************************************************************/
movie* netflix::get_m(){
	return m;
}