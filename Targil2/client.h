#pragma once
#include <iostream>
#include <string>
#include <list>
#include "volunteer.h"
using namespace std;

class client
{
public:
	string name;
	int phone;
	string address;
	list<volunteer> helped;

	client() {
		name = '\0';
		phone = 0;
		address = '\0';
	}

	client operator=(client c) {
		name = c.name;
		address = c.address;
		phone = c.phone;
		return *this;
	}

	bool operator==(client c) {
		if (phone == c.phone)
			return true;
		return false;
	}

	friend ostream& operator<<(ostream& os, const client& c) {

		cout << c.phone << ":client name: " << c.name << " phone: " << c.phone << " address: " << c.address
			<< " helped by: ";

		for (std::list<volunteer>::const_iterator it = c.helped.begin(); it != c.helped.end(); it++)
			cout << (it)->name << " ";

		cout << endl;
		return os;
	}
	friend istream& operator>>(istream& is, client& c) {

		cout << "please enter name and phone and address of client\n";
		cin >> c.name;
		cin >> c.phone;
		cin >> c.address;

		return is;
	}
};

