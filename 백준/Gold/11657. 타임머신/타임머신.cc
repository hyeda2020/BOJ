#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

enum { INF = 987654321 };

long long Dist[501];
vector<tuple<int, int, int>> EdgesVec;

bool BellmanFord(int n, int m)
{
	bool bNonNegetiveCycle = true;

	/* 거리 배열 초기화 */
	for (int i = 2; i <= n; i++)
	{
		Dist[i] = INF;
	}

	int src, dest, cost;
	for (int v = 0; v < n - 1; v++)
	{
		for (size_t e = 0; e < EdgesVec.size(); e++)
		{
			src = get<0>(EdgesVec[e]);
			dest = get<1>(EdgesVec[e]);
			cost = get<2>(EdgesVec[e]);

			if (Dist[src] != INF)
			{
				Dist[dest] = min(Dist[dest], Dist[src] + cost);
			}
		}
	}

	/* 
		[음수 사이클이 있는지 체크]
		만약 V-1 단계만큼 모든 간선들을 갱신하는 과정을 거쳤음에도 불구하고
		또다시 갱신할 간선이 있다면 이는 곧 Negative Cycle이 있다고 판단
	*/
	for (size_t e = 0; e < EdgesVec.size(); e++)
	{
		src = get<0>(EdgesVec[e]);
		dest = get<1>(EdgesVec[e]);
		cost = get<2>(EdgesVec[e]);
		if (Dist[src] != INF)
		{
			if (Dist[dest] > Dist[src] + cost)
			{
				bNonNegetiveCycle = false;
				break;
			}
		}
	}

	/* 경로가 없으면 -1로 체크 */
	for (int i = 1; i <= n; i++)
	{
		if (Dist[i] == INF)
		{
			Dist[i] = -1;
		}
	}
	return bNonNegetiveCycle;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, a, b, c;

	cin >> n >> m;

	EdgesVec.reserve(m);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		EdgesVec.push_back({ a, b, c });
	}

	if (BellmanFord(n, m))
	{
		for (int i = 2; i < n; i++)
		{
			cout << Dist[i] << '\n';
		}
		cout << Dist[n];
	}
	else // 음수 사이클이 있는 경우
	{
		cout << -1;
	}

	return 0;
}