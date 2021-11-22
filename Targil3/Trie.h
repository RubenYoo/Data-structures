#pragma once
#include <iostream>
#include <string>

using namespace std;

const int ALPHABET = 26;

class Trie
{
protected:
	class TrieNode
	{
	public:
		TrieNode* children[ALPHABET] = { 0 };
		TrieNode* father;
		bool isEndWord = false;
		int isLeaf = true;
		TrieNode() {};
	};
	TrieNode* root;
public:
	Trie() { root = new TrieNode(); };
	
	void insertWord(string str);
	bool deleteWord(string str);
	bool searchWord(string str);
	bool printAllWordsFromPrefix(string str);
private:
	void printAllWordsFromPrefix(string str, TrieNode* node);
};


