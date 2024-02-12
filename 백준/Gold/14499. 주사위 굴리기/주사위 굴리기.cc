#include <iostream>
using namespace std;
enum {EAST = 1, WEST, NORTH, SOUTH};
int drow[5] = {0, 0, 0, -1, 1};
int dcol[5] = {0, 1, -1, 0, 0};

int N, M, x, y, K;
int matrix[20][20];

int up;
int street[3];	// 가로
int column[3];	// 세로

void MoveE(int nr, int nc)
{
	int temp = street[0];
	street[0] = street[1];
	street[1] = street[2];
	street[2] = up;
	up = temp;

	if (matrix[nr][nc] == 0)
	{
		matrix[nr][nc] = street[1];
	}
	else
	{
		street[1] = matrix[nr][nc];
		matrix[nr][nc] = 0;
	}
	column[1] = street[1];
}

void MoveW(int nr, int nc)
{
	int temp = street[2];
	street[2] = street[1];
	street[1] = street[0];
	street[0] = up;
	up = temp;

	if (matrix[nr][nc] == 0)
	{
		matrix[nr][nc] = street[1];
	}
	else
	{
		street[1] = matrix[nr][nc];
		matrix[nr][nc] = 0;
	}
	column[1] = street[1];
}

void MoveN(int nr, int nc)
{
	int temp = column[2];
	column[2] = column[1];
	column[1] = column[0];
	column[0] = up;
	up = temp;

	if (matrix[nr][nc] == 0)
	{
		matrix[nr][nc] = column[1];
	}
	else
	{
		column[1] = matrix[nr][nc];
		matrix[nr][nc] = 0;
	}
	street[1] = column[1];
}

void MoveS(int nr, int nc)
{
	int temp = column[0];
	column[0] = column[1];
	column[1] = column[2];
	column[2] = up;
	up = temp;

	if (matrix[nr][nc] == 0)
	{
		matrix[nr][nc] = column[1];
	}
	else
	{
		column[1] = matrix[nr][nc];
		matrix[nr][nc] = 0;
	}
	street[1] = column[1];
}

int main()
{
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> matrix[i][j];
		}
	}

	int command, nx, ny;
	while (K--)
	{
		cin >> command;
		nx = x + drow[command];
		ny = y + dcol[command];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)	continue;
		switch (command)
		{
		case EAST:
			MoveE(nx, ny);
			break;
		case WEST:
			MoveW(nx, ny);
			break;
		case NORTH:
			MoveN(nx, ny);
			break;
		case SOUTH:
			MoveS(nx, ny);
			break;
		}
		cout << up << '\n';
		x = nx, y = ny;
	}
	return 0;
}