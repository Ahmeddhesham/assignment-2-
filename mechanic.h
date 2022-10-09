#pragma once
#include <iostream>
#include "person.h"
using namespace std;

class mechanic : public person {
private:
	int counter;
	appointment app[24];

public:
	mechanic();

	void setcounter(int c);
	void setappointment(int h, int m);

	int getcounter()const;
	appointment* getappointment();


	bool isavailble(int h, int m);
	void print()const;
};