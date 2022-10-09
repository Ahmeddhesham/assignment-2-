#pragma once
#include <iostream>
#include "person.h"
using namespace std;

class customer :public person {
private:
	int mechanicid;
	appointment app;
public:
	
	customer();

	void setmechanicid(int mid);
	void setappointment(int h, int m);

	int getmechanicid()const;
	appointment getappointment()const;

	bool operator <(customer& b);
	bool operator >(customer& b);
	bool operator ==(customer& b);

	void print()const;

};