/* 문제풀이 출처 : https://transferhwang.tistory.com/347 */
#include <iostream>
#include <string>
#include <climits>
using namespace std;

int N;
void Push(string& str, int idx)
{
	for (int i = idx - 1; i <= idx + 1; i++)
	{
		if (i < 0 || i >= N)
		{
			continue;
		}
		if (str[i] == '0')	str[i] = '1';
		else				str[i] = '0';
	}
}

int GetPushedCnt(string start, string target, bool firstBulbPush)
{
	int ret = 0;

	if (firstBulbPush) // 0번째 전구 스위치 누름
	{
		Push(start, 0);
		ret++;
	}

	for (int i = 1; i < N; i++)
	{
		if (start[i - 1] != target[i - 1])
		{
			Push(start, i);
			ret++;
		}
	}

	if (start != target)
	{
		ret = INT_MAX;
	}
	return ret;
}

int main()
{
	cin >> N;
	
	string start, target;
	cin >> start >> target;

	int answer = min(GetPushedCnt(start, target, true), GetPushedCnt(start, target, false));
	if (answer == INT_MAX)
	{
		answer = -1;
	}

	cout << answer << '\n';
	return 0;
}