#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "HuffmanTree.h"
using namespace std;

int main()
{
	char choice;
	string word;

	HuffmanTree* t = new HuffmanTree();
	cout << "enter E to encode a text\n";
	cout << "enter D to decode a text\n";
	cout << "enter X to exit\n";

	do
	{
		cin >> choice;
		switch (choice)
		{
		case 'E':
		{

			cout << "enter the original text" << endl;
			cin >> word;

			//Build Huffman tree given the data inside "word".
			t->buildHuffmanTree(word);
			//Then find the code of each letter.
			//Then print the output - number of leaves, order of letters, tree structure and the encoded text - according to the explanation in the exercise.
			cout << "The encoded string is" << endl;
			cout << t->getLeaves() << endl << t->getOrderOfLetters() << endl << t->getTreeStructure() << endl << t->getEncodedText(word) << endl;

			break;
		}
		case 'D':
		{
			//input the number of leaves, the  order of letters, tree structure and the encoded text.
			int n;
			string letters, encodedStructure, encodedText;
			cout << "enter n\n";
			cin >> n;
			cout << "enter the letters\n";
			cin >> letters;
			cout << "enter the encoded structure\n";
			cin >> encodedStructure;
			cout << "enter the encoded text\n";
			cin >> encodedText;

			//checking validity
			if (2 * n - 1 != encodedStructure.length()) {
				cout << "ERROR" << endl; break;
			}

			//build the Huffman Tree according to the tree strcture. put the letters in the leaves according to the given order. 
			t->rebuildHuffmanTree(letters, encodedStructure);
			//Given the Huffman Tree and the encoded text, find the original text, and print it. 
			cout << "The decoded string is\n" << t->getDecodedText(encodedText) << endl;
		}
			break;
		case 'X': 
			cout << "bye";
			break;
		default: 
			cout << "ERROR\n"; 
			break;
		}

	} while (choice != 'X');
	return 0;
}
