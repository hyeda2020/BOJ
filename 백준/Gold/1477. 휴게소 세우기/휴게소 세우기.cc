#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, L;
vector<int> RestVec;

bool Check(int mid)
{
	int cnt = 0;	
	int dist;
	for (size_t i = 1; i < RestVec.size(); i++)
	{
		/* 
			이미 있는 휴게소 구간별로 그 사이에 
			mid 거리마다 새로운 휴게소를 몇개 지을 수 있는지 구하고,
			그 합을 합산.
		*/
		dist = (RestVec[i] - RestVec[i - 1]);
		cnt += (dist / mid);
		if (dist % mid == 0)
		{
			cnt--;
		}
	}

	return cnt > M; // 그리고 그 합산된 값이 M보다 큰지 여부를 리턴
}

int main()
{
	cin >> N >> M >> L;

	int val;
	for (int i = 0; i < N; i++)
	{
		cin >> val;
		RestVec.push_back(val);
	}
	RestVec.push_back(0);
	RestVec.push_back(L);
	sort(RestVec.begin(), RestVec.end());

	int begin = 1;
	int end = L;
	int mid;
	int answer = 0;

	while (begin <= end)
	{
		mid = (begin + end) / 2;
		if (Check(mid))
		{
			/*
				새로 지을 수 있는 휴게소가 M보다 크다면
				다음번 mid의 값을 증가시킴
			*/ 
			begin = mid + 1; 
		}
		else
		{
			answer = mid;	
			end = mid - 1; // M보다 작다면 다음번 mid의 값을 감소시킴
		}
	}

	cout << answer << '\n';
	return 0;
}