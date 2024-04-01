#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int N, d, k, c;
int ChobobBelt[30001];
map<int, int> ChobobChainMap;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> d >> k >> c;
	int chobob;
	for (int i = 0; i < N; i++)
	{
		cin >> ChobobBelt[i];
	}

	for (int i = 0; i < k; i++)
	{
		ChobobChainMap[ChobobBelt[i]]++;
	}
	ChobobChainMap[c]++;

	int left = 0;
	int right = k - 1;
	int cnt = 0;
	while (left < N)
	{
		cnt = max(cnt, (int)ChobobChainMap.size());

		/* left 초밥 지움 */
		ChobobChainMap[ChobobBelt[left]]--;
		if (ChobobChainMap[ChobobBelt[left]] == 0)
		{
			ChobobChainMap.erase(ChobobBelt[left]);
		}
		left++;
		
		right = (right + 1) % N;
		ChobobChainMap[ChobobBelt[right]]++;
	}

	cout << cnt << '\n';
	return 0;
}