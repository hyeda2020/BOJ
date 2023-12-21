#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int Drow[4] = { 0, -1, 0, 1 };
int Dcol[4] = { -1, 0, 1, 0 };

int N, M, CheeseCnt;
bool Matrix[102][102];
int Visited[102][102];

void ResetVisited()
{
	for (int r = 0; r <= N + 1; r++)
	{
		for (int c = 0; c <= M + 1; c++)
		{
			Visited[r][c] = 0;
		}
	}
}

void BFS(int startR, int startC)
{
	vector<pair<int, int>> cleanTgtCheesePosVec;
	queue<pair<int, int>> Q;

	Q.push({ startR, startC });
	Visited[startR][startC] = 1;

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
			if (nr < 0 || nr > N || nc < 0 || nc > M)
			{
				continue;
			}

			if (Matrix[nr][nc]) // 치즈인 경우
			{
				Visited[nr][nc]++;
				if (Visited[nr][nc] == 2)
				{
					cleanTgtCheesePosVec.push_back({ nr, nc });
				}
			}
			else
			{
				if (!Visited[nr][nc])
				{
					Visited[nr][nc] = 1;
					Q.push({ nr, nc });
				}
			}
		}
	}

	for (size_t i = 0; i < cleanTgtCheesePosVec.size(); i++)
	{
		r = cleanTgtCheesePosVec[i].first;
		c = cleanTgtCheesePosVec[i].second;
		Matrix[r][c] = 0;
		CheeseCnt--;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	// 모눈종이 외부 테두리 영역 추가(1 <= r, c <= N,M)
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= M; c++)
		{
			cin >> Matrix[r][c];
			if (Matrix[r][c])
			{
				CheeseCnt++;
			}
		}
	}

	int answer = 0;
	while (CheeseCnt > 0)
	{
		BFS(0, 0); // 모눈종이 외부 테두리에서부터 탐색 시작
		answer++;
		ResetVisited();
	}

	cout << answer;
	return 0;
}