#include <iostream>
#include "mechanic.h"
using namespace std;

mechanic::mechanic() {
	counter = 0;

	for (int i = 0; i < 24; i++) {
		app[i].hours = -1;
		app[i].minutes = -1;
	}
}

void mechanic::setcounter(int c) {
	counter = c;
}

void mechanic::setappointment(int h, int m) {
	//the array has 24 slots each slot represnts the 24 hours of the day. slot 0 is 12:00 am or 00:00 am int 24 hour format.
	//So i before hand know the index of each hour as the hour is = to its index
	app[h].hours = h;
	app[h].minutes = m;
}

int mechanic::getcounter()const {
	return counter;
}

person::appointment* mechanic::getappointment() {
	return app;
}

bool mechanic::isavailble(int h, int m) {
	//the array has 24 slots each slot represnts the 24 hours of the day. slot 0 is 12:00 am or 00:00 am int 24 hour format.
	//So i before hand know the index of each hour as the hour is = to its index
	// so by checking the this index is still set to -1 as set in the constructor then this time is availble.
	if ((app[h].hours == -1)&&(app[h].minutes ==-1)) {
		return true;
	}
	return false;
}

void mechanic::print() const{
	cout << "override";
}