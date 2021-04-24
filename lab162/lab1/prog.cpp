#include"./mult_div.h"
#include<iostream>

using namespace std;

int main(int argc, char *argv[]){
   char *b,*c;
   int rows,col,x=1;
   b=argv[1];
   c=argv[2];
   mult_div_values **a;
   while (x==1){
      notaletterrows(b);
      notalettercols(c);
      rows = atoi(b);
      col = atoi(c);
         if (is_valid_diminsions(b,c)==1){
	   cout<<"in if"<<endl;
     	   a=create_table(rows,col);
      	   set_mult_values(a,rows,col);
       	   set_div_values(a,rows,col);
      	   delete_table(a,rows);
	   play_again(x,b,c);

      } 
   }
   
}
