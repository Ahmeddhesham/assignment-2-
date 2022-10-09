#include <iostream>
#include "person.h"
using namespace std;

person::person() {
	name = "";
	id = "";
	age = 0;
}

void person ::setname(string n) {
	 name = n;
}

 void person:: setid(string i) {
	 id = i;
 }

 void person::setage(int a) {
	 age = a;
 }

 string person::getname()const {
	 return name;
 }

 string person::getid()const {
	 return id;
 }

int person :: getage()const{
	return age;
}