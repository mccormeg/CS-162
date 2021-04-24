#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<string>


using namespace std;

class Date{
   private:
      int day;
      int mon;
      int year;
   public:
      Date();
      Date(int,int,int);
      int getM();
      int getD();
      int getY();
      void print(int,int,int);
      void print2(string,int,int);
      void print3(string,int,int);
      bool validD(int,int);
      bool validM(int);
      bool validY(int);
      void setD(int);
      void setM(int);
      void setY(int);
      string monN(int);    
};
#endif
