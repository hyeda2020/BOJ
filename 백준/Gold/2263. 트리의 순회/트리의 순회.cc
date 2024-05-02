#include <iostream>
using namespace std;

int inOrderArr[100001];
int postOrderArr[100001];
int indexArr[100001];

void Solution(int inBegin, int inEnd, int postBegin, int postEnd)
{
	if (inBegin > inEnd || postBegin > postEnd)	return;

	int inRootIdx = indexArr[postOrderArr[postEnd]];
	int inLeftSize = inRootIdx - inBegin;
	int inRightSize = inEnd - inRootIdx;

	cout << inOrderArr[inRootIdx] << " ";
	Solution(inBegin, inRootIdx - 1, postBegin, postBegin + inLeftSize - 1); // Left
	Solution(inRootIdx + 1, inEnd, postBegin + inLeftSize, postEnd - 1); // Right
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> inOrderArr[i];
		indexArr[inOrderArr[i]] = i;
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> postOrderArr[i];
	}

	Solution(1, N, 1, N);
	return 0;
}