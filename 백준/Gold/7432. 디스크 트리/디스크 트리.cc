#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

class Node
{
public:
	string val;
	map<string, Node*> child;

	Node(string str)
	{
		this->val = str;
	}
};

class Trie
{
public:
	Node* root;

	void insertChild(Node* subRoot, vector<string>& vec, int idx)
	{
		if (idx >= (int)vec.size())
		{
			return;
		}

		string val = vec[idx];
		if (!subRoot->child.count(val))
		{
			subRoot->child.insert({ val, new Node(val) });
		}
		insertChild(subRoot->child[val], vec, idx + 1);
	}

	void printChild(Node* subRoot, int depth)
	{
		for (auto iter = subRoot->child.begin(); iter != subRoot->child.end(); iter++)
		{
			for (int i = 0; i < depth; i++)
			{
				cout << " ";
			}
			cout << iter->first << '\n';
			printChild(iter->second, depth + 1);
		}
	}

	Trie()
	{
		this->root = new Node("ROOT");
	}
};

int N;
vector<string> InputVec;
int main()
{
	cin >> N;
	string input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		InputVec.push_back(input);
	}

	vector<vector<string>> parsedInputVec;
	string buffer;
	for (string cur : InputVec)
	{
		istringstream iss(cur);
		vector<string> vec;
		while (getline(iss, buffer, '\\'))
		{
			vec.push_back(buffer);
		}
		parsedInputVec.push_back(vec);
	}

	Trie trie;
	for (size_t i = 0; i < parsedInputVec.size(); i++)
	{
		trie.insertChild(trie.root, parsedInputVec[i], 0);
	}
	trie.printChild(trie.root, 0);
	return 0;
}