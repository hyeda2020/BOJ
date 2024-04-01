#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int N, d, k, c;
int ChobobBelt[3000001];
int ChobobCnt[3001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++)
	{
		cin >> ChobobBelt[i];
	}

	int cnt = 0;
	for (int i = 0; i < k; i++)
	{
		ChobobCnt[ChobobBelt[i]]++;
	}
	ChobobCnt[c]++;

	for (int i = 1; i <= d; i++)
	{
		if (ChobobCnt[i])
		{
			cnt++;
		}
	}

	int left = 0;
	int right = k - 1;
	int res = 0;
	while (left < N)
	{
		res = max(cnt, res);

		/* left 초밥 지움 */
		if (ChobobBelt[left] != c)
		{
			ChobobCnt[ChobobBelt[left]]--;
		}
		if (ChobobCnt[ChobobBelt[left]] == 0)
		{
			cnt--;
		}
		left++;

		/* right 초밥 추가 */
		right = (right + 1) % N;
		ChobobCnt[ChobobBelt[right]]++;
		if (ChobobCnt[ChobobBelt[right]] == 1)
		{
			cnt++;
		}
	}

	cout << res << '\n';
	return 0;
}