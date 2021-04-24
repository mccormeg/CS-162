#include "./mult_div.h"

using namespace std;


void notalettercols(char *b){
   int x=0;
   char a;
   while(1){
      x=0;
      for (int i=0; i<strlen(b); i++){ 
	 a=b[i];
        //cout<<"cols"<<a<<endl;	 
	 if (a!='0' && a!='1' && a!='2' && a!='3' && a!='4' && a!='5' && a!='6' && a!='7' && a!='8' && a!='9'&&a!=NULL){
	    x=1;
	    break;
      }
   }
      if(x==1){
	 cout<<"Try a real integer for columns."<<endl;
	 cin>>b;
      }
      else
	 break;
   }
}
void notaletterrows(char *c){
   int x=0;
   char a;
   while(1){
      x=0;
      for (int i=0; i<strlen(c); i++){ 
	 a=c[i];
         //cout<<"rows"<<a<<endl;
	 //cout << x << endl;	 
	 if (a!='0' && a!='1' && a!='2' && a!='3' && a!='4' && a!='5' && a!='6' && a!='7' && a!='8' && a!='9'&&a!=NULL){
	    cout<<"rows in if"<<a<<endl;
	    x=1;
	    break;
      }
   }
      if(x==1){
	 cout<<"Try a real integer for rows."<<endl;
	 cin>>c;
      }
      else
	 break;
   }
}

	    
// checks that value is a non-zero integer
bool is_valid_diminsions(char *m,char*n){
   int rows, col;
   rows = atoi(m);
   col = atoi(n);
   if (rows == 0 || col ==0|| rows<0 || col<0){
      return 0;
   }
   else {
      return 1;
   }
}
// creates table
mult_div_values **create_table(int m, int n){
   mult_div_values **arry;
   arry = new mult_div_values *[m];
   for (int i = 0; i <m; i++){
      arry[i] = new mult_div_values [n];
   }
   return arry;

}
// Sets table values for multiplication
void set_mult_values(mult_div_values **table,int m, int n){
  cout<< "Multiplication Table: "<<endl;
   // sets multipication values in array	
   for (int j=0; j<m; j++){
      for(int k=0; k<n;k++){
   	 table[j][k].mult = ((j+1)*(k+1));
	 // will print array with spacing
	 if (table[j][k].mult <=9){
	    cout<<"0"<<table[j][k].mult<< " ";
	 }
	 else{
	    cout<<table[j][k].mult<< " ";
	 }

      }
      cout<<endl;

   }
   cout<<endl;
	
}
// Sets table values for division
void set_div_values(mult_div_values**table, int m, int n){
   cout<<"Division Table: "<<endl;
   float p=0,q=0;
   //Sets division values in array
   for (int j=0; j<m; j++){
      p=p+1;  
      q=0;
      for(int k=0; k<n;k++){ 
	 q=q+1;
	 table[j][k].div=((p)/(q));
	 cout<<setw(6);
	 cout<<table[j][k].div<<"  ";
      }

      cout<<endl;
   }
   cout<<endl;
}
// deletes tables
void delete_table(mult_div_values **table, int m){
   for (int i = 0; i<m; i++){
      delete [] table[i];
   }
   delete [] table;
}


void play_again(int &x,char *b,char *c){
   int y;
   cout<< "Would you like to see a different matrix (0-no, 1-yes)?"<<endl:
   cin>>y;
      if(y==1){
        cout<<"Please enter the number of rows: "<<endl;
        cin>>b;
        cout<<"Please enter the number of columns: "<<endl;
        cin>>c;
	x=1;
      }
      else{
	 x=0
      }
}



/***********************************************

int main(int argc, char *argv[]){
   char *b, *c;
   int rows, col;
   b=argv[1];
   c=argv[2];
   mult_div_values **a;
   notaletterrows(b);
   notalettercols(c);
   rows = atoi(argv[1]);
   col = atoi(argv[2]);
  if (is_valid_diminsions(argv[1],argv[2])==1){
   a=create_table(rows,col);
   set_mult_values(a, rows, col);
   set_div_values(a,rows,col);
   delete_table(a,rows); 
  }
  else{
     cout<<"You entered a value wrong. Please try again."<<endl;
  }
  


return 0;
}
**********************************************************************/

