/* 참고풀이 : https://viin.tistory.com/192 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

int N;
map<string, vector<int>> PrefixPosMap; // { prefix, { prefixIdx } }
set<string> VisitedSet;
vector<string> wordVec;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int maxPrefixSize = 0;
	string word;
	for (int i = 0; i < N; i++)
	{
		cin >> word;
		wordVec.push_back(word);
		if (VisitedSet.count(word))
		{
			continue;
		}
		else
		{
			VisitedSet.insert(word);
		}

		string tmp = "";
		for (size_t j = 0; j < word.size(); j++)
		{
			tmp += word[j];
			PrefixPosMap[tmp].push_back(i);
			if (PrefixPosMap[tmp].size() >= 2)
			{
				maxPrefixSize = max(maxPrefixSize, (int)tmp.size());
			}
		}
	}
	
	int maxPrefixOrder = INT_MAX;
	string maxPrefix;
	for (const auto& iter : PrefixPosMap)
	{
		if ((int)iter.first.size() == maxPrefixSize && (int)iter.second.size() >= 2)
		{
			if (iter.second[0] < maxPrefixOrder)
			{
				maxPrefixOrder = iter.second[0];
				maxPrefix = iter.first;
			}
		}
	}

	cout << wordVec[PrefixPosMap[maxPrefix][0]] << '\n' << wordVec[PrefixPosMap[maxPrefix][1]] << '\n';
	return 0;
}