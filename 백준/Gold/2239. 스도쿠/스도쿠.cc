#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Sudoku[9][9];
vector<pair<int, int>> BlankPosVec;
vector<vector<int>> ResultVec;

void MakeCheck(int r, int c, vector<bool>& check)
{
	for (int i = 0; i < 9; i++)
	{
		check[Sudoku[r][i]] = 1;
		check[Sudoku[i][c]] = 1;
	}

	int groupR = r / 3;
	int groupC = c / 3;

	for (int i = (groupR * 3); i < (groupR * 3) + 3; i++)
	{
		for (int j = (groupC * 3); j < (groupC * 3) + 3; j++)
		{
			if (Sudoku[i][j])
			{
				check[Sudoku[i][j]] = 1;
			}
		}
	}
}

void DFS(int blankPosVecIdx)
{
	if (blankPosVecIdx == (int)BlankPosVec.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << Sudoku[i][j];
			}
			cout << '\n';
		}
		exit(0);
	}

	int r = BlankPosVec[blankPosVecIdx].first;
	int c = BlankPosVec[blankPosVecIdx].second;

	vector<bool> check(10, 0);
	MakeCheck(r, c, check);

	for (int num = 1; num <= 9; num++)
	{
		if (!check[num])
		{
			Sudoku[r][c] = num;
			DFS(blankPosVecIdx + 1);
			Sudoku[r][c] = 0;
		}
	}
}

int main()
{
	string input;
	for (int i = 0; i < 9; i++)
	{
		cin >> input;
		for (int j = 0; j < 9; j++)
		{
			Sudoku[i][j] = input[j] - '0';
			if (!Sudoku[i][j])
			{
				BlankPosVec.push_back({ i, j });
			}
		}
	}

	DFS(0);
	return 0;
}