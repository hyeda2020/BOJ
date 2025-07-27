#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L;
int main()
{
	cin >> N >> L;

	int start, end;
	vector<pair<int, int>> puddleVec;
	for (int i = 0; i < N; i++)
	{
		cin >> start >> end;
		puddleVec.push_back({ start, end });
	}
	sort(puddleVec.begin(), puddleVec.end());

	int answer = 0;
	int cnt = 0;
	int cur = 0;
	for (int i = 0; i < (int)puddleVec.size(); i++)
	{
		start = puddleVec[i].first;
		end = puddleVec[i].second;
		if (end < cur)
		{
			continue;
		}
		
		if (start < cur)
		{
			start = cur;
		}
		cnt = (end - start) / L;
		if ((end - start) % L)
		{
			cnt++;
		}
		cur = start + cnt * L;
		answer += cnt;
	}

	cout << answer << '\n';
	return 0;
}