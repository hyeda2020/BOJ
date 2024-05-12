#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

int N, M;
vector<pair<int, int>> Graph[1001]; // { cost, dest }
bool bVisited[1001];

int Prim()
{
	int ret = 0;
	priority_queue<
		pair<int, int>, // { cost, dest }
		vector<pair<int, int>>,
		greater<pair<int, int>>
	> PQ;

	PQ.push({ 0, 1 });
	
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
		ret += cost;
		bVisited[cur] = true;

		for (size_t i = 0; i < Graph[cur].size(); i++)
		{
			next = Graph[cur][i].second;
			PQ.push({ Graph[cur][i].first, next });
		}
	}
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	cin >> M;
	
	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		Graph[a].push_back({ c, b });
		Graph[b].push_back({ c, a });
	}

	cout << Prim() << '\n';

	return 0;
}