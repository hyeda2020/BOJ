#include <iostream>
using namespace std;

int Drow[3] = { -1, 0, 1 };
int Dcol[3] = { 1, 1, 1 };

int R, C;
char Matrix[10001][501];
bool bVisited[10001][501];

bool DFS(int r, int c)
{
	bVisited[r][c] = true;
	if (c == C - 1)
	{
		return true;
	}

	int nr, nc;
	for (int i = 0; i < 3; i++)
	{
		nr = r + Drow[i];
		nc = c + Dcol[i];
		if (nr < 0 || nc < 0 || nr >= R || nc >= C)
		{
			continue;
		}
		if (Matrix[nr][nc] == '.' && !bVisited[nr][nc])
		{
			if (DFS(nr, nc))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> Matrix[i][j];
		}
	}

	int answer = 0;
	for (int r = 0; r < R; r++)
	{
		if (DFS(r, 0)) // 도달할 수 있음
		{
			answer++;
		}
	}
	
	cout << answer << '\n';
	return 0;
}