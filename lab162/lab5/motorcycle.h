#ifndef M_H
#define M_H
#include "./vehicle.h"
class motorcycle : public vehicle {
	public:
	motorcycle();
	 motorcycle(int);
	 int get_toll(int);
};
#endif