/* 풀이 출처 : https://uiop5809.tistory.com/123 */
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;
int Graph[501][501];

void FloydWarshall()
{
	for (int m = 1; m <= N; m++)
	{
		for (int s = 1; s <= N; s++)
		{
			for (int d = 1; d <= N; d++)
			{
				if (Graph[s][m] != INT_MAX && Graph[m][d] != INT_MAX && s != d)
				{
					Graph[s][d] = min(Graph[s][d], Graph[s][m] + Graph[m][d]);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			Graph[i][j] = INT_MAX;
		}
	}

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		Graph[a][b] = 1;
	}

	FloydWarshall();

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++)
		{
			// i보다 큰 사람이 존재 || i보다 작은 사람이 존재
			if (Graph[i][j] != INT_MAX || Graph[j][i] != INT_MAX)
			{
				cnt++;
			}
		}
		/*
			자신을 제외한 모든 정점과 연결되어 있다면
			자신의 위치를 알 수 있음
		*/
		if (cnt == N - 1) 
		{
			answer++;
		}
	}

	cout << answer << '\n';
	return 0;
}