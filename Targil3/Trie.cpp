#include "Trie.h"

void Trie::insertWord(string str)
{
	TrieNode* node = root;

	for (int i = 0; i < str.length(); i++)
	{
		if (node->children[(int)str[i] - 97] == 0) {
			node->children[(int)str[i] - 97] = new TrieNode();
			node->isLeaf = false;
		}

		node->children[(int)str[i] - 97]->father = node;
		node = node->children[(int)str[i] - 97];

		if (i == str.length() - 1)
			node->isEndWord = true;
	}
}

bool Trie::deleteWord(string str)
{
	if (!searchWord(str))
		return false;

	TrieNode* node = root;
	int j = str.length() - 1;
								
	for (int i = 0; i < str.length(); i++)
	{
		if (node->children[(int)str[i] - 97] != 0)
		{
			node = node->children[(int)str[i] - 97];
			if (i == str.length() - 1 && node->isEndWord == true)
				break;
		}
	}
	while (node != root)
	{
		if (!node->isLeaf) {
			node->isEndWord = false;
			break;
		}
		else
		{
			node = node->father;
			delete node->children[(int)str[j] - 97];
			node->children[(int)str[j] - 97] = 0;
			if(checkIfLeaf(node))
				node->isLeaf = true;
		}
		j--;
	}

	return true;
}

bool Trie::searchWord(string str)
{
	TrieNode* node = root;

	for (int i = 0; i < str.length(); i++)
	{
		if (node->children[(int)str[i] - 97] != 0)
		{
			node = node->children[(int)str[i] - 97];
			if (i == str.length() - 1 && node->isEndWord == true)
				return true;
		}
		else
			break;
	}
	return false;
}

bool Trie::printAllWordsFromPrefix(string str)
{
	TrieNode* node = root;
	for (int i = 0; i < str.length(); i++)
	{
		if (node->children[(int)str[i] - 97] != 0)
		{
			node = node->children[(int)str[i] - 97];
			if (i == str.length() - 1) {
				printAllWordsFromPrefix(str, node);
				return true;
			}
		}
		else
			break;
	}
	return false;
}

void Trie::printAllWordsFromPrefix(string str, TrieNode* node)
{
	while (!node->isLeaf)
	{
		if (node->isEndWord)
			cout << str << endl;

		for (int i = 0; i < ALPHABET; i++)
		{
			if (node->children[i] != 0)
				printAllWordsFromPrefix(str + char(i + 97), node->children[i]);
			if (i == 25)
				return;
		}
	}
	if (node->isEndWord)
		cout << str << endl;
}

bool Trie::checkIfLeaf(TrieNode* node)
{
	for (int i = 0; i < ALPHABET; i++)
		if (node->children[i] != 0)
			return false;
	return true;
}

void Trie::deleteAllTheTree(TrieNode* node)
{
	for (int i = 0; i < ALPHABET; i++)
	{
		if (node != NULL) {
			if (node->children[i] != 0)
				deleteAllTheTree(node->children[i]);
		}
	}
	delete node;
}

