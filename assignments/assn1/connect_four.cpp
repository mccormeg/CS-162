/*********************************************************************************
** Program: connect_four.cpp
** Author: Megan McCormick
** Date: 04/12/15
** Description: All the functions for my main
** Input: rows, colunms, pieces
** Output: gameplay
**********************************************************************************/
#include"./connect_four.h"
/*********************************************************************************
** Function: is_valid_arguments
** Description: checks valid arguments
** Parameters: char*
** Pre-Conditions: none
** Post-conditions: True or False
*********************************************************************************/
bool is_valid_arguments(char*info[]){
   int x;
   char *a, *b, *c;

   a=info[2];
   b=info[4];
   c=info[6];

   if ((!strcmp(info[1], "-r") || !strcmp(info[3], "-r") || !strcmp(info[5], "-r"))&&(!strcmp(info[1],"-c")||!strcmp(info[3],"-c")||!strcmp(info[5],"-c"))&&(!strcmp(info[1],"-p")||!strcmp(info[3],"-p")||!strcmp(info[5],"-p"))){
      x=num_check(a,b,c);
      if (x ==1){
	 return 1;
      }
      else{
	 return 0;
      }
   }
   else {
      return 0;
   }

}

/*********************************************************************************
** Function: is_num
** Description: Checks that it is a number
** Parameters: char*
** Pre-Conditions: pointer
** Post-conditions: true or false
*********************************************************************************/
bool is_num(char*a){
   char d;
   for (int i=0; i< strlen(a); i++){
      d=a[i];
      if(d!='0' && d!='1' && d!='2'&& d!='3' && d!='4'&& d!='5' && d!='6' && d!= '7' && d!='8' && d!= '9'){
	 cout<< "You did not enter a correct integer."<<endl;
	 break;
	 return 0;
      }
      else{
	 return 1;
      }
   }
}

/*********************************************************************************
** Function: num_check
** Description: checks that it is not a 0
** Parameters: char*a,char*b,char*c
** Pre-Conditions: Pointers
** Post-conditions: true or false
*********************************************************************************/
bool num_check(char*a,char*b,char*c){
   int i,j,k;
   i=atoi(a);
   j=atoi(b);
   k=atoi(c);
   if(is_num(a)==1 && is_num(b)==1 && is_num(c)==1){
      if(i==0||j==0||k==0){
	 return 0;
      }
      else{
	 return 1;
      }
   }
   else{
      return 0;
   }
   
}

/*********************************************************************************
** Function: set_game_info
** Description: Sets all info for game by value
** Parameters: game*cf,char*info[]
** Pre-Conditions: empty struct
** Post-conditions: full struct
*********************************************************************************/
void set_game_info(game *cf,char *info[]){
  
  for(int i = 1; i <6;i=i+2){
       if (!strcmp(info[i],"-r")){
	cf->r = atoi(info[i+1]);
     }
     else if(!strcmp(info[i],"-c")){
        cf->c =atoi(info[i+1]);
     }
     else if(!strcmp(info[i],"-p")){
	cf->p =atoi(info[i+1]);
     }
     else{
     }
  }
  cout <<"Player one, what color would you like (first letter)?"<<endl;
  cin >> cf->p1;
  cout<<"Player two , what color would you like (first letter)?"<<endl;
  cin >> cf->p2;
  cf->board = create_table(cf->r, cf->c);
}

/*********************************************************************************
** Function: create_table
** Description: creates table
** Parameters: int r, int c
** Pre-Conditions: none
** Post-conditions: A table on the heap
*********************************************************************************/
char ** create_table(int r, int c){
   char **arry;
   arry= new char*[r];
   for (int i=0; i< r;++i){
      arry[i] = new char[c]; 
   }
   return arry;

}
/*********************************************************************************
** Function: set_val
** Description: Sets table values to NULL
** Parameters: game *con
** Pre-Conditions: None
** Post-conditions: Full table
*********************************************************************************/
void set_val(game *con){
   for (int i = 0; i< con->r; i++){    
     for ( int j = 0; j< con->c; j++){
	con->board[i][j] = NULL;
      }
   }
}
/*********************************************************************************
** Function: player_input
** Description: Gets player input
** Parameters: game *cf, int &cp1
** Pre-Conditions: None
** Post-conditions: Colunm
*********************************************************************************/
void player_input(game *cf,int &cp1){
   int x;
      cin.ignore();
   while(x=1){
      cin>>cp1;
      if (cp1>cf->c||cp1==0|| cin.fail()){
	 cout<<"Please enter a valid column."<<endl;
	 cin.clear();
	 cin.ignore();
      }
      else if(col_full(cf,cp1)==1){
	 cout<<"That column is full, please try a different one."<<endl;
      }
      else{
	 break;
      }
   }
}

/*********************************************************************************
** Function: play_game
** Description: Plays game for player 1 
** Parameters: game*cf
** Pre-Conditions: None
** Post-conditions: Play game
*********************************************************************************/
void play_game(game*cf){
   int cp1, cp2, x; 
   cout<<"Plyer 1, where do you want to put your piece?"<<endl; 
   player_input(cf,cp1);
   edit_colp1(cf,cp1);
   print_table(cf);
}
/*********************************************************************************
** Function: play_game1
** Description: Plays game for player two
** Parameters: game *cf
** Pre-Conditions: none
** Post-conditions: PLay game table print
*********************************************************************************/
void play_game1(game*cf){
   int cp1, cp2, x; 
   cout<<"Player 2, where do you want to put your piece?"<<endl; 
   player_input(cf,cp2);
   edit_colp2(cf,cp2);
   print_table(cf);
}
/*********************************************************************************
** Function: col_full
** Description: Checks if colunm is full or not
** Parameters: game *cf, int col
** Pre-Conditions: array
** Post-conditions: error message, true or false
*********************************************************************************/
bool col_full(game *cf, int col){
   if (cf->board[0][col-1] != NULL){
      return 1;
   }
   else {
      return 0;
   }
}

/*********************************************************************************
** Function: edit_colp1
** Description: places piece for player 1
** Parameters: game *cf, int col
** Pre-Conditions: Table
** Post-conditions: changed table
*********************************************************************************/
void edit_colp1(game *cf, int col){
   for (int i = (cf->r)-1; i< cf->r;i--){
      if (cf->board[i][col-1]== NULL){
	 cf->board[i][col-1] = cf->p1;
	 break;
      }
   }
}

/*********************************************************************************
** Function: edit_colp2
** Description: Places piece for player 2
** Parameters: game *cf, int col
** Pre-Conditions: Table
** Post-conditions: changed table
*********************************************************************************/
void edit_colp2(game *cf,int col){
   for (int i = (cf->r)-1; i< cf->r;i--){
      if (cf->board[i][col-1]== NULL){
	 cf->board[i][col-1] = cf->p2;
	 break;
      }
   }
}

/*********************************************************************************
** Function: check_winner
** Description: Checks winner
** Parameters: game con
** Pre-Conditions: None
** Post-conditions: true or false
*********************************************************************************/
bool check_winner(game con){
   if(ver(con)==1 || hor(con)==1 || dia1(con)==1 || dia2(con)==1){
      cout<<"You are the winner!!!"<<endl;
      return 1;
   }
   else if (full(con)==1){
      cout<<"On no, no body wins!"<<endl;
      return 1;
   }
   else {
      return 0;
   }
}

/*********************************************************************************
** Function: full
** Description: Checks if the table is full
** Parameters: game con
** Pre-Conditions: None
** Post-conditions: True or false
*********************************************************************************/
bool full(game con){
   int counter=0,area;
   area= con.r*con.c;
   for (int i = 0; i<con.r; i++){
      for (int j=0; j<con.c; j++){
	 if (con.board[i][j]!=NULL){
	    counter++;
	 }
	 else{
	    break;
	 }
      }
   }
   if (counter == area){
          return 1;
   }
   else{ 
      return 0;
   }
}


/*********************************************************************************
** Function: ver
** Description: Checks vertical
** Parameters: game con
** Pre-Conditions: none
** Post-conditions:true false
*********************************************************************************/
bool ver(game con){
   int x,counter1=1,counter2=1,y=0;
   x= (con.r-1);
   for (int i = 0; i<con.c;i++){ 
      counter1=1;
      counter2=1;    
      for (int j=0; j<x;j++){
	 if(con.board[j][i]==con.p1&&con.board[j][i]==con.board[j+1][i]){ 
	   counter1++;	 
           if (counter1 == con.p){             
              return 1;
              break;
	      y=1;
           }
	 }
	 else if(con.board[j][i]==con.p1&&con.board[j][i]==con.board[j+1][i]){ 
	    counter2++;	   
               if (counter2 == con.p){                
                 return 1;
		 break;
		 y=1;
               }
	}
      }
     
     
   }
   if(y=0){
      return 0;
   }
  
}

/*********************************************************************************
** Function: hor
** Description: checks horizontal winner
** Parameters: game con
** Pre-Conditions: none
** Post-conditions: True false
*********************************************************************************/
bool hor(game con){
   int x,counter1=1,counter2=1,y=0;
   x= (con.c-1);
   for (int i = 0; i<con.r;i++){ 
     counter1=1;
     counter2=1;    
      for (int j=0; j<x;j++){   
	if((con.board[i][j]==con.p1)&&con.board[i][j]==con.board[i][j+1]){
	   counter1++;	  
           if (counter1 == con.p){           
              return 1;
	      break;
	      y=1;
           }
	}
	else if((con.board[i][j]==con.p2)&&con.board[i][j]==con.board[i][j+1]){
	   counter1++;	
           if (counter1 == con.p){       
              return 1;
	      break;
	      y=1;
           }
	}
      }
   }
   if (y=0){
      return 0;
   }
}

/*********************************************************************************
** Function: dia1
** Description: checks winner diagonally
** Parameters: game con
** Pre-Conditions:none
** Post-conditions: true false
*********************************************************************************/

bool dia1(game con){
   int x,y,counter1=1,counter2=1,l,z=0;
   x= (con.r-con.p)+1;
   y=(con.c-con.p)+1;
   for (int i = 0; i<x;i++){ 
      for (int j=0; j<y;j ++){
	 l=1; 
         counter1=0;
         counter2=0;
	 if(((j+con.p)<=con.c) && ((i+con.p) <=con.r)){
	    for(int k=0; k<con.p;k++){     	   
	       if(con.board[i][j]==con.p1 && con.board[i][j]==con.board[i+k][j+k]){
	          counter1++;
                  if (counter1 == con.p){             	
                    return 1;
	            break;
	            z=1;
                  }
	       }
	       else if(con.board[i][j]==con.p2 && con.board[i][j]==con.board[i+k][j+k]){
	          counter2++;       
                  if (counter2 == con.p){             
                    return 1;
	            break;
	            z=1;
                  }	       
	      }
	       l=l+1;
	    } 
	 }
       }
    }
      if (z=0){
         return 0;
      }
}

/*********************************************************************************
** Function: dia2
** Description: checks winner diagonally
** Parameters: game con
** Pre-Conditions: none
** Post-conditions: true false
*********************************************************************************/
bool dia2(game con){
   int x,y,counter1=1,counter2=1,l,z=0;
   x=(con.c);
   y=(con.r);
   for (int j=0; j<x;j++){
      for (int i=0; i<y;i++){
	 l=1;
         counter1=0;
         counter2=0;
	 if(((j-con.p) >= 0) && ((i+con.p) <= y)){
            for(int k=0; k<(con.p);k++){
	       if((con.board[i][j]==con.p1) && (con.board[i][j]==con.board[i+k][j-k])){
	          counter1++;	       
                  if (counter1 == con.p){             
                     return 1;
	             break;
	             z=1;
               }
	    }
	    else if(con.board[i][j]==con.p2 && con.board[i][j]==con.board[i+k][j-k]){
	      counter2++;
              if (counter2 == con.p){             
                 return 1;	
	         break;
	         z=1;
              }
	    }
	    l=l+1;
	    }
         }
      }
   }
   if (z=0){
      return 0;
   }
}
 
/*********************************************************************************
** Function: delete_table
** Description: deletes table
** Parameters: game *cf
** Pre-Conditions: Table
** Post-conditions: No table
*********************************************************************************/
void delete_table(game *cf){
   for (int i=0; i <cf->r; i++){
      delete [] cf->board[i];
   }
   delete [] cf->board;

}

/*********************************************************************************
** Function: print_table
** Description: prints table
** Parameters: game *con
** Pre-Conditions: none
** Post-conditions: Printed table
*********************************************************************************/
void print_table(game *con){
   for (int i=0; i<con->r; i++){
     for(int j=0; j<con->c; j++){
	 cout<<" | "<<con->board[i][j];
      }
      cout<<" |"<<endl;
      for(int k =1; k <con->c; k++){
      cout<<"----";
      }
      cout<<endl;
   }
}

/*********************************************************************************
** Function: arg_check
** Description: Checks arguments
** Parameters: argc, char*argv[]
** Pre-Conditions: none
** Post-conditions: true or false
*********************************************************************************/
int arg_check(int argc, char*info[]){
   if(argc == 7){
      if(is_valid_arguments(info)==1){
	 return 1;
      }
      else{
	 cout<<"You're argument is invalid."<<endl;
	 return 0;
      }
   }
   else if (argc == 1){
      return 2;
   }
   else{
      cout<<"The number of arguments you entered is wrong. Stop breaking things."<<endl;
   }
}

/*********************************************************************************
** Function: play_again
** Description: Asks to play again
** Parameters: char*argv[]
** Pre-Conditions: none
** Post-conditions: Resets values or not, true or false
*********************************************************************************/

bool play_again( char *argv[]){
   int y; 
   argv[1]="-r";
   argv[3]="-c";
   argv[5]="-p";
   cout<<"Would you like to play again (0-no, 1-yes)?"<<endl;
   cin>> y;
   if(y==1){
     cout<<"Please enter how many rows: "<<endl;
     cin>>argv[2];
     cout<<"Please enter the number of columns: "<<endl;
     cin>> argv[4];
     cout<<"Please enter the number of pieces needed to win."<<endl;
     cin>>argv[6];
      return 1;
   }
  else if (y==0){
      return 0;
  }
   else{
      cout<<"Just for that you don't get to play again."<<endl;
      return 0;
   }
}

/*********************************************************************************
** Function: set_con
** Description: Sets connect four
** Parameters: game*
** Pre-Conditions: Empty game
** Post-conditions: full game
*********************************************************************************/
void set_con(game*cf){
  cf->r=6;
  cf->c=7;
  cf->p=4;
  cout <<"Player one, what color would you like (first letter)?"<<endl;
  cin >> cf->p1;
  cout<<"Player two , what color would you like (first letter)?"<<endl;
  cin >> cf->p2;
  cf->board = create_table(cf->r, cf->c);
}

/*********************************************************************************
** Function: play_ai
** Description: plays for ai
** Parameters: none
** Pre-Conditions: none 
** Post-conditions: turn taken
********************************************************************************/
bool play_ai(){
   int a;
   cout<<"Would you like to play with Ammen?(1-yes, 0-no)"<<endl;
   cin>> a;
   if (a== 1){
      return 1;
   }
   else if(a==0){
      return 0;
   }
   else {
      cout<<"You know what, Ammen doesn't want to play with you either."<<endl;
      return 0;
   }
}
/*********************************************************************************
** Function: set_game_info_ai
** Description: sets game info for ai game
** Parameters: game* char*
** Pre-Conditions: empty game
** Post-conditions: full game
*********************************************************************************/
void set_game_info_ai(game*cf,char*info[]){
  
  for(int i = 1; i <6;i=i+2){
     cout<<i<<endl;
       if (!strcmp(info[i],"-r")){
	cf->r = atoi(info[i+1]);
     }
     else if(!strcmp(info[i],"-c")){
        cf->c =atoi(info[i+1]);
     }
     else if(!strcmp(info[i],"-p")){
	cf->p =atoi(info[i+1]);
     }
     else{
     }
  }
  cout <<"Player one, what color would you like (first letter)?"<<endl;
  cin >> cf->p1;
  cout<<"Ammen chooses b"<<endl;
  cf->p2 = 'b';
  cf->board = create_table(cf->r, cf->c);
}
/*********************************************************************************
** Function: set_con_ai
** Description: sets connect four for ai
** Parameters: game*
** Pre-Conditions: empty game
** Post-conditions: full game
*********************************************************************************/
void set_con_ai(game*cf){
  cf->r=6;
  cf->c=7;
  cf->p=4;
  cout <<"Player one, what color would you like (first letter)?"<<endl;
  cin >> cf->p1;
  cout<<"Ammen chooses b"<<endl;
  cf->p2='b';
  cf->board = create_table(cf->r, cf->c);
}
/*********************************************************************************
** Function: edit_col_ai
** Description: edis for ai
** Parameters: game*, int
** Pre-Conditions: none
** Post-conditions: placed piece
*********************************************************************************/
void edit_col_ai(game *cf,int col){
   for (int i = (cf->r)-1; i< cf->r;i--){
      if (cf->board[i][col-1]== NULL){
	 cf->board[i][col-1] = cf->p2;
	 break;
      }
   }
}
/*********************************************************************************
** Function: play_game_ai
** Description: plays for ai
** Parameters: game*
** Pre-Conditions: none
** Post-conditions: play
*********************************************************************************/
void play_game_ai(game*cf){
   int ai; 
   cout<<"Ammen is placing his piece"<<endl; 
   ai_input(cf,ai);
   edit_colp2(cf,ai);
   print_table(cf);
}
/*********************************************************************************
** Function: ai_input
** Description: input for ai
** Parameters: game*, int &
** Pre-Conditions: none
** Post-conditions: a
*********************************************************************************/
void ai_input(game*cf,int &ai){
   int x;
   srand(time(NULL));
   while(x=1){
      ai = rand()%cf->c + 1;
      if(col_full(cf,ai)==1){
	 ai =rand()%cf->c +1;
      }
      else{
	 break;
      }
   }
}
/*********************************************************************************
** Function: connect
** Description: plays game
** Parameters:game *, game &, char* 
** Pre-Conditions: no game
** Post-conditions: game
*********************************************************************************/
void connect(game*cf, game &con, char*argv[]){
   int x=0;
   do{
      set_game_info(cf, argv);
      set_val(cf);
      print_table(cf);
      do{
	 play_game(cf);
	 x=check_winner(con);
	 if (x==0){
	    play_game1(cf);
	    x=check_winner(con);
	 }
      }while(x==0);
      delete_table(cf);
   }while(play_again(argv)==1);
}
/*********************************************************************************
** Function: connect_four
** Description: plays connect four
** Parameters: game*, game&, char*
** Pre-Conditions: no game
** Post-conditions: game
*********************************************************************************/
void connect_four(game*cf, game &con, char*argv[]){
   int x=0;
   do{
      set_con(cf);
      set_val(cf);	 
      print_table(cf);
      do{
	 play_game(cf);
	 x=check_winner(con);
	 if (x==0){
	    play_game1(cf);
	    x=check_winner(con);
	 }
      }while(x==0);
      delete_table(cf);
   }while(play_again_cf()==1);
}
/*********************************************************************************
** Function: connect_ai
** Description: plays with ai
** Parameters: game*, game&, char*
** Pre-Conditions: no game
** Post-conditions: game
*********************************************************************************/
void connect_ai(game*cf, game &con, char*argv[]){
   int x=0;
   do{
      set_game_info_ai(cf, argv);
      set_val(cf);
      print_table(cf);
      do{

	 play_game(cf);
	 x=check_winner(con);
	 if (x==0){
	    play_game_ai(cf);
	    x=check_winner(con);
	 }
      }while(x==0);
      delete_table(cf);
   }while(play_again(argv)==1);
}
/*********************************************************************************
** Function: connect_four_ai
** Description: plays game
** Parameters: game*, game&, char*
** Pre-Conditions: no game
** Post-conditions: game
*********************************************************************************/
void connect_four_ai(game*cf, game &con, char*argv[]){
   int x=0;
   do{
      set_con_ai(cf);
      set_val(cf);
      print_table(cf);
      do{
	 play_game(cf);
	 x=check_winner(con);
	 if (x==0){
	    play_game_ai(cf);
	    x=check_winner(con);
	 }
      }while(x==0);
      delete_table(cf);
   }while(play_again_cf()==1);
}
/*********************************************************************************
** Function: play_again_cf
** Description: prompt to play again
** Parameters: none
** Pre-Conditions: none
** Post-conditions: game play
*********************************************************************************/
bool play_again_cf(){
   int y; 
   cout<<"Would you like to play again (0-no, 1-yes)?"<<endl;
   cin>> y;
   if(y==1){
      return 1;
   }
  else if (y==0){
      return 0;
  }
  else{
     cout<<"Just for that you don't get to play again."<<endl;
     return 0;
  }
}







