#include <iostream>
#include <cmath>
#include <climits>
#include <map>
using namespace std;

int N;
int Solution[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Solution[i];
	}

	if (Solution[0] >= 0)
	{
		cout << Solution[0] << " " << Solution[1] << '\n';
	}
	else if (Solution[N - 1] < 0)
	{
		cout << Solution[N - 2] << " " << Solution[N - 1] << '\n';
	}
	else
	{
		pair<int, int> answer;
		int left = 0;
		int right = N - 1;
		int minAbs = INT_MAX;
		int sum = 0;

		while (left < right)
		{
			sum = abs(Solution[left] + Solution[right]);
			if (minAbs > sum)
			{
				minAbs = sum;
				answer.first = Solution[left];
				answer.second = Solution[right];
			}

			if (Solution[left] + Solution[right] < 0)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
		cout << answer.first << " " << answer.second << '\n';
	}

	return 0;
}