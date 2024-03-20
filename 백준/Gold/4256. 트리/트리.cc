#include <iostream>
#include <vector>
using namespace std;

int T, N;
int PreOrder[1001];
int InOrder[1001];
int InOrderIdx[1001];

void MakeTree(int preOrderIdx, int treeIdx, int inOrderLeftIdx, int inOrderRightIdx)
{
	if (inOrderLeftIdx > inOrderRightIdx) // 재귀 탈출조건
	{
		return;
	}

	int rootVal = PreOrder[preOrderIdx];
	int inOrderRootIdx = InOrderIdx[rootVal];
	int preOrderLeftChildIdx = preOrderIdx + 1;
	int preOrderRightChildIdx = preOrderIdx + (inOrderRootIdx - inOrderLeftIdx) + 1;

	MakeTree(preOrderLeftChildIdx, treeIdx * 2, inOrderLeftIdx, inOrderRootIdx - 1);
	MakeTree(preOrderRightChildIdx, treeIdx * 2 + 1, inOrderRootIdx + 1, inOrderRightIdx);
	cout << rootVal << " ";
}

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> PreOrder[i];
		}
		for (int i = 0; i < N; i++)
		{
			cin >> InOrder[i];
			InOrderIdx[InOrder[i]] = i;
		}

		MakeTree(0, 1, 0, N - 1);
		cout << '\n';
	}
	return 0;
}