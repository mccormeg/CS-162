#ifndef pharmacy
#include<iostream>
using namespace std;

class pharmacy{
   private:
      float pharmacycost[6];
   public:
      pharmacy();
      void inputphar(int &);
      float cost(int);
};


#endif
