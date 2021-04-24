#include"./PatientAccount.h"


patientaccount::patientaccount(){days=1; perdiem = 100; charges=100;};
patientaccount::patientaccount(float c){
   int d;
   cout<<"How long was the patient in the hospital?"<<endl;
   cin>> d;
   charges = 0;
   days = d; perdiem = 100; charges += (days*perdiem)+(c);
}

float patientaccount::gettotal(){
   return charges;
}
int patientaccount::pdays(){
   return days;
}



