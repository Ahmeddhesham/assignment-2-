#include <iostream>
#include "person.h"
#include "customer.h"
using namespace std;

customer::customer() {
	mechanicid = -1;
	app.hours = -1;
	app.minutes = -1;
}

void customer::setmechanicid(int mid) {
	mechanicid = mid;
}

void customer::setappointment(int h, int m) {
	app.hours = h;
	app.minutes = m;
}

int customer::getmechanicid()const {
	return mechanicid;
}

person::appointment customer::getappointment()const {
	return app;
}

bool customer::operator<(customer&b) {


	//first check the hours then the minutes
	if (this->app.hours < b.app.hours) {
		return true;
	}
	//now the minutes
	else if (this->app.hours == b.app.hours) {
		if (this->app.minutes < b.app.minutes) {
			return true;
		}
		else if (this->app.minutes == b.app.minutes) {
			return false;
		}
		else {
			return false;
		}
	}
	//if both conditions are not true then This surely has a bigger time.
	else {
		return false;
	}
}

bool customer::operator>(customer& b) {

	if (this->app.hours > b.app.hours) {
		return true;
	}
	//now the minutes
	else if (this->app.hours == b.app.hours) {
		if (this->app.minutes > b.app.minutes) {
			return true;
		}
		else if (this->app.minutes == b.app.minutes) {
			return false;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool customer::operator==(customer& b) {
	if ((this->app.hours == b.app.hours) && (this->app.minutes == b.app.minutes)) {
		return true;
	}
	return false;
}

void customer::print()const {
	cout << "The name of customer: " << name << endl;
	cout << "The age of the customer: " << age<<endl;
	cout << "The Id of the customer: " << id << endl;
	cout << "The assigned mechanic id: " << mechanicid << endl;
	cout << "The appointment time is: " << app.hours << ":" << app.minutes<<endl;
}