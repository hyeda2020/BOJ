#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int Seq[100001];
int DP[2][100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> Seq[i];
	}

	DP[0][1] = Seq[1];
	DP[1][1] = Seq[1];
	int answer = Seq[1];
	for (int i = 2; i <= n; i++)
	{
		/* 
			[수를 제거하지 않는 경우 연속합 먼저 계산]
			i-1번 까지의 연속합이 Seq[i]보다 작을 경우엔 Seq[i] 값으로 DP배열 갱신
		*/
		DP[0][i] = max(DP[0][i - 1] + Seq[i], Seq[i]);

		/* 
			[하나의 수를 제거하는 경우 연속합 계산] 
			1. i 번째를 삭제하는 경우에는 i-1번째에서 삭제하지 않았을 경우의 연속합을 그대로 가져옴
			2. 만약 i 이전 위치에서 수 하나를 삭제했을 경우 Seq[i]는 반드시 포함되어야 함.
			   따라서 i-1번째에서 삭제를 사용했을 때의 연속합에 Seq[i]를 더해준다
		*/
		DP[1][i] = max(DP[0][i - 1], DP[1][i - 1] + Seq[i]);

		/* 두 경우 중 최대값 계산 */
		answer = max(answer, max(DP[0][i], DP[1][i]));
	}

	cout << answer << '\n';
	return 0;
}