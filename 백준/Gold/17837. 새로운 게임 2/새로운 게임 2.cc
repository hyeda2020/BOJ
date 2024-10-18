#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum {
	WHITE = 0,
	RED,
	BLUE
};

class ChessHorse
{
public:
	int num;
	int r;
	int c;
	int dir;

	ChessHorse(int num, int r, int c, int dir)
	{
		this->num = num;
		this->r = r;
		this->c = c;
		this->dir = dir;
	}
};

int Drow[5] = { 0, 0, 0, -1, 1 };
int Dcol[5] = { 0, 1, -1, 0, 0 };

int N, K;
int BoardColor[13][13];
vector<int> Board[13][13];
vector<ChessHorse*> ChessHorseVec;

int GetNextDir(int r, int c, int dir)
{
	int nr = r + Drow[dir];
	int nc = c + Dcol[dir];

	int nextDir = dir;
	if (nr > N || nr < 1 || nc > N || nc < 1 || BoardColor[nr][nc] == BLUE)
	{
		switch (dir)
		{
		case 1: // ->
			nextDir = 2;
			break;
		case 2: // <-
			nextDir = 1;
			break;
		case 3: // 위
			nextDir = 4;
			break;
		case 4: // 아래
			nextDir = 3;
			break;
		}
	}

	return nextDir;
}

bool CheckGameOver()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Board[i][j].size() >= 4)
			{
				return true;
			}
		}
	}

	return false;
}

void Move(ChessHorse* cur, int nr, int nc)
{
	int num, r, c, dir;

	num = cur->num;
	r = cur->r;
	c = cur->c;

	auto curPos = find(Board[r][c].begin(), Board[r][c].end(), num);
	if (BoardColor[nr][nc] == RED)
	{
		reverse(curPos, Board[r][c].end());
	}
	for (auto iter = curPos; iter != Board[r][c].end(); iter++)
	{
		ChessHorseVec[*iter]->r = nr;
		ChessHorseVec[*iter]->c = nc;
		Board[nr][nc].push_back(*iter);
	}
	Board[r][c].erase(curPos, Board[r][c].end());
}

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> BoardColor[i][j];
		}
	}
	ChessHorseVec.push_back(nullptr);

	int r, c, dir;
	for (int num = 1; num <= K; num++)
	{
		cin >> r >> c >> dir;
		ChessHorse* newHorse = new ChessHorse(num, r, c, dir);
		ChessHorseVec.push_back(newHorse);
		Board[r][c].push_back(num);
	}

	int answer = 0;
	int nr, nc;
	ChessHorse* cur = nullptr;

	bool flag = false;
	while (answer <= 1000)
	{
		answer++;
		for (size_t i = 1; i < ChessHorseVec.size(); i++)
		{
			cur = ChessHorseVec[i];
			cur->dir = GetNextDir(cur->r, cur->c, cur->dir);
			nr = cur->r + Drow[cur->dir];
			nc = cur->c + Dcol[cur->dir];
			if (nr > N || nr < 1 || nc > N || nc < 1 || BoardColor[nr][nc] == BLUE)
			{
				continue;
			}
			Move(cur, nr, nc);

			if (CheckGameOver())
			{
				flag = true;
				break;
			}
		}

		if (flag)
		{
			break;
		}
	}

	if (answer > 1000)
	{
		answer = -1;
	}
	cout << answer << '\n';
	return 0;
}