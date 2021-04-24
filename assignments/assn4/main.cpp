/*********************************************************************************
** Program: main.cpp
** Author: Megan McCormick
** Date: 05/26
** Description: All the functions for my main
** Input: Choosing roomba, inputing values
** Output: clean room/floor
**********************************************************************************/
#include<cstring>
#include<stdexcept>
#include <fstream>
#include <iostream>
#include<cstdlib>
#include<string>
#include "Room.hpp"
#include "Roomba.h"
#include "RandomRoomba.h"
#include "BetterRoomba.h"
#include "SuperRoomba.h"
#include "Floor.h"

using namespace std;

/*********************************************************************************
** Function: Struct command
** Description: takes command arguments and puts them in once place 
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
struct command {
	char* file[3];
	int battery;
	int moves;
	int srow;
	int scol;
};

bool check_arg(int argc, char* argv[]);
void simulate_roomba(command) ;
void choose_roomba(Room <Roomba> &r,command);
int cols(command);
int rows(command);
void floor(command d,int row, int c,Room <Roomba> &r);
void set_command(command &c, char* agrv[]);
bool file_check(command &);



int main(int argc, char* argv[]){
	if(check_arg(argc,argv)==1){
		command c;
		set_command(c,argv);
		while(file_check(c)==0){
			cout<<"Please provide a correct file"<< endl;
			cin>>c.file[1];
		}
		simulate_roomba(c);
	}
	else{
		cout<<"Please try to enter the correct arguments next time"<<endl;
	}
	
	return 0;
}
/*********************************************************************************
** Function: file_check(command &d)
** Description: Checks file
** Parameters: command &
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
bool file_check(command &d){
	int n;
	ifstream in;
	in.open(d.file[1]);
	try {
		ifstream in;
		in.open(d.file[1]);
		if(!in){
			throw n;
		}
	}
	catch (int &e){
		cout<<"That wasn't a correct file."<<endl;
		return 0; 
	}
	in.close();
	return 1;
}
/*********************************************************************************
** Function: set_command(command &c, char* argv[])
** Description: sets the struct
** Parameters: command &c, char* argv[]
** Pre-Conditions: None
** Post-conditions: STRUCT
*********************************************************************************/
void set_command(command &c, char* argv[]){
	for (int i =1; i<11; i = i+2){
		if(!strcmp(argv[i],"-f")){
			c.file[1] = argv[i+1];
		}
		else if(!strcmp(argv[i],"-b")){
			c.battery = atoi(argv[i+1]);
		}
		else if(!strcmp(argv[i],"-r")){
			c.srow = atoi(argv[i+1]);
		}
		else if(!strcmp(argv[i],"-c")){
			c.scol = atoi(argv[i+1]);
		}
		else if(!strcmp(argv[i],"-v")){
			c.moves = atoi(argv[i+1]);
		}
	}
	
}
/*********************************************************************************
** Function: check_arg(int argc, char* argv[])
** Description: checks for correct arguments
** Parameters: int argc, char* argv[]
** Pre-Conditions: None
** Post-conditions: Bool
*********************************************************************************/
bool check_arg(int argc, char* argv[]){
	int j =0;
	if(argc != 11){
		cout<<"You did not enter the correct number of arguments"<<endl;
		return 0;
	}
	else{
		for (int i =1; i<argc; i=i+2){
			if(!strcmp(argv[i],"-f") || !strcmp(argv[i], "-b") || !strcmp(argv[i],"-r") || !strcmp(argv[i],"-c") || !strcmp(argv[i],"-v")){
				j = 1;
			}
			else{
				cout<<"Your argument is invalid."<<endl;
				j = 0;
			}
		}
		if (j == 1){
			return 1;
		}
		else 
			return 0;
	}
}
/*********************************************************************************
** Function: choose_roomba(Room <Roomba> &r, command d)
** Description: Chooses roomba
** Parameters: Room <Roomba> &r, command d
** Pre-Conditions: None
** Post-conditions: The chosen one
*********************************************************************************/
void choose_roomba(Room <Roomba> &r, command d) {
	int choice, x=1;
	
	do{
		
		cout << "Which Roomba (1 – Random, 2 - Better, 3 - Super)? ";
		cin >> choice;
	}while(choice != 1 && choice != 2 && choice != 3);
	
		if(choice == 1){
			r.set_roomba(new RandomRoomba);
			r.get_obj()->set_battery(d.battery);
			r.get_obj()->set_view(d.moves);
		}
		else if(choice ==2){
			r.set_roomba(new BetterRoomba);
			r.get_obj()->set_battery(d.battery);
			r.get_obj()->set_view(d.moves);
		}
		else if(choice ==3){
			r.set_roomba(new SuperRoomba);
			r.get_obj()->set_battery(d.battery);
			r.get_obj()->set_view(d.moves);
		}
}
/*********************************************************************************
** Function: simulate_roomba(command d)
** Description: Simulates roomba
** Parameters: command
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
void simulate_roomba(command d) {
	int row, col,an;
	Room <Roomba> r;
	col = cols(d);
	row = rows(d);
	choose_roomba(r,d);
	floor(d,row,col,r);
	r.clean_room(); //Now clean it after everything is setup
	cout<<"Total moves: "<<r.get_obj()->get_total_moves()<<endl;
	cout<<"Battery life left: "<<r.get_obj()->get_battery()<<endl;
	cout<<"Are you satisfied with your care(1-yes,0-no)?"<<endl;
	cin >> an;
	if (an == 1){
		cout<<"Your Roomba will deactivate."<<endl;
	}
	else if(an == 0){
		cout<<"You have hurt your Roomba's feelings. It is going to charge in a corner."<<endl;
	}
	else {
		cout<<"That wasn't an option. Your Roomba says stop breaking things."<<endl;
	}
 
}
/*********************************************************************************
** Function: floor(command d,int row, int c,Room <Roomba> &r)
** Description: Sets the floors for room
** Parameters: command d,int row, int c,Room <Roomba> &r
** Pre-Conditions: None
** Post-conditions: A brand new floor
*********************************************************************************/
void floor(command d,int row, int c,Room <Roomba> &r){
	Floor flow(row,c,d.srow,d.scol);
	r.set_floor(flow);
}
/*********************************************************************************
** Function: rows(command d)
** Description: sets rows
** Parameters: command d
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
int rows(command d){
	int row = 0;
	char a[300];
	ifstream in;
	in.open(d.file[1]);
	if(!in){
		cout<<"There is no file."<<endl;
	}
	while(!in.eof()){
		in.getline(a,300);
		row= row +1;
		in.peek();
	}
	in.close();
	return row;
}
/*********************************************************************************
** Function: cols(command d)
** Description: Gets col from file
** Parameters: command
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
int cols(command d){
	int col=0;
	char b[300];
	ifstream in;
	in.open(d.file[1]);
	in.getline(b,300);
	for (int i = 0; i<300; i ++){
		if (b[i]== 'f' || b[i] == 'd'){
			col++;
		}
	}
	in.close();
	return col;
}
