#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, TotalBudget;
vector<int> ProvinceBungetVec;

int GetMaxBudget(int value)
{
	int ret = 0;

	for (int cur : ProvinceBungetVec)
	{
		if (cur < value)
		{
			ret += cur;
		} 
		else 
		{
			ret += value;
		}
	}

	return ret;
}

int main()
{
	cin >> N;
	int provinceBudget;

	int begin = 1;
	int end = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> provinceBudget;
		end = max(end, provinceBudget);
		ProvinceBungetVec.push_back(provinceBudget);
	}
	cin >> TotalBudget;

	int mid, tmpMaxBudget;
	int answer = 0;
	while (begin <= end)
	{
		mid = (begin + end) / 2;
		tmpMaxBudget = GetMaxBudget(mid);

		if (tmpMaxBudget > TotalBudget)
		{
			end = mid - 1;
		}
		else
		{
			begin = mid + 1;
			answer = mid;
		}
	}

	cout << answer << '\n';
	return 0;
}