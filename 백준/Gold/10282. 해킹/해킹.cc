#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int T;
vector<pair<int, int>> GraphVec[10001];
bool bVisited[10001];
long long DP[10001];

void Dijkstra(int start)
{
	int cur, next, cost;

	priority_queue<
		pair<long long, int>, // { cost, dest }
		vector<pair<long long, int>>,
		greater<pair<long long, int>>
	> PQ;

	bVisited[start] = 1;
	PQ.push({ 0, start });

	while (!PQ.empty())
	{
		cur = PQ.top().second;
		PQ.pop();

		for (size_t i = 0; i < GraphVec[cur].size(); i++)
		{
			next = GraphVec[cur][i].first;
			cost = GraphVec[cur][i].second;
			if (!bVisited[next])
			{
				bVisited[next] = 1;
				DP[next] = DP[cur] + cost;
				PQ.push({ DP[next], next });
			}
			else
			{
				if (DP[next] > DP[cur] + cost)
				{
					DP[next] = DP[cur] + cost;
					PQ.push({ DP[next], next });
				}
			}
		}
	}
}

int main()
{
	int n, d, c, a, b, s;
	int cnt = 0;
	long long time = 0;

	cin >> T;
	while (T--)
	{
		cin >> n >> d >> c;
		for (int i = 0; i < d; i++)
		{
			cin >> a >> b >> s;
			GraphVec[b].push_back({ a, s });
		}

		Dijkstra(c);
		for (int i = 1; i <= n; i++)
		{
			if (bVisited[i])
			{
				time = max(time, DP[i]);
				cnt++;
			}
		}

		cout << cnt << " " << time << '\n';

		/* 초기화 */
		memset(bVisited, 0, sizeof(bVisited));
		for (int i = 1; i <= n; i++)
		{
			DP[i] = 0;
			GraphVec[i].clear();
		}
		cnt = 0;
		time = 0;
	}

	return 0;
}