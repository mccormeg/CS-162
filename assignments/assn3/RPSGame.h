/*************************************************************************
** Program Filename: RPSGame.h
** Author: Megan MCCormick
** Date: 5/10/15
** Description: Prototype for RPSGame class
** Input: None
** Output: None
*************************************************************************/
#ifndef RPS_H
#define RPS_H
#include "./Tool.h"
class RPSGame{
	protected:
		Tool *human;
		Tool *ai;
		int player_win;
		int ai_win;
		int tie;
	public:
		RPSGame();
		void display_stats();
		void compare_rock(Tool);
		void compare_scissors(Tool);
		void compare_paper(Tool);
		void compare_rock_set(Tool,int);
		void compare_scissors_set(Tool, int);
		void compare_paper_set(Tool, int);
		void set_human();
		int set_human_set();
		void set_ai();
		void set_ai2();
		Tool* get_human();
		Tool* get_ai();
		virtual ~RPSGame();
		RPSGame(const RPSGame &);
		void operator =(const RPSGame &other);
};
#endif