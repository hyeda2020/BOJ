#include <iostream>
#include <cmath>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;

int Graph[1001][1001];
bool bVisited[1001];

int N, M;

int PrimBest()
{
	memset(bVisited, 0, sizeof(bVisited));
	int ret = 0;
	priority_queue<
		pair<int, int>,		// dest, cost
		vector<pair<int, int>>,
		greater<pair<int, int>>
	> PQ;

	PQ.push({ 0, 0 });

	int cur, cost;
	while (!PQ.empty())
	{
		cur = PQ.top().second;
		cost = PQ.top().first;
		PQ.pop();
		if (bVisited[cur])
		{
			continue;
		}

		if (cost == 2)
		{
			ret++;
		}
		bVisited[cur] = true;

		for (int i = 1; i <= N; i++)
		{
			if (Graph[cur][i])
			{
				PQ.push({ Graph[cur][i], i });
			}
		}
	}

	return (int)pow(ret, 2);
}

int PrimWorst()
{
	int ret = 0;
	priority_queue<
		pair<int, int>,		// dest, cost
		vector<pair<int, int>>,
		less<pair<int, int>>
	> PQ;

	PQ.push({ 0, 0 });
	

	int cur, cost;
	while (!PQ.empty())
	{
		cur = PQ.top().second;
		cost = PQ.top().first;
		PQ.pop();
		if (bVisited[cur])
		{
			continue;
		}
		
		if (cost == 2)
		{
			ret++;
		}
		bVisited[cur] = true;

		for (int i = 1; i <= N; i++)
		{
			if (Graph[cur][i])
			{
				PQ.push({ Graph[cur][i], i });
			}
		}
	}

	return (int)pow(ret, 2);
}

int main()
{
	cin >> N >> M;
	int src, dest, cost;

	cin >> src >> dest >> cost;
	if (cost) // 내리막길
	{
		cost = 1;
	}
	else // 오르막길
	{
		cost = 2;
	}
	Graph[src][dest] = cost;

	for (int i = 0; i < M; i++)
	{
		cin >> src >> dest >> cost;
		if (cost) // 내리막길
		{
			cost = 1;
		}
		else // 오르막길
		{
			cost = 2;
		}
		Graph[src][dest] = cost;
		Graph[dest][src] = cost;
	}

	cout << (PrimWorst() - PrimBest()) << '\n';
	return 0;
}