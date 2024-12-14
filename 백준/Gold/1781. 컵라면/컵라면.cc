#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int N;
int main()
{
	cin >> N;
	int deadline, cups;
	vector<pair<int, int>> vec;
	priority_queue<int, vector<int>, greater<int>> PQ;

	for (int i = 0; i < N; i++)
	{
		cin >> deadline >> cups;
		vec.push_back({ deadline, cups });
	}
	sort(vec.begin(), vec.end());

	int answer = 0;
	for (int i = 0; i < (int)vec.size(); i++)
	{
		answer += vec[i].second;
		PQ.push(vec[i].second);
		if (PQ.size() > vec[i].first)
		{
			answer -= PQ.top();
			PQ.pop();
		}
	}
	cout << answer << '\n';
	
	return 0;
}