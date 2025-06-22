#include <iostream>
#include <vector>
using namespace std;

int N;
int Parent[51];
bool bErased[51];
vector<int> Child[51];

int GetTotalLeafCnt(int n)
{
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (!bErased[i])
		{
			bool bLeaf = true;
			for (int j = 0; j < (int)Child[i].size(); j++)
			{
				if (!bErased[Child[i][j]])
				{
					bLeaf = false;
					break;
				}
			}
			if (bLeaf)
			{
				ret++;
			}
		}
	}
	return ret;
}

void DeleteSubTree(int cur)
{
	int parent = Parent[cur];
	for (int i = 0; i < (int)Child[cur].size(); i++)
	{
		DeleteSubTree(Child[cur][i]);
	}

	bErased[cur] = true;
}

int main()
{
	cin >> N;
	int parent;
	for (int i = 0; i < N; i++)
	{
		cin >> parent;
		Parent[i] = parent;
		if (parent != -1)
		{
			Child[parent].push_back(i);
		}
	}

	int removal;
	cin >> removal;

	DeleteSubTree(removal);
	cout << GetTotalLeafCnt(N) << '\n';
	return 0;
}