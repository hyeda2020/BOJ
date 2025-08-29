#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

/*
	a~z : 1~26
	A~Z : 27~52
	a : 97 - 96
	A : 65 - 38
*/
int N;
vector<pair<int, int>> Graph[51]; // { cost, dest }
bool bVisited[51];

int Prim()
{
	int ret = 0;
	priority_queue<
		pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>
	> PQ;
	
	PQ.push({ 0, 0 });

	int cur, cost, next, ncost;
	while (!PQ.empty())
	{
		cur = PQ.top().second;
		cost = PQ.top().first;
		PQ.pop();
		if (bVisited[cur])
		{
			continue;
		}

		bVisited[cur] = true;
		ret += cost;

		for (int i = 0; i < (int)Graph[cur].size(); i++)
		{
			ncost = Graph[cur][i].first;
			next = Graph[cur][i].second;
			if (cur != next && ncost)
			{
				PQ.push({ ncost, next });
			}
		}
	}
	return ret;
}

bool CheckAllVisited(int n)
{
	bool ret = true;
	for (int i = 0; i < n; i++)
	{
		if (!bVisited[i])
		{
			ret = false;
			break;
		}
	}
	return ret;
}

int main()
{
	cin >> N;
	string input;
	int val, totLength = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		for (int j = 0; j < N; j++)
		{
			if (input[j] >= 97) // 소문자
			{
				val = (int)input[j] - 96;
			}
			else if (input[j] == '0')
			{
				val = 0;
			}
			else // 대문자
			{
				val = (int)input[j] - 38;
			}

			Graph[i].push_back({ val, j });
			Graph[j].push_back({ val, i });
			totLength += val;
		}
	}

	int minLength = Prim();
	int answer = 0;
	if (minLength && CheckAllVisited(N))
	{
		answer = (totLength - minLength);
	}
	else if (N == 1) // 예외 케이스 : 하나만 있는 경우엔 그 자체로 완전한 SubGraph
	{
		answer = Graph[0][0].first;
	}
	else
	{
		answer = -1;
	}
	cout << answer << '\n';
	return 0;
}