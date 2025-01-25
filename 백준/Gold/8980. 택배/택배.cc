/* 참고 풀이 : https://life318.tistory.com/163 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int VillageCnt, Capacity, BoxInfoCnt;
int CurrentTruckSizeArr[2001];
int main()
{
	cin >> VillageCnt >> Capacity >> BoxInfoCnt;

	int src, dest, boxCnt;
	vector<pair<pair<int, int>, int>> boxInfoVec; // {{ dest, src }, boxCnt }
	for (int i = 0; i < BoxInfoCnt; i++)
	{
		cin >> src >> dest >> boxCnt;
		boxInfoVec.push_back({ { dest, src }, boxCnt });
	}
	int answer = 0;

	/*
	받는 마을과 보내는 마을의 차이가 적고, 택배를 빨리 내릴수록 효율적이므로
	받는 마을의 번호를 기준으로 오름차순 정렬한 후 탐색
	*/
	sort(boxInfoVec.begin(), boxInfoVec.end());

	int maxBoxSizeInTruck = 0;
	int possibleBoxSize = 0;
	for (int i = 0; i < (int)boxInfoVec.size(); i++)
	{
		src = boxInfoVec[i].first.second;
		dest = boxInfoVec[i].first.first;
		boxCnt = boxInfoVec[i].second;
		maxBoxSizeInTruck = 0;
		possibleBoxSize = 0;

		/* 해당 구간에 대하여 옮겨지는 박스들의 사이즈 중에서 가장 큰 것을 구함 */
		for (int j = src; j < dest; j++)
		{
			maxBoxSizeInTruck = max(CurrentTruckSizeArr[j], maxBoxSizeInTruck);
		}

		/* 트럭의 용량 - 해당 구간에서 옮겨지는 박스들의 최대 사이즈 = 해당 구간에서 실을 수 있는 박스의 양 */
		possibleBoxSize = min(boxCnt, Capacity - maxBoxSizeInTruck);
		
		answer += possibleBoxSize;
		for (int j = src; j < dest; j++) // 해당 구간에 실을 수 있는 박스의 양 추가
		{
			CurrentTruckSizeArr[j] += possibleBoxSize;
		}
	}

	cout << answer << '\n';
	return 0;
}
