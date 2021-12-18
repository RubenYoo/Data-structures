#pragma once
#include <iostream>
using namespace std;

class HuffmanNode
{
	char str;
	int frequency;
	HuffmanNode* left;
	HuffmanNode* right;
public:
	HuffmanNode(char str, int freq) {
		this->str = str;
		this->frequency = freq;
		left = NULL;
		right = NULL;
	}
	HuffmanNode() {
		this->str = 0;
		this->frequency = 0;
		left = NULL;
		right = NULL;
	}

	friend class CompareNode;
	friend class HuffmanTree;
};

class CompareNode
{
public:
	bool operator()(HuffmanNode* const& n1, HuffmanNode* const& n2) {
		return n1->frequency > n2->frequency;
	}
};