#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <functional>
using namespace std;

int Drow[4] = { 0, -1, 0, 1 };
int Dcol[4] = { -1, 0, 1, 0 };

int N, M;
int Pool[51][51];
int Water[51][51];
bool bVisited[51][51];
bool bFillVisited[51][51];
bool bHeightVisited[51][51];

int BFS(int startR, int startC)
{
	int minHeight = 9;

	queue<pair<int, int>> Q;
	Q.push({ startR, startC });
	bVisited[startR][startC] = true;
	bHeightVisited[startR][startC] = true;

	int height = Pool[startR][startC];
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
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) // 외곽과 인접한 경우
			{
				return 0;
			}

			if (!bVisited[nr][nc] && Pool[nr][nc])
			{
				bVisited[nr][nc] = true;
				if (Pool[nr][nc] == height)
				{
					bHeightVisited[nr][nc] = true; // 같은 높이는 미리 표기(현재 단계에서 물을 채울 대상)
				}

				if (Pool[nr][nc] > height)
				{
					minHeight = min(minHeight, Pool[nr][nc]);
				}
				else
				{
					Q.push({ nr, nc });
				}
			}
		}
	}

	return minHeight;
}

void FillWater(int amount, int startR, int startC)
{
	queue<pair<int, int>> Q;
	Q.push({ startR, startC });
	bFillVisited[startR][startC] = true;
	
	int height = Pool[startR][startC];
	Water[startR][startC] += amount;
	
	int r, c, nr, nc;
	while (!Q.empty())
	{
		r = Q.front().first;
		c = Q.front().second;
		Q.pop();

		Pool[r][c] += amount;
		for (int i = 0; i < 4; i++)
		{
			nr = r + Drow[i];
			nc = c + Dcol[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M)
			{
				continue;
			}

			if (Pool[nr][nc] == height && !bFillVisited[nr][nc])
			{
				Q.push({ nr, nc });
				bFillVisited[nr][nc] = true;
				Water[nr][nc] += amount;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int minHeight = 9;
	vector<pair<int, pair<int, int>>> heightAndPosVec; // { height, { r, c} }

	cin >> N >> M;
	string input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		for (int j = 0; j < M; j++)
		{
			Pool[i][j] = input[j] - '0';
			minHeight = min(minHeight, Pool[i][j]);
			heightAndPosVec.push_back({ Pool[i][j], {i, j}});
		}
	}

	/* 높이가 작은 벽부터 진행 */
	sort(heightAndPosVec.begin(), heightAndPosVec.end());

	minHeight = 9;
	int curR, curC;
	for (size_t cur = 0; cur < heightAndPosVec.size(); cur++)
	{
		curR = heightAndPosVec[cur].second.first;
		curC = heightAndPosVec[cur].second.second;
		minHeight = BFS(curR, curC);
		if (minHeight > 0)
		{
			//Water[curR][curC] = (minHeight - Pool[curR][curC]);
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if (bHeightVisited[i][j])
					{
						Water[i][j] += (minHeight - Pool[i][j]);
						Pool[i][j] = minHeight;
					}
				}
			}
		}
		memset(bHeightVisited, 0, sizeof(bHeightVisited));
		memset(bVisited, 0, sizeof(bVisited));
	}

	/* 채울 수 있는 물의 양 계산 */
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			answer += Water[i][j];
		}
	}
	
	cout << answer;
	return 0;
}