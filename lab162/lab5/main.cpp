#include<iostream>
#include "./vehicle.h"
#include "./bike.h"
using namespace std;
int main(){
	vehicle v(4);
	bike b(1);
	vehicle *vptr = &b;
	
	cout<<v.get_seats()<<endl;
	cout<<b.get_seats()<<endl;
	cout<<v.get_toll()<<endl;
	cout<<b.get_toll()<<endl;
	cout<<vptr->get_seats()<<endl;
	cout<<vptr->get_toll()<<endl;
}