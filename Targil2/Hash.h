#pragma once
#include "Item.h"
#include <iostream>
using namespace std;

template<class T, class K>
class Hash
{
public:
	Item<T, K>* table = NULL;
	int size;

	Hash(int s) {

		size = findPrime(s);
		table = new Item<T,K> [size];
	}
	~Hash() {
		
		if (table)
			delete[] table;
	}

	virtual int h1(K key) = 0;
	virtual int h2(K key) = 0;

	int hash(K key, int i) {

		return (h1(key) + h2(key) * i) % size;
	}

	int search(K key) {

		int i = 0;
		while (i < size)
		{
			int index = hash(key, i);
			if (table[index].flag == EMPTY)
				break;
			if (table[index].key == key && table[index].flag == FULL)
				return index;
			i++;
		}
		return -1;
	}

	int insert(K key, T data) {

		int i = 0;
		while (i < size)
		{
			int index = hash(key, i);
			if (table[index].flag == EMPTY || table[index].flag == DELETED)
			{
				table[index].key = key;
				table[index].data = data;
				table[index].flag = FULL;
				return index;
			}
			i++;
		}
		return -1; //overlow
	}

	bool deleteItem(K key) {
		
		int i = 0;
		while (i < size)
		{
			int index = hash(key, i);
			if (table[index].key == key)
			{
				table[index].flag = DELETED;
				return true;
			}
			if (table[index].flag == EMPTY)
				break;
		}
		return false;

	}
	void print() {

		for (int i = 0; i < size; i++)
			if (table[i].flag == FULL)
				cout << table[i].data << endl;
	}


	bool isPrime(int num)
	{
		if (num == 0 || num == 1)
			return false;
		for (int i = 2; i < num/2; i++)
			if ((num % i) == 0)
				return false;
		return true;
	}

	int findPrime(int num)
	{
		if (isPrime(num))
			return num;

		for (int i = num, j = num; i > 1; i++, j--)
		{
			if (isPrime(i))
				return i;
			if (isPrime(j))
				return j;
		}
	}

};

