#pragma once
#include "VolunteerTable.h"
#include "ClientTable.h"
#include <iostream>
#include <algorithm>
using namespace std;

class HashTbls
{
	VolunteerTable* tab1;
	ClientTable* tab2;

public:
	HashTbls() {

		tab1 = new VolunteerTable(100);
		tab2 = new ClientTable(100);
	}
	~HashTbls() {
		delete tab1;
		delete tab2;
	}

	void addVolunteer(volunteer v) {

		tab1->insert(v.name, v);
	}

	void delVolunteer(volunteer v) {

		if (!tab1->deleteItem(v.name))
		{
			cout << "ERROR\n";
		}
	}

	void addClient(client c) {

		tab2->insert(c.phone, c);
	}
	void delClient(client c) {
		tab2->deleteItem(c.phone);
	}
	
	void addVolunteerToClient(volunteer v, client c) {

		int x = tab1->search(v.name);
		int y = tab2->search(c.phone);

		if (x != -1 && y != -1)
		{
			std::list<volunteer>::iterator it;
			it = std::find(tab2->table[y].data.helped.begin(), tab2->table[y].data.helped.end(), v);

			if (it == tab2->table[y].data.helped.end())
				tab2->table[y].data.helped.push_back(v);
			else
				cout << "ERROR" << endl;
		}
		else {
			cout << "ERROR" << endl;
		}
	}
	void listOfVolunteers(client c) {

		int x = tab2->search(c.phone);

		cout << "The volunteers that helped to client " << c.phone << ": ";
		if (x != -1) {

			for (std::list<volunteer>::iterator it = tab2->table[x].data.helped.begin(); it != tab2->table[x].data.helped.end(); it++)
			{
				cout << ' ' << it->name;
			}
		}

	}
	void listOfClients(volunteer v) {

		cout << "The clients that were helped by volunteer "<< v.name <<": ";


		for (int i = 0; i < 100; i++)
		{
			if (tab2->table[i].flag == FULL)
			{
				std::list<volunteer>::iterator it;
				it = std::find(tab2->table[i].data.helped.begin(), tab2->table[i].data.helped.end(), v);

				if (it != tab2->table[i].data.helped.end())
					cout << tab2->table[i].data.name << ' ';
			}
		}
		cout << endl;
		
	}

	void printTables() {
		cout << "Volunters:\n";
		tab1->print();
		cout << "Clients:\n";
		tab2 ->print();
	}
};

