#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int T, N;

class Node
{
public:
	char val;
	map<char, Node*> child;

	Node(char val)
	{
		this->val = val;
	}
};

class Trie
{
public:
	Node* root;

	Trie()
	{
		this->root = new Node('R');
	}

	bool insert(string str, int idx, int matchCnt, Node* pos)
	{
		if (matchCnt == (int)str.size())
		{
			return false;
		}
		if (idx == (int)str.size())
		{
			return true;
		}

		char val = str[idx];
		if (!pos->child.count(val))
		{
			Node* newNode = new Node(val);
			pos->child.insert({ val, newNode });
		}
		else
		{
			matchCnt++;
		}

		return insert(str, idx + 1, matchCnt, pos->child.find(val)->second);
	}
};

int main()
{
	cin >> T;
	string input;
	string result;
	for (int i = 0; i < T; i++)
	{
		Trie trie;
		vector<pair<int, string>> telNumVec;

		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> input;
			telNumVec.push_back({ (int)input.size(), input });
		}
		sort(telNumVec.begin(), telNumVec.end(), greater<pair<int, string>>());

		result = "YES";
		for (auto iter : telNumVec)
		{
			if (!trie.insert(iter.second, 0, 0, trie.root))
			{
				result = "NO";
			}
		}
		cout << result << '\n';
	}
	return 0;
}