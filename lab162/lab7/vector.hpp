#include<cstdlib>
#include<iostream>
using namespace std;
template <class T>

class vector {
 private:
 T *v;
 int s;
 int capacity;
 public:
 vector(){
	v=NULL;
	s=0;
 }
 vector(int a){
	 capacity = a;
	 s = a;
	 v = new T[s];
 }
 ~vector(){
	delete [] v;
 }
 int size(){
	return s;
 }
 void push_back(T ele) {
	T *temp=new T[s];
	for(int i=0; i<s; i++)
		temp[i]=v[i];
		delete [] v;
		s++
		capacity ++;
		v=new T[s];
	for(int i=0; i<s-1; i++)
		v[i]=temp[i];
		v[s-1]=ele;
		delete [] temp;
}
  vector(vector<T> &other){
	s = other.s;
	if(s == 0 ){
		 v=NULL;
	}
	else {
		v = new T[s];
		for(int i=0; i<s; i++){
			v[i]= other.v[i];
		}
	}
  }
  void operator=(vector<T> &other){
	if(v!=NULL){
		delete [] v;
	}
	s = other.s;
	if(s == 0 ){
		 v=NULL;
	}
	else {
		v = new T[s];
		for(int i=0; i<s; i++){
			v[i]= other.v[i];
		}
	}
  }
  void resize(){
	T *other;
	s= s*2;
	other = new T[s];
	v = other;	
  }
  T operator[](int a){
	  if(a<s)
		return v[a];
	  else
		  cout<<"You have got out of range."<<endl;
  }
  T at(int a){
	  if (a < s)
		return v[a];
	  else 
		  cout<<"Your number is too big."<<endl
  }
  
};
