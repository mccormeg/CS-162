/*************************************************************************
** Program Filename: RPSGame.cpp
** Author: Megan MCCormick
** Date: 5/10/15
** Description: Functions for RPSGame class
** Input: None
** Output: Displays stats
*************************************************************************/
#include "RPSGame.h"
#include <iostream>
#include "Tool.h"
#include "Rock.h"
#include "Scissors.h"
#include "Paper.h"
#include<cstring>
#include<cstdlib>

using namespace std;

bool check_RPS(char a);
/*********************************************************************************
** Function: display_stats()
** Description: Displays stats to the screen
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
void RPSGame::display_stats(){
	cout<<"Player won: "<<player_win<<endl;;
	cout<<"AI won: "<<ai_win<<endl;
	cout<<"Tie: "<<tie<<endl;	
}
/*********************************************************************************
** Function: compare_rock(Tool a)
** Description: Compares Rock
** Parameters: Tool a
** Pre-Conditions: Stats
** Post-conditions: Changed stats
*********************************************************************************/
void RPSGame::compare_rock(Tool a){
		Rock t;
		int p;
		p=t.fight(a);
		if (p == 0){
			cout<<"Oh no, you lost"<<endl;
			ai_win += 1;
		}
		else if ( p == 1){
			cout<<"You Won"<<endl;
			player_win += 1;
		}
		else if (p == 2){
			cout<< "It's a tie."<<endl;
			tie += 1;		
	    }
		
	
}
/*********************************************************************************
** Function: compare_scissors(Tool a)
** Description: Compares Scissors
** Parameters: Tool a
** Pre-Conditions: Stats
** Post-conditions: Changed stats
*********************************************************************************/
void RPSGame::compare_scissors(Tool a){
	
		Scissors t;
		int p;
		p=t.fight(a);
		if (p == 0){
			cout<<"Oh no, you lost"<<endl;
			ai_win += 1;
		}
		else if ( p == 1){
			cout<<"You Won"<<endl;
			player_win += 1;
		}
		else if (p == 2){
			cout<< "It's a tie."<<endl;
			tie += 1;		
	    }
	
}
/*********************************************************************************
** Function: compare_paper(Tool a)
** Description: Compares Paper
** Parameters: Tool a
** Pre-Conditions: Stats
** Post-conditions: Changed stats
*********************************************************************************/
void RPSGame::compare_paper(Tool a){
		Paper t;
		cout<<"paper"<<endl;
		int p;
		p=t.fight(a);
		cout<<"p"<<p<<endl;
		if (p == 0){
			cout<<"Oh no, you lost"<<endl;
			ai_win += 1;
		}
		else if ( p == 1){
			cout<<"You Won"<<endl;
			player_win += 1;
		}
		else if (p == 2){
			cout<< "It's a tie."<<endl;
			tie += 1;		
	    }
	
}
/*********************************************************************************
** Function: compare_rock_set(Tool a)
** Description: Compares rock 
** Parameters: Tool a
** Pre-Conditions: Stats
** Post-conditions: Changed stats
*********************************************************************************/
void RPSGame::compare_rock_set(Tool a, int i){
		Rock t(i);
		int p;
		
		p=t.fight(a);
		if (p == 0){
			cout<<"Oh no, you lost"<<endl;
			ai_win += 1;
		}
		else if ( p == 1){
			cout<<"You Won"<<endl;
			player_win += 1;
		}
		else if (p == 2){
			cout<< "It's a tie."<<endl;
			tie += 1;		
	    }
		
	
}
/*********************************************************************************
** Function: compare_scissors_set(Tool a)
** Description: Compares scissors 
** Parameters: Tool a
** Pre-Conditions: Stats
** Post-conditions: Changed stats
*********************************************************************************/
void RPSGame::compare_scissors_set(Tool a, int i){
	
		Scissors t(i);
		int p;
		p=t.fight(a);
		if (p == 0){
			cout<<"Oh no, you lost"<<endl;
			ai_win += 1;
		}
		else if ( p == 1){
			cout<<"You Won"<<endl;
			player_win += 1;
		}
		else if (p == 2){
			cout<< "It's a tie."<<endl;
			tie += 1;		
	    }
	
}
/*********************************************************************************
** Function: compare_paper_set(Tool a)
** Description: Compares paper
** Parameters: Tool a
** Pre-Conditions: Stats
** Post-conditions: Changed stats
*********************************************************************************/
void RPSGame::compare_paper_set(Tool a, int i){
		Paper t(i);
		int p;
		p=t.fight(a);
		if (p == 0){
			cout<<"Oh no, you lost"<<endl;
			ai_win += 1;
		}
		else if ( p == 1){
			cout<<"You Won"<<endl;
			player_win += 1;
		}
		else if (p == 2){
			cout<< "It's a tie."<<endl;
			tie += 1;		
	    }
	
}
/*********************************************************************************
** Function: RPSGame()
** Description: Constructor
** Parameters: None
** Pre-Conditions: None
** Post-conditions:None
*********************************************************************************/
RPSGame::RPSGame(){
	ai =NULL;
	human =  NULL;
	player_win = 0;
	ai_win=0;
	tie=0;
}
/*********************************************************************************
** Function: set_human()
** Description: Sets human
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
void RPSGame::set_human(){
	delete [] human;
	char a;
	do{
		cout<<"Which piece would you like: Rock, Paper or Scissors?(r,p or s)"<<endl;
		cin >>a;
	}while(check_RPS(a)==0);
	if (a == 'r'){
		human = new Rock;
		
	}
	else if(a == 's'){
		human = new Scissors;
	}
	else if( a == 'p'){
		human = new Paper;
	}
}
/*********************************************************************************
** Function: set_human_set()
** Description: Sets human
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
int RPSGame::set_human_set(){
	delete [] human;
	char a;
	int s;
	Tool *h;
	do{
		cout<<"Which piece would you like: Rock, Paper or Scissors?(r,p or s)"<<endl;
		cin >>a;
	}while (check_RPS(a)==0);
	cout<<"What do you want the strength of your tool to be?"<<endl;
	cin >>s;
	if (a == 'r'){
		human = new Rock;
	}
	else if(a == 's'){
		human = new Scissors;
	}
	else if( a == 'p'){
		human = new Paper;
	}
	return s;
}
/*********************************************************************************
** Function: set_ai()
** Description: Sets ai
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
void RPSGame::set_ai(){
	delete [] ai;
	ai = new Rock;
}
/*********************************************************************************
** Function: get_human()
** Description: Returns human
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
Tool* RPSGame::get_human(){
	return human;
}
/*********************************************************************************
** Function: get_ai()
** Description: Reutrns ai
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
Tool* RPSGame::get_ai(){
	return ai;
}
/*********************************************************************************
** Function: ~RPSGame()
** Description: Deletes ai and human
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
RPSGame::~RPSGame(){
	delete [] ai;
	delete [] human;
	ai = NULL;
	human =NULL;
}
/*********************************************************************************
** Function: RPSGame(const RPSGame &other)
** Description: Copy Constructor
** Parameters: const RPSGame &other
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
RPSGame::RPSGame(const RPSGame &other){
	 if(sizeof(human) ==0){

      human = NULL;
   }
   else{
      human = new Tool [sizeof(human)+1];
      for(int j=0;j<sizeof(human)+1; j++){
	    human[j] = other.human[j];
      }
   }
   if(sizeof(ai) ==0){

      ai = NULL;
   }
   else{
      ai = new Tool [sizeof(ai)+1];
      for(int j=0;j<sizeof(human)+1; j++){
	    ai[j] = other.ai[j];
      }
   }
}
/*********************************************************************************
** Function: operator =(const RPSGame &other)
** Description: Operator overload
** Parameters: const RPSGame &other
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/	
void RPSGame::operator =(const RPSGame &other){
	   if(human!=NULL){
	   delete [] human;
   }
    if(sizeof(human) ==0){

      human = NULL;
   }
   else{
      human = new Tool [sizeof(human)+1];
      for(int j=0;j<sizeof(human)+1; j++){
	    human[j] = other.human[j];
      }
   }
   if(ai!=NULL){
	   delete [] ai;
   }
   if(sizeof(ai) ==0){

      ai = NULL;
   }
   else{
      ai = new Tool [sizeof(ai)+1];
      for(int j=0;j<sizeof(human)+1; j++){
	    ai[j] = other.ai[j];
      }
   }
}
/*********************************************************************************
** Function: check_RPS(char a)
** Description: Checks for r p or s
** Parameters: char a
** Pre-Conditions: None
** Post-conditions: bool
*********************************************************************************/
bool check_RPS(char a){
	if (a == 'r' || a == 'p' || a == 's'){
		return 1;
	}
	else{
		cout<<"That was not an option. Try again."<<endl;
		return 0;
	}

}
/*********************************************************************************
** Function: set_ai2()
** Description: Sets ai level 2
** Parameters: None
** Pre-Conditions: None
** Post-conditions: None
*********************************************************************************/
void RPSGame::set_ai2(){
	int i;
	i = rand() % 3 +1;
	if (i == 1){
		ai = new Rock;
		cout<<"AI chooses rock"<<endl;
	}
	else if (i ==2){
		ai = new Scissors;
		cout<<"AI chooses scissors"<<endl;
	}
	else if (i == 3){
		ai = new Paper;
		cout<<"AI chooses paper"<<endl;
	}
}