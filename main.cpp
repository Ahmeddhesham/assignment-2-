#include <iostream>
#include "queueheader.h"
#include "customer.h"	
#include "mechanic.h"
#include "person.h"
using namespace std;

void main() {
	int numberofmechanics;
	cout << "Enter the number of mechanics: ";
	cin >> numberofmechanics;
	mechanic *mechs = new mechanic[numberofmechanics];
	string name;
	for (int i = 0; i < numberofmechanics; i++) {
		cout << "Enter the mechanic's name: ";
		cin >> name;
		mechs[i].setname(name);
	}

	int numberofcustomers;
	cout << "Enter number of customers: ";
	cin >> numberofcustomers;

	customer* c = new customer[numberofcustomers];
	

	int mechindex = 0;
	int hour, minute;
	for (int i = 0; i < numberofcustomers; i++) {
		cout << "Enter the customer's name: ";
		cin >> name;
		c[i].setname(name);
		cout << "Enter the time desired for " << c[i].getname() << endl;
		cout << "Hours: ";
		cin >> hour;
		cout << "Minutes: ";
		cin >> minute;

		if (mechs[mechindex].isavailble(hour, minute)) {
			//cout << "Appointment scheduled with "<<mechs[mechindex].getname() << endl;
			mechs[mechindex].setappointment(hour, minute);
			mechs[mechindex].setcounter(mechs[mechindex].getcounter() + 1);
			c[i].setmechanicid(mechindex);
			c[i].setappointment(hour, minute);
		}
		else {
			//cout << "mechanic " << mechs[mechindex].getname() << " is not availble at this time attempting to find another mechanic..." << endl;
			for (int j = 0; j < numberofmechanics; j++) {
				if (mechs[j].isavailble(hour, minute)) {
					cout << "Appointment scheduled with " << mechs[j].getname() << endl;
					mechs[j].setappointment(hour, minute);
					mechs[j].setcounter(mechs[j].getcounter() + 1);
					c[i].setmechanicid(j);
					c[i].setappointment(hour, minute);

					j = numberofmechanics;
				}
				
			}
		}
		if (mechindex == numberofmechanics - 1) {
			mechindex = 0;
		}
		else {
			mechindex = mechindex + 1;
		}
		
	}

	for (int i = 0; i < numberofcustomers; i++) {
		if (c[i].getmechanicid() != -1) {
			cout << "Mr/s. " << c[i].getname() << " should be assigned to " << mechs[c[i].getmechanicid()].getname() << " at " <<
				c[i].getappointment().hours << ":"<<c[i].getappointment().minutes << endl;
		}
		else {
			cout << "Unfortunately the appointment for Mr/s." << c[i].getname() << " is cancelled as there are no mechanics avaible at that time." << endl;
		}
		cout << "--------------------------------------------------------------" << endl;
	}
	
	Queue<customer> q(numberofcustomers);
	int* index = new int[numberofcustomers];
	customer temp;
	for (int i = 0; i < numberofcustomers; i++) {
		for (int j = i + 1; j < numberofcustomers; j++) {
			if (c[j] < c[i]) {
				temp = c[i];
				c[i] = c[j];
				c[j] = temp;
			}
		}
	}
	for (int i = 0; i < numberofcustomers;i++) {
		q.push(c[i]);
	}
	cout << endl;
	cout << "Queue: " << endl;
	for (int i = 0; i < numberofcustomers; i++) {
		if (q.getfront().getmechanicid() != -1) {
			cout << q.getfront().getname() << " should be assigned to " << mechs[q.getfront().getmechanicid()].getname() << " at "
				<< q.getfront().getappointment().hours << ":" << q.getfront().getappointment().minutes << endl;
		}
		q.pop();
		cout << "--------------------------------------------------------------" << endl;
	}
}