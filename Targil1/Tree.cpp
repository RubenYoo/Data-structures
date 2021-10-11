#include "Tree.h"
#include "Node.h"

Node* Tree::search(Node* p, string val, Node*& parent)
{
	if (!p)
		return NULL;
	if (p->value == val)
		return p;
	
	Node* tmp = NULL;
	for (std::list<Answer*>::iterator it = p->answersList.begin(); it != p->answersList.end(); it++)
	{
		parent = p;
		tmp = search((**it).son, val, parent);
		if (tmp != NULL)
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
		for (std::list<Answer*>::iterator it = p->answersList.begin(); it != p->answersList.end(); it++) {

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
		for (std::list<Answer*>::iterator it = p->answersList.begin(); it != p->answersList.end(); it++)
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
	if (t) {
		std::list<Answer*>::iterator it = t->answersList.begin();
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

string Tree::printToString(Node* p)
{
	string str;
	if (p) {
		if (p == root)
			str += "( ";
		str += p->value + " ";
		for (std::list<Answer*>::iterator it = p->answersList.begin(); it != p->answersList.end(); it++) {

			str += "( ";
			str += (**it).ans + " ";
			str += printToString((**it).son);
		}
		str += " )";
	}
	return str;
}

void Tree::deleteSubTree(string val)
{
	Node* tmp = NULL;
	Node* parent = root;
	tmp	= search(root, val, parent);
	if (tmp) {
		deleteAllSubTree(tmp,tmp);
		tmp->isLeaf = true;
	}
}
