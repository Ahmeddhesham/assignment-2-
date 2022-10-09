#pragma once
#include <iostream>
using namespace std;

class person {
protected:
	string name;
	string id;
	int age;
public:
	 person();
	 virtual void print() const= 0;
	 struct appointment {
		 int hours;
		 int minutes;
	 };
	 virtual void setname(string n);
	 virtual void setid(string i);
	 virtual void setage(int a);
	 virtual string getname()const;
	 virtual string getid()const;
	 virtual int getage()const;
};