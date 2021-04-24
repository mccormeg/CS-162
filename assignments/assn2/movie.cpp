/*********************************************************************************
** Program: movie.cpp
** Author: Megan McCormick
** Date: 04/26/15
** Description: All functions for movie class
** Input: Movie information
** Output: Movie information
**********************************************************************************/
#include"./movie.h"
/*********************************************************************************
** Function: movie()
** Description: constructor
** Parameters: none
** Pre-Conditions: none
** Post-conditions: full class
*********************************************************************************/
movie::movie(){name="Computer Science 162";stars =5; num_cast=2; cast=new string [num_cast]; cast[0]= "Jennifer Parham-Mocello"; cast[1]="Students"; rating = "PG"; copies=2;
}

/*********************************************************************************
** Function: movie(int c)
** Description: constructor
** Parameters: int c
** Pre-Conditions: none
** Post-conditions: full movie class
*********************************************************************************/
movie::movie(int c){
   name ="movie";
   stars=4;   
   num_cast = c;
   cast = new string [num_cast];
   rating = "PG";
   copies = 2;

}
/*********************************************************************************
** Function: ~movie()
** Description: destructor
** Parameters: none
** Pre-Conditions: array
** Post-conditions: no array
*********************************************************************************/
movie::~movie(){
   delete [] cast;
}
/*********************************************************************************
** Function: movie( const movie & other)
** Description: copy constructor
** Parameters: const movie & other
** Pre-Conditions: array
** Post-conditions: array
*********************************************************************************/
movie::movie( const movie & other){
   num_cast = other.num_cast;
   if(num_cast ==0){
      cast = NULL;
   }
   else {
      cast = new string[num_cast];
      for (int i=0; i<num_cast; i++){
	 cast[i]= other.cast[i];
      }
   }
}
/*********************************************************************************
** Function: operator=(const movie &m)
** Description: operator overload
** Parameters: const movie &m
** Pre-Conditions: array
** Post-conditions: deep copy array 
*********************************************************************************/
void movie::operator=(const movie &m){
	if(cast!=NULL) {
		delete [] cast;
	}
	num_cast=m.num_cast;
	if(num_cast==0){
		cast =NULL;
	}
	else{
		cast=new string[num_cast];
		for(int i=0;i<num_cast;i++){
			cast[i]=m.cast[i];
		}
	}
}
/*********************************************************************************
** Function: set_name() 
** Description: sets name
** Parameters: none
** Pre-Conditions: none
** Post-conditions: set name
*********************************************************************************/
void movie::set_name(){
	cin.ignore();
	 cout<<"What is the name of the movie?"<<endl;
     getline(cin,name);
}
/*********************************************************************************
** Function: set_stars()
** Description: sets stars
** Parameters: none
** Pre-Conditions: none
** Post-conditions: set name
*********************************************************************************/
void movie::set_stars(){
	cout<<"How many stars did it receive?(1-5)"<<endl;
	cin>> stars;
}
/*********************************************************************************
** Function: set_cast(int c)
** Description: sets cast
** Parameters: int c
** Pre-Conditions: none
** Post-conditions: sets cast  
*********************************************************************************/
void movie::set_cast(int c){
	cin.ignore();
	
	for(int i=0; i<num_cast; i++){
      cout<<"What is the name of cast member "<<i+1<<"."<<endl;
      getline(cin,cast[i]);
   }
}
/*********************************************************************************
** Function: set_rating()
** Description: sets rating
** Parameters: none
** Pre-Conditions: none
** Post-conditions: set rating
*********************************************************************************/
void movie::set_rating(){
	cout<<"What is the rating of the movie(G,PG,PG-13 or R)?"<<endl;
    cin>> rating;
}
/*********************************************************************************
** Function: set_copies()
** Description: sets copies
** Parameters: none
** Pre-Conditions: none
** Post-conditions: set copies
*********************************************************************************/
void movie::set_copies(){
	 cout<<"How many copies are there of this movie?"<<endl;
     cin>> copies;
}
/*********************************************************************************
** Function: get_name()
** Description: gets name
** Parameters: none
** Pre-Conditions: none
** Post-conditions: name
*********************************************************************************/
string movie::get_name(){
	return name;
}
/*********************************************************************************
** Function: get_stars()
** Description: gets stars
** Parameters: none
** Pre-Conditions: none
** Post-conditions: stars
*********************************************************************************/
int movie::get_stars(){
	return stars;
}
/*********************************************************************************
** Function: get_num_cast()
** Description: gets number of cast members
** Parameters: none
** Pre-Conditions: none
** Post-conditions: cast members
*********************************************************************************/
int movie::get_num_cast(){
	return num_cast;
}
/*********************************************************************************
** Function: get_cast(int a)
** Description: gets cast
** Parameters: int
** Pre-Conditions: none
** Post-conditions: cast
*********************************************************************************/
string movie::get_cast(int a){
	return cast[a];
}
/*********************************************************************************
** Function: get_rating()
** Description: gets ratings
** Parameters: none
** Pre-Conditions: none
** Post-conditions: rating
*********************************************************************************/
string movie::get_rating(){
	return rating;
}
/*********************************************************************************
** Function: get_copies()
** Description: gets copies
** Parameters: none
** Pre-Conditions: none
** Post-conditions: copies
*********************************************************************************/
int movie::get_copies(){
	return copies;
}	

   

