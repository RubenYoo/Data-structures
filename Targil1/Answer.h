#pragma once
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

class Node;

//Answer: for each answer, the string, and the pointer to the node where to continue
class Answer
{
public:
	string ans;
	Node* son;
	Answer(string s, Node* p) { ans = s; son = p; }
};

