#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iomanip>

using namespace std;

struct mult_div_values{
   int mult;
   float div;
};

bool is_valid_diminsions(char*m, char*n);
mult_div_values** create_table(int,int);
void set_div_values(mult_div_values**,int,int);
void set_mult_values(mult_div_values**,int,int);
void delete_table(mult_div_values **table,int m);
void notalettercols(char*b);
void notaletterrows(char*c);
void play_again(int &x,char *b, char*c);
