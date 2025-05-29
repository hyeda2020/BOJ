#include <iostream>
#include <queue>
using namespace std;

int Drow[4] = { 0, -1, 0, 1 };
int Dcol[4] = { -1, 0, 1, 0 };

int N, M;

int Matrix[1001][1001];
int Dist[1001][1001];
bool bVisited[1001][1001];

void BFS(pair<int, int> startPos)
{
	queue<pair<int, int>> Q;
	Q.push(startPos);
	bVisited[startPos.first][startPos.second] = true;

	int r, c, nr, nc;
	while (!Q.empty())
	{
		r = Q.front().first;
		c = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			nr = r + Drow[i];
			nc = c + Dcol[i];
			if (nr < 0 || nr >= N || nc < 0 || nr >= M)
			{
				continue;
			}
			if (Matrix[nr][nc] == 1 && !bVisited[nr][nc])
			{
				Q.push({ nr, nc });
				Dist[nr][nc] = Dist[r][c] + 1;
				bVisited[nr][nc] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	pair<int, int> startPos;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Matrix[i][j];
			if (Matrix[i][j] == 2)
			{
				startPos = { i, j };
			}
		}
	}

	BFS(startPos);

	/* 도달 불가능 지역 처리 */
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Matrix[i][j] == 1 && Dist[i][j] == 0)
			{
				Dist[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << Dist[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}