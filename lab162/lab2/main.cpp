#include"./date.h"

int main(){
   Date d1, d2(12,12,2003);
   if(d2.validD(d2.getD(),d2.getM())==1 && d2.validM(d2.getM())==1 && d2.validY(d2.getY())==1){
   d2.print(d2.getM(), d2.getD(),d2.getY());
   d2.print2(d2.monN(d2.getM()), d2.getD(),d2.getY());
   d2.print3(d2.monN(d2.getM()), d2.getD(),d2.getY());
   }
   else{
   d1.print(d1.getM(), d1.getD(),d1.getY());
   d1.print2(d1.monN(d1.getM()), d1.getD(),d1.getY());
   d1.print3(d1.monN(d1.getM()), d1.getD(),d1.getY());
   }
   return 0;
}

