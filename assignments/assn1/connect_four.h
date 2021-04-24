/*************************************************************************
** Program Filename: connect_four.h
** Author: Megan MCCormick
** Date: 4/12/15
** Description: Prototypes all functions
** Input: None
** Output: None
*************************************************************************/
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<time.h>

using namespace std;

struct game{
   char**board;
   int r,c,p;
   char p1;
   char p2;
};

bool is_valid_arguments(char*info[]);
void set_game_info(game *, char *info[]);
char** create_table(int,int);
void play_game(game*);
bool check_winner(game);
void delete_table(game *);
void print_table(game*);
int arg_check(int,char*info[]);
bool num_check(char *, char*, char*);
bool is_num(char*);
void set_val(game *con);
void edit_colp1(game *, int);
void edit_colp2(game *, int);
bool hor(game con);
bool ver(game con);
bool dia1(game con);
bool dia2(game con);
bool full(game);
bool col_full(game *, int);
bool play_again(char *argv[]);
void delete_arg(char *argv[]);
void player_input(game *, int &);
void play_game1(game*cf);
void set_con(game *);
bool play_ai();
void set_game_info_ai(game*,char*info[]);
void set_set_con_ai(game*);
void edit_col_ai(game*,int);
void play_game_ai(game*);
void ai_input(game*,int &);
void connect_four(game*,game&,char*argv[]);
void connect(game *,game&,char*argv[]);
void connect_four_ai(game*,game&,char*argv[]);
void connect_ai(game *,game&,char*argv[]);
bool play_again_cf();
