#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <functional>
using namespace std;

bool bYNY[1001];
bool bVisited[1001];
int DP[1001];
vector<pair<int, int>> Graph[1001]; // { cost, dest }

int N, M, K;
void Prim()
{
	priority_queue<
		pair<int, int>, // { cost, dest }
		vector<pair<int, int>>,
		greater<pair<int, int>>
	> PQ;

	/* YNY도시들 먼저 우선순위 큐에 넣어줌 */
	for (int start = 1; start <= N; start++)
	{
		if (bYNY[start])
		{
			PQ.push({ 0, start });
			DP[start] = 0;
		}
	}

	int cur, next, ncost;
	while (!PQ.empty())
	{
		cur = PQ.top().second;
		PQ.pop();
		if (bVisited[cur])
		{
			continue;
		}
		bVisited[cur] = true;

		for (int i = 0; i < (int)Graph[cur].size(); i++)
		{
			next = Graph[cur][i].second;
			ncost = Graph[cur][i].first;
			if (!bYNY[next])
			{
				if (!bVisited[next] && (ncost < DP[next]))
				{
					DP[next] = ncost;
					PQ.push({ DP[next], next });
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M >> K;
	int yny;
	for (int i = 0; i < K; i++)
	{
		cin >> yny;
		bYNY[yny] = true;
	}

	int src, dest, cost;
	for (int i = 0; i < M; i++)
	{
		cin >> src >> dest >> cost;
		// 양방향
		Graph[src].push_back({ cost, dest });
		Graph[dest].push_back({ cost, src });
	}

	// DP 배열 초기화
	for (int i = 1; i <= N; i++)
	{
		DP[i] = INT_MAX;
	}

	Prim();

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		answer += DP[i];
	}

	cout << answer << '\n';
	return 0;
}