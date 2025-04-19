#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
vector<int> Graph[1000001];
int Parents[1000001];
int bVisited[1000001];

int main()
{
	cin >> N;
	
	int src, dest;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> src >> dest;
		Graph[src].push_back(dest);
		Graph[dest].push_back(src);
	}

	queue<int> Q;
	Q.push(1);
	bVisited[1] = true;

	int cur;
	while (!Q.empty())
	{
		cur = Q.front();
		Q.pop();
		bVisited[cur] = true;

		for (int next : Graph[cur])
		{
			if (!bVisited[next])
			{
				Q.push(next);
				Parents[next] = cur;
			}
		}
	}

	for (int i = 2; i <= N; i++)
	{
		cout << Parents[i] << '\n';
	}

	return 0;
}