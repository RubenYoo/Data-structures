#include "Tree.h"
#include "Node.h"

Node* Tree::search(Node* p, string val, Node*& parent)
{
	if (!p)
		return nullptr;
	if (p->value == val)
		return p;
	
	Node* tmp = nullptr;
	for (auto it = p->answersList.begin(); it != p->answersList.end(); it++)
	{
		parent = p;
		tmp = search((**it).son, val, parent);
		if (tmp != nullptr)
			break;
	}
	return tmp;
}

bool Tree::searchAndPrint(Node* p, string val)
{
	Node* parent = p;
	Node* tmp = search(p, val, parent);
	if (!tmp)
		return false;
	cout << val;
	while (parent != root)
	{
		tmp = search(p, parent->value, parent);
		cout << "=>" << tmp->value;
	}
	if(root->value != val)
		cout << "=>" << root->value;
	return true;
}

void Tree::print(Node* p, int level)
{
	for (int i = 0; i < level; i++)
	{
		cout << "   ";
	}
	if (p) {
		cout << p->value << endl;
		for (auto it = p->answersList.begin(); it != p->answersList.end(); it++) {

			for (int i = 0; i < level; i++)
			{
				cout << "   ";
			}
			cout << ": " << (**it).ans << endl;
			print((**it).son, level + 1);
		}
	}
}

void Tree::process(Node* p)
{
	while (!p->isLeaf)
	{
		string answer;
		cout << p->value << endl;
		cin >> answer;
		for (auto it = p->answersList.begin(); it != p->answersList.end(); it++)
		{
			if ((*it)->ans == answer) {
				p = (*it)->son;
				break;
			}
		}
	}
	if(p)
		cout << p->value;
}

void Tree::deleteAllSubTree(Node* t, Node* p)
{
	auto it = t->answersList.begin();
	for (it; it != t->answersList.end(); it++)
	{
		deleteAllSubTree((**it).son, t);
		delete (*it);
	}
	if (it == t->answersList.end()) {
		t->answersList.clear();
		if (t != p)
			delete t;
	}
}

void Tree::addRoot(string newval)
{
	if(!root)
		root = new Node(newval);
	else
	{
		deleteAllSubTree(root,root);
		delete root;
		root = new Node(newval);
	}
}

bool Tree::addSon(string fatherquestion, string newanswer, string newval)
{
	Node* parent = root;
	Node* temp = search(root, fatherquestion, parent);
	if(!temp)
		return false;
	temp->answersList.push_back(new Answer(newanswer, new Node(newval)));
	temp->isLeaf = false;
	return true;
}

void Tree::deleteSubTree(string val)
{
	Node* tmp = nullptr;
	tmp	= search(root, val, root);
	if (tmp) {
		deleteAllSubTree(tmp,tmp);
		tmp->isLeaf = true;
	}
}
