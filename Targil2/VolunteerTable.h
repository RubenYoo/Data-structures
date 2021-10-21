#pragma once
#include "Hash.h"
#include "volunteer.h"

class VolunteerTable : public Hash<volunteer,string>
{
public:
	VolunteerTable(int s) : Hash(s) {}

	int h1(string key) override {

		int hashCode = 0;
		for (int i = 0; i < key.size(); i++) 
			hashCode += key[i]; 

		return hashCode % size;
	}

	int h2(string key) override {

		int hashCode = 5381;

		for (int i = 0; i < key.size(); i++)
			hashCode = ((hashCode << 5) + hashCode) + key[i];

		return hashCode;
	}

};

