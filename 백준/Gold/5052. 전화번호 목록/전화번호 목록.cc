#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

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

	bool insert(string str, int idx, int cnt, Node* pos)
	{
		if (cnt == (int)str.size())
		{
			return false;
		}
		if (idx == (int)str.size())
		{
			return true;
		}

		char val = str[idx];
		if (pos->child.count(val) == 0)
		{
			Node* newNode = new Node(val);
			pos->child.insert({ val, newNode });
		}
		else // 이미 있는 경우
		{
			cnt++;
		}
		
		return insert(str, idx + 1, cnt, pos->child.find(val)->second);
	}
};


int main()
{
	int T, N;
	cin >> T;

	string telNum;
	string res;
	for (int t = 0; t < T; t++)
	{
		vector<pair<int, string>> telNumVec;
		Trie trie;

		cin >> N;
		for (int n = 0; n < N; n++)
		{
			cin >> telNum;
			telNumVec.push_back({ (int)telNum.size(), telNum });
		}

		sort(telNumVec.begin(), telNumVec.end(), greater<pair<int, string>>());

		res = "YES";
		for (auto iter : telNumVec)
		{
			if (!trie.insert(iter.second, 0, 0, trie.root))
			{
				res = "NO";
				break;
			}
		}

		cout << res << '\n';
	}
	return 0;
}