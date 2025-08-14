#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
vector<pair<int, int>> Graph[301]; // { dest, cost }
int DP[301][301];

int main()
{
	cin >> N >> M >> K;

	int src, dest, cost;
	for (int i = 0; i < K; i++)
	{
		cin >> src >> dest >> cost;
		if (src <= dest)
		{
			Graph[src].push_back({ dest, cost });
		}
	}

	int next;
	for (int i = 0; i < (int)Graph[1].size(); i++)
	{
		next = Graph[1][i].first;
		cost = Graph[1][i].second;

		DP[next][2] = max(DP[next][2], cost);
	}

	for (int i = 2; i <= M; i++)
	{
		for (int cur = 1; cur <= N; cur++)
		{
			if (DP[cur][i])
			{
				for (pair<int, int> pos : Graph[cur])
				{
					next = pos.first;
					cost = pos.second;

					DP[next][i + 1] = max(DP[next][i + 1], DP[cur][i] + cost);
				}
			}
		}
	}
	
	int answer = 0;
	for (int i = 2; i <= M; i++)
	{
		answer = max(answer, DP[N][i]);
	}
	cout << answer << '\n';
	return 0;
}