#include"./date.h"

Date::Date(){day = 1; mon = 1; year = 2001;}
Date::Date(int d, int m, int y){ 
   day = d; mon = m; year = y;
}

int Date::getD(){
   return day;
}

int Date::getM(){
   return mon;
}

int Date::getY(){
   return year;
}

void Date::setD(int d){
   day = d;
}

void Date::setM(int m){
   mon = m;
}
void Date::setY(int y){
   year = y;
}
string Date::monN(int m){
   if (m ==1){
      return "January";
   }
   else if (m ==2){
      return "February";
   }
   else if(m==3){
      return "March";
   }
   else if(m==4){
      return "April";
   }
   else if(m==5){
      return "May";
   }
   else if (m==6){
      return "June";
   }
   else if (m==7){
      return "July";
   }
   else if (m==8){
      return "August";
   }
   else if (m==9){
      return "September";
   }
   else if (m==10){
      return "October";
   }
   else if (m==11){
      return "November";
   }
   else{
      return "December";
   }
}
bool Date::validD(int d,int m){
      if(d<32 && d>0){
	 if(m==2 && d>28){ 
	    cout<<"You didn't enter a correct day for this month(1-28)."<<endl;
	    return 0;
	 }
	 else if((m==4 || m==6 || m==9 || m==11) && d>30){
	    cout<<"You didn't enter a right day for this month (1-30)."<<endl;
	    return 0;
	 }
	 else {
	    return 1;;
	 }
      }
      else{
	 cout<<"You didn't enter a correct date."<<endl;
	 return 0;
      }
}

bool Date::validM(int m){
      if(m>0 && m<=12){
	 return 1;
      }
      else {
	 cout<< "You didn't enter a correct month (1-12)"<<endl;
	 return 0;
      }
}

bool Date::validY(int y){
      if(y<1700 || y>3000){
	 cout<<"You didn't enter a correct year (1700-3000)."<<endl;
	 return 0;
      }
      else {
	 return 1;;
      }   
}

void Date::print(int m,int d,int y){
   cout<<m<<"/"<<d<<"/"<<y<<endl;
}
void Date::print2(string m, int d,int y){
   cout<<m<<" "<<d<<","<<y<<endl;
}
void Date::print3(string m, int d, int y){
   cout<<d<<" "<<m<<" "<<y<<endl;
}




