#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int HouseCnt, RoadCnt;
int Group[200001];
int GroupSize[200001];

class Edge
{
public:
	int src;
	int dest;
	int cost;

	Edge(int& src, int& dest, int& cost)
	{
		this->src = src;
		this->dest = dest;
		this->cost = cost;
	}
};

bool Cmp(Edge& left, Edge& right)
{
	return (left.cost < right.cost);
}

int Find(int& u)
{
	if (Group[u] == u)
	{
		return u;
	}
	else
	{
		return Group[u] = Find(Group[u]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> answerVec;
	vector<Edge> roadVec;
	while (true)
	{
		cin >> HouseCnt >> RoadCnt;
		if (HouseCnt == 0 && RoadCnt == 0)
		{
			break;
		}

		for (int i = 0; i < HouseCnt; i++)
		{
			Group[i] = i;
			GroupSize[i] = 1;
		}

		roadVec.clear();

		int src, dest, cost;
		int totCost = 0;
		for (int i = 0; i < RoadCnt; i++)
		{
			cin >> src >> dest >> cost;
			totCost += cost;
			roadVec.push_back({ src, dest, cost });
		}

		int minCost = 0;
		sort(roadVec.begin(), roadVec.end(), Cmp);
		for (int i = 0; i < (int)roadVec.size(); i++)
		{
			int u = Find(roadVec[i].src);
			int v = Find(roadVec[i].dest);
			if (u != v)
			{
				if (GroupSize[u] > GroupSize[v])
				{
					swap(u, v);
				}
				Group[v] = u;
				GroupSize[u] += GroupSize[v];
				minCost += roadVec[i].cost;
			}
		}
		answerVec.push_back(totCost - minCost);
	}

	for (int cur : answerVec)
	{
		cout << cur << '\n';
	}
	return 0;
}