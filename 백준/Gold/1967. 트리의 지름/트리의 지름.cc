#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int N;
bool bVisited[10001];
int DP[10001];
vector<pair<int, int>> Graph[10001];

void BFS(int num)
{
	queue<int> Q;
	bVisited[num] = true;
	Q.push(num);

	int cur, next, cost;
	while (!Q.empty())
	{
		cur = Q.front();
		Q.pop();

		for (int i = 0; i < (int)Graph[cur].size(); i++)
		{
			next = Graph[cur][i].first;
			cost = Graph[cur][i].second;
			if (!bVisited[next])
			{
				DP[next] = max(DP[next], DP[cur] + cost);
				bVisited[next] = true;
				Q.push(next);
			}
		}
	}
}

int main()
{
	cin >> N;

	int src, dest, cost;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> src >> dest >> cost;
		Graph[src].push_back({ dest, cost });
		Graph[dest].push_back({ src, cost });
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		BFS(i);
		memset(bVisited, 0, sizeof(bVisited));
		for (int j = 1; j <= N; j++)
		{
			answer = max(answer, DP[j]);
			DP[j] = 0;
		}
	}
	cout << answer << '\n';
	return 0;
}