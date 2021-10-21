#pragma once
#include <iostream>
#include <string>
using namespace std;


class volunteer
{
public:
	string name;
	string address;
	int phone;
	string regionName;

	volunteer() {
		name = '\0';
		address = '\0';
		phone = 0;
		regionName = '\0';
	}

	volunteer(string n,string ad,int x,string reg) {
		name = n;
		address = ad;
		phone = x;
		regionName = reg;

	}
	
	volunteer operator=(volunteer v) {
		name = v.name;
		address = v.address;
		phone = v.phone;
		regionName = v.regionName;
		return *this;
	}

	bool operator==(volunteer v) {
		if (name == v.name)
			return true;
		return false;
	}

	friend ostream& operator<<(ostream& os, const volunteer& v) {

		cout << v.name << ":volunteer name=" << v.name << " phone=" << v.phone << " address=" << v.address << endl;
		return os;
	}
	friend istream& operator>>(istream& is, volunteer& v) {

		cout << "Enter volunteer name phone address\n";
		cin >> v.name;
		cin >> v.phone;
		cin >> v.address;

		return is;
	}
};

