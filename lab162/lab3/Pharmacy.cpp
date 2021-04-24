#include"./Pharmacy.h"

pharmacy::pharmacy(){
   pharmacycost[0]=720.8;
   pharmacycost[1]=1440.9;
   pharmacycost[2]=20.7;
   pharmacycost[3]=720.0;
   pharmacycost[4]=400.1;
   pharmacycost[5]=7206.6;
}

float pharmacy::cost(int a){
   return pharmacycost[a];
}

void pharmacy::inputphar(int &a){
   cout<<"Which medication does the patient need? (0-5)"<<endl;
   cin >> a;
}


