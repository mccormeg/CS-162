#include"./Surgery.h"

surgery::surgery(){
   surgerycost[0]=1.1;
   surgerycost[1]=100000.3;
   surgerycost[2]=275.6;
   surgerycost[3]=1234.6;
   surgerycost[4]=314.159;
   surgerycost[5]=1337.5;
}
float surgery::cost(int b){
   return surgerycost[b];
}

void surgery::inputsur(int &b){
   cout<<"Which surgery did the patient have(0-5)?"<<endl;
  cin >> b;
}

