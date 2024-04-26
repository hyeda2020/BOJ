#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> route[200001];
int dist[200001];

int BFS(int src, int dest)
{
	queue<int> Q;
	int cur, next, ret = -1;

	Q.push(src);
	while (!Q.empty())
	{
		cur = Q.front();
		Q.pop();

		if (cur == dest)
		{
			if (dist[cur] > -1) ret = dist[cur];
			else				ret = 0;
			break;
		}

		for (size_t i = 0; i < route[cur].size(); i++)
		{
			next = route[cur][i];
			if (dist[next] > -1)	continue;

			if (next > 100000) // 환승
			{
				Q.push(next);
				dist[next] = dist[cur] + 1;
			}
			else // 같은 노선
			{
				Q.push(next);
				dist[next] = dist[cur];
			}
		}
	}
	return ret;
}

int main()
{
	int N, L, src, dest, val;
	cin >> N >> L;

	for (int l = 1; l <= L; l++)
	{
		while (true)
		{
			cin >> val;
			if (val == -1)	break;
			route[val].push_back(l + 100000); // 노선
			route[l + 100000].push_back(val); // 해당 노선에 속한 역
		}
	}
	cin >> src >> dest;

	for (int i = 0; i <= 200000; i++)
	{
		dist[i] = -1;
	}
	cout << BFS(src, dest);
	return 0;
}