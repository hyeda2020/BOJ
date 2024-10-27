#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int N, M;
vector<int> Arr;
int main()
{
	cin >> N >> M;
	
	int val;
	for (int i = 0; i < N; i++)
	{
		cin >> val;
		Arr.push_back(val);
	}
	sort(Arr.begin(), Arr.end());

	int answer = INT_MAX;

	int begin = 0;
	int end = 0;
	int size = (int)Arr.size();
	int diff;
	while (begin < size)
	{
		diff = abs(Arr[begin] - Arr[end]);
		if (diff >= M)
		{
			if (diff >= answer)
			{
				begin++;
			}
			else
			{
				answer = diff;
				if (end < size - 1)
				{
					end++;
				}
				else
				{
					begin++;
				}
			}
		}
		else
		{
			if (end < size - 1)
			{
				end++;
			}
			else
			{
				begin++;
			}
		}
	}

	cout << answer << '\n';
	return 0;
}