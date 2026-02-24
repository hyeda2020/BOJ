#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int T, N, K, W;
int Cost[1001];
int DP[1001];
int Indegree[1001];
bool Graph[1001][1001];

void TopologicalSort()
{	
	queue<int> Q;
	for (int i = 1; i <= N; i++)
	{
		if (!Indegree[i])
		{
			Q.push(i);
			DP[i] = Cost[i];
		}
	}

	int cur;
	while (!Q.empty())
	{
		cur = Q.front();
		Q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (Graph[cur][i])
			{
				DP[i] = max(DP[i], Cost[i] + DP[cur]);
				if (--Indegree[i] == 0)
				{
					Q.push(i);
				}
			}
		}
	}

}

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> K;
		for (int n = 1; n <= N; n++)
		{
			cin >> Cost[n];
		}

		int src, dest;
		for (int k = 0; k < K; k++)
		{
			cin >> src >> dest;
			Graph[src][dest] = true;
			Indegree[dest]++;
		}

		TopologicalSort();

		cin >> W;
		cout << DP[W] << '\n';

		memset(Graph, 0, sizeof(Graph));
		memset(DP, 0, sizeof(DP));
		memset(Indegree, 0, sizeof(Indegree));
		memset(Cost, 0, sizeof(Cost));
	}

	return 0;
}