#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N, M, H;
int Answer = INT_MAX;
bool Ladder[32][12];

bool CheckReachToSameNums()
{
	bool ret = true;
	
	int cur;
	for (int column = 1; column <= N; column++)
	{
		cur = column;
		for (int h = 1; h <= H; h++)
		{
			if (Ladder[h][cur - 1])
			{
				cur--;
			}
			else if (cur < N && Ladder[h][cur])
			{
				cur++;
			}
		}

		if (cur != column)
		{
			ret = false;
			break;
		}
	}

	return ret;
}

void DFS(int height, int cnt)
{
	if (cnt > 3)
	{
		return;
	}

	if (CheckReachToSameNums() == true)
	{
		Answer = min(Answer, cnt);
		return;
	}

	/* 배열 [1, 1] 부터 [H, N-1] 까지 순차적으로 DFS 진행 */
	for (int h = height; h <= H; h++)
	{
		for (int c = 1; c < N; c++)
		{
			if (Ladder[h][c - 1] == true || Ladder[h][c] == true || Ladder[h][c + 1] == true)
			{
				continue;
			}

			Ladder[h][c] = true;
			DFS(h, cnt + 1);
			Ladder[h][c] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> H;

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		Ladder[a][b] = true;
	}

	DFS(1, 0);
	if (Answer == INT_MAX)
	{
		Answer = -1;
	}

	cout << Answer;
	return 0;
}