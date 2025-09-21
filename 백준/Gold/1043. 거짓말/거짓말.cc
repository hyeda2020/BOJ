#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, T;
vector<int> PersonVec[51];
vector<int> GroupVec[51];
bool bTrueGroup[51];
bool bVisited[51];
int main()
{
	cin >> N >> M;
	cin >> T;
	
	queue<int> truePersonQ;
	int truePerson;
	for (int i = 0; i < T; i++)
	{
		cin >> truePerson;
		bVisited[truePerson] = true;
		truePersonQ.push(truePerson);
	}

	int num, person;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			cin >> person;
			PersonVec[person].push_back(i);
			GroupVec[i].push_back(person);
		}
	}

	int groupNum, nextPerson;
	while (!truePersonQ.empty())
	{
		person = truePersonQ.front();
		truePersonQ.pop();
		bVisited[person] = true;

		for (int i = 0; i < (int)PersonVec[person].size(); i++)
		{
			groupNum = PersonVec[person][i];
			bTrueGroup[groupNum] = true;
			for (int j = 0; j < GroupVec[groupNum].size(); j++)
			{
				nextPerson = GroupVec[groupNum][j];
				if (!bVisited[nextPerson])
				{
					truePersonQ.push(nextPerson);
				}
			}
		}
	}
	
	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		if (!bTrueGroup[i])
		{
			answer++;
		}
	}
	cout << answer << '\n';
	return 0;
}