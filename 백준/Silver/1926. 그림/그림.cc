#include <iostream>
#include <algorithm>
using namespace std;

int Drow[4] = { 0, -1, 0, 1 };
int Dcol[4] = { -1, 0, 1, 0 };

int N, M, Count;
bool Graph[501][501];
bool bVisited[501][501];

void DFS(int r, int c)
{
	bVisited[r][c] = true;
	Count++;

	int nr, nc;
	for (int i = 0; i < 4; i++)
	{
		nr = r + Drow[i];
		nc = c + Dcol[i];
		if (nr < 0 || nr >= N || nc < 0 || nc >= M)
		{
			continue;
		}
		if (!bVisited[nr][nc] && Graph[nr][nc])
		{
			DFS(nr, nc);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Graph[i][j];
		}
	}

	int maxSize = 0;
	int pictureCnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Graph[i][j] && !bVisited[i][j])
			{
				DFS(i, j);
				maxSize = max(maxSize, Count);
				pictureCnt++;
				Count = 0;
			}
		}
	}

	cout << pictureCnt << '\n' << maxSize << '\n';
	return 0;
}