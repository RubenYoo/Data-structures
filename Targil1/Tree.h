#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Answer.h"
#include "Node.h"
using namespace std;

class Tree
{
	Node* root;
	Node* search(Node* p, string val, Node*& parent);

	bool searchAndPrint(Node* p, string val);
	void print(Node* p, int level = 0);
	void process(Node* p);
public:
	Tree() { root = NULL; }
	~Tree() {
		deleteAllSubTree(root,root);
		delete root;
		root = 0;
	}
	void deleteAllSubTree(Node* t, Node* p);
	void addRoot(string newval);
	bool addSon(string fatherquestion, string newanswer, string newval);
	void searchAndPrint(string val)
	{
		if (!searchAndPrint(root, val))
			cout << "Value not found" << endl;
	}
	void printAllTree() { print(root); }
	void deleteSubTree(string val);
	void process() { process(root); }
};