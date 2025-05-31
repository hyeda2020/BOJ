#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int N, M, T;
vector<pair<int, int>> Graph[10001]; // { dest, cost }
bool bVisited[10001];

int Prim()
{
	int ret = 0;

	priority_queue<
		pair<int, int>, // cost, dest
		vector<pair<int, int>>,
		greater<pair<int, int>>
	> PQ;

	PQ.push({ 0, 1 });
	
	int cur, cost;
	pair<int, int> next;
	int loadCost = 0;
	int cnt = 0;

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
		ret += (cost + loadCost);
		
		for (int i = 0; i < Graph[cur].size(); i++)
		{
			next = Graph[cur][i];
			PQ.push({ next.second, next.first });
		}

		cnt++;
		if (cnt >= 2)
		{
			loadCost += T;
		}
	}

	return ret;
}

int main()
{
	cin >> N >> M >> T;

	int src, dest, cost;
	for (int i = 0; i < M; i++)
	{
		cin >> src >> dest >> cost;
		Graph[src].push_back({ dest, cost });
		Graph[dest].push_back({ src, cost });
	}

	cout << Prim() << '\n';
	return 0;
}