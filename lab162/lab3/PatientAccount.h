#ifndef patientaccount
#include<iostream>
using namespace std;

class patientaccount{
   private:
   float charges;
   int  days;
   float perdiem;
   public:
   patientaccount(); //default constructor
   patientaccount(float);
   float gettotal();
   int pdays();
  
};
#endif
