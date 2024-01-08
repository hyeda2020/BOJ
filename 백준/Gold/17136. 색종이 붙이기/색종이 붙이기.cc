#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int Answer = INT_MAX;
bool Paper[10][10];
int UsedCnt[6];

bool IsAttachable(int row, int col, int size)
{
	if (row + size - 1 >= 10 || col + size - 1 >= 10)
	{
		return false;
	}
	
	for (int r = row; r < row + size; r++)
	{
		for (int c = col; c < col + size; c++)
		{
			if (!Paper[r][c])
			{
				return false;
			}
		}
	}

	return true;
}

void Attach(int row, int col, int size)
{
	for (int r = row; r < row + size; r++)
	{
		for (int c = col; c < col + size; c++)
		{
			Paper[r][c] = 0;
		}
	}
}

void Detach(int row, int col, int size)
{
	for (int r = row; r < row + size; r++)
	{
		for (int c = col; c < col + size; c++)
		{
			Paper[r][c] = 1;
		}
	}
}

void DFS(int row, int col)
{
	while (Paper[row][col] == 0)
	{
		if (++col >= 10)
		{
			if (++row >= 10) 
			{
				int cnt = 0;
				for (int i = 1; i <= 5; i++)
				{
					cnt += UsedCnt[i];
				}
				Answer = min(Answer, cnt);
				return;
			}
			col = 0;
		}
	}

	for (int size = 5; size >= 1; size--)
	{
		if (IsAttachable(row, col, size) && UsedCnt[size] < 5)
		{
			Attach(row, col, size);
			UsedCnt[size]++;

			DFS(row, col);

			Detach(row, col, size);
			UsedCnt[size]--;
		}
	}
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> Paper[i][j];
		}
	}

	DFS(0, 0);
	
	if (Answer == INT_MAX)
	{
		Answer = -1;
	}
	cout << Answer;
	return 0;
}