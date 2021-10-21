#pragma once
#include <iostream>

enum state { EMPTY, FULL, DELETED };

template <class T, class K>
class Item
{
public:
	T data{};
	K key{};
	state flag;
	Item() {flag = EMPTY; }
	Item(T d, K k, state f) { data = d; key = k; flag = f; }
};
