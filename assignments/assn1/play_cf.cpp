/**************************************************************************
** Program Filename: play_cf.cpp
** Author: Megan McCormick
** Date: 4/12/15
** Description: Runs all functions
** Input: None
** Output: None
***************************************************************************/
#include"./connect_four.h"

int main(int argc,char*argv[]){
   int a;
   game con;
   game *cf;
   cf = &con;
        a = arg_check(argc,argv);
   	if(a==1){
	   int x=0;
	   x=play_ai();
	   if(x ==1){
	      connect_ai(cf,con,argv);
	   }
	   else if(x==0){
	      connect(cf,con,argv);
	   }
	}   
	else if (a==2){	
	   int z=0;
	   z=play_ai();
	   if (z == 1){
	      connect_four_ai(cf,con,argv);
	   }
	   else if(z==0){
	      connect_four(cf,con,argv);
	   }
	}		 
return 0;
}
