#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int N, Q;
vector<pair<int, int>> Graph[5001]; // dest, cost
int DP[5001][5001];
bool bVisited[5001];

void BFS(int vtx)
{
	queue<pair<int, int>> Q; // next, USADO
	Q.push({ vtx, INT_MAX });
	bVisited[vtx] = true;

	int cur, usado;
	while (!Q.empty())
	{
		cur = Q.front().first;
		usado = Q.front().second;
		Q.pop();

		int next;
		for (size_t i = 0; i < Graph[cur].size(); i++)
		{
			next = Graph[cur][i].first;
			if (!bVisited[next])
			{
				bVisited[next] = true;
				DP[vtx][next] = min(Graph[cur][i].second, usado);
				Q.push({ next, DP[vtx][next] });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> Q;

	int p, q, r;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> p >> q >> r;
		Graph[p].push_back({ q, r });
		Graph[q].push_back({ p, r });
	}

	for (int i = 1; i <= N; i++)
	{
		BFS(i);
		memset(bVisited, 0, sizeof(bVisited));
	}
	
	int k, v, answer;
	for (int i = 0; i < Q; i++)
	{
		cin >> k >> v;
		
		answer = 0;
		for (int j = 1; j <= N; j++)
		{
			if (DP[v][j] >= k)
			{
				answer++;
			}
		}
		cout << answer << '\n';
	}
	return 0;
}