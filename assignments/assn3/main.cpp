/*************************************************************************
** Program Filename: main.cpp
** Author: Megan MCCormick
** Date: 5/10/15
** Description: Exacution file
** Input: Game info
** Output: Game Stats
*************************************************************************/
#include "Paper.h"
#include "Rock.h"
#include "Scissors.h"
#include "Tool.h"
#include <iostream>
#include "RPSGame.h"

using namespace std;

void play_norm();
void set_tool(Tool &, char );
void play_set();
bool play_again();
bool num_check(int);
void ai_1();
void ai_2();
void play_set2();
void play_norm2();

int main(){
	int a;
	do{
		cout<<"Which level AI would you like?(1-Novice, 2-Advance)"<<endl;
		cin >> a;
	}while(num_check(a)== 0);
	if (a == 1){
		ai_1();
	}
	else if( a == 2){
		ai_2();
	}

	
}
/*********************************************************************************
** Function: play_norm2()
** Description:  Plays the normal version of RPS for second ai
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
void play_norm2(){
	RPSGame play;
	char a, b;
	Tool c;
	do{
		play.set_human();
		a = play.get_human()->get_type();
		play.set_ai2();
		b = play.get_ai()->get_type();
		set_tool(c, b);
		if (a == 'r'){
			
			play.compare_rock(c);
			play.display_stats();
		}
		if (a == 's'){
			play.compare_scissors(c);
			play.display_stats();
		}
		else if(a == 'p'){
			play.compare_paper(c);
			play.display_stats();
		}
	}while(play_again()==1);
}
/*********************************************************************************
** Function: play_norm()
** Description: Normal game for first AI
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
void play_norm(){
	RPSGame play;
	char a, b;
	Tool c;
	do{
		play.set_human();
		a = play.get_human()->get_type();
		play.set_ai();
		b = play.get_ai()->get_type();
		set_tool(c, b);
		if (a == 'r'){
			
			play.compare_rock(c);
			play.display_stats();
		}
		if (a == 's'){
			play.compare_scissors(c);
			play.display_stats();
		}
		else if(a == 'p'){
			play.compare_paper(c);
			play.display_stats();
		}
	}while(play_again()==1);
}
/*********************************************************************************
** Function: play_set()
** Description: Play through for setting values 
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
void play_set(){
	RPSGame play;
	char a, b;
	int s;
	Tool c;
	do{
		s = play.set_human_set();
		a = play.get_human()->get_type();
		play.set_ai();
		b = play.get_ai()->get_type();
		set_tool(c, b);
		if (a == 'r'){
			
			play.compare_rock_set(c,s);
			play.display_stats();
		}
		if (a == 's'){
			play.compare_scissors_set(c,s);
			play.display_stats();
		}
		else if(a == 'p'){
			play.compare_paper_set(c,s);
			play.display_stats();
		}
	}while(play_again()==1);
	
}
/*********************************************************************************
** Function: play_set2()
** Description: Play through for setting values with AI2
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
void play_set2(){
	RPSGame play;
	char a, b;
	int s;
	Tool c;
	do{
		s = play.set_human_set();
		a = play.get_human()->get_type();
		play.set_ai2();
		b = play.get_ai()->get_type();
		set_tool(c, b);
		if (a == 'r'){
			
			play.compare_rock_set(c,s);
			play.display_stats();
		}
		if (a == 's'){
			play.compare_scissors_set(c,s);
			play.display_stats();
		}
		else if(a == 'p'){
			play.compare_paper_set(c,s);
			play.display_stats();
		}
	}while(play_again()==1);
	
}
/*********************************************************************************
** Function: set_tool(Tool &a, char b)
** Description: Sets tools
** Parameters: Tool &a, char b
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
void set_tool(Tool &a, char b){
	if (b == 'r'){
		Rock r;
		a = r;
	}
	else if(b == 'p'){
		Paper p;
		a = p;
	}
	else if(b == 's'){
		Scissors s;
		a = s;
	}
}
/*********************************************************************************
** Function: play_again()
** Description: Asks to play again
** Parameters: None
** Pre-Conditions: NOne
** Post-conditions: Bool
*********************************************************************************/
bool play_again(){
	char an;
	do {
		cout<<"Would you like to play again?(y-yes, n-no)"<<endl;
		cin >> an;
	}while(an != 'y' && an != 'n');
	if (an == 'y'){
		return 1;
	}
	else{
		return 0;
	}
	
}
/*********************************************************************************
** Function: num_check(int a)
** Description: Checks numbers
** Parameters: int a
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
bool num_check(int a){
	if (a != 1 && a != 2){
		cout<<"You entered a wrong number. Try again."<<endl;
		return 0;
	}
	else {
		return 1;
	}
}
/*********************************************************************************
** Function: ai_1()
** Description: PLays with first AI
** Parameters: None
** Pre-Conditions: None
** Post-conditions: Play trhough
*********************************************************************************/
void ai_1(){
	char an;
	int r,p,s;
	cout<<"Do you want to choose the strengths of the tool? (y or n)"<<endl;
	cin >>an;
	if(an =='y'){
		play_set();
	}
	else if (an == 'n'){
		play_norm();
	}
	else{
		cout<<"You did not enter  a y or n. Just for that you don't get to play."<<endl;
	}
}
/*********************************************************************************
** Function: ai_2()
** Description: Plays with second AI
** Parameters: None
** Pre-Conditions: None
** Post-conditions: Play through
*********************************************************************************/
void ai_2(){
	char an;
	int r,p,s;
	cout<<"Do you want to choose the strengths of the tool? (y or n)"<<endl;
	cin >>an;
	if(an =='y'){
		play_set2();
	}
	else if (an == 'n'){
		play_norm2();
	}
	else{
		cout<<"You did not enter  a y or n. Just for that you don't get to play."<<endl;
	}
}
