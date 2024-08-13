#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int N, M;
vector<pair<int, int>> Graph[100001]; // { dest, cost }
bool bVisited[100001];

long long Prim(int start)
{
	priority_queue<
		pair<int, int>, // cost, dest
		vector<pair<int, int>>,
		greater<pair<int, int>>
	> PQ;

	PQ.push({ 0, start });

	long long ret = 0;
	int cur, next, cost, ncost;
	while (!PQ.empty())
	{
		cur = PQ.top().second;
		cost = PQ.top().first;
		PQ.pop();
		if (bVisited[cur])
		{
			continue;
		}
		bVisited[cur] = true;
		ret += cost;

		for (int i = 0; i < (int)Graph[cur].size(); i++)
		{
			next = Graph[cur][i].first;
			ncost = Graph[cur][i].second;
			PQ.push({ ncost, next });
		}
	}

	return ret;
}

int main()
{
	cin >> N >> M;

	int src, dest;
	long long cost, totCost = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> src >> dest >> cost;
		Graph[src].push_back({ dest, cost });
		Graph[dest].push_back({ src, cost });
		totCost += cost;
	}

	long long mst = Prim(1);
	bool bNonVisited = false;

	for (int i = 1; i <= N; i++)
	{
		if (!bVisited[i])
		{
			bNonVisited = true;
			break;
		}
	}

	if (bNonVisited)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << totCost - mst << '\n';
	}
	return 0;
}