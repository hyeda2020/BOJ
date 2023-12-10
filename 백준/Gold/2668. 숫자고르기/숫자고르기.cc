#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int N;
int Graph[101];
bool bVisited[101];
vector<int> Stk;
set<int> Set;

void DFS(int cur, int start)
{
	if (Graph[cur] == start)
	{
		Stk.push_back(Graph[cur]);
		for (size_t i = 0; i < Stk.size(); i++)
		{
			Set.insert(Stk[i]);
		}
		Stk.pop_back();
		return;
	}

	int next = Graph[cur];

	Stk.push_back(next);
	bVisited[cur] = true;
	if (!bVisited[next])
	{
		DFS(next, start);
	}
	bVisited[cur] = false;
	Stk.pop_back();
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Graph[i];
	}

	for (int i = 1; i <= N; i++)
	{
		DFS(i, i);
	}

	cout << static_cast<int>(Set.size()) << '\n';
	for (auto iter = Set.begin(); iter != Set.end(); iter++)
	{
		cout << *iter << '\n';
	}
	return 0;
}