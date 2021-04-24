/*********************************************************************************
** Program: main.cpp
** Author: Megan McCormick
** Date: 04/26/15
** Description: All the functions for my main
** Input: Renting and movie information
** Output: Movie information
**********************************************************************************/
#include"./netflix.h"
#include"./movie.h"
#include<fstream>
#include<stdlib.h>
#include<cstring>
#include<string>

void menue(int &a);
void menue2(int &b);
void enter();
void set_net(int);
void output1(netflix,int,int );
int counter();
void check_title(string);
void check_stars(string);
void pipe_count(string);
void test();
void cast_check(string c,int count,int &d,int &);
void movie_info(int q,int z);
void print(char* b, string c,int q,int &,int&,int &);
void which();
void overwrite(char *b,int a);

int main(){
   int a,b;
   string c,d;
   menue(a);
   if (a==1){
	   enter();
   }
   else if (a==2){   
	   menue2(b);
	   cin.ignore();
	   if(b==1){
		   cout<<"What movie are you looking for?"<<endl;
		   getline(cin,c);
		   pipe_count(c);
		   which();
	   }
	   else if(b==2){
		   cout<<"How many stars are you looking for?"<<endl;
		   cin>>d;
		   pipe_count(d);
		   which();
	   }
	   else if(b==3){
		   cout<<"What is the name of the actor you are looking for?"<<endl;
		   cin>>c;
		   pipe_count(c);
		   which();
	   }
	   else if(b==4){
		   cout<<"What rating are you looking for?"<<endl;
		   cin>>d;
		   pipe_count(d);
		   which();
		   
	   }
	   else{
		   cout<<"Thank You!"<<endl;
	   }
   }
   else if (a==3){
	   cout<<"Thank you"<<endl;
	  // break;
   }
   else{
	 cout<<"You know what, go away."<<endl;
    // break;	 
   }
   return 0;

}
/*********************************************************************************
** Function: menue(int &a)
** Description: prints menue
** Parameters: int &
** Pre-Conditions: none
** Post-conditions: answer
*********************************************************************************/
void menue(int &a){
   cout<<"Would you like to:"<<endl;
   cout<<"1. Enter a movie."<<endl;
   cout<<"2. Rent a movie."<<endl;
   cout<<"3. Exit."<<endl;
   cin>>a;
} 
/*********************************************************************************
** Function: menue2(int &b)
** Description: prints second menue 
** Parameters: int &
** Pre-Conditions: none
** Post-conditions: answer
*********************************************************************************/
void menue2(int &b){
	cout<<"What would you like to search by?"<<endl;
	cout<<"1. By title"<<endl;
	cout<<"2. By stars"<<endl;
    cout<<"3. By cast member"<<endl;
	cout<<"4. By rating"<<endl;
	cout<<"5. I do not want to search"<<endl;
	cin>>b;
}
/*********************************************************************************
** Function: enter()
** Description: Gets movie information from user
** Parameters: none
** Pre-Conditions: none
** Post-conditions: movie
*********************************************************************************/
void enter(){
	int b,c;
	 cout<<"How many movies would you like to enter?"<<endl;
      cin>>b;
      netflix net(b);
	  set_net(b);
}
/*********************************************************************************
** Function: set_net(int b)
** Description: Sets netflix
** Parameters: int 
** Pre-Conditions: no netflix
** Post-conditions: netflix
*********************************************************************************/
void set_net(int b){
	char a;
	ofstream output;
	output.open("netflix.dat",ios::app);
	netflix net(b);
	for (int i = 0; i<b; i++){
		int c;
	    cout<<"For movie "<<i+1<<":"<<endl;
	    net.set_m(i,c);
	    net.get_m()[i].set_name();
	    net.get_m()[i].set_stars();
	    net.get_m()[i].set_cast(c);
	    net.get_m()[i].set_rating();
	    net.get_m()[i].set_copies();
		output<<counter()<<"|"<<net.get_m()[i].get_name()<<"|"<<net.get_m()[i].get_stars()<<"|"<<net.get_m()[i].get_num_cast()<<"|";
        for(int j= 0; j<c; j++){
			output<<net.get_m()[i].get_cast(j)<<"|";
		}		
		output<<net.get_m()[i].get_rating()<<"|"<<net.get_m()[i].get_copies()<<"|"<<0<<endl;;
	}
	output.close();
}
/*********************************************************************************
** Function: counter()
** Description: counts
** Parameters: none
** Pre-Conditions: none
** Post-conditions: count
*********************************************************************************/
int counter(){
	fstream input;
	char a[256];
	int count=0;
	input.open("netflix.dat",ios::in);
	while(!input.eof()){      
		input.getline(a,256);
		count ++;
		input.peek();
	}
	return count+1;
	input.close();
}
/*********************************************************************************
** Function: check_title(string t)
** Description: checks title
** Parameters: string t
** Pre-Conditions: none
** Post-conditions: checked title
*********************************************************************************/
void check_title(string t){
	fstream in;
	int c=1,p=0,d=1,q,z,count;
	char a[256];
	in.open("netflix.dat",ios::in);
	while(!in.eof()){
		in.get( a, 256, '|');
		in.get( a, 2);
		in.get( a, 256, '|');
		cout<<"a1"<<a<<endl;
		string b;
		b = a;
		q=2;
		if(!b.compare(t)){
			cout<<"Movie match: "<<c<<endl;
			cout<<"Title: "<<b<<endl;
			c++;
			in.getline(a,256);
		    //cout<<a<<endl;
			p=d;
			print(a,t,q,z,count,d);
			
		}
		//in.getline(a,256);
		//cout<<a<<endl;
        in.peek();
	}
	in.close();
}
/*********************************************************************************
** Function: check_stars(string s)
** Description: checks stars
** Parameters: string
** Pre-Conditions: none
** Post-conditions: none
*********************************************************************************/
void check_stars(string s){
	fstream in;
	int c=1,p=0,d=1,q,z,count;
	char a[256],t[256];
	in.open("netflix.dat",ios::in);
	while(!in.eof()){
		for (int i=0; i<2;i++){
		in.get( a, 256, '|');
		in.get( a, 2);
		}
		in.get( a, 256, '|');
		cout<<t<<endl;
		string b,k;	
		b = a;
		q=3;
		if(!b.compare(s)){
			//cout<<t<<endl;
			//break;
			cout<<"Movie match: "<<c<<endl;
			c++;
			cout<<"Title: "<<endl;
			cout<<"Stars: "<<b<<endl;
			//in.getline(t,256);
			in.getline(a,256);
			p=d;
			print(a,s,q,z,count,d);
			
		}
		cout<<a<<endl;
		in.peek();
	}
	in.close();
}

/*********************************************************************************
** Function: pipe_count(string c)
** Description: counts pipes
** Parameters: string 
** Pre-Conditions: none
** Post-conditions: rented movie
*********************************************************************************/
void pipe_count(string c){
	
	char b[265];
	int count =0;
	char *ptr;
	int d = 1,p=0,q=0,z;	
	fstream in;
	in.open("netflix.dat",ios::in);
	while(!in.eof()){
	in.getline(b,265);
	q=0;
	//cout<<b<<endl;
	    for(int i=0; i<strlen(b);i++){
	        if (b[i]=='|'){
		       count++;
	           //cout<<"count"<<count<<endl;
			}
			   //cout<<"b[i]"<<b[i]<<endl;
			   //cout<<c.at(0)<<endl;
			   	if (b[i]== c.at(0)&&count>=4){
		          cast_check(c,count, d,p);
			      print(b,c,q,z,count,d);  
				}
	    }
	}
}
/*********************************************************************************
** Function: cast_check(string c,int count,int &d,int &p)
** Description: checks cast
** Parameters: string, int, int &, int &
** Pre-Conditions: none
** Post-conditions: checked cast
*********************************************************************************/
void cast_check(string c,int count,int &d,int &p){
	char a[265];
	fstream in;
	in.open("netflix.dat",ios::in);
	for (int j=0; j<count;j++){
		   in.get( a, 256, '|');
		   in.get( a, 2);
		   }
		   in.get( a, 256, '|');
		  // cout<<a<<endl;
		   string l;
		   l = a;
		   p=d;
		   //cout<<"a"<<a<<endl;
		   if(!l.compare(c)){
			   cout<<"Movie match: "<<d<<endl;  
			   d++;
		   }
		   in.getline(a,256);
		   //cout<<a<<endl;
		   in.peek();
		   
}	
/*********************************************************************************
** Function: movie_info(int q,int z)
** Description: prints movie information
** Parameters: int, int
** Pre-Conditions: none
** Post-conditions: printed information
*********************************************************************************/
void movie_info(int q,int z){
	if(q==0){
		cout<<"Number: ";
	}
	else if(q==1){
		cout<<"Title: ";
	}
	else if(q==2){
		cout<<"Stars: ";
	}
	else if(q==3){
		cout<<"Cast number: ";
	}
	else if(q==4){
		cout<<"Cast Member(s): ";
	}
	else if(q==(4+z)){
		cout<<"Rating: ";
	}
	else if(q==(4+z+1)){
		cout<<"Copies: ";
	}
	else if (q== (4+z+2)){
		cout<<"Rented: ";
	}
		
}
/*********************************************************************************
** Function: print(char* b, string c,int q,int &z,int &count,int &d)
** Description: prints
** Parameters: char* b, string c,int q,int &z,int &count,int &d
** Pre-Conditions: information
** Post-conditions: printed information
*********************************************************************************/
void print(char* b, string c,int q,int &z,int &count,int &d){
	int p=0;
	char *ptr;

    if(d>p){
	ptr = strtok(b,"|");
	while(ptr !=NULL){
		//cout<<"q"<<q<<endl;
		if(q==3){
		    z= atoi(ptr);
			//cout<<z<<endl;
			}
			movie_info(q,z);
			if(q>3&& q<3+z){
			cout<<ptr;
	            if(q==3+z){
				    cout<<endl;
	            }
				else{
				     cout<<", ";
				}
			}
			else{
				cout<<ptr<<endl;
			}
			ptr = strtok(NULL,"|");
				q++;
						
     }
	count+=z;
	}
		          
}
/*********************************************************************************
** Function:
** Description: 
** Parameters: 
** Pre-Conditions: 
** Post-conditions: 
*********************************************************************************/
void which(){
	int i=0,a,l;
	char b[256],c[256];
	cout<<"Which movie would you like?(movie number)"<<endl;
	cin>>a;
	fstream in;
	in.open("netflix.dat",ios::in);
	while(i!=a){
	  in.getline(b, 256);
	  i++;
	}
    l = strlen(b);
	b[l-1] += 1;
	in.close();
	overwrite(b,a);
}
/*********************************************************************************
** Function: overwrite(char *b,int a)
** Description: updates file
** Parameters: char *, int
** Pre-Conditions: none 
** Post-conditions: over written file
*********************************************************************************/
void overwrite(char *b,int a){
	int z=1;
	ifstream in;
	ofstream out;
	char c[300],d[300];
	in.open("netflix.dat");
	out.open("netflix2.dat");
	while(!in.eof()){
		if(z==a){
			in.getline(d,300);
			out<<b<<endl;
		}
		else {
			in.getline(c,300);
			out<<c<<endl;
		}
		z++;
		in.peek();
	}
	in.close();
	out.close();
	rename("netflix2.dat","netflix.dat");
	cout<<"Movie has been rented"<<endl;
}

	

	
