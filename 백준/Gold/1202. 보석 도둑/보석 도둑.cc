#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;

vector<pair<int, int>> JewelVec;
vector<int> BagVec;

int main()
{
	cin >> N >> K;
	int M, V;
	for (int i = 0; i < N; i++)
	{
		cin >> M >> V;
		JewelVec.push_back({ M, V });
	}
	
	int C;
	for (int i = 0; i < K; i++)
	{
		cin >> C;
		BagVec.push_back(C);
	}

	sort(JewelVec.begin(), JewelVec.end());
	sort(BagVec.begin(), BagVec.end());
	
	priority_queue<int> PQ;
	long long answer = 0;
	int jewelIdx = 0;

	for (int i = 0; i < (int)BagVec.size(); i++)
	{
		while (jewelIdx < N && BagVec[i] >= JewelVec[jewelIdx].first)
		{
			PQ.push(JewelVec[jewelIdx++].second);
		}
		if (!PQ.empty())
		{
			answer += PQ.top();
			PQ.pop();
		}
	}
	
	cout << answer << '\n';
	return 0;
}