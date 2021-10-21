#pragma once
#include "Hash.h"
#include "client.h"

class ClientTable : public Hash<client,int>
{
public:
	ClientTable(int s) : Hash(s) {}

	int h1(int key) override {

		return key % size;
	}
	int h2(int key) override {

		return 1 + (key % 7);
	}
};

