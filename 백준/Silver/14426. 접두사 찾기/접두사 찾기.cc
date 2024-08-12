#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;

class Node
{
public:
	char val;
	map<char, Node*> childMap;

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
		root = new Node('R');
	}

	Node* getRoot()
	{
		return this->root;
	}

	void insert(Node* subRoot, string& str, int idx)
	{
		if (idx >= (int)str.size())
		{
			return;
		}

		char cur = str[idx];
		if (!subRoot->childMap.count(cur)) // 없을 경우 
		{
			Node* newNode = new Node(cur);
			subRoot->childMap.insert({ cur, newNode });
		}
		insert(subRoot->childMap.find(cur)->second, str, idx + 1);
	}

	bool check(Node* subRoot, string& str, int idx)
	{
		if (idx >= (int)str.size())
		{
			return true;
		}

		char cur = str[idx];
		if (!subRoot->childMap.count(cur))
		{
			return false;
		}
		return check(subRoot->childMap.find(cur)->second, str, idx + 1);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	Trie trie;
	string input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		trie.insert(trie.getRoot(), input, 0);
	}

	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> input;
		if (trie.check(trie.getRoot(), input, 0))
		{
			answer++;
		}
	}

	cout << answer << '\n';
	return 0;
}