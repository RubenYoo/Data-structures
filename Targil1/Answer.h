#pragma once
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

class Node;

class Answer
{
public:
	string ans;
	Node* son;
	Answer(string s, Node* p) { ans = s; son = p; }
};

