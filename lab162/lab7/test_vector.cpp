#include "./vector.hpp"
#include <vector>
#include <iostream>
//We do not want to include either stmt. We wouldn't
//be able to compare our vector template to the Standard
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;
int main (){
 //vector<int> v,*other; //Our vector class
 //other=v;
 //other=new vector<int>(v);
 std::vector<int> stdv; //Standard vector
 //Compare operation of our vector to std
// v.push_back(23);
stdv.push_back(23);

 //cout<<v.at(2)<<" v at "<<endl;
 //cout<<v[2]<<" v []"<<endl;
 //cout<<v.size()<<"now double"<<endl;
 //v.resize();
 //cout<<v.size()<<endl;
 std::vector<int>::iterator i; 
 i = stdv.begin();
 cout << "The contents of a vector element: " << *i << endl;


 return 0;
}
