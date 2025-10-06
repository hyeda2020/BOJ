#include <iostream>
using namespace std;

int N;
int matrix[101][101];
long long DP[101][101];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> matrix[i][j];
		}
	}

	int next = 0;
	DP[0][0] = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (DP[i][j] == 0)	continue;	// 해당 지점을 지나는 경로가 없을 경우
			if (i == N - 1 && j == N - 1)	break;

			/* 오른쪽 */
			next = j + matrix[i][j];
			if (next < N)
			{
				DP[i][next] += DP[i][j];
			}

			/* 아래쪽 */
			next = i + matrix[i][j];
			if (next < N)
			{
				DP[next][j] += DP[i][j];
			}
		}
	}

	cout << DP[N - 1][N - 1] << '\n';
	return 0;
}