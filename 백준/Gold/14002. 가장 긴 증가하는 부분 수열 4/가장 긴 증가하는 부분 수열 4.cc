#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int seq[1001];
int DP[1001];
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> seq[i];
	}

	int res = 1;
	int max_idx = 1;
	for (int i = 1; i <= N; i++)
	{
		DP[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (seq[j] < seq[i])
			{
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}

		if (res < DP[i])
		{
			res = DP[i];
			max_idx = i;
		}
	}
	cout << res << endl;
	
	vector<int> vec;
	int cur = seq[max_idx];
	int cur_idx = max_idx;

	vec.push_back(cur);
	for (int i = max_idx - 1; i > 0; i--)
	{
		if (cur > seq[i] && DP[i] == DP[cur_idx] - 1)
		{
			vec.push_back(seq[i]);
			cur = seq[i];
			cur_idx = i;
		}
	}
	
	for (int i = vec.size() - 1; i >= 0; i--)
	{
		cout << vec[i] << " ";
	}
	return 0;
}