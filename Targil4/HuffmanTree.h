#pragma once
#include "HuffmanNode.h"
#include <map>

class HuffmanTree
{
	HuffmanNode* root;
	int numbersLeaves;
public:
	HuffmanTree() { root = NULL; numbersLeaves = 0; }
	~HuffmanTree() { clear(root); }
	void buildHuffmanTree(string word);
	void rebuildHuffmanTree(string text, string tree);
	int getLeaves() { return numbersLeaves; }
	string getOrderOfLetters() { string str; calculateOrderOfLetters(root, str); return str; }
	string getTreeStructure() { string str; calculateTreeStructure(root, str); return str; }
	string getEncodedText(string word);
	string getDecodedText(string encodedText);
private:
	void calculateAllCodes(HuffmanNode* current, string str, map<char, string>& codesEncode);
	void calculateOrderOfLetters(HuffmanNode* current, string& str);
	void calculateTreeStructure(HuffmanNode* current, string& str);
	void rebuildHuffmanTree(HuffmanNode* current, string text, string tree, int& i, int& j);
	void calculateAllValues(HuffmanNode* current, string str, map<string, char>& codesDecode);
	void clear(HuffmanNode* current);
};

