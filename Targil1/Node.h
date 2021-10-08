#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Answer.h"
using namespace std;

class Answer;

class Node
{
public:
	list<Answer *> answersList;
	string value;
	bool isLeaf;
	Node(string v) { isLeaf = true;  value = v;}

	friend class Tree;
};

