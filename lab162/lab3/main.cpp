#include"./Pharmacy.h"
#include"./PatientAccount.h"
#include"./Surgery.h"
#include<fstream>

using std::fstream;

int main(){
   ofstream output;
   output.open("hospital.txt", ios::app);
   output<<"Phillip"; 
   int a, answer, b,p,y;
   float c = 0;
   while(y=1){   
      cout<<"What would you like to do?"<<endl;   
      cout<<"1. Enter a surgery."<<endl;  
      cout<<"2. Enter a medicine."<<endl;   
      cout<<"3. Check the patient out."<<endl;   
      cin >> answer;   
      if (answer == 1){      
	 surgery s1;      
	 s1.inputsur(b);      
	 c += s1.cost(b);
         output<<"|surg|";
	 output<<b;
	 output<<"|";
	 output<< s1.cost(b);
      }   
      else if(answer ==2){      
	 pharmacy p1;      
	 p1.inputphar(p);      
	 c += p1.cost(p);   
         output<<"|pharm|";
	 output<<p;
	 output<<"|";
	 output<< p1.cost(p);
      }   
      else if (answer == 3){      
	 patientaccount Phillip(c);      
	 cout<<"The total charges for Phillip are $"<<Phillip.gettotal()<<endl; 
	 output<<"|Daysin|";
	 output<<Phillip.pdays();
	 output<<endl; 
	 output.close();
	 break;
      } 
      else{
	 patientaccount Bob;
	 cout<<"You didn't enter a correct number, this is the default information."<<endl;
	 output<<endl;
	 output.close();
	 break;
      }
     }
   return 0;
}
