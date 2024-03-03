#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int N, K, T;
class Node {
public:
	string val;
	map<string, Node*> child;

	Node() {}
	Node(string val)
	{
		this->val = val;
	}
};

class Trie {
public:
	Node* Root;

	Trie()
	{
		this->Root = new Node("Root");
	}

	void insert(Node* pos, vector<string>& inputVec, int idx)
	{
		if (idx >= (int)inputVec.size())
		{
			return;
		}

		string val = inputVec[idx];
		if (pos->child.count(val) == 0) // 없을 경우 새로 노드 생성하여 자식에 추가
		{
			pos->child.insert({ val, new Node(val) });
		}

		/* 재귀로 진행 */
		insert(pos->child[val], inputVec, idx + 1);
	}

	void print(Node* pos, int depth)
	{
		if (pos->val != "Root")
		{
			for (int i = 1; i < depth; i++)
			{
				cout << "--";
			}
			cout << pos->val << '\n';
		}

		for (auto iter = pos->child.begin(); iter != pos->child.end(); iter++)
		{
			print(iter->second, depth + 1);
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	Trie trie;
	string str;
	for (int n = 0; n < N; n++)
	{
		cin >> K;
		vector<string> inputVec;
		for (int k = 0; k < K; k++)
		{
			cin >> str;
			inputVec.push_back(str);
		}
		trie.insert(trie.Root, inputVec, 0);
	}

	trie.print(trie.Root, 0);
	return 0;
}