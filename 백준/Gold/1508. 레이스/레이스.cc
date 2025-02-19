/* 참고풀이 : https://rccode.tistory.com/254 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M, K;
vector<int> JudgePosVec;
int main()
{
	cin >> N >> M >> K;

	int pos;
	for (int i = 0; i < K; i++)
	{
		cin >> pos;
		JudgePosVec.push_back(pos);
	}

	string answer;
	int begin = 0;
	int end = N;
	int mid;

	while (begin <= end)
	{
		mid = (begin + end) / 2;

		/*
		  정답이 여러개일 경우에는 사전순으로 가장 늦는 것을 출력해야 하기 때문에
		  첫번째 자리엔 무조건 심판을 고정적으로 배치시키고 시작.
		  즉, 첫번째 값은 무조건 '1' 고정.
		*/
		string tmpAnswer = "1";
		int prePos = 0;
		int selectedCnt = 1;
		
		/* 심판 배치 시작 */
		for (int curPos = 1; curPos < K; curPos++)
		{
			if (JudgePosVec[curPos] - JudgePosVec[prePos] >= mid)
			{
				tmpAnswer += '1';
				selectedCnt++;
				prePos = curPos;
			}
			else
			{
				tmpAnswer += '0';
			}

			if (selectedCnt >= M)
			{
				break;
			}
		}
		
		while ((int)tmpAnswer.size() < K) // 남은 빈자리는 '0'으로 채우기
		{
			tmpAnswer += '0';
		}

		if (selectedCnt >= M) // 충분히 배치했으면, 심판들 사이의 거리를 좀 더 늘려봄
		{
			answer = tmpAnswer;
			begin = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << answer << '\n';
	return 0;
}